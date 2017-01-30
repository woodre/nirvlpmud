 inherit "room/room";
 int i;
   reset(arg){
     if(!present("specter")) {
       for(i=0;i<4;i++) {
    move_object(clone_object("players/arrina/monsters/specter"),this_object());
       }
    }
    if(arg) return;
    set_light(0);
    short_desc=("Storage Room");
    long_desc=
    "This small room off the main entry appears to have been used for\n"
 +  "storage at some point in time.  Boxes litter the floor, and clothing\n"
 +  "is scattered around randomly.  It appears that nobody has had need of\n"
 +  "anything in here for a very long time.  It is so dark in here that \n"
 +  "it would be easy to simply hide out in here.\n";
    items=
   ({
     "boxes","These boxes may have at one time contained treasure of \n"
 +             "great worth, but are empty now",
      "clothing","The clothing is yellowed with age, and although once \n"
 +             "fine, it is now worthless",
    });
    dest_dir=
    ({
      "players/arrina/newbie/newbie1","west",
      });
    }
  init()  {
  ::init();
   add_action("search_room","search");
         }
  search_room() {
   write("You search through the room but find nothing of value.\n");
 say (this_player()->query_name() +" searches the room but finds nothing.\n");
   return 1;         }
