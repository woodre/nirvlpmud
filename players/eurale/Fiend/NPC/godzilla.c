#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("godzilla");
set_race("creature");
set_short("Godzilla");
set_long(
	"  This 400 foot tall reptile comes from the age of dinosaurs.\n"+
	"He walks upright like a Tyrannosaurus rex and he has sharp\n"+
	"scales on his back like a Stegosaurus.  This Japanese monster\n"+
	"is the most popular movie monster of all time.  He has appeared\n"+
	"in more than a dozen films as both a hero and a villian.\n");

set_level(20);
set_hp(700);
set_al(0);
set_wc(30);
set_ac(15);
set_aggressive(1);
set_dead_ob(this_object());

set_chance(10);
set_spell_dam(55);

set_spell_mess1(
  "\n\nGodzilla let's out a smokey atomic blast....\n\n"+
  BOLD+
  "     >>>>>>>>>>>>>>>\n"+
  ">>>>  ATOMIC BLAST  >>>>>>>>>>>>>>>  *\n"+
  "     >>>>>>>>>>>>>>>"+NORM+"\n\n");
set_spell_mess2(
  "\n\nGodzilla singes you with an atomic blast...\n\n"+
  BOLD+
  "      >>>>>>>>>>>>>>>>>>>>\n"+
  ">>>>> ATOMIC BLAST  >>>>>>>>>>>>>>>>>>>  *\n"+
  "      >>>>>>>>>>>>>>>>>>>>"+NORM+"\n\n");

}

monster_died() {
tell_room(environment(this_object()),
  "Godzilla gives one last UUURRRAAAAAAGGGGGGGHHHHHHH! and crashes \n"+
  "to the ground in a heap.\n\n");
  move_object(clone_object("players/eurale/Fiend/OBJ/godzilla_plate"),
    environment(this_object()));
return 0; }
