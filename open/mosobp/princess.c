inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) return;
set_name("princess");
set_short("A Princess");
set_race("namekian");
set_long("blah.\n");
set_level(13);
set_ac(10);
set_wc(8);
set_hp(325);
set_al(400);
set_aggressive(0);
set_chat_chance(0);
move_object(clone_object("/players/mosobp/area/TEMPLE/OBJ/tiara.c"), this_object());
init_command("wear armor");
}
