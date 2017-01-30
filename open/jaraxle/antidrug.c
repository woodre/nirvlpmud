#include "/players/fred/ansi.h";
inherit "/obj/treasure.c";
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

reset (arg) {
  set_id("drug");
  set_alias("pill");
  set_short(BOLD+"Anti"+GRN+"-"+NORM+BOLD+"Drug"+NORM);
  set_long(
 "  A small pill that is used to help people with detox\n"+
 "if they have overdone it.\n" );
  set_weight(1);
  set_value(6000);
}

init(){
 ::init();
   add_action("snarfblat", "eat");
   }

snarfblat(str){
  if(!str) { write("Eat what?\n"); return 1; }
  if(str == "pill" || str == "drug"){
  int z, q, x;
  z = this_player()->query_stuffed();
x = this_player()->query_alcohol();
  q = this_player()->query_soaked();
   say(tpn+" eats a small pill.\n");
   write("You eat the small pill and feel relief.\n");
call_other(this_player(),"drink_alcohol",-x);
call_other(this_player(),"drink_soft",-q);
call_other(this_player(),"eat_food",-z);

   write(HIY+"HP: "+NORM+BOLD+this_player()->query_hp()+NORM+BOLD+"/"+NORM+BOLD+this_player()->query_mhp()+NORM);
   write(BOLD+HIY+"   SP: "+NORM+BOLD+this_player()->query_sp()+NORM+BOLD+"/"+NORM+BOLD+this_player()->query_msp());  
   write(HIY+"   I "+NORM+BOLD+((this_player()->query_intoxication()*100)/(this_player()->query_level()+3))+BOLD+"%"+NORM);
   write(BOLD+HIY+"  F "+NORM+BOLD+((this_player()->query_stuffed()*100)/(this_player()->query_level()*8))+BOLD+"%"+NORM);
   write(BOLD+HIY+"  S "+NORM+BOLD+((this_player()->query_soaked()*100)/(this_player()->query_level()*8))+BOLD+"%"+NORM);
   write("\n\n");
   destruct(this_object());
   this_player()->recalc_carry();
   return 1; }
  }

  
