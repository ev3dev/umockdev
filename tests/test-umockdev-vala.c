/* test-umockdev-vala.c generated by valac 0.20.1, the Vala compiler
 * generated from test-umockdev-vala.vala, do not modify */

/*
 * test-umockdev.vala
 *
 * Copyright (C) 2012 Canonical Ltd.
 * Author: Martin Pitt <martin.pitt@ubuntu.com>
 *
 * umockdev is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * umockdev is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; If not, see <http://www.gnu.org/licenses/>.
 */

#include <glib.h>
#include <glib-object.h>
#include <umockdev.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gudev/gudev.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include "linux/usbdevice_fs.h"
#include <errno.h>
#include <unistd.h>
#include <glib/gstdio.h>
#include <sys/stat.h>

#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define __g_list_free__g_object_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_object_unref0_ (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _vala_assert(expr, msg) if G_LIKELY (expr) ; else g_assertion_message_expr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);



void tb_add_from_string (UMockdevTestbed* tb, const gchar* s);
void t_testbed_empty (void);
static void _g_object_unref0_ (gpointer var);
static void _g_list_free__g_object_unref0_ (GList* self);
void t_testbed_add_device (void);
void t_testbed_gudev_query_list (void);
void t_usbfs_ioctl_static (void);
void t_usbfs_ioctl_tree (void);
static guint8* _vala_array_dup1 (guint8* self, int length);
void t_usbfs_ioctl_tree_xz (void);
void t_tty_stty (void);
void t_tty_data (void);
gint _vala_main (gchar** args, int args_length1);
static void _t_testbed_empty_gtest_func (void);
static void _t_testbed_add_device_gtest_func (void);
static void _t_testbed_gudev_query_list_gtest_func (void);
static void _t_usbfs_ioctl_static_gtest_func (void);
static void _t_usbfs_ioctl_tree_gtest_func (void);
static void _t_usbfs_ioctl_tree_xz_gtest_func (void);
static void _t_tty_stty_gtest_func (void);
static void _t_tty_data_gtest_func (void);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


void tb_add_from_string (UMockdevTestbed* tb, const gchar* s) {
	GError * _inner_error_ = NULL;
	g_return_if_fail (tb != NULL);
	g_return_if_fail (s != NULL);
	{
		UMockdevTestbed* _tmp0_;
		const gchar* _tmp1_;
		gboolean _tmp2_ = FALSE;
		gboolean _tmp3_;
		_tmp0_ = tb;
		_tmp1_ = s;
		_tmp2_ = umockdev_testbed_add_from_string (_tmp0_, _tmp1_, &_inner_error_);
		_tmp3_ = _tmp2_;
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
		_vala_assert (_tmp3_, "tb.add_from_string (s)");
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		FILE* _tmp4_;
		const gchar* _tmp5_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp4_ = stderr;
		_tmp5_ = e->message;
		fprintf (_tmp4_, "Failed to call Testbed.add_from_string(): %s\n", _tmp5_);
		abort ();
		_g_error_free0 (e);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _g_list_free__g_object_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_object_unref0_, NULL);
	g_list_free (self);
}


