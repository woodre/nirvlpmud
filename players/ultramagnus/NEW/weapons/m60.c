inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("M-60 Machine Gun");
set_short("Machine Gun");
set_alias("gun");
set_long("An extremely powerful gun that can shoot 600 rounds per second.\n");
set_value(10000);
set_weight(4);
set_class(200);
set_hit_func(this_object());
}
weapon_hit(attacker) {
write("Your opponent suddenly has some bullet holes that u can see through\n");
return 0;
 }
