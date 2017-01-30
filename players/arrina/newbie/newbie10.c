 inherit "room/room";
int cups_taken;   /* a global variable, so it holds its value */
 reset(arg) {
     set_light(0);
    short_desc=("Barracks Kitchen");
    long_desc=
    "This looks like it used to be the kitchen for the guards.  It has\n"
 +  "been stripped nearly bare, except for an old stove and sink.  The\n"
 +  "atmosphere here is not such that you feel you would like to eat\n"
 +  "much of the food that had been prepared here anyway, but there are\n"
 +  "a few eating utensils that have been dropped on the floor.\n";
     items=
   ({
     "floor","There is something shiny on the floor over in the \n"
 +             "corner, perhaps you should 'search' a bit",
      "sink","The sink has remnants of food particles from long ago,\n"
 +             "and it appears nothing has been washed in years",
      "stove","The stove is an old, wood-burning stove, and like all\n"
 +             "the other things, seems to not have been used in ages",
      });
    dest_dir=
    ({
      "players/arrina/newbie/newbie9","east",
      });
 }
  init()  {
  ::init();
   add_action("search_room","search");
         }
  search_room() {
    if(cups_taken >= 1) { /* change 1 to the number of cups that can be found */
      write("You search but find nothing of interest.\n");
      return 1;
    }
    cups_taken += 1; /* increment the # of cups taken */
   write("You search through the room and find a silver cup.\n");
 say (this_player()->query_name() +" searches, and finds a silver cup.\n");
   move_object(clone_object("players/arrina/treas/cup"),this_player());
     return 1;         }
