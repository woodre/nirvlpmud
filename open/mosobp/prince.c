inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) return;
set_name("prince");
set_short("A Prince");
set_race("namekian");
set_long("blah.\n");
set_level(13);
set_ac(10);
set_wc(8);
set_hp(325);
set_al(400);
set_aggressive(0);
set_chat_chance(1);
load_chat("The Prince says: I hope i dont get dirty my mommy would have a fit if i got these clothes dirty.\n");
load_chat("The Prince says: I sure hope i find dende i need to have a talk with him.\n");
move_object(clone_object("/players/mosobp/areas/TEMPLE/OBJ/princerobes.c"), this object());
init_command("wear armor");
}
