#include "/players/illarion/dfns.h"
inherit "/players/illarion/room";

int tub_full,whirlpool_on;

void reset(int arg) {
  if(arg) return;
  
  set_light(1);
  set_short("A "+HIG+"tropical"+NORM+" honeymoon villa");
  set_long(
"A huge ivory-colored tub in the center of the room dominates this bathroom "+
"tiled in white and blue.  A long marble counter runs all the way along the "+
"east wall, under a mirror that covers the rest of the wall.  The toilet "+
"sits in the northeast corner, and a rack for towels and washcloths hangs "+
"from the wall in the southeast corner.  To the south, a door leads back "+
"to the bedroom. \n");

  add_item("tub","This large circular tub looks quite roomy for two.  Some "
                +"controls along one side probably controll the water level "
                +"and the whirlpool feature.  $&tub_string$&.");
  add_item("tiles","The tiles are perfect and spotless.");
  add_item("sink","Used for washing hands, and brushing teeth.  This one "
                 +"has a faucet and a drain, pretty much like you'd expect.");
  add_item("counter","The counter is one long slab of white-streaked blue "
                    +"marble, except for the cut-out for the sink and faucet.");
  add_item("controls","There are controls to fill and empty the tub, and "
                     +"to activate and deactivate the whirlpool.");
  add_item("toilet","Looks about like you'd expect.");
  add_item("mirror","$&mirror_desc$&");
  add_item("rack","A variety of towels and washcloths hang from the rack, "
                 +"as well as two terrycloth robes.");
                 
  add_exit("bedroom",VILLA+"bedroom");
}
string tub_string() {
  return "The tub is "+(tub_full?"full of hot water":"empty")+", and the "+
         "whirlpool is "+(whirlpool_on?"on":"off");
}
string mirror_desc() {
  string pdesc;
  say(TPN+" admires "+TP->query_possessive()+" reflection in the mirror.\n");
  return "You look in the mirror, and see:\n"+
  ((pdesc=(string)TP->query_description())?pdesc:
    "That you need a description.\n");
}
void init() {
  ::init();
  add_action("cmd_fill","fill");
  add_action("cmd_drain","drain");
  add_action("cmd_activate","activate");
  add_action("cmd_deactivate","deactivate");
}
int cmd_fill(string str) {
  if(!str || str !="tub")
    FAIL("Fill what?\n");
  if(tub_full) {
    write("You run a little more hot water into the tub, to warm it up.\n");
    say(TPN+" runs a little more hot water into the tub.\n");
    return 1;
  }
  write("You fill the tub up with steaming warm water.\n");
  say(TPN+"fills the tub up with steaming warm water.\n");
  tub_full=1;
  return 1;
}
int cmd_drain(string str) {
  if(!str || str !="tub")
    FAIL("Fill what?\n");
  if(!tub_full) {
    write("It's empty already.\n");
    return 1;
  }
  if(whirlpool_on)
    this_object()->cmd_deactivate("whirlpool");
  write("You drain the water out of the tub.\n");
  say(TPN+" drains the water out of the tub.\n");
  tub_full=0;
  return 1;
}
int cmd_activate(string str) {
  if(!str || str!="whirlpool")
    FAIL("Activate what?\n");
  if(whirlpool_on) {
    write("It's already on.\n");
    return 1;
  }
  if(!tub_full) {
    write("You cannot do that while the tub is empty.\n");
    return 1;
  }
  write("You turn the whirlpool on, and the water in the tub begins to \n"+
        "swirl pleasingly.\n");
  say(TPN+" turns on the whirlpool, and the water in the tub begins to swirl\n"+
      "pleasingly.\n");
  whirlpool_on=1;
  return 1;
}
int cmd_deactivate(string str) {
  if(!str || str !="whirlpool")
    FAIL("Activate what?\n");
  if(!whirlpool_on) {
    write("It is already off.\n");
    return 1;
  }
  write("You turn the whirlpool off, and the water stops swirling.\n");
  say(TPN+" turns the whirlpool off, and the water stops swirling.\n");
  whirlpool_on=0;
  return 1;
}
