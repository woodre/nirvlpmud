inherit "room/room";

reset(arg) {
	if(arg)  return;
short_desc = "An Orc Mage Practice Room";
long_desc =
	"This is a practice room for the Orc Mage's of the Blood Fisted\n"
	+"Clan. The walls are scorched and there is a strange odor in the\n"
	+"air. You wonder if the mages actually get anything out of all\n"
	+"of this practicing. You may just find out.\n";
set_light(2);
items = ({
	"walls", "The walls are abused and covered with soot",
	});
dest_dir = ({
	"/players/pain/NEW/3", "east",
	"/players/pain/NEW/5", "south",
	"/players/pain/NEW/1", "southeast",
	});
if(!present("orc"))
{
move_object(clone_object("/players/pain/NEW/mon/orc_m"),this_object());
move_object(clone_object("/players/pain/NEW/mon/orc_m"),this_object());
}

}

