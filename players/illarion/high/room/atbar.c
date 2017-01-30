#pragma strict_types
inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  if(!present("Joe Dawson",this_object()));
    move_object(HMON+"joe",this_object());
  if(arg) return;
  
  set_light(1);
  set_short("At the bar in Joe's place");
  set_long("\
A long wooden bar complete with a long brass pipe stands on the floor \
here, in front of a typical bartender's area, with the usual machines, \
containers, and other objects behind and under the bar.  A few stools \
have been placed here for patrons that don't prefer the tables.  \
To the west is the main floor of the bar, and behind the bar is \
a door to the east.");

  add_item("bar","A long wooden counter that drinks are served over.");
  add_item("pipe","A hollow cylinder of brass for people to hook their\n"+
                  "feet under while sitting on the stools.");
  add_item("area","The place behind the bar that the bartender frequents.");
  add_item("machines","Machines for making, stirring, and otherwise\n"+
                      "constructing drinks.");
  add_item("containers","Glasses, jars, bottles, even a few vials.\n");
  add_item("objects","Napkins, containers for condiments and snacks, and\n"+
                     "other things.");
  add_item("stools","Four-legged, and padded.");
  add_item("door","A simple wooden door.");
  add_item("menu","There's writing on it you might want to take a look at.");

  add_exit("west",HROOM+"bar");
  add_exit("east",HROOM+"wroom");
}
void init() {
  ::init();
  add_action("cmd_read","read");
  add_action("cmd_order","order");
  add_action("cmd_order","buy");
  add_action("cmd_door","east");
}
int cmd_read(string str) {
  if(!str || str != "menu") FAIL("Read what?\n");
  write(BLD("Beer")+"........................10\n"); /* heal=1, intox=3 */
  write(BLD("Import")+"ed Beer...............60\n"); /* heal=3, intox=5 */
  write(BLD("Shot")+" of Liquor.............252\n"); /* heal=14, intox=7 */
  write(BLD("Long shot")+" of Liquor........375\n"); /* heal=25, intox=9 */
  write(BLD("Special")+" mix................403\n"); /* heal=31, intox=11 */
  write("Joe's "+BLD("Brew")+".................500\n"); /* heal=50, intox=14 */
  return 1;
}
int cmd_order(string str) {
  string name;
  int heal,intox,cost;
  object ob,bartender;
  if(!str) FAIL("Order what?\n");
  if(!(bartender=present("Joe Dawson",this_object()))) {
    write("There is no one here to serve the drinks.\n");
    return 1;
  }
  switch(str) {
    case "beer":
      name=" a beer";
      heal=1; intox=3; cost=10;
      break;
    case "import": case "imported beer":
      name=" an imported beer";
      heal=3; intox=5; cost=60;
      break;
    case "shot":
      name=" a shot of liqour";
      heal=14; intox=7; cost=252;
      break;
    case "long shot": case "long":
      name=" a long shot of liquor";
      heal=25; intox=9; cost=375;
      break;
    case "special":
      name=" a special mix";
      heal=31; intox=11; cost=403;
      break;
    case "brew":
      name=" his special brew";
      heal=50; intox=14; cost=500;
      break;
    default:
      tell_room(this_object(),"Joe says, \"We don't serve that here.\"\n");
      return 1;
  }
  ob=this_player();
  tell_room(this_object(),ob->query_name()+" asks Joe for"+name+".\n",
    ({ob,bartender}));
  tell_object(ob,"You ask Joe for"+name+".\n");
  if((ob->query_level()+1) < intox) {
    tell_room(this_object(),"Joe says, \"Sorry, "+
      ((string)ob->query_gender()=="male"?
      "pal":"lady")+", but that's a bit strong for you.\n");
    return 1;
  }
  if(ob->query_money()<cost) {
    tell_room(this_object(),"Joe says, \"Sorry, but I don't give credit.\"\n");
    return 1;
  }
  if(ob->drink_alcohol(intox)==0) {
    tell_room(this_object(),"Joe says, \"Listen, "+ob->query_name()+
    ", I think you've had enough.  Go home.\"\n");
    return 1;
  }
  tell_room(this_object(),
    "Joe gives"+name+" to "+ob->query_name()+", who drinks it down.\n",
    ({ob,bartender}));
  tell_object(ob,
    "Joe serves you"+name+", and you drink it down.\n");
  tell_object(ob,"You spot an odd, old-looking symbol tattood on his wrist.\n");
  ob->add_money(-cost);
  ob->heal_self(heal);
  return 1;
}
int cmd_door() {
  object ob;
  if((ob=present("Joe Dawson",this_object()))) {
    if(present("watcher_amulet",TP)) {
      write("Joe inspects your amulet and lets you pass.\n");
      say("Joe looks at something "+TPN+" has, and allows "+
          TP->query_objective()+" into the back room.\n");
      return 0;
    }
    write("Joe stands in your way, saying, \"Employees only.\"\n");
    say("Joe stops "+TPN+" from entering the back room.\n",({ob,TP}));
    return 1;
  }
  return 0;
}
