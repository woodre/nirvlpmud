#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

     set_name("scorpion");
     set_alias("scorpion");
     set_race("arachnid");
     set_gender("male");
     set_short(RED+"Deadly Scorpion"+NORM);
     set_long(
       "Perching as if ready to strike you at any moment, he watches your \n"+
       "every move.  Dark red in color, having an elongated, lobster like \n"+
       "body and a segmented tail bearing a venomous sting.\n");

     set_level(10);
     set_hp(150);
     set_al(0);
     set_wc(14);
     set_ac(8);
     set_aggressive(0);

     set_chat_chance(5);
       load_chat("The "+RED+"scorpion "+NORM+"watches your every move.\n");
     set_a_chat_chance(35);
       load_a_chat("The scorpion "+RED+"S T R I K E S "+NORM+"at you with his tail.\n");
       load_a_chat("You feel very "+RED+"S I C K"+NORM+" as the "+RED+"V E N O M "+NORM+"flows in your veins.\n");
       load_a_chat("Your head "+RED+"S W I M S"+NORM+" from the poison.\n");

     set_dead_ob(this_object());

     set_chance(11);
     set_spell_dam(10 + random(12));
     set_spell_mess1(
	"\n         The "+RED+"Scorpion"+NORM+" jerks quickly and strikes..... \n\n"+
	"  "+this_player()->query_name()+" jerks back in pain.....\n\n"+
	RED+"         V E N O M  "+NORM+"flows thru "+this_player()->query_name()+"'s veins..\n\n"+
	" "+this_player()->query_name()+" begins to look very "+RED+"SICK"+NORM+".....\n\n");
     set_spell_mess2(
	"\n         The "+RED+"Scorpion"+NORM+" strikes at you with his tail..... \n\n"+
	"    Your skin begins to burn.....\n\n"+
	RED+"         V E N O M   "+NORM+"flows through your veins..\n\n"+
	"    You begin to feel very "+RED+"DIZZY"+NORM+".....\n\n");
}

monster_died() {
    move_object(clone_object("players/dreamspeakr/mesa/OBJ/tail.c"), environment(this_object()));
    tell_room(environment(this_object()),
	"The scorpion's tail breaks off and falls to the ground. \n");
    return 0; 
    }