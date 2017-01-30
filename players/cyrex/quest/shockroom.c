inherit	"room/room";

init() {
add_action("up", "up");
add_action("north", "north");
}
north() {
this_player()->move_player("exits the honeycomb#players/cyrex/quest/hive12");
return 1;
}
up() {
if(present("trooper")) {
write("The trooper steps in front of you and smacks you!\n");
command("bleed",this_player());
return 1;
}
this_player()->move_player("enters the lair#players/cyrex/quest/lair");
return 1;
}
reset(arg) { 
 if(!present("trooper")) {
   move_object(clone_object("players/cyrex/quest/strooper"), this_object());
 }
 if(!present("trooper1")) {
   move_object(clone_object("players/cyrex/quest/strooper1"), this_object());
 }
if(!present("trooper2")) {
  move_object(clone_object("players/cyrex/quest/strooper2"), this_object());
}
  if(!arg) {
  set_light(0);
  short_desc = "Shock Room";
  long_desc = 
   "This is the secret room of the newly generated shock troopers. They are\n"+
   "guarding the main entrance to Queen Regis's Lair. The troopers don't look\n"+
   "too happy that you have stumbled into the room. There is a passage\n"+
   "leading up where there is a cloud of mist.\n";
  no_exits = 1;
  property = ({"NT"});
  items = ({"mist",
	    "The mist seems to be gathering only around the entrance"});
  }
}
