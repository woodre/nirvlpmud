inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("amodezius");
   set_alias("amodezius");
   set_short("Amodezius, the greater devil");
   set_level(13);
   set_race("devil");
   set_hp(195);
   set_wc(17);
   set_ac(10);
   set_long(
"     Amodezius stands nearly 17 feet tall. He has three large blazing\n"+
"horns upon his head, a set of very mean looking claws, and a huge spiked\n"+
"tail. Billows of fire erupt from his skin. His eyes are those of a\n"+
"snake, with red slits upon a black background. His bumpy skin is dark\n"+
"red. He talks as if billions of souls are crying for mercy.\n");
   set_chat_chance(10);
   load_chat("Amodezius says: The Lich has told me you would come.\n");
   load_chat("Amodezius says: Demosater has agreed to let me be summoned by the Lich.\n");
   load_chat("Amodezius says: I shall lead Demosater's army to victory.\n");
   load_chat("Amodezius looks disdainfully upon you.\n");
   load_chat("Amodezius says: If you try and stop me, I shall easily crush you.\n");
   load_chat("Amodezius laughs in a deep resounding voice.\n");
   load_chat("Amodezius says: And the lizards all fell for the Lich's plan.\n");
}
