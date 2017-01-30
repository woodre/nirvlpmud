
/*
 * PROTECTION FROM EVIL SHIELD (5/20/94)
 * Reduces damage by 1/3 from evil creatures
 */

object player;
int damage, max_damage;

query_protected_from_evil() { return 1; }

#define BASE 75

start_protection_from_evil(who, amt) {
   player = who;
   damage = amt;
   damage += BASE;
   damage += (player->query_level()/2 * 10) + 10;
   damage += player->query_attrib("pie")/2 * 10;
   damage /= 2;
   max_damage = damage;
   shadow(player, 1);
   return 1;
}

stop_protection_from_evil() {
   shadow(player, 0);
   destruct(this_object());
   return 1;
}

quit() {
   shadow(player, 0);
   player->quit();
   return 1;
}

short() { return player->short()+" (surrounded by a blue glow)"; }

hit_player(dam) {
   int tmp_dam;
   object att_obj;

   att_obj = player->query_attack();
   if(att_obj && att_obj->query_alignment() > 0) {
     player->hit_player(dam);
     return dam;
   }
   damage -= dam/3;
   if(damage < 0) {
     tell_object(player, "[P] Your protection from evil spell wears off.\n");
     player->hit_player(dam);
     stop_protection_from_evil();
     return 1;
   }
   tell_object(player, "[P] Your blue aura flashes brightly. "+
       "Strength: "+((damage*100)/max_damage)+"%\n");
   tmp_dam = (dam*2)/3;
   player->hit_player(tmp_dam);
   return tmp_dam;
}

