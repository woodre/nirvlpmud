/* Setup room for DarK ArenA realm */

inherit "room/room.c";
#include "std.h"
#include "defs.h"
#include "/players/snow/closed/cyber/color.h"

dark_cmds(str) {
  if(!str) { dark_help(); RE; }
  if(str == "who") { dark_who(); RE; }
}

dark_help() {
  TE(TP,"...."+BOLD+"----DarK----"+OFF+"....\n\n");
  TE(TP,"....dark........This menu.\n");
  TE(TP,"....dark who....Who's in the Dark Arena.\n");
  TE(TP,"....dvoice........Tell to everyone in the Dark Arena.\n\n");
  TE(TP,".... "+BOLD+"----DarK----"+OFF+"....\n");
  RE;
}

dark_who() {
  object ob;
  int i;
  ob = users();
  TE(TP,BOLD+"* ^ > < ^ * ^ > < ^ * ^ > < ^ *"+OFF+"\n\n");
  for( i = 0; i < sizeof(ob); i += 1 ) {
  if(ENV(ob[i])->query_darena() == "boo") {
    if(ob[i]->query_invis() < TP->query_level()) {
      TE(TP,BOLD+"** "+OFF+ob[i]->query_name()+"\n");
    }
  }
  }
  TE(TP,BOLD+"\n* ^ > < ^ * ^ > < ^ * ^ > < ^ *"+OFF+"\n");
  RE;
}

dark_voice(str) {
  object ob;
  int i;
  ob = users();
  for( i = 0; i < sizeof(ob); i++ ) {
    if(ENV(ob[i])->query_darena() == "boo") {
    TE(ob[i],BOLD+"  =|+|= "+OFF+"A shadow whispers: "+str+"\n");
    }
  }
  RE;
}

random_creation(str) {
  int rnum;
  string mpath;
  object cmon, to;
  if(!str) {
  if("/players/snow/dark/counter.c"->query_count() > 3) return 1;
    rnum = random(60);
    if(rnum == 0) mpath = VAMPM;
    if(rnum >= 1 && rnum <= 13) mpath = CREEM;
    if(rnum >= 14 && rnum <= 20) mpath = SPINM;
    if(rnum >= 21 && rnum <= 25) mpath = SPECM;
    if(rnum >= 26 && rnum <= 35) mpath = SHADM;
    if(rnum >= 36 && rnum <= 45) mpath = SKELM;
    if(rnum >= 46 && rnum <= 55) mpath = ZOMBM;
    if(rnum > 55) mpath = ASSAM;
  if(!mpath) return 1;
  if(cmon != clone_object(mpath)) return 1;
  to = this_object();
  if(!to) return 1;
  move_object(cmon, to);
  "/players/snow/dark/counter.c"->add_count(1);
  return;
  }
}

check_count() {
  write("Current monster count is: "+
  "/players/snow/dark/counter.c"->query_count()+"\n");
  return 1; }

do_create() {
  write("You create a monster...\n");
  random_creation();
  return 1; }
