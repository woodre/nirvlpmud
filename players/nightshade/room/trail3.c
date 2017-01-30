inherit "players/nightshade/new_room";
object lag;
reset(arg){
  if(!lag) {
    lag = clone_object("players/nightshade/mons/lag_mon");
  move_object(lag, this_object());
  }
   if(arg) return;
        set_light(1);
        short_desc = "Forest Trail";
     long_desc =
"You are walking caustiously along a trail going south through the forest.\n";
      dest_dir = 
      ({ "/players/nightshade/room/trail4", "south",
      "players/nightshade/room/trail2", "north",
    "players/nightshade/room/forest4", "east",
 "players/nightshade/room/forest3", "west",
      });
}
