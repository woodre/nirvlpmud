inherit "/obj/treasure.c";
#include "/players/jaraxle/define.h"
reset(arg){
if(!root()) {
call_out("dest_me", 30);
call_out("poison_me", 3);
}
set_weight(0);
set_value(5);
}
short(){ return "An arrow [BROKEN]"; }
long(){ write("A broken arrow\nSome kind of liquid has hardened on the tip.\n"); }
id(str){ return str == "arrow" || str == "broken arrow"; }
query_save_flag(){      return 1;       }
poison_me(){
if(!environment()) { destruct(this_object()); return; }
environment()->hit_player(1+random(4));
say("Poison invades your body.\n");
call_out("poison_me2", 3);
return 1; }
poison_me2(){
if(!environment()) { destruct(this_object()); return; }
environment()->hit_player(1+random(4));
say("Poison invades your body.\n");
call_out("poison_me3", 3);
return 1; }
poison_me3(){
if(!environment()) { destruct(this_object()); return; }
environment()->hit_player(1+random(4));
say("Poison invades your body.\n\nThe poison wears off. . .\n");
return 1; }
dest_me(){
destruct(this_object());
return 1; }

drop(){
write("The poison in the arrow disappears.\n");
destruct(this_object());
return 1; }
