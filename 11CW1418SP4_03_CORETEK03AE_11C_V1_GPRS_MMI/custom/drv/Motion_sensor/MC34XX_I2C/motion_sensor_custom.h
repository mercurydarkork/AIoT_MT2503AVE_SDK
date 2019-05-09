#ifndef _MOTION_SENSOR_CUSTOM_H_
#define _MOTION_SENSOR_CUSTOM_H_

#include "motion_sensor.h"

//#define MS_SLAVE_ADDR       0x98 //0x4C << 1 
#define MS_SLAVE_ADDR       0xD8 //0x6C << 1 //for VPP high level

//Register define start
#define MS_REG_XOUT 0x00
#define MS_REG_YOUT 0x01
#define MS_REG_ZOUT 0x02
#define MS_REG_TILT 0x03
#define MS_REG_OPSTAT 0x04
#define MS_REG_SC 0x05

#define MS_REG_INTEN 0x06
#define MS_REG_MODE 0x07
#define MS_REG_SAMPR 0x08
#define MS_REG_TAPEN 0x09
#define MS_REG_TAPP 0x0A

#define MS_REG_DROP_CTRL 0x0B
#define MS_REG_SHDB 0x0C
//0x0D~0x17 Reserved
#define MS_REG_CHIPID 0x18
//0x19~0x20 Reserved

#define MS_REG_XOFFL 0x21
#define MS_REG_XOFFH 0x22
#define MS_REG_YOFFL 0x23
#define MS_REG_YOFFH 0x24
#define MS_REG_ZOFFL 0x25
#define MS_REG_ZOFFH 0x26

#define MS_REG_XGAIN 0x27
#define MS_REG_YGAIN 0x28
#define MS_REG_ZGAIN 0x29
//0x2A RESERVED

#define MS_REG_SHAKE_TH 0x2B
#define MS_REG_UD_Z_TH 0x2C
#define MS_REG_UD_X_TH 0x2D
#define MS_REG_RL_Z_TH 0x2E
#define MS_REG_RL_Y_TH 0x2F
#define MS_REG_FB_Z_TH 0x30
#define MS_REG_DROP_TH 0x31
#define MS_REG_TAP_TH 0x32
//0x33~0x3A RESERVED

#define MS_REG_PCODE 0x3B
//0x3C~0x3F RESERVED
//Register define End

//Operate state
#define MS_STANDBY_MODE 	0x43
#define MS_WAKE_MODE 		0x41    //0x59
#define MS_SNIFF_MODE 		0x02 

//Tilt Status
#define TILT_STATUS_BAFR_MASK    0x03
#define TILT_STATUS_BAFR_UNKNOWN 0x00
#define TILT_STATUS_BAFR_FRONT   0x01
#define TILT_STATUS_BAFR_BACK    0x02

#define TILT_STATUS_POLA_MASK    0x1C
#define TILT_STATUS_POLA_UNKNOWN 0x00
#define TILT_STATUS_POLA_LEFT    0x04
#define TILT_STATUS_POLA_RIGHT   0x08
#define TILT_STATUS_POLA_DOWN    0x14
#define TILT_STATUS_POLA_UP      0x18

#define TILT_STATUS_TAP_EVENT    0x20
#define TILT_STATUS_DROP_EVENT   0x40
#define TILT_STATUS_SHAKE_EVENT  0x80

//Sleep Count
#define SLEEP_COUNT 0

//TAP
#define TAP_X_ENABLE 0x20
#define TAP_Y_ENABLE 0x40
#define TAP_Z_ENABLE 0x80
#define TAP_PULSE_COUNT 0x0F //This value sets the number of samples for which a tap pulse must exceed the TAP_TH threshold before it is rejected as not a tap event. If the values detected by the sensor exceed the TAP_TH threshold for longer than the reject count, no tap event is detected and the interrupt is not set.
#define TAP_THRESHOLD 0x20

//Drop
#define DROP_DEBOUNCE   0x05 // 0~255
#define DROP_INTERRUPT  0x40  //bit6: 0: disable ; 1: enable
#define DROP_MODE  0x00 //bit7: 0: mode_A; 1: mode_B
#define DROP_THRESHOLD 0x7F //~2.9mg/LSB

