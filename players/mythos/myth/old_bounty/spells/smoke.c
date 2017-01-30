#include "/players/mythos/closed/ansi.h"
#define ep environment(this_object())

id(str) { return str == "smoke bomb" || str == "smoke" || str == "msmoke" || 
                 str == "bomb"; }

get() { return 1; }
drop() { return 0; }
query_weight() { return 1; }
query_value() { return lev; }
query_save_flag() { return 0; }

short() { return "Smoke bomb"; }

long() { 
         write("\n");
       }
       
init() { 
  add_action("throw","fling");
  add_action("toss","toss");
}

toss(str) {
object ob;
  if(!str) { write("Usage: toss <name of player>\n"); return 1; }
  ob = find_player(str);
  if(!ob) { write("That player is not in game.\n"); return 1; }
  if(ob->query_invis() > 20) { write("That player is not in game.\n"); return 1; }
  if(in_editor(ob)) { write("That player is not in game.\n"); return 1; }
  this_player()->add_weight(-query_weight());
  write("\n");
  say("\n");
  ob->add_weight(query_weight());
  tell_object(ob,"\n");
  move_object(this_object(),ob);
return 1; }

throw(str) {
object ob;
if(ep == this_player()) { 
    this_player()->add_weight(-query_weight());
}
move_object(this_object(),environment(this_player()));
write("\n");
say("\n");
if(str) {
  ob = present(str,ep);
  if(!ob) { write("That target is not here.\n"+
                  "Smoke bomb set for all.\n"); 
            peace(1);
            return 1; }
  if(!living(ob)) { write("That target is not living.\n"+
                          "Smoke bomb set for all.\n"); 
                    peace(1);
                    return 1; }
  if(!ob->query_attack()) { write("That target is not in combat.\n"+
                                  "Smoke bomb set for all.\n"); 
                            peace(1);
                            return 1; }
  move_object(this_object(),ob);
  peace(0);
return 1; }
peace(1);
return 1; }

peace(arg) {
object ob;
int h;
  if(!arg) { 
  if(ep->query_attack()) { 
   (ep->query_attack())->stop_fight();
    ep->stop_fight(); 
    tell_object(ep,"\n");
    tell_room(environment(ep),"\n");
  } }
  else {
      tell_room(ep,"\n");
      ob = all_inventory(ep);
      for(h=0;h<sizeof(ob);h++) {
        if(living(ob[h])) {
            if(ob[h]->query_attack()) { 
              (ob[h]->query_attack())->stop_fight();
               ob[h]->stop_fight(); 
               tell_object(ob[h],"\n");
            }
        }
        }
      }
return 1; }
