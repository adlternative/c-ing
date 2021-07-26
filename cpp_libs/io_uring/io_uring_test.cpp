#include <fcntl.h>
#include <fmt/core.h>
#include <linux/fs.h>
#include <linux/io_uring.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/uio.h>
#include <tuple>
#include <unistd.h>
int io_uring_setup(unsigned entries, struct io_uring_p *p) {
  return (int)syscall(__NR_io_uring_setup, entries, p);
}
#define QUEUE_DEPTH 1
#include <iostream>

int main(int argc, char **argv) {
  struct io_uring_p p = {};
  int ring_fd = io_uring_setup(QUEUE_DEPTH, &p); // 3
  /*
   *	struct io_uring_p {
   *   __u32 sq_entries; 1
   *   __u32 cq_entries; 2
   *   __u32 flags; 0
   *   __u32 sq_thread_cpu; 0
   *   __u32 sq_thread_idle; 0
   *   __u32 features; 1023
   *   __u32 wq_fd; 0
   *   __u32 resv[3]; 0 0 0
   *   struct io_sqring_offsets sq_off;
   *   {head = 0, tail = 64, ring_mask = 256, ring_entries =
   * 264, flags = 276, dropped = 272, array = 384, resv1 = 0, resv2 = 0}
   *   struct io_cqring_offsets cq_off;
   *   {head = 128, tail = 192, ring_mask = 260, ring_entries
   * = 268, overflow = 284, cqes = 320, flags = 280, resv1 = 0, resv2 = 0}
   * };
   */
  void *subqueue = mmap(0, p.sq_off.array + p.sq_entries * sizeof(__u32),
                        PROT_READ | PROT_WRITE | MAP_SHARED | MAP_POPULATE,
                        ring_fd, IORING_OFF_SQ_RING);
  void *sqentries = mmap(0, p.sq_entries * sizeof(struct io_uring_sqe),
                         PROT_READ | PROT_WRITE | MAP_SHARED | MAP_POPULATE,
                         ring_fd, IORING_OFF_SQES);
}