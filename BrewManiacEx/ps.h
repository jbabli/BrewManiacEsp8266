/**********************************************************************
 BrewManiac 
 created by Vito Tai
 Copyright (C) 2015 Vito Tai
 
 This soft ware is provided as-is. Use at your own risks.
 You are free to modify and distribute this software without removing 
 this statement.
 BrewManiac by Vito Tai is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
***********************************************************************/

#ifndef PS_H
#define PS_H
// Persistence Storage
//  PID MENU

#define PS_SPACE   0  //	Use Gas
#define PS_PidBase PS_SPACE

#define PS_AddrOfPidSetting(i) (PS_PidBase+i)

#define PS_kP      1  // 	kP
#define PS_kI      2  //	kI
#define PS_kD      3  //     kD
#define PS_SampleTime      4  //     SampleTime
#define PS_WindowSize      5  //     WindowSize
#define PS_BoilHeat      6    //   Boil Heat %
#define PS_Offset     7      // Offset
#define PS_PID_Start   8      // star PID 
#define PS_PID_DoughIn  9      // PID DoughIn

//  UNIT MENU  
#define PS_TempUnit   10     //  Scale Temp
#define PS_UnitBase PS_TempUnit
#define PS_AddrOfUnitSetting(i) (PS_UnitBase+i)
//#define PS_SensorType     11      // Sensor Type
#define PS_NoDelayStart  11      // delaystart
#define PS_BoilTemp     12       //Temp Boil °C
//     13       Temp Boil °F
#define PS_PumpCycle     14  //     Time Pump Cycle
#define PS_PumpRest     15   //    Time Pump Rest
#define PS_PumpPreMash     16  //     Pump PreMash
#define PS_PumpOnMash     17   //    Pump on Mash
#define PS_PumpOnMashOut     18  //     Pump on MashOut
#define PS_PumpOnBoil      19     //  Pump on Boil
#define PS_TempPumpRest     20    //   Temp Pump Rest °C
//     21       Temp Pump Rest °F
#define PS_PidPipe     22     //  PID Pipe
#define PS_SkipAddMalt     23  //     Skip Add Malt
#define PS_SkipRemoveMalt     24  //     Skip Remove Malt
#define PS_SkipIodineTest     25    //   Skip Iodine Test
#define PS_IodineTime     26   //    Iodine Time
#define PS_Whirlpool     27     //  Whirlpool
#define PS_DisableBeep      28  //  Disable beeper
//     29 -  31 foot print 
#define PS_SpargeWaterEnableAddress    32
#define PS_SpargeWaterTemperatureControlAddress    33
#define PS_SpargeWaterSensorIndexAddress 34
#define PS_SpargeWaterTemperatureAddress	35
#define PS_SpargeWaterTemperatureDifferenceAddress	36


//  RUN  (HTemp °C - LTemp °C - HTemp °F - LTemp °F - Time)
#define PS_RunBase 37
#define PS_StageTemperatureAddr(i) ((PS_RunBase)+(i)* 5)
#define PS_StageTimeAddr(i) ((PS_RunBase)+(i)*5+4)
#define ToTempInStorage(t) ((int)((t)*16))
#define TempFromStorage(t)  ((float)(t)/16.0)


// 0:   37 -  41  [T1 T2 T3 T4 Time]   MashIn
// 
// 7:   72 - 76   Mash Out

#define PS_NumberOfHops    77  //      Numbers of Hops
#define PS_BoilTime     78    //   Boil Time 
#define PS_HopTimeBase 79
#define PS_TimeOfHop(i) ((PS_HopTimeBase)+i)
/*
    79       Time Hop  1
    80       Time Hop  2
    81       Time Hop  3
    82       Time Hop  4
    83       Time Hop  5
    84       Time Hop  6
    85       Time Hop  7
    86       Time Hop  8
    87       Time Hop  9
    88       Time Hop 10
*/

//[90-93]  RESUME automation
/*
#define  PS_AutomodeStarted    90    //   FLAG Automode Started

#define PS_StageResume    91 //      HANDLE Stage
#define PS_HopAdd    92     //  Hop Add
// simple wear leveling, leave 5 space for time rest
#define PS_StageTimeLeft    93 //      HANDLE Time Rest
// 93,94,95,96,97
*/
//[94-98,99-103] Sensor index for stages, total 6 stages
// Idle, Manual, PreMash, Mashing, Boiling, Cooling
#define PS_SensorUseBase    100 
#define PS_SensorUseAddressOf(i)    (PS_SensorUseBase+(i)) 

