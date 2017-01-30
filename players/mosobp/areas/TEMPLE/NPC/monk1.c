inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) return;
set_name("priest");
set_short("A Namekian Priest");
set_race("namekian");
set_long(
"This is a priest of Namek, who is here to tell people of Namekian\n"+
"scriptures he has been trained by Prince Kami's father in the Namekian\n"+
"fighting style. Along side Kami he helps defend the planet.\n");
set_level(8);
set_wc(12);
set_hp(120);
set_al(1000);
set_aggressive(0);
set_chat_chance(10);
set_a_chat_chance(0);
load_chat("The priest begins to hum a hymn.\n");
load_chat("The priest begins quoting scriptures from the namekian bible at you.\n");
move_object(clone_object("/players/mosobp/areas/TEMPLE/OBJ/robes.c"), this_object ());
init_command("wear armor");
set_ac(7);
}
