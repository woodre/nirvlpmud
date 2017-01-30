inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) return;
set_name("princess");
set_alias("maron");
set_short("Princess Maron");
set_race("namekian");
set_long(
"Princess Maron is Kami's twin sister. She basically just follows\n"+
"Kami around doing whatever he does. She has two antennae and green\n"+
"skin, and she looks to be a little shorter than Kami. Perhaps this is the\n"+
"defining feature for female Namekians. Maron has been betrothed\n"+
"by her father to marry Dende.\n");
set_level(6);
set_wc(8);
set_hp(250);
set_al(400);
set_aggressive(0);
set_chat_chance(0);
move_object(clone_object("/players/mosobp/areas/TEMPLE/OBJ/tiara.c"), this_object());
init_command("wear armor");
set_ac(10);
set_ac(10);
}
