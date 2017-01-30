
inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "Roman Empire" ;
    long_desc = "You see here some little houses and the Coliseum in the\n" +
    "distance. You can see also the Roman Forum. There's a man's\n" +
    "bust in the middle of the room.\n";
   dest_dir =
   ({
    "/players/hurtbrain/castello/entrance" , "out" ,
    "/players/hurtbrain/castello/dag/dag2" , "east" ,
    "/players/hurtbrain/castello/dag/dag16" , "west"
    });
    set_light(1) ;
   items = ({"bust" ,
   "This is a bust representing an elderly man. The sign above the\n" +
   "bust reads : 'Giulius Caesar'" });

}

