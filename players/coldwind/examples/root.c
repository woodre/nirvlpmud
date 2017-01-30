#include "/players/coldwind/ansi.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()
int uses;

id(str){ return str == "root" || str == "cactus"; }
short() { return HIG+"Cactus root "+NORM+BOLD+"["+NORM+GRN+uses+NORM+BOLD+"]"+NORM; }  
long(){
   write(
"    This is a small piece of cactus root.  It has been used by ancients\n"+
"for centuries to restore the bodies energy and health, for they believed\n"+
"it is magical. You can 'eat' it to feel it's magical power.\n"+   
"It has "+GRN+"["+uses+"]"+NORM+" bites left in it.\n"); }

query_value(){ return (uses * 500); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 3;      
  }
  
init(){
   add_action("use_root", "eat");
   }
   
use_root(str){
if(str == "root"){
if(environment(this_object()) != this_player()) return 0;
if(this_player()->query_stuffed() + 10 > (int)this_player()->query_level() * 8){
    notify_fail("You are too full!\n");
    return 0;
  }
if(this_player()->query_soaked() + 10 > (int)this_player()->query_level() * 8){
    notify_fail("The root contains too much juice.\n"+
	            "You can't drink that much!\n");
    return 0;
  }
if(!call_other(this_player(),"eat_food", 8) ||
 !call_other(this_player(), "drink_soft", 8)) return 0;
write( 
"You feel better as the roots magical powers runs through your veins.\n");
call_other(this_player(),"add_spell_point", 50);
call_other(this_player(),"heal_self", 50);
write(
"  HP ("+HIG+""+HP+""+NORM+"/"+HIG+""+MHP+""+NORM+")"+
"  SP ("+HIG+""+SP+""+NORM+"/"+HIG+""+MSP+""+NORM+")"+
" Stuff["+HIG+""+USER->query_stuffed()*100/(USER->query_level()*8)+"%"+NORM+"]  "+
" Soak["+HIG+""+USER->query_soaked()*100/(USER->query_level()*8)+"%"+NORM+"]\n");
uses -= 1;
write("The root has "+HIG+"["+uses+"]"+NORM+" bites left.\n");
if(!uses){
	write(
	"You have finished the root.\n");
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
