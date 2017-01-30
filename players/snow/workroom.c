#include "std.h"

#define TP this_player()
#define CAP capitalize
#define TPN CAP(TP->query_name())
#define TPRN TP->query_real_name()
#define TO this_object()
#define MO move_object
#define TE tell_object
#define TR tell_room

 int shield, notin;

init() {
  if(TPRN == "snow") {
    add_action("backup_login","cloneall");
  }
   add_action("church","church");
    add_action("lockers","lockers");
    add_action("cyberninja","cyberninja");
  set_light( 1);
}

short() { return "The Citadel of Snow"; }

long() {
  write("\n  This is the Citadel of Snow.\n\n");
  return 1;
}


backup_login() {
  MO(clone_object("/players/snow/closed/dmark.c"),TP);
  MO(clone_object("/obj/mail_reader"),TP);
  return 1;
}

lockers() {
  TR("/players/catwoman/tl.c",TPN+" suddenly arrives.\n");
  MO(TP,"/players/catwoman/tl.c");
  command("look",TP);
  TR(TO,TPN+" left to the lockers.\n");
  return 1;
}

church() {
  TR("/room/church",TPN+" suddenly arrives.\n");
  MO(TP,"/room/church");
  command("look",TP);
  TR(TO,TPN+" left to the church.\n");
  return 1;
}

cyberninja() {
  TR("/players/snow/closed/cyber/rooms/guildhall",TPN+" suddenly arrives.\n");
  MO(TP,"/players/snow/closed/cyber/rooms/guildhall");
  command("look",TP);
  TR(TO,TPN+" left to the CyberNinja guild hall.\n");
  return 1;
}
realm() { return "NT"; }
