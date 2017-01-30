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
int anchor, protect;

init() {
  if(TPRN == "snow") {
  add_action("room_commands","room");
    add_action("shield_commands","shield");
    add_action("backup_login","cloneall");
  }
   add_action("church","church");
   add_action("hotel","hotel");
    add_action("lockers","lockers");
    add_action("cyberninja","cyberninja");
  set_light( 1);
  if(TPRN != "snow" && shield == 1) {
    write("You are not desired here right now.\n");
    TR("/room/church",CAP(TPRN)+" is deposited in a heap.\n");
    move_object(TP,"/room/church");
  }
}

short() { return "The Citadel of Snow"; }

long() {
  write("\n  This is the Citadel of Snow.\n\n");
  return 1;
}

room_commands(string str) {
  if(!str) { notify_fail("Relative: anchor , protect\n"); return 0; }
  if(str == "anchor") { room_anchor(); return 1; }
  if(str == "protect") { room_protect(); return 1; }
}
shield_commands(str) {
  if(!str) {
    if(shield == 1) {
      write("Shield Status: ON\n");
    }
    if(shield != 1) {
      write("Shield Status: OFF\n");
    }
    return 1;
  }
  if(str == "on") {
    shield = 1;
    write("Shield Status: ON\n");
    return 1;
  }
  if(str == "off") {
    shield = 0;
    write("Shield Status: OFF\n");
    return 1;
  }
  write("Shield <"+str+"> is not a valid command.\n");
  return 1;
}

backup_login() {
  MO(clone_object("/players/snow/closed/mark.c"),TP);
  MO(clone_object("/players/snow/closed/binder.c"),TP);
  MO(clone_object("/players/snow/closed/qt.c"),TP);
  MO(clone_object("/players/snow/closed/tbolt.c"),TP);
  MO(clone_object("/obj/mail_reader"),TP);
  return 1;
}

hotel() {
  TR("/players/boltar/hotel/hotel",TPN+" suddenly appears.\n");
  MO(TP,"/players/boltar/hotel/hotel");
  command("look",TP);
  TR(TO,TPN+" left to the hotel.\n");
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
  TR("/players/dune/closed/guild/rooms/guildhall",TPN+" suddenly arrives.\n");
  MO(TP,"/players/dune/closed/guild/rooms/guildhall");
  command("look",TP);
  TR(TO,TPN+" left to the CyberNinja guild hall.\n");
  return 1;
}

room_anchor() {
  if(anchor) {
    write("Room anchor: OFF\n");
    remove_call_out("room_anchor");
    anchor = 0;
    return 1;
  }
  call_out("anchoring",3);
  write("Room anchor: ON\n");
  anchor = 1;
  return 1;
}
 
anchoring() {
  object me;
  me = find_player("snow");
  if(!me) return 1;
  call_out("anchoring",3);
  if(environment(me) != this_object()) {
    move_object(me,this_object());
    write("[ANCHOR] -> returned to Citadel.\n");
    command("look",me);
    return 1;
  }
  return 1;
}
 
room_protect() {
  if(protect) {
    write("Protect Inventory: OFF\n");
    remove_call_out("protect_inventory");
    protect = 0;
    return 1;
  }
  write("Protect Inventory: ON\n");
  protect = 1;
  protect_inventory();
  return 1;
}
 
protect_inventory() {
  string qt, mark, imp;
  object all;
  int i;
  qt = "/players/snow/closed/qt.c";
  mark = "/players/snow/closed/dmark.c";
  imp = "/players/dune/closed/guild/implants.c";
  all = all_inventory(find_player("snow"));
  for(i=0; i < sizeof(all); i++) {
    if(file_name(all[i]) != qt    &&
      file_name(all[i]) != mark   &&
      file_name(all[i]) != imp    &&
       file_name(all[i]) != "closed/wiz_soul" ) {
      tell_object(find_player("snow"),
        "PROTECT->["+file_name(all[i])+"] found and destroyed.\n");
      destruct(all[i]);
    }
  }
  call_out("protect_inventory",20);
  return 1;
}
