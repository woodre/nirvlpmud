inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc="Mall Hallway";
  long_desc="You are standing in the middle of the mall's hallways.\n"+
  "To the east you can see Mongo's Custom Armor Shop.  In there you can\n"+
  "purchase armor that will allow you to spicify it's name.  To the west\n"+
  "you can see Fred's Casino.  Although Fred is very new to the business\n"+
  "he is trying to get more casino games for you to enjoy.  To the south\n"+
  "you can see a large fountain in the middle of the hallway.\n";
  set_light(1);
  dest_dir=({
             "/players/grimm/closed/mall/casino","west",
             "/players/grimm/closed/mall/shop","east",
             "/players/grimm/closed/mall/hall3","south",
           });
}
