/*
*	MG47 : superblock operations for slfs
* TODO : replace pr_alert with pr_info
*/

#include <slfs.h>

static const struct super_operations slfs_super_ops = {

};

static int slfs_fill_super(struct super_block *sb,
				void *data, int silent)
{
	struct inode *inode;
	struct dentry *root;
	pr_alert("MG47 slfs: filling supeblock \n");
	if (!sb) {
		pr_err("MG47 slfs: error: sb is NULL \n");
		return -1;
	}

	sb->s_magic = SLFS_MAGIC;
	sb->s_op = &slfs_super_ops;

	inode = new_inode(sb);
	if (!inode) {
		pr_err("MG47 slfs: error: could not allocate new inode for superblock \n");
	} else	{
		pr_alert("MG47 slfs: created new inode for superblock \n");
	}

	root = d_make_root(inode);
	if (!root) {
		pr_err("MG47 slfs: error: could not create root \n");
	} else {
		pr_alert("MG47 slfs: made new root \n");
	}

	sb->s_root = root;
	sb->s_d_op = &slfs_dentry_ops;


	/* Create stats file */

	return 0;
}

/* mount function for slfs */
/* TODO Fill raw data with mount options */
struct dentry *slfs_mount(struct file_system_type *fs_type, 
				int flags, const char *dev_name, void *raw_data)
{
	struct dentry *dent;
	pr_alert("MG47 slfs: mouting slfs \n");
	/* Use mount_nodev as slfs is not device-based */
	//TODO cehck raw-data
	dent = mount_nodev(fs_type, flags, raw_data, slfs_fill_super);
	pr_alert("MG47 slfs: Mounted slfs \n");

	return dent;
}

void slfs_kill_sb(struct super_block *sb)
{
	//TODO
	pr_alert("MG47 slfs: Killing Superblock \n");
	kill_anon_super(sb);
}

