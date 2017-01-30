inherit 
"room/room";
int flag = 0;
object ob, ob1, ob2, gold;
reset(arg) {
  if(arg) return;
    ob = clone_object ("players/beren/Monsters/Gdemia/leader1.c");
    move_object (ob, this_object ());
  if(arg) return;
    set_light(0);
    short_desc = "Gdemia Cavern";
    long_desc = "You are in the great Gdemia Cavern. It's very dark here"+
                ", so\nyou can lose your way very simple.\n";
    dest_dir = ({"players/beren/Rooms/Gdemia/groom19", "up"});
}

init ()
{
    ::init ();
    add_action ("dig", "dig");
}

dig (str)
{
    if (flag == 1) return 0;
    if (present ("leader")) write ("Leaders won't let you dig!\n");
    else
    {
	write ("You have found the treasure of Gdemia!\n");
	call_other (this_player(), "add_money", 15000);
flag = 1;
    }
    return 1;
}
