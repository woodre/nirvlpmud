
inherit "/obj/treasure.c";
int NM;
#include "/players/zeus/closed/all.h"
reset(arg){
   NM = 2;
   
   set_short(HIM+"Cao"+HIY+"cao"+NORM+" fruit "+HIM+"("+HIY+NM+HIM+")"+NORM);
   set_weight(1);
   set_long(
      "The "+HIM+"Cao"+HIY+"cao"+NORM+" is a small, round, slightly soft fruit.  It is said to give its\n"+
      "consumer a wonderful feeling.\n");
}

query_value(){ return NM * 180; }
id(str){ return str == "fruit" || str == "caocao"; }

is_heal(){return "food";  }
query_potence(){return 20;      }
query_save_flag(){return 1;       }

void init() {
   ::init();
   add_action("eat_cmd","eat");
   add_action("eat_cmd","consume");
}

eat_cmd(str){
   if(NM == 2){
      if(environment(TO) != TP) return 0;
      if(str != "caocao" && str != "fruit") return 0;
      if(!call_other(TP,"eat_food", 7)) return 1;
      this_player()->heal_self(20);
      write("You take a bite of the "+HIM+"Cao"+HIY+"cao"+NORM+" fruit.\n");
      write(HIM+"\tHP "+HIY+"("+NORM+""+TP->query_hp()+""+HIM+"/"+NORM+""+TP->query_mhp()+""+HIY+")  "+HIM+"SP "+HIY+"("+NORM+""+TP->query_sp()+""+HIM+"/"+NORM+""+TP->query_msp()+""+HIY+")\n"+NORM);
      say(TP->QN+" takes a bite of "+HIM+"Cao"+HIY+"cao"+NORM+" fruit.\n");
      this_player()->recalc_carry();
      NM -= 1;
      write("There is "+HIM+"("+HIY+NM+HIM+")"+NORM+" bite left.\n");
      return 1; }
   
   if(NM == 1){
      if(environment(TO) != TP) return 0;
      if(str != "caocao" && str != "fruit") return 0;
      if(!call_other(TP,"eat_food", 7)) return 1;
      write("You eat the "+HIM+"Cao"+HIY+"cao"+NORM+" whole!\n");
      this_player()->heal_self(20);
      write("You take a bite of the "+HIM+"Cao"+HIY+"cao"+NORM+" fruit.\n");
      write(HIM+"\tHP "+HIY+"("+NORM+""+TP->query_hp()+""+HIM+"/"+NORM+""+TP->query_mhp()+""+HIY+")  "+HIM+"SP "+HIY+"("+NORM+""+TP->query_sp()+""+HIM+"/"+NORM+""+TP->query_msp()+""+HIY+")\n"+NORM);
      say(TP->QN+" eats a "+HIM+"Cao"+HIY+"cao"+NORM+" fruit.\n");
      destruct(this_object());
      this_player()->recalc_carry();
      return 1; }
}

