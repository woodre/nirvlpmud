#include "/players/zeus/closed/tool/vars.h"
#include "/players/zeus/closed/tool/tellobj.h"
#include "/players/zeus/closed/tool/battle.h"
#include "/players/zeus/closed/tool/cq.h"
#include "/players/zeus/closed/tool/bring.h"
#include "/players/zeus/closed/tool/zwho.h"
#include "/players/zeus/closed/tool/vortex.h"
#include "/players/zeus/closed/tool/clean.h"
#include "/players/zeus/closed/tool/tellh.h"
#include "/players/zeus/closed/tool/short.h"
#include "/players/zeus/closed/all.h"

id(str){ return str == "zobj" ||
/*    str == "vampire fangs" || - Eurale says "No!" */
   str == "guild_medal"; 
}

reset(arg){
        if(arg) return;
        vis = 1;
}

drop() { return 1;}

void init(){
  add_action("clean_cmd", "clean");
  add_action("who_cmd", "zwho");
  add_action("tellh_cmd", "tellh");
  add_action("bring_cmd", "bring");
  add_action("vortex_cmd", "v"); 
  add_action("battle_cmd", "battle");
  add_action("know_cmd","know");
  add_action("telle_cmd", "telle");
  add_action("say_cmd", "say");
  add_action("emote_cmd", "emote");
  add_action("filer","logit");
  add_action("toggle_cmd", "toggle");
}
