inherit "room/room";
 
reset(arg) {
    if(arg) return;
    set_light(1);
   long_desc =
 "The path you are on continues up the mountain while a small, twisty\n\
path forks off to the west. There appears to be a cave a little further\n\
up this path.\n";
   short_desc = "On the mountain path";
    dest_dir = ({ "/players/snow/ROOMS/path3.c","up",
                  "/players/snow/mountains/bandit/path","west",
                  "/players/snow/ROOMS/path1.c", "down"});
                  }
 
