#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

struct tcp_client {
	char dest_ip[32];
	uint16_t dest_port;
	int sock;

	int (*connection_made)(struct tcp_client *)
};

typedef struct tcp_client tcp_client_t;

struct tcp_request {
	uint32_t reqid;
	int (*sent)(struct tcp_request *, size_t sentsize, int errno);
};

typedef struct tcp_request tcp_request_t;

struct tcp_response {
	tcp_request_t *req;
	void *user_arg;
	int (*user_resp)(struct tcp_response *, void *arg);
};

typedef struct tcp_response tcp_response_t;

tcp_client_t * tcp_client_init()
{
	return NULL;
}

int tcp_client_connect(tcp_client_t *client)
{
	assert(client != NULL);
	return 0;
}

int tcp_client_recv(tcp_client_t *client)
{
}

int tcp_client_send()
{
}

int tcp_client_add_request(tcp_request_t *req)
{
}
