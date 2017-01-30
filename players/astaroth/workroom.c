inherit        "room/room";
reset(arg) {
 
  if(!arg) {
  set_light(1);
  short_desc = "A fairly well kept room (if you ignore the desk that's got stuff stacked a \n" + "mile high on it).";
  long_desc = 
   "This is the workroom of Astaroth\n"+
   "Astaroth will only be hostile if you are not invited here.\n"+
   "Don't worry, you probably won't even be noticed if Astaroth isn't here\n";
  dest_dir = ({"room/pub2", "pub",
               "room/shop", "shop",
               "room/church", "church",
               "players/astaroth/locker", "in",
               "players/astaroth/tub", "tub",
               "room/adv_guild", "guild",
               "room/post", "north"});
  }
}
realm() { return"NT"; }
