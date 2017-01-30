inherit "room/room";

reset(arg) {
	if(arg)  return;
short_desc = "An Orc Grunt Practice Room";
long_desc =
	"This is a practice room for the Orc Grunts of the Blood Fisted\n"
	+"Clan. The walls are dirty and there is a strange odor in the\n"
	+"air. You wonder if the grunts actually get anything out of all\n"
	+"of this practicing. You may just find out.\n";
set_light(2);
items = ({
	"walls", "The walls are dirty and covered with phlegm",
	});
dest_dir = ({
	"/players/pain/NEW/36", "north",
	"/players/pain/NEW/31", "south",
	});
if(!present("orc"))
{
move_object(clone_object("/players/pain/NEW/mon/orc_gr"),this_object());
move_object(clone_object("/players/pain/NEW/mon/orc_gr"),this_object());
move_object(clone_object("/players/pain/NEW/mon/orc_gr"),this_object());
}

}

