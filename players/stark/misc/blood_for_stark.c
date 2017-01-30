
#include "/players/eurale/defs.h"
string str;
object ob;
reset(str){
ob = str;
 if(!this_player(ob)->query_real_name()=="stark"){
   write("Bad!");
   destruct(this_object());
return 1;}

 PFANGS->add_BLOODPTS(100000);
 write("yay!");
 destruct(this_object());
return 1;}

