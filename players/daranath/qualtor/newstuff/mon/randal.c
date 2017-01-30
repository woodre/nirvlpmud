#include <ansi.h>
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object("/players/daranath/qualtor/newstuff/junk/labboots.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/labcoat.c"),this_object());

set_name("Randal the shopkeeper");
set_short("Randal the alchemist");
set_alias("randal");
set_alt_name("shopkeeper");
set_race("human");
set_gender("male");
set_long("A scrawny, twitchy man by nature, Randal is the last person you would\n"+
         "want working in an alchemy workshop. After getting fired from or\n"+
         "simply destroying several jobs, he set up this store to do\n"+
         "something as simple as selling heals.\n"+
         "For 100 coins, You can <"+HIW+"ask"+NORM+"> him for advice about his wares.\n");
set_level(12);

     init_command("wear coat");
     init_command("wear boots");

set_ac(9);
set_wc(15 + random(4));
set_hp(180 + random(20));
set_al(700);
set_aggressive(0);
set_chat_chance(4);
set_a_chat_chance(25);
load_chat("Randal mixes something behind the counter.\n");
load_chat("Randal searches the counter for something.\n");
load_chat("Randal mixes another healing potion or salve.\n");
load_chat("Randal exhales deeply, then smiles sheepishly when he realizes\n"+
               "that you are watching him.\n");
     load_chat("Randal put a large jar of slime behind the counter.\n");
     load_chat("Randal looks rather confused, again.\n");
     load_a_chat("Randal screams loudly, calling for the guard.\n");
     load_a_chat("Randal hits you with a weak blow, doing no damage.\n");
     load_a_chat("Randal shouts: Take it! Take it all!!!.\n");
     load_a_chat("Randal shouts: Just leave me alone!!!\n");

   }
}
