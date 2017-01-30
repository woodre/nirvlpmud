#include "/players/coldwind/define.h"
int uses;

id(str){ return str == "evilsoul" || str == "giant_soul_2"; }
short() { return HIC+"Evilsoul"+NORM; }  
alias() {return "giant_soul_2"; }
long(){
   write(
"  A transparent figure hovers around you madly. It was said that a\n"+
"witch was able to control some creatures by allowing the evilsouls\n"+ 
"to take over their bodies and minds. In their hearts, those who can \n"+
"free the evilsouls will carry the evil.\n"); }

query_value(){ return (0); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 1;      
  }
  
init(){
   add_action("use_soul", "free");
   }
   
use_soul(str){
if(str == "evilsoul"){
if(!call_other(this_player(),"eat_food", 0) ||
 !call_other(this_player(), "drink_soft", 0)) return 0;
write(HIC+ 
"The soul touches your heart!\n"+NORM);
call_other(this_player(),"add_alignment", -1500);
uses = 0;
write("Evil thoughts take over your mind...\n");
if(!uses){
write(
	"The transparent figure drifts away.\n");
	this_object()->set_weight(0);
	call_other(this_player(), "recalc_carry");
        destruct(this_object());
	return 1; }
return 1;
  }	
return;
}


get(){ return 1; }
query_weight(){ return 1; }	
