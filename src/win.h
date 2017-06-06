#ifndef WIN_H
#define WIN_H

#include "term.h"

#define dont_debug_resize

#ifdef debug_resize
#define trace_resize(params)	printf params
#else
#define trace_resize(params)
#endif

extern char * home;
extern char * cmd;
extern bool icon_is_from_shortcut;

extern void exit_mintty(void);
extern void report_pos(void);
extern void win_reconfig(void);

extern void win_update(void);
extern void win_schedule_update(void);
extern void do_update(void);

extern void win_text(int x, int y, wchar *text, int len, cattr attr, cattr *textattr, ushort lattr, bool has_rtl);
extern void win_update_mouse(void);
extern void win_capture_mouse(void);
extern void win_bell(config *);

extern void win_set_title(char *);
extern void win_save_title(void);
extern void win_restore_title(void);
extern void win_copy_title(void);
extern char * win_get_title(void);
extern void win_copy_text(const char *s);

extern colour win_get_colour(colour_i);
extern void win_set_colour(colour_i, colour);
extern void win_reset_colours(void);
extern colour win_get_sys_colour(bool fg);

extern void win_invalidate_all(void);

extern void win_set_pos(int x, int y);
extern void win_set_chars(int rows, int cols);
extern void win_set_pixels(int height, int width);
extern void win_set_geom(int y, int x, int height, int width);
extern void win_maximise(int max);
extern void win_set_zorder(bool top);
extern void win_set_iconic(bool);
extern void win_update_scrollbar(void);
extern bool win_is_iconic(void);
extern void win_get_pos(int *xp, int *yp);
extern void win_get_pixels(int *height_p, int *width_p);
extern void win_get_screen_chars(int *rows_p, int *cols_p);
extern void win_popup_menu(mod_keys mods);

extern void win_zoom_font(int, bool sync_size_with_font);
extern void win_set_font_size(int, bool sync_size_with_font);
extern uint win_get_font_size(void);

extern void win_check_glyphs(wchar *wcs, uint num);

extern void win_open(wstring path);
extern void win_copy(const wchar *data, uint *attrs, int len);
extern void win_paste(void);

extern void win_set_timer(void_fn cb, uint ticks);

extern bool print_opterror(FILE * stream, string msg, bool utf8params, string p1, string p2);
extern void win_show_about(void);
extern void win_show_error(char * msg);
extern void win_show_warning(char * msg);
extern int message_box(HWND parwnd, char * wtext, char * wcaption, int type, wstring ok);
extern int message_box_w(HWND parwnd, wchar * wtext, wchar * wcaption, int type, wstring ok);

extern bool win_is_glass_available(void);

extern void win_clear_images(void);

extern int get_tick_count(void);
extern int cursor_blink_ticks(void);

extern int win_char_width(xchar);
extern wchar win_combine_chars(wchar bc, wchar cc);

extern wchar win_linedraw_chars[31];

#endif
