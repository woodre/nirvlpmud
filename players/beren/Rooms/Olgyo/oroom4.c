inherit "room/room";
object h, h1, h2;

reset(arg) {
  if(arg) return;
    h = clone_object ("players/beren/Monsters/Olgyo/guard.c");
    move_object (h, this_object());
/*
    h1 = clone_object ("players/beren/Monsters/Olgyo/guard.c");
    move_object (h1, this_object ());
    h2 = clone_object ("players/beren/Monsters/Olgyo/guard.c");
    move_object (h2, this_object ());
*/
    if (arg) return;

    set_light(1);
    short_desc = "A guard outpost";
    long_desc =
"You are entered the Guard outpost. The Guards won't let you pass unless you are\n"+
"Olgyo. But you aren't, are you?\n"+
"You feel the great DANGER coming from east. You see a small hut there.\n"+
"Enter on your own risk (make sure your level is high enough)!\n";
    dest_dir = ({"players/beren/Rooms/Olgyo/oroom8", "east",
		 "players/beren/Rooms/Olgyo/oroom5", "west"});
}

init ()
{
    ::init ();
    add_action ("my_east", "east");
}

my_east (str)
{

    if (present ("guard")) {
	    write ("You aren't Olgyo! You can't pass!\n");
            return 1;
    }
}

