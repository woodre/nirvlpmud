/* Setup room for ChAoS realm */

#include "std.h"
#include "/players/snow/chaos/defs.h"

short() { return "ChAoS base room"; }
long(str) {
  write("This is the ChAoS room model. You may wander around.\n");
  write("There is a swing and chair here. 'jumpout' to leave.\n");
}

realm() { return "NT"; }
query_chaos() { return "devour"; }

reset(arg) {
  if(arg) return;
  call_out("wandering",20);
}

init() {
this_player()->set_fight_area();
  set_light(1);
  add_action("chaos_cmds","chaos");
  add_action("chaos_voice","voice");
  add_action("chaos_move","north");
  add_action("chaos_move","south");
  add_action("chaos_move","east");
  add_action("chaos_move","west");
  add_action("chaos_move","northeast");
  add_action("chaos_move","northwest");
  add_action("chaos_move","southeast");
  add_action("chaos_move","southwest");
  add_action("jump_out","jumpout");
}

exit() { this_player()->clear_fight_area(); }
 
chaos_cmds(str) {
  if(!str) { chaos_help(); RE; }
  if(str == "who") { chaos_who(); RE; }
}

chaos_help() {
    TE(TP,"....----ChAoS----....\n\n");
  TE(TP,"....chaos........This menu.\n");
  TE(TP,"....jumpout......Leave ChAoS.\n");
  TE(TP,"....chaos who....Who's in ChAoS.\n");
  TE(TP,"....voice........Tell to everyone in ChAoS.\n\n");
  TE(TP,"....----ChAoS----....\n");
  RE;
}
chaos_who() {
  object ob;
  int i;
  ob = users();
  TE(TP,"* ^ > < ^ * ^ > < ^ * ^ > < ^ *\n\n");
  for( i = 0; i < sizeof(ob); i += 1 ) {
  if(ENV(ob[i])->query_chaos() == "devour") {
    if(ob[i]->query_invis() < TP->query_level()) {
      TE(TP,"!! "+ob[i]->query_name()+"\n");
    }
  }
  }
  TE(TP,"\n* ^ > < ^ * ^ > < ^ * ^ > < ^ *\n");
  RE;
}

chaos_voice(str) {
  object ob;
  int i;
  ob = users();
  for( i = 0; i < sizeof(ob); i++ ) {
    if(ENV(ob[i])->query_chaos() == "devour") {
    TE(ob[i],"  =|+|= A chaotic voice screams: "+str+"\n");
    }
  }
  RE;
}

jump_out() {
  TE(TP,"You leap out of ChAoS!\n");
  say(TPN+" leaps out of ChAoS!\n");
  TR(CPORT,TPN+" leaps into the room!\n");
  MO(TP,CPORT); command("look",TP);
  return 1;
}

chaos_move() {
  int MM,RW;
  string destdir;
  MM = random(9);
  TE(TP,"You meander through the fabric of ChAoS...\n");
  say(TPN+" meanders away...\n");
    if(MM == 0) destdir = C2;
    if(MM == 1) destdir = C3;
    if(MM == 2) destdir = C4;
    if(MM == 3) destdir = C5;
    if(MM == 4) destdir = C6;
    if(MM == 5) destdir = C7;
    if(MM == 6) destdir = C8;
    if(MM == 7) destdir = C9;
    if(MM == 8) destdir = C1;
  TR(destdir,TPN+" meanders into the room.\n");
  move_object(TP,destdir);
  command("look",TP);
return 1;
}
 
wandering() {
  object chc, monst;
 call_out("wandering",random(WANDER));
chc = present("chaoscreature");
 if(!chc && random(100) < 45) {
    TR(TO,"The ChAoS gives birth to another monster!\n");
    MO(clone_object(random_creation("monster")),TO);
   return 1;
 }
return 1;
}

random_creation(str) {
  int rnum;
  string mpath;
  if(str == "monster") {
    rnum = random(100);
    if(rnum < 15)               mpath = BLOBM;
    if(rnum >= 15 && rnum < 25) mpath = CRABM;
    if(rnum >= 25 && rnum < 50) mpath = CRAWFISHM;
    if(rnum >= 50 && rnum < 55) mpath = EFREETIM;
    if(rnum >= 55 && rnum < 65) mpath = QUICKM;
    if(rnum >= 65 && rnum < 80) mpath = STIRGEM;
    if(rnum >= 80 && rnum < 90) mpath = SPHINXM;
    if(rnum >= 90 && rnum < 95) mpath = CATERM;
    if(rnum >= 95)              mpath = HUNTERM;
  return mpath;
  }
}
