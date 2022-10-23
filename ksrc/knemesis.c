#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init knemesis_init(void)
{
    printk(KERN_INFO "knemesis is starting\n");
    return 0;
}

static void __exit knemesis_exit(void)
{
    printk(KERN_INFO "knemesis is exiting\n");
}


module_init(knemesis_init);
module_exit(knemesis_exit);