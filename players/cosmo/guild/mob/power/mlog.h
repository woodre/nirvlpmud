/* Wizard ability for logging any changes made to guild code */

#include "/players/languilen/guild/mob/mobdefs.h"

mlog_cmd(string str){
  if(!str) {
    command("tail "+GUILDDIR+"log/CHANGE_REPORT",TP);
    return 1;
  }
  else {
    write_file("/players/languilen/guild/mob/log/CHANGE_REPORT",ctime()+
      " ** "+TPRN+" ** "+str+"\n");
    write("You wrote: "+str+", to the Mob CHANGE_REPORT.\n");
    return 1;
  }
}
