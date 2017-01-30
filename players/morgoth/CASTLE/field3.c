inherit "room/room";
object bat, money, ruby;
int i;
reset(arg)
{
    if (arg) return;
    set_light(1);
    i = 0;
    if (!bat || !living(bat))
     {
    while (i < random(10))
      {
      i += 1;
      bat = clone_object("players/morgoth/MONSTERS/bat");
    money = clone_object("obj/money");
    money->set_money(random(50));
    move_object(money, bat);
      move_object(bat, this_object());
      }
    }
    short_desc = "Strawberry Fields forever....";
    long_desc = "This is the nesting grounds for the bats\n"+
            "that inhabit Strawberry Fields.\n"+
		"\n";
/*
            "To the west is the lair of the Cyclops.\n";
*/

dest_dir = 
({
    "players/morgoth/CASTLE/field2", "north",
    "players/morgoth/CASTLE/Fnest", "east",
    "players/morgoth/CASTLE/field4", "south",
});
}

/*  quest changes  4/2/97  moved cyclops room  Eurale  */
/*  Added the nest room. 12/14/00 Feldegast */
init()
{
    ::init();
    add_action("move_east", "east");
}

move_east()
{
    if(present("bat", this_object()))
    {
      write("The bats block your way !!\n");
    return 1;
    }
    this_player()->move_player("east#players/morgoth/CASTLE/Fnest");
    return 1;
}

query_temp() { return 1; }
