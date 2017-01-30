
#include "/players/boltar/things/esc.h"

short()
{
string stat;
if (call_other("players/boltar/motel/front_desk","query_vac",0))
stat = esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[31m"+esc+"[40m(vacancy)"+esc+"[0m";
  else
stat = esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[31m"+esc+"[40m(NO vacancy)"+esc+"[0m";
  return "The One Night Stand Motel "+stat+" is to the east";
}

query_value()
{
        return 3;
}

  query_weight() {   return 200; }
long()
{
   write("The motel is a long single-story wood frame building that is \n"+
    "placed with the end towards the road. The motel is run down and a\n"+
    "blinking neon sign delcares the name and points to the office.\n"+
    "The motel is dark, creepy, and reminds one of the place Norman Bates\n"+
    "once ran.\n");
}

init() {
  add_action("east","east");
}



get() {
    return 0;
}
id(str) { return str=="motel"; }
 east() {
 call_other(this_player(), "move_player","east#players/boltar/motel/front_desk.c");
   return 1;
}
is_castle() {return 1;}
