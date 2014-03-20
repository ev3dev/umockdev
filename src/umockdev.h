/* umockdev.h generated by valac 0.22.1, the Vala compiler, do not modify */


#ifndef __SRC_UMOCKDEV_H__
#define __SRC_UMOCKDEV_H__

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>

G_BEGIN_DECLS


#define UMOCKDEV_TYPE_TESTBED (umockdev_testbed_get_type ())
#define UMOCKDEV_TESTBED(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UMOCKDEV_TYPE_TESTBED, UMockdevTestbed))
#define UMOCKDEV_TESTBED_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UMOCKDEV_TYPE_TESTBED, UMockdevTestbedClass))
#define UMOCKDEV_IS_TESTBED(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UMOCKDEV_TYPE_TESTBED))
#define UMOCKDEV_IS_TESTBED_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UMOCKDEV_TYPE_TESTBED))
#define UMOCKDEV_TESTBED_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UMOCKDEV_TYPE_TESTBED, UMockdevTestbedClass))

typedef struct _UMockdevTestbed UMockdevTestbed;
typedef struct _UMockdevTestbedClass UMockdevTestbedClass;
typedef struct _UMockdevTestbedPrivate UMockdevTestbedPrivate;

struct _UMockdevTestbed {
	GObject parent_instance;
	UMockdevTestbedPrivate * priv;
};

struct _UMockdevTestbedClass {
	GObjectClass parent_class;
};

typedef enum  {
	UMOCKDEV_ERROR_PARSE,
	UMOCKDEV_ERROR_VALUE
} UMockdevError;
#define UMOCKDEV_ERROR umockdev_error_quark ()

GType umockdev_testbed_get_type (void) G_GNUC_CONST;
UMockdevTestbed* umockdev_testbed_new (void);
UMockdevTestbed* umockdev_testbed_construct (GType object_type);
gchar* umockdev_testbed_get_root_dir (UMockdevTestbed* self);
gchar* umockdev_testbed_get_sys_dir (UMockdevTestbed* self);
void umockdev_testbed_set_attribute (UMockdevTestbed* self, const gchar* devpath, const gchar* name, const gchar* value);
void umockdev_testbed_set_attribute_binary (UMockdevTestbed* self, const gchar* devpath, const gchar* name, guint8* value, int value_length1);
void umockdev_testbed_set_attribute_int (UMockdevTestbed* self, const gchar* devpath, const gchar* name, gint value);
void umockdev_testbed_set_attribute_hex (UMockdevTestbed* self, const gchar* devpath, const gchar* name, guint value);
void umockdev_testbed_set_attribute_link (UMockdevTestbed* self, const gchar* devpath, const gchar* name, const gchar* value);
void umockdev_testbed_set_property (UMockdevTestbed* self, const gchar* devpath, const gchar* name, const gchar* value);
void umockdev_testbed_set_property_int (UMockdevTestbed* self, const gchar* devpath, const gchar* name, gint value);
void umockdev_testbed_set_property_hex (UMockdevTestbed* self, const gchar* devpath, const gchar* name, guint value);
gchar* umockdev_testbed_add_devicev (UMockdevTestbed* self, const gchar* subsystem, const gchar* name, const gchar* parent, gchar** attributes, gchar** properties);
gchar* umockdev_testbed_add_device (UMockdevTestbed* self, const gchar* subsystem, const gchar* name, const gchar* parent, ...);
void umockdev_testbed_remove_device (UMockdevTestbed* self, const gchar* syspath);
GQuark umockdev_error_quark (void);
gboolean umockdev_testbed_add_from_string (UMockdevTestbed* self, const gchar* data, GError** error);
gboolean umockdev_testbed_add_from_file (UMockdevTestbed* self, const gchar* path, GError** error);
void umockdev_testbed_uevent (UMockdevTestbed* self, const gchar* devpath, const gchar* action);
gboolean umockdev_testbed_load_ioctl (UMockdevTestbed* self, const gchar* dev, const gchar* recordfile, GError** error);
gboolean umockdev_testbed_load_script (UMockdevTestbed* self, const gchar* dev, const gchar* recordfile, GError** error);
gboolean umockdev_testbed_load_socket_script (UMockdevTestbed* self, const gchar* path, gint type, const gchar* recordfile, GError** error);
gboolean umockdev_testbed_load_evemu_events (UMockdevTestbed* self, const gchar* dev, const gchar* eventsfile, GError** error);
void umockdev_testbed_disable (UMockdevTestbed* self);
void umockdev_testbed_enable (UMockdevTestbed* self);
void umockdev_testbed_clear (UMockdevTestbed* self);
gint umockdev_testbed_get_dev_fd (UMockdevTestbed* self, const gchar* devnode);
gboolean umockdev_in_mock_environment (void);


G_END_DECLS

#endif
