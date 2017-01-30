#include "/players/mythos/closed/ansi.h"
string owner,msg, form1, form2;
object pest;
id(str) {return str == "sform" || str == form1 || str == form2; }

long() {write(msg);}

set_owner(str) { owner = str; pest = find_player(owner);}
query_owner() { return owner;}
set_form1(str) { form1 = str;}
set_form2(str) { form2 = str;}
set_msg(str) { msg = str;}
		
get() {return 0; }

query_weight() {return 1000;}
query_value() {return 0; }

reset(arg) {
  if(arg) return;
  call_out("shadow",1); }

init() {
  add_action("form_off","form_off");
  add_action("nspell","kill");
  add_action("nspell","missile",2);
  add_action("nspell","shock",2);
  add_action("nspell","fireball",2);
  add_action("nspell","sonic",2); 
  add_action("slook","look at");
  add_action("sexa","examine");
}

sexa(str) {
  if(!str) { write("What?\n"); return 1;}
  if(str == owner) { long(); return 1;}
}
  
slook(str) {
   sexa(str); return 1;
}

nspell(str) {
  if(str == form1 || str == form2) {
    if((find_player(owner)->query_pl_k() && this_player()->query_pl_k()) ||
    this_player()->query_fight_area() && this_player()->query_real_name() != owner) {
    this_player()->attack_object(find_player(owner));
    find_player(owner)->attack_object(this_player());
    return 1;}
    return 1;}
}

form_off() {
  if(this_player()->query_real_name() == owner) {
    tell_room(environment(pest),"The form of the "+capitalize(form1)+" shimmers.\n"+
          capitalize(owner)+" is back to normal.\n");
    command("smn",this_player());
 destruct(present("form_ob",this_player()));
 destruct(this_object());
 return 1;}
}

shadow() {
if(!pest) { destruct(this_object()); return 1; }
if(pest->query_ghost() || !(pest->query_interactive())) {
tell_room(environment(pest),"The form of the "+capitalize(form1)+" shimmers.\n"+
          capitalize(owner)+" is back to normal.\n");
    present("form_ob",this_player())->normal();
  destruct(present("form_ob",this_player()));
 destruct(this_object());
 return 1;}
 if(!present(owner,environment(this_object()))) {
 move_object(this_object(),environment(pest)); }
 call_out("shadow",1);
return 1;} 

query_shatter_proof() { return 1;} 
