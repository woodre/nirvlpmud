inherit "room/room";
object disp;

reset(arg) {
   if(!present("dispenser")) {
      disp = clone_object ("players/beren/Objects/dispenser");
      move_object(disp, this_object());
   }
    if (arg) return;

    set_light(1);
    short_desc = "Great Crossroad of Roccanon's world";
    long_desc = 
"You are standing on the new planet, which just joined the Star League.\nYou know nothing about it's nations, so you should get a guide.\nThere is a large sign in the middle of intersection.\n";
     dest_dir = ({"players/beren/Rooms/Olgyo/oroom.c", "northeast",
		  "players/beren/Rooms/Gdemia/groom1.c", "northwest",
/*
		  "players/beren/Rooms/heals.c", "pub",
*/
		  "room/plane13", "leave"});
    items = ({"sign", "It's a big metal sign. You can read it as well"});
}
init ()
{
   ::init ();
   add_action ("reading", "read");
/*  taken out as a special room - Eurale 9/4
   add_action ("honey", "honeymoon");
*/
}

honey ()
{
 if ((this_player()->query_name() != "Beren") && (this_player()->query_name()!="Julianne"))
 {
	write ("You can't be teleportated! You aren't invited, sorry!\n");
	return 1;
 }
 call_other (this_player (), "move_player", "home#players/beren/workroom.c");
 write ("Welcome here, love!\n");
 return 1;
}
reading (str)
{
   if (!id2 (str)) return 0;
   write ("Here are the directions you can go here:\n");
   write ("North - Castles of Angya.\n");
   write ("Northeast - Villages of Olgyo.\n");
   write ("Northwest - Caverns of Gdemia.\n");
   write ("West - Villages of Fiia.\n");
   write ("East - ???\n");
   write ("South - ???\n");
   return 1;
}

id2 (str)
{
   return str == "sign" || str == "large sign";
}

