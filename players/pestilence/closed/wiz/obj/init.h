#include "../defs.h"

static string *cmds;

init() {
  string who;
  object s;
  if(environment(this_object()) == this_player()) {
    who = this_player()->query_real_name();
    if(!restore_object(SAVE+who)) {
      save_object(SAVE+who);

    }
    CHAND->add_channel(CHAN_NAME, this_player(), 1 );
  }
  if(tp->query_level() < 20) {
    tp->set_guild_name("Dark Order");
}
/*
        if(tp->query_guild_rank() != g_level) tp->add_guild_rank(g_level - tp->query_guild_rank());
  tp->save_character();
  }
*/
            

/*
#ifndef __LDMUD__
add_action("unwield"); add_xverb("unwield");

#else
add_action("unwield","unwield");
#endif
*/
/*
add_action("guild_quit","guild_leave");
add_action("restore_me","drestore");
add_action("guild_update","gupdate");
add_action("guild_quit","leave_guild");
*/
/* moved to cmds
add_action("settitle","set_title");
add_action("pwho","pwho");
add_action("filer","gbug");
add_action("new_inventory","inv");
add_action("noraise","raise");
add_action("enrage","enrage");
add_action("cmd_order","order");
add_action("ravage","ravage");
add_action("ravage","ra");
add_action("offwield","offwield");
add_action("dhelp","dhelp");
add_action("distraught","distraught");
add_action("fatal","fatal");
add_action("distraught","dist");
add_action("stun","stun");
add_action("cmd_ctitle","dtitle");
add_action("teleport","darkness");
add_action("demon","demon");
add_action("torment","torment", 2);
add_action("wound","wound");
add_action("alignment","align");
add_action("alignment","alignment");
add_action("slash", "slash", 2);
add_action("new_invis","dinvis");
add_action("dportal","dportal");
add_action("enrage","enrage");
add_action("losers","losers");
add_action("punch","punch");
add_action("restore_me","drestore");
add_action("save_me","dsave");
add_action("guild_quit","guild_leave");
add_action("restore_me","drestore");
add_action("guild_update","gupdate");
add_action("guild_quit","leave_guild");
add_action("guild_login","login")
add_action("decorpse","drain");
*/;
add_cmds();
;
 if(this_player()->query_level() < 21){
write(""+HIK+"I'm changing up the format of some commands so some things"+NORM+"\n"+
""+HIW+"might bug, don't go whining, i know you will just report it to me, Thanks"+NORM+".\n");
return 1;
}
/*
init_callout();
*/
}
