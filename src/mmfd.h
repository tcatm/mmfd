#pragma once

#include "vector.h"

#include <stdint.h>
#include <stdbool.h>
#include <netinet/in.h>

#define PORT 27275

struct context {
  int efd;
  int tunfd;
  int babelfd;
  int babeld_reconnect_tfd;
  int udpfd;
  char *babeld_buffer;
  VECTOR(struct neighbor) neighbors;
  VECTOR(uint64_t) seen;
};

struct __attribute__((__packed__)) header {
  uint32_t nonce;
};

struct neighbor {
  struct sockaddr_in6 address;
  char *ifname;
  int reach;
  int cost;
};
