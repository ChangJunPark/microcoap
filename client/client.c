// light GET    : 40 01 <a5 8a> b5 6c 69 67 68 74 c1 02
// light POST   : 40 02 <51 d0> b5 6c 69 67 68 74 ff 31
// light PUT    : 40 03 <61 12> b5 6c 69 67 68 74 ff 31
// light DELETE : 40 04 <9a 7e> b5 6c 69 67 68 74
// light HEAD   : 40 05 <a5 8a> b5 6c 69 67 68 74
// light OPTIONS: 40 06 <a5 8a> b5 6c 69 67 68 74
// light TRACE  : 40 07 <a5 8a> b5 6c 69 67 68 74

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

void dump(const uint8_t *buf, int len)
{
  while(len--)
            printf("%02X%s", *buf++, (len > 0) ? " " : "\n");
}


int getMethodCode(char * str){
	if(*str=='G')
		return 1;
	else if(*str=='P'){
		if(*(++str)=='O')
			return 2;
		else
			return 3;
	}
	else if(*str=='D')
		return 4;
	else if(*str=='H')
		return 5;
	else if(*str=='O')
		return 6;
	else if(*str=='T')
		return 7;
	else
		return -1;
}

int main( int argc, char *argv[])
{
   int	sock;
   int	server_addr_size;

   struct	sockaddr_in   server_addr;

   int send_size = 0;
   int rcv_size = 0;
   uint8_t	buff_send[12];
   uint8_t	buff_rcv[BUF_SIZE+5];


   sock = socket( PF_INET, SOCK_DGRAM, 0);

   if( -1 == sock)
   {
      printf( "socket 생성 실패n");
      exit( 1);
   }

   memset( &server_addr, 0, sizeof( server_addr));
   server_addr.sin_family     = AF_INET;
   server_addr.sin_port       = htons(5683);
   server_addr.sin_addr.s_addr= inet_addr( "127.0.0.1");


   switch(getMethodCode(argv[1])){
	   case 1:
           buff_send[0] = 0x40; 
           buff_send[1] = 0x01;
           buff_send[2] = 0xa5;
           buff_send[3] = 0x8a;
           buff_send[4] = 0xb5;
           buff_send[5] = 0x6c;
           buff_send[6] = 0x69;
           buff_send[7] = 0x67;
           buff_send[8] = 0x68;
           buff_send[9] = 0x74;
           buff_send[10] =0xc1;
           buff_send[11] =0x02;
		   send_size = 12;
		   break;
   	   case 2:
   		   if(*argv[2] == '1'){
               buff_send[0] = 0x40;
               buff_send[1] = 0x02;
               buff_send[2] = 0x51;
               buff_send[3] = 0xd0;
               buff_send[4] = 0xb5;
               buff_send[5] = 0x6c;
               buff_send[6] = 0x69;
               buff_send[7] = 0x67;
               buff_send[8] = 0x68;
               buff_send[9] = 0x74;
               buff_send[10] =0xff;
               buff_send[11] =0x31;
            }
   		   else{
               buff_send[0] = 0x40;
               buff_send[1] = 0x02;
               buff_send[2] = 0x51;
               buff_send[3] = 0xd0;
               buff_send[4] = 0xb5;
               buff_send[5] = 0x6c;
               buff_send[6] = 0x69;
               buff_send[7] = 0x67;
               buff_send[8] = 0x68;
               buff_send[9] = 0x74;
               buff_send[10] =0xff;
               buff_send[11] =0x30;
           }
   		   send_size = 12;
   		   break;
   	   case 3:
   		   if(*argv[2] == '1'){
               buff_send[0] = 0x40;
               buff_send[1] = 0x03;
               buff_send[2] = 0x51;
               buff_send[3] = 0xd0;
               buff_send[4] = 0xb5;
               buff_send[5] = 0x6c;
               buff_send[6] = 0x69;
               buff_send[7] = 0x67;
               buff_send[8] = 0x68;
               buff_send[9] = 0x74;
               buff_send[10] =0xff;
               buff_send[11] =0x31;
            }
   		   else{
               buff_send[0] = 0x40;
               buff_send[1] = 0x03;
               buff_send[2] = 0x51;
               buff_send[3] = 0xd0;
               buff_send[4] = 0xb5;
               buff_send[5] = 0x6c;
               buff_send[6] = 0x69;
               buff_send[7] = 0x67;
               buff_send[8] = 0x68;
               buff_send[9] = 0x74;
               buff_send[10] =0xff;
               buff_send[11] =0x30;
            }
   		   send_size = 12;
   		   break;
   	   case 4:
           buff_send[0] = 0x40; 
           buff_send[1] = 0x04;
           buff_send[2] = 0xa5;
           buff_send[3] = 0x8a;
           buff_send[4] = 0xb5;
           buff_send[5] = 0x6c;
           buff_send[6] = 0x69;
           buff_send[7] = 0x67;
           buff_send[8] = 0x68;
           buff_send[9] = 0x74;
   		   send_size = 10;
   		   break;
   	   case 5:
           buff_send[0] = 0x40; 
           buff_send[1] = 0x05;
           buff_send[2] = 0xa5;
           buff_send[3] = 0x8a;
           buff_send[4] = 0xb5;
           buff_send[5] = 0x6c;
           buff_send[6] = 0x69;
           buff_send[7] = 0x67;
           buff_send[8] = 0x68;
           buff_send[9] = 0x74;
   		   send_size = 10;
   		   break;
   	   case 6:
           buff_send[0] = 0x40; 
           buff_send[1] = 0x06;
           buff_send[2] = 0xa5;
           buff_send[3] = 0x8a;
           buff_send[4] = 0xb5;
           buff_send[5] = 0x6c;
           buff_send[6] = 0x69;
           buff_send[7] = 0x67;
           buff_send[8] = 0x68;
           buff_send[9] = 0x74;
   		   send_size = 10;
   		   break;
   	   case 7:
           buff_send[0] = 0x40; 
           buff_send[1] = 0x07;
           buff_send[2] = 0xa5;
           buff_send[3] = 0x8a;
           buff_send[4] = 0xb5;
           buff_send[5] = 0x6c;
           buff_send[6] = 0x69;
           buff_send[7] = 0x67;
           buff_send[8] = 0x68;
           buff_send[9] = 0x74;
   		   send_size = 10;
   		   break;
   	   case -1:
   		   printf("argv[1] : Method err\n");
		   exit(1);
   		   break;
   }


   printf( "send: %d\n", send_size);
   dump(buff_send,send_size);
   sendto( sock, buff_send, send_size, 0, ( struct sockaddr*)&server_addr, sizeof( server_addr));

   server_addr_size  = sizeof( server_addr);
   rcv_size = recvfrom( sock, buff_rcv, BUF_SIZE, 0 , ( struct sockaddr*)&server_addr, &server_addr_size);
   printf( "receive: %d\n", rcv_size);
   dump(buff_rcv,rcv_size);
   close( sock);

   return 0;
}
