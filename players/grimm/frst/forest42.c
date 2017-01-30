inherit "room/room";
reset(arg) {
if(arg)
   return;
short_desc="Old Musky Cavern";
long_desc="You have come to the bottom of the clock tower.  There is a\n"+
          "steel ladder bolted on the northern wall which will allow you\n"+
          "to climb up into the tower.\n";
dest_dir=({"players/grimm/frst/forest41","south",
   "players/grimm/tower","up"});
set_light(1);
}
