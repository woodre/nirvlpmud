inherit "room/room";
reset(arg){
 if(!arg){
  set_light(1);
  short_desc="Hidden Cavern of the Wyrm";
  long_desc="This is a huge underground cavern.  This is where Maldraedior's real body\n"+
            "is located.  This room is filled with blocks of gold.  The gold blocks\n"+
            "are to heavy to be lifted.  There isn't much in here besides the torches\n"+
            "that light the room and a huge stone egg-like thing.\n";
  dest_dir=({"players/mouzar/quest/mouth","up",});
 }
 if(!present("egg",this_object())){
   move_object(clone_object("/players/mouzar/quest/obj/egg"),this_object());
 }
}
