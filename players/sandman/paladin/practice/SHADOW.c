
/*
 * PRACTICE SHADOW
 * Prevents player from being killed or recieving experience
 * during practice sessions
 */

object player;
int max_exp;

short() { return player->short()+" [PRACTICING]"; }

query_practice_shadow() { return 1; }

start_practice_shadow(who) {
   player = who;
   max_exp = player->query_exp();
   shadow(player, 1);
   return 1;
}

stop_practice_shadow() {
   adjust_exp();
/*
   player->heal_self(10000);
  I changed the heal_selfs to add_hitpoint because players
  were abusing it to heal spellpoints, -mizan 1 dec 95
*/
   player->add_hit_point(10000);
   shadow(this_player(), 0);
   destruct(this_object());
   return 1;
}

quit() {
   adjust_exp();
/*
   player->heal_self(10000);
   here too
 */
   player->add_hit_point(10000);
   shadow(this_player(), 0);
   this_player()->quit();
   return 1;
}

hit_player(dam) {
   string junk1, junk2, where;
   
   where = file_name(environment(player));
   if(sscanf(where, "%s/sandman/paladin/practice/%s",junk1,junk2) != 2) {
     write("You are no longer in the practice area.\n");
     write("Destructing shadow.....\n");
     stop_practice_shadow();
     return 1;
   }
   if(dam >= player->query_hp()) {
     tell_object(player,"      *****You are protected from death*****\n");
     return 1;
   } else
   player->hit_player(dam);
   return dam;
}

add_exp(amt) {
   write("You are in a practice session. No experience gained.\n");
   return 1;
}

adjust_exp() {
   int current_exp, exp_adjustment;

   current_exp = player->query_exp();
   if(current_exp > max_exp) {
     write("Adjusting experience........\n");
     exp_adjustment = current_exp - max_exp;
     player->add_exp(-exp_adjustment);
   }
   return 1;
}
