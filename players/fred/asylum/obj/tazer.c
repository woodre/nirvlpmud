inherit "/obj/treasure.c";
#include <ansi.h>
#include "/players/fred/defines.h"

reset (arg) {

 set_id("tazer");
 set_short("A small "+BOLD+BLK+"Tazer"+NORM);
 set_long(
 "  A small tazer that could be used to ward off certain enemies.\n"+
 "All one has to do is '"+HIY+"zap"+NORM+"' someone.\n");
 set_weight(1);
 set_value(350);
}

init(){
 ::init();
   add_action("chuckle_chuckle_ha_ha", "zap");
 }

chuckle_chuckle_ha_ha(str){
  object BRASSMONKEY;
  if(!str) { write("Zap who?\n"); return 1; }
  if(str){
    BRASSMONKEY = present(str, environment(TP)); }
  if(!BRASSMONKEY){ write("You do not see "+CAP(BRASSMONKEY->query_name())+" here.\n"); }
  if(!BRASSMONKEY->query_wimpy()){
    write("You try to shock "+CAP(BRASSMONKEY->query_name())+" but they don't seem to react.\n"+
          "You hit the tazer a couple times in frustration.\n");
    tell_object(BRASSMONKEY,
      TPN+" tried to shock you with a tazer.\n");
    return 1;  }
  if(TP->query_spell_point() < 20){ write("You don't have enough power to use the tazer.\n"); } 
   write("You press a button on the tazer and "+HIY+"SHOCK "+NORM+CAP(BRASSMONKEY->query_name())+".\n");
   tell_object(BRASSMONKEY,
     TPN+HIY+" SHOCKS"+NORM+" you with a tazer!\n");
   BRASSMONKEY->run_away();
   TP->add_spell_point(-20);
  return 1; 
  } 




   

    

