#include "../defs.h"

cmd(str){
object ob;
 if(!GOB->checklev(3,7)) return 1;  
if (!str){
    write("What would you like to echo?\n");
    return 1;
}
say(str+" "+BOLD+BLK+"<"+tpn+">\n"+OFF);
write("You echo:\n "+str+" "+BOLD+BLK+"<"+tpn+">\n"+OFF);
return 1;
}
