#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object mace;
object robe;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("chelaris");
set_alt_name("elf");
set_race("elf");
set_short(HIW+"Chelaris"+NORM+", the elven high maiden");
set_long(
  "  You stand before Chelaris, the one true love of Yeroc.  Her long\n"+
  "strawberry blond hair, reaches gracefully to the middle of her back.\n"+
  "She looks upon you with sorrow through her soft green eyes.  Along \n"+
  "the sides of her short narrow nose tear stains can be seen.  At the\n"+
  "end of her back half of a ying yang can be seen tattooed.  She left\n"+
  "the safety of the village in search of the only person that truly \n"+
  "understands her life, Yeroc.  Against all odds and others' opinions,\n"+
  "she entered the forest of despair in hopes that one day she could \n"+
  "reunite with him.\n");
 
set_level(23);
set_hp(800);
set_al(777);
add_money(3000 + random(2000))
set_aggressive(0);
set_chat_chance(3);
  load_chat("A small tear traces down Chelaris's face.\n");
set_a_chat_chance(2);
  load_a_chat("Chelaris wanders around the tree preoccupied.\n");
  load_a_chat("Chelaris says: 'I know he is out there somewhere and I will find him.'\n");
  load_a_chat("The elven maiden weeps softly.\n");

mace = clone_object("/players/catacomb/MF/items/Polaris.c"); 
move_object(mace, this_object());
command("wield polaris", this_object());
set_wc(40);

robe = clone_object("/players/catacomb/MF/items/elderrobe.c");
move_object(robe, this_object());
command("wear robe", this_object());
set ac(25);
}
 
heart_beat()
{
  int chance;
  chance = random(50);

    ::heart_beat();
  if(!environment())
    return;
  if(!ATTACKED)
    return;
  if (chance > 40)
  {
     write("\n     Chelaris calls forth a raging whirlwind\n"+
             "    you reel in pain as the wind "+RED+"FILLETS"+NORM+" your skin.\n\n");
     say("\n    A raging whirlwind filets Chelaris's attacker.\n\n");
     hit_player(40 + random(20));
     return 1;
   }
  if ((chance < 30) && (chance > 20))
  {
    write("\n     Chelaris releases her sorrow in a vicious onslaught against your mind\n");
    write(  "            You fight the overwhelming mind assault to no avail.\n");
    write(BLU+"                 You fall to the ground in agony.\n\n"+NORM);
    say(ATTACKED->query_name()+" falls to the ground in agonizing pain.\n");
    hit_player(40 + random (30));
     return 1;
  }
  if (chance < 15)
  {
    write("\n     Chelaris chants an incantation and is bathed in a healing light.\n");
    say("\n    Chelaris chants quietly and a healing light engulfs her.\n");
    heal_self(5 + random (10));
    return 1;
  }
}   