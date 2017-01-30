#include "/players/wocket/closed/ansi.h"

cmd(str){
object ob;
string msg;
if(str == "-old"){ return 0; }
msg = MAG+"---["+HIR+"*"+OFF+MAG+"]---\n"+OFF;
ob = first_inventory(this_player());
while(ob){
  if(ob->short()){
    msg += ob->short();
  msg+= "\n";
  }
ob = next_inventory(ob);
}
msg += MAG+"---["+HIR+"*"+OFF+MAG+"]---\n"+OFF;
write(msg);
return 1;
}
