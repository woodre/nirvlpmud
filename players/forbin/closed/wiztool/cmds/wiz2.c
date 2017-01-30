#include <security.h>
#include "/players/forbin/define.h"
#include "/players/forbin/closed/wiztool/define.h"

#define II WTC+"++"+NORM
#define V WTC+"+++++"+NORM
#define III HIW+"+++"+NORM
#define VII HIW+"+++++++"+NORM
#define LONGLINE V+III+II+VII+II+III+V+V+III+V+III+V+III+V+V+III+II+VII+II+III+V

main() {
  object *list;
  int i, level, invis;
  string snooper;
  string name, ed, tab;
  list=users();
  write("\n"+LONGLINE+"\n");   
  write(pad("name",20)+pad("Level",7)+pad("Invis",8)+pad("Edit",8)+"\n");
  for(i=0; i<sizeof(list); i++) {
    name=capitalize((string)list[i]->query_real_name());
    level=list[i]->query_level();
    invis=list[i]->query_invis();
    if(invis>999) { invis=999;}
    ed="  ";
    if(in_editor(list[i])) {
      ed="Ed";
    }
    if(level>19) {
      write(pad(name,20)+pad(level,7)+pad(invis,8)+pad(ed,8));
      write(list[i]->query_pwd());
      write("\n");
    }
    snooper=query_snoop(list[i]);
    if(snooper) write(snooper+"->"+list[i]+"\n");
  }
  write("\n"+LONGLINE+"\n"); 
  return 1;
}
