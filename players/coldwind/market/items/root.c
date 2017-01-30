#include "/players/coldwind/ansi.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "root" || str == "cuctus"; }
short() { return HIG+"Cactus root "+NORM+BOLD+"["+NORM+GRN+uses+NORM+BOLD+"]"+NORM; }  
long(){
   write(
"    This is a small piece of cactus root.  It has been used by\n"+
"ancients for centuries to restore the bodies health, for they\n"+
"believed it is magical. You can 'eat' it to feel it's magical \n"+   
"power. It has "+GRN+"["+uses+"]"+NORM+" bites left in it.\n"); }

query_value(){ return (uses * 500); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 3;      
  }
  
init(){
   add_action("use_heal", "eat");
   }
   
use_leaf(str){
if(str == "root"){
if(environment(this_object()) != this_player()) return 0;
if(this_player()->query_stuffed() + 10 > (int)this_player()->query_level() *8){
    notify_fail("You are too full!\n");
    return 0;
  }
if(this_player()->query_soaked() + 10 > (int)this_player()->query_level() *8){
    notify_fail("The root contains too much juice.\n"+
	            "Your stomach can't hold that much!\n");
    return 0;
  }
if(!call_other(this_player(),"eat_food", 7) ||
 !call_other(this_player(), "drink_soft", 7)) return 0;
write( 
"You feel better as the roots magical powers runs through your veins.\n");
call_other(this_player(),"heal_hit_point", 75);
write(
"  HP ("+BOLD+""+HP+""+NORM+"/"+BOLD+""+MHP+""+NORM+")"+
"  SP ("+BOLD+""+SP+""+NORM+"/"+BOLD+""+MSP+""+NORM+")"+
" Stuff["+BOLD+""+USER->query_stuffed()*100/(USER->query_level()*8)+"%"+NORM+"]  "+
" Soak["+BOLD+""+USER->query_soaked()*100/(USER->query_level()*8)+"%"+NORM+"]\n");
uses -= 1;
write("The root has "+BOLD+"["+uses+"]"+NORM+" bites left.\n");
if(!uses){
	write(
	"You ate the last bite of the root.\n");
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
