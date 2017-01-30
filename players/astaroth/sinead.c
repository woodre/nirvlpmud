inherit        "room/room";
 
reset(arg) { 
 object money, sinead;
 if(!present("sinead")) {
   sinead = clone_object("players/astaroth/oconnor");
   money = clone_object("obj/treasure");
   money->set_short("british currency");
   money->set_long("british currency - sell at shop for local money.\n");
   money->set_value(800+random(300));
   money->set_weight(2);
   money->set_id("currency");
   money->set_alias("british currency");
   move_object(money, sinead);
   move_object(sinead, this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "All you see is a glare.";
  long_desc = 
   "Your eyes adjust and you can see again.  The glare was just \n"+
   "the normal light reflecting off of the head of Sinead O'connor.\n"+
   "She is singing a song against war in the middle east.\n";
  dest_dir = ({"players/astaroth/gdmusic", "south"});
  }
}
