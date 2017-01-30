inherit "room/room";
 
reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc = 
"  You have just entered Trixtown which lies on a little green hill.  The sun\n"+
"seems to shine brighter here than in any other place in Nirvana.  Trixtown\n"+
"Main Road runs through the center in a westerly direction.\n";
  short_desc = "Trixtown entrance";
  dest_dir = ({ "/players/trix/castle/town/mainroad2.c", "west",
                "/players/trix/castle/center.c", "east"});
}
