
/*
 * Prison room.
 * The players weapons/items are stored in the locker if they
 * triggered the trap in (under3.c). The key is on the
 * dragonman guard.
 */

#include "/players/molasar/rowan/room/exit.h"
#define CELL "/players/molasar/rowan/mtn/cell"

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

extra_reset() {
   object guard, locker, key;
   if(!present("dragonman")) {
     guard = clone_object("players/molasar/rowan/monsters/d_guard");
     key = clone_object("obj/treasure");
     key->set_id("key");
     key->set_alias("mol_locker_key");
     key->set_short("A small iron key");
     key->set_value(10);
     move_object(key, guard);
     move_object(guard, this_object());
     guard = clone_object("players/molasar/rowan/monsters/d_guard");
     move_object(guard, this_object());
   }
   if(!present("locker")) {
     locker = clone_object("players/molasar/rowan/obj/chest");
     locker->set_name("locker");
     locker->set_short("A large storage locker");
     locker->set_long("A sturdy locker constructed of heavy wood.\n");
     locker->set_key_id("mol_locker_key");
     locker->set_locked(1);
     move_object(locker, this_object());
   }
}

id(str) { return str == "gate" || str == "desk" || str == "chair"; }

short() { return "Main prison room"; }
   
long(str) {
   if(str == "desk" || str == "chair") {
     write("You find nothing particularly interesting about it.\n");
     return 1;
   }
   if(str == "gate") {
     if(CELL->query_locked()) {
       write("Although the gate itself seems sturdy enough, the lock\n");
       write("wouldn't be a challenge to the smallest thief.\n");
       write("If only you had something to pick it with.\n");
       return 1;
     }
     if(CELL->query_closed()) {
       write("The gate is closed, but appears to be unlocked.\n");
       return 1;
     }
     if(!CELL->query_closed()) {
       write("The gate is open.\n");
       return 1;
     }
   }
   write("You are in a main prison room.\n");
   write("A large locker against the southern wall dominates the room.\n");
   write("Next to it lies a small desk and chair.\n");
   write("     There is one obvious exit:  north and west\n");
}


init() {
   add_exit("west","/players/molasar/rowan/mtn/cell");
   add_exit("north","/players/molasar/rowan/mtn/phall");
   add_action("open","open");
   add_action("unlock","unlock");
   add_action("close","close");
}

move() {
  string verb;
  
  verb = query_verb();
  if(verb == "west") {
    if(CELL->query_closed()) {
      write("The cell gate is closed.\n");
      return 1;
    }
    this_player()->move_player("west#players/molasar/rowan/mtn/cell");
    return 1;
  }
  if(verb == "north") {
    this_player()->move_player("north#players/molasar/rowan/mtn/phall");
    return 1;
  }
}

unlock(str) {
   if(!str || str != "gate")
     return;
   write("You do not have the right key.\n");
   return 1;
}

open(str) {
   if(!str || str != "gate") 
     return;
   if(CELL->query_locked()) {
     write("You must unlock the gate first.\n");
     return 1;
   }
   if(!CELL->query_closed()) {
     write("The gate is not closed.\n");
     return 1;
   }
   if(this_player()->query_attrib("str") < random(30)) {
     write("You tug at the gate, but it refuses to budge.\n");
     say(capitalize(this_player()->query_name())+
                        " makes a futile attempt to open the gate.\n");
     return 1;
   }
   write("You grit your teeth and give a huge pull.\n");
   write("The gate opens!\n");
   say(capitalize(this_player()->query_name())+
                      " heaves the gate open.\n");
   CELL->set_closed(0);
   return 1;
}

close(str) {
   if(!str || str != "gate") 
     return;
   if(CELL->query_closed()) {
     write("The gate is already closed.\n");
     return 1;
   }
   if(this_player()->query_attrib("str") < random(30)) {
     write("You tug at the gate, but it refuses to budge.\n");
     say(capitalize(this_player()->query_name())+
                        " makes a futile attempt to close the gate.\n");
     return 1;
   }
   write("You grit your teeth and give a huge pull.\n");
   write("The gate closes!\n");
   say(capitalize(this_player()->query_name())+
                      " pushes the gate closed.\n");
   CELL->set_closed(1);
   return 1;
}

combine_lockers() {
   object invob, locker, next_invob, locker_invob, locker_next_invob;

   invob = first_inventory(this_object());
   while(invob) {
     next_invob = next_inventory(invob);
     if(locker && invob->query_key_id() == "mol_locker_key") {
       locker_invob = first_inventory(invob);
       while(locker_invob) {
         locker_next_invob = next_inventory(locker_invob);
         move_object(locker_invob, locker);
         locker_invob = locker_next_invob;
       }
       destruct(invob);
     }
     if(!locker && invob->query_key_id() == "mol_locker_key") 
       locker = invob;
     invob = next_invob;
   }
   return 1;
}




