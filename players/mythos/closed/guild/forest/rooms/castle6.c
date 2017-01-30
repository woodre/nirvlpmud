#include "/sys/ansi.h"
#include "/players/mythos/closed/guild/def.h"
object mon;
int m;
inherit "room/room";
reset(arg) {
 m = 0;
  if(!arg) {
  set_light(0);
    short_desc = HIK+"Forbidden Castle"+NORM+" ["+YEL+"Room of Circles"+NORM+"]";
    long_desc =
    YEL+"You enter a large domes hall.  A large magic circle\n"+
    "is inscribed into the floor.  In the middle of this circle\n"+
    "a bookstand stands.  The walls are covered with strange writings\n"+
    "and pictures.\n"+NORM;
  items = ({
    "west","Leads to the north hall...",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/castle4.c", "west",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    this_player()->set_fight_area();
    if(!pp && tp->is_player()) { 
          tell_object(tp,HIR+"Do NOT venture further!\n"+
                                  "Your life is in danger!\n"+NORM);
          tell_room(this_object(),HIC+"A wind blasts out of nowhere!\n"+NORM);
          mon = clone_object("/players/mythos/closed/guild/forest/mon/nightmare.c");
          move_object(mon,this_object());
          mon->attack_object(tp);
          mon = clone_object("/players/mythos/closed/guild/forest/mon/nightmare.c");
          move_object(mon,this_object());
          mon->attack_object(tp);
          }
    add_action("read","read");
    if(tl >15 && tgl == 7 && pp && qtf > 9) {
    add_action("pplace","place");
    add_action("cchant","chant"); }
}

read(str) {
  if(!str) return 0;
  if(str == "walls" || str == "wall") {
    if(!pp) { write("The writing is gibberish.....\n"); return 1;}
    write("      Om sanmaya satoban om bazaramariya tarata\n");
    return 1;}
}

pplace(str) {
  if(!str) return 0;
  if(str == "lysis") { 
    if(!present("lysis",this_player())) { write("You do not have that.\n"); return 1;}
      command("drop lysis",this_player());
    return 1;}
  if(str == "drakis") { 
    if(!present("drakis",this_player())) { write("You do not have that.\n"); return 1;}
      command("drop drakis",this_player());
    return 1;}
  if(str == "brixon") { 
    if(!present("brixon",this_player())) { write("You do not have that.\n"); return 1;}
      command("drop brixon",this_player());
    return 1;}
  if(str == "cryeo") { 
    if(!present("cryeo",this_player())) { write("You do not have that.\n"); return 1;}
      command("drop cryeo",this_player());
    return 1;}
  if(str == "nex") { 
    if(!present("nex",this_player())) { write("You do not have that.\n"); return 1;}
      command("drop nex",this_player());
      destruct(present("nex",this_object()));
      write("The knife flashes and disappears!\n");
    return 1;}
}

cchant(str) {
  if(!str) return 0;
  if(lower_case(str) == "om sanmaya satoban om bazaramariya tarata") {
  if(present("nex",this_player()) &&
       present("lysis",this_object()) && present("drakis",this_object()) &&
       present("brixon",this_object()) && present("cryeo",this_object())) {
    m = m + 1; }
    else { 
    write("Light flares and something comes!\n");
    mon = clone_object("/players/mythos/closed/guild/forest/mon/nightmare.c");
          move_object(mon,this_object());
          mon->attack_object(tp);
    return 1;}
    if(m > 2) {
      destruct(present("lysis",this_object()));
      destruct(present("brixon",this_object()));
      destruct(present("draxis",this_object()));
      destruct(present("cryeo",this_object()));
      tell_room(this_object(),"Suddenly, the room shakes and everything in the circle vanishes!\n");
      write("You feel odd...\nEverything turns dark and suddenly you find yourself someplace new!\n");
      move_object(this_player(),"/players/mythos/closed/guild/task/8/shaitan.c");
      present("tarrant",environment(this_player()))->set_target(tpn);
      present("tarrant",environment(this_player()))->start();
    return 1;}
    tell_room(this_object(),"The circle glows or a brief second.\n");
    return 1;}
    else {
    return 0; }
return 1;}
