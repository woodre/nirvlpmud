inherit"room/room";

int dir;

reset(arg) {

   if(!arg) {

   set_light(1);
   short_desc = "An obsidian plane.";
   long_desc =
   "You find yourself standing on a 10' square piece of black obsidian rock"+
",\nthat appears to be suspended in mid air.  All around you hang similiar "+
"\nslabs of rock, magestically floating.  You see no sky, or ground, but "+
"\nseem to be in a huge room, with only blackness for the ceiling and ground."+
"\n  These great planes of shining black rock are each 10' apart, and you may"+
"\nbe able to jump between them, although you don't know exactly what is belo"+
"w\nor above you in this strange cavern.\n";

dest_dir = ({
   "players/blue/plane/plane16","north",
   "players/blue/plane/plane11","south",
   "players/blue/plane/plane6","east",
    "players/blue/plane/plane5","west",
    "players/blue/castle/pit_enter","up"
});
   }
}

