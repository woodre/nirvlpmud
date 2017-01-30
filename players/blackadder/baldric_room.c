

inherit "/players/blackadder/room";

object turnip;
int turnip_vis;

reset(arg) {
   if (!turnip || !present(turnip)) {
      turnip = clone_object("/obj/treasure");
      call_other(turnip,"set_name","turnip");
      call_other(turnip,"set_alias","turnip");
      call_other(turnip,"set_short","A turnip shaped like a thinge");
      call_other(turnip,"set_long","A turnip shaped like a thinge!!\n");
      call_other(turnip,"set_value",300);
      turnip_vis = 0;
      call_other(turnip,"set_weight",1);
   }
   if (arg) return;
   
   set_light(1);
   short_desc = "Baldric's room";
   no_castle_flag = 0;
   long_desc = 
   "You have entered Baldric's bedroom.  This room is a mess!  Dirty laundry\n"
   + "and clutter lie scattered throughout the room.  How does Baldric ever\n"
   + "find anything in this pig sti?\n";
   dest_dir = 
   ({
         "/players/blackadder/hall2", "west",
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

search(str) {
   if (str == "corpse")
      return 0;
   if (!turnip || turnip_vis == 1) {
      write("You search through the debris and find nothing worthwhile.\n");
      return 1;
   }
   write("You found a turnip!!!\n");
   move_object(turnip,this_object());
   turnip_vis = 1;
   return 1;
}
