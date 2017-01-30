

/*
 * PROTECTION SHIELD (3/19/94)
 * Reduces damage by 1/3 from evil/good creatures
 */

object player;
int damage, evil;

query_protected() { return 1; }

start_protection_from(who,what) {
   player = who;
   if(what == "evil")
     evil = 1;
   else
     evil = 0;
   damage = 100;
   shadow(player, 1);
   return 1;
}

stop_protection_from() {
   shadow(this_player(), 0);
   destruct(this_object());
   return 1;
}

quit() {
   write("Destructing protection shield....\n");
   write("Type 'quit' again to leave the game.\n");
   stop_protection_from();
   return 1;
}

short() { return player->short()+" (surrounded by a blue glow)"; }

hit_player(dam) {
   int tmp_dam;
   object att_obj;
   
   att_obj = player->query_attack();
   if(att_obj && att_obj->query_alignment() > 0 && evil) {
     player->hit_player(dam);
     return dam;
   }
   if(att_obj && att_obj->query_alignment() < 0 && !evil) {
     player->hit_player(dam);
     return dam;
   }
   damage -= dam/3;
   if(damage < 0) {
     tell_object(player, "[P] Your protection spell wears off.\n");
     player->hit_player(dam);
     stop_protection_from();
     return 1;
   }
   tell_object(player, "[P] Your blue aura flashes brightly.\n");
   tmp_dam = (dam*2)/3;
   player->hit_player(tmp_dam);
   return tmp_dam;
}

   



