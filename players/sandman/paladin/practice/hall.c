
/*
 * MAIN HALL TO PRACTICE ROOMS
 */

realm() { return "NT"; }

reset(arg) {
   if(!arg)
     set_light(1);
}

init() {
   add_action("east","east");
   add_action("south","south");
   add_action("west","west");
}

east() {
   if(occupied_room("/players/sandman/paladin/practice/room1"))
     return 1;
   if(deny_entry())
     return 1;
   this_player()->move_player("east#players/sandman/paladin/practice/room1");
   return 1;
}

west() {
   if(occupied_room("/players/sandman/paladin/practice/room2"))
     return 1;
   if(deny_entry())
     return 1;
   this_player()->move_player("west#players/sandman/paladin/practice/room2");
   return 1;
}

south() {
   this_player()->move_player("south#players/sandman/paladin/hall3");
   return 1;
}

short() { return "Practice hall"; }

long() {
   write("You are in the practice hall of the Paladins.\n");
   write("Practice rooms lie to the east and west. They allow you to\n"); 
   write("test your new abilities and weapons. You cannot be killed in\n"); 
   write("the practice rooms.\n");
   write("East practice room:\t");
   if(!occupied_room("/players/sandman/paladin/practice/room1")) 
     write("[available]\n");
   write("West practice room:\t");
   if(!occupied_room("/players/sandman/paladin/practice/room2")) 
     write("[available]\n");
   write("    There are three obvious exits:  south, east, and west\n");
}

occupied_room(room) {
   object invob, deny;

   deny = 0;
   invob = first_inventory(room);
   while(invob) {
     if(query_ip_number(invob))
       deny = 1;
     invob = next_inventory(invob);
   }
   if(deny) {
     write("That practice room is occupied.\n");
     return 1;
   } else
     return 0;
}

deny_entry() {
   int hp, mhp;

   hp = this_player()->query_hp();
   mhp = this_player()->query_mhp();
   if(hp < ((4*mhp)/5)) {
     write("You must heal yourself more before you can enter.\n");
     return 1;
   }
   return 0;
}


