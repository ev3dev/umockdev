/* umockdev-1.0.vapi generated by valac 0.20.1, do not modify. */

namespace UMockdev {
	[CCode (cheader_filename = "umockdev.h")]
	public class Testbed : GLib.Object {
		public Testbed ();
		public string? add_device (string subsystem, string name, string? parent, ...);
		public string? add_devicev (string subsystem, string name, string? parent, [CCode (array_length = false, array_null_terminated = true)] string[] attributes, [CCode (array_length = false, array_null_terminated = true)] string[] properties);
		public bool add_from_file (string path) throws UMockdev.Error, GLib.FileError;
		public bool add_from_string (string data) throws UMockdev.Error;
		public void clear ();
		public void disable ();
		public void enable ();
		public int get_dev_fd (string devnode);
		public string get_root_dir ();
		public string get_sys_dir ();
		public bool load_ioctl (string dev, string recordfile) throws GLib.FileError;
		public bool load_script (string dev, string recordfile) throws GLib.FileError;
		public void remove_device (string syspath);
		public void set_attribute (string devpath, string name, string value);
		public void set_attribute_binary (string devpath, string name, uint8[] value);
		public void set_attribute_hex (string devpath, string name, uint value);
		public void set_attribute_int (string devpath, string name, int value);
		public void set_attribute_link (string devpath, string name, string value);
		public new void set_property (string devpath, string name, string value);
		public void set_property_hex (string devpath, string name, uint value);
		public void set_property_int (string devpath, string name, int value);
		public void uevent (string devpath, string action);
	}
	[CCode (cheader_filename = "umockdev.h")]
	public errordomain Error {
		PARSE,
		VALUE
	}
}
