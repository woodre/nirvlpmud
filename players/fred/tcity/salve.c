#include "/players/fred/ansi.h"
#include "/players/fred/defines.h"
inherit "/obj/treasure.c";
#define HP  TP->query_hp()
#define SP  TP->query_sp()
#define MHP TP->query_mhp()
#define MSP TP->query_msp()
#define STUFF TP->query_stuffed()
#define SOAK TP->query_soaked()
#define TOX TP->query_intoxication()
#define LVL TP->query_level()

int shots;

reset(arg){
  if(arg) return;
  set_id("salve");
  set_alias("stick");
  long_desc = "A yellowish brown stick of salve that you could '"+BOLD+"apply"+NORM+"' to your wounds.\n";
  set_weight(1);
  shots = 3;
}

init(){
  ::init();
   add_action("since_Ive_gone_and","apply");
 }

since_Ive_gone_and(str){
    if(str == "salve" || str == "stick"){
      if(environment(TO) != TP) return 0;
        if(STUFF + 10 > (int)LVL * 8){
        write(BOLD+"You are too stuffed to use any more salve."+NORM+"\n"); return 1; }
        if(SOAK + 10 > (int)LVL * 8){
        write(BOLD+"You are too soaked to use any more salve."+NORM+"\n"); return 1; }
         if(!TP->drink_soft(7) ||
            !TP->eat_food(7)) return 0;
      say(TPN+" applies some healing salve to "+POS+" wounds.\n");
      write("You apply some of the healing salve to your"+NORM+"\n");
      write("wounds. A soothing feeling rushes over your body."+NORM+"\n\n");     
      TP->heal_self(50);
      shots --;
      write(BOLD+YEL+"     HP: "+NORM+BOLD+HP+NORM+BOLD+"/"+NORM+BOLD+MHP+NORM);
      write(BOLD+YEL+"  SP: "+NORM+BOLD+SP+NORM+BOLD+"/"+NORM+BOLD+MSP);  
      write(BOLD+YEL+"  I "+NORM+BOLD+((TOX*100)/(LVL+3))+BOLD+"%"+NORM);
      write(BOLD+YEL+"  F "+NORM+BOLD+((STUFF*100)/(LVL*8))+BOLD+"%"+NORM);
      write(BOLD+YEL+"  S "+NORM+BOLD+((SOAK*100)/(LVL*8))+BOLD+"%"+NORM);
      write("\n\n"); 
      write("There are still "+BOLD+YEL+shots+NORM+" applications remaining.\n");
       if(!shots){
         write("\nYou finish off the last of the salve and drop the stick to the ground.\n");
         say(TPN+" finishes off the salve and throws the stick to the ground.\n");
       destruct(TO);
       TP->recalc_carry();
     return 1; }
  return 1; }
 }

short(){
 return ""+YEL+"A healing Salve "+NORM+"["+shots+"]"; 
 }

query_save_flag(){ return 1; }
query_value(){ return (shots * 400); }
get(){ return 1; }



   
      
              
    
