

short()
{
  return "The Hotel Time and Space is to the east";
}

query_value()
{
        return 3;
}

  query_weight() {   return 200; }
long()
{
    write("The sign on the grand old hotel reads: The Hotel Time and Space.\n"+
     "It's a wood and brick structure, the first floor brick, the upper \n"+
     "ones in wood. The once colorful paint scheme is faded and peeling.\n");
}

init() {
  add_action("east","east");
}



get() {
    return 0;
}
id(str) { return str=="hotel"; }
 east() {
 call_other(this_player(), "move_player", "east#players/boltar/hotel/hotel.c");
   return 1;
}
is_castle() {return 1;}
