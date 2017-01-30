inherit "room/room";

reset(arg) {
	if(arg)  return;
short_desc = "An Orc Berserker Practice Room";
long_desc =
	"This is a practice room for the Orc Berserkers of the Blood Fisted\n"
	+"Clan. The walls are covered with drool and there is a strange odor\n"
	+"in the air. You wonder if the berserkers actually get anything out\n"
	+"of all of this practicing. You may just find out.\n";
set_light(2);
items = ({
	"walls", "The walls are abused and covered with saliva",
	});
dest_dir = ({
	"/players/pain/NEW/27", "north",
	"/players/pain/NEW/22", "south",
	});
if(!present("orc"))
move_object(clone_object("/players/pain/NEW/mon/orc_b"),this_object());

}

