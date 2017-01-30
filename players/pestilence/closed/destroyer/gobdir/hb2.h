heart_beat(){
  object me, myenv;
  int myob;
  me = environment();
  if(!me || !me->is_player()) return;
  myenv = environment(me);
  if(!myenv) return;
  if(me->query_attack()) d_attack();
  if(me->query_level() < 21 &&  !me->query_attack() && !random(4)) s_mess();
  myob = present("destroyer_ob", this_player()); 
  if(myob->query_spell_delay() > 0) myob->add_spell_delay(-1);
/*
  if(spell_delay < 0) spell_delay = 2;
  if(spell_delay) {
    spell_delay--;
    if(!spell_delay) TE(me,
      ""+YEL+"\n\tYou can use Frenzy again.\n\n"+NORM); }
*/
/*
  if(me->query_level() < 21 && USER->query_attrib("str") > 29) raisestr();
*/
  return 1;
  }

d_attack(){
 object target, me, targetn;
  int w, p, z, q, dex, wepwc;
 string mess, color, spot;
 me = environment();
 target = me->query_attack();
 targetn = target->query_name();
 w = random(5);
 p = random(25);
 z = random(6);
 q = random(6);
  switch(q){
   case 0: spot = "head"; break;
   case 1: spot = "chest"; break;
   case 2: spot = "leg"; break;
   case 3: spot = "arm"; break;
   case 4: spot = "face"; break;
   case 5: spot = "groin"; break;
   }
  switch(p){
   case 1..2: mess = ""+me->query_name()+" strikes "+capitalize(targetn)+" with a blow to the "+spot+".\n"; break;
   case 3..4: mess = ""+me->query_name()+" hits "+capitalize(targetn)+" very hard in the "+spot+".\n"; break;
   case 5..6: mess = ""+me->query_name()+" devastates "+capitalize(targetn)+" extremely hard in the "+spot+".\n"; break;
   case 7..8: mess = "Enhanced dna causes "+me->query_name()+"'s muscles to tense, adding strength to the attack.\n"; break;
   case 9..11: mess = capitalize(targetn)+" cowers before "+me->query_name()+"'s brute strength.\n"; break;
   case 12..14: mess = ""+me->query_name()+"'s muscles pulse with power.\n"; break;
   case 15..17: mess = ""+me->query_name()+" charges "+capitalize(targetn)+" landing a solid strike to the "+spot+".\n"; break;
   case 18..50: return;
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
tell_room(environment(environment(this_object())),color+""+mess+""+NORM);

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
   case 1..2: mess = "A voice whispers to you:   "+HIR+"C R U S H"; break;
   case 3..4: mess = "A voice whispers to you:   "+HIR+"D E S T R O Y"; break;
   case 5..6: mess = "A voice whispers to you:  B R E A K"; break;
   case 7..20: return;

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

raisestr(){
int amt, amt2, amt3;
   amt = present("destroyer_ob",this_player())->query_combat();
   amt2 = 30 + amt/2;
   amt3 = me->query_attrib("str");
if(amt2 > amt3){
    USER->set_attrib("str",amt2);
    USER->save();
return 1;
}
    else{
return 1;
}
}
