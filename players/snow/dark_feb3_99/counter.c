/* Setup room for DarK ArenA realm */

#include "std.h"
#include "defs.h"
#include "/players/snow/closed/cyber/color.h"

int monster_count;
query_count() { return monster_count; }
add_count(int num) { monster_count += num; }


short() { return BOLD+"DarK ArenA"+OFF+" base room"; }
long(str) {
  write("This is the "+BOLD+"DarK ArenA"+OFF+" room model. \n");
}

realm() { return "NT"; }
query_darena() { return "boo"; }

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
  if(str == "monster") {
    rnum = random(20);
    if(rnum == 0) mpath = VAMPM;
    if(rnum >= 1 && rnum <= 3) mpath = CREEM;
    if(rnum >= 4 && rnum <= 6) mpath = SPINM;
    if(rnum >= 7 && rnum <= 8) mpath = SPECM;
    if(rnum >= 9 && rnum <= 12) mpath = SHADM;
    if(rnum >= 13 && rnum <= 15) mpath = SKELM;
    if(rnum >= 16 && rnum <= 18) mpath = ZOMBM;
    if(rnum == 19) mpath = ASSAM;
  return mpath;
  }
}
