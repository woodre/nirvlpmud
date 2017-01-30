inherit "room/room";
 
reset(arg) {
object hutman;
    if(arg) return;
    set_light(1);
     long_desc ="You have entered the Famous Pizza The Hut's private back room.\n"+
     "He is one big slimy looking dood! Think you're tough enough?\n";
     short_desc = "A Back Room";
   dest_dir = ({ "/players/emerson/rooms/room29.c","south"});

     hutman = clone_object("players/emerson/mons/hutman.c");
      move_object(hutman,this_object());
}
