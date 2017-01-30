inherit "room/room";
 
reset(arg){
 
 if(!arg){
 
 set_light(1);
  short_desc="The desert";
 long_desc=
 "You are walking through a burning-hot, sandy rift in the desert.\n\
The sides rise up about you like quicksilver. You could not hope to\n\
move in any direction but north or south. There is a large obelisk in\n\
the center of the path.\n";
 
items=({
 "rift", "A rift in the desert - the path you have taken",
 "sides","The sides of the rift glow with heat",
 "obelisk","A large, grey stone rising out of the ground. It looks like\n\
 you could read the inscriptions on it",
 "path","The path is a rift in the desert",
 "desert","A horribly dry and hot desert. Right now you are in a deathly-\n\
hot rift",
            });
 
  dest_dir=({
 "/players/snow/dervish/hall/desert3.c","north",
 "/players/snow/dervish/hall/desert1.c","south",
      });
  }   }
 
 init() {
  ::init();
  add_action("read_inscription","read"); }

read_inscription(str) {
  if(!str) { notify_fail("Read what?\n"); return 0; }
  if(str == "inscription" || str == "obelisk" || str == "stone" ||
     str == "inscriptions") {
    write("You read the Obelisk's inscription..\n\n");
    cat("/players/snow/dervish/lore2.txt");
    return 1; }
  notify_fail("Read what?\n"); return 0; }