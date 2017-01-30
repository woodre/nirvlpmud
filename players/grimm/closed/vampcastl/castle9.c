inherit "room/room";
realm() { return "NT"; }
reset(arg) {
monster();
if(arg)
   return;
short_desc="Grungy Kitchen";
long_desc="You have entered the kitchen area of the castle.  It doesn't seem\n"+
          "like it has been used at all though.  There are cupboards on the\n"+
          "walls but they appear to be emtpy.  Also, the gas stove seems to\n"+
          "have been destroyed (maybe so no one could start a fire in here).\n",
items=({"cupboard","They are very old, antiques probably, and empty",
        "stove","This was an old fashioned gas stove, but it is totaly destroyed now"});
dest_dir=({"players/grimm/closed/vampcastl/castle6","south"});
set_light(1);
}
monster() {
   int count;
   object monster;
   if(!present("roach")) 
      while(count < 3) {
         count += 1;
         monster = clone_object("players/grimm/monster/roach");
         move_object(monster,this_object());
      }
return 1; 
}
