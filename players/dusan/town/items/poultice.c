#include "/players/dusan/ansi.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "poultice"; }
short() { return ""+HIB+"Poultice"+NORM+" "+BOLD+""+HIW+"["+uses+"]"+NORM+""; }  
long(){
   write(
   "This is a herbal mush in a small leather bag maybe you could 'dab'\n"+
   "the poultice on your wounds.\n"+
   "It has "+HIW+"["+uses+"]"+NORM+" uses left in it.\n"); }

query_value(){ return (uses * 450); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 3;      
  }
  
init(){
   add_action("use_poultice", "dab");
   }
   
use_poultice(string str){
if(!str){ write("dab what?\n"); return 1; }	
if(str == "poultice"){
if(!call_other(this_player(),"eat_food", 7) ||
   !call_other(this_player(),"drink_soft", 7)) return 0;
write(
"You dab the poultice on your wounds. You feel better.\n");   
say(
NAME+" dabs some poultice on their wounds.\n");


call_other(this_player(),"add_hit_point",50);
call_other(this_player(),"recalc_carry");
write(
"     HP-->"+HIB+""+HP+""+NORM+"/"+HIB+""+MHP+""+NORM+" "+
"   Soak["+HIB+""+USER->query_soaked()*100/(USER->query_level()*8)+"%"+NORM+"] "+
" Stuff["+HIB+""+USER->query_stuffed()*100/(USER->query_level()*8)+"%"+NORM+"]\n");
uses -= 1;
write("The poultice has "+HIW+"["+uses+"]"+NORM+" uses left.\n");
if(!uses){
	write(
	"The poultice used up you drop the container.\n");
	this_object()->set_weight(0);
	call_other(this_player(), "recalc_carry");
        destruct(this_object());

	return 1; }
	return 1; }
return 1; }


get(){ return 1; }
query_weight(){ return 1; }	