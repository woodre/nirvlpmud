inherit "/obj/monster.c";
#include "/obj/ansi.h"
#define tpn this_player()->query_name()

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Ogre Mage");
  set_race("ogre");
  set_short(BOLD+RED+"An Ogre Mage"+NORM);
  set_long(
    "  This is one of the intelligent leaders of the Orges.\n"+
    "His enormous size and powerful magical nature make him\n"+
    "a formittable foe.\n");
  
  add_money(3500+random(3000));
  set_level(21);
  set_hp(500+random(150));
  set_al(-1000);
  set_ac(21+random(4));
  set_wc(32);
  set_aggressive(1);
  set_chance(25);
  set_spell_dam(35);
  set_spell_mess1(											      
  	"														FFF	   FFFFFFFFFFFF\n"+															 
  	"													 FF		FFFFFFFFFFFFFFFF\n"+											 
  	"													     FFFFFFFFFFFFFFFFFFFF\n"+										
    "The Ogre Mage casts a "+HIR+"F I R E B A L L!!!"+RED+" FFFFFFFFFFFFFFFFFFFFFFFFFFFF\n"+
    "														 FFFFFFFFFFFFFFFFFFFF\n"+
    "													 FF		FFFFFFFFFFFFFFFF\n"+
    "														FFF    FFFFFFFFFFFF"+NORM+"\n");
  set_spell_mess2(
    "The Ogre Mage casts an  "+HIC+"      I C E   S T O R M!!!"+NORM+"\n"+
    " \n"+
    "  "+HIB+"@"+NORM+"  *   "+HIB+"\#"+NORM+"  *   \#     \#    @   *   *  \#   "+HIB+"@ "+NORM+"   "+HIB+"*"+NORM+"   @   *   *   *   *\#\n"+
    "	  *		"+HIC+"*"+NORM+" *	    *   *   *   *	*	@	\#	*	*"+HIC+"*"+NORM+"	*	*	*	*\n"+
    "	*	"+HIC+"*"+NORM+"	*	"+HIB+"*"+NORM+"	*	*\#	*	\#	*	*"+HIB+"@"+NORM+"	\#	*		*\n"+
    " *   "+HIB+"*"+NORM+"   *      *    **    *"+HIC+"*"+NORM+" *  *  *   *   "+HIC+"*"+NORM+" * *  "+HIC+"*"+NORM+"    *   *\n"+
    " 	#		*		"+HIC+"*"+NORM+"	*	"+HIB+"*"+NORM+"	*	*	"+HIB+"@"+NORM+"	*	@	*	"+HIC+"*"+NORM+"  *\n"+
    " \n");   
}
