/*
*	MG47 : Entry/exit for slfs
* TODO : replace pr_alert with pr_info
*/

#include <linux/init.h>
#include <linux/module.h>

#include <slfs.h>

static struct file_system_type slfs_fs_type = {
	.owner = THIS_MODULE,
	.name = SLFS_NAME,
	.mount = slfs_mount,
	.kill_sb = slfs_kill_sb,
	.next = NULL,
};

static int __init slfs_init(void)
{
	int ret;
	pr_alert("MG47 slfs: initializing slfs \n");

	/* Register Filesystem */
	ret = register_filesystem(&slfs_fs_type);
	if (ret) {
		pr_err("MG47 slfs: error: Could not register filesystem\n");
		return 0;
	}
	pr_alert("MG47 slfs: registered slfs \n");
	return 0;
}

static void __exit slfs_exit(void)
{
	int ret;
	pr_alert("MG47 slfs: exiting slfs \n");

	/* Unregister filesystem */
	ret = unregister_filesystem(&slfs_fs_type);
	if (ret) {
		pr_err("MG47 slfs: error: Could not unregister filesystem\n");
		return;
	}
	pr_alert("MG47 slfs: unregistered slfs \n");
}

//TODO fs init?
module_init(slfs_init);
module_exit(slfs_exit);
