#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

#include "hi_ssp.h"


int pana_sensor_write_packet(unsigned int data)
{
	int fd = -1;
	int ret;
	unsigned int value;
    
	fd = open("/dev/ssp", 0);
	if(fd<0)
	{
		printf("Open /dev/ssp error!\n");
		return -1;
	}

	value = data;

	ret = ioctl(fd, SSP_WRITE_ALT, &value);

	//printf("ssp_write %#x, %#x\n", addr, value);

	close(fd);

	return 0;
}

int sensor_write_register(int addr, int data)
{
    return pana_sensor_write_packet((unsigned int)((addr<<16) | (data & 0xFFFF)));
}

static void delay_ms(int ms) { }

void sensor_prog(int* rom) 
{
    int i = 0;
    while (1) {
        int lookup = rom[i++];
        int addr = (lookup >> 16) & 0xFFFF;
        int data = lookup & 0xFFFF;
        if (addr == 0xFFFE) {
            delay_ms(data);
        } else if (addr == 0xFFFF) {
            return;
        } else {
			sensor_write_register(addr, data);
        }
    }
}

void sensor_init()
{

	//for PLL system register,only writing
	
	
	sensor_write_register(0x0001,0x0030);
	//sensor_write_register(0x0001,0x0018);
	sensor_write_register(0x0002,0x0002);
	sensor_write_register(0x0004,0x0546);
      
	sensor_write_register(0x0000,0x0003);
	sensor_write_register(0x0003,0x8220);
     
      sensor_write_register(0x0000,0x0013);
     
	sensor_write_register(0x0005,0x0000);
    
	sensor_write_register(0x0006,0x2AAA);
	sensor_write_register(0x0007,0x0000);
	sensor_write_register(0x0008,0x0000);
	sensor_write_register(0x0100,0x0697);
	sensor_write_register(0x0101,0x0697);
	sensor_write_register(0x0102,0x0697);
	sensor_write_register(0x0103,0x01A5);
	sensor_write_register(0x0104,0x0000);
	sensor_write_register(0x0105,0x0000);
	sensor_write_register(0x0106,0x0000);
	sensor_write_register(0x0107,0x0000);
	sensor_write_register(0x0108,0x0008);
	sensor_write_register(0x0109,0x0009);
	sensor_write_register(0x010A,0x0696);
	sensor_write_register(0x010B,0x0008);
	sensor_write_register(0x010C,0x0000);
	sensor_write_register(0x010D,0x0008);
	sensor_write_register(0x010E,0x0009);
	sensor_write_register(0x010F,0x0696);
	sensor_write_register(0x0110,0x0000);
	sensor_write_register(0x0111,0x0003);
	sensor_write_register(0x0112,0x0009);
	sensor_write_register(0x0113,0x0696);
	sensor_write_register(0x0114,0x033E);
	sensor_write_register(0x0115,0x0341);
	sensor_write_register(0x0116,0x034F);
	sensor_write_register(0x0117,0x05EF);
	sensor_write_register(0x0118,0x0000);
	sensor_write_register(0x0119,0x0005);
	sensor_write_register(0x011A,0x001F);
	sensor_write_register(0x011B,0x0000);
	sensor_write_register(0x011C,0x0005);
	sensor_write_register(0x011D,0x0013);
	sensor_write_register(0x011E,0x001D);
	sensor_write_register(0x011F,0x001F);
	sensor_write_register(0x0120,0x0000);
	sensor_write_register(0x0121,0x0007);
	sensor_write_register(0x0122,0x0006);
	sensor_write_register(0x0123,0x0000);
	sensor_write_register(0x0124,0x034F);
	sensor_write_register(0x0125,0x05F9);
	sensor_write_register(0x0126,0x0002);
	sensor_write_register(0x0127,0x068F);
	sensor_write_register(0x0130,0x0000);
	sensor_write_register(0x0131,0x0000);
	sensor_write_register(0x0132,0x0000);
	sensor_write_register(0x0133,0x0000);
	sensor_write_register(0x0134,0x0000);
	sensor_write_register(0x0135,0x0605);
	sensor_write_register(0x0136,0x0351);
	sensor_write_register(0x0137,0x0000);
	sensor_write_register(0x0138,0x0000);
	sensor_write_register(0x0139,0x0000);
	sensor_write_register(0x013A,0x0000);
	sensor_write_register(0x0140,0x0009);
	sensor_write_register(0x0141,0x00D0);
	sensor_write_register(0x0142,0x0007);
	sensor_write_register(0x0143,0x031D);
	sensor_write_register(0x0144,0x0008);
	sensor_write_register(0x0145,0x00CF);
	sensor_write_register(0x0146,0x0006);
	sensor_write_register(0x0147,0x031C);
	sensor_write_register(0x0148,0x0000);
	sensor_write_register(0x0149,0x0000);
	sensor_write_register(0x014A,0x0008);
	sensor_write_register(0x014B,0x0006);
	sensor_write_register(0x014C,0x0000);
	sensor_write_register(0x014D,0x0002);
	sensor_write_register(0x014E,0x0002);
	sensor_write_register(0x014F,0x0007);
	sensor_write_register(0x0150,0x0008);
	sensor_write_register(0x0151,0x0006);
	sensor_write_register(0x0152,0x0009);
	sensor_write_register(0x0160,0x0001);
	sensor_write_register(0x0161,0x0004);
	sensor_write_register(0x0162,0x01A5);
	sensor_write_register(0x0163,0x0001);
	sensor_write_register(0x0164,0x0007);
	sensor_write_register(0x0165,0x0017);
	sensor_write_register(0x0166,0x001F);
	sensor_write_register(0x0167,0x0163);
	sensor_write_register(0x0168,0x0003);
	sensor_write_register(0x0169,0x0004);
	sensor_write_register(0x016A,0x0000);
	sensor_write_register(0x016B,0x0000);
	sensor_write_register(0x0170,0x0335);
	sensor_write_register(0x0171,0x0343);
	sensor_write_register(0x0172,0x0000);
	sensor_write_register(0x0173,0x0000);
	sensor_write_register(0x0174,0x0000);
	sensor_write_register(0x0175,0x0000);
	sensor_write_register(0x0176,0x0000);
	sensor_write_register(0x0177,0x0000);
	sensor_write_register(0x0178,0x0000);
	sensor_write_register(0x0179,0x0000);
	sensor_write_register(0x017C,0x0000);
	sensor_write_register(0x017D,0x0000);
	sensor_write_register(0x017E,0x0000);
	sensor_write_register(0x017F,0x0000);
	sensor_write_register(0x0190,0x0007);
	sensor_write_register(0x0191,0x0181);
	sensor_write_register(0x0192,0x0013);
	sensor_write_register(0x0193,0x0015);
	sensor_write_register(0x0194,0x0016);
	sensor_write_register(0x0195,0x0017);
	sensor_write_register(0x0196,0x001B);
	sensor_write_register(0x0197,0x0174);
	sensor_write_register(0x0198,0x0000);
	sensor_write_register(0x0199,0x0174);
	sensor_write_register(0x019A,0x001B);
	sensor_write_register(0x019B,0x0174);
	sensor_write_register(0x01A0,0x0429);
	sensor_write_register(0x01A1,0x0000);
	sensor_write_register(0x01A2,0x0429);
	sensor_write_register(0x01A3,0x041B);
	sensor_write_register(0x01A4,0x0429);
	sensor_write_register(0x01A5,0x041B);
	sensor_write_register(0x01A6,0x0000);
	sensor_write_register(0x01A7,0x041C);
	sensor_write_register(0x01A8,0x0001);
	sensor_write_register(0x01A9,0x0009);
	sensor_write_register(0x01AA,0x0008);
	sensor_write_register(0x01AB,0x0009);
	sensor_write_register(0x01AC,0x0000);
	sensor_write_register(0x01AD,0x041B);
	sensor_write_register(0x01AE,0x0000);
	sensor_write_register(0x01AF,0x0000);
	sensor_write_register(0x01B0,0x0000);
	sensor_write_register(0x01B1,0x041C);
	sensor_write_register(0x01B2,0x0000);
	sensor_write_register(0x01B3,0x0000);
	sensor_write_register(0x01C0,0x0010);
	sensor_write_register(0x01C1,0x0417);
	sensor_write_register(0x01C2,0x0010);
	sensor_write_register(0x01C3,0x0417);
	sensor_write_register(0x01C4,0x0000);
	sensor_write_register(0x01C5,0x0000);
	sensor_write_register(0x01C6,0x0000);
	sensor_write_register(0x01C7,0x0000);
	sensor_write_register(0x01C8,0x000F);
	sensor_write_register(0x01D0,0x0000);
	sensor_write_register(0x01D1,0x0000);
	sensor_write_register(0x01D2,0x0000);
	sensor_write_register(0x01D3,0x0000);
	sensor_write_register(0x01E0,0x000A);
	sensor_write_register(0x01E1,0x0023);
	sensor_write_register(0x01E2,0x0023);
	sensor_write_register(0x01E3,0x0023);
	sensor_write_register(0x01E4,0x0026);
	sensor_write_register(0x01E5,0x0026);
	sensor_write_register(0x01E6,0x0026);
	sensor_write_register(0x01E7,0x004A);
	sensor_write_register(0x01E8,0x008C);
	sensor_write_register(0x01E9,0x008C);
	sensor_write_register(0x01EA,0x008C);
	sensor_write_register(0x01EB,0x0087);
	sensor_write_register(0x01EC,0x00CF);
	sensor_write_register(0x01ED,0x00D8);
	sensor_write_register(0x01EE,0x0116);
	sensor_write_register(0x01EF,0x0324);
	sensor_write_register(0x01F0,0x0003);
	sensor_write_register(0x01F1,0x001F);
	sensor_write_register(0x01F2,0x00B3);
	sensor_write_register(0x01F3,0x01BC);
	sensor_write_register(0x0020,0x0080);
	sensor_write_register(0x0021,0x0000);
	sensor_write_register(0x0022,0x0000);
	sensor_write_register(0x0023,0x000F);
	sensor_write_register(0x0024,0x0000);
	sensor_write_register(0x0025,0x0000);
	sensor_write_register(0x0026,0x0000);
	sensor_write_register(0x0027,0x0000);
	sensor_write_register(0x0028,0x0008);
	sensor_write_register(0x0029,0x0000);
	sensor_write_register(0x0030,0x5420); 
	sensor_write_register(0x0031,0x111A);
	sensor_write_register(0x0032,0x0460);
	sensor_write_register(0x0033,0x0000);
	sensor_write_register(0x0034,0x0000);
	sensor_write_register(0x0035,0x20E0);
	sensor_write_register(0x0036,0x0400);
	sensor_write_register(0x0037,0x0000);
	sensor_write_register(0x003E,0x014E);
	sensor_write_register(0x003F,0x0000);
   //    sensor_write_register(0x003F,0x0731);
	sensor_write_register(0x0040,0x0000);
      sensor_write_register(0x0041,0x0200);
    //   sensor_write_register(0x0041,0x0000);
	sensor_write_register(0x0042,0x0100);
	sensor_write_register(0x0043,0x7057);
	sensor_write_register(0x0046,0x0000);
	sensor_write_register(0x004C,0x0000);
	sensor_write_register(0x004E,0x0FFF);
	sensor_write_register(0x004F,0x0000);
	sensor_write_register(0x0050,0x0FFE);
	sensor_write_register(0x0057,0x0010);
	sensor_write_register(0x005C,0x0038);
	sensor_write_register(0x0060,0x0000);
	sensor_write_register(0x0061,0x0200);
    //   sensor_write_register(0x0061,0x0000);
	sensor_write_register(0x0062,0x0100);
      sensor_write_register(0x0063,0x7057);
	sensor_write_register(0x0066,0x0000);
	sensor_write_register(0x006C,0x0000);
	sensor_write_register(0x006D,0x0000);
	sensor_write_register(0x006E,0x0FFF);
	sensor_write_register(0x006F,0x0000);
	sensor_write_register(0x0070,0x0FFE);
	sensor_write_register(0x0077,0x0010);
	sensor_write_register(0x007C,0x0038);
	sensor_write_register(0x0080,0x000C);
	sensor_write_register(0x0081,0xFFFF);
	sensor_write_register(0x0082,0x0000);
	sensor_write_register(0x0083,0x0000);
	sensor_write_register(0x0084,0x0000);
	sensor_write_register(0x0085,0x0004);
	sensor_write_register(0x0086,0x1032);
	sensor_write_register(0x0087,0x0000);
	sensor_write_register(0x0088,0x0001);
	sensor_write_register(0x0089,0x0000);
	sensor_write_register(0x0090,0x0012);
	sensor_write_register(0x0091,0x0013);
	sensor_write_register(0x0092,0x0010);
	sensor_write_register(0x0093,0x0011);
	sensor_write_register(0x0094,0x0016);
	sensor_write_register(0x0095,0x0017);
	sensor_write_register(0x0096,0x0014);
	sensor_write_register(0x0097,0x0015);
	sensor_write_register(0x0098,0x0002);
	sensor_write_register(0x0099,0x0003);
	sensor_write_register(0x009A,0x0000);
	sensor_write_register(0x009B,0x0001);
	sensor_write_register(0x009C,0x0006);
	sensor_write_register(0x009D,0x0007);
	sensor_write_register(0x009E,0x0004);
	sensor_write_register(0x009F,0x0005);
	sensor_write_register(0x00A0,0x0000);
	sensor_write_register(0x00A1,0x0000);
	sensor_write_register(0x00A2,0x0000);
	sensor_write_register(0x00A3,0x0000);
	sensor_write_register(0x00A4,0x0000);
	sensor_write_register(0x00A9,0x0000);
	sensor_write_register(0x00C0,0x1155);
	sensor_write_register(0x00C1,0xC5D5);
	sensor_write_register(0x00C2,0x93D5);
	sensor_write_register(0x00C3,0x01FC);
	sensor_write_register(0x00C4,0xF041);
	sensor_write_register(0x00C5,0x7FC4);
	sensor_write_register(0x00C6,0x0F54);
	sensor_write_register(0x00C7,0x0051);
	sensor_write_register(0x00C8,0x1541);
	sensor_write_register(0x00C9,0x0200);
	sensor_write_register(0x00CA,0x0100);
	sensor_write_register(0x00CB,0x0000);
	sensor_write_register(0x00CC,0x0000);
	sensor_write_register(0x00CE,0x0000);
	sensor_write_register(0x00D0,0x0000);
	sensor_write_register(0x00D1,0x041B);
	sensor_write_register(0x00D2,0x0000);
	sensor_write_register(0x00D3,0x041B);
	sensor_write_register(0x0000,0x0113);
	sensor_write_register(0x0003,0x8260);
	//printf("-------delay 30ms for TG--------\n");

//	sensor_write_register(0x0000,0x0113);
	//printf("-------sensor MN34031 initial ok!----\n");
}