#define PS_SensorAuxBase    106 
#define PS_AuxSensorAddressOf(i)    (PS_SensorAuxBase+(i)) 

//[104-143] sensor addresses 
#define PS_SensorAddressBase    112 
#define PS_SensorAddressOf(i) ((i)*8 + PS_SensorAddressBase)

//[144-148] multi-sensor calibration 
#define PS_SensorCalibrationAddressBase    152
#define CalibrationAddressOf(i) ((i) + PS_SensorCalibrationAddressBase)

//[148-] Sparge water heater
 

const unsigned char  DEFAULT_EEPROM[] PROGMEM={
0, //#define PS_UseGas   0  //	space
200, //#define PS_kP      1  // 	kP
200, //#define PS_kI      2  //	kI
200, //#define PS_kD      3  //     kD
6, //  * 250 #define PS_SampleTime      4  //     SampleTime
20, //#define PS_WindowSize      5  //     WindowSize
85, //#define PS_BoilHeat      6    //   Boil Heat %
50, //#define PS_Offset     7      // Offset
30, //#define PID Start     8   //    Hysteresi 
0, //      9       [ SPACE ]
0, //#define PS_TempUnit   10     //  Scale Temp
0,  //#define NoDelay Start     11      //
99, //#define PS_BoilTemp     12       //Temp Boil °C
0, //     13       Temp Boil °F
15, //#define PS_PumpCycle     14  //     Time Pump Cycle
0, //#define PS_PumpRest     15   //    Time Pump Rest
0, //#define PS_PumpPreMash     16  //     Pump PreMash
1, //#define PS_PumpOnMash     17   //    Pump on Mash
1, //#define PS_PumpOnMashOut     18  //     Pump on MashOut
0, //#define PS_PumpOnBoil      19     //  Pump on Boil
105, //#define PS_TempPumpRest     20    //   Temp Pump Rest °C
0, //     21       Temp Pump Rest °F
0, //#define PS_PidPipe     22     //  PID Pipe
0, //#define PS_SkipAddMalt     23  //     Skip Add Malt
0, //#define PS_SkipRemoveMalt     24  //     Skip Remove Malt
1, //#define PS_SkipIodineTest     25    //   Skip Iodine Test
0, //#define PS_IodineTime     26   //    Iodine Time
0, //#define PS_Whirlpool     27     //  Whirlpool
0, //#define PS_DisableBeep      28  //  Disable beeper (0 = False, 1 = True)
////     28 -  31 [ SPACE ]
//'B','M','E','X',
//     29 -  31 [ SPACE ]
'M','E','X',
/*#define PS_SpargeWaterEnableAddress    32
#define PS_SpargeWaterTemperatureControlAddress    33
#define PS_SpargeWaterSensorIndexAddress 34
#define PS_SpargeWaterTemperatureAddress	35
#define PS_SpargeWaterTemperatureDifferenceAddress	36 */
0,0,1,78,1,
//  RUN  (HTemp °C - LTemp °C - HTemp °F - LTemp °F - Time)
//#define PS_RunBase 37
// 0:   37 -  41  [T1 T2 T3 T4 Time]   MashIn
// 
// 7:   72 - 77   Mash Out
2,208,0,0,1, // 0:   37 -  41 MashIn
4,16,0,0,60, // 1:   42 -  46 Fitasi / phytase
0,0,0,0,0, // 2:   47 -  51 Glucanasi /glucanase
0,0,0,0,0, // 3:   52 -  55 Proteasi /protease
0,0,0,0,0, // 4:   57 -  61 B-Amilasi /B-amylase
0,0,0,0,0, // 5:   62 -  66 A-Amilasi 1 
0,0,0,0,0, // 6:   67 -  71 A-Amilasi 2
4,176,0,0,20,// 7:   72 -  76 Mash Out

1, //#define PS_NumberOfHops    77  //      Numbers of Hops
60, //#define PS_BoilTime     78    //   Boil Time 
60, //#define PS_HopTimeBase 79
//#define PS_TimeOfHop(i) ((PS_HopTimeBase)+i)
0,0,0,0,0,0,0,0,0,
/*
    79       Time Hop  1
    88       Time Hop 10
*/
0, // 89 space
0, //#define  PS_AutomodeStarted    90    //   FLAG Automode Started

//  RESUME
0, //#define PS_StageResume    91 //      HANDLE Stage
0,//#define PS_StageTimeLeft    92 //      HANDLE Time Rest
0 //#define PS_HopAdd    93     //  Hop Add
};
#include "SpiffsEeprom.h"

