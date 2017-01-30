

int entered, paid;
string castle, where;
id(str) { return str == "taxi" || str == "cab"; }

short() { return "A yellow taxi cab"; }

long(){
    if(environment(this_player()) != this_object()) {
    write("A yellow taxi that will take you to the differnt castle.\n"+
          "of Nirvana.  Just 'enter taxi' .\n");
   } else {
    write("You see the cabby sitting in front.\n"+
          "Chances are he doesn't speak english, but you can see a 'list'\n"+
          "of places on his rout.  Then just 'say to <destination>.\n");
    }
   return 1;
}

take() { return 1; }

realm() { return "NT"; }

reset(arg) {
  if(arg)
    move_object(this_object(), "room/vill_green");
  set_heart_beat(1);
}
init() {
    paid=1;
    add_action("enter","enter");
    add_action("leave","leave");
    add_action("pay","pay");
    add_action("transfer","say");
    add_action("dests","list");
}

enter(str) {
   if(!str) { write("What?\n"); return 1; }
    if(str != "taxi"){write("Enter what?\n"); return 1; }
   if(entered == 1){ write("There is already someone in the cab.\n"); return 1;}
    move_object(this_player(), this_object());
   say(capitalize(this_player()->query_real_name())+" enters the cab.\n");
    command("look", this_player());
    entered=1;
   return 1;
}
leave(str) {
   if(!str){write("What?\n"); return 1; }
    if(str != "taxi"){write("Leave what?\n"); return 1; }
   if(paid != 1){ write("The cabby screams: WHAT! You better pay me first!\n");
     return 1; }
   move_object(this_player(), environment(this_object()));
   write("The cabby says: Thank yo, and have a nice day.\n");
   command("look", this_player());
  entered=0;
  paid=0;
   return 1;
}

is_castle(){return 0;}
transfer(str) {
   if(environment(this_player()) != this_object()) return 0;
  if(!str || sscanf(str,"to %s",where) !=1) {
    write("The cabby asks: Wherba dois you wiiiish to be going?\n");
    return 1;
  }
  write("Traffic is pretty bad, and you are stuck now,\n"+
        "Might as well 'pay cabby' now.  Maybe you'll\n"+
        "get there alive.\n");
  if(where == "train") castle="players/lew/castle";
  if(where == "house") castle="players/boltar/castle";
  if(where == "well") castle="players/sandman/castle";
  if(where == "realms") castle="players/glaendor/castle";
  if(where == "airport") castle="players/vulture/castle";
  if(where == "portal") castle="players/persephone/castle";
  if(where == "trail") castle="players/pavlik/castle";
  if(where == "1953") castle="players/hawkeye/castle";
  if(where == "hole") castle="players/sweetness/castle";
  if(where == "cavern") castle="players/scathe/castle";
  if(where == "keep") castle="players/molasar/castle";
  if(where == "path") castle="players/catwoman/castle";
  if(where == "jungle book") castle="players/bagera/castle";
  if(where == "jello") castle="players/mizan/castle";
  paid=0;
  call_out("move",15);
  return 0;
}

move() {
   move_object(this_object(), environment(castle));
   tell_room(this_object(), "You barely arrive at your destination.\n");
   tell_room(environment(this_object()), "A yellow taxi comes to screechin halt.\n");
    call_out("back",20);
   return 1;
}
back() {
    tell_room(environment(this_object()), "The cab squeals its tires as it heads to its main\n"+
          "pick-up point.\n");
  move_object(this_object(), "room/vill_road2");
  tell_room("room/vill_green", "The taxi returns.\n");
}
pay(str) {
  if(!str) {
   write("Pay who?\n"); return 1; }
  if(str != "cabby") {
   write("Pay who?\n"); return 1; }
  if(this_player()->query_money()<50){
    write("The cabby is outraged that you do not have the money.\n"+
          "So he does somethings very mean.  He dumps you off back\n"+
          "where he got you.\n");
    move_object(this_player(), "room/vill_green");
    return 1; }
  write("The cabby smiles as he ripps you off.\n");
  call_other(this_player(), "add_money", random(50));
  paid = 1;
  return 1;
}
dests() {
  if(environment(this_player()) == this_object()){
  write("The list is the following:\n"+
"-----------------------------------------------------------------\n"+
"The big House (Boltar's)           say to house\n"+
"In the well (Sandman's)            say to well\n"+
"The El Train (Lew's)               say to train\n"+
"The Ultra Realms (Glaendor's)      say to realms\n"+
"Nirvana International (Vulture)    say to airport\n"+
"The Portal (Persephone)            say to portal\n"+
"A rocky trail (Pavlik)              say to trail\n"+
"1953 (Hawkeye)                      say to 1953\n"+
"A hole (Sweetness)                  say to hole\n");
write(
"A cavern (Scathe)                   say to cavern\n"+
"The keep (Molasar)                  say to keep\n"+
"A path to the east (Catwoman)       say to path\n"+
"Jungle Book (Bagera)                say to jungle book\n"+
"A Tub of Jello (Mizan)              say to jello\n"+
"-----------------------------------------------------------------\n");
write("The list is currently incomplete.\n"+
      "Wizzes please write me (Lew) so i may add your castle\n"+
      "to the list.\n");
return 1;
}
return;
}

heart_beat(){
    string here;
    int talk,chance;
    talk = random(3);
    here=environment(this_object());
   if(entered == 0){
   if(random(100) < 10 ) {
    if(talk == 1 ) {
      tell_room(here, "A cabby jumps out in front of you.\n"); return 1; }
    if(talk==2){
      tell_room(here, "A cabby says:  Ifn you be needin a lift,\n"+
           "A cabby says:  Ibe can be takink yous to most ob de castles\n");
      return 1; }
   if(talk==3){
      tell_room(here, "A cabby says:  Be needing lift?\n"); return 1;}
}
}
}
