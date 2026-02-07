#include <zephyr/kernel.h>

int
main(void) {

  while (1) {
    printk("bonjour\n");
    k_sleep(K_SECONDS(2));
  }

  return 0;
}
