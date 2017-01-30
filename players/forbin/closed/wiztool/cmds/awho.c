/* betterwho command */

#include "/players/forbin/define.h"
#include "/players/forbin/closed/wiztool/define.h"

#define II WTC+"++"+NORM
#define V WTC+"+++++"+NORM
#define III HIW+"+++"+NORM
#define VII HIW+"+++++++"+NORM
#define LONGLINE V+III+II+VII+II+III+V+V+III+V+III+V+III+V+V+III+II+VII+II+III+V

main() {
  int x; object *us;
  us = users();   
  write("\n"+LONGLINE+"\n\n");
  for(x=0; x<sizeof(us); x++) {
    string lev, xlev;
    lev = us[x]->query_level();
    xlev = us[x]->query_extra_level();
    write("   ");
    if(!us[x] || !ENV(us[x])) write("Logging on....\n"); 
    else if(us[x]->query_level() < 20) write(pad(CAP(us[x]->query_real_name()),18)+" "+NORM+pad(lev+"+"+xlev,10)+" "+(ENV(us[x]) ? ENV(us[x])->short() : "Unknown")+"\n");
    else if(us[x]->query_level() <= 40) write(HIW+pad(CAP(us[x]->query_real_name()),18)+" "+NORM+pad(lev+"+"+xlev,10)+" "+(ENV(us[x]) ? ENV(us[x])->short() : "Unknown")+"\n");    
    else if(us[x]->query_level() < 100) write(WTC2+pad(CAP(us[x]->query_real_name()),18)+" "+NORM+pad(lev+"+"+xlev,10)+" "+(ENV(us[x]) ? ENV(us[x])->short() : "Unknown")+"\n");
    else write(WTC+pad(CAP(us[x]->query_real_name()),18)+" "+NORM+pad(lev+"+"+xlev,10)+" "+(ENV(us[x]) ? ENV(us[x])->short() : "Unknown")+"\n");
  }
  write("\n"+LONGLINE+"\n");
    return 1; 
}

