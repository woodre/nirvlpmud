#include "/players/mythos/closed/ansi.h"
string owner;
int num;

id(str) {return str == "distraction"; }

long() {write("Your eyes seem unable to focus on "+capitalize(owner)+".\n");}

set_owner(str) { owner = str;}
query_owner() { return owner;}
set_num(n) { num = n;}

get() {return 0; }

query_weight() {return 1000;}
query_value() {return 0; }

reset(arg) {
  if(arg) return;
  if(!owner)
   owner = "kjsahdkadkhakdakhd";
    call_out("shadow",1);}

init() {
  add_action("nspell","kill");
  add_action("nspell","missile",2);
  add_action("nspell","shock",2);
  add_action("nspell","fireball",2);
  add_action("nspell","sonic",2); 
  add_action("dlook","look");
  add_action("dex","examine");
}

dex(str) {
  if(!str) { write("What?\n"); return 1;}
  if(str == owner) { long(); return 1;}
}
  
dlook(str) {
string what;
  if(str)
  if(sscanf(str,"at %s",what) == 1) { dex(what); return 1;}
}

nspell(str) {
  if(str == owner) {
    if(call_other(this_player(),"query_attrib","int") < random(num*10)) {
    write("Your eyes trick you.  You seem unable to hit "+capitalize(owner)+".\n");
    say(capitalize(this_player()->query_real_name())+" yells: ATTACK!\n"+
        "Strangely, "+this_player()->query_pronoun()+" strikes at the open air.\n");
    return 1;}
    }
}      
    
shadow() {
object pest;
pest=find_player(owner);
if(!pest) destruct(this_object());
if(pest->query_ghost() || !((pest->query_attack())->query_npc())) {
tell_object(pest,"Distraction has disappeared.\n");
destruct(present("shadowcon",pest));
 destruct(this_object());
 return 1;}
  if(environment(pest) != environment(this_object())) {
 move_object(this_object(),environment(pest)); }
 call_out("shadow",1);
return 1;} 

query_shatter_proof() { return 1;}
