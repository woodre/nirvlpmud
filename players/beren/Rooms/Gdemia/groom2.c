inherit "room/room";
object ob, ob1, ob2;
reset(arg) {
  if(arg) return;
    ob = clone_object ("players/beren/Monsters/Gdemia/guard1.c");
    move_object (ob, this_object ());
    ob1 = clone_object ("players/beren/Monsters/Gdemia/guard1.c");
    move_object (ob1, this_object ());
  if(arg) return;

    set_light(1);
    short_desc = "Gdemia Cavern";
    long_desc =
"You are near the enterance to the Great Cavern.\n"+
"You can see some guards near it. They won't let you pass unless you\n"+
"are Gdemia or invited here but you aren't, are you?\n";
    dest_dir = ({"players/beren/Rooms/Gdemia/groom1", "east",
		 "players/beren/Rooms/Gdemia/groom3", "down"});
}

init ()
{
    ::init ();
    add_action ("my_down", "down");
}

my_down (str)
{
    if (present ("guard")) {
            write ("You aren't invited! You can't pass!\n");
            return 1;
    }
}
