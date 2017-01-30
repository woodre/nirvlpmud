inherit "room/room";
reset(arg) {
if(arg)
   return;
short_desc="Old Musky Cavern";
long_desc="You have enter the caverns below the forest.  It is said that\n"+
          "Malachi hid an object he greatly feared in here.  If this is\n"+
          "true, he must have also conjured many beasts to roam in here to\n"+
          "ensure that no one who entered would leave!\n"+
          "You notice that you might be able to climb back up.\n";
dest_dir=({
   "players/grimm/caverns/cavern12","east",
   "players/grimm/caverns/cavern2","west",
   "players/grimm/caverns/cavern10","south"});
set_light(0);
}
init() {
  add_action("up","up");
  add_action("up","climb");
  ::init();
}
up() {
  write("As you crawl back up you you notice that you're not in the same\n"+
        "spot of the forest as when you entered the caverns.\n");
  this_player()->move_player("up#players/grimm/frst/forest25");
  return 1;
}
