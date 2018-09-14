/*
	MG47 : Superblock Operations for slfs
*/

#include <linux/init.h>
#include <linux/module.h>

static int __init slfs_init(void)
{
	pr_alert("MG47: initializing slfs \n");
	return 0;
}

static void __exit slfs_exit(void)
{
	pr_alert("MG47: exiting slfs \n");
}

module_init(slfs_init);
module_exit(slfs_exit);
