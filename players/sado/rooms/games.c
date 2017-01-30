inherit "/players/sado/rooms/mansion.c";

reset()
{
  set_short("Sado's Gaming Parlour");
  set_long("Welcome to Sado's gaming parlour!\n"+
	   "You can play a variety of games here.  The following games are currently\n"+
	   "available:\n\n"+
	   "Hippo's \"51\"\n"+
	   "\n"+
	   "Type \"exa <game>\" for more info on any of the games listed\n");
  set_items(({
    "51",
      "Type \"rules 51\" for the rules.\n"+
      "Type \"51 <player2> [<player3> [<player4>]]\" to start a game",
      }));
  set_dest_dir(({
"/players/sado/rooms/workroom.c","work",
      }));
  move_object(clone_object("/players/hippo/games/fiftyone.c"),this_object());
  set_light(1);
}
