inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc="Mall Hallway";
  long_desc="You are standing in the entrance to the mall.\n"+
"To the west you can see the entrance to Paco's Tatoo shop.  Although\n"+
"he isn't very intelligent, he occasionally does do good work.\n"+
"To the east you see Daemon's Monster Truck Ralley.  You can race against\n"+
"other players in modified death-mobile monster trucks.  To the south you\n"+
"can hear the mall security snoring away at the mall's entrance.  And \n"+
"further to the north you can see a large fountain and more shops.\n";
  set_light(1);
  dest_dir=({
             "/players/grimm/closed/mall/pacos","west",
             "/players/grimm/closed/mall/daemons","east",
             "/players/grimm/closed/mall/hall2","north",
             "/players/grimm/closed/mall/entrance","south",
           });
}
