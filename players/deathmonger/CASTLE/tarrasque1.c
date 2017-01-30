
#include "std.h"
#undef EXTRA_RESET
#undef EXTRA_INIT
#define EXTRA_RESET extra_reset();
#define EXTRA_INIT extra_init();
object tarrasque, armor, helmet, shield;
object horn;

extra_reset() {
if (!tarrasque || !living(tarrasque)) {
      tarrasque = clone_object("players/deathmonger/MONSTERS/tarrasque");
      move_object(tarrasque, this_object());

      armor = clone_object("obj/armor");
      call_other(armor, "set_name", "Tarrasque Plate");
      call_other(armor, "set_short", "Tarrasque Plate, tougher than nails");
      call_other(armor, "set_long", "Clearly the best armor you can get.\n");
      call_other(armor, "set_weight", 3);
      call_other(armor, "set_ac", 4);
      call_other(armor, "set_value", 2000);
      call_other(armor, "set_alias", "plate");
      call_other(armor, "set_type", "armor");
      call_other(armor, "set_arm_light");
      transfer(armor, tarrasque);
      helmet = clone_object("obj/armor");
      call_other(helmet, "set_name", "Tarrasque Helmet");
      call_other(helmet, "set_alias", "helmet");
      call_other(helmet, "set_short", "Tarrasque Helmet");
      call_other(helmet, "set_weight", 1);
      call_other(helmet, "set_ac", 2);
/* Changed from ac1 to ac2, we need more ac2 helms -Jaraxle  */
      call_other(helmet, "set_value", 800);
      call_other(helmet, "set_type", "helmet");
      transfer(helmet, tarrasque);

      shield = clone_object("obj/armor");
      call_other(shield, "set_name", "shield");
      call_other(shield, "set_short", "Tarrasque Shield");
      call_other(shield, "set_weight", 1);
      call_other(shield, "set_ac", 1);
      call_other(shield, "set_value", 400);
      call_other(shield, "set_type", "shield");
      transfer(shield, tarrasque);
/* This directory no longer exists. -Feldegast 6-10-00
      horn = clone_object("players/deathmonger/ASSASSIN/questob2");
      move_object(horn, tarrasque);
*/
}
}

extra_init(){
     add_action("search","search");
}

search(){
     object mushroom;
     write("You found a delicate mushroom on the volcanic floor.\n");
     mushroom = clone_object("players/deathmonger/QUEST/shroom");
       move_object(mushroom, this_player());
        return 1;
}
TWO_EXIT("players/deathmonger/mid_volcano", "up",
         "players/deathmonger/UNDERDARK/tunnel1", "south",
         "A smoky room with an ash-covered floor.",
         "A smoky room with an ash-covered floor.\n",  1)


