
heart_beat(){
  object me, myenv;
  me = environment();
  if(!me || !me->is_player()) return;
  myenv = environment(me);
  if(!myenv) return;
  if(me->query_level() < 20) stat_check();
  if(me->query_attack() && me->liched()) l_attack();
  if(me->query_attack() && me->dknighted()) d_attack();
  if(me->query_ghost() && me->query_attack()) stop_all();
  return 1;
  }

l_attack(){
 object target, me, targetn;
 int w, z, s;
 string mess2, color;
 me = environment();
 target = me->query_attack();
 targetn = target->query_name();
 s = 2+random(4);
 w = random(20);
 z = random(6);
  switch(s){
   case 2: mess2 = "Dark energy flows around the Lich"; break;
   case 3: mess2 = "Lich lashes out at "+capitalize(targetn)+""; break;
   case 4: mess2 = "The Lich strengthens your attack"; break;
   case 5: mess2 = capitalize(targetn)+" is wounded by a blow from the lich"; break;
   }
  switch(z){
   case 0: color = CYN; break;
   case 1: color = BOLD+BLK; break;
   case 2: color = BOLD+RED; break;
   case 3: color = HIR; break;
   case 4: color = HIY; break;
   case 5: color = BOLD+YEL; break;
   }
  if(s > w){
   tell_object(USER, color+"\t"+mess2+"\n"+NORM);
  }
 }

d_attack(){
 object target, me, targetn;
 int w, p, z;
 string mess1, color;
 me = environment();
 target = me->query_attack();
 targetn = target->query_name();
 w = random(20);
 p = 5+random(7);
 z = random(6);
  switch(p){
   case 5: mess1 = "Energy radiates around the Deathknight"; break;
   case 6: mess1 = "The Deathknight lashes out at "+capitalize(targetn)+""; break;
   case 7: mess1 = "The Deathknight lends power to your attack"; break;
   case 8: mess1 = capitalize(targetn)+" is crushed by a blow from the deathknight"; break;
   case 9: mess1 = "Energy radiates around the Deathknight"; break;
   case 10: mess1 = "The Deathknight lashes out at "+capitalize(targetn)+""; break;
   case 11: mess1 = "The Deathknight lends power to your attack"; break; 
   }
  switch(z){
   case 0: color = CYN; break;
   case 1: color = BOLD+BLK; break;
   case 2: color = BOLD+RED; break;
   case 3: color = HIR; break;
   case 4: color = HIY; break;
   case 5: color = BOLD+YEL; break;
   }
  if(p > w){
    if(p > w) tell_object(USER, color+"\t"+mess1+"\n"+NORM); 
  }
}

stop_all(){
 object me, target;
 me = environment();
 target = me->query_attack();
 if(target){
   me->stop_fight();
   target->stop_fight();
   target->stop_fight();
   me->stop_fight();
 }
}
