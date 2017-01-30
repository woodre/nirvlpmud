#include "/players/mythos/closed/guild/def.h"
object tt;
int check;
inherit "room/room";
reset(arg) {
  check = 0;
  if(!arg) {
  set_light(-3);
    short_desc = "Dark Chamber ";
    long_desc =
    "You step into a different world...  The Fae swirls at your\n"+
    "feet and the darknss sooths you.  This chambr is a large chamber\n"+
    "decoratd with gems of great value- emeralds, rubies, diamonds, fire\n"+
    "gems, and deathcloaks.  In the center of the chamber sits a throne\n"+
    "of great beauty.  Runes cover it and Power radiates from it.\n"+
    "The only exit is leave.\n";
  items = ({
    "leave","Leads out to the river",
    "throne","You examine the throne and read the runes on it\n"+
             "Runes: Know that He who sits on Me must know the\n"+
             "       Words of the Codex or forevermore be damned",
  });
} }

realm() { return "NT"; }

set_check(n) { check = n; }

init() {
 ::init();
 if(!pp) { write("Suddenly something rips through your soul!\n");
           tp->move_player("into the Nether Void#room/void.c");
           tp->hit_player(1000);
           return 1;}
 if(check) { 
  write("You may not enter the chamber for someone is already there.\n");
  tp->move_player("off a magical shield#players/mythos/closed/guild/task/hills/under.c");
  return 1;}
 else { check = 1; }
 add_action("dive","enter");
 add_action("ssit","sit");
 add_action("qqquit","quit");
}

qqquit() { check = 0; }

dive() {
 check = 0;
  tp->move_player("out to the river#players/mythos/closed/guild/task/hills/under.c");
return 1;}

ssit(str) {
  if(!str) return 0;
  if(str == "on throne" || str == "throne") {
    tt = tp;
    call_out("test",6);
  }
return 1;}

test() {
  tell_object(tt,"Suddenly, the room turns dark.\n"+
                 "Dark things flitter at the edge of your vision.\n"+
                 "Odd sounds are heard and feear grips you!\n");
  call_out("test2",6);
return 1;}

test2() { 
  tell_object(tt,"\n");
return 1;}
