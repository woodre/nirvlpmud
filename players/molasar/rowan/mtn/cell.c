
/*
 * Cell room.
 * This is where players are brought if they spring the trap
 * in (under3.c).  To leave, they must find the wire under the
 * bunk and pick the gate.
 */

#include "/players/molasar/rowan/room/exit.h"

int locked, closed, found;

reset(arg) {
   if(!arg)
     set_light(1);
   closed = 1;
   locked = 1;
   found = 0;
}

id(str) { return str == "gate" || str == "cot"; }

query_closed() { return closed; }
set_closed(c) { closed = c; }

query_locked() { return locked; }
set_locked(l) { locked = l; }

short() { return "A prison cell"; }
   
long(str) {
   if(str == "gate") {
     if(locked) {
       write("Although the gate itself seems sturdy enough, the lock\n");
       write("wouldn't be a challenge to the smallest thief.\n");
       write("If only you had something to pick it with.\n");
       return 1;
     }
     if(closed) {
       write("The gate is closed, but appears to be unlocked.\n");
       return 1;
     }
     if(!closed) {
       write("The gate is open.\n");
       return 1;
     }
   }
   if(str == "cot") {
     if(!found) {
       object wire;
       write("After doing a quick search of the cot the only thing\n");
       write("you find is a small wire which has rusted off from\n");
       write("the frame.\n");
       wire = clone_object("obj/treasure");
       wire->set_id("wire");
       wire->set_short("A small rusted wire");
       wire->set_long("A piece of metal torn from an old cot.\n");
       wire->set_value(1);
       move_object(wire, this_player());
       found = 1;
       return 1;
     }
     write("An old smelly cot.  Certainly not something you'd ");
     write("wanna sleep on.\n");
     return 1;
   }
   write("You are in a prison cell.\n");
   write("It is really nothing more than a cubby carved out of the\n");
   write("rock. A strong iron gate serves as a barricade.\n");
   write("There is a single cot in the corner of the room.\n");
   write("     There is one obvious exit:  east\n");
}


init() {
   add_exit("east","/players/molasar/rowan/mtn/prison");
   add_action("open","open");
   add_action("pick","pick");
   add_action("close","close");
   add_action("no_go","unlock");
   add_action("no_go","lock");
}

no_go() {
   write("A key will not work from the inside.\n");
   return 1;
}

move() {
  string verb;
  
  verb = query_verb();
  if(verb == "east") {
    if(closed) {
      write("The cell gate is closed.\n");
      return 1;
    }
    this_player()->move_player("east#players/molasar/rowan/mtn/prison");
    return 1;
  }
}

pick(str) {
   string item;
   object itemob;

   if(!str) {
     write("Pick what with what?\n");
     return 1;
   }
   if(sscanf(str, "gate with %s", item) != 1 &&
                                  sscanf(str, "lock with %s", item) != 1) {
     write("Pick what with what?\n");
     return 1;
   }
   itemob = present(item, this_player());
   if(!itemob) {
     write("You do not have a "+item+".\n");
     return 1;
   }
   if(!itemob->id("wire")) {
     write("You can't pick the lock with that!\n");
     return 1;
   }
   if(!locked) {
     write("The gate is not locked.\n");
     return 1;
   }
   if(this_player()->query_attrib("luc") < random(30)) {
     write("You fumble with the lock but can't get it open.\n");
     say(capitalize(this_player()->query_name())+
                        " fails to pick the lock on the gate.\n");
     return 1;
   }
   write("You hear a faint click.\n");
   say(capitalize(this_player()->query_name())+
                      " picks the lock on the gate.\n");
   locked = 0;
   return 1;
}

open(str) {

   if(!str || str != "gate") 
     return;
   if(locked) {
     write("You must unlock the gate first.\n");
     return 1;
   }
   if(!closed) {
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
   closed = 0;
   return 1;
}

close(str) {
   if(!str || str != "gate") 
     return;
   if(closed) {
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
   closed = 1;
   return 1;
}


