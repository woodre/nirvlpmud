#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("glowing spear");
    set_alias("spear");
    set_type("spear");         /* set type added by Pavlik */
      set_short("A Glowing Spear");
      set_long("A sturdy magical spear of fine craftsmanship.\n");
    set_class(15);
    set_weight(2);
    set_value(600);
    set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(11);
   if (w>8) {
say(tp+"'s spear pulses with power as it drinks the blood of its foe.\n");
write("Your spear pulses with power as it drinks the blood of your foe.\n");
return 4;
    }
    return;
}
