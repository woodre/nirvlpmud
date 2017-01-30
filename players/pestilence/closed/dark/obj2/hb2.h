heart_beat(){
  object me, myenv;
  me = environment();
  if(!me || !me->is_player()) return;
  myenv = environment(me);
  if(!myenv) return;
  if(me->query_attack() && me->query_alignment() < 0) d_attack();
if(me->query_level() < 21 &&  !me->query_attack() && !random(2)) s_mess();
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
  int w, p, z, dex, wepwc;
 string mess, color;
 me = environment();
 target = me->query_attack();
 targetn = target->query_name();
  w = 0;
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
   case 21..50: mess = ""; break;
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
/*
  wepwc = USER->query_second_weapon();
 wepwc = present("dknight_ob",USER)->query_offwep_wc();
   if(present("dknight_ob",USER)->query_offwep()) {;  
    wepwc = present("dknight_ob",USER)->query_offwep()->weapon_class();
   }
   else {
   wepwc = 0;
   }
             if(present("dknight_ob",USER)->query_offwep()) dex = random(20);
*/
   target->hit_player(2 + random(wepwc));
/*
if(USER->query_real_name() == "pestilence" || "pesty" ) tell_object(USER, "Hit_player DAM IS: "+dex+" and wc dam is "+wepwc+".\n");
*/
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
