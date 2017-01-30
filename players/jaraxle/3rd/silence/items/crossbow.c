inherit "players/jaraxle/weapon/weapon.c";
#include "/players/jaraxle/define.h"

int turn;

reset(x) {
   ::reset(x);
   if (!x) {
      turn = 1;
      set_name("Rapidfire");
      set_alt_name("rapidfire");
      set_alias("crossbow");
      set_short(HIW+"Rapid"+HIR+"fire"+NORM+", the crossbow");
      set_long("A small wooden crossbow with a hair trigger. The\n"+
         "shaft is short, yet sturdy.  Made from the wood of\n"+
         "elders, magical arrows fire from the crossbow at\n"+
         "alarming rate.\n");
      set_class(15);
      set_value(10000);
      set_weight(2);
      set_type("bow");
      message_hit=({""+HIR+"drove"+NORM+" an arrow through"," with "+HIR+"thundering force"+NORM+"",""+RED+"drove"+NORM+" an arrow through"," with "+RED+"great strength"+NORM+"",""+HIB+"fired"+NORM+" an arrow into"," with "+HIB+"pristine accuracy"+NORM+"",""+HIB+"fired"+NORM+" an arrow into"," with "+HIB+"great skill"+NORM+"",""+HIC+"shot"+NORM+" an arrow at"," with "+HIC+"painfull precision"+NORM+"","barely "+CYN+"nicked"+NORM+""," with an arrow","scratched"," lightly, with an arrow"});
      set_hit_func(this_object());
   }
}
query_save_flag() {return 1; }

weapon_hit(attacker) {
   int x;
   x = random(4);
   if(x == 3){
      object ob;
      if (!turn) return 0;
      ob = environment(this_object());
      turn = 0;
      call_other(ob,"attack");
      turn = 0;
      if (attacker)
         call_other(ob,"attack");
      
      turn = 1;
      if (attacker)
         return 0;
      else return "miss";
   }
}


