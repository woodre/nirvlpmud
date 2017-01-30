

#include "/players/maledicta/ansi.h"

int duration;

id(str){ return str == "smoke_from_potion"; }

query_value(){ return 0; }
query_save_flag(){ return 1; }
query_weight(){ return 1000; }

reset(arg){
  if(arg) return;
  duration = 5 + random(5);
  set_light(-10);
  call_out("smokey", 1);
  }
  
init(){
if(this_player())
tell_object(this_player(), BOLD+"A thick smoke fills the room!"+NORM+"\n");   
   }

smokey(){
     duration -= 1;
     if(duration){
     tell_room(environment(), BOLD+"Smoke swirls about the room..."+NORM+"\n");
     }
     if(!duration){
       tell_room(environment(),
       "The Smoke Fades...\n");
       destruct(this_object());
       return 1;
       }
     call_out("smokey", 1);
     }