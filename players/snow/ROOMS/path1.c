inherit "room/room";
 
reset(arg) {
    if(arg) return;
    set_light(1);
  long_desc =
 "You find yourself on a mountain suspended in space. It appears to have\n\
its own atmosphere somehow so you can breath and, though it is a bit cold\n\
here, you are relatively comfortable. A path winds up the mountain from\n\
where you are standing. Will you attempt the climb?\n";
   short_desc="The foot of Snow Mountain";
    dest_dir = ({
"/players/snow/ROOMS/path2.c","up",
"/players/snow/gate.c","vortex"
    });
                }
