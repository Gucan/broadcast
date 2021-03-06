#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
	int sock = -1;
	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		printf("socket error\n");
		return 1;
	}
	const int opt = 1;
	//设置该套接字为广播类型
	int nb = -1;
	nb = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char *)&opt, sizeof(opt));
	if(nb == -1) {
		printf("set socket error\n");
		return 1;
	}
	struct sockaddr_in addrto;
	bzero(&addrto, sizeof(struct sockaddr_in));
	addrto.sin_family=AF_INET;
	addrto.sin_addr.s_addr=htonl(INADDR_BROADCAST);
	addrto.sin_port=htons(6000);
	int nlen=sizeof(addrto);
	char msg[4096];
	while(1) {
		//从广播地址发送消息
		printf("input: ");
		scanf("%s",msg);
		int ret=sendto(sock, msg, strlen(msg), 0, (struct sockaddr *)&addrto, nlen);
		if(ret<0) {  
			printf("send error....\n");
		} else {
			printf("ok\n");
		}
	}
	return 0;
}
