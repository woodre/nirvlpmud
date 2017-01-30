
/*
 * A battle-axe is here for players that lose all their items in
 * the prison locker.
 */

#include "/players/molasar/rowan/room/exit.h"

object *visitors;

reset(arg) {
   if(!arg)
     set_light(0);
   visitors = ({ });
}

id(str) { return str == "bunk" || str == "bunks" ||
                 str == "locker" || str == "lockers"; }

short() { return "Guard Barracks"; }

long(str) {
   if(str == "bunk" || str == "bunks" || 
                                      str == "locker" || str == "lockers") {
     write("You search but find nothing of interest.\n");
     return 1;
   }
   write("You are in the guard's barracks.\n");
   write("Rows of bunks and lockers line the room making it difficult\n");
   write("to move around in.\n");
   write("     There is one obvious exit:  west\n");
}

init() {
   add_exit("west","/players/molasar/rowan/mtn/eroom1");
   if(this_player())
     check_for_axe();
}

move() {
  string verb;

  verb = query_verb();
  if(verb == "west") {
    this_player()->move_player("west#players/molasar/rowan/mtn/eroom1");
    return 1;
  }
}

check_for_axe() {
   object invob, axe, shield, armor;
   int no_give;

   if(member_array(this_player(), visitors) != -1)
     return 1;
   no_give = 0;
   invob = first_inventory(this_player());
   while(invob) {
     if(invob->weapon_class())
       no_give = 1;
     invob = next_inventory(invob);
   }
   if(no_give)
     return 1;
   visitors += ({ this_player() });
   axe = clone_object("players/sandman/paladin/obj/weapon");
   axe->set_name("battle axe");
   axe->set_weapon_type("axe");
   axe->set_short("A battle axe");
   axe->set_long("A crude but effective battle axe.\n");
   axe->set_class(14);
   axe->set_weight(2);
   axe->set_value(500);
   shield = clone_object("obj/armor");
   shield->set_type("shield");
   shield->set_id("shield");
   shield->set_ac(1);
   shield->set_short("A wooden shield");
   shield->set_value(100);
   shield->set_weight(2);
   armor = clone_object("obj/armor");
   armor->set_name("armor");
   armor->set_type("armor");
   armor->set_short("Leather armor");
   armor->set_long("Not something you'd buy, but better than nothing.\n");
   armor->set_ac(1);
   armor->set_value(150);
   armor->set_weight(1);
   move_object(armor, this_object());
   move_object(shield, this_object());
   move_object(axe, this_object());
   return 1;
}

