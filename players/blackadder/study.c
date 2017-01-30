

inherit "/players/blackadder/room";
object desk;
object trump;
reset(arg) {
if (!trump || !present(trump)) {
      trump = clone_object("/players/blackadder/trumps/tub");
      move_object(trump,this_object());
   }
   if (!arg) {
      set_light(1);
      move_object(clone_object("/players/blackadder/chair"),this_object());
      move_object(clone_object("/players/blackadder/couch"),this_object());
      desk = clone_object("/players/blackadder/desk");
      move_object(desk,this_object());
      move_object(clone_object("/players/blackadder/book"),this_object());
      short_desc = "study";
      no_castle_flag = 0;
      long_desc = 
      "This is Lord Blackadders study.  He comes here from time to time for rest\n"
      + "and relaxation and to peruse great works of literature (or maybe a trashy\n"
      + "novel -- whatever he's in the mood for).  The shelves are well stocked with\n"
      + "books and charts.  Maps adorn the walls and a giant tapestry is suspended\n"
      + "from the ceiling.  An oak desk stands at the far end of the room and a \n"
      + "leather couch rests in the near corner.\n";
      dest_dir = 
      ({
            "/players/blackadder/entrance", "east",
       });
   }
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
room_is_modified() {
   return 1;
}

/*
make your additions below this comment, do NOT remove this comment
--END-ROOM-MAKER-CODE--
*/

