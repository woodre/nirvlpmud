inherit "room/room";

reset(arg) {
	if(arg)  return;
short_desc = "An Orc Axemen Practice Room";
long_desc =
	"This is a practice room for the Orc Axemen of the Blood Fisted\n"
	+"Clan. The walls are dented and slashed and wood chips lay about\n"
	+"everywhere. You wonder if the axemen actually get anything out\n"
	+"of all of this practicing. You may just find out.\n";
set_light(2);
items = ({
	"walls", "The walls are dented and covered with pock marks",
	});
dest_dir = ({
	"/players/pain/NEW/12", "east",
	"/players/pain/NEW/10", "southeast",
	"/players/pain/NEW/14", "south",
	});
if(!present("orc"))
{
move_object(clone_object("/players/pain/NEW/mon/orc_a"),this_object());
move_object(clone_object("/players/pain/NEW/mon/orc_a"),this_object());
}

}

