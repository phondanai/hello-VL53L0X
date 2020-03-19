## Example code for using VL53L0X [Time-of-Flight (ToF) ranging sensor]

### Require
 - [VL53L0X](https://os.mbed.com/teams/ST/code/VL53L0X/#e9269ff624ed)

Compile
```
mbed compile --target DISCO_L475VG_IOT01A --toolchain GCC_ARM --source . --source ../mbed-os --source ../VL53L0X --flash
```

Example output
```
VL53L0X [mm]:               131

VL53L0X [mm]:               102

VL53L0X [mm]:                98

VL53L0X [mm]:                75

VL53L0X [mm]:               103

VL53L0X [mm]:                94

VL53L0X [mm]:                85

VL53L0X [mm]:                52

VL53L0X [mm]:                98

VL53L0X [mm]:                 0

```

### Ref
[HelloWorld_ST_Sensors](https://os.mbed.com/teams/ST/code/HelloWorld_ST_Sensors/)
