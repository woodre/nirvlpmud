#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object book;
object scepter;
object robe;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("priest");
set_alt_name("elf");
set_race("elf");
set_short("A priest of the Shamot");
set_long(
  "  This elf is one of the elder of the tribe.  He has lived many\n"+
  "more centuries than you can fathom.  Even after so many years\n"+
  "this elf doesn't look to have aged a bit.  There are virtually\n"+
  "no marks to tell of the elf's true age.\n");
 
set_level(18);
set_hp(400);
/* set_hp_bonus();         7.5 hp per round,  happening 20% of the time, for  rounds*/ 
set_al(1000);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(3);
  load_chat("The priest chant:  Nadroj infactuas razosh.\n");
set_a_chat_chance(1);
  load_a_chat("The priest tells you: Yeroc is a disgrace to the Shamot.\n");
  load_a_chat("The priest kneels and prays to Silvanus.\n");
  load_a_chat("The priest says: Bless you my child.\n");
  load_a_chat("The priest hums an ancient hymn.\n");
}
book = clone_object("/players/catacomb/MF/items/book1.c"); 
move_object(book, this_object());

scepter = clone_object("/players/catacomb/MF/items/scepter.c");
move_object(scepter, this_object());
command("wield scepter", this_object());
set_wc(26); 

robe = clone_object("/players/catacomb/MF/items/robes.c"); 
move_object(robe, this_object());
command("wear robes", this_object());
set_ac(15);
}   

heart_beat()
{
  int HEALCHANCE;
  int HEALAMT;
  HEALCHANCE = random(50);
  HEALAMT = random (15);

    ::heart_beat();
  if(!environment())
    return;
  if(!ATTACKED)
    return;
  if (heal > 40)
  {
     write("\n     The priest is engulfed in "+WHT+"Holy Light"+NORM+"..\n"+
             "         You watch as his wounds disappear.\n\n");
     say("\n    The priest is bathed in Holy Light.\n\n");
     heal_self(HEALAMT);
     return 1;
   }
  else
     return 1;
}