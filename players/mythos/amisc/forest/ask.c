#define ep environment(this_object())
#define epn ep->query_name()

id(str) {return str == "ask"; }
string asker, f;
int once;

reset(arg) {
  if(arg) return;
  once = 0;
}

drop() {return 1; }

query_weight() {return 0;}
query_value() {return 0; }

set_asker(str) { asker=str; }

init() {
  if(!ep) return 1;
  add_action("off","off");
  add_action("answer","fyes");
  if(!(ep->query_npc()) && !once) {
  if(ep->query_attack()) { destruct(this_object()); return 1; }
 tell_object(find_player(lower_case(asker)),"You ask "+capitalize(epn)+" to follow.\n");
    tell_object(ep,capitalize(asker)+" wishes for you to follow.\n"+
          "If you wish to follow type 'fyes'\n"+
          "Note: this will abort in 10 sec.\n");
    call_out("mooo",20);
    }
}

answer() {
  tell_object(ep,"You follow "+capitalize(asker)+".\nTo turn it off type <off>\n");
  tell_object(find_player(lower_case(asker)),capitalize(epn)+" follows you.\n");
  once = 1;
  remove_call_out("mooo");
  call_out("follow",2);
  return 1;}

follow() {
object pask;
if(!ep) { destruct(this_object()); return 1; }
if(ep->query_ghost()) { off(); return 1;}
if(!present(lower_case(asker),environment(ep))) {
pask=find_player(lower_case(asker));
if(!pask || !(pask->query_interactive())) { tell_object(ep,"The leader is no longer in Nirvana\n"); off(); return 1;}
if(pask->query_ghost()) { tell_object(ep,"The leader is dead.\n"); off(); return 1;}
if(environment(pask)->realm() == "NT") { 
tell_object(ep,"The leader is in a place that can not be entered.\n");
call_out("follow",6); return 1;}
 tell_room(environment(ep),capitalize(epn)+
    " leaves following "+capitalize(asker)+".\n");
 move_object(ep,environment(pask)); 
  tell_room(environment(ep),capitalize(epn)+
    " enters following "+capitalize(asker)+".\n");}
 call_out("follow",2);
return 1;}

mooo() { 
  if(ep) {
   tell_object(ep,"Flute follow aborted.\n");
   if(find_player(lower_case(asker))) 
     tell_object(find_player(lower_case(asker)),"Flute follow aborted.\n");
  destruct(this_object()); }
return 1; }

off() {
  tell_object(ep,"You turn off the follow.\n");
if(find_player(lower_case(asker))) {
tell_object(find_player(lower_case(asker)),capitalize(epn)+" turns off the follow.\n");
}
  destruct(this_object());
return 1;}
