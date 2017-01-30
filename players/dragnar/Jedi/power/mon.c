#include <ansi.h>
#include "defs.h"

main(string str) {
  string mon_color;
  int x,percent;

if(!str) {
  mon_color = previous_object()->query_mon_color();
percent = cp*100/mcp;
tell_object(USER,
""+mon_color+"-=[JEDI]=-"+NORM+" HP: "+mon_color+""+USER->query_hp()+""+NORM+"/"+mon_color+""+
""+USER->query_mhp()+" "+NORM+"SP: "+mon_color+USER->query_sp()+NORM+"/"+mon_color+
USER->query_msp()+NORM+" CP: "+mon_color+""+percent+"%"+NORM+""+
" I: "+mon_color+""+USER->query_intoxination()*100/(USER->query_level()+3)+"%"+NORM+""+
" F: "+mon_color+""+USER->query_stuffed()*100/(USER->query_level()*8)+"%"+NORM+""+
" S: "+mon_color+""+USER->query_soaked()*100/(USER->query_level()*8)+"%"+NORM+""+
" T: "+mon_color+""+USER->query_infuse()*100/(9*(USER->query_level()/2))+"%"+NORM+"");
if(attack) {
  tell_object(USER,
 " AHP: "+mon_color+""+(attack->query_hp())*10/(attack->query_mhp())+"/10"+NORM);
}
tell_object(USER, "\n");
return 1;
}
if( str == "on" ) {
  command("monitor on", this_player());
  return 1;
}

}
