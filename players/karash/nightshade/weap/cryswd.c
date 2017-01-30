inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sword");
                set_class(15);
                set_value(450);
                set_weight(4);
                set_alias("razor");
                set_short("Crystal Sword");
set_long("This sword is made of crystal but is strong as any steel blade you can find.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
  {
if (random(100) < 20) return 3;
}
