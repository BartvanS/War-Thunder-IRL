#define MMA7455L_DEVICE_ADDRESS (0x1D)

/********* registers van de 3D acceleratiesensor ***********/

#define XOUTL      0x00   // 10 bits output value X LSB             XOUT[7]  XOUT[6]  XOUT[5]  XOUT[4]  XOUT[3]  XOUT[2]  XOUT[1]  XOUT[0]
#define XOUTH      0x01   // 10 bits output value X MSB             --       --       --       --       --       --       XOUT[9]  XOUT[8]
#define YOUTL      0x02   // 10 bits output value Y LSB             YOUT[7]  YOUT[6]  YOUT[5]  YOUT[4]  YOUT[3]  YOUT[2]  YOUT[1]  YOUT[0]
#define YOUTH      0x03   // 10 bits output value Y MSB             --       --       --       --       --       --       YOUT[9]  YOUT[8]
#define ZOUTL      0x04   // 10 bits output value Z LSB             ZOUT[7]  ZOUT[6]  ZOUT[5]  ZOUT[4]  ZOUT[3]  ZOUT[2]  ZOUT[1]  ZOUT[0]
#define ZOUTH      0x05   // 10 bits output value Z MSB             --       --       --       --       --       --       ZOUT[9]  ZOUT[8]
#define XOUT8      0x06   // 8 bits output value X                  XOUT[7]  XOUT[6]  XOUT[5]  XOUT[4]  XOUT[3]  XOUT[2]  XOUT[1]  XOUT[0]
#define YOUT8      0x07   // 8 bits output value Y                  YOUT[7]  YOUT[6]  YOUT[5]  YOUT[4]  YOUT[3]  YOUT[2]  YOUT[1]  YOUT[0]
#define ZOUT8      0x08   // 8 bits output value Z                  ZOUT[7]  ZOUT[6]  ZOUT[5]  ZOUT[4]  ZOUT[3]  ZOUT[2]  ZOUT[1]  ZOUT[0]
#define STATUS     0x09   // Status registers                       --       --       --       --       --       PERR     DOVR     DRDY
#define DETSRC     0x0A   // Detection source registers             LDX      LDY      LDZ      PDX      PDY      PDZ      INT1     INT2
#define TOUT       0x0B   // "Temperature output value" (Optional)  TMP[7]   TMP[6]   TMP[5]   TMP[4]   TMP[3]   TMP[2]   TMP[1]   TMP[0]
//                 0x0C   // (Reserved)                             --       --       --       --       --       --       --       --
#define I2CAD      0x0D   // I2C device address I                   2CDIS    DAD[6]   DAD[5]   DAD[4]   DAD[3]   DAD[2]   DAD[1]   DAD[0]
#define USRINF     0x0E   // User information (Optional)            UI[7]    UI[6]    UI[5]    UI[4]    UI[3]    UI[2]    UI[1]    UI[0]
#define WHOAMI     0x0F   // "Who am I" value (Optional)            ID[7]    ID[6]    ID[5]    ID[4]    ID[3]    ID[2]    ID[1]    ID[0]
#define XOFFL      0x10   // Offset drift X value (LSB)             XOFF[7]  XOFF[6]  XOFF[5]  XOFF[4]  XOFF[3]  XOFF[2]  XOFF[1]  XOFF[0]
#define XOFFH      0x11   // Offset drift X value (MSB)             --       --       --       --       --       XOFF[10] XOFF[9]  XOFF[8]
#define YOFFL      0x12   // Offset drift Y value (LSB)             YOFF[7]  YOFF[6]  YOFF[5]  YOFF[4]  YOFF[3]  YOFF[2]  YOFF[1]  YOFF[0]
#define YOFFH      0x13   // Offset drift Y value (MSB)             --       --       --       --       --       YOFF[10] YOFF[9]  YOFF[8]
#define ZOFFL      0x14   // Offset drift Z value (LSB)             ZOFF[7]  ZOFF[6]  ZOFF[5]  ZOFF[4]  ZOFF[3]  ZOFF[2]  ZOFF[1]  ZOFF[0]
#define ZOFFH      0x15   // Offset drift Z value (MSB)             --       --       --       --       --       ZOFF[10] ZOFF[9]  ZOFF[8]
#define MCTL       0x16   // Mode control                           LPEN     DRPD     SPI3W    STON     GLVL[1]  GLVL[0]  MOD[1]   MOD[0]
#define INTRST     0x17   // Interrupt latch reset                  --       --       --       --       --       --       CLRINT2  CLRINT1
#define CTL1       0x18   // Control 1                              --       THOPT    ZDA      YDA      XDA      INTRG[1] INTRG[0] INTPIN
#define CTL2       0x19   // Control 2                              --       --       --       --       --       DRVO     PDPL     LDPL
#define LDTH       0x1A   // Level detection threshold limit value  LDTH[7]  LDTH[6]  LDTH[5]  LDTH[4]  LDTH[3]  LDTH[2]  LDTH[1]  LDTH[0]
#define PDTH       0x1B   // Pulse detection threshold limit value  PDTH[7]  PDTH[6]  PDTH[5]  PDTH[4]  PDTH[3]  PDTH[2]  PDTH[1]  PDTH[0]
#define PW         0x1C   // Pulse duration value                   PD[7]    PD[6]    PD[5]    PD[4]    PD[3]    PD[2]    PD[1]    PD[0]
#define LT         0x1D   // Latency time value                     LT[7]    LT[6]    LT[5]    LT[4]    LT[3]    LT[2]    LT[1]    LT[0]
#define TW         0x1E   // Time window for 2nd pulse value        TW[7]    TW[6]    TW[5]    TW[4]    TW[3]    TW[2]    TW[1]    TW[0]
//                 0x1F   // (Reserved)                             --       --       --       --       --       --       --       --