#define USE_SPIFFS_EEPROM true

#if USE_SPIFFS_EEPROM

void commitSetting(void)
{
	SpiEEPROM.commit();
}

byte readSetting(int addr)
{
	return SpiEEPROM.read(addr);
}

bool updateSetting(int addr,byte value)
{
	return SpiEEPROM.write(addr,value);
}

word readSettingWord(int addr)
{
	return word(SpiEEPROM.read(addr),SpiEEPROM.read(addr+1));
}

word updateSettingWord(int addr,word value)
{
  	SpiEEPROM.write(addr,highByte(value));
  	SpiEEPROM.write((addr+1),lowByte(value));
}

void EepromInit(void)
{
	SpiEEPROM.begin(256);

	if(!(SpiEEPROM.read(29)=='M'
	 		&& SpiEEPROM.read(30)=='E'
	 		&& SpiEEPROM.read(31)=='X')){

//		Serial.printf("re-initialized EEPROM data\n");

		for(byte i=0;i<sizeof(DEFAULT_EEPROM);i++){
			SpiEEPROM.write(i,pgm_read_byte_near(& DEFAULT_EEPROM[i]));
		}
	}

}

void SaveDefaultSettingsToEeprom(void)
{
  for (byte i=0; i < sizeof(DEFAULT_EEPROM); i++)
  {
    SpiEEPROM.write(i, pgm_read_byte_near(& DEFAULT_EEPROM[i]));
  }
}  //end SaveDefaultSettingsToEeprom


#else //#if USE_SPIFFS_EEPROM
bool isEepromInitialized(void)
{

	if(EEPROM.read(29)=='M'
	 && EEPROM.read(30)=='E'
	 && EEPROM.read(31)=='X') return true;
	return false;
}

void setEepromDefault(void)
{
	for(byte i=0;i<sizeof(DEFAULT_EEPROM);i++){
		EEPROM.write(i,pgm_read_byte_near(& DEFAULT_EEPROM[i]));
	}
}

bool _eepromDirty=false;
void commitSetting(void)
{
	if(_eepromDirty)
	{
		EEPROM.commit();
		_eepromDirty=false;
	}
}

byte readSetting(int addr)
{
	return EEPROM.read(addr);
}

bool updateSetting(int addr,byte value)
{
    byte old=readSetting(addr);
	if(old != value){
		EEPROM.write(addr,value);
		_eepromDirty = true;
		return true;
	}
	return false;
}

word readSettingWord(int addr)
{
	return word(EEPROM.read(addr),EEPROM.read(addr+1));
}

word updateSettingWord(int addr,word value)
{
  	//EEPROM.update(addr,highByte(value));
  	//EEPROM.update((addr+1),lowByte(value));
  	EEPROM.write(addr,highByte(value));
  	EEPROM.write((addr+1),lowByte(value));
	_eepromDirty = true;
}
void EepromInit(void)
{
	//ESP8266
	EEPROM.begin(256);

	if(!isEepromInitialized())
	{
		setEepromDefault();
	}
}


void SaveDefaultSettingsToEeprom(void)
{
  setEepromDefault();
}  //end SaveDefaultSettingsToEeprom

#endif //#if USE_SPIFFS_EEPROM


