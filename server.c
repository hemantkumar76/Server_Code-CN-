// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd, new_sock;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[100];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error in socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);                   // Choose any available port for communication
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost

    // Bind socket to the specified IP and port
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error in bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(sockfd, 10);

    printf("Server listening...\n");

    // connection accept karega client se
    addr_size = sizeof(new_addr);
    new_sock = accept(sockfd, (struct sockaddr *)&new_addr, &addr_size);

        // client se message revieve karega into terminal
    recv(new_sock, buffer, sizeof(buffer), 0);
    printf("Message from client: %s\n", buffer);

    // Close sockets
    close(new_sock);
    close(sockfd);




    return 0;
}
