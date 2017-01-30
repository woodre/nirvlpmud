inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

int windows_open;

void reset(int arg) {
  if(arg) return;
  
  set_light(1);
  set_short("A "+HIG+"tropical"+NORM+" honeymoon villa");
  set_long(
     "This is the living area of the villa.  In the center of the room a huge "
    +"loveseat faces the glass windows that make up the entire east wall.  "
    +"Through the windows, you can see a patio, and beyond, a beautiful "
    +"beach.  On either side of the pillow-covered loveseat is a small end "
    +"table, and a few other chairs sit along the walls.  To the west, a "
    +"hallway leads back towards the entrance, while to the north a doorway "
    +"leads into the bedroom and to the south one leads into the dining "
    +"area.  To the east, $&breeze_string$&.");
    
  add_item("loveseat","A loveseat that would serve as a large bed for most "
                     +"people dominates the room.  Its already soft "
                     +"upolstery is complimented by an prodigous number of "
                     +"pillows.");
  add_item("windows","Perfect windows, so well-made and clean that it's "
                    +"almost impossible to tell they are there.  "
                    +"$&window_string$&");
  add_item("patio","A wide patio, with some outdoor furniture on it.");
  add_item("beach","A wide, white beach, with waves washing gently "
                  +"across it, and all the other things you'd expect from a "
                  +"tropical beach.");
  add_item("pillows","Soft pillows of all sizes and shapes are stacked on "
                    +"top of the loveseat.");
  add_item("table","Small tables made of exotic wood and trimmed in shells "
                   +"sit on each side of the love seat, with a coaster "
                   +"sitting atop each to hold a drink.");
  add_item("bedroom","The villa's large bedroom is just to the north.");
  add_item("dining area","A small dining area is just to the south.");
  add_item("hall","The hall leads back toward the landward entrance to "+
                  "the villa.");
                  
  add_exit("west",VILLA+"hall");
  add_exit("patio",VILLA+"patio");
  add_exit("bedroom",VILLA+"bedroom");
  add_exit("dining",VILLA+"dining");
}
string breeze_string() {
  if(!windows_open)
    return "a pair of sliding glass doors stands shut";
  else
    return "a pair of sliding glass doors stands open, letting the breeze in";
}
string window_string() {
  if(!windows_open)
    return "In the center of the wall of windows, a pair of sliding glass "
          +"doors stands shut.";
  else
    return "The breeze blows gently in through the open sliding glass doors.";
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
