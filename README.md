This is a simplified version of the Nexmon Framework by Daniel Wegemer and Matthias Schulz (https://github.com/seemoo-lab/nexmon)

I presented in 2018 at DEFCON how to use the Nexmon framework to modify Xiaomi firmwares, which are based on Marvel or Mediatek Cortex-M chips. You find the presentation here: http://dontvacuum.me/talks/DEFCON26-IoT-Village/DEFCON26-IoT-Village_How_to_Modify_Cortex_M_Firmware-Xiaomi.html

This release does not contain the buildtools, please download them from the nexmon repository.
# Steps:
* import folder buildtools from (https://github.com/seemoo-lab/nexmon/tree/master/buildtools)
* `source setup.env.sh`
* Maybe: `cd buildtools/` and `make`
* Edit: `patches/common/wrapper.c` to add more firmware functions (see *blinkenlights*)
* Edit: `patches/mw300/<firmware>/demo/src/patch.c` to add new code to your firmware
* Edit: `firmwares/mw300/<firmware>/definitions.mk` to define where new patches have to go
