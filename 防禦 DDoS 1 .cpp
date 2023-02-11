#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " PORT\n";
        return -1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Failed to create socket\n";
        return -1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(atoi(argv[1]));

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        std::cerr << "Failed to bind socket\n";
        return -1;
    }

    if (listen(sock, SOMAXCONN) < 0) {
        std::cerr << "Failed to listen\n";
        return -1;
    }

    while (true) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            std::cerr << "Failed to accept connection\n";
            continue;
        }
        std::cout << "Accepted connection\n";
        close(client_sock);
    }

    close(sock);

    return 0;
}
