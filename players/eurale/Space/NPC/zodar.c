#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("zodar");
set_alias("hulking zodar");
set_race("creature");
set_short(BOLD+"a hulking zodar"+NORM);
set_long(
	"  This zodar is an incredibly powerful biped.  All zodars are\n"+
	"identical, standing exactly 6 feet tall.  He resembles a smooth,\n"+
	"deep-black suit of obsidian plate armor.  This is actually\n"+
	"their exoskeleton, which is comprised of material that seems\n"+
	"very similar to a crystal shell.  He has no facial features\n"+
	"except for two small slits which some believe to be sensory\n"+
	"organs.\n");

set_level(20);
  set_hp(650 + random(200));
  set_al(-random(800));
  set_wc(30);
  set_ac(18);
  set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(8);
  load_chat("The zodar faces you and waits.....\n");
set_a_chat_chance(15);
  load_a_chat("\nThe zodar "+BOLD+"SMASHES"+NORM+" you with his fist....\n\n");
  load_a_chat("\nYou duck a mighty swing.....\n\n");

set_chance(10);
set_spell_dam(15 + random(20));

set_spell_mess1(
  "\nThe zodar "+BOLD+"PUMMELS"+NORM+" his opponent....\n\n");
set_spell_mess2(
  "\nThe zodar "+BOLD+"PUNCHES"+NORM+" you in the face.....\n"+
  "with his other hand he "+BOLD+"DRIVES HOME"+NORM+" a blow to your stomach...\n"+
  "and then a two-handed "+BOLD+"BACK BLOW"+NORM+" as you're doubled over..\n\n");

gold = clone_object("obj/money");
gold->set_money(3000 + random(1500));
move_object(gold,this_object());
}

monster_died() {
  move_object(clone_object("players/eurale/Space/OBJ/plate.c"),
    environment(this_object()));
return 0; }
