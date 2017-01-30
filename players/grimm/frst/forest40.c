inherit "room/room";
reset(arg) {
if(arg)
   return;
short_desc="Old Musky Cavern";
long_desc="You have found a secret passage to the clock tower!  It is a\n"+
   "long way to the north but you are sure it should be safe.\n";
dest_dir=({"players/grimm/frst/forest41","north",
   "players/grimm/frst/forest12","up"});
set_light(1);
}
