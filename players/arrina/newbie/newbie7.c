 inherit "room/room";
 int i;
   reset(arg){
     if(!present("wraith")) {
       for(i=0;i<4;i++) {
    move_object(clone_object("players/arrina/monsters/dkwraith"),this_object());
       }
    }
    if(arg) return;
    set_light(0);
    short_desc=("Guard's Quarters");
    long_desc=
    "This dismal room appears to have once been the quarters of the castle\n"
 +  "guards.  There are racks on the walls, and several cots are scattered\n"
 +  "around the room.  Dust clings to everything, and this wall, like others\n"
 +  "appears to have at one time held a window, now blocked over.  It seems\n"
 +  "as if no light has entered here for years, and the air is stale.\n";
    items=
   ({
     "racks","The racks look like they may have held armor at one time,\n"
 +             "and there are a few which may have held weapons",
      "cots","The cots are battered and the mattresses on them are no\n"
 +             "longer fit to sleep on.",
    });
    dest_dir=
    ({
      "players/arrina/newbie/newbie5","south",
      "players/arrina/newbie/newbie8","west",
      });
 }
  init()  {
  ::init();
   add_action("search_room","search");
  add_action("go_in","in");
         }
  search_room() {
   write("You search the room and notice a small hidden tunnel.\n"
 +       "You could go 'in' to see where it takes you\n");
 say (this_player()->query_name() +" searches the room.\n");
   return 1;         }
  go_in() {
  write("You enter the dark tunnel...where will it take you?\n");
 call_other(this_player(),"move_player","in#players/arrina/newbie/newbie1.c");

 return 1;  }
