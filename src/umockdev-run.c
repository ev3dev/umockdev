/* umockdev-run.c generated by valac 0.42.3, the Vala compiler
 * generated from umockdev-run.vala, do not modify */



#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include "config.h"
#include <umockdev.h>
#include <glib/gstdio.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_option_context_free0(var) ((var == NULL) ? NULL : (var = (g_option_context_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _vala_assert(expr, msg) if G_LIKELY (expr) ; else g_assertion_message_expr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);
#define _vala_return_if_fail(expr, msg) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return; }
#define _vala_return_val_if_fail(expr, msg, val) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return val; }
#define _vala_warn_if_fail(expr, msg) if G_LIKELY (expr) ; else g_warn_message (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);


extern gchar** opt_device;
gchar** opt_device = NULL;
extern gchar** opt_ioctl;
gchar** opt_ioctl = NULL;
extern gchar** opt_script;
gchar** opt_script = NULL;
extern gchar** opt_unix_stream;
gchar** opt_unix_stream = NULL;
extern gchar** opt_evemu_events;
gchar** opt_evemu_events = NULL;
extern gchar** opt_program;
gchar** opt_program = NULL;
extern gboolean opt_version;
gboolean opt_version = FALSE;
extern GPid child_pid;
GPid child_pid = 0;

void child_sig_handler (gint sig);
gint _vala_main (gchar** args,
                 int args_length1);
static void _child_sig_handler_sighandler_t (gint signal);
static void _vala_array_destroy (gpointer array,
                          gint array_length,
                          GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array,
                       gint array_length,
                       GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);

const GOptionEntry options[8] = {{"device", 'd', 0, G_OPTION_ARG_FILENAME_ARRAY, &opt_device, "Load an umockdev-record device description into the testbed. Can be sp" \
"ecified multiple times.", "filename"}, {"ioctl", 'i', 0, G_OPTION_ARG_FILENAME_ARRAY, &opt_ioctl, "Load an umockdev-record ioctl dump into the testbed. Can be specified " \
"multiple times.", "devname=ioctlfilename"}, {"script", 's', 0, G_OPTION_ARG_FILENAME_ARRAY, &opt_script, "Load an umockdev-record script into the testbed. Can be specified mult" \
"iple times.", "devname=scriptfilename"}, {"unix-stream", 'u', 0, G_OPTION_ARG_FILENAME_ARRAY, &opt_unix_stream, "Load an umockdev-record script for a mocked Unix stream socket. Can be" \
" specified multiple times.", "socket_path=scriptfilename"}, {"evemu-events", 'e', 0, G_OPTION_ARG_FILENAME_ARRAY, &opt_evemu_events, "Load an evemu .events file into the testbed. Can be specified multiple" \
" times.", "devname=eventsfilename"}, {"", (gchar) 0, 0, G_OPTION_ARG_STRING_ARRAY, &opt_program, "", ""}, {"version", (gchar) 0, 0, G_OPTION_ARG_NONE, &opt_version, "Output version information and exit"}, {NULL}};

void
child_sig_handler (gint sig)
{
	GPid _tmp0_;
	g_debug ("umockdev-run.vala:61: umockdev-run: caught signal %i, propagating to c" \
"hild\n", sig);
	_tmp0_ = child_pid;
	if (kill ((pid_t) _tmp0_, sig) != 0) {
		FILE* _tmp1_;
		GPid _tmp2_;
		gint _tmp3_;
		const gchar* _tmp4_;
		_tmp1_ = stderr;
		_tmp2_ = child_pid;
		_tmp3_ = errno;
		_tmp4_ = g_strerror (_tmp3_);
		fprintf (_tmp1_, "umockdev-run: unable to propagate signal %i to child %i: %s\n", sig, (gint) _tmp2_, _tmp4_);
	}
}


static void
_child_sig_handler_sighandler_t (gint signal)
{
	child_sig_handler (signal);
}