//
//         MCTL - Mode control register
//   +---------------------------------------+
//   ¦ D7 ¦ D6 ¦ D5 ¦ D4 ¦ D3 ¦ D2 ¦ D1 ¦ D0 ¦
//   +----+----+----+----+----+----+----+----¦
//   ¦ -- ¦DRPD¦SPI3¦STON¦GLVL¦GLVL¦MODE¦MODE¦
//   +---------------------------------------+
//
//
//   D7       - don't care          0
//
//   D6(DRPD) - DATA ready status   0 - OUTPUT TO INT1 PIN
//                                  1 - is NOT OUTPUT TO INT1 PIN
//
//   D5(SPI3W)- Wire Mode           0 - SPI is 4-wire mode
//                                  1 - SPI is 3-wire mode
//
//   D4(STON) - Self Test           0 - NOT enabled
//                                  1 - enabled
//
//   D3(GLVL[1]) - g-SELECT        00 - 8g ; 16 LSB/g in 8-Bit format
//   D2(GLVL[0]) - g-SELECT        10 - 4g ; 32 LSB/g in 8-Bit format
//                                 01 - 2g ; 64 LSB/g in 8-Bit format
//
//                                         ; Note: When reading g in 10-Bit
//                                         ;       format, resolution is fixed
//                                         ;       at 64 LSB/g
//                   10-Bit g register
//   +-------------------------------------------------+
//   ¦ D9 ¦ D8 ¦ D7 ¦ D6 ¦ D5 ¦ D4 ¦ D3 ¦ D2 ¦ D1 ¦ D0 ¦
//   +-------------------------------------------------+
//   ¦<------------------------------------->¦            ; These 8 bits are READ in 8g mode
//        ¦<------------------------------------->¦       ; These 8 bits are READ in 4g mode
//             ¦<------------------------------------->¦  ; These 8 bits are READ in 2g mode
//
//   D1(MODE[1]) - Mode SELECT     00 - Standby           dit scheelt aanzienlijk in power consumptie
//   D0(MODE[0]) - Mode SELECT     01 - Measurement
//                                 10 - Level Detection
//                                 11 - Pulse Detection

