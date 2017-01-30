inherit "room/room";
object corridor;

reset(arg)
{
  if(!arg)
    {
      set_light(1);
      short_desc = "Town Central";
      long_desc = "     This is Town Central, the gathering place for all the surrounding\n" +
                  "communities to meet and discuss their trades.  There are roads wandering\n" +
		  "off in 4 directions, north, south, east, and west.\n"+
		  "You can also 'ride' back to where you came from.\n";

      dest_dir =
        (
         {
           "players/rumplemintz/room/dlanding", "north",
            "players/rumplemintz/room/eastland", "east",
           "players/rumplemintz/room/elanding", "south",
	   "players/rumplemintz/room/westland", "west",
         }
         );
      
    }
}
init() {
  ::init();
/*
  add_action("search_room", "search");
  add_action("enter", "enter");
*/
  add_action("ride", "ride");
}
search_room(str) {
  if(str=="floor"){
    write("After a great deal of rummaging, you pull a large black switch\n" +
          "and see a corridor going down which you can enter.\n");
    corridor = this_player();
    return 1;
  }
}
enter(){
  if(corridor==this_player()){
    write("You go down through the hidden exit, into the darkness you found.\n");
    this_player()->move_player("enter#players/rumplemintz/workroom");
    return(1);
  }
  write("What?\n");
  return 1;
}
ride() {
  say(capitalize(this_player()->query_name())+" rides the cloud away.\n");
  write("You hop on the cloud, and take off for Nirvana.\n");
  move_object(this_player(), "room/mount_top2");
  say(capitalize(this_player()->query_name())+" climbs off the cloud.\n");
  command("look", this_player());
  return 1;
}
