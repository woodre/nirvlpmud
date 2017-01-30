#include "/players/languilen/closed/ansi.h"
string whos;

int id (string str ) { return str == "wet";}

reset(arg){
   if(arg) return;
   call_out("timerw",500);
}
   
string extra_look() {
   return (whos+" is completely drenched from head to toe.\n"+
           whos+" is soaking "+HIB+"wet"+NORM+" and looks alot like a drowned rat. \n");
   }

timerw() {
   destruct(this_object());
}

void init(){
  if ( !whos ) {
       whos= (string)this_player()->query_real_name();
       whos = capitalize(whos);
     }
}
query_save_flag() { return 1; }
drop(){ return 1; }

