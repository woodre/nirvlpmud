heart_beat(){
  object me, myenv;
  me = environment();
  if(!me || !me->is_player()) return;
  myenv = environment(me);
  if(!myenv) return;
  if(me->query_attack() && me->query_alignment() < 0) d_attack();
/*
if(USER->query_invis() && !random(4)) mp -= 1;
if(USER->query_invis() && mp < 15){
  tell_object(USER,"\nYou run out of enough spell points to sustain darkness."+NORM+"\n\n");
  USER->visible();
  }
if(USER->query_invis() && USER->query_level() < 20 && me->query_sp() > 15) USER->set_invs_sp();
*/
  return 1;
  }

d_attack(){
 object target, me, targetn;
 int w, p, z;
 string mess, color;
 me = environment();
 target = me->query_attack();
 targetn = target->query_name();
  w = random(4);
 p = random(9);
 z = random(6);
  switch(p){
   case 1..2: mess = ""+me->query_name()+" strikes terror through "+capitalize(targetn)+"."; break;
   case 3..4: mess = "\n\t\t"+HIK+"D A R K N E S S"+NORM+"\nErupts from the ground engulfing "+HIY+capitalize(targetn)+NORM+" in\n\t\t"+HIR+"  F L A M E S"+NORM+".\n"; break;
   case 5..6: mess = "\n\t"+RED+"C H A O S"+NORM+" rips through "+capitalize(targetn)+"'s soul.\n"; break;
   case 7: mess = "Evil erupts from "+me->query_name()+" leaving "+capitalize(targetn)+" in pain"; break;
   case 8: mess = capitalize(targetn)+" cowers before pure evil"; break;
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
   target->hit_player(2); 
   return 1;}
}
