inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Middle of Nowhere";
    long_desc=
     "An error has occured. You are in the middle of nowhere.\n"+
     "The only thing you can see is a black portal....\n";

    items=({
     "portal","The portal is the goportal room",
    });

    dest_dir=({
      "/players/saber/ryllian/portal.c","portal",
    });

    }
  }
