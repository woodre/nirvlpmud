inherit "room/room";
 
reset(arg){
 
  while( !present("snow demon 2") ) {
move_object(clone_object("/players/snow/MONSTERS/snow_demon"),this_object());
  }
if(!present("ogre mage")) {
move_object(clone_object("/players/snow/MONSTERS/ogre_magi"),this_object()); }
 
 if(!arg){
 
 set_light(1);
  short_desc="Lair of Cold and Death";
 long_desc=
 "As you look around this huge cave, you are chilled to your very soul.\n\
Blue-tipped daggers of ice sprout from the walls, floor, and ceiling-\n\
creating and spreading a sickly bluish glow around the chamber.\n";
 
items=({
 "daggers", "Icicles sprout at unusual angles from the walls of this area",
 "glow","The glow seems to come from a bluish mold of some sort on the walls",
 "icicles","You aren't sure how these horrible icicles were formed",
 "mold","The blue mold turns black as you gaze more closely at it",
 });
 
  dest_dir=({
  "/players/snow/ROOMS/death/cold2.c", "south" });
  }   }
 
init() {
  ::init();
  add_action("south","south"); }

south() {
  object dem, og;
  dem = present("snow demon");
  og = present("ogre mage");
  if(this_player()->query_npc()) return;
  if(dem) {
    write("The Snow Demon blocks your path!\n");
    dem->attack_object(this_player());
    return 1; }
  if(og) {
    write("The Ogre Mage blocks your path!\n");
    og->attack_object(this_player());
    return 1; }
  else return 0; }

realm() { return "NT"; }
