inherit "/players/beck/updates/armor.c";
#include "/players/beck/esc.h"

reset(arg){
if(arg) return;
::reset();

set_name("fire ring");
set_silently(1);
set_ac(1);
set_res(40);
set_special(0);
set_type("ring");
set_short(BOLD+RED+"Red Hot Ring"+OFF);
set_long(
"This ring feels very warm.  Although it looks rather plain,\n"+
"you know there is something very special about it.\n"+
"");
set_params("other|fire",1,0,"do_special");

}
do_special(other){
write(other->query_name()+"\n");
write("Armor special\n");
say("Armor special\n");
return 10;
}
