heart_beat(){
  object me, myenv;
  me = environment();
  cout += 1;
if(cout >= 12) {
cout = 0;
}
switch(cout){
  case 2: light_damage();
  break;
  case 4: align_hurt();
  break;
  case 6: light_damage();
  break;
  case 7: align_hurt();
  break;
  case 8: light_damage();
  break;
  case 9: test_stats();
  break;
  case 10: light_damage();
  break;
  case 12: light_damage();
  break;
  case 13..2000: return 0;
  break;
/*
    case 4: align_hurt();
  break;

    case 8: test_stats();
  break;

    case 10: light_damage();
  break;
    case 11..2000: return 0;
  break;
*/
}
/*
  if(cout == 4){
this_object()->align_hurt;
return 1;
}
if(cout == 10){
test_stats
return 1;
}
*/
if(query_spell_delay()) add_spell_delay(-1);
    if(query_spell_delay() == 1) tell_object(USER,
      YEL+"You regain use of all your skills.\n"+NORM);
if(query_spell_delay() < 0) set_spell_delay(0);
  if(!me || !me->is_player()) return;
  myenv = environment(me);
  if(!myenv) return;
/*
  if(me->query_attack() && me->query_alignment() < 0) d_attack();
*/
if(me->query_attack()) d_attack();
  if(me->query_level() < 21 &&  !me->query_attack() && !random(4)) s_mess();
    if(me->query_hp() < 5 && !me->query_attack()  && me->query_ghost() == 0) kill_me(me);
  return 1;
  }

d_attack(){
 object target, me, targetn;
  int w, p, z, dex, wepwc;
 string mess, color;
 me = environment();
 target = me->query_attack();
 targetn = target->query_name();
  w = random(10);
 p = random(50);
 z = random(6);
  switch(p){
   case 1..2: mess = ""+me->query_name()+" strikes terror through "+capitalize(targetn)+"."; break;
   case 3..4: mess = "\n\t\t"+HIK+"D A R K N E S S"+NORM+"\nErupts from the ground engulfing "+HIY+capitalize(targetn)+NORM+" in\n\t\t"+HIR+"  F L A M E S"+NORM+".\n"; break;
   case 5..6: mess = "\n\t"+RED+"C H A O S"+NORM+" rips through "+capitalize(targetn)+"'s soul.\n"; break;
   case 7: mess = "Evil erupts from "+me->query_name()+" leaving "+capitalize(targetn)+" in pain"; break;
   case 8: mess = capitalize(targetn)+" cowers before pure evil"; break;
   case 9: mess = "Darkness assists "+me->query_name()+"'s attack"; break;
   case 10: mess = ""+me->query_name()+" screams, You don't know my hate!"; break;
   case 11..13: mess = "B L O O D"; break;
   case 14..17: mess = "H A T E"; break;
   case 18..19: mess = "K I L L"; break; 
   case 20: mess = "D E S T R O Y"; break;
   case 21..50: return;
   }
  switch(z){
   case 0: color = HIK; break;
   case 1: color = HIR; break;
   case 2: color = HIB; break;
   case 3: color = HIK; break;
   case 4: color = BLU; break;
   case 5: color = RED; break;
   }
 if(p > w){
tell_room(environment(environment(this_object())),color+"\t"+mess+"\n"+NORM);

   return 1;}
}

s_mess(){
 object target, me, targetn;
  int k, l, m;
 string mess, color;
 me = environment();
 k = random(21);
 l = random(250);
 m = random(6);
  switch(k){
   case 1..2: mess = "A voice whispers to you:   "+HIR+"K I L L"; break;
   case 3..4: mess = "A voice whispers to you:   "+HIR+"D E S T R O Y"; break;
   case 5..6: mess = "A voice whispers to you:  FEED ME "+HIR+"BLOOD!"; break;
   case 7..9: mess = "A voice whispers to you: Feel my "+HIG+"H A T E!"; break;
   case 10: mess = "A voice whispers to you:   "+HIR+"B L O O D"; break;
   case 11..20: return;

   }
  switch(m){
   case 0: color = HIK; break;
   case 1: color = HIR; break;
   case 2: color = HIB; break;
   case 3: color = HIK; break;
   case 4: color = BLU; break;
   case 5: color = RED; break;
   }
 if(k > l){
 tell_object(USER, color+""+mess+"\n"+NORM);
   return 1;}
}

kill_mee(ob) {
  object goodness;
  goodness=clone_object("/players/pestilence/closed/dark/mob/goodness.c");
  tell_object(ob, HIW+"\n\n\tYour GOODY GOODY GOODNESS TAKES YOUR LIFE!\n\n"+NORM);
  move_object(goodness, environment(ob));
  ob->attacked_by(goodness);
  ob->hit_player(100000, "other|pestilence");
  destruct(goodness);
  return 1;
}
kill_me(ob) {
  object sand;
  sand=clone_object("/players/pestilence/closed/dark/mob/light.c");
  tell_object(ob, HIW+"\n\n\tTHE LIGHT TAKES YOUR LIFE!\n\n"+NORM);
  move_object(sand, environment(ob));
  ob->attacked_by(sand);
  ob->hit_player(100000, "other|snow");
  destruct(sand);
  return 1;
}
align_hurt() {
    if(USER->query_ghost()) return 0;
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
   if(USER->query_alignment() > 300 && me->query_hp() > 40){
    tell_object(environment(this_object()),
      ""+HIK+"You feel pain from the goodness inside you"+NORM+".\n");
    if(interactive(ETO)) 
    ETO->hit_player(25 + random(20), "other|pestilence");
/*
    call_out("align_hurt",random(30));
*/
      if(me->query_hp() < 20) kill_mee(me);
    return 1; }
  else {
/*
    call_out("align_hurt",random(30));
*/
 }
   }
}
}