void PrintEepromSettings(void)
{
#if SerialDebug == true
  byte byStage;

  Serial.println();
  Serial.println(F("EEPROM Settings"));
  Serial.println();
  
  Serial.println(F("PID - PWM Settings"));
  Serial.print(F("   kP: "));
  Serial.println(readSetting(PS_AddrOfPidSetting(1)));
  Serial.print(F("   kI: "));
  Serial.println(readSetting(PS_AddrOfPidSetting(2)));
  Serial.print(F("   kD: "));
  Serial.println(readSetting(PS_AddrOfPidSetting(3)));
  Serial.print(F("   Sample Time: "));
  Serial.println(readSetting(PS_AddrOfPidSetting(4)));
  Serial.print(F("   Window Size: "));
  Serial.println(readSetting(PS_AddrOfPidSetting(5)));
  Serial.print(F("Boil Heat PWM %: "));
  Serial.println(readSetting(PS_AddrOfPidSetting(6)));
  Serial.print(F("Temp Sensor Offset: "));
  Serial.println(readSetting(PS_AddrOfPidSetting(7)));
  Serial.print(F("PID Start: "));
  Serial.println(readSetting(PS_AddrOfPidSetting(8)));
  Serial.print(F("PID DoughIn: "));
  Serial.println(readSetting(PS_AddrOfPidSetting(9)));
  
  Serial.println(F("Unit Settings"));
  Serial.print(F("   Temperature Unit: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(0)));
  Serial.print(F("   No Start Delay: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(1)));
  Serial.print(F("   Boil Temp - Celcius: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(2)));
  Serial.print(F("   Boil Temp - Fahrenheit: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(3)));
  Serial.print(F("   Pump Cycle Time: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(4)));
  Serial.print(F("   Pump Rest Time: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(5)));
  Serial.print(F("   Pump on During Pre-Mash: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(6)));
  Serial.print(F("   Pump on During Mash: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(7)));
  Serial.print(F("   Pump on During Mash-Out: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(8)));
  Serial.print(F("   Pump on During Boil: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(9)));
  Serial.print(F("   Temp Pump Stop - Celcius: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(10)));
  Serial.print(F("   Temp Pump Stop - Fahrenheit: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(11)));
  Serial.print(F("   PID Malt Pipe: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(12)));
  Serial.print(F("   Skip Add Malt: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(13)));
  Serial.print(F("   Skip Remove Malt: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(14)));
  Serial.print(F("   Skip Iodine Test: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(15)));
  Serial.print(F("   Iodine Time: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(16)));
  Serial.print(F("   Whirlpool: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(17)));
  Serial.print(F("   Disable Beep: "));
  Serial.println(readSetting(PS_AddrOfUnitSetting(18)));
  
  Serial.println(F("Init Pattern"));
  Serial.print(F("   Byte 1: "));
  Serial.println(readSetting(29));
  Serial.print(F("   Byte 2: "));
  Serial.println(readSetting(30));
  Serial.print(F("   Byte 3: "));
  Serial.println(readSetting(31));
  
  Serial.println(F("Auto Settings"));
  Serial.println(F("   Mash-In Temperature"));
  Serial.print(F("      Raw C: "));
  Serial.print(readSettingWord(PS_StageTemperatureAddr(0)));
  Serial.print(F(", Temp C: "));
  Serial.println(TempFromStorage(readSettingWord(PS_StageTemperatureAddr(0))));
  Serial.print(F("      Raw F: "));
  Serial.print(readSettingWord(PS_StageTemperatureAddr(0) + 2));
  Serial.print(F(", Temp F: "));
  Serial.println(TempFromStorage(readSettingWord(PS_StageTemperatureAddr(0) + 2)));
  
  for (int i = 1; i < 7; i++)
  {
    Serial.print(F("   Stage "));
    Serial.println(i);
    Serial.print(F("      Raw C: "));
    Serial.print(readSettingWord(PS_StageTemperatureAddr(i)));
    Serial.print(F(", Temp C: "));
    Serial.println(TempFromStorage(readSettingWord(PS_StageTemperatureAddr(i))));
    Serial.print(F("      Raw F: "));
    Serial.print(readSettingWord(PS_StageTemperatureAddr(i) + 2));
    Serial.print(F(", Temp F: "));
    Serial.println(TempFromStorage(readSettingWord(PS_StageTemperatureAddr(i) + 2)));
    Serial.print(F("      Stage Time: "));
    Serial.println(readSetting(PS_StageTimeAddr(i)));
  }
  
  Serial.println(F("   Mash-Out Temperature"));
  Serial.print(F("      Raw C: "));
  Serial.print(readSettingWord(PS_StageTemperatureAddr(7)));
  Serial.print(F(", Temp C: "));
  Serial.println(TempFromStorage(readSettingWord(PS_StageTemperatureAddr(7))));
  Serial.print(F("      Raw F: "));
  Serial.print(readSettingWord(PS_StageTemperatureAddr(7) + 2));
  Serial.print(F(", Temp F: "));
  Serial.println(TempFromStorage(readSettingWord(PS_StageTemperatureAddr(7) + 2)));
  Serial.print(F("      Stage Time: "));
  Serial.println(readSetting(PS_StageTimeAddr(7)));
  
  Serial.print(F("   Number of Hops: "));
  Serial.println(readSetting(PS_NumberOfHops));
  Serial.print(F("   Boil Time: "));
  Serial.println(readSetting(PS_BoilTime));
  
  for (int i = 0; i < 10; i++)
  {
    Serial.print(F("   Hop Time "));
    Serial.print(i + 1);
    Serial.print(F(": "));
    Serial.println(readSetting(PS_TimeOfHop(i)));
  }
#endif
}  //end PrintEepromSettings

#endif

