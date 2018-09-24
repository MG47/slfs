/*
*	MG47 : file operations for slfs
*
*/

#include <slfs.h>

static int slfs_file_open(struct inode *inode, struct file *file)
{
	pr_alert("MG47 slfs: slfs_file_open ... \n");
	return 0;
}

static ssize_t slfs_file_write(struct file *file, const char __user *buf,
			       size_t count, loff_t *ppos)
{
	pr_alert("MG47 slfs: slfs_file_write ... \n");
	return 1;
}

static ssize_t slfs_file_read(struct file *file, char __user *buf,
			      size_t count, loff_t *ppos)
{
	pr_alert("MG47 slfs: slfs_file_read ... \n");
	return 0;
}

const struct file_operations slfs_file_ops = {
	.open = slfs_file_open,
	.write = slfs_file_write,
	.read = slfs_file_read,
};
