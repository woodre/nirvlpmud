/* tport.c: logger's guild teleport room */
inherit "room/room";
#define ROOM_DIR "/players/wizardchild/closed/logger/room/"
reset(arg) {
  if(arg) return 0;
  set_light(1);
  short_desc = "Logger's Guild crossroads";
  long_desc  = "You walk outside into the mountainy forests of Nirvana. Here is where the\n"
              +"logging trucks pick up and drop off their loads of nature's bounty. To find\n"
              +"out where they can take you, look at the chart.\n"
              +"A time chart for deliveries.\n";
  dest_dir = 
  ({
  ROOM_DIR+"g_hall.c", "west"
  });
}
init() {
  if(!(ROOM_DIR+"checkok")->query_ok(this_player())) {
    write_file(ROOM_DIR+"ILLEGAL_ENTRY", "<"+ctime(time())+"> "+this_player()->query_real_name()+" tport\n");
    move_object(this_player(), "room/plane12");
  } else {
    add_action("lk", "look");
    add_action("lk", "l");
    add_action("hitch", "hitch");
  }
  ::init();
}
lk(str) {
  if(str != "at chart") return 0;
  write("From what you can tell, you can thumb a ride to the following places:\n");
  write("church\nshop\nadvance\nhump\nocean\n");
  write("Apparently, more locations will come on demand later.\n");
  return 1;
}    
/* players can go to church,shop,advance,hump, and ocean */
hitch(str) {
  string where;
  if(str != "church" && str != "shop" && str != "advance" && str != "hump" && str != "plane" && str != "ocean") 
    write("There are no trucks going that direction.\n");
  else {
    if(str == "advance") where = "adv_guild";
    if(str == "ocean") where = "sea";
    if(!where) where = str;
    where = "/room/"+where+".c";
    write("You stick out your thumb, and a passing by driver picks you up.\n");
    this_player()->move_player(str+"#"+where);
    write("You quickly arrive at the "+str+".\n");
    say(this_player()->query_name()+" jumps off a logging truck.\n");
  }
  return 1;
}    
