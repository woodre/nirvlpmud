/* 25 heal_self points, 3 charges. stuff and soak heal
   at 4/4 soaked/stuffed  
   DRAWBACKS:
   Addiction: You can lose hps and sometimes stats.
   Must get from players, which means not always
   available.
*/

#include "/players/maledicta/ansi.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "injector"; }
short() { return "Injector Patch "+HIG+"]GREEN["+NORM+" "+BOLD+"-"+NORM+uses+BOLD+"-"+NORM; }  
long(){
   write(
"  This is a small square path with a green symbol across\n"+
"its surface. You can 'slap patch' to heal from it.\n"+   
"It has "+GRN+"["+uses+"]"+NORM+" uses left in it.\n"); }

query_value(){ return (uses * 100); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 3;      
  }
  
init(){
   add_action("use_kit", "slap");
   }
   
use_kit(str){
if(str == "patch"){
if(environment(this_object()) != this_player()) return 0;
if(this_player()->query_stuffed() + 4 > (int)this_player()->query_level() * 8){
write(HIR+"You are too stuffed to use it!"+NORM+"\n"); return 1; }
if(this_player()->query_soaked() + 4 > (int)this_player()->query_level() * 8){
write(HIR+"You are too soaked to use it!"+NORM+"\n"); return 1; }
if(!call_other(this_player(),"eat_food", 4) || 
!call_other(this_player(), "drink_soft", 4)) return 0;
write(
"You slap the patch onto your shoulder and feel energy enter your body!\n");   
say(
NAME+" uses a small patch.\n");
call_other(this_player(),"heal_self", 25);
call_other(this_player(),"recalc_carry");

write(
"     HP>>>"+HIG+""+HP+""+NORM+"/"+HIG+""+MHP+""+NORM+"  SP>>>"+HIG+""+SP+""+NORM+"/"+HIG+""+MSP+""+NORM+""+
" Stuff["+HIG+""+USER->query_stuffed()*100/(USER->query_level()*8)+"%"+NORM+"]  "+
" Soak["+HIG+""+USER->query_soaked()*100/(USER->query_level()*8)+"%"+NORM+"]\n");
uses -= 1;
write("The injector has "+HIG+"["+uses+"]"+NORM+" left.\n");

/* ADDICTION! (2% chance) */
if(!present("addiction_object", this_player()) && !random(50)){
  write_file("/players/maledicta/log/addicted",
  USER->query_real_name()+" became addicted on: "+ctime(time())+"\n");  
  move_object(clone_object("/players/maledicta/town/obj/addiction"), this_player());
  present("addiction_object", this_player())->addiction();
  }
else{
 if(present("addiction_object", this_player()))
   present("addiction_object", this_player())->addiction();
  }
/**************************/
if(!uses){
	write(
	"Useless now, you drop the patch.\n");
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
