inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) return;
set_name("prince");
set_alias("kami");
set_short("Prince Kami");
set_race("namekian");
set_long(
"Prince Kami has green skin and two antennae like the rest of the\n"+
"namekians. He looks to be about 19 or 20 years old. Kami is the son \n"+
"of King Saichoryo of Planet Namek. He's been trained to defend his\n"+
"planet. Although he's not very powerful, he's won many battles.\n");
set_level(13);
set_wc(8);
set_hp(325);
set_al(400);
set_aggressive(0);
set_chat_chance(10);
load_chat("The Prince says: I hope i dont get dirty my mommy would have a fit if i got these clothes dirty.\n");
load_chat("The Prince says: I sure hope i find dende i need to have a talk with him.\n");
move_object(clone_object("/players/mosobp/areas/TEMPLE/OBJ/princerobes.c"), this_object());
init_command("wear armor");
set_ac(10);
}
