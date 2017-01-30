inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Main Road";
  long_desc = 
   "You are standing on a well travelled path heading west and east. A castle can\n"+
   "be seen to your west. A huge forest can be seen to your north-east. Some sort\n"+
   "of shop can be seen to your south.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/amain2", "west",
               "players/cyrex/aldera/amain4", "east",
               "players/cyrex/aldera/ashop", "south"});
  }
}
