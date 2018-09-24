/* 
* MG47 slfs.h -  Common header file
*/

#ifndef _SLFS_H
#define _SLFS_H

// TODO move to individual modules? 
#include <linux/fs.h>
#include <linux/mount.h>
#include <linux/dcache.h>

#define SLFS_NAME "slfs"
#define SLFS_MAGIC 0x534c4653 /* 'SLFS' */

extern const struct dentry_operations slfs_dentry_ops;

struct dentry *slfs_mount(struct file_system_type *fs_type,
						int flags, const char *dev_name, void *raw_data);
void slfs_kill_sb(struct super_block *sb);

extern const struct file_operations slfs_file_ops;

#endif /* _SLFS_H */
