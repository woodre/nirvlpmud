inherit "obj/weapon";
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("whip");
                set_class(15);
                set_value(500);
                set_weight(5);
                set_alias("whip");
set_short("Six-headed Whip");
set_long("A wicked six-headed whip used by the female Drow clerics to enforce the will of Lolth their evil deity and for the pleasure of causing pain.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
  {
if (random(100) < 30) return 4;
}
