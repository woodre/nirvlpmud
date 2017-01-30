#define ep environment(this_object())
#define epn ep->query_name()
string name, ans;

id(str) {return str == "ask"; }
string asker, f;
int once;

reset(arg) {
  if(arg) return;
  once = 0;
  call_out("check",30);
}

drop() {return 1; }

set_ask(str) { name = str; }
query_weight() {return 0;}
query_value() {return 0; }

init() {
if(this_player())
  if(this_player()->query_attack()) { destruct(this_object()); return 1; }
  if(!(ep->query_npc()) && !once) {
 tell_object(ep,capitalize(name)+" invites you to "+
         find_player(name)->query_possessive()+" room.\nDo you wish to go? <y/n> ");
    input_to("answer");
    return 1;}
}

answer(string f) {
string wheree;
  sscanf(f,"%s",ans);
  if(!find_player(name)) { tell_object(ep,"Inviter is no longer in play.\n");
  destruct(this_object());
  return 1;}
  if(this_player()->query_attack()) { destruct(this_object()); return 1; }
  if(ans != "y" & ans != "Y" || !f) {
    tell_object(ep,"You decline to go.\n");
    tell_object(find_player(name),capitalize(epn)+" declines the invite.\n");
  destruct(this_object());
  return 1;}
  if(!present("zzzb",environment(find_player(name)))) {
  tell_object(ep,"The inviter is no longer in the room to teleport to.\n");
  tell_object(find_player(name),"The invite is gone because you are no longer in an invite room.\n");
  destruct(this_object());
  return 1;}
  find_player(name)->add_spell_point(-55-random(5));
  if(wheree = call_other("obj/base_tele","teleport")) {
      ep->move_player("with an astonished look#"+wheree); 
      tell_object(find_player(name),"Something has gone wrong!\n"); }
  else {
  tell_room(environment(ep),capitalize(epn)+" vanishes!\n");
  move_object(ep,environment(find_player(name)));
  tell_room(environment(ep),capitalize(epn)+" appears.\n");
  }
  destruct(this_object());
return 1;}

check() {
if(!ep) return 1; 
  if(!find_player(name)) { tell_object(ep,"Inviter is no longer in player.\n");
  destruct(this_object());
  return 1;}
  tell_object(ep,"Time for invite is over.\n");
  tell_object(find_player(name),"The invite for "+epn+"'s time is up.\n");
  destruct(this_object());
return 1;}
