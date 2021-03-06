/*-------------------------------------------
  RTC DS3231 - function file
  ARDUINO NANO
  (c) Can Tho University 2019 
  version 1.10 - 05/08/2019
--------------------------------------------*/ 
#ifndef  __NANO_RTC_DS3231_CPP
#define  __NANO_RTC_DS3231_CPP
#include "Nano_RTC_DS3231.h"

// ------ Private constants -----------------------------------
#define I2C_SDA A4
#define I2C_SCL A5

// ------ Private function prototypes -------------------------
/**
Set new time if the time is wrong - only works once - fix the time directly inside the function
**/
void set_time();
// ------ Private variables -----------------------------------
DS3231 rtc(I2C_SDA,I2C_SCL);
// ------ PUBLIC variable definitions -------------------------

//--------------------------------------------------------------
// FUNCTION DEFINITIONS
//--------------------------------------------------------------
bool RTC_init()
{
    rtc.begin();
    //set_time(); //set new time if the time is wrong - only works once - fix the time directly inside the function
    return true;
}//end RTC_init
//------------------------------------------
String RTC_getTime()
{ 
  String rtcData="";
  Time t;
  t=rtc.getTime();
  rtcData += t.hour; rtcData += ":";
  rtcData += t.min; rtcData += "(";
  rtcData += t.date; rtcData +="/";
  rtcData += t.mon; rtcData += "/";
  rtcData += t.year; rtcData += ")";
  D_PRINTLN(rtcData);
  return rtcData;
}// end RTC_getTime
//------------------------------------
void set_time()
{ 
  Time t;
  t=rtc.getTime();
  if ((t.date==1)&(t.mon==1)&(t.year==2000))
 {
  rtc.setDate(25,8,2019); 
  rtc.setTime(15,32,0);
 }//end if
}//end set_time
//--------------------------------
#endif //__NANO_RTC_DS3231_CPP
