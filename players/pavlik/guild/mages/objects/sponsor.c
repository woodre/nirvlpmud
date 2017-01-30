#include "/players/pavlik/closed/colors.h"
string sponsor;

short(){ return; }

long(){ write("Mage Sponsor Object.\n"); return; }

extra_look(){
  return "There is a "+CYN+"glowing sigil"+NORM+" on the palm of his right hand";
}

query_weight(){ return 0; }

query_value(){ return 0; }

drop(){ return 1; }

reset(arg){
  if(arg) return;
  sponsor = 0;
}

id(str){
  return str=="sponsor"||str=="mage_sponsor"||str=="sigil";
}

query_auto_load(){
  return "/players/pavlik/guild/mages/obj/sponsor.c:"+sponsor;
}

query_sponsor(){ return sponsor; }
set_sponsor(str){ sponsor = str; }


