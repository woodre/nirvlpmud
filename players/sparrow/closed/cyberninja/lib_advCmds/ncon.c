#include "../DEFS.h"
#define LEVEL  7

status main(string str) {
  int hps, sps;
  string name, loc;
  int b;
  object * ob;

  if(!gotrank(TP, LEVEL)) return 0;
  write("\n"+LINE);
  write(BOLD+YELLOW+
        " Ninja           HP    SP      Location\n"+
        OFF+LINE);

  ob = users();
  for(b=0; b<sizeof(ob); b+=1) {
    if(!((int)ob[b]->query_invis())) {
if(present(GUILD_ID,ob[b])){
        name = (string)ob[b]->query_name();
        /* verte */
        if(!environment(ob[b])) loc = "Logging in";
      else
        loc  = (string)environment(ob[b])->short();
        /* mult. by 10 instead of 100, this intentionally reduces accuracy */
        hps  = (((int)ob[b]->query_hp()) * 10) / ((int)ob[b]->query_mhp());
        sps  = (((int)ob[b]->query_sp()) * 10) / ((int)ob[b]->query_msp());
        write(" "+
          pad(name,15)+" "+pad(hps+"0%",5)+" "+pad(sps+"0%",7)+" "+loc+"\n");
      }
    }
  }

  write(LINE);
  return 1;
}