void t_testbed_empty (void) {
	UMockdevTestbed* _tmp0_;
	UMockdevTestbed* tb;
	GUdevClient* _tmp1_;
	GUdevClient* _tmp2_;
	GUdevEnumerator* _tmp3_;
	GUdevEnumerator* _tmp4_;
	GUdevEnumerator* enumerator;
	GList* _tmp5_ = NULL;
	GList* devices;
	guint _tmp6_ = 0U;
	_tmp0_ = umockdev_testbed_new ();
	tb = _tmp0_;
	_vala_assert (tb != NULL, "tb != null");
	_tmp1_ = g_udev_client_new (NULL);
	_tmp2_ = _tmp1_;
	_tmp3_ = g_udev_enumerator_new (_tmp2_);
	_tmp4_ = _tmp3_;
	_g_object_unref0 (_tmp2_);
	enumerator = _tmp4_;
	_tmp5_ = g_udev_enumerator_execute (enumerator);
	devices = _tmp5_;
	_tmp6_ = g_list_length (devices);
	g_assert_cmpuint (_tmp6_, ==, (guint) 0);
	__g_list_free__g_object_unref0_0 (devices);
	_g_object_unref0 (enumerator);
	_g_object_unref0 (tb);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void t_testbed_add_device (void) {
	UMockdevTestbed* _tmp0_;
	UMockdevTestbed* tb;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar** _tmp5_ = NULL;
	gchar** _tmp6_;
	gint _tmp6__length1;
	gchar* _tmp7_;
	gchar* _tmp8_;
	gchar* _tmp9_;
	gchar* _tmp10_;
	gchar** _tmp11_ = NULL;
	gchar** _tmp12_;
	gint _tmp12__length1;
	gchar* _tmp13_ = NULL;
	gchar* _tmp14_;
	gchar* syspath;
	GUdevClient* _tmp15_;
	GUdevClient* _tmp16_;
	GUdevEnumerator* _tmp17_;
	GUdevEnumerator* _tmp18_;
	GUdevEnumerator* enumerator;
	GList* _tmp19_ = NULL;
	GList* devices;
	guint _tmp20_ = 0U;
	gconstpointer _tmp21_ = NULL;
	GUdevDevice* _tmp22_;
	GUdevDevice* device;
	const gchar* _tmp23_ = NULL;
	const gchar* _tmp24_ = NULL;
	const gchar* _tmp25_ = NULL;
	const gchar* _tmp26_ = NULL;
	const gchar* _tmp27_ = NULL;
	const gchar* _tmp28_ = NULL;
	const gchar* _tmp29_ = NULL;
	const gchar* _tmp30_ = NULL;
	const gchar* _tmp31_ = NULL;
	const gchar* _tmp32_ = NULL;
	const gchar* _tmp33_ = NULL;
	_tmp0_ = umockdev_testbed_new ();
	tb = _tmp0_;
	_tmp1_ = g_strdup ("idVendor");
	_tmp2_ = g_strdup ("0815");
	_tmp3_ = g_strdup ("idProduct");
	_tmp4_ = g_strdup ("AFFE");
	_tmp5_ = g_new0 (gchar*, 4 + 1);
	_tmp5_[0] = _tmp1_;
	_tmp5_[1] = _tmp2_;
	_tmp5_[2] = _tmp3_;
	_tmp5_[3] = _tmp4_;
	_tmp6_ = _tmp5_;
	_tmp6__length1 = 4;
	_tmp7_ = g_strdup ("ID_INPUT");
	_tmp8_ = g_strdup ("1");
	_tmp9_ = g_strdup ("ID_INPUT_KEYBOARD");
	_tmp10_ = g_strdup ("1");
	_tmp11_ = g_new0 (gchar*, 4 + 1);
	_tmp11_[0] = _tmp7_;
	_tmp11_[1] = _tmp8_;
	_tmp11_[2] = _tmp9_;
	_tmp11_[3] = _tmp10_;
	_tmp12_ = _tmp11_;
	_tmp12__length1 = 4;
	_tmp13_ = umockdev_testbed_add_devicev (tb, "usb", "extkeyboard1", NULL, _tmp6_, _tmp12_);
	_tmp14_ = _tmp13_;
	_tmp12_ = (_vala_array_free (_tmp12_, _tmp12__length1, (GDestroyNotify) g_free), NULL);
	_tmp6_ = (_vala_array_free (_tmp6_, _tmp6__length1, (GDestroyNotify) g_free), NULL);
	syspath = _tmp14_;
	g_assert_cmpstr (syspath, ==, "/sys/devices/extkeyboard1");
	_tmp15_ = g_udev_client_new (NULL);
	_tmp16_ = _tmp15_;
	_tmp17_ = g_udev_enumerator_new (_tmp16_);
	_tmp18_ = _tmp17_;
	_g_object_unref0 (_tmp16_);
	enumerator = _tmp18_;
	_tmp19_ = g_udev_enumerator_execute (enumerator);
	devices = _tmp19_;
	_tmp20_ = g_list_length (devices);
	g_assert_cmpuint (_tmp20_, ==, (guint) 1);
	_tmp21_ = g_list_nth_data (devices, (guint) 0);
	_tmp22_ = _g_object_ref0 ((GUdevDevice*) _tmp21_);
	device = _tmp22_;
	_tmp23_ = g_udev_device_get_name (device);
	g_assert_cmpstr (_tmp23_, ==, "extkeyboard1");
	_tmp24_ = g_udev_device_get_sysfs_path (device);
	g_assert_cmpstr (_tmp24_, ==, "/sys/devices/extkeyboard1");
	_tmp25_ = g_udev_device_get_subsystem (device);
	g_assert_cmpstr (_tmp25_, ==, "usb");
	_tmp26_ = g_udev_device_get_sysfs_attr (device, "idVendor");
	g_assert_cmpstr (_tmp26_, ==, "0815");
	_tmp27_ = g_udev_device_get_sysfs_attr (device, "idProduct");
	g_assert_cmpstr (_tmp27_, ==, "AFFE");
	_tmp28_ = g_udev_device_get_sysfs_attr (device, "noSuchAttr");
	g_assert_cmpstr (_tmp28_, ==, NULL);
	_tmp29_ = g_udev_device_get_property (device, "DEVPATH");
	g_assert_cmpstr (_tmp29_, ==, "/devices/extkeyboard1");
	_tmp30_ = g_udev_device_get_property (device, "SUBSYSTEM");
	g_assert_cmpstr (_tmp30_, ==, "usb");
	_tmp31_ = g_udev_device_get_property (device, "ID_INPUT");
	g_assert_cmpstr (_tmp31_, ==, "1");
	_tmp32_ = g_udev_device_get_property (device, "ID_INPUT_KEYBOARD");
	g_assert_cmpstr (_tmp32_, ==, "1");
	_tmp33_ = g_udev_device_get_property (device, "NO_SUCH_PROP");
	g_assert_cmpstr (_tmp33_, ==, NULL);
	_g_object_unref0 (device);
	__g_list_free__g_object_unref0_0 (devices);
	_g_object_unref0 (enumerator);
	_g_free0 (syspath);
	_g_object_unref0 (tb);
}


void t_testbed_gudev_query_list (void) {
	UMockdevTestbed* _tmp0_;
	UMockdevTestbed* tb;
	UMockdevTestbed* _tmp1_;
	GUdevClient* _tmp2_;
	GUdevClient* client;
	GUdevClient* _tmp3_;
	GList* _tmp4_ = NULL;
	GList* devices;
	GList* _tmp5_;
	guint _tmp6_ = 0U;
	GList* _tmp7_;
	_tmp0_ = umockdev_testbed_new ();
	tb = _tmp0_;
	_tmp1_ = tb;
	tb_add_from_string (_tmp1_, "P: /devices/myusbhub/cam\n" \
"N: bus/usb/001/002\n" \
"E: SUBSYSTEM=usb\n" \
"E: DEVTYPE=usb_device\n" \
"E: DEVNAME=/dev/bus/usb/001/002\n" \
"\n" \
"P: /devices/myusbhub\n" \
"N: bus/usb/001/001\n" \
"E: SUBSYSTEM=usb\n" \
"E: DEVTYPE=usb_device\n" \
"E: DEVNAME=/dev/bus/usb/001/001\n");
	_tmp2_ = g_udev_client_new (NULL);
	client = _tmp2_;
	_tmp3_ = client;
	_tmp4_ = g_udev_client_query_by_subsystem (_tmp3_, NULL);
	devices = _tmp4_;
	_tmp5_ = devices;
	_tmp6_ = g_list_length (_tmp5_);
	g_assert_cmpuint (_tmp6_, ==, (guint) 2);
	_tmp7_ = devices;
	{
		GList* dev_collection = NULL;
		GList* dev_it = NULL;
		dev_collection = _tmp7_;
		for (dev_it = dev_collection; dev_it != NULL; dev_it = dev_it->next) {
			GUdevDevice* _tmp8_;
			GUdevDevice* dev = NULL;
			_tmp8_ = _g_object_ref0 ((GUdevDevice*) dev_it->data);
			dev = _tmp8_;
			{
				GUdevDevice* _tmp9_;
				const gchar* _tmp10_ = NULL;
				GUdevDevice* _tmp11_;
				const gchar* _tmp12_ = NULL;
				_tmp9_ = dev;
				_tmp10_ = g_udev_device_get_subsystem (_tmp9_);
				g_assert_cmpstr (_tmp10_, ==, "usb");
				_tmp11_ = dev;
				_tmp12_ = g_udev_device_get_sysfs_path (_tmp11_);
				if (g_strcmp0 (_tmp12_, "/sys/devices/myusbhub") == 0) {
					GUdevDevice* _tmp13_;
					const gchar* _tmp14_ = NULL;
					GUdevDevice* _tmp15_;
					const gchar* _tmp16_ = NULL;
					_tmp13_ = dev;
					_tmp14_ = g_udev_device_get_name (_tmp13_);
					g_assert_cmpstr (_tmp14_, ==, "myusbhub");
					_tmp15_ = dev;
					_tmp16_ = g_udev_device_get_device_file (_tmp15_);
					g_assert_cmpstr (_tmp16_, ==, "/dev/bus/usb/001/001");
				} else {
					GUdevDevice* _tmp17_;
					const gchar* _tmp18_ = NULL;
					GUdevDevice* _tmp19_;
					const gchar* _tmp20_ = NULL;
					GUdevDevice* _tmp21_;
					const gchar* _tmp22_ = NULL;
					_tmp17_ = dev;
					_tmp18_ = g_udev_device_get_sysfs_path (_tmp17_);
					g_assert_cmpstr (_tmp18_, ==, "/sys/devices/myusbhub/cam");
					_tmp19_ = dev;
					_tmp20_ = g_udev_device_get_name (_tmp19_);
					g_assert_cmpstr (_tmp20_, ==, "cam");
					_tmp21_ = dev;
					_tmp22_ = g_udev_device_get_device_file (_tmp21_);
					g_assert_cmpstr (_tmp22_, ==, "/dev/bus/usb/001/002");
				}
				_g_object_unref0 (dev);
			}
		}
	}
	__g_list_free__g_object_unref0_0 (devices);
	_g_object_unref0 (client);
	_g_object_unref0 (tb);
}


void t_usbfs_ioctl_static (void) {
	UMockdevTestbed* _tmp0_;
	UMockdevTestbed* tb;
	gint _tmp1_ = 0;
	gint fd;
	gint i;
	gint _tmp2_ = 0;
	gint _tmp3_;
	gint _tmp4_ = 0;
	gint _tmp5_;
	struct usbdevfs_connectinfo ci = {0};
	gint _tmp6_ = 0;
	gint _tmp7_;
	_tmp0_ = umockdev_testbed_new ();
	tb = _tmp0_;
	tb_add_from_string (tb, "P: /devices/mycam\nN: 001\nE: SUBSYSTEM=usb\n");
	_tmp1_ = open ("/dev/001", O_RDWR, (mode_t) 0);
	fd = _tmp1_;
	g_assert_cmpint (fd, >=, 0);
	i = 1;
	_tmp2_ = ioctl (fd, USBDEVFS_CLAIMINTERFACE, &i);
	g_assert_cmpint (_tmp2_, ==, 0);
	_tmp3_ = errno;
	g_assert_cmpint (_tmp3_, ==, 0);
	_tmp4_ = ioctl (fd, USBDEVFS_GETDRIVER, &i);
	g_assert_cmpint (_tmp4_, ==, -1);
	_tmp5_ = errno;
	g_assert_cmpint (_tmp5_, ==, ENODATA);
	errno = 0;
	memset (&ci, 0, sizeof (struct usbdevfs_connectinfo));
	_tmp6_ = ioctl (fd, USBDEVFS_CONNECTINFO, &ci);
	g_assert_cmpint (_tmp6_, ==, -1);
	_tmp7_ = errno;
	g_assert_cmpint (_tmp7_, >=, 22);
	errno = 0;
	close (fd);
	_g_object_unref0 (tb);
}


static guint8* _vala_array_dup1 (guint8* self, int length) {
	return g_memdup (self, length * sizeof (guint8));
}


void t_usbfs_ioctl_tree (void) {
	UMockdevTestbed* _tmp0_;
	UMockdevTestbed* tb;
	UMockdevTestbed* _tmp1_;
	gchar* test_tree = NULL;
	gchar* tmppath = NULL;
	gint fd = 0;
	gint _tmp7_;
	const gchar* _tmp8_;
	const gchar* _tmp9_;
	gint _tmp10_;
	gint _tmp11_;
	gssize _tmp12_ = 0L;
	gint i;
	gint _tmp13_;
	gint _tmp14_ = 0;
	gint _tmp15_;
	gint _tmp16_;
	gint _tmp20_ = 0;
	gint _tmp21_;
	gint _tmp22_;
	gint _tmp23_ = 0;
	gint _tmp24_;
	struct usbdevfs_connectinfo ci = {0};
	gint _tmp25_;
	gint _tmp26_ = 0;
	gint _tmp27_;
	struct usbdevfs_connectinfo _tmp28_;
	guint _tmp29_;
	struct usbdevfs_connectinfo _tmp30_;
	guint _tmp31_;
	guint8* _tmp32_ = NULL;
	guint8* urb_buffer;
	gint urb_buffer_length1;
	gint _urb_buffer_size_;
	guint8* _tmp33_;
	gint _tmp33__length1;
	struct usbdevfs_urb _tmp34_ = {0};
	struct usbdevfs_urb urb;
	gint _tmp35_;
	gint _tmp36_ = 0;
	gint _tmp37_;
	struct usbdevfs_urb _tmp38_;
	gint _tmp39_;
	guint8 _tmp40_;
	struct usbdevfs_urb* urb_reap;
	gint _tmp41_;
	gint _tmp42_ = 0;
	gint _tmp43_;
	struct usbdevfs_urb* _tmp44_;
	struct usbdevfs_urb _tmp45_;
	gint _tmp46_;
	struct usbdevfs_urb _tmp47_;
	guint8* _tmp48_;
	gint _tmp48__length1;
	guint8 _tmp49_;
	struct usbdevfs_urb _tmp50_;
	guint8* _tmp51_;
	gint _tmp51__length1;
	guint8 _tmp52_;
	struct usbdevfs_urb _tmp53_;
	guint8* _tmp54_;
	gint _tmp54__length1;
	guint8 _tmp55_;
	struct usbdevfs_urb _tmp56_;
	guint8* _tmp57_;
	gint _tmp57__length1;
	guint8 _tmp58_;
	gint _tmp59_ = 0;
	gint fd2;
	gint _tmp60_ = 0;
	gint _tmp61_;
	struct usbdevfs_connectinfo _tmp62_;
	guint _tmp63_;
	struct usbdevfs_connectinfo _tmp64_;
	guint _tmp65_;
	gint _tmp66_;
	gint _tmp67_ = 0;
	gint _tmp68_;
	struct usbdevfs_connectinfo _tmp69_;
	guint _tmp70_;
	struct usbdevfs_connectinfo _tmp71_;
	guint _tmp72_;
	gint _tmp73_;
	gint _tmp74_ = 0;
	gint _tmp75_;
	struct usbdevfs_connectinfo _tmp76_;
	guint _tmp77_;
	struct usbdevfs_connectinfo _tmp78_;
	guint _tmp79_;
	GError * _inner_error_ = NULL;
	_tmp0_ = umockdev_testbed_new ();
	tb = _tmp0_;
	_tmp1_ = tb;
	tb_add_from_string (_tmp1_, "P: /devices/mycam\nN: 001\nE: SUBSYSTEM=usb\n");
	if (G_BYTE_ORDER == G_LITTLE_ENDIAN) {
		gchar* _tmp2_;
		_tmp2_ = g_strdup ("# little-endian test ioctls\n" \
"USBDEVFS_CONNECTINFO 0 0B00000000000000\n" \
"USBDEVFS_REAPURB 0 1 129 -1 0 4 4 0 9902AAFF\n" \
"\n" \
"# another connect info\n" \
"USBDEVFS_CONNECTINFO 42 0C00000001000000\n");
		_g_free0 (test_tree);
		test_tree = _tmp2_;
	} else {
		gchar* _tmp3_;
		_tmp3_ = g_strdup ("# big-endian test ioctls\n" \
"USBDEVFS_CONNECTINFO 0 0000000B00000000\n" \
"USBDEVFS_REAPURB 0 1 129 -1 0 4 4 0 9902AAFF\n" \
"\n" \
"# another connect info\n" \
"USBDEVFS_CONNECTINFO 42 0000000C01000000\n");
		_g_free0 (test_tree);
		test_tree = _tmp3_;
	}
	{
		gchar* _tmp4_ = NULL;
		gint _tmp5_ = 0;
		gint _tmp6_;
		_tmp5_ = g_file_open_tmp ("test_ioctl_tree.XXXXXX", &_tmp4_, &_inner_error_);
		_g_free0 (tmppath);
		tmppath = _tmp4_;
		_tmp6_ = _tmp5_;
		if (_inner_error_ != NULL) {
			goto __catch1_g_error;
		}
		fd = _tmp6_;
	}
	goto __finally1;
	__catch1_g_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		abort ();
		_g_error_free0 (e);
	}
	__finally1:
	if (_inner_error_ != NULL) {
		_g_free0 (tmppath);
		_g_free0 (test_tree);
		_g_object_unref0 (tb);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp7_ = fd;
	_tmp8_ = test_tree;
	_tmp9_ = test_tree;
	_tmp10_ = strlen (_tmp9_);
	_tmp11_ = _tmp10_;
	_tmp12_ = write (_tmp7_, _tmp8_, (gsize) _tmp11_);
	g_assert_cmpint ((gint) _tmp12_, >, 20);
	i = 1;
	_tmp13_ = fd;
	_tmp14_ = ioctl (_tmp13_, USBDEVFS_CLAIMINTERFACE, &i);
	g_assert_cmpint (_tmp14_, ==, -1);
	_tmp15_ = errno;
	g_assert_cmpint (_tmp15_, >=, 22);
	_tmp16_ = fd;
	close (_tmp16_);
	{
		UMockdevTestbed* _tmp17_;
		_tmp17_ = tb;
		umockdev_testbed_load_ioctl (_tmp17_, "/dev/001", tmppath, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_FILE_ERROR) {
				goto __catch2_g_file_error;
			}
			_g_free0 (tmppath);
			_g_free0 (test_tree);
			_g_object_unref0 (tb);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	goto __finally2;
	__catch2_g_file_error:
	{
		GError* e = NULL;
		FILE* _tmp18_;
		const gchar* _tmp19_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp18_ = stderr;
		_tmp19_ = e->message;
		fprintf (_tmp18_, "Cannot load ioctls: %s\n", _tmp19_);
		abort ();
		_g_error_free0 (e);
	}
	__finally2:
	if (_inner_error_ != NULL) {
		_g_free0 (tmppath);
		_g_free0 (test_tree);
		_g_object_unref0 (tb);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	g_unlink (tmppath);
	_tmp20_ = open ("/dev/001", O_RDWR, (mode_t) 0);
	fd = _tmp20_;
	_tmp21_ = fd;
	g_assert_cmpint (_tmp21_, >=, 0);
	_tmp22_ = fd;
	_tmp23_ = ioctl (_tmp22_, USBDEVFS_CLAIMINTERFACE, &i);
	g_assert_cmpint (_tmp23_, ==, 0);
	_tmp24_ = errno;
	g_assert_cmpint (_tmp24_, ==, 0);
	memset (&ci, 0, sizeof (struct usbdevfs_connectinfo));
	_tmp25_ = fd;
	_tmp26_ = ioctl (_tmp25_, USBDEVFS_CONNECTINFO, &ci);
	g_assert_cmpint (_tmp26_, ==, 0);
	_tmp27_ = errno;
	g_assert_cmpint (_tmp27_, ==, 0);
	_tmp28_ = ci;
	_tmp29_ = _tmp28_.devnum;
	g_assert_cmpuint (_tmp29_, ==, (guint) 11);
	_tmp30_ = ci;
	_tmp31_ = _tmp30_.slow;
	g_assert_cmpuint (_tmp31_, ==, (guint) 0);
	_tmp32_ = g_new0 (guint8, 4);
	urb_buffer = _tmp32_;
	urb_buffer_length1 = 4;
	_urb_buffer_size_ = urb_buffer_length1;
	_tmp33_ = (urb_buffer != NULL) ? _vala_array_dup1 (urb_buffer, urb_buffer_length1) : ((gpointer) urb_buffer);
	_tmp33__length1 = urb_buffer_length1;
	_tmp34_.type = (guint8) 1;
	_tmp34_.endpoint = (guint8) 129;
	_tmp34_.status = 0;
	_tmp34_.flags = (guint) 0;
	_tmp34_.buffer = (g_free (_tmp34_.buffer), NULL);
	_tmp34_.buffer = _tmp33_;
	_tmp34_.buffer_length = 4;
	_tmp34_.actual_length = 0;
	urb = _tmp34_;
	_tmp35_ = fd;
	_tmp36_ = ioctl (_tmp35_, USBDEVFS_SUBMITURB, &urb);
	g_assert_cmpint (_tmp36_, ==, 0);
	_tmp37_ = errno;
	g_assert_cmpint (_tmp37_, ==, 0);
	_tmp38_ = urb;
	_tmp39_ = _tmp38_.status;
	g_assert_cmpuint ((guint) _tmp39_, ==, (guint) 0);
	_tmp40_ = urb_buffer[0];
	g_assert_cmpint ((gint) _tmp40_, ==, 0);
	urb_reap = NULL;
	_tmp41_ = fd;
	_tmp42_ = ioctl (_tmp41_, USBDEVFS_REAPURB, &urb_reap);
	g_assert_cmpint (_tmp42_, ==, 0);
	_tmp43_ = errno;
	g_assert_cmpint (_tmp43_, ==, 0);
	_tmp44_ = urb_reap;
	_vala_assert (_tmp44_ == (&urb), "urb_reap == &urb");
	_tmp45_ = urb;
	_tmp46_ = _tmp45_.status;
	g_assert_cmpint (_tmp46_, ==, -1);
	_tmp47_ = urb;
	_tmp48_ = _tmp47_.buffer;
	_tmp48__length1 = -1;
	_tmp49_ = _tmp48_[0];
	g_assert_cmpuint ((guint) _tmp49_, ==, (guint) 0x99);
	_tmp50_ = urb;
	_tmp51_ = _tmp50_.buffer;
	_tmp51__length1 = -1;
	_tmp52_ = _tmp51_[1];
	g_assert_cmpuint ((guint) _tmp52_, ==, (guint) 0x02);
	_tmp53_ = urb;
	_tmp54_ = _tmp53_.buffer;
	_tmp54__length1 = -1;
	_tmp55_ = _tmp54_[2];
	g_assert_cmpuint ((guint) _tmp55_, ==, (guint) 0xAA);
	_tmp56_ = urb;
	_tmp57_ = _tmp56_.buffer;
	_tmp57__length1 = -1;
	_tmp58_ = _tmp57_[3];
	g_assert_cmpuint ((guint) _tmp58_, ==, (guint) 0xFF);
	_tmp59_ = open ("/dev/001", O_RDWR, (mode_t) 0);
	fd2 = _tmp59_;
	g_assert_cmpint (fd2, >=, 0);
	ci.devnum = (guint) 99;
	ci.slow = (guint) 99;
	_tmp60_ = ioctl (fd2, USBDEVFS_CONNECTINFO, &ci);
	g_assert_cmpint (_tmp60_, ==, 0);
	_tmp61_ = errno;
	g_assert_cmpint (_tmp61_, ==, 0);
	_tmp62_ = ci;
	_tmp63_ = _tmp62_.devnum;
	g_assert_cmpuint (_tmp63_, ==, (guint) 11);
	_tmp64_ = ci;
	_tmp65_ = _tmp64_.slow;
	g_assert_cmpuint (_tmp65_, ==, (guint) 0);
	ci.devnum = (guint) 99;
	ci.slow = (guint) 99;
	_tmp66_ = fd;
	_tmp67_ = ioctl (_tmp66_, USBDEVFS_CONNECTINFO, &ci);
	g_assert_cmpint (_tmp67_, ==, 42);
	_tmp68_ = errno;
	g_assert_cmpint (_tmp68_, ==, 0);
	_tmp69_ = ci;
	_tmp70_ = _tmp69_.devnum;
	g_assert_cmpuint (_tmp70_, ==, (guint) 12);
	_tmp71_ = ci;
	_tmp72_ = _tmp71_.slow;
	g_assert_cmpuint (_tmp72_, ==, (guint) 1);
	_tmp73_ = fd;
	close (_tmp73_);
	ci.devnum = (guint) 99;
	ci.slow = (guint) 99;
	_tmp74_ = ioctl (fd2, USBDEVFS_CONNECTINFO, &ci);
	g_assert_cmpint (_tmp74_, ==, 42);
	_tmp75_ = errno;
	g_assert_cmpint (_tmp75_, ==, 0);
	_tmp76_ = ci;
	_tmp77_ = _tmp76_.devnum;
	g_assert_cmpuint (_tmp77_, ==, (guint) 12);
	_tmp78_ = ci;
	_tmp79_ = _tmp78_.slow;
	g_assert_cmpuint (_tmp79_, ==, (guint) 1);
	close (fd2);
	 (&urb);
	urb_buffer = (g_free (urb_buffer), NULL);
	_g_free0 (tmppath);
	_g_free0 (test_tree);
	_g_object_unref0 (tb);
}


void t_usbfs_ioctl_tree_xz (void) {
	UMockdevTestbed* _tmp0_;
	UMockdevTestbed* tb;
	UMockdevTestbed* _tmp1_;
	gchar* test_tree = NULL;
	gchar* tmppath = NULL;
	gint exit = 0;
	gint _tmp22_ = 0;
	gint fd;
	struct usbdevfs_connectinfo ci = {0};
	gint _tmp23_ = 0;
	gint _tmp24_;
	struct usbdevfs_connectinfo _tmp25_;
	guint _tmp26_;
	struct usbdevfs_connectinfo _tmp27_;
	guint _tmp28_;
	gint _tmp29_ = 0;
	gint _tmp30_;
	struct usbdevfs_connectinfo _tmp31_;
	guint _tmp32_;
	struct usbdevfs_connectinfo _tmp33_;
	guint _tmp34_;
	GError * _inner_error_ = NULL;
	_tmp0_ = umockdev_testbed_new ();
	tb = _tmp0_;
	_tmp1_ = tb;
	tb_add_from_string (_tmp1_, "P: /devices/mycam\nN: 001\nE: SUBSYSTEM=usb\n");
	if (G_BYTE_ORDER == G_LITTLE_ENDIAN) {
		gchar* _tmp2_;
		_tmp2_ = g_strdup ("USBDEVFS_CONNECTINFO 0 0B00000000000000\n" \
"USBDEVFS_REAPURB 0 1 129 -1 0 4 4 0 9902AAFF\n" \
"USBDEVFS_CONNECTINFO 42 0C00000001000000\n");
		_g_free0 (test_tree);
		test_tree = _tmp2_;
	} else {
		gchar* _tmp3_;
		_tmp3_ = g_strdup ("USBDEVFS_CONNECTINFO 0 0000000B00000000\n" \
"USBDEVFS_REAPURB 0 1 129 -1 0 4 4 0 9902AAFF\n" \
"USBDEVFS_CONNECTINFO 42 0000000C01000000\n");
		_g_free0 (test_tree);
		test_tree = _tmp3_;
	}
	{
		gchar* _tmp4_ = NULL;
		gint _tmp5_ = 0;
		gint _tmp6_;
		_tmp5_ = g_file_open_tmp ("test_ioctl_tree.XXXXXX.xz", &_tmp4_, &_inner_error_);
		_g_free0 (tmppath);
		tmppath = _tmp4_;
		_tmp6_ = _tmp5_;
		if (_inner_error_ != NULL) {
			goto __catch3_g_error;
		}
		close (_tmp6_);
	}
	goto __finally3;
	__catch3_g_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		abort ();
		_g_error_free0 (e);
	}
	__finally3:
	if (_inner_error_ != NULL) {
		_g_free0 (tmppath);
		_g_free0 (test_tree);
		_g_object_unref0 (tb);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	{
		const gchar* _tmp7_;
		gchar* _tmp8_;
		gchar* _tmp9_;
		gchar* _tmp10_;
		gchar* _tmp11_;
		gchar* _tmp12_;
		gchar* _tmp13_;
		gchar* _tmp14_;
		gchar* _tmp15_;
		gint _tmp16_ = 0;
		_tmp7_ = test_tree;
		_tmp8_ = g_strconcat ("sh -c 'echo \"", _tmp7_, NULL);
		_tmp9_ = _tmp8_;
		_tmp10_ = g_strconcat (_tmp9_, "\" | xz -9c > ", NULL);
		_tmp11_ = _tmp10_;
		_tmp12_ = g_strconcat (_tmp11_, tmppath, NULL);
		_tmp13_ = _tmp12_;
		_tmp14_ = g_strconcat (_tmp13_, "; sync'", NULL);
		_tmp15_ = _tmp14_;
		g_spawn_command_line_sync (_tmp15_, NULL, NULL, &_tmp16_, &_inner_error_);
		exit = _tmp16_;
		_g_free0 (_tmp15_);
		_g_free0 (_tmp13_);
		_g_free0 (_tmp11_);
		_g_free0 (_tmp9_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_SPAWN_ERROR) {
				goto __catch4_g_spawn_error;
			}
			_g_free0 (tmppath);
			_g_free0 (test_tree);
			_g_object_unref0 (tb);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	goto __finally4;
	__catch4_g_spawn_error:
	{
		GError* e = NULL;
		FILE* _tmp17_;
		const gchar* _tmp18_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp17_ = stderr;
		_tmp18_ = e->message;
		fprintf (_tmp17_, "Cannot call xz: %s\n", _tmp18_);
		abort ();
		_g_error_free0 (e);
	}
	__finally4:
	if (_inner_error_ != NULL) {
		_g_free0 (tmppath);
		_g_free0 (test_tree);
		_g_object_unref0 (tb);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	g_assert_cmpint (exit, ==, 0);
	{
		UMockdevTestbed* _tmp19_;
		_tmp19_ = tb;
		umockdev_testbed_load_ioctl (_tmp19_, "/dev/001", tmppath, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_FILE_ERROR) {
				goto __catch5_g_file_error;
			}
			_g_free0 (tmppath);
			_g_free0 (test_tree);
			_g_object_unref0 (tb);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	goto __finally5;
	__catch5_g_file_error:
	{
		GError* e = NULL;
		FILE* _tmp20_;
		const gchar* _tmp21_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp20_ = stderr;
		_tmp21_ = e->message;
		fprintf (_tmp20_, "Cannot load ioctls: %s\n", _tmp21_);
		abort ();
		_g_error_free0 (e);
	}
	__finally5:
	if (_inner_error_ != NULL) {
		_g_free0 (tmppath);
		_g_free0 (test_tree);
		_g_object_unref0 (tb);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	g_unlink (tmppath);
	_tmp22_ = open ("/dev/001", O_RDWR, (mode_t) 0);
	fd = _tmp22_;
	g_assert_cmpint (fd, >=, 0);
	memset (&ci, 0, sizeof (struct usbdevfs_connectinfo));
	_tmp23_ = ioctl (fd, USBDEVFS_CONNECTINFO, &ci);
	g_assert_cmpint (_tmp23_, ==, 0);
	_tmp24_ = errno;
	g_assert_cmpint (_tmp24_, ==, 0);
	_tmp25_ = ci;
	_tmp26_ = _tmp25_.devnum;
	g_assert_cmpuint (_tmp26_, ==, (guint) 11);
	_tmp27_ = ci;
	_tmp28_ = _tmp27_.slow;
	g_assert_cmpuint (_tmp28_, ==, (guint) 0);
	_tmp29_ = ioctl (fd, USBDEVFS_CONNECTINFO, &ci);
	g_assert_cmpint (_tmp29_, ==, 42);
	_tmp30_ = errno;
	g_assert_cmpint (_tmp30_, ==, 0);
	_tmp31_ = ci;
	_tmp32_ = _tmp31_.devnum;
	g_assert_cmpuint (_tmp32_, ==, (guint) 12);
	_tmp33_ = ci;
	_tmp34_ = _tmp33_.slow;
	g_assert_cmpuint (_tmp34_, ==, (guint) 1);
	close (fd);
	_g_free0 (tmppath);
	_g_free0 (test_tree);
	_g_object_unref0 (tb);
}


static gboolean string_contains (const gchar* self, const gchar* needle) {
	gboolean result = FALSE;
	const gchar* _tmp0_;
	gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (needle != NULL, FALSE);
	_tmp0_ = needle;
	_tmp1_ = strstr ((gchar*) self, (gchar*) _tmp0_);
	result = _tmp1_ != NULL;
	return result;
}


void t_tty_stty (void) {
	UMockdevTestbed* _tmp0_;
	UMockdevTestbed* tb;
	struct stat st = {0};
	struct stat _tmp1_ = {0};
	gint _tmp2_ = 0;
	struct stat _tmp3_;
	mode_t _tmp4_;
	gboolean _tmp5_ = FALSE;
	struct stat _tmp6_;
	dev_t _tmp7_;
	guint _tmp8_ = 0U;
	struct stat _tmp9_;
	dev_t _tmp10_;
	guint _tmp11_ = 0U;
	gchar* pout = NULL;
	gchar* perr = NULL;
	gint pexit = 0;
	gboolean _tmp17_ = FALSE;
	GError * _inner_error_ = NULL;
	_tmp0_ = umockdev_testbed_new ();
	tb = _tmp0_;
	tb_add_from_string (tb, "P: /devices/usb/tty/ttyUSB1\n" \
"N: ttyUSB1\n" \
"E: DEVNAME=/dev/ttyUSB1\n" \
"E: SUBSYSTEM=tty\n" \
"A: dev=188:1\n");
	_tmp2_ = lstat ("/dev/ttyUSB1", &_tmp1_);
	st = _tmp1_;
	g_assert_cmpint (_tmp2_, ==, 0);
	_tmp3_ = st;
	_tmp4_ = _tmp3_.st_mode;
	_tmp5_ = S_ISCHR (_tmp4_);
	_vala_assert (_tmp5_, "Posix.S_ISCHR (st.st_mode)");
	_tmp6_ = st;
	_tmp7_ = _tmp6_.st_rdev;
	_tmp8_ = major (_tmp7_);
	g_assert_cmpuint (_tmp8_, ==, (guint) 188);
	_tmp9_ = st;
	_tmp10_ = _tmp9_.st_rdev;
	_tmp11_ = minor (_tmp10_);
	g_assert_cmpuint (_tmp11_, ==, (guint) 1);
	{
		gchar* _tmp12_ = NULL;
		gchar* _tmp13_ = NULL;
		gint _tmp14_ = 0;
		g_spawn_command_line_sync ("stty -F /dev/ttyUSB1", &_tmp12_, &_tmp13_, &_tmp14_, &_inner_error_);
		_g_free0 (pout);
		pout = _tmp12_;
		_g_free0 (perr);
		perr = _tmp13_;
		pexit = _tmp14_;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_SPAWN_ERROR) {
				goto __catch6_g_spawn_error;
			}
			_g_free0 (perr);
			_g_free0 (pout);
			_g_object_unref0 (tb);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	goto __finally6;
	__catch6_g_spawn_error:
	{
		GError* e = NULL;
		FILE* _tmp15_;
		const gchar* _tmp16_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp15_ = stderr;
		_tmp16_ = e->message;
		fprintf (_tmp15_, "Cannot call stty: %s\n", _tmp16_);
		abort ();
		_g_error_free0 (e);
	}
	__finally6:
	if (_inner_error_ != NULL) {
		_g_free0 (perr);
		_g_free0 (pout);
		_g_object_unref0 (tb);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	g_assert_cmpstr (perr, ==, "");
	g_assert_cmpint (pexit, ==, 0);
	_tmp17_ = string_contains (pout, "speed 38400 baud");
	_vala_assert (_tmp17_, "pout.contains (\"speed 38400 baud\")");
	_g_free0 (perr);
	_g_free0 (pout);
	_g_object_unref0 (tb);
}


void t_tty_data (void) {
	UMockdevTestbed* _tmp0_;
	UMockdevTestbed* tb;
	gint _tmp1_ = 0;
	gint client_fd;
	gint _tmp2_ = 0;
	gint master_fd;
	gchar* _tmp3_ = NULL;
	gchar* buf;
	gint buf_length1;
	gint _buf_size_;
	gssize _tmp4_ = 0L;
	gchar* _tmp5_;
	gint _tmp5__length1;
	gssize _tmp6_ = 0L;
	gchar* _tmp7_;
	gint _tmp7__length1;
	gchar* _tmp8_ = NULL;
	gssize _tmp9_ = 0L;
	gchar* _tmp10_;
	gint _tmp10__length1;
	gssize _tmp11_ = 0L;
	gchar* _tmp12_;
	gint _tmp12__length1;
	_tmp0_ = umockdev_testbed_new ();
	tb = _tmp0_;
	tb_add_from_string (tb, "P: /devices/serial/ttyS10\n" \
"N: ttyS10\n" \
"E: DEVNAME=/dev/ttyS10\n" \
"E: SUBSYSTEM=tty\n" \
"A: dev=4:74\n");
	_tmp1_ = open ("/dev/ttyS10", O_RDWR, (mode_t) 0);
	client_fd = _tmp1_;
	g_assert_cmpint (client_fd, >=, 0);
	_tmp2_ = umockdev_testbed_get_dev_fd (tb, "/dev/ttyS10");
	master_fd = _tmp2_;
	g_assert_cmpint (master_fd, >=, 0);
	_tmp3_ = g_new0 (gchar, 100);
	buf = _tmp3_;
	buf_length1 = 100;
	_buf_size_ = buf_length1;
	_tmp4_ = write (client_fd, "hello\n", (gsize) 6);
	g_assert_cmpint ((gint) _tmp4_, ==, 6);
	_tmp5_ = buf;
	_tmp5__length1 = buf_length1;
	_tmp6_ = read (master_fd, _tmp5_, (gsize) 100);
	g_assert_cmpint ((gint) _tmp6_, ==, 6);
	_tmp7_ = buf;
	_tmp7__length1 = buf_length1;
	g_assert_cmpstr ((const gchar*) _tmp7_, ==, "hello\n");
	_tmp8_ = g_new0 (gchar, 100);
	buf = (g_free (buf), NULL);
	buf = _tmp8_;
	buf_length1 = 100;
	_buf_size_ = buf_length1;
	_tmp9_ = write (master_fd, "world\n", (gsize) 6);
	g_assert_cmpint ((gint) _tmp9_, ==, 6);
	_tmp10_ = buf;
	_tmp10__length1 = buf_length1;
	_tmp11_ = read (client_fd, _tmp10_, (gsize) 100);
	g_assert_cmpint ((gint) _tmp11_, ==, 6);
	_tmp12_ = buf;
	_tmp12__length1 = buf_length1;
	g_assert_cmpstr ((const gchar*) _tmp12_, ==, "world\n");
	close (client_fd);
	buf = (g_free (buf), NULL);
	_g_object_unref0 (tb);
}


static void _t_testbed_empty_gtest_func (void) {
	t_testbed_empty ();
}


static void _t_testbed_add_device_gtest_func (void) {
	t_testbed_add_device ();
}


static void _t_testbed_gudev_query_list_gtest_func (void) {
	t_testbed_gudev_query_list ();
}


static void _t_usbfs_ioctl_static_gtest_func (void) {
	t_usbfs_ioctl_static ();
}


static void _t_usbfs_ioctl_tree_gtest_func (void) {
	t_usbfs_ioctl_tree ();
}


static void _t_usbfs_ioctl_tree_xz_gtest_func (void) {
	t_usbfs_ioctl_tree_xz ();
}


static void _t_tty_stty_gtest_func (void) {
	t_tty_stty ();
}


static void _t_tty_data_gtest_func (void) {
	t_tty_data ();
}


gint _vala_main (gchar** args, int args_length1) {
	gint result = 0;
	gint _tmp0_ = 0;
	g_test_init (&args_length1, &args, NULL);
	g_test_add_func ("/umockdev-testbed-vala/empty", _t_testbed_empty_gtest_func);
	g_test_add_func ("/umockdev-testbed-vala/add_devicev", _t_testbed_add_device_gtest_func);
	g_test_add_func ("/umockdev-testbed-vala/gudev-query-list", _t_testbed_gudev_query_list_gtest_func);
	g_test_add_func ("/umockdev-testbed-vala/usbfs_ioctl_static", _t_usbfs_ioctl_static_gtest_func);
	g_test_add_func ("/umockdev-testbed-vala/usbfs_ioctl_tree", _t_usbfs_ioctl_tree_gtest_func);
	g_test_add_func ("/umockdev-testbed-vala/usbfs_ioctl_tree_xz", _t_usbfs_ioctl_tree_xz_gtest_func);
	g_test_add_func ("/umockdev-testbed-vala/tty_stty", _t_tty_stty_gtest_func);
	g_test_add_func ("/umockdev-testbed-vala/tty_data", _t_tty_data_gtest_func);
	_tmp0_ = g_test_run ();
	result = _tmp0_;
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return _vala_main (argv, argc);
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



