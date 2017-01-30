inherit "obj/treasure.c";
#include "/players/jaraxle/closed/jdefine.h"
int shots, no;
reset(arg) {
   if(arg) return; 
   shots = 3;  }
id(str) { return str == "heal" || str == "healing pack" || str == "heal pack" || str == "customheal" || str == "heals" || str == "pack of healing" || str == "healing" || str == "pack of heals"; }
short() { return ""+YEL+"Healing Pack "+HIY+"-"+NORM+""+shots+""+HIY+"-"+NORM+""; }

long() {  
   
   write("This is a small metal box that resembles a slice of bread.\n"+
      "There are two metal contact points on it that look like they\n"+
      "could be attached to the skin.  Simply type '"+HIW+"healme"+NORM+"' to utilize\n"+ 
      "these heals.\n");
}

void init(){ 
   ::init(); 
   add_action("healme","healme"); 
}

healme(){
   if(environment() != TP) { write("You must get it first!\n"); return 1; }
   if(!call_other(TP,"drink_soft", no)) return 1;
   if(!call_other(TP,"eat_food", no)) return 1;
   write("The pack hums and you feel healed...\n");
   say(""+CAP(TPRN)+"'s healing pack hums and "+TP->query_pronoun()+" appears healed.\n");
   TP->heal_self(50);
   write(HIY+"\tHP"+NORM+": "+HIR+TP->query_hp()+NORM+"/"+HIR+TP->query_mhp()+HIY+" SP"+NORM+": "+HIR+TP->query_spell_point()+NORM+"/"+HIR+TP->query_msp()+NORM+"\n");
   shots--;
   if(shots== 0){
      write("The healing pack vaporizes upon it's last usage.\n");
      destruct(TO);
      call_other(TP,"recalc_carry"); }
   return 1; } 

query_save_flag() { return 1; }

query_value(){ return (shots * 500); }

get() { return 1; }

query_weight() { return 1; }

set_no(aa) { no = aa; } 

query_no() { return no; }


