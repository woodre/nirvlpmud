inherit	"room/room";

reset(arg) { 
 if(!present("goblin")) {
   move_object(clone_object("/players/bastion/monster/goblin"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "A little test room";
  long_desc = 
   "This is a little place. It is very empty.\n";
  no_exits = 1;
  property = ({"NT"});
  dest_dir = ({"/players/bastion/room/hell", "out"});
  }
}
