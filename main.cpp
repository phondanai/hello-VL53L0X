#include "mbed.h"
#ifdef TARGET_DISCO_L475VG_IOT01A
#include "VL53L0X.h"
#endif


/* Interface definition */
#ifdef TARGET_DISCO_L475VG_IOT01A
static DevI2C devI2c(PB_11,PB_10);
#else // X-Nucleo-IKS01A2 or SensorTile
#ifdef TARGET_SENSOR_TILE
#define SPI_TYPE_LPS22HB   LPS22HBSensor::SPI3W
#define SPI_TYPE_LSM6DSL   LSM6DSLSensor::SPI3W
SPI devSPI(PB_15, NC, PB_13);  // 3-wires SPI on SensorTile  
static Serial ser(PC_12,PD_2); // Serial with SensorTile Cradle Exp. Board + Nucleo   
#define printf(...) ser.printf(__VA_ARGS__)     
#else  // Nucleo-XXX + X-Nucleo-IKS01A2 
static DevI2C devI2c(D14,D15);
#endif
#endif

/* Range sensor - B-L475E-IOT01A2 only */
#ifdef TARGET_DISCO_L475VG_IOT01A
static DigitalOut shutdown_pin(PC_6);
static VL53L0X range(&devI2c, &shutdown_pin, PC_7);
#endif

/* Simple main function */
int main() {
  uint8_t id;
  float value1, value2;
//  char buffer1[32], buffer2[32];
  int32_t axes[3];
  
#ifdef TARGET_DISCO_L475VG_IOT01A
  range.init_sensor(VL53L0X_DEFAULT_ADDRESS);
#else // X-NUCLEO-IKS01A2 or SensorTile
  accelerometer.init(NULL);
#endif

  
//  /* Enable all sensors */
//#ifndef TARGET_DISCO_L475VG_IOT01A // X-NUCLEO-IKS01A2
//  magnetometer.enable();
//  accelerometer.enable();
//#endif

  while(1) {
    printf("\r\n");

    value1=value2=0;    

#ifdef TARGET_DISCO_L475VG_IOT01A
    uint32_t distance;
    int status = range.get_distance(&distance);
    if (status == VL53L0X_ERROR_NONE) {
        printf("VL53L0X [mm]:            %6ld\r\n", distance);
    } else {
        printf("VL53L0X [mm]:                --\r\n");
    }
#endif

    wait(1);
  }
}
