inherit "room/room";
#define SAVE "players/snow/closed/cyber/tournaments/tourney"
#define RN this_player()->query_real_name()
#define TE tell_object
#define TR tell_room
#define TP this_player()
#define TPN capitalize(TP->query_name())

string name;
string sstatus;
string dead;
string type;
string draw;
string notes;
string writingdraw;
string writingnotes;
int cost, on;

init() {
  restore_me();
  add_action("enter_arena","enter");
  add_action("register","register");
  add_action("info","info");
  add_action("tourneyhelp","tourneyhelp");
  add_action("signup","signup");
  add_action("draw","draw");
  add_action("display","display");
  if(IP(TP)) {
  if(IP(TP)->referee() ||
     IP(TP)->head_referee() ||
     IP(TP)->regent()  || RN == "dune"           ||
     RN == "snow") {
     add_action("entries","entries"); }
  if(IP(TP)->head_referee() || IP(TP)->regent() ||
     RN == "dune" || RN == "snow") {
     add_action("tournament_name","tournament_name");
     add_action("tournament_status","tournament_status");
     add_action("tournament_deadline","tournament_deadline");
     add_action("tournament_cost","tournament_cost");
     add_action("tournament_type","tournament_type");
     add_action("tournament_notes","tournament_notes");
     add_action("tournament_draw","tournament_draw"); }
  }
  ::init();
    if(TP->query_ghost()) {
    write("Ghosts are not allowed here.\n");
    move_object(TP, "/players/snow/closed/cyber/rooms/hallway2.c");
    return 1; }
  }

reset(arg){
 if(!arg){
 set_light(1);
 short_desc="The CyberNinja Arena Lounge";
 long_desc=
"     This room is a comfortable players' lounge.  It is designed\n"+
"for watching the arena action.  A panel lies under the arena display.\n"+
"Upon the arena desk in the center of the room lies the tournament\n"+
"sign up sheet.\n";

items=({
 "arena", "The huge arena is blocked off by thick perma-windows",
 "desk","This is the Head Referee's tournament desk",
 "panel","The arena display may be turned on/off by 'display <on/off>'",
 "sheet","Type 'register' to learn more about tournament sign-up",
 });

  dest_dir=({
 "/players/snow/closed/cyber/rooms/hallway2.c","east",
      });
 }
}

display(string str) {
  if(!str) {    write("Usage: display <on/off>\n");
    return 1; }
  if(str == "off") {
    if(!on) {
      write("The arena display is already off.\n");
      return 1; }
    on = 0;
    TR("/players/snow/closed/cyber/rooms/arenalounge.c",
       capitalize(this_player()->query_name())+
       " turns the arena display off.\n");
    return 1; }
  if(str == "on") {
    if(on) {
      write("The arena display is already on.\n");
      return 1; }
    on = 1;
    TR("/players/snow/closed/cyber/rooms/arenalounge.c", 
       capitalize(this_player()->query_name())+
       " turns the arena display on.\n");
    return 1; }
  return 0;
}

incoming(string message) {
  if(on) {
    TR("/players/snow/closed/cyber/rooms/arenalounge.c", message);
    return 1;
    }
}

save_me() {
  string file;
  file = SAVE;
  if(!save_object(file)) {
    tell_object(TP,"Tournament info error...\n");
    return 0;}
  return 1;}

restore_me() {
  string file;
  file = SAVE;
  if(!restore_object(file)) {
    tell_object(TP,"Tournament info error...\n");
    return 0;}
  return 1;}

object IP(object ob) {
/* This function is similar to a #define, it just
 * returns the guild object on the player specified.
 */
   object guild_object;
   guild_object = present("implants", ob);
   return guild_object;
}

enter_arena(str) {
  if(!str) { write("Enter what?\n"); return 1; }
  if(str == "arena") {
    if(!TP->query_pl_k()) {
      write("You must type 'kill_players spar' before you can enter\n"+
       "the CyberNinja Arena.\n");  return 1; }
    write("You enter the CyberNinja Arena...\n");
    say(TP->query_name()+" enters the CyberNinja Arena...\n");
    move_object(TP, "/players/snow/closed/cyber/rooms/arena.c");
    command("look",TP);
    return 1; }
}

