

inherit "/players/blackadder/room";

reset(arg) {
   if (arg) return;
   
   set_light(1);
   short_desc = "bathroom";
   no_castle_flag = 0;
   long_desc = 
   "This is Blackadders bathroom.\n"
   + "A gold and jewel encrusted toilet dominates this room.\n"
   + "A sign on the wall reads:\n"
   + "    'No man is an island, but when you piss your a nation!'\n";
   dest_dir = 
   ({
         "/players/blackadder/hall1", "east",
    });
}

query_light() {
   return 1;
}
query_room_maker() {
   return 101;
}

/*
remove the comments around the "room is modified()" code
below to prevent changes you have done to this room to
to be lost by using the room maker
*/
/*
room_is_modified() {
   return 1;
}
*/

/*
make your additions below this comment, do NOT remove this comment
--END-ROOM-MAKER-CODE--
*/

add_init() {
   add_action("piss","piss");
   add_action("shit","shit");
}

piss() {
   write("You send a wonderful golden shower into the toilet!\n");
   write("The toilet flushes and swirls.  You feel relief.\n");
   return 1;
}

shit() {
   write("You strain and strain and eventually drop a load into the toilet.\n");
   write("The toilet flushes and swirls.  Lysol sprays overhead.\n");
   return 1;
}
