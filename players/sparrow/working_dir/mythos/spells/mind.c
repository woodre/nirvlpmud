#include "/players/mythos/closed/guild/def.h"
string base, from;
int num;
id(str) {return str == "mind_meld" || str == "link";}

short() { return "Link with "+capitalize(base); }

long() { write("A link with "+capitalize(base)+".\n"+
               "To speak on mindlink channel: ml <msg>\n"+
               "To check group mind: ml\n"+
               "To shut off link: shut_link\n"+
               "Note: if you die, base will die and link will be severed.\n"); }

set_base(str) { base = str;}
set_from(str) { from = str;}
set_num(n) { num = n;}
query_num() { return num;}
query_from() { return from;}
query_base() { return base;}

get() { return 0;}
drop() { return 1;}

reset(arg) {
 if(arg) return;
 call_out("xp",3);
}

init() {
add_action("ml","ml");
add_action("shut_link","shut_link");
}

xp() {
if(!find_player(base) || !ep) { shut_link(); return 1;}
  if(ep->query_ghost()) {
  find_player(base)->zap_object(find_player(base)); 
  shut_link(); 
  return 1;}
  if(ep->query_exp() > num) {
  find_player(base)->add_sxp(ep->query_exp() - num);
  tell_object(find_player(base),"You recieve "+ (ep->query_exp() - num)+
  " xp from "+epn+"\n");
  ep->add_sxp(-(ep->query_exp() - num));
  }
  num = ep->query_exp();
  call_out("xp",3);
return 1;}

ml(str) {
object ob;
string msg;
int n;
ob = users();
if(!str) {
write("MIND LINK:\n");
write("          "+capitalize(base)+"   xp: "+find_player(base)->query_exp()+
      "  accumilated: "+
      (find_player(base)->query_exp() - 
      present("base_link",find_player(base))->query_num())+"\n");
for(n = 0; n < sizeof(ob); n++) {
  if(present("mind_meld",ob[n]) && 
     present("mind_meld",ob[n])->query_base() == base &&
     ob[n]->query_real_name() != base) {
write("          "+capitalize(ob[n]->query_real_name())+" "+
     (ob[n]->query_hp() *10)/ ob[n]->query_mhp() +
      "/"+"10"+"   ");
if(ob[n]->query_attack()) { write((ob[n]->query_attack())->short()+" has "+
     (((ob[n]->query_attack())->query_hp() *10)/ (ob[n]->query_attack())->query_mhp())+"/"+"10"+"\n");}
else { write("Not in combat.\n"); }
} }
return 1;}
for(n = 0; n < sizeof(ob); n++) {
  if(present("mind_meld",ob[n]) && 
     present("mind_meld",ob[n])->query_base() == base) {
     msg = str;
     msg = format(msg,60);
     tell_object(ob[n],"<"+MAG+from+NORM+"> "+MAG+msg+NORM+"\n");
     }
     }
return 1;}

shut_link() {
object ob;
int n;
ob = users();
for(n = 0; n < sizeof(ob); n++) {
  if(present("mind_meld",ob[n]) && 
     present("mind_meld",ob[n])->query_base() == base) {
     tell_object(ob[n],"<"+MAG+from+NORM+"> "+HIB+"LINK OFF"+NORM+"\n");
     }
     }
destruct(this_object());
return 1;}

