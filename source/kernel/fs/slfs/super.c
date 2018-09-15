/*
*	MG47 : Superblock Operations for slfs
*/

#include <linux/init.h>
#include <linux/module.h>

#include <slfs.h>

static struct dentry *slfs_mount(struct vfsmount *mnt,
				 struct file_system_type *fs_type, int flags,
				 const char *dev_name, void *raw_data)
{
	//TODO
	struct dentry *dent;
	dent = NULL;
	return dent;
}

void slfs_kill_sb(struct super_block *sb)
{
	//TODO
}

static struct file_system_type slfs_fs_type = {
	.owner = THIS_MODULE,
	.name = SLFS_NAME,
	//TODO why mount2
	.mount2 = slfs_mount,
	.kill_sb = slfs_kill_sb,	
};

static int __init slfs_init(void)
{
	int ret;
	pr_info("MG47 slfs: initializing slfs \n");

	/* Register Filesystem */
	ret = register_filesystem(&slfs_fs_type);
	if (ret) {
		pr_err("MG47 slfs: error: Could not register filesystem\n");
		goto init_error;
	}
	pr_info("MG47 slfs: registered slfs \n");
init_error:
		    return 0;
}

static void __exit slfs_exit(void)
{
	pr_info("MG47 slfs: exiting slfs \n");
	//TODO superblock cleanup, unregister filesystem
}

//TODO fs init? 
module_init(slfs_init);
module_exit(slfs_exit);
