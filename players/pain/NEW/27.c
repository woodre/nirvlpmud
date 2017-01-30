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
	"/players/pain/NEW/24", "south",
	"/players/pain/NEW/19", "southeast",
	"/players/pain/NEW/26", "west",
	});

}

