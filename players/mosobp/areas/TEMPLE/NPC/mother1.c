inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
 if(arg) return;
set_name("mother");
set_short("A mother");
set_race("Namekian");
set_long(
"This mother appears to be quite distraught looking for something,\n"+
"perhaps her child. She is wearing the rags of a peasant and looks\n"+
"as if she hasnt changed or showered in days.\n");
set_level(10);
set_wc(7);
set_hp(250);
set_al(0);
set_aggressive(0);
set_chat_chance(10);
load_chat("A mother says: have you seen my child?");
move_object(clone_object("/players/mosobp/areas/TEMPLE/OBJ/rags.c"), this_object());
init_command("wear armor");
set_ac(10);
}
