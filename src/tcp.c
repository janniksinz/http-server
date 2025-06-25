#include "tcp.h"
#include "main.h"

server_status_e bind_tcp_port(tcp_server *server, int port) {
	memset(server, 0, sizeof(*server));
	server->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server->socket_fd == -1){
		debug_log("tcp: socket creation failed");
		return SERVER_SOCKET_ERROR;
	}

	server->address.sin_family = AF_INET;
	server->address.sin_addr.s_addr = INADDR_ANY;
	server->address.sin_port = htons(port);
}
