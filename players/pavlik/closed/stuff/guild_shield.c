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

hit_player(arg) {
if (arg + dmg < 500) {
dmg = dmg + arg;
 target->hit_player(arg/3);
return 1;
}
remove_target();
return 1;
}

remove_target() {
tell_object(target, "\n"+
     "You feel the field around you flicker and then fade out.\n\n");
target->hit_player(dmg - dmg);
if(present("shobj", target))
  destruct(present("shobj", target));
destruct(this_object());
return 1;
}
