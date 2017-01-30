/* waitingroom.c -- Nanny version, with an exit to the surgeon's room! */

#include "std.h"

object obj_1, obj_2;    /* doors */

#undef EXTRA_RESET
#define EXTRA_RESET  extra_reset(arg);

extra_reset(arg) {
   if(!arg) {
      /* First reset */
      
      /* Commenting this out, macro doesn't work. Need to set the doors up
      Manually -- Rumplemintz
      MAKE_DOORS("players/padrone/inside/waitingroom", "south",
         "players/padrone/tower/tower1", "north",
         "crystal", "towerdoor",
         "This is the door leading from the waiting room to Padrone's private tower.\n" +
         "It is a thick and solid wooden door, and it has a sign saying 'PRIVATE'.\n",
         1, 1, 1)
      */
      
      if(!present("door")) {      /* Added present check - keep 1 door only */
         obj_1 = clone_object("obj/door");
         obj_1->set_door_room("players/padrone/inside/waitingroom");
         obj_1->set_dir("south");
         obj_1->set_type("crystal");
         obj_1->set_code("towerdoor");
         obj_1->set_door_long(""+
            "This is the door leading from the waiting room to Padrone's private tower.\n"+
            "It is a thick and solid wooden door, and it has a sign saying 'PRIVATE'.\n");
         obj_1->set_locked(1);
         obj_1->set_closed(1);
         obj_1->set_can_lock(1);
         
         obj_2 = clone_object("obj/door");
         obj_2->set_door_room("players/padrone/tower/tower1");
         obj_2->set_dir("north");
         obj_2->set_type("crystal");
         obj_2->set_code("towerdoor");
         obj_2->set_door_long(""+
            "This is the door leading from the waiting room to Padrone's private tower.\n"+
            "It is a thick and solid wooden door, and it has a sign saying 'PRIVATE'.\n");
         
         obj_1->set_door(obj_2);
         obj_2->set_door(obj_1);
         move_object(obj_1, this_object());
         move_object(obj_2, "players/padrone/tower/tower1");
         
         obj_1->set_both_status();
      }
      return;
   }
   
   obj_1->set_closed(1);
   obj_1->set_locked(1);
   obj_1->set_both_status();
}

TWO_EXIT("players/padrone/inside/main_hall", "west",
   "players/padrone/inside/cons", "east",
   "Waiting room",
   "This is the waiting room, where people who want help or advice\n" +
   "from the mighty Wizard sit and wait until they are admitted\n" +
   "to the consultation room to the east.\n" +
   "Through the door to the west you can see the main hall,\n" +
   "but there is also a small door to the south.\n" +
   "There is a sign on that door saying 'PRIVATE!'.\n", 1)

