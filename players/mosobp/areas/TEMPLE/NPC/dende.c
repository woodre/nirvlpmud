inherit "/obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
set_alias("guardian");
set_name("dende");
set_short("The Namekian guardian Dende");
set_race("namekian");
set_long(
"Dende is the guardian of Namek itself, although he's not very powerful\n"+
"he merely looks over the planet and alerts the fighters if he notices\n"+
"something is awry. He has green skin and two antennae like all\n"+
"nameks do. Dende is known for unlocking Gohan's powers to fight\n"+
"against Frieza's henchmen.\n");
set_level(12);
set_wc(16);
set_hp(185);
set_al(1000);
set_aggressive(0);
set_chat_chance(10);
load_chat("Dende begins chanting an ancient encantation to heal someone in the room.\n");
load_chat("Dende says: Hello, Welcome to my temple.\n");
move_object(clone_object("/players/mosobp/areas/TEMPLE/OBJ/robes.c"), this_object ());
init_command("wear armor");
set_ac(9);
}
