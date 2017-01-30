#include "/players/pestilence/ansi.h"

main(){
        object tp;
        tp = this_player();
      tp->set_guild_name(0);
      tp->set_guild_file(0);
      tp->add_exp(tp->query_guild_exp());
     tp->set_home("room/church");
      tp->add_guild_exp(-tp->query_guild_exp());
      tp->add_guild_rank(-tp->query_guild_rank());
          tp->add_exp(-(tp->query_exp()/2));
      tp->set_attrib("sta",1);
          tp->reset(1);
          command("save",tp);
  /** Guild halls reset titles as well as levels **/
  call_other( "/room/adv_guild", "correct_level", this_player() );
  call_other( "/room/exlv_guild", "correct_extra_level", this_player() );
          write("Silly fool, see u on the flip side!\n");
          destruct(previous_object());
return 1; } 

