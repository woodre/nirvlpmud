inherit "obj/monster";
reset(arg) {
set_name("rabbit");
set_short("A common white rabbit");
set_long("An incredibly vicious monster as in Monty Python.\n");
set_level(12);
set_ac(9);
set_hp(180);
set_wc(16);
set_can_kill(1);
set_heal(4, 50);

::reset();
}