register() {
  string gender, gen;
  gender = TP->query_gender();
  if(gender == "male") gen = "his";
  if(gender == "female") gen = "her";
  if(gender == "creature") gen = "its";
  TE(TP,
"CYBERNINJA TOURNAMENTS\n"+
"___________________________________________________________\n"+
"info.........................see the latest tournament info\n"+
"signup.......................sign up for the latest tournament\n"+
"draw.........................see seedings and draw, if posted yet\n"+
"tourneyhelp..................learn more about guild tournaments\n");
  if(!IP(TP)) return 1;
  if(IP(TP)->regent() || RN == "dune" || RN == "snow" ||
     IP(TP)->head_referee()           || IP(TP)->referee()) {
     TE(TP,
"entries......................see the list of entries\n");
     }
  if(IP(TP)->regent() || RN == "dune" || RN == "snow" ||
     IP(TP)->head_referee()) {
     TE(TP,
"tournament_name <name>.......set the tournament name\n"+
"tournament_status <status>...set the tournament status\n"+
"tournament_deadline <date>...set the tournament deadline\n"+
"tournament_cost <amount>.....set the tournament cost (in credits)\n"+
"tournament_type <type>.......set the tournament type\n"+
"tournament_notes.............add in some notes about the tournament\n"+
"tournament_draw..............set up the tournament draw\n");
     }
  TE(TP,
"___________________________________________________________\n");
  tell_room(TP, TP->query_name()+" registers "+gen+" name.\n");
  return 1;
}

set_tourney_name(string new) { name = new; }
string query_tourney_name() { return name; }
set_tourney_status(string new) { sstatus = new; }
string query_tourney_status() { return sstatus; }
set_tourney_deadline(string new) { dead = new; }
string query_tourney_deadline() { return dead; }
set_tourney_cost(int new) { cost = new; }
int query_tourney_cost() { return cost; }
set_tourney_type(string tip) { type = tip; }
string query_tourney_type() { return type; }
set_tourney_draw(string new) { draw = new; }
string query_tourney_draw() { return draw; }
set_tourney_notes(string new) { notes = new; }
string query_tourney_notes() { return notes; }

info() {
  if(name == "none") {
    write("There is no tournament up right now.\n");
    return 1; }
  write("Current Tournament Info....\n");
  write("**********************************************\n");
  write("Name: "+name+"\n");
  write("Deadline: "+dead+"\n");
  write("Cost: "+cost+"\n");
  write("Type: "+type+"\n");
  write("Status: "+sstatus+"\n");
  if(notes) write("Extra Notes....\n");
  if(notes) write(notes+"\n");
  write("**********************************************\n");
  return 1;
}

tourneyhelp() {
  write(
"     For more info, type 'cyber tournaments'.\n"+
"All tournaments have the following characteristics:\n"+
"     Name, this is the name of the tournament.\n"+
"     Deadline, this is the last date that you can sign up for\n"+
"           for the given tournament.  Entries past the\n"+
"           deadline may not be accepted.\n"+
"     Cost, tournaments which cost money will have an entry\n"+
"           fee.  This fee pays for prizes.  The larger the\  Distribution of\n"+
"           money varies with each tournament.  Prizes are\n"+
"           distributed by Emperor or Regent.\n"+
"     Type, tournaments are divided into 4 types...\n"+
"           1) Satellite, these are minor tournaments.  Usually no prizes\n"+
"           2) Challenger, these are moderate size tournaments.\n"+
"           3) Open, these are large tournaments which will\n"+
"                offer a substantial prize.  Competition is tough.\n"+
"           4) Grand Slam, these are very large tournaments which\n"+
"                take much preparation and allow time for\n"+
"                many entrants.  Competition is fierce, prizes big.\n"+
"     Status, this can be either of 3 stages...\n"+
"             'tournament over', 'accepting entries', or 'setting up'\n"+
"     Notes, any special notes which may apply to tournaments\n");
  return 1;
}

