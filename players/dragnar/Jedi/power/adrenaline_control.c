#include <ansi.h>
#include "defs.h"
inherit CMDBASE;
#define skill previous_object()->query_skill("adrenaline_control")
#define color previous_object()->query_mon_color()

main(){

if(USER->query_ghost()) return 0;
if(skill_check(1)){ return 1; }
if(cp_check(80-(skill*2))){ return 1;}

write(
""+color+"[]"+NORM+" You concentrate briefly causing the adrenaline within your\n"+
""+color+"[]"+NORM+" body to flow rapidly!\n");

if(skill > 9){
previous_object()->set_adr_con(1800);
}
else{
previous_object()->set_adr_con(skill*90);
  }
return 1;

} 
