#include "/players/dusan/ansi.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "salve"; }
short() { return ""+HIG+"Healing Salve"+NORM+" "+BOLD+""+HIW+"["+uses+"]"+NORM+""; }  
long(){
   write(
   "This is a small crystal container with a blue pudding like substance\n"+
   "inside it. You can 'apply salve' to your wounds for instant healing.\n"+
   "It has "+HIW+"["+uses+"]"+NORM+" uses left in it.\n"); }

query_value(){ return (uses * 260); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 3;      
  }
  
init(){
   add_action("use_salve", "apply");
   }
   
use_salve(string str){
if(!str){ write("apply what?\n"); return 1; }	
if(str == "salve"){
if(!call_other(this_player(),"eat_food", 4) ||
   !call_other(this_player(),"drink_soft", 4)) return 0;
write(
"You apply a thin coat of salve to your wounds.\n");   
say(
NAME+" applys some healing salve to their wounds.\n");


call_other(this_player(),"add_hit_point",30);
call_other(this_player(),"recalc_carry");
write(
"     HP-->"+HIB+""+HP+""+NORM+"/"+HIB+""+MHP+""+NORM+" "+
"   Soak["+HIB+""+USER->query_soaked()*100/(USER->query_level()*8)+"%"+NORM+"] "+
" Stuff["+HIB+""+USER->query_stuffed()*100/(USER->query_level()*8)+"%"+NORM+"]\n");
uses -= 1;
write("The salve has "+HIW+"["+uses+"]"+NORM+" uses left.\n");
if(!uses){
	write(
	"The salve used up you drop the container.\n");
	this_object()->set_weight(0);
	call_other(this_player(), "recalc_carry");
        destruct(this_object());

	return 1; }
	return 1; }
return 1; }


get(){ return 1; }
query_weight(){ return 1; }	