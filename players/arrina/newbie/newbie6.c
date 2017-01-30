  inherit "room/room";
  reset(arg){
   if(!present("skeleton")) {
 move_object(clone_object("/players/arrina/monsters/skeleton.c"),this_object());
 }
    if(!arg){
    set_light(0);
    short_desc="Closet";
   long_desc=
  "You have entered a tiny closet.  You wonder what must have been\n" +
  "stored in here in bygone times.  The fetid air closes in on you\n" +
  "and the cramped quarters make it unpleasant to be here.  You notice\n" +
  "several hooks on the walls and a chest on the floor.\n";
    items=({
   "hooks", "These carved wooden hooks look like they would be good\n"+
            "for hanging cloaks or other outergarments on",
   "chest","This finely crafted chest is empty",
  });
   dest_dir=({
  "/players/arrina/newbie/newbie2.c","east",
   });
 }
 }
