#include "/sys/ansi.h"
#include "/players/mythos/closed/guild/def.h"
object mon;
int k1,k2,k3,k4,k5, m1,m2,m3,m4,m5;
inherit "room/room";
reset(arg) {
  k1 = k2 = k3 = k4 = k5 =1;
  m1 = m2 = m3 = m4 = m5 =0;
  if(!arg) {
  set_light(0);
    short_desc = HIK+"Forbidden Castle"+NORM+" ["+YEL+"Room of Knives"+NORM+"]";
    long_desc =
    YEL+"You enter a room of gigantic proportions.  The ceiling is far\n"+
    "above you and the distances are great.  And the walls are covered\n"+
    "with blades of various types and sizes.  Hunting knives, throwing\n"+
    "daggers, machettes, scimitars, broad swords, katanas.  In the middle\n"+
    "of the room is a pedastal- with 5 gleaming knives on it.\n"+NORM;
  items = ({
    "west","Leads to the south hall...",
    "pedastal","There are 5 knives on this.\n"+
               "To take a close look at each type '"+HIC+"inspect #"+NORM+"'",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/castle3.c", "west",
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
    add_action("llook","look");
    add_action("inspect","inspect");
    add_action("ttake","get");
    add_action("ttake","take");
}

inspect(str) {
if(!str || (str && str != "1" && str != "2" && str != "3" && str != "4" &&
    str != "5")) return 0;
    if(str == "1") {
      if(!k1) { 
        write("That is not here right now. Somone must have taken it.\n");
       return 1;}
    write("A blade of purest "+HIW+"crystal"+NORM+" flashes before your eyes.\n"+
          "Deep within the "+HIW+"crystal"+NORM+" a "+HIB+"flame of blue"+NORM+" burns.\n");
    write("The name is "+HIB+"lysis"+NORM+".\n");
    return 1;}
    if(str == "2") {
    if(!k2) { 
        write("That is not here right now. Somone must have taken it.\n");
       return 1;}
    write("The blade of this knife seems formless, the blade shifts \n"+
          "from shape to shape- one second its a "+HIR+"blade of fire"+NORM+", the\n"+
          "next it is a "+HIC+"pick of ice"+NORM+"....\n");
    write("The name is "+HIM+"drakis"+NORM+".\n");
    return 1;}
    if(str == "3") {
    if(!k3) { 
        write("That is not here right now. Somone must have taken it.\n");
       return 1;}
    write(HIC+"A blade of pure magical ice.  The cold aura seems to freeze\n"+
          "everything around it...\n"+NORM);
    write("The name is "+HIC+"brixon"+NORM+".\n");
    return 1;}
    if(str == "4") {
    if(!k4) { 
        write("That is not here right now. Somone must have taken it.\n");
       return 1;}
    write("A dark steel blade.  Magical runes are \n"+
          "etched along its length.\n");
    write("The name is "+BOLD+"cryeo"+NORM+".\n");
    return 1;}
    if(str == "5") {
    if(!k5) { 
        write("That is not here right now. Somone must have taken it.\n");
       return 1;}
    write(HIK+"A blade of some dark material- black as dried "+NORM+RED+"blood"+HIK+".\n"+
          "It has a malicious aura.\n");
    write("The name is "+HIK+HBRED+"nex"+NORM+".\n");
    return 1;}
return 1;}

ttake(str) {
object kn, mo;
  if(!str) return 0;
  if(str == "lysis") { 
    if(!k1) { write("That is not here. Someone must have taken it.\n");
    return 1;}
    if(!m1) { write("A monster appears and attacks you before you can get the knife!\n");
    mo = clone_object("/players/mythos/closed/guild/forest/mon/guard.c");
    mo->set_type("m1");
    move_object(mo,this_object());
    mo->attack_object(this_player());
    return 1;}
    write("You take the blade LYSIS.\n");
    say(capitalize(tpn)+" takes a blade from the pedastal.\n");
    kn = clone_object("/players/mythos/closed/guild/task/8/knife1.c");
    tp->add_weight(kn->query_weight());
    move_object(kn,tp);
    k1 = 0;
  return 1; }
  if(str == "drakis") { 
    if(!k2) { write("That is not here. Someone must have taken it.\n");
    return 1;}
    if(!m2) { write("A monster appears and attacks you before you can get the knife!\n");
    mo = clone_object("/players/mythos/closed/guild/forest/mon/guard.c");
    mo->set_type("m2");
    move_object(mo,this_object());
    mo->attack_object(this_player());
    return 1;}
    write("You take the blade DRAKIS.\n");
    say(capitalize(tpn)+" takes a blade from the pedastal.\n");
    kn = clone_object("/players/mythos/closed/guild/task/8/knife2.c");
    tp->add_weight(kn->query_weight());
    move_object(kn,tp);
    k2 = 0;
  return 1; }
  if(str == "brixon") { 
    if(!k3) { write("That is not here. Someone must have taken it.\n");
    return 1;}
    if(!m3) { write("A monster appears and attacks you before you can get the knife!\n");
    mo = clone_object("/players/mythos/closed/guild/forest/mon/guard.c");
    mo->set_type("m3");
    move_object(mo,this_object());
    mo->attack_object(this_player());
    return 1;}
    write("You take the blade BRIXON.\n");
    say(capitalize(tpn)+" takes a blade from the pedastal.\n");
    kn = clone_object("/players/mythos/closed/guild/task/8/knife3.c");
    tp->add_weight(kn->query_weight());
    move_object(kn,tp);
    k3 = 0;
  return 1; }
  if(str == "cryeo") { 
    if(!k4) { write("That is not here. Someone must have taken it.\n");
    return 1;}
    if(!m4) { write("A monster appears and attacks you before you can get the knife!\n");
    mo = clone_object("/players/mythos/closed/guild/forest/mon/guard.c");
    mo->set_type("m4");
    move_object(mo,this_object());
    mo->attack_object(this_player());
    return 1;}
    write("You take the blade CRYEO.\n");
    say(capitalize(tpn)+" takes a blade from the pedastal.\n");
    kn = clone_object("/players/mythos/closed/guild/task/8/knife4.c");
    tp->add_weight(kn->query_weight());
    move_object(kn,tp);
    k4 = 0;
  return 1; }
  if(str == "nex") { 
    if(!k5) { write("That is not here. Someone must have taken it.\n");
    return 1;}
    if(!m5) { write("A monster appears and attacks you before you can get the knife!\n");
    mo = clone_object("/players/mythos/closed/guild/forest/mon/guard.c");
    mo->set_type("m5");
    move_object(mo,this_object());
    mo->attack_object(this_player());
    return 1;}
    write("You take the blade NEX.\n");
    say(capitalize(tpn)+" takes a blade from the pedastal.\n");
    kn = clone_object("/players/mythos/closed/guild/task/8/knife5.c");
    tp->add_weight(kn->query_weight());
    move_object(kn,tp);
    k5 = 0;
  return 1; }
}

llook(str) {
  if(!str) { this_player()->look(); return 1;}
  if(str == "at pedastal") {
  write("There are 5 knives on this.\n"+
        "To take a close look at each type 'inspect #'\n");
  return 1;}
}

set_m1() { m1 = 1;}
set_m2() { m2 = 1;}
set_m3() { m3 = 1;}
set_m4() { m4 = 1;}
set_m5() { m5 = 1;}
