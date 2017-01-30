inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

int windows_open;

void reset(int arg) {
  if(arg) return;

  set_light(1);
  set_short("A "+HIG+"tropical"+NORM+" honeymoon villa");
  set_long(
     "The villa's bedroom is almost large enough for the dining all of a "
    +"small mansion, and the large canopied bed is large in the same "
    +"proportion.  The bed's foot faces toward the wall of windows to the "
    +"east, between two large easy chairs also facing toward the stunning "
    +"ocean view outside.  On either side of the bed are two large end "
    +"tables with lamps seemingly constructed entirely of shells.  The north "
    +"wall of the room contains two large closets on either side of "
    +"a well-stocked mini-bar.  Two doors in the south lead to the hallway "
    +"or the living area, another just south of the bed leads to the bathroom, "
    +"and to the east $&window_string$&.");
    
  add_item("bed",
    "The bed is a very-oversized king, with large wooden posts, and a "+
    "matching midnight blue canopy and comforter, over white, pure silk "+
    "sheets, with a large variety of soft pillows.");
  add_item("windows",
    "The windows are so well-made and clear that it almost seems they "+
    "aren't there.  $&window_desc_string$&");
  add_item("chair",
    "The overstuffed easy chairs are easily big enough for one, and quite "+
    "soft.  They face the window's panoramic view of the beach.");
  add_item("chairs","@chair");
  add_item("view",
    "The ocean and beach-below are picture perfect, and you would swear "+
    "the were from a painting if it weren't that the waves and sand were "+
    "moving.");
  add_item("table",
    "The end tables are the same exotic-wood shell trimmed furniture that "+
    "is found elsewhere in the villa.");
  add_item("lamps","@lamp");
  add_item("lamp",
    "The lamps are almost totally made of shells, even the shades, but "+
    "the light from them seems to come from a softly glowing crystal "+
    "rather than a lightbulb.");
  add_item("closets","@closet");
  add_item("closet",
    "The closets are deeper than they look at first glance, one stocked with "+
    "clothes for men, the other with clothes for women.");
  add_item("bar",
    "The bar is stocked with all the glasses and beverages needed to aid "+
    "with pleasure and relaxation.");
  
  set_etime_const(120);
  set_etime_rand(60);
  
  add_room_emote("The light from the lamps pulses softly.");
  
  
  add_exit("southwest",VILLA+"hall");
  add_exit("southeast",VILLA+"livingroom");
  add_exit("west",VILLA+"bathroom");
  add_exit("patio",VILLA+"patio");
}
string window_string() {
  return "a pair of sliding glass doors stands "+
    (windows_open?"open":"closed");
}
string window_desc_string() {
  return "The center two windows of the wall are a pair of sliding glass "
         +"doors, which are "+(windows_open?"standing open to the breeze.":
         "closed.");
}
void init() {
  ::init();
  add_action("cmd_open","open");
  add_action("cmd_close","close");
}
int cmd_open(string str) {
  if(!str || str != "doors")
    FAIL("Open what?\n");
  if(windows_open) {
    write("They are already open.");
    return 1;
  }
  windows_open=1;
  write("You open the sliding glass doors.\n");
  say(TPN+" opens the sliding glass doors.\n");
  add_room_emote("A cool sea breeze wafts through the room.");
  return 1;
}
int cmd_close(string str) {
  if(!str || str !="doors")
    FAIL("Close what?\n");
  if(!windows_open) {
    write("They're already closed.\n");
    return 1;
  }
  windows_open=0;
  write("You pull the sliding glass doors shut.\n");
  say(TPN+" pulls the sliding glass doors shut.\n");
  remove_room_emote("A cool sea breeze wafts through the room.");
  return 1;
}
