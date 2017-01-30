#include "/players/mythos/closed/ansi.h"
#define eo environment(this_object())
#define to this_object()
#define tp this_player()
#define eoo environment(eo)
#define tre tell_room(eoo
int count;

id(str) { str == "aura_def"; }

short() { return HIR+"DarVast AURA"+NORM; }

extra_look() { return HIR+"DarVast Aura"+NORM; }

reset(arg) {
  if(arg) return ;
 count = 0;
 call_out("hb",3);
}

init() {
  if(eo == tp) {
    tre,CYN+"\n\t\t\tFLASH!\n\n"+NORM);
    double_check();
  }
}

hb() {
  if(eo) 
    if(eoo) {
      if(count < 4) {
       if(!eo->query_attack()) count++;
       else {
         count = 0;
         if(!random(10)) eo->set_ac(eo->query_ac() + 
                         random(5));
         else if(!random(10)) eo->set_wc(eo->query_wc() +
                         random(10); 
         else if(!random(3)) 
             eo->heal_self(eo->query_level() + 
               random(eo->query_level()));
       }
    call_out("hb",3);
    return 1; }
    destruct(to);
  } }
return 1; }

double_check() {
object ob;
int h;
ob = all_inventory(eo);
for(h=0;h<sizeof(ob);h++) {
   if(ob[h]->id("aura_def") && ob[h] != to) destruct(ob[h]);
}
return 1; }
