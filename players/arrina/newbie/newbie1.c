 inherit "room/room";
  reset(arg){
  if(!present("sentry")) {
 move_object(clone_object("/players/arrina/monsters/sentry.c"),this_object());
                 }
 if(!present("sentry 2")) {
 move_object(clone_object("/players/arrina/monsters/sentry.c"),this_object());
                }
   if(!arg){
  set_light(1);
   short_desc="A dim room";
   long_desc=
  "You are just inside the castle doors, and an aura of gloom begins to \n"+
 "descend upon you, although you don't know why.  The torches on the \n"+
 "walls are very dim, and appear about to go out.\n"+
  "There is an area that looks like a stable to the west.\n"+
   "If you wish to leave, go south, otherwise keep going.\n";
  items=({
  "doors", "The doors appear unlocked.  You could still turn back",
  "torches", "The torches are almost out of fuel.  Did you bring some? \n"+
        "Do you have a light source, should it get really dark?",
  "walls", "Just your ordinary gloomy, musty, castle walls.\n",
 });
    dest_dir=({
   "/players/arrina/newbie/newbie3.c","east",
   "/players/arrina/newbie/newbie2.c","north",
    "/players/arrina/grounds/stable.c","west",
   "/players/arrina/newbie/newbie1a.c","south",
 });
   }   }
  init()  {
  ::init();
   add_action("search_room","search");
         }
  search_room() {
   write("You search through the room but find nothing of value.\n");
 say (this_player()->query_name() +" searches the room but finds nothing.\n");
   return 1;         }
