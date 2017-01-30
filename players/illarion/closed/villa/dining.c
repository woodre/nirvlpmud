inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

int windows_open;

void reset(int arg) {
  if(arg) return;
  
  set_light(1);
  set_short("A "+HIG+"tropical"+NORM+" honeymoon villa");
  set_long(
"This small dining room seems designed as much for watching the beach as "+
"for eating.  Its one table for two is arragned so its chairs half face the "+
"wall of windows to the east, and half-face each other.  Both place-settings "+
"on the table are flawless, and seem to stay that way on their own. To the "+
"north, a doorway leads back to the living area, another to the west leads "+
"to the kitchen, and to the east, $&win_exit_string$&.");

  add_item("beach","The wall of windows to the east provides a picturesque "
                  +"view of the beach below.");
  add_item("table","A small table for two, trimmed in small seashells.  It "
                  +"seems to stay set perfectly for the time of day, and "
                  +"dirty dishes just vanish when they're no longer needed.");
  add_item("windows","The eastern wall is made up entirely of windows "
                    +"so clean and perfect that it's hard to tell they are "
                    +"there at all.  The middle pair of windows are sliding "
                    +"glass doors which $&window_string$&.");
  add_item("place-settings","The table stays suitable for whatever meal might "
                           +"be next.");
                           
  add_exit("living",VILLA+"livingroom");
  add_exit("patio",VILLA+"patio");
  add_exit("kitchen",VILLA+"kitchen");
}
string win_exit_string() {
  return "a pair of sliding glass doors stand "+(windows_open?"open":"closed");
}
string window_string() {
  return windows_open?"stand open to the beeze":"are closed";
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
  return 1;
}
