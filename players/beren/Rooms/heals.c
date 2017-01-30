inherit "room/room";
object ob;
reset(arg) {
      set_light (1);
      short_desc = "Roccanon's world heal shop";
      long_desc = "You 've entered the heal shop!\nYou can type 'list' to see the goods "+
		  "and 'buy <number>' to get a heal!\n";
     dest_dir = ({"players/beren/Rooms/hall.c", "out"});
}

init ()
{
    ::init ();
    add_action ("list", "list");
    add_action ("buy", "buy");
}

list ()
{
    write ("Here is the list of the heals which are sold here:\n");
    write ("1. Large bottle of Angya grog (10 portions) - 4000 coins.\n");
    return 1;
}

buy (str)
{
write("Do to a coding problem, nothing is currently avialible.\n");
return 1;
    if (str != "1") { write ("You can't buy it here!\n"); return 1; }
    ob = clone_object ("players/beren/Objects/Heals/grog.c");
    move_object (ob, this_player ());
    this_player () -> add_money (-4000);
    write ("You 've bought a large bottle of grog!\n");
    say (this_player ()-> query_name () + " bought a large bottle of grog.");
     return 1;
}    

