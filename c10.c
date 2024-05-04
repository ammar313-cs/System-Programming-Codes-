#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<string.h>



int main() {
int S_sockfd, C_sockfd;
int S_len,    C_len;
struct sockaddr_un S_address;
struct sockaddr_un C_address;
     int result;
    char ch='A';
    unlink("server_socket");

/* pathname */
S_sockfd= socket(AF_UNIX, SOCK_STREAM, 0);
S_address.sun_family = AF_UNIX;
 strcpy(S_address.sun_path, "server_socket");
S_len = sizeof(S_address);
bind(S_sockfd, (struct sockaddr *) &S_address, S_len);
listen(S_sockfd, 5);



while(1) { char ch;
         printf("Server %d waiting\n",getpid());
C_len = sizeof(C_address);
C_sockfd = accept(S_sockfd, (struct sockaddr *) &C_address, &C_len);
read(C_sockfd, &ch, 1); /* Caution: Error Checking skipped */ ch++;
write(C_sockfd, &ch, 1);
close(C_sockfd);
} exit(0);

}