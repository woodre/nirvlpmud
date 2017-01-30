#include "/players/mythos/closed/ansi.h"
#define ep environment(this_object())
string form;
string tip;
string col;
int lev,time,switch;

id(str) { return str == "grenade" || str == "bounty_grenade" || str == "mgren" ||
                 str == tip+"Gren"; }

get() { return 1; }
drop() { return 0; }
query_weight() { return 1; }
query_value() { return lev; }
query_save_flag() { return 1; }

reset(arg) { if(arg) return; tip = ""; time = 5; switch = 0; col = NORM;}

set_form(str) { form = str; }
set_level(n) { lev = n; 
               if(lev == 69) col = BOLD; 
               else {
               switch(lev/4) {
                 case 0: col = NORM; break;
                 case 1: col = GRN; break;
                 case 2: col = BLU; break;
                 case 3: col = MAG; break;
                 case 4: col = RED; break;
                 case 5: col = HIR; break;}
              } }


short() { 
 string setting;
   if(!switch) setting = "[ OFF ]";
   else setting = "[ SET: "+col+time+NORM+" sec ]";
   if(lev != 69) tip = "";
   else tip = "Poison ";
return col+tip+"Grenade "+NORM+setting; }

long() { write(short());
         if(switch) write("\n");
         else write("\n");
         write("\n");
       }
       
init() { 
  add_action("set","set");
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
  
set(str) {
string msg,msg2;
  if(!str) return 0;
  if(id(str)) {
    if(form == "tech") {
      msg = "\n";
      msg2 = "\n"; 
    } else {
      msg = "\n";
      msg2 = "\n";
    }
    write(msg);
    say(msg2);
    set_on();
  return 1; }
}

set_on() {
object ob,ob2;
int h;
string msg;
  switch = 1; 
  if(!ep) return 1;
  if(living(ep)) tell_object(ep,"T-minus: "+col+time+NORM+" seconds\n");
  else tell_room(ep,"T-minus: "+col+time+NORM+" seconds\n");
  if(time < 1) {
      if(form == "tech") { if(lev != 69) msg = "\n";
      else msg = "\n"; }
      else { if(lev != 69) msg = "\n";
      else msg = "\n"; }
      if(living(ep) && !interactive(ep)) {
        tell_room(environment(ep),msg);
        ob = all_inventory(environment(ep));
        if(lev != 69) { lev = lev/2; 
        ep->heal_self(-lev); }
        else ep->heal_self(-random(10));
      } else { 
        tell_room(ep,msg);
        ob = all_inventory(ep);
      }
         for(h=0;h<sizeof(ob);h++) {
           if(living(ob[h])) {
             if(!interactive(ob[h])) {
             if(lev != 69) ob[h]->heal_self(-lev);
             else {
               ob[h]->heal_self(-random(5));
               ob2 = clone_object("/players/mythos/bounty/poison.c");
               ob2->set_level(1+random(10));
               move_object(ob2,ob[h]);
             }
          }
        }
      }
  destruct(this_object());
  return 1; }
  time = time - 1;
  call_out("set_on",5);
return 1; }
