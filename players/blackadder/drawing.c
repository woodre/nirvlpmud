

inherit "/players/blackadder/room";

reset(arg) {
   if (arg) return;
   
   set_light(1);
   short_desc = "Drawing Room";
   no_castle_flag = 0;
   long_desc = 
   "You have entered Blackadders drawing room.  Old bits and pieces of discarded\n"
   + "paper litter the floor.  A machine stands against the far wall with a sign\n"
   + "which reads:\n"
   + "                            Enigma Trump Maker\n"
   + " \n"
   + "                   To use type 'buy trump <name>'\n"
   + "                   where <name> is the name of the person to appear on the\n"
   + "                   face of the card.  Cards cost 500 coins each.\n";
   dest_dir = 
   ({
         "/players/blackadder/hall2", "east",
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
   add_action("buy","buy");
}


buy(str) {
   string what;
   string who;
   object trump;
   if (!str) {
      write("Buy what?\n");
      return 1;
   }
   if (sscanf(str,"%s %s",what,who) != 2) {
      write("buy what?\n");
      return 1;
   }
   if (what != "trump") {
      write("Did you want a trump or something?\n");
      return 1;
   }
   if (call_other(this_player(),"query_money",0) < 500) {
      write("You can't afford a trump!\n");
      return 1;
   }
   if (!find_player(who)) {
      write("That person is not in the MUD right now.\n");
      return 1;
   }
   trump = clone_object("/players/blackadder/trumps/gen_trump");
   call_other(trump,"set_pict",who);
   call_other(trump,"set_pict_desc","A very good likeness!\n");
   if (!call_other(this_player(),"add_weight",
            call_other(trump,"query_weight"))) {
      write("You can't carry that much!\n");
      return 1;
   }
   move_object(trump,this_player());
   call_other(this_player(),"add_money", -500);
   write("Ok.\n");
   return 1;
}

