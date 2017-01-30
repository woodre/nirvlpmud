inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) return;
set_name("child");
set_alias("boy");
set_short("A lost little boy");
set_race("namekian");
set_long(
"This child looks to be about 8 or 9 years old. He has green skin\n"+
"and two antennae on top of his head. He looks to be lost and trying\n"+
"to find his mother. He's wearing only a set of rags so he must\n"+
"be a peasant or someone of lower stature in the community\n");
set_level(8);
set_wc(5);
set_hp(150);
set_al(500);
set_aggressive(0);
set_chat_chance(30);
set_a_chat_chance(0);
load_chat("The little boy begins to cry because he cant find his mother.\n");
load_chat("The little boy says: Have you seen my mother?\n");
load_chat("The little boy screams as he starts to throw a temper tantrum.\n");
move_object(clone_object("/players/mosobp/areas/TEMPLE/OBJ/rags.c"), this_object());
init_command("wear armor");
set_ac(8);
}
