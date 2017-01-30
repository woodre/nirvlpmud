inherit "/room/room";

reset(arg)
{
if(!present("guard")) {
move_object(clone_object("/players/morgoth/MONSTERS/entrance_guard.c"),this_object());
}
    if (arg) return;
    set_light(1);
    short_desc = "Morgoth's Realm";
    long_desc = "The realm of Morgoth, The Dark One.\n" +
    " \n"+
    "The forest beyond is forbidding and gloomy.\n" +
    "The trees are twisted and gnarled. Most uninviting.\n" +
    "A sense of doom permeates the very air.\n" +
    " \n" +
    " \n";
    
dest_dir = ({ "/players/morgoth/CASTLE/forest_1", "east",
              "/room/plane7.c", "out" });
    
}
init()
{
    add_action("east","east");
    add_action("out","out");
}

east()
{
    if (present("guard")) {
	write("Morgoth's guard blocks your way !\n");
	return 1;
    }
    call_other(this_player(), "move_player", "east#/players/morgoth/CASTLE/forest_1");
    return 1;
}

out()
{
  
    call_other(this_player(), "move_player", "out#/room/plane7");
    return 1;
}
