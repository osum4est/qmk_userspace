OS_DETECTION_ENABLE = yes
CONSOLE_ENABLE = yes # For debug print statements
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes # So that we can run OS detection after startup
DYNAMIC_TAPPING_TERM_ENABLE = yes # So we can test different tapping terms
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

# TAP_DANCE_ENABLE = yes

AUDIO_ENABLE = no
# AUDIO_ENABLE = yes

INTROSPECTION_KEYMAP_C = artemis.c

SRC += utils.c extensions.c
VPATH += keyboards/gboards
