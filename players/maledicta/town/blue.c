/* 50 heal_self points, 15 charges, at 10000 coins. splits
   between soaked and stuffed */

#include "/players/maledicta/ansi.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "injector"; }
short() { return "Injector "+BLU+"]BLUE["+NORM+" "+uses+""; }  
long(){
   write(
"  This is a small metallic injector used for healing\n"+
"major wounds. To use type: ib\n"+   
"It has "+BLU+"["+uses+"]"+NORM+" uses left in it.\n"); }

query_value(){ return (uses * 650); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 15;      
  }
  
init(){
   add_action("use_kit", "ib");
   }
   
use_kit(){

if(!call_other(this_player(),"drink_soft", 7) ||
   !call_other(this_player(),"eat_food", 7)) return 0;
write(
"You pick up an injector and place it against your arm. You press the\n"+
"button and feel a soothing chemical enter your bloodstream.\n");   
say(
NAME+" uses a small injector.\n");


call_other(this_player(),"heal_self", 50);
call_other(this_player(),"recalc_carry");
write(
"     HP>>>"+HIB+""+HP+""+NORM+"/"+HIB+""+MHP+""+NORM+" "+
" Soak["+HIB+""+USER->query_soaked()*100/(USER->query_level()*8)+"%"+NORM+"]\n");
uses -= 1;
write("The injector has "+HIB+"["+uses+"]"+NORM+" left.\n");
if(!uses){
	write(
	"Useless now, you drop the injector.\n");
	this_object()->set_weight(0);
	call_other(this_player(), "recalc_carry");
        destruct(this_object());

	return 1; }
	
return 1; }


get(){ return 1; }

query_weight(){ 
if(uses > 13) return 5;
else if(uses > 10) return 4;
else if(uses > 7) return 3;
else if(uses > 4) return 2;
else return 1;
 }	
