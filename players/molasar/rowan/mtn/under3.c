
/*
 * Trap room.
 * The lever must be in the 'up' position in (under1.c) to 
 * prevent springing the trap.
 * If sprung, players are transported to (cell.c) and
 * imprisoned.
 */

#include "/players/molasar/rowan/room/exit.h"
#define TELL(x) tell_room(this_object(), x);

reset(arg) {
   if(!arg)
     set_light(0);
}

short() { return "A passage underneath the mountain"; }
   
long() {
   write("You are in a passage underneath the mountain.\n");
   write("     There are two obvious exits:  south and east\n");
}


init() {
   add_exit("south","/players/molasar/rowan/mtn/under4");
   add_exit("east","/players/molasar/rowan/mtn/under2");
}

move() {
  string verb;
  
  verb = query_verb();
  if(verb == "south") {
    if("/players/molasar/rowan/mtn/under1"->query_down()) {
      write("As you move to the south you hear a sharp click.\n");
      say(capitalize(this_player()->query_name())+" moves to the "+
                         "south and sets off a trap.\n");
      TELL("The floor collapses beneath you!\n");
      move_to_cell();
      return 1;
    }
    this_player()->move_player("south#players/molasar/rowan/mtn/under4");
    return 1;
  }
  if(verb == "east") {
    this_player()->move_player("east#players/molasar/rowan/mtn/under2");
    return 1;
  }
}

move_to_cell() {
   object invob, next_invob, player_invob, player_next_invob, locker;

   locker = clone_object("players/molasar/rowan/obj/chest");
   locker->set_name("locker");
   locker->set_short("A large storage locker");
   locker->set_long("A sturdy locker constructed of heavy wood.\n");
   locker->set_key_id("mol_locker_key");
   locker->set_locked(1);
   
   TELL("\n");
   TELL("After a moments of unconciousness you awaken to find a hideous\n");
   TELL("reptilian monster staring at you.  It seems to grin\n");
   TELL("sarcastically at you.\n");
   TELL("The Dragonman says:  Night night.\n");
   TELL("Then precedes to hit you over the head.\n");
   TELL("You awaken later in an unfamiliar room.\n");
   invob = first_inventory(this_object());
   while(invob) {
     next_invob = next_inventory(invob);
     if(query_ip_number(invob)) {
       player_invob = first_inventory(invob);
       while(player_invob) {
         player_next_invob = next_inventory(player_invob);
         if(!player_invob->drop()) {
           invob->add_weight(-player_invob->query_weight());
           move_object(player_invob, locker);
         }
         player_invob = player_next_invob;
       }
     }
     move_object(invob, "/players/molasar/rowan/mtn/cell");
     invob = next_invob;
   }
   move_object(locker, "/players/molasar/rowan/mtn/prison");
   call_other("/players/molasar/rowan/mtn/prison","combine_lockers");
   call_other("/players/molasar/rowan/mtn/cell","reset",1);
   call_other("/players/molasar/rowan/mtn/prison","reset",1);
   return 1;
}