//Shake
#define SHAKE_DEBOUNCE 0x0a  //0~63
#define SHAKE_THRESHOLD 0x0  //offset value:mag(X/Y/Z) > 1.3g + SHAKE_TH, ~2.9mg/LSB

typedef enum
{
   MCUBE_DROP_MODE_A,
   MCUBE_DROP_MODE_B
} mCubeAccelDropMode_t;

#define TAP_DETECT_X   0x20
	/** Enable Tap Detection on Y-axis */
#define TAP_DETECT_Y   0x40
	/** Enable Tap Detection on Z-axis */
#define TAP_DETECT_Z   0x80

/* Calibration parameters for gesture event triggering */
#define MC3XXX_DFLT_UDZ_THRESH           0x0
#define MC3XXX_DFLT_UDX_THRESH           0x0
#define MC3XXX_DFLT_RLZ_THRESH           0x0
#define MC3XXX_DFLT_RLY_THRESH           0x0
#define MC3XXX_DFLT_FBZ_THRESH           0x0
#define MC3XXX_DFLT_DROP_THRESH          0x0
#define MC3XXX_DFLT_TAP_THRESH           0x0
#define MC3XXX_DFLT_SHAKE_DEBOUNCE       0x0
#define MC3XXX_DFLT_SHAKE_THESH_OFFSET   0x0
#define MC3XXX_DFLT_DROP_DEBOUNCE        0x0
#define MC3XXX_DFLT_DROP_MODE            MCUBE_DROP_MODE_A
#define MC3XXX_DFLT_TAP_AXES             TAP_DETECT_Z
#define MC3XXX_DFLT_TAP_DETECT_SAMP      0x0

////////////////////////////////////////////////////
#define MC3413_RANGE       16	//+/-8g
#define MC3413_RESOLUTION  14	//14-Bits

#define ACC_MC3413_0G_X      8096
#define ACC_MC3413_1G_X      9120
#define ACC_MC3413_MINUS1G_X 7072
#define ACC_MC3413_0G_Y      8096   
#define ACC_MC3413_1G_Y      9120
#define ACC_MC3413_MINUS1G_Y  7072
#define ACC_MC3413_0G_Z      8096       
#define ACC_MC3413_1G_Z      9120
#define ACC_MC3413_MINUS1G_Z  7072

/////////////////////////////////////////////////////
#define MC3433_RANGE       4	//+/-2g
#define MC3433_RESOLUTION  8	//8-Bits

#define ACC_MC3433_0G_X      127
#define ACC_MC3433_1G_X      127+63
#define ACC_MC3433_MINUS1G_X 127-64
#define ACC_MC3433_0G_Y      127
#define ACC_MC3433_1G_Y      127+63
#define ACC_MC3433_MINUS1G_Y 127-64
#define ACC_MC3433_0G_Z      127     
#define ACC_MC3433_1G_Z      127+63
#define ACC_MC3433_MINUS1G_Z 127-64


#define MC3436_RANGE       4	//+/-2g
#define MC3436_RESOLUTION  8	//8-Bits

#define ACC_MC3436_0G_X      127
#define ACC_MC3436_1G_X      127+63
#define ACC_MC3436_MINUS1G_X 127-64
#define ACC_MC3436_0G_Y      127
#define ACC_MC3436_1G_Y      127+63
#define ACC_MC3436_MINUS1G_Y 127-64
#define ACC_MC3436_0G_Z      127     
#define ACC_MC3436_1G_Z      127+63
#define ACC_MC3436_MINUS1G_Z 127-64


extern MotionSensor_customize_function_struct *ms_GetFunc(void);
extern MotionSensor_custom_data_struct *ms_get_data(void);
extern kal_bool mcube_i2c_read_buf(kal_uint8 reg, char* buf, kal_uint8 size);
void mc3xxx_sensor_pwr_up(void);
void mc3xxx_sensor_pwr_down(void);
void mc3xxx_sensor_init(void);

#endif //_MOTION_SENSOR_CUSTOM_H_
