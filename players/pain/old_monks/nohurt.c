object target;
int dmg;
reset(arg) {
if (arg) return;
dmg = 0;
}
shadow_target(str) {
shadow(str,1);
target = str;
}
/* My own little way of coding this, if anyone copies this code
damn your fucking cheesy shit ass to hell */
/* Nightshade 9/30/92 */

hit_player(arg) {
if (arg + dmg < 1000) {
dmg = dmg + arg;
return 0;
}
tell_object(target,"You feel the effects of invincibility wearing off.\n");
target->hit_player((dmg + arg) - 1000);
destruct(this_object());
return 1;
}
