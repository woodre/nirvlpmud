inherit "/obj/monster";
#include "/obj/ansi.h"
#define ATN (this_object()->query_attack())
object Brdaxe;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("barbarian");
set_alt_name("warrior");
set_race("human");
set_short("A forest barbarian");
set_long("  A mammoth of a man, standing almost 6 feet tall.  His\n"+
  "face has scars from his many battles.  A tattoo of a snake wraps\n"+
  "around his eye and continues on over his forehead, a symbol of\n"+
  "his status within the tribe.\n");
 
set_level(16);
set_hp(300);
set_al(100);
set_ac(13);
set_aggressive(0);
set_chat_chance(10);
  load_chat("The barbarian sits calmly sharpening his axe.\n");
  load_a_chat("The barbarian warns you of the impending doom\n"+
   		  "of the forest.\n");
set_chance(10);
set_spell_dam(20);
set_spell_mess1(
  "The barbarian"+RED+" SCREAMS "+NORM+"out a warcry to his god.\n"+
  "Bringing down his axe, he takes a chunk of flesh from "+ATN+"'s arm.\n");
set_spell_mess2(
  "The barbarian"+RED+" SCREAMS "+NORM+"out a warcry to his god.\n"+
  "Bringing down his axe, he takes a chunk of flesh from your arm.\n");

Brdaxe = clone_object("/players/catacomb/barbtribe/Rbrkr.c"); 
move_object(Brdaxe, this_object());
command("wield axe", this_object());
set_wc(22);
}
