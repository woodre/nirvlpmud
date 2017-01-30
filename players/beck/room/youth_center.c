inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("Angel Grove Youth Center");
   long_desc=
   "This is the Youth Center of Angel Grove.\n"+
   "It is run by Ernie as a place for all the local high schoolers\n"+
   "to hang out in the afternoon.  It is almost always busy\n"+
   "and usually it's near impossible to find an empty booth to sit at.\n"+
   "There are several tables for people to sit at,\n"+
   "and a snack bar that is run by Ernie.  The room\n"+
   "is also filled with various entertainment equipment.\n"+
   "",
   items=
   ({
    });
   dest_dir=
   ({
"players/beck/room/street3.c","exit",
    });
if(!present("jukebox", this_object())){
move_object(clone_object("players/cosmo/jb/jukebox.c"), this_object());
}
   if(!present("machine", this_object())){
      move_object(clone_object("/players/emerson/obj/pin"), this_object());}
   if(!present("ernie", this_object())){
      move_object("/players/beck/monster/ernie.c", this_object());}
}
short(){
return "Angel Grove Youth Center";
}
