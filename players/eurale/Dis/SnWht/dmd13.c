#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Diamond Mine Drive";
long_desc =
	"  This is a wonderful bark path.  It wanders through the thick \n"+
	"forest and among the tall timber.  The rustling of the leaves \n"+
	"as the wind caresses the branches creates a soothing and serene \n"+
	"atmosphere.  Queen Anne's Lace grows in abundance all along the \n"+
	"edges of the path.  You stand on the porch of a woodland cottage.\n"+
	"It sounds like there might be people here.  Maybe you should just\n"+
	"knock on the door.\n";

items = ({
	"path","Chopped and shredded bark from felled trees",
	"lace","Large, white, delicate flowerheads on tall stems",
	"cottage","A quaint little building with a thatched room and \n"+
		"flower gardens ringing the building",
});

dest_dir = ({
	"players/eurale/Dis/SnWht/dmd12.c","west",
});

}

init() {
  ::init();
  add_action("knock","knock");
}

knock(str) {
  if(query_verb() == "knock") {
  write("The door opens and admits you...\n");
  this_player()->move_player("knock#players/eurale/Dis/SnWht/dmd20.c");
  return 1; }
return 1;
}
