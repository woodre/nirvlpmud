inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sword");
                set_class(12);
                set_value(500);
                set_weight(4);
                set_alias("razor");
                set_short("Knight sword");
set_long(
"A rusty but decent weapon of a long dead knight.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
  {
if (random(100) < 30) return 7;
}
