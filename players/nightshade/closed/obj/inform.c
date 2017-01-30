object target;
shadow_target(str) {
shadow(str,1);
target = str;
}
/* My own little way of using shadows, if anyone copies this code
damn your fucking cheesy shit ass to hell */
hit_player(arg) {
int real_damage;
real_damage = target->hit_player(arg);
if (real_damage > 0)
tell_object(target,"Shield says: You just got hit for "+real_damage+" points of damage.\n");
return real_damage;
}
