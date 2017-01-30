#include "/players/mythos/closed/guild/def.h"
#define SAVE "players/mythos/closed/guild/orb_check"
static object ob, ob2,book;
int check;
int mending;

short() {
  string shr;
  shr = allocate(18);
  shr[0]="Shrine Center [n,e,s,w]";
  shr[1]="Smithy [n]";
  shr[2]="Forest [n,e,s,w]";
  shr[3]="Forest Pathway4 [se]";
  shr[4]="Library Entrance [portal,n]";
  shr[5]="The Post Office [n,s]";
  shr[6]="Village Church";
  shr[7]="Village Church";
  shr[8]="Village Church";
  shr[9]="Village Church";
  shr[10]="Just for Kicks [n,s]";
  shr[11]="Just for Kicks [w,e]";
  shr[12]="The adventurers guild";
  shr[13]="The stomach [throw_up,s,blood]";
  shr[14]="BGC Tokyo [n,w,s]";
  shr[15]="Village road [west,east,south,north]";
  shr[16]="Jetty [w,e]";
  shr[17]="City of Ryllian [n,e,s,w]";
  return shr[random(18)];
}

long() {
  write("You have entered the assembly hall of the guild\n"+
        "Darkness shrouds this room and sounds are deadened.\n");
  write("The guild board is in the storage room.\n");
  write("You may go: hall <back to the hall> or room <personal quarters>\n"+
        "            storage <storage room>\n");
}

reset(arg) {
if(!present("sands",this_object()) || !present("book",this_object())) {
  book = clone_object("/players/mythos/closed/guild/books/book.c");
  book->set_cond(0);
  book->set_title("sands");
  book->set_last(8);
  book->set_not(0);
  move_object(book,this_object());
}
   if(!present("dymon")) {
    move_object(clone_object("/players/braxana/horlach/mon/min_demon.c"),this_object()); }
  if(present("dymon")) {  present("dymon")->set_perception(200);
     present("dymon")->set_aggressive(100); }
if(arg) return;
if(!restore_object(SAVE)) { check = 0; mending = 0; save_object(SAVE); }
if(!present("black_orb")) {
  if(check)
   move_object(clone_object("/players/mythos/closed/guild/orb2.c"),this_object());
  if(!check)
   move_object(clone_object("/players/mythos/closed/guild/orb.c"),this_object());
}
set_light(-2);
}

realm() { return "NT"; }
init() {
  this_player()->set_fight_area();
  if(pp) { pp->set_defence(1);}
  add_action("hall","hall");
  add_action("room","room");
  add_action("storage","storage");
}

hall() {
  MV,"north#players/mythos/closed/guild/hall.c");
return 1;}

room() {
  if(present("black_orb",tp)) { command("drop black_orb",tp);}
  if(tp->query_level() < 20)
   if(!random(3)) { write("Something holds you back......\n"); return 1; }
  if(tgl > 3) {
  ob = clone_object("/players/mythos/closed/guild/rooms.c");
  ob->restore_owner("players/mythos/closed/guild/room/"+tpn);
  ob->set_owner(tpn);
  move_object(tp,ob);
  write("You enter your quarters.\n");
  say(capitalize(tpn)+" vanishes into the personal quarters.\n");
  command("look",tp);
  return 1;}
  MV,"room#players/mythos/closed/guild/novice.c");
return 1;}

storage() {
if(present("black_orb",tp)) { command("drop black_orb",tp);}
  MV,"storage#players/mythos/closed/guild/storage.c");
return 1;}
