inherit "obj/monster";
reset (arg) {
set_name("deathmonger");
set_short("deathmonger---the mentally disturbed");
set_long ("The disillusioned person who thinks he is a demigod.  Very tragic.\n");
set_level(18);
set_ac(3);
set_hp(200);
set_wc(12);
set_can_kill(1);
set_heal(4, 50);
::reset();
}
