/* umockdev-run.c generated by valac 0.20.1, the Vala compiler
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


extern gchar** opt_device;
gchar** opt_device = NULL;
extern gchar** opt_ioctl;
gchar** opt_ioctl = NULL;
extern gchar** opt_script;
gchar** opt_script = NULL;
extern gchar** opt_unix_stream;
gchar** opt_unix_stream = NULL;
extern gchar** opt_program;
gchar** opt_program = NULL;
extern gboolean opt_version;
gboolean opt_version = FALSE;
extern GPid child_pid;
GPid child_pid = 0;

void child_sig_handler (gint sig);
gint _vala_main (gchar** args, int args_length1);
static void _child_sig_handler_sighandler_t (gint signal);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);

const GOptionEntry options[7] = {{"device", 'd', 0, G_OPTION_ARG_FILENAME_ARRAY, &opt_device, "Load an umockdev-record device description into the testbed. Can be sp" \
"ecified multiple times.", "filename"}, {"ioctl", 'i', 0, G_OPTION_ARG_FILENAME_ARRAY, &opt_ioctl, "Load an umockdev-record ioctl dump into the testbed. Can be specified " \
"multiple times.", "devname=ioctlfilename"}, {"script", 's', 0, G_OPTION_ARG_FILENAME_ARRAY, &opt_script, "Load an umockdev-record script into the testbed. Can be specified mult" \
"iple times.", "devname=scriptfilename"}, {"unix-stream", 'u', 0, G_OPTION_ARG_FILENAME_ARRAY, &opt_unix_stream, "Load an umockdev-record script for a mocked Unix stream socket. Can be" \
" specified multiple times.", "socket_path=scriptfilename"}, {"", (gchar) 0, 0, G_OPTION_ARG_STRING_ARRAY, &opt_program, "", ""}, {"version", (gchar) 0, 0, G_OPTION_ARG_NONE, &opt_version, "Output version information and exit"}, {NULL}};

void child_sig_handler (gint sig) {
	gint _tmp0_;
	GPid _tmp1_;
	gint _tmp2_;
	gint _tmp3_ = 0;
	_tmp0_ = sig;
	g_debug ("umockdev-run.vala:56: umockdev-run: caught signal %i, propagating to c" \
"hild\n", _tmp0_);
	_tmp1_ = child_pid;
	_tmp2_ = sig;
	_tmp3_ = kill ((pid_t) _tmp1_, _tmp2_);
	if (_tmp3_ != 0) {
		FILE* _tmp4_;
		gint _tmp5_;
		GPid _tmp6_;
		gint _tmp7_;
		const gchar* _tmp8_ = NULL;
		_tmp4_ = stderr;
		_tmp5_ = sig;
		_tmp6_ = child_pid;
		_tmp7_ = errno;
		_tmp8_ = g_strerror (_tmp7_);
		fprintf (_tmp4_, "umockdev-run: unable to propagate signal %i to child %i: %s\n", _tmp5_, (gint) _tmp6_, _tmp8_);
	}
}


static void _child_sig_handler_sighandler_t (gint signal) {
	child_sig_handler (signal);
}


gint _vala_main (gchar** args, int args_length1) {
	gint result = 0;
	GOptionContext* _tmp0_;
	GOptionContext* oc;
	GOptionContext* _tmp1_;
	GOptionContext* _tmp2_;
	gboolean _tmp9_;
	const gchar* _tmp11_ = NULL;
	gchar* _tmp12_;
	gchar* preload;
	const gchar* _tmp13_;
	const gchar* _tmp17_;
	gchar* _tmp18_;
	gchar* _tmp19_;
	UMockdevTestbed* _tmp20_;
	UMockdevTestbed* testbed;
	gchar** _tmp21_;
	gint _tmp21__length1;
	gchar** _tmp35_;
	gint _tmp35__length1;
	gchar** _tmp54_;
	gint _tmp54__length1;
	gchar** _tmp73_;
	gint _tmp73__length1;
	gchar** _tmp92_;
	gint _tmp92__length1;
	gint status = 0;
	struct sigaction _tmp100_ = {0};
	struct sigaction act;
	struct sigaction _tmp101_;
	sigset_t _tmp102_;
	struct sigaction _tmp103_;
	gint _tmp104_ = 0;
	struct sigaction _tmp105_;
	gint _tmp106_ = 0;
	struct sigaction _tmp107_;
	gint _tmp108_ = 0;
	struct sigaction _tmp109_;
	gint _tmp110_ = 0;
	struct sigaction _tmp111_;
	gint _tmp112_ = 0;
	GPid _tmp113_;
	gint _tmp114_ = 0;
	GPid _tmp115_;
	gint _tmp116_;
	gboolean _tmp117_ = FALSE;
	gint _tmp120_;
	gboolean _tmp121_ = FALSE;
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
		if (_inner_error_ != NULL) {
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
		gchar** _tmp7_;
		gint _tmp7__length1;
		const gchar* _tmp8_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp4_ = stderr;
		_tmp5_ = e;
		_tmp6_ = _tmp5_->message;
		_tmp7_ = args;
		_tmp7__length1 = args_length1;
		_tmp8_ = _tmp7_[0];
		fprintf (_tmp4_, "Error: %s\nRun %s --help for how to use this program\n", _tmp6_, _tmp8_);
		result = 1;
		_g_error_free0 (e);
		_g_option_context_free0 (oc);
		return result;
	}
	__finally0:
	if (_inner_error_ != NULL) {
		_g_option_context_free0 (oc);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
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
					if (_inner_error_ != NULL) {
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
				if (_inner_error_ != NULL) {
					_g_free0 (record);
					_g_free0 (path);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return 0;
				}
				{
					UMockdevTestbed* _tmp29_;
					const gchar* _tmp30_;
					_tmp29_ = testbed;
					_tmp30_ = record;
					umockdev_testbed_add_from_string (_tmp29_, _tmp30_, &_inner_error_);
					if (_inner_error_ != NULL) {
						goto __catch2_g_error;
					}
				}
				goto __finally2;
				__catch2_g_error:
				{
					GError* e = NULL;
					FILE* _tmp31_;
					const gchar* _tmp32_;
					GError* _tmp33_;
					const gchar* _tmp34_;
					e = _inner_error_;
					_inner_error_ = NULL;
					_tmp31_ = stderr;
					_tmp32_ = path;
					_tmp33_ = e;
					_tmp34_ = _tmp33_->message;
					fprintf (_tmp31_, "Error: Invalid record file %s: %s\n", _tmp32_, _tmp34_);
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
				if (_inner_error_ != NULL) {
					_g_free0 (record);
					_g_free0 (path);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return 0;
				}
				_g_free0 (record);
				_g_free0 (path);
			}
		}
	}
	_tmp35_ = opt_ioctl;
	_tmp35__length1 = _vala_array_length (opt_ioctl);
	{
		gchar** i_collection = NULL;
		gint i_collection_length1 = 0;
		gint _i_collection_size_ = 0;
		gint i_it = 0;
		i_collection = _tmp35_;
		i_collection_length1 = _tmp35__length1;
		for (i_it = 0; i_it < _tmp35__length1; i_it = i_it + 1) {
			gchar* _tmp36_;
			gchar* i = NULL;
			_tmp36_ = g_strdup (i_collection[i_it]);
			i = _tmp36_;
			{
				const gchar* _tmp37_;
				gchar** _tmp38_;
				gchar** _tmp39_ = NULL;
				gchar** parts;
				gint parts_length1;
				gint _parts_size_;
				gchar** _tmp40_;
				gint _tmp40__length1;
				_tmp37_ = i;
				_tmp39_ = _tmp38_ = g_strsplit (_tmp37_, "=", 2);
				parts = _tmp39_;
				parts_length1 = _vala_array_length (_tmp38_);
				_parts_size_ = parts_length1;
				_tmp40_ = parts;
				_tmp40__length1 = parts_length1;
				if (_tmp40__length1 != 2) {
					FILE* _tmp41_;
					_tmp41_ = stderr;
					fprintf (_tmp41_, "Error: --ioctl argument must be devname=filename\n");
					result = 1;
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					return result;
				}
				{
					UMockdevTestbed* _tmp42_;
					gchar** _tmp43_;
					gint _tmp43__length1;
					const gchar* _tmp44_;
					gchar** _tmp45_;
					gint _tmp45__length1;
					const gchar* _tmp46_;
					_tmp42_ = testbed;
					_tmp43_ = parts;
					_tmp43__length1 = parts_length1;
					_tmp44_ = _tmp43_[0];
					_tmp45_ = parts;
					_tmp45__length1 = parts_length1;
					_tmp46_ = _tmp45_[1];
					umockdev_testbed_load_ioctl (_tmp42_, _tmp44_, _tmp46_, &_inner_error_);
					if (_inner_error_ != NULL) {
						goto __catch3_g_error;
					}
				}
				goto __finally3;
				__catch3_g_error:
				{
					GError* e = NULL;
					FILE* _tmp47_;
					gchar** _tmp48_;
					gint _tmp48__length1;
					const gchar* _tmp49_;
					gchar** _tmp50_;
					gint _tmp50__length1;
					const gchar* _tmp51_;
					GError* _tmp52_;
					const gchar* _tmp53_;
					e = _inner_error_;
					_inner_error_ = NULL;
					_tmp47_ = stderr;
					_tmp48_ = parts;
					_tmp48__length1 = parts_length1;
					_tmp49_ = _tmp48_[1];
					_tmp50_ = parts;
					_tmp50__length1 = parts_length1;
					_tmp51_ = _tmp50_[0];
					_tmp52_ = e;
					_tmp53_ = _tmp52_->message;
					fprintf (_tmp47_, "Error: Cannot install %s for device %s: %s\n", _tmp49_, _tmp51_, _tmp53_);
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
				if (_inner_error_ != NULL) {
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return 0;
				}
				parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
				_g_free0 (i);
			}
		}
	}
	_tmp54_ = opt_script;
	_tmp54__length1 = _vala_array_length (opt_script);
	{
		gchar** i_collection = NULL;
		gint i_collection_length1 = 0;
		gint _i_collection_size_ = 0;
		gint i_it = 0;
		i_collection = _tmp54_;
		i_collection_length1 = _tmp54__length1;
		for (i_it = 0; i_it < _tmp54__length1; i_it = i_it + 1) {
			gchar* _tmp55_;
			gchar* i = NULL;
			_tmp55_ = g_strdup (i_collection[i_it]);
			i = _tmp55_;
			{
				const gchar* _tmp56_;
				gchar** _tmp57_;
				gchar** _tmp58_ = NULL;
				gchar** parts;
				gint parts_length1;
				gint _parts_size_;
				gchar** _tmp59_;
				gint _tmp59__length1;
				_tmp56_ = i;
				_tmp58_ = _tmp57_ = g_strsplit (_tmp56_, "=", 2);
				parts = _tmp58_;
				parts_length1 = _vala_array_length (_tmp57_);
				_parts_size_ = parts_length1;
				_tmp59_ = parts;
				_tmp59__length1 = parts_length1;
				if (_tmp59__length1 != 2) {
					FILE* _tmp60_;
					_tmp60_ = stderr;
					fprintf (_tmp60_, "Error: --script argument must be devname=filename\n");
					result = 1;
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					return result;
				}
				{
					UMockdevTestbed* _tmp61_;
					gchar** _tmp62_;
					gint _tmp62__length1;
					const gchar* _tmp63_;
					gchar** _tmp64_;
					gint _tmp64__length1;
					const gchar* _tmp65_;
					_tmp61_ = testbed;
					_tmp62_ = parts;
					_tmp62__length1 = parts_length1;
					_tmp63_ = _tmp62_[0];
					_tmp64_ = parts;
					_tmp64__length1 = parts_length1;
					_tmp65_ = _tmp64_[1];
					umockdev_testbed_load_script (_tmp61_, _tmp63_, _tmp65_, &_inner_error_);
					if (_inner_error_ != NULL) {
						goto __catch4_g_error;
					}
				}
				goto __finally4;
				__catch4_g_error:
				{
					GError* e = NULL;
					FILE* _tmp66_;
					gchar** _tmp67_;
					gint _tmp67__length1;
					const gchar* _tmp68_;
					gchar** _tmp69_;
					gint _tmp69__length1;
					const gchar* _tmp70_;
					GError* _tmp71_;
					const gchar* _tmp72_;
					e = _inner_error_;
					_inner_error_ = NULL;
					_tmp66_ = stderr;
					_tmp67_ = parts;
					_tmp67__length1 = parts_length1;
					_tmp68_ = _tmp67_[1];
					_tmp69_ = parts;
					_tmp69__length1 = parts_length1;
					_tmp70_ = _tmp69_[0];
					_tmp71_ = e;
					_tmp72_ = _tmp71_->message;
					fprintf (_tmp66_, "Error: Cannot install %s for device %s: %s\n", _tmp68_, _tmp70_, _tmp72_);
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
				if (_inner_error_ != NULL) {
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return 0;
				}
				parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
				_g_free0 (i);
			}
		}
	}
	_tmp73_ = opt_unix_stream;
	_tmp73__length1 = _vala_array_length (opt_unix_stream);
	{
		gchar** i_collection = NULL;
		gint i_collection_length1 = 0;
		gint _i_collection_size_ = 0;
		gint i_it = 0;
		i_collection = _tmp73_;
		i_collection_length1 = _tmp73__length1;
		for (i_it = 0; i_it < _tmp73__length1; i_it = i_it + 1) {
			gchar* _tmp74_;
			gchar* i = NULL;
			_tmp74_ = g_strdup (i_collection[i_it]);
			i = _tmp74_;
			{
				const gchar* _tmp75_;
				gchar** _tmp76_;
				gchar** _tmp77_ = NULL;
				gchar** parts;
				gint parts_length1;
				gint _parts_size_;
				gchar** _tmp78_;
				gint _tmp78__length1;
				_tmp75_ = i;
				_tmp77_ = _tmp76_ = g_strsplit (_tmp75_, "=", 2);
				parts = _tmp77_;
				parts_length1 = _vala_array_length (_tmp76_);
				_parts_size_ = parts_length1;
				_tmp78_ = parts;
				_tmp78__length1 = parts_length1;
				if (_tmp78__length1 != 2) {
					FILE* _tmp79_;
					_tmp79_ = stderr;
					fprintf (_tmp79_, "Error: --unix-stream argument must be socket_path=filename\n");
					result = 1;
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					return result;
				}
				{
					UMockdevTestbed* _tmp80_;
					gchar** _tmp81_;
					gint _tmp81__length1;
					const gchar* _tmp82_;
					gchar** _tmp83_;
					gint _tmp83__length1;
					const gchar* _tmp84_;
					_tmp80_ = testbed;
					_tmp81_ = parts;
					_tmp81__length1 = parts_length1;
					_tmp82_ = _tmp81_[0];
					_tmp83_ = parts;
					_tmp83__length1 = parts_length1;
					_tmp84_ = _tmp83_[1];
					umockdev_testbed_load_socket_script (_tmp80_, _tmp82_, SOCK_STREAM, _tmp84_, &_inner_error_);
					if (_inner_error_ != NULL) {
						goto __catch5_g_error;
					}
				}
				goto __finally5;
				__catch5_g_error:
				{
					GError* e = NULL;
					FILE* _tmp85_;
					gchar** _tmp86_;
					gint _tmp86__length1;
					const gchar* _tmp87_;
					gchar** _tmp88_;
					gint _tmp88__length1;
					const gchar* _tmp89_;
					GError* _tmp90_;
					const gchar* _tmp91_;
					e = _inner_error_;
					_inner_error_ = NULL;
					_tmp85_ = stderr;
					_tmp86_ = parts;
					_tmp86__length1 = parts_length1;
					_tmp87_ = _tmp86_[1];
					_tmp88_ = parts;
					_tmp88__length1 = parts_length1;
					_tmp89_ = _tmp88_[0];
					_tmp90_ = e;
					_tmp91_ = _tmp90_->message;
					fprintf (_tmp85_, "Error: Cannot install %s for stream socket %s: %s\n", _tmp87_, _tmp89_, _tmp91_);
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
				if (_inner_error_ != NULL) {
					parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (i);
					_g_object_unref0 (testbed);
					_g_free0 (preload);
					_g_option_context_free0 (oc);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return 0;
				}
				parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
				_g_free0 (i);
			}
		}
	}
	_tmp92_ = opt_program;
	_tmp92__length1 = _vala_array_length (opt_program);
	if (_tmp92__length1 == 0) {
		FILE* _tmp93_;
		_tmp93_ = stderr;
		fprintf (_tmp93_, "No program specified. See --help for how to use umockdev-run\n");
		result = 1;
		_g_object_unref0 (testbed);
		_g_free0 (preload);
		_g_option_context_free0 (oc);
		return result;
	}
	{
		gchar** _tmp94_;
		gint _tmp94__length1;
		GPid _tmp95_ = 0;
		_tmp94_ = opt_program;
		_tmp94__length1 = _vala_array_length (opt_program);
		g_spawn_async (NULL, _tmp94_, NULL, (G_SPAWN_SEARCH_PATH | G_SPAWN_CHILD_INHERITS_STDIN) | G_SPAWN_DO_NOT_REAP_CHILD, NULL, NULL, &_tmp95_, &_inner_error_);
		child_pid = _tmp95_;
		if (_inner_error_ != NULL) {
			goto __catch6_g_error;
		}
	}
	goto __finally6;
	__catch6_g_error:
	{
		GError* e = NULL;
		FILE* _tmp96_;
		gchar** _tmp97_;
		gint _tmp97__length1;
		const gchar* _tmp98_;
		const gchar* _tmp99_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp96_ = stderr;
		_tmp97_ = opt_program;
		_tmp97__length1 = _vala_array_length (opt_program);
		_tmp98_ = _tmp97_[0];
		_tmp99_ = e->message;
		fprintf (_tmp96_, "Cannot run %s: %s\n", _tmp98_, _tmp99_);
		exit (1);
		_g_error_free0 (e);
	}
	__finally6:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (testbed);
		_g_free0 (preload);
		_g_option_context_free0 (oc);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
	memset (&_tmp100_, 0, sizeof (struct sigaction));
	_tmp100_.sa_handler = _child_sig_handler_sighandler_t;
	_tmp100_.sa_flags = SA_RESETHAND;
	act = _tmp100_;
	_tmp101_ = act;
	_tmp102_ = _tmp101_.sa_mask;
	sigemptyset (&_tmp102_);
	_tmp103_ = act;
	_tmp104_ = sigaction (SIGTERM, &_tmp103_, NULL);
	_vala_assert (_tmp104_ == 0, "Posix.sigaction (Posix.SIGTERM, act, null) == 0");
	_tmp105_ = act;
	_tmp106_ = sigaction (SIGHUP, &_tmp105_, NULL);
	_vala_assert (_tmp106_ == 0, "Posix.sigaction (Posix.SIGHUP, act, null) == 0");
	_tmp107_ = act;
	_tmp108_ = sigaction (SIGINT, &_tmp107_, NULL);
	_vala_assert (_tmp108_ == 0, "Posix.sigaction (Posix.SIGINT, act, null) == 0");
	_tmp109_ = act;
	_tmp110_ = sigaction (SIGQUIT, &_tmp109_, NULL);
	_vala_assert (_tmp110_ == 0, "Posix.sigaction (Posix.SIGQUIT, act, null) == 0");
	_tmp111_ = act;
	_tmp112_ = sigaction (SIGABRT, &_tmp111_, NULL);
	_vala_assert (_tmp112_ == 0, "Posix.sigaction (Posix.SIGABRT, act, null) == 0");
	_tmp113_ = child_pid;
	waitpid ((pid_t) _tmp113_, &_tmp114_, 0);
	status = _tmp114_;
	_tmp115_ = child_pid;
	g_spawn_close_pid (_tmp115_);
	_g_object_unref0 (testbed);
	testbed = NULL;
	_tmp116_ = status;
	_tmp117_ = WIFEXITED (_tmp116_);
	if (_tmp117_) {
		gint _tmp118_;
		gint _tmp119_ = 0;
		_tmp118_ = status;
		_tmp119_ = WEXITSTATUS (_tmp118_);
		result = _tmp119_;
		_g_object_unref0 (testbed);
		_g_free0 (preload);
		_g_option_context_free0 (oc);
		return result;
	}
	_tmp120_ = status;
	_tmp121_ = WIFSIGNALED (_tmp120_);
	if (_tmp121_) {
		gint _tmp122_;
		int _tmp123_ = 0;
		_tmp122_ = status;
		_tmp123_ = WTERMSIG (_tmp122_);
		raise (_tmp123_);
	}
	result = status;
	_g_object_unref0 (testbed);
	_g_free0 (preload);
	_g_option_context_free0 (oc);
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


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



