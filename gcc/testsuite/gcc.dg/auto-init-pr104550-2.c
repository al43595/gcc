/* PR 104550 */
/* { dg-do compile } */
/* { dg-options "-O -Wuninitialized -ftrivial-auto-var-init=zero" } */
struct vx_audio_level {
 int has_monitor_level : 1;
};

void vx_set_monitor_level() {
 struct vx_audio_level info; 
 __builtin_clear_padding (&info);  /* { dg-bogus "info" "is used uninitialized" } */ 
}
