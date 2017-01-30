#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Drygulch Hotel basement";
long_desc =
	"  There are racks with wide shelves in this part of the basement. \n"+
	"On the shelves are linens of various sizes.  Some of the linens \n"+
	"have started to dry-rot and the dust on top of most of them seems\n"+
	"to be undisturbed.  It appears the hotel has shifted a little \n"+
	"as the wall behind the rack has some tiny cracks, almost as if \n"+
	"someone had pushed the rack against the wall too hard. \n";

items = ({
	"racks","Sturdy wooden structures designed to hold much weight",
	"linens","Bedsheets, wash clothes, pillow cases and the like",
	"dust","The clock of time... accumulated slowly",
	"cracks","These cracks look a little peculiar as they nearly \n"+
		"outline this huge rack",
});

dest_dir = ({
	"/players/eurale/Hotel/dghb2.c","west",
});

}
init() {
   ::init();
   add_action("push", "push");
}

push(str) {
	if(str == "rack") {
        this_player()->move_player("push#players/eurale/Hotel/dghb7");
        return 1;
    }
return 1;
}
