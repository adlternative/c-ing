#include <arpa/inet.h>  // 'struct sockaddr_in'
#include <errno.h>
#include <net/if.h>  // 'struct ifreq' and 'struct if_nameindex'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>  // ioctl
#include <unistd.h>

int GetInterfaceIp(const char *eth_inf, char *ip) {
  int sd;
  struct sockaddr_in sin;
  struct ifreq ifr;

  sd = socket(AF_INET, SOCK_DGRAM, 0);
  if (-1 == sd) {
    printf("socket error: %s\n", strerror(errno));
    return -1;
  }

  strncpy(ifr.ifr_name, eth_inf, IFNAMSIZ);
  ifr.ifr_name[IFNAMSIZ - 1] = 0;

  // if error: No such device
  if (ioctl(sd, SIOCGIFADDR, &ifr) < 0) {
    printf("iterfac %s ioctl error: %s\n", eth_inf, strerror(errno));
    close(sd);
    return -1;
  }

  printf("interfac: %s, ip: %s\n", eth_inf,
         inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));

  close(sd);
  return 0;
}

void GetAllInterfaceNames() {
  struct if_nameindex *if_nidxs, *intf;

  // the begin of if_name index.
  if_nidxs = if_nameindex();
  if (if_nidxs != NULL) {
    for (intf = if_nidxs; intf->if_index != 0 || intf->if_name != NULL;
         intf++) {
      char ip[1024];
      GetInterfaceIp(intf->if_name, ip);
    }

    if_freenameindex(if_nidxs);
  }
}

int main() {
  GetAllInterfaceNames();
  return 0;
}

