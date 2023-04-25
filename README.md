# Personal QMK userspace

This is a personal userspace repo for QMK keyboard firmware where the idea and organization directly follows [filterpaper's userspace](https://github.com/filterpaper/qmk_userspace). This organization allows keeping all user keymaps self-contained in one folder rather than split across userspace and keyboard folders. Please see the README of the linked repo for more details.

To build firmware for keyboards, symbolic link a local copy or directly clone this repo into `<qmk_firmware_path>/users/caksoylar` then build with `qmk compile <qmk_firmware_path>/users/caksoylar/keymaps/<keyboard>.json`.

## Keyboards
Keyboards that have keymaps in this repo are the following:
- A handwired [Skeletyl](https://github.com/Bastardkb/Skeletyl) built with Xiao RP2040's (custom keyboard at [`keyboards/skelexiao`](keyboards/skelexiao))
- [Keebio Iris Rev 4](https://github.com/qmk/qmk_firmware/tree/master/keyboards/keebio/iris)
- [Fingerpunch FFKB](https://fingerpunch.xyz/product/faux-fox-keyboard/)
- [Gergoplex](https://github.com/qmk/qmk_firmware/tree/master/keyboards/gboards/gergoplex)
- [Capsunlocked CU7](https://github.com/qmk/qmk_firmware/tree/master/keyboards/capsunlocked/cu7)
- [`choc_ergo`](https://github.com/caksoylar/qmk_firmware/tree/caksoylar/userspace-only/keyboards/choc_ergo) (not supported in upstream QMK)

## Keymap
The keymap for above keyboards follows my ZMK keymap that you can see in my [zmk-config repo](https://github.com/caksoylar/zmk-config/).
