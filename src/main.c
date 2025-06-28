#include "main.h"
#include "tcp.h"
#include <stdlib.h>

int main() {
	tcp_server server = {0};
	server_status_e status = bind_tcp_port(&server, 8080);
	if (status != SERVER_OK) {
		debug_log("main: Server initialization failed");
		exit(EXIT_FAILURE);
	}

	int client_fd = accept_client(server.socket_fd);
	if (client_fd == -1) {
		debug_log("main: failed to accept client connection");
		close(server.socket_fd);
		exit(EXIT_FAILURE);
	}

	debug_log("Client connected!");

	close(client_fd);
	close(server.socket_fd);
	return 0;
}
