#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

     set_name("lizard");
     set_alias("lizard");
     set_alt_name("chameleon");
     set_race("lizard");
     set_gender("male");
     set_short(HIG+"Chameleon Lizard"+NORM);
     set_long(
       "Changing his color as he moves from resting spot to resting spot.  \n"+
       "His best protection is that he can blend into his surroundings. \n"+
       "Silent in his movement, he scurries alongside the towering wall, \n"+
       "searching for nice dark cracks to hide in.\n");

     set_level(11);
     set_hp(165);
     set_al(0);
     set_wc(15);
     set_ac(9);
     set_aggressive(0);

     set_chat_chance(5);
       load_chat("The "+HIG+"chameleon"+NORM+" spots you and sits perfectly still.\n");
     set_a_chat_chance(35);
       load_a_chat("The "+HIG+"chameleon "+NORM+"hisses and spits venom at you. \n");
       load_a_chat("Your eyes "+HIG+" B U R N "+NORM+" as "+HIG+"V E N O M "+NORM+"flows.\n");
       load_a_chat("You stagger "+HIG+"B L I N D L Y "+NORM+"trying to avoid the chameleon.\n");

     set_chance(11);
     set_spell_dam(10 + random(6));
     set_spell_mess1(
	"\n The "+HIG+"Chameleon "+NORM+" spits at "+this_player()->query_name()+"..... \n\n"+
	"      "+this_player()->query_name()+" jerks back.....\n\n"+
	HIG+"          V E N O M  "+NORM+"blinds "+this_player()->query_name()+"...\n\n"+
	"             "+this_player()->query_name()+" screams in "+HIG+"P A I N"+NORM+".....\n\n");
     set_spell_mess2(
	"\n The "+HIG+"Chameleon"+NORM+" hisses and spits at you..... \n\n"+
	"      Your eyes begin to burn.....\n\n"+
	HIG+"         V E N O M   "+NORM+"fills your eyes..\n\n"+
	"             You hands rush to your "+HIG+" B U R N I N G "+NORM+"eyes.....\n\n");

     set_dead_ob(this_object());
}

monster_died() {
    move_object(clone_object("players/dreamspeakr/mesa/OBJ/skin.c"), environment(this_object()));
    tell_room(environment(this_object()),
	"OHHH.....There appears to be a valuable skin left from the chameleon. \n");
    return 0; 
    }