#include "/players/mythos/closed/guild/def.h"
string sacrificer, p;
id(str) {return str == "spouse_ask"; }

drop() {return 1; }


set_sacrificer(str) { sacrificer = str; }

init() {
  if(!(ep->query_npc())) {
 tell_object(find_player(lower_case(sacrificer)),"You ask "+
     capitalize(epn)+" to allow sacrifice.\n");
    tell_object(ep,capitalize(sacrificer)+" wishes to sacrifice you.\n"+
          "Will you allow it? <y/n>  ");
    input_to("aan");
    }
}

aan(p) {
int nl, nx;
  if(p == "y") {
  tell_room(environment(ep),"Suddenly a Black Altar materializes!\n");
  tell_room(environment(ep),capitalize(sacrificer)+
  " lays "+capitalize(epn)+" upon the black altar.\n");
  tell_room(environment(ep),capitalize(sacrificer)+
  " raises a ceremonial dagger and plunges it deep into the heart of "+
  capitalize(epn)+"!\n");
  nl = epl;
  nx = epx;
  find_player(lower_case(sacrificer))->zap_object(ep);
  present(pact,find_player(lower_case(sacrificer)))->add_sacrifice(30000 * (nl + nx)/4);
  write_file("/players/mythos/closed/guild/sacrifice_spouse",
  ctime()+" "+RED+sacrificer+NORM+" "+epn+" level: "+nl+ " x: "+nx+"\n");
  return 1;}
  if(p == "n") {
  tell_object(find_player(lower_case(sacrificer)),capitalize(epn)+
              " refuses to become your sacrifice.\n");
  destruct(this_object());
  return 1;}
  move_object(this_object(),ep);
return 1;}
  
check() {
 if(ep->query_ghost()) { 
 tell_room(environment(ep),capitalize(epn)+" is whisked away to the church.\n");
 move_object(ep,"/room/church.c");
 destruct(this_object());
 return 1;}
 ep->heal_self(-1000);
call_out("check",3);
return 1;}
