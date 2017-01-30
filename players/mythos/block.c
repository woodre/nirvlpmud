#define eo environment(this_object())
id(str) { return str == "still" || str == "h1r2" || str == "dark_cloak"; }
int hit,spell,rate;

drop() { return 1; }
get() { return 0; }

reset(arg) {
hit = 1; spell = 1; rate = 1;
call_out("check",1);
}
init() {
  add_action("no","kill");
  add_action("no","sonic",2);
  add_action("no","missle",2);
  add_action("no","shock",2);
  add_action("no","fireball",2);
  add_action("hhp","hhp");
  add_action("hsp","hsp");
  add_action("hr","hr");
  add_action("both","both");
  call_out("allo",6);
  call_out("heart",3);
}

allo() {
  tell_object(eo,
      "You may change the type of healing as well as rate.\n"+
      "type 'hhp' to heal only hp\n"+
      "type 'hsp' to heal only sp\n"+
      "type 'both' to heal both\n"+
      "type 'hr #' to heal # amount of points per heartbeat\n"+
      "cost is 30 coins per hp or sp, 60 for both\n"+
      "\nDefault values are : 1 point of both per heartbeat\n"+
      "\n\n                              - Mythos\n");
return 1; }

hhp() { hit = 1; spell = 0; write("You are healing hp at "+rate+" per hb\n"); return 1; }

hsp() { hit = 0; spell = 1; write("You are healing sp at "+rate+" per hb\n"); return 1; }

both() { hit = 1; spell = 1; write("You are healing both at "+rate+" per hb\n"); return 1; }

hr(str) { int x; if(!str) return 0; if(sscanf(str,"%d",x) != 1) return 0; if(x < 1) x = 1; if(x>49) x = 49; rate =x; write("The rate is "+rate+" point per hb\n"); return 1; }
check() {
  if(!eo) { destruct(this_object()); return 1; }
return 1; }
no() { write("You may not do that here.\n"); return 1; }

heart() {
  if(!eo) { destruct(this_object()); return 1; }
  if(eo->query_npc() || eo->is_pet()) {
      destruct(this_object()); return 1; }
  if(eo->query_money() < 60) {
      tell_object(eo,"You don't have enough money.\n");
/*
  if(eo->query_money() < 0) eo->hit_player(-(eo->query_money()));
*/
  call_out("heart",9);
  return 1;
  }
  if(eo->query_hp() < eo->query_mhp() && hit) {
    eo->add_hit_point(rate);
  tell_object(eo,"You have been healed "+rate+" hp\n");
   eo->add_money(-30*rate);
}
  if(eo->query_sp() < eo->query_msp() && spell) {
    eo->add_spell_point(rate);
   eo->add_money(-30*rate);
  tell_object(eo,"You have been healed "+rate+" sp\n");
}
  /*  the healing rules are for non-intox/non-stuff
       cost is 60 per point , however that is for both 1hp and 1 sp
   so in this case i split it 30 coins of either sp or hp 60 if both
    - mythos 7-10-97 */
call_out("heart",3);
return 1; }
