inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "office";
  long_desc = 
   "     You have entered the back office of the investigation room.  Nothing\n"+
   "is worth looking in here.  Everything has been left to deterioate.  You\n"+
   "do notice a desk in the corner though.  However, you don't want to waste\n"+
   "time looking at it.\n";
  property = ({"NF", "NT"});
  items = ({"desk",
            "A finely made oak desk that has been left unused"});
  dest_dir = ({"players/cyrex/investigation", "north",
               "players/cyrex/bank", "south",
});
  }
}
