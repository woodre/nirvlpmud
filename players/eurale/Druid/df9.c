#define tpn this_player()->query_name()
#define tp this_player()
inherit "room/room";

reset(arg) {
if(!present("messenger")) {
move_object(clone_object("players/eurale/Druid/mess.c"),this_object()); }
  if(arg) return;
set_light(1);

short_desc = "Lush Forest";
long_desc =
	"  This a beautiful and lush forest.  In fact, it seems almost\n"+
	"too beautiful to be true.  Everything that is growing here is\n"+
	"extra green and appears to be very healthy.  The wild flowers\n"+
	"that grow between the trees on the forest floor add magnificent\n"+
	"color to this aready majestic area.  Here stands the largest\n"+
	"Ironwood tree you've ever seen..... impressive in size alone\n"+
	"to be sure.\n";

items = ({
	"tree","This huge tree, sometimes called a Hornbeam, has grayish,\n"+
		"flaky bark and the leaves look like giant birch leaves.\n"+
		"A close inspection reveals that you may be able to \n"+
		"actually [enter] the trunk of this splendid specimen",
	"trees","Birch, maple and poplar trees with deep green leaves",
	"flowers","Richly colored Sand Myrtle, Winged Sumac, Blackberry\n"+
		"Lily, Witch Hazel and Mountain Rosebay",
	"myrtle","A low, widely branching evergreen shrub with crowded\n"+
		"leathery leaves and small pink flowers in dense clusters",
	"sumac","A small tree with hairy twigs, milky sap and small\n"+
		"greenish flowers",
	"lily","Leafless flower stalks with several red-spotted, orange\n"+
		"flowers that grow from among flat sword-like leaves",
	"witch hazel","Tall, flowering shrub with clusters of spidery,\n"+
		"yellow flowers in the leaf axils",
	"rosebay","An evergreen shrub with clusters of large, rose or\n"+
		"purple-lilac, funnel-shaped flowers",
});

dest_dir = ({
	"players/eurale/Druid/df6.c","south",
	"players/eurale/Druid/df8.c","west",
});

}

init() {
  ::init();
  add_action("enter","enter");
}

enter() {
tp->move_player("enters tree#players/eurale/Druid/df10.c");
  return 1; }