gint
_vala_main (gchar** args,
            int args_length1)
{
	gint result = 0;
	GOptionContext* oc = NULL;
	GOptionContext* _tmp0_;
	GOptionContext* _tmp1_;
	GOptionContext* _tmp2_;
	gboolean _tmp9_;
	gchar* preload = NULL;
	const gchar* _tmp11_;
	gchar* _tmp12_;
	const gchar* _tmp13_;
	const gchar* _tmp17_;
	gchar* _tmp18_;
	gchar* _tmp19_;
	UMockdevTestbed* testbed = NULL;
	UMockdevTestbed* _tmp20_;
	gchar** _tmp21_;
	gint _tmp21__length1;
	gchar** _tmp37_;
	gint _tmp37__length1;
	gchar** _tmp57_;
	gint _tmp57__length1;
	gchar** _tmp77_;
	gint _tmp77__length1;
	gchar** _tmp97_;
	gint _tmp97__length1;
	gchar** _tmp117_;
	gint _tmp117__length1;
	gint status = 0;
	struct sigaction act = {0};
	struct sigaction _tmp126_ = {0};
	sigset_t _tmp127_ = {0};
	struct sigaction _tmp128_;
	gint _tmp129_;
	struct sigaction _tmp130_;
	gint _tmp131_;
	struct sigaction _tmp132_;
	gint _tmp133_;
	struct sigaction _tmp134_;
	gint _tmp135_;
	struct sigaction _tmp136_;
	gint _tmp137_;
	GPid _tmp138_;
	gint _tmp139_ = 0;
	GPid _tmp140_;
	gint _tmp141_;
	gint _tmp143_;
	GError * _inner_error_ = NULL;
	_tmp0_ = g_option_context_new ("-- program [args..]");
	oc = _tmp0_;
	_tmp1_ = oc;
	g_option_context_set_summary (_tmp1_, "Run a program under an umockdev testbed.");
	_tmp2_ = oc;
	g_option_context_add_main_entries (_tmp2_, options, NULL);
	{
		GOptionContext* _tmp3_;
		_tmp3_ = oc;
		g_option_context_parse (_tmp3_, &args_length1, &args, &_inner_error_);
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			goto __catch0_g_error;
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		FILE* _tmp4_;
		GError* _tmp5_;
		const gchar* _tmp6_;
		const gchar* _tmp7_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp4_ = stderr;
		_tmp5_ = e;
		_tmp6_ = _tmp5_->message;
		_tmp7_ = args[0];
		fprintf (_tmp4_, "Error: %s\nRun %s --help for how to use this program\n", _tmp6_, _tmp7_);
		result = 1;
		_g_error_free0 (e);
		_g_option_context_free0 (oc);
		return result;
	}
	__finally0:
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		gint _tmp8_ = -1;
		_g_option_context_free0 (oc);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return _tmp8_;
	}
	_tmp9_ = opt_version;
	if (_tmp9_) {
		FILE* _tmp10_;
		_tmp10_ = stdout;
		fprintf (_tmp10_, "%s\n", VERSION);
		result = 0;
		_g_option_context_free0 (oc);
		return result;
	}
	_tmp11_ = g_getenv ("LD_PRELOAD");
	_tmp12_ = g_strdup (_tmp11_);
	preload = _tmp12_;
	_tmp13_ = preload;
	if (_tmp13_ == NULL) {
		gchar* _tmp14_;
		_tmp14_ = g_strdup ("");
		_g_free0 (preload);
		preload = _tmp14_;
	} else {
		const gchar* _tmp15_;
		gchar* _tmp16_;
		_tmp15_ = preload;
		_tmp16_ = g_strconcat (_tmp15_, ":", NULL);
		_g_free0 (preload);
		preload = _tmp16_;
	}
	_tmp17_ = preload;
	_tmp18_ = g_strconcat (_tmp17_, "libumockdev-preload.so.0", NULL);
	_tmp19_ = _tmp18_;
	g_setenv ("LD_PRELOAD", _tmp19_, TRUE);
	_g_free0 (_tmp19_);
	_tmp20_ = umockdev_testbed_new ();
	testbed = _tmp20_;
	_tmp21_ = opt_device;
	_tmp21__length1 = _vala_array_length (opt_device);
	{
		gchar** path_collection = NULL;
		gint path_collection_length1 = 0;
		gint _path_collection_size_ = 0;
		gint path_it = 0;
		path_collection = _tmp21_;
		path_collection_length1 = _tmp21__length1;
		for (path_it = 0; path_it < _tmp21__length1; path_it = path_it + 1) {
			gchar* _tmp22_;
			gchar* path = NULL;
			_tmp22_ = g_strdup (path_collection[path_it]);
			path = _tmp22_;
			{
				gchar* record = NULL;
				{
					const gchar* _tmp23_;
					gchar* _tmp24_ = NULL;
					_tmp23_ = path;
					g_file_get_contents (_tmp23_, &_tmp24_, NULL, &_inner_error_);
					_g_free0 (record);
					record = _tmp24_;
					if (G_UNLIKELY (_inner_error_ != NULL)) {
						goto __catch1_g_error;
					}
				}
				goto __finally1;
				__catch1_g_error:
				{
					GError* e = NULL;
					FILE* _tmp25_;
					const gchar* _tmp26_;
					GError* _tmp27_;
					const gchar* _tmp28_;
					e = _inner_error_;
					_inner_error_ = NULL;
					_tmp25_ = stderr;
					_tmp26_ = path;
					_tmp27_ = e;
					_tmp28_ = _tmp27_->message;
					fprintf (_tmp25_, "Error: Cannot open %s: %s\n", _tmp26_, _tmp28_);
					result = 1;
					_g_error_free0 (e);
					_g_free0 (record);
					_g_free0 (path);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					return result;
				}
				__finally1:
				if (G_UNLIKELY (_inner_error_ != NULL)) {
					gint _tmp29_ = -1;
					_g_free0 (record);
					_g_free0 (path);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return _tmp29_;
				}
				{
					UMockdevTestbed* _tmp30_;
					const gchar* _tmp31_;
					_tmp30_ = testbed;
					_tmp31_ = record;
					umockdev_testbed_add_from_string (_tmp30_, _tmp31_, &_inner_error_);
					if (G_UNLIKELY (_inner_error_ != NULL)) {
						goto __catch2_g_error;
					}
				}
				goto __finally2;
				__catch2_g_error:
				{
					GError* e = NULL;
					FILE* _tmp32_;
					const gchar* _tmp33_;
					GError* _tmp34_;
					const gchar* _tmp35_;
					e = _inner_error_;
					_inner_error_ = NULL;
					_tmp32_ = stderr;
					_tmp33_ = path;
					_tmp34_ = e;
					_tmp35_ = _tmp34_->message;
					fprintf (_tmp32_, "Error: Invalid record file %s: %s\n", _tmp33_, _tmp35_);
					result = 1;
					_g_error_free0 (e);
					_g_free0 (record);
					_g_free0 (path);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					return result;
				}
				__finally2:
				if (G_UNLIKELY (_inner_error_ != NULL)) {
					gint _tmp36_ = -1;
					_g_free0 (record);
					_g_free0 (path);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return _tmp36_;
				}
				_g_free0 (record);
				_g_free0 (path);
			}
		}
	}
	_tmp37_ = opt_ioctl;
	_tmp37__length1 = _vala_array_length (opt_ioctl);
	{
		gchar** i_collection = NULL;
		gint i_collection_length1 = 0;
		gint _i_collection_size_ = 0;
		gint i_it = 0;
		i_collection = _tmp37_;
		i_collection_length1 = _tmp37__length1;
		for (i_it = 0; i_it < _tmp37__length1; i_it = i_it + 1) {
			gchar* _tmp38_;
			gchar* i = NULL;
			_tmp38_ = g_strdup (i_collection[i_it]);
			i = _tmp38_;
			{
				gchar** parts = NULL;
				const gchar* _tmp39_;
				gchar** _tmp40_;
				gchar** _tmp41_;
				gint parts_length1;
				gint _parts_size_;
				gchar** _tmp42_;
				gint _tmp42__length1;
				_tmp39_ = i;
				_tmp41_ = _tmp40_ = g_strsplit (_tmp39_, "=", 2);
				parts = _tmp41_;
				parts_length1 = _vala_array_length (_tmp40_);
				_parts_size_ = parts_length1;
				_tmp42_ = parts;
				_tmp42__length1 = parts_length1;
				if (_tmp42__length1 != 2) {
					FILE* _tmp43_;
					_tmp43_ = stderr;
					fprintf (_tmp43_, "Error: --ioctl argument must be devname=filename\n");
					result = 1;
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					return result;
				}
				{
					UMockdevTestbed* _tmp44_;
					gchar** _tmp45_;
					gint _tmp45__length1;
					const gchar* _tmp46_;
					gchar** _tmp47_;
					gint _tmp47__length1;
					const gchar* _tmp48_;
					_tmp44_ = testbed;
					_tmp45_ = parts;
					_tmp45__length1 = parts_length1;
					_tmp46_ = _tmp45_[0];
					_tmp47_ = parts;
					_tmp47__length1 = parts_length1;
					_tmp48_ = _tmp47_[1];
					umockdev_testbed_load_ioctl (_tmp44_, _tmp46_, _tmp48_, &_inner_error_);
					if (G_UNLIKELY (_inner_error_ != NULL)) {
						goto __catch3_g_error;
					}
				}
				goto __finally3;
				__catch3_g_error:
				{
					GError* e = NULL;
					FILE* _tmp49_;
					gchar** _tmp50_;
					gint _tmp50__length1;
					const gchar* _tmp51_;
					gchar** _tmp52_;
					gint _tmp52__length1;
					const gchar* _tmp53_;
					GError* _tmp54_;
					const gchar* _tmp55_;
					e = _inner_error_;
					_inner_error_ = NULL;
					_tmp49_ = stderr;
					_tmp50_ = parts;
					_tmp50__length1 = parts_length1;
					_tmp51_ = _tmp50_[1];
					_tmp52_ = parts;
					_tmp52__length1 = parts_length1;
					_tmp53_ = _tmp52_[0];
					_tmp54_ = e;
					_tmp55_ = _tmp54_->message;
					fprintf (_tmp49_, "Error: Cannot install %s for device %s: %s\n", _tmp51_, _tmp53_, _tmp55_);
					result = 1;
					_g_error_free0 (e);
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					return result;
				}
				__finally3:
				if (G_UNLIKELY (_inner_error_ != NULL)) {
					gint _tmp56_ = -1;
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return _tmp56_;
				}
				parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
				_g_free0 (i);
			}
		}
	}
	_tmp57_ = opt_script;
	_tmp57__length1 = _vala_array_length (opt_script);
	{
		gchar** i_collection = NULL;
		gint i_collection_length1 = 0;
		gint _i_collection_size_ = 0;
		gint i_it = 0;
		i_collection = _tmp57_;
		i_collection_length1 = _tmp57__length1;
		for (i_it = 0; i_it < _tmp57__length1; i_it = i_it + 1) {
			gchar* _tmp58_;
			gchar* i = NULL;
			_tmp58_ = g_strdup (i_collection[i_it]);
			i = _tmp58_;
			{
				gchar** parts = NULL;
				const gchar* _tmp59_;
				gchar** _tmp60_;
				gchar** _tmp61_;
				gint parts_length1;
				gint _parts_size_;
				gchar** _tmp62_;
				gint _tmp62__length1;
				_tmp59_ = i;
				_tmp61_ = _tmp60_ = g_strsplit (_tmp59_, "=", 2);
				parts = _tmp61_;
				parts_length1 = _vala_array_length (_tmp60_);
				_parts_size_ = parts_length1;
				_tmp62_ = parts;
				_tmp62__length1 = parts_length1;
				if (_tmp62__length1 != 2) {
					FILE* _tmp63_;
					_tmp63_ = stderr;
					fprintf (_tmp63_, "Error: --script argument must be devname=filename\n");
					result = 1;
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					return result;
				}
				{
					UMockdevTestbed* _tmp64_;
					gchar** _tmp65_;
					gint _tmp65__length1;
					const gchar* _tmp66_;
					gchar** _tmp67_;
					gint _tmp67__length1;
					const gchar* _tmp68_;
					_tmp64_ = testbed;
					_tmp65_ = parts;
					_tmp65__length1 = parts_length1;
					_tmp66_ = _tmp65_[0];
					_tmp67_ = parts;
					_tmp67__length1 = parts_length1;
					_tmp68_ = _tmp67_[1];
					umockdev_testbed_load_script (_tmp64_, _tmp66_, _tmp68_, &_inner_error_);
					if (G_UNLIKELY (_inner_error_ != NULL)) {
						goto __catch4_g_error;
					}
				}
				goto __finally4;
				__catch4_g_error:
				{
					GError* e = NULL;
					FILE* _tmp69_;
					gchar** _tmp70_;
					gint _tmp70__length1;
					const gchar* _tmp71_;
					gchar** _tmp72_;
					gint _tmp72__length1;
					const gchar* _tmp73_;
					GError* _tmp74_;
					const gchar* _tmp75_;
					e = _inner_error_;
					_inner_error_ = NULL;
					_tmp69_ = stderr;
					_tmp70_ = parts;
					_tmp70__length1 = parts_length1;
					_tmp71_ = _tmp70_[1];
					_tmp72_ = parts;
					_tmp72__length1 = parts_length1;
					_tmp73_ = _tmp72_[0];
					_tmp74_ = e;
					_tmp75_ = _tmp74_->message;
					fprintf (_tmp69_, "Error: Cannot install %s for device %s: %s\n", _tmp71_, _tmp73_, _tmp75_);
					result = 1;
					_g_error_free0 (e);
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					return result;
				}
				__finally4:
				if (G_UNLIKELY (_inner_error_ != NULL)) {
					gint _tmp76_ = -1;
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return _tmp76_;
				}
				parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
				_g_free0 (i);
			}
		}
	}
	_tmp77_ = opt_unix_stream;
	_tmp77__length1 = _vala_array_length (opt_unix_stream);
	{
		gchar** i_collection = NULL;
		gint i_collection_length1 = 0;
		gint _i_collection_size_ = 0;
		gint i_it = 0;
		i_collection = _tmp77_;
		i_collection_length1 = _tmp77__length1;
		for (i_it = 0; i_it < _tmp77__length1; i_it = i_it + 1) {
			gchar* _tmp78_;
			gchar* i = NULL;
			_tmp78_ = g_strdup (i_collection[i_it]);
			i = _tmp78_;
			{
				gchar** parts = NULL;
				const gchar* _tmp79_;
				gchar** _tmp80_;
				gchar** _tmp81_;
				gint parts_length1;
				gint _parts_size_;
				gchar** _tmp82_;
				gint _tmp82__length1;
				_tmp79_ = i;
				_tmp81_ = _tmp80_ = g_strsplit (_tmp79_, "=", 2);
				parts = _tmp81_;
				parts_length1 = _vala_array_length (_tmp80_);
				_parts_size_ = parts_length1;
				_tmp82_ = parts;
				_tmp82__length1 = parts_length1;
				if (_tmp82__length1 != 2) {
					FILE* _tmp83_;
					_tmp83_ = stderr;
					fprintf (_tmp83_, "Error: --unix-stream argument must be socket_path=filename\n");
					result = 1;
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					return result;
				}
				{
					UMockdevTestbed* _tmp84_;
					gchar** _tmp85_;
					gint _tmp85__length1;
					const gchar* _tmp86_;
					gchar** _tmp87_;
					gint _tmp87__length1;
					const gchar* _tmp88_;
					_tmp84_ = testbed;
					_tmp85_ = parts;
					_tmp85__length1 = parts_length1;
					_tmp86_ = _tmp85_[0];
					_tmp87_ = parts;
					_tmp87__length1 = parts_length1;
					_tmp88_ = _tmp87_[1];
					umockdev_testbed_load_socket_script (_tmp84_, _tmp86_, SOCK_STREAM, _tmp88_, &_inner_error_);
					if (G_UNLIKELY (_inner_error_ != NULL)) {
						goto __catch5_g_error;
					}
				}
				goto __finally5;
				__catch5_g_error:
				{
					GError* e = NULL;
					FILE* _tmp89_;
					gchar** _tmp90_;
					gint _tmp90__length1;
					const gchar* _tmp91_;
					gchar** _tmp92_;
					gint _tmp92__length1;
					const gchar* _tmp93_;
					GError* _tmp94_;
					const gchar* _tmp95_;
					e = _inner_error_;
					_inner_error_ = NULL;
					_tmp89_ = stderr;
					_tmp90_ = parts;
					_tmp90__length1 = parts_length1;
					_tmp91_ = _tmp90_[1];
					_tmp92_ = parts;
					_tmp92__length1 = parts_length1;
					_tmp93_ = _tmp92_[0];
					_tmp94_ = e;
					_tmp95_ = _tmp94_->message;
					fprintf (_tmp89_, "Error: Cannot install %s for stream socket %s: %s\n", _tmp91_, _tmp93_, _tmp95_);
					result = 1;
					_g_error_free0 (e);
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					return result;
				}
				__finally5:
				if (G_UNLIKELY (_inner_error_ != NULL)) {
					gint _tmp96_ = -1;
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return _tmp96_;
				}
				parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
				_g_free0 (i);
			}
		}
	}
	_tmp97_ = opt_evemu_events;
	_tmp97__length1 = _vala_array_length (opt_evemu_events);
	{
		gchar** i_collection = NULL;
		gint i_collection_length1 = 0;
		gint _i_collection_size_ = 0;
		gint i_it = 0;
		i_collection = _tmp97_;
		i_collection_length1 = _tmp97__length1;
		for (i_it = 0; i_it < _tmp97__length1; i_it = i_it + 1) {
			gchar* _tmp98_;
			gchar* i = NULL;
			_tmp98_ = g_strdup (i_collection[i_it]);
			i = _tmp98_;
			{
				gchar** parts = NULL;
				const gchar* _tmp99_;
				gchar** _tmp100_;
				gchar** _tmp101_;
				gint parts_length1;
				gint _parts_size_;
				gchar** _tmp102_;
				gint _tmp102__length1;
				_tmp99_ = i;
				_tmp101_ = _tmp100_ = g_strsplit (_tmp99_, "=", 2);
				parts = _tmp101_;
				parts_length1 = _vala_array_length (_tmp100_);
				_parts_size_ = parts_length1;
				_tmp102_ = parts;
				_tmp102__length1 = parts_length1;
				if (_tmp102__length1 != 2) {
					FILE* _tmp103_;
					_tmp103_ = stderr;
					fprintf (_tmp103_, "Error: --evemu-events argument must be devname=filename\n");
					result = 1;
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					return result;
				}
				{
					UMockdevTestbed* _tmp104_;
					gchar** _tmp105_;
					gint _tmp105__length1;
					const gchar* _tmp106_;
					gchar** _tmp107_;
					gint _tmp107__length1;
					const gchar* _tmp108_;
					_tmp104_ = testbed;
					_tmp105_ = parts;
					_tmp105__length1 = parts_length1;
					_tmp106_ = _tmp105_[0];
					_tmp107_ = parts;
					_tmp107__length1 = parts_length1;
					_tmp108_ = _tmp107_[1];
					umockdev_testbed_load_evemu_events (_tmp104_, _tmp106_, _tmp108_, &_inner_error_);
					if (G_UNLIKELY (_inner_error_ != NULL)) {
						goto __catch6_g_error;
					}
				}
				goto __finally6;
				__catch6_g_error:
				{
					GError* e = NULL;
					FILE* _tmp109_;
					gchar** _tmp110_;
					gint _tmp110__length1;
					const gchar* _tmp111_;
					gchar** _tmp112_;
					gint _tmp112__length1;
					const gchar* _tmp113_;
					GError* _tmp114_;
					const gchar* _tmp115_;
					e = _inner_error_;
					_inner_error_ = NULL;
					_tmp109_ = stderr;
					_tmp110_ = parts;
					_tmp110__length1 = parts_length1;
					_tmp111_ = _tmp110_[1];
					_tmp112_ = parts;
					_tmp112__length1 = parts_length1;
					_tmp113_ = _tmp112_[0];
					_tmp114_ = e;
					_tmp115_ = _tmp114_->message;
					fprintf (_tmp109_, "Error: Cannot install %s for device %s: %s\n", _tmp111_, _tmp113_, _tmp115_);
					result = 1;
					_g_error_free0 (e);
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					return result;
				}
				__finally6:
				if (G_UNLIKELY (_inner_error_ != NULL)) {
					gint _tmp116_ = -1;
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return _tmp116_;
				}
				parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
				_g_free0 (i);
			}
		}
	}
	_tmp117_ = opt_program;
	_tmp117__length1 = _vala_array_length (opt_program);
	if (_tmp117__length1 == 0) {
		FILE* _tmp118_;
		_tmp118_ = stderr;
		fprintf (_tmp118_, "No program specified. See --help for how to use umockdev-run\n");
		result = 1;
		_g_object_unref0 (testbed);
		_g_free0 (preload);
		_g_option_context_free0 (oc);
		return result;
	}
	{
		gchar** _tmp119_;
		gint _tmp119__length1;
		GPid _tmp120_ = 0;
		_tmp119_ = opt_program;
		_tmp119__length1 = _vala_array_length (opt_program);
		g_spawn_async (NULL, _tmp119_, NULL, (G_SPAWN_SEARCH_PATH | G_SPAWN_CHILD_INHERITS_STDIN) | G_SPAWN_DO_NOT_REAP_CHILD, NULL, NULL, &_tmp120_, &_inner_error_);
		child_pid = _tmp120_;
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			goto __catch7_g_error;
		}
	}
	goto __finally7;
	__catch7_g_error:
	{
		GError* e = NULL;
		FILE* _tmp121_;
		gchar** _tmp122_;
		gint _tmp122__length1;
		const gchar* _tmp123_;
		const gchar* _tmp124_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp121_ = stderr;
		_tmp122_ = opt_program;
		_tmp122__length1 = _vala_array_length (opt_program);
		_tmp123_ = _tmp122_[0];
		_tmp124_ = e->message;
		fprintf (_tmp121_, "Cannot run %s: %s\n", _tmp123_, _tmp124_);
		exit (1);
		_g_error_free0 (e);
	}
	__finally7:
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		gint _tmp125_ = -1;
		_g_object_unref0 (testbed);
		_g_free0 (preload);
		_g_option_context_free0 (oc);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return _tmp125_;
	}
	memset (&_tmp126_, 0, sizeof (struct sigaction));
	_tmp126_.sa_handler = _child_sig_handler_sighandler_t;
	_tmp126_.sa_flags = SA_RESETHAND;
	act = _tmp126_;
	sigemptyset (&_tmp127_);
	act.sa_mask = _tmp127_;
	_tmp128_ = act;
	_tmp129_ = sigaction ((gint) SIGTERM, &_tmp128_, NULL);
	_vala_assert (_tmp129_ == 0, "Posix.sigaction (Posix.Signal.TERM, act, null) == 0");
	_tmp130_ = act;
	_tmp131_ = sigaction ((gint) SIGHUP, &_tmp130_, NULL);
	_vala_assert (_tmp131_ == 0, "Posix.sigaction (Posix.Signal.HUP, act, null) == 0");
	_tmp132_ = act;
	_tmp133_ = sigaction ((gint) SIGINT, &_tmp132_, NULL);
	_vala_assert (_tmp133_ == 0, "Posix.sigaction (Posix.Signal.INT, act, null) == 0");
	_tmp134_ = act;
	_tmp135_ = sigaction ((gint) SIGQUIT, &_tmp134_, NULL);
	_vala_assert (_tmp135_ == 0, "Posix.sigaction (Posix.Signal.QUIT, act, null) == 0");
	_tmp136_ = act;
	_tmp137_ = sigaction ((gint) SIGABRT, &_tmp136_, NULL);
	_vala_assert (_tmp137_ == 0, "Posix.sigaction (Posix.Signal.ABRT, act, null) == 0");
	_tmp138_ = child_pid;
	waitpid ((pid_t) _tmp138_, &_tmp139_, 0);
	status = _tmp139_;
	_tmp140_ = child_pid;
	g_spawn_close_pid (_tmp140_);
	_g_object_unref0 (testbed);
	testbed = NULL;
	_tmp141_ = status;
	if (WIFEXITED (_tmp141_)) {
		gint _tmp142_;
		_tmp142_ = status;
		result = WEXITSTATUS (_tmp142_);
		_g_object_unref0 (testbed);
		_g_free0 (preload);
		_g_option_context_free0 (oc);
		return result;
	}
	_tmp143_ = status;
	if (WIFSIGNALED (_tmp143_)) {
		gint _tmp144_;
		_tmp144_ = status;
		raise (WTERMSIG (_tmp144_));
	}
	result = status;
	_g_object_unref0 (testbed);
	_g_free0 (preload);
	_g_option_context_free0 (oc);
	return result;
}


int
main (int argc,
      char ** argv)
{
	return _vala_main (argv, argc);
}


static void
_vala_array_destroy (gpointer array,
                     gint array_length,
                     GDestroyNotify destroy_func)
{
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void
_vala_array_free (gpointer array,
                  gint array_length,
                  GDestroyNotify destroy_func)
{
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint
_vala_array_length (gpointer array)
{
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



