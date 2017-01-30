 inherit "players/mythos/closed/guild/dweapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("dark blade");
    set_alt_name("sword");
    set_alias("dark");
    set_short("Dark Blade");
    set_long("The base mold for the Dark Blade.\n");
    set_class(18);
    set_weight(3);
    set_value(0);
    set_hit_func(this_object());
}
weapon_hit(attacker){
if(1 == random(3))
  {
    return 5;
}}
