inherit "room/room";
 
reset(arg) {
    if(arg) return;
    set_light(1);
   long_desc=
"  You are in the hallway of the disco.  You see a door to the south and you\n"+
"hear music coming from behind it.  Your legs seem to carry you in that\n"+
"direction.\n";
   short_desc = "A dark hallway";
    dest_dir = ({ "/players/trix/castle/disco/hall3.c","north",
                  "/players/trix/castle/disco/grid3.c","south"});
}
