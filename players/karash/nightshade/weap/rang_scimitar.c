/* changed the random(10) < 6 to < 3
 - mythos <5-10-96> */

inherit "obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("scimitar");
set_alias("scimitar");
set_short("Ranger Scimitar");
set_long("This is a normal looking scimitar.\n");
set_class(15);
set_value(200);
set_weight(5);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(10) < 3) return 3;
}
