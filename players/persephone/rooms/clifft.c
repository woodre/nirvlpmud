inherit "/players/persephone/closed/thingys.c";
reset (arg){
 if (arg) return;
  set_light(1);
  short_desc="Cliff Top";
  long_desc="You are standing on the top of a limestone cliff that must have one\n" +
            "of the most beautiful panoramas in all of Nirvana. To the north you see\n" +
            "the mysterious Sea of Fate while to the east you can see a lovely\n" +
            "sandy beach while on top of the cliff you are surrounded by a pasture\n" +
            "full of beautiful and mysterious wild flowers. Far off in the distance\n" +
            "to the east you think that you can see small town and you start to\n" +
            "wonder what awaits you in the distance.  \n";
  dest_dir=({"players/persephone/rooms/meado1","south",
             "players/persephone/rooms/cliff_f2","down",
  });
}
realm(){ return "NT";}
