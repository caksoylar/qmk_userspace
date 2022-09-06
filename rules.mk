SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE   = no
MAGIC_ENABLE       = no
COMMAND_ENABLE     = no

SRC += caksoylar.c

ifneq ($(KEYBOARD), capsunlocked/cu7)
	COMBO_ENABLE = yes
	VPATH +=  keyboards/gboards/
	CAPS_WORD_ENABLE = yes
else
	ENCODER_ENABLE = yes
	ENCODER_MAP_ENABLE = yes
endif

ifeq ($(KEYBOARD), keebio/iris/rev4)
	ENCODER_ENABLE = yes
	RGBLIGHT_ENABLE = yes
	MOUSEKEY_ENABLE = yes
	USE_SECRETS = yes
endif

ifeq ($(strip $(USE_SECRETS)), yes)
	ifneq ("$(wildcard $(USER_PATH)/secrets.c)", "")
		SRC += rotary_lock.c secrets.c
	else
		OPT_DEFS += -DNO_SECRETS
	endif
else
	OPT_DEFS += -DNO_SECRETS
endif
