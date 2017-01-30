  inherit "room/room";
  reset(arg){
   if(!present("sentry")) {
 move_object(clone_object("/players/arrina/monsters/sentry1.c"),this_object());
 }
    if(!arg){
    set_light(0);
    short_desc="Dark Atrium ";
   long_desc=
  "This room appears to be an entryway of some sort.  It is musty and\n" +
  "dreary, and gives you a feeling of unease.  You can see that this\n" +
  "room was once magnificent, but has gone to ruin.  There are torches\n" +
  "on the walls, and as you walk, you feel stickiness on the floor.\n";
   items=({
   "torches", "These once fine torches have gone out.  It appears\n"+
   "whoever still inhabits this place has no need for light",
   "floor","You look at the floor and see it is covered with blood",
  });
   dest_dir=({
  "/players/arrina/newbie/newbie1.c","south",
  "/players/arrina/newbie/newbie9.c","north",
  "/players/arrina/newbie/newbie6.c","west",
  "/players/arrina/newbie/newbie4.c","east",
   });
}
}
