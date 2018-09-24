/*
*	MG47 : superblock operations for slfs
* TODO : replace pr_alert with pr_info
*/

#include <slfs.h>

static struct tree_descr OurFiles[] = {
	{.name = "stats", 
	 .ops = &slfs_file_ops,
	 .mode = S_IWUSR | S_IRUGO},
	{"", NULL, 0} /* Terminates the list */
};

static int slfs_fill_super(struct super_block *sb, void *data, int silent)
{
	int ret;
	struct dentry *new_dent;
	struct inode *inode;

	ret = simple_fill_super(sb, SLFS_MAGIC, OurFiles);
	if (ret) {
		pr_err("MG47 slfs: error: could not fill superblock \n");
		return ret;
	}

	/* Create procs/ directory */
	inode = new_inode(sb);
	if (!inode) {
		pr_err("MG47 slfs: error: could not allocate new inode \n");
		return -1;
	}
	inode->i_ino = 2;
	inode->i_mode = S_IFDIR | S_IWUSR | S_IRUGO;
	inode->i_fop = &slfs_file_ops;

	new_dent = d_alloc_name(sb->s_root, "procs");
	if (!new_dent) {
		pr_err("MG47 slfs: error: could not allocate new dentry \n");
		return -1;
	}
	d_add(new_dent, inode);
	pr_alert("MG47 slfs: done with procs \n");

	/* Create 'out' file */
	inode = new_inode(sb);
	if (!inode) {
		pr_err("MG47 slfs: error: could not allocate new inode \n");
		return -1;
	}
	inode->i_ino = 3;
	inode->i_mode = S_IFREG | S_IWUSR | S_IRUGO;
	inode->i_fop = &slfs_file_ops;

	new_dent = d_alloc_name(sb->s_root, "out");
	if (!new_dent) {
		pr_err("MG47 slfs: error: could not allocate new dentry \n");
		return -1;
	}
	d_add(new_dent, inode);
	pr_alert("MG47 slfs: done with procs \n");

	return ret;
}

/* mount function for slfs */
/* TODO Fill raw data with mount options */
struct dentry *slfs_mount(struct file_system_type *fs_type, 
				int flags, const char *dev_name, void *raw_data)
{
	struct dentry *dent;
	pr_alert("MG47 slfs: mouting slfs \n");
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

