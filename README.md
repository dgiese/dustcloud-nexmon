This is a simplified version of the Nexmon Framework by Daniel Wegemer and Matthias Schulz (https://github.com/seemoo-lab/nexmon)

This release does not contain the buildtools, please download them from the nexmon repository.
# Steps:
* import folder buildtools from (https://github.com/seemoo-lab/nexmon/tree/master/buildtools)
* `source setup.env.sh`
* Maybe: `cd buildutils/` and `make`
* Edit: `patches/common/wrapper.c` to add more firmware functions (see *blinkenlights*)
* Edit: `patches/mw300/1/demo/src/patch.c` to add new code to your firmware
* Edit: `firmwares/mw300/1/definitions.mk` to define where new patches have to go
