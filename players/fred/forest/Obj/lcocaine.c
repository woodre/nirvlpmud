#include "/players/fred/ansi.h"
inherit "/obj/treasure.c";
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

reset (arg) {
  set_id("cocaine");
  set_alias("liquid");
  set_short(BOLD+BLK+"Liquid"+RED+" Cocaine"+NORM);
  set_long(
 "  A syringe filled with a colorless liquid. There\n"+
 "is something written on the side of the syringe.\n" );
  set_weight(1);
  set_value(1000);
}

init(){
 ::init();
   add_action("injectem", "inject");
   add_action("readem","read");
 }

injectem(str){
  int soaked, smax, hmax;
  if(!str) { write("Inject what?\n"); return 1; }
  if(str == "cocaine" || str == "liquid"){
   hmax = this_player()->query_mhp();
   smax = this_player()->query_msp();
   this_player()->heal_self(hmax);
   this_player()->add_spell_point(smax);
   say(tpn+" injects a syringe into "+tpp+" arm and looks revived.\n");
   write("You inject the colorless liquid into your arm.\n"+
         "A warm"+HIY+" soothing"+NORM+" feeling rushes"+BOLD+" over"+NORM+" your body.\n\n");
   write(HIY+"HP: "+NORM+BOLD+this_player()->query_hp()+NORM+BOLD+"/"+NORM+BOLD+this_player()->query_mhp()+NORM);
   write(BOLD+HIY+"   SP: "+NORM+BOLD+this_player()->query_sp()+NORM+BOLD+"/"+NORM+BOLD+this_player()->query_msp());  
   write(HIY+"   I "+NORM+BOLD+((this_player()->query_intoxication()*100)/(this_player()->query_level()+3))+BOLD+"%"+NORM);
   write(BOLD+HIY+"  F "+NORM+BOLD+((this_player()->query_stuffed()*100)/(this_player()->query_level()*8))+BOLD+"%"+NORM);
   write(BOLD+HIY+"  S "+NORM+BOLD+((this_player()->query_soaked()*100)/(this_player()->query_level()*8))+BOLD+"%"+NORM);
   write("\n\n");
   destruct(this_object());
   return 1; }
  }

readem(str){
  if(!str) { write("Read what?\n"); return 1; }
  if(str == "syringe"){
   write("You are not sure how safe this is but you could 'inject cocaine'!\n");
   return 1; }
  }

   


  
