#include <ansi.h>
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object("/players/daranath/qualtor/newstuff/junk/dress2.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/boots.c"),this_object());

     set_name("Chandra the shopkeeper");
     set_short("Chandra the store owner");
     set_alias("chandra");
     set_alt_name("shopkeeper");
     set_race("human");
     set_gender("female");
     set_long("Chandra has worked hard to help her store make a profit here within the\n"+
              "ruins of Qual'tor. It has not been an easy task, and the weathered look\n"+
              "on her face reveals this. Her long, curly hair hangs tangled, evidence\n"+
               "of her time spent here.\n"+
              "For 100 coins, You can <"+HIW+"ask"+NORM+"> her about her wares for sale.\n");
     set_level(12);

     init_command("wear dress");
     init_command("wear boots");

     set_ac(9);
     set_wc(15 + random(4));
     set_hp(180 + random(20));
     set_al(700);
     set_aggressive(0);
     set_chat_chance(4);
     set_a_chat_chance(25);
     load_chat("Chandra greets you as you browse through her store.\n");
     load_chat("Chandra puts the final stich into another piece of clothing.\n");
     load_chat("Chandra folds some clothes then stacks them on a shelf.\n");
     load_chat("Chandra writes on a small piece of paper as she takes inventory.\n");
     load_chat("Chandra puts some items back on the shelf.\n");
     load_a_chat("Chandra screams for the local guard!\n");

   }
}
