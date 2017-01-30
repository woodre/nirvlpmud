/* gwho command */

#include "/players/forbin/define.h"
#include "/players/forbin/closed/wiztool/define.h"

mixed main(int mode) {
  object *usr;
  int x, index;
  string *Data;
  string *foo;
  string g;
  usr = users(); foo = ({ });
  Data = ({ });
  for(x=0; x<sizeof(usr); x++) {
    if(usr[x]->query_level() < 20) {
      g = (string)usr[x]->query_guild_name();
      if(!g) g = "None";
      index = member_array(g, foo);
      if(index == -1) foo += ({ g, 1 });
      else            foo[index + 1] = ((foo[index + 1]) + 1);
    }
  }
  write(WTC+" ~=~= "+NORM+"Guild Counts"+WTC+" =~=~ \n"+NORM);
  for(x=0; x<sizeof(foo); x+=2) {
    if(mode) Data += ({ capitalize(foo[x]), foo[x + 1] });
    else write(pad(capitalize(foo[x]), 15) + " " + foo[x + 1] + "\n");
  }
  if(mode) return Data;
    return 1;
}

