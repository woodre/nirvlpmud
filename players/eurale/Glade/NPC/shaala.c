#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("shaala");
set_alias("cyclops");
set_race("creature");
set_gender("female");
set_short(BOLD+"Shaala"+NORM+", the cyclops");
set_long(
  "This diminutive relative of the giants is a single-eyed creature\n"+
  "that lives alone in the densest part of the forest.  He weighs up-\n"+
  "of 350 poinds and stands nearly 8 feet tall.  A single large, red\n"+
  "eye dominates the center of her forehead.  Her shaggy black hair\n"+
  "falls in a tangled mass about her head and shoulders.  Her skin tone\n"+
  "is a muddy yellow and and her voice is rough and sharp.  She is\n"+
  "dressed in a ragged animal hide and smells of equal parts dirt and\n"+
  "dung.\n");

set_level(19);
set_hp(475);
set_al(100 + random(200));
  if(!present("maquahuilt")) {
    move_object(clone_object("players/eurale/Glade/OBJ/maquahuilt.c"),
      this_object()); }
  if(!present("assegai")) {
    move_object(clone_object("players/eurale/Glade/OBJ/assegai.c"),
      this_object()); }
  init_command("wield maquahuilt");
set_wc(30);
set_ac(15);
set_aggressive(1);

set_a_chat_chance(15);
  load_a_chat("Shaala takes a mighty swing at you with her maquahuilt.\n");
  load_a_chat("You feel the sting of Shaala's assegai.\n");
  load_a_chat("Your attack bounces off of the cyclops' tough skin.\n");
  load_a_chat("The wicked club just misses your head.\n");
}