signup() {
  int credits, diff;
  if(name == "none") {
    write("There is no tournament up right now.\n");
    return 1; }
  if(sstatus != "accepting entries") {
    write("You cannot sign up for the tournament right now.\n");
    return 1; }
  credits = IP(TP)->balance();
  if(credits < cost) {
    diff = cost - credits;
    write("You are short "+diff+" @'s.\n");
    write("You cannot pay the entry fee.\n");
    return 1; }
  IP(TP)->addToBalance(-cost);
  IP(TP)->save_me();
  write("You sign your name up for the "+name+" tournament.\n");
  say(TPN+" signs up for the "+name+" tournament.\n");
  write_file("/players/dune/closed/guild/tournaments/entries",
    TPN+" -> "+name+" tournament. ("+cost+" @'s)  ["+ctime()+"]\n");
  return 1;
}

draw() {
  if(name == "none") {
    write("There is no tournament up right now.\n");
    return 1; }
  if(!draw) {
    write("There is no draw yet.\n");
    return 1; }
  write("You look at the draw....\n");
  write(draw+"\n");
  return 1;
}

entries() {
  call_other("/players/dune/closed/guild/_more.c",
    "more_file",
    "/players/dune/closed/guild/tournaments/entries");
  return 1;
}

tournament_name(string str) {
  if(!str) {
    write("Name the tournament whatever you want.\n");
    return 1; }
  set_tourney_name(str);
  write("You set the current tournament name to: "+str+".\n");
  save_me();
  return 1;
}

tournament_status(string str) {
  if(!str) {
    write(
"Choices are: 'tournament over', 'accepting entries', or 'setting up'\n");
    return 1; }
  str == lower_case(str);
  if(str == "tournament over" || str == "accepting entries" ||
     str == "setting up") {
     set_tourney_status(str);
     write("You set the current tournament status to: "+str+".\n");
     save_me();
     return 1; }
  write(
"Choices are: 'tournament over', 'accepting entries', or 'setting up'\n");
  return 1;
}

tournament_deadline(string str) {
  if(!str) {
    write("Example: December 31, 1999 at 12:00 pm Pacific Standard Time\n");
    return 1; }
  set_tourney_deadline(str);
  write("You set the current tournament deadline to: "+str+".\n");
  save_me();
  return 1;
}

tournament_cost(string strnum) {
  int num;
  if(!strnum) {
    write("You must specify the entry fee.\n");
    return 1; }
  if(!sscanf(strnum, "%d", num)) {
     write("The entry fee must be a number.\n");
     return 1; }
  if(num < 0) {
    write("Negative entry feee?  I don't think so.\n");
    return 1; }
  set_tourney_cost(num);
  write("You set the current tournament cost to: "+num+".\n");
  save_me();
  return 1;
}

tournament_type(string str) {
  if(!str) {
    write(
"Choices are: 'Satellite', 'Challenger', 'Open', and 'Grand Slam'\n");
    return 1; }
  str = lower_case(str);
  if(str == "satellite" || str == "challenger" || str == "open" ||
     str == "grand slam") {
    set_tourney_type(str);
    write("You set the current tournament type to: "+str+".\n");
    save_me();
    return 1;
    }
  write(
"Choices are: 'Satellite', 'Challenger', 'Open', and 'Grand Slam'\n");
  return 1;
}

tournament_draw() {
  write("Enter draw. End with '**', abort with '~q'.\n");
  write("__________________________________________________________\n");
  writingdraw = "";
  input_to("get_draw");
  return 1;
}

get_draw(string str) {
  if (str == "~q") {
    write("aborted.\n");
    return 1; }
  if (str=="**") {
    write("Ok.\n");
    draw = writingdraw;
    say(TPN+" has put up the draw.\n");
    save_me();
    return; }
  writingdraw = writingdraw + str + "\n";
  input_to("get_draw");
}

tournament_notes() {
  write("Enter notes. End with '**', abort with '~q'.\n");
  write("__________________________________________________________\n");
  writingnotes = "";
  input_to("get_notes");
  return 1;
}

get_notes(string str) {
  if (str == "~q") {
    write("aborted.\n");
    return 1; }
  if (str=="**") {
    write("Ok.\n");
    notes = writingnotes;
    save_me();
    return; }
  writingnotes = writingnotes + str + "\n";
  save_me();
  input_to("get_notes");
}
