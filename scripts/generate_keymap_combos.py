#!/usr/bin/env python3

import argparse
import json
import sys
import re
import yaml
from milc import cli

def parse_args():
    parser = argparse.ArgumentParser("Generate keymap combos")
    parser.add_argument("--drawer-config", type=str, help="Path to the keymap config file")
    parser.add_argument("--layer-names", type=str, nargs='+', help="List of layers to generate combos for")
    parser.add_argument("--keymap-source", type=str, help="Path to the c/h source file with the combos")
    return parser.parse_args()

def parse_source_file(file_path):
    cmd = ['cpp', str(file_path)]
    processed = cli.run(cmd)
    if "fatal error" in processed.stderr:
        print("Error while preprocessing file")
        print(processed.stderr)
        sys.exit(1)

    lines = processed.stdout.split("\n")

    combo_re = re.compile(r"\(combo_t\).*\.keys.*{(.+?),\s*COMBO_END}.*\.keycode\s*=\s*(.+)}")

    combos = []
    for line in lines:
        match = combo_re.search(line)
        if match is None:
            continue
        params = match.groups()
        combo = {
            "result": params[1],
            "keys": [k.strip() for k in params[0].split(",")]
        }
        combos.append(combo)

    return combos

def parse_qmk_json():
    json_data = json.load(sys.stdin)
    return json_data

def parse_keymap_config(file_path):
    yaml_data = yaml.safe_load(open(file_path))
    return yaml_data

def generate_yaml(config, combos, qmk_json, layer_names):
    yaml = "combos:\n"
    for combo in combos:
        combo_result, combo_keys = combo["result"], combo["keys"]
        for (i, layer) in enumerate(qmk_json["layers"]):
            key_indexes = [i for i, key in enumerate(layer) if key in combo_keys]
            if len(key_indexes) == len(combo_keys):
                layer = layer_names[i]
                result = combo_result.replace("KC_", "")

                if result in config["parse_config"]["qmk_keycode_map"]:
                    result = config["parse_config"]["qmk_keycode_map"][result]

                if result == "'":
                    result = "'" + result

                yaml += f"  - {{ p: {key_indexes}, k: '{result}', l: [{str(layer)}]}}\n"
    return yaml


def main():
    args = parse_args()
    combos = parse_source_file(args.keymap_source)
    qmk_json = parse_qmk_json()
    config = parse_keymap_config(args.drawer_config)
    yaml = generate_yaml(config, combos, qmk_json, args.layer_names)
    print(yaml)

if __name__ == "__main__":
    main()
