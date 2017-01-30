
/*
 * SPARRING SHADOW (4/5/94)
 * Shadow used for players who are sparring against each other
 */

/* Maximum hp/sp which can be added to a player */
#define MAXHP 0
#define MAXSP 0

/* Max damage done at one time */
#define MAXDAM 35

object player;
int max_exp, total_hp, total_sp;

short() { return player->short()+" [SPARRING]"; }

query_sparring_shadow() { return 1; }

query_pl_k() { return 1; }

start_sparring_shadow(who) {
   player = who;
   max_exp = player->query_exp();
   total_hp = 0;
   total_sp = 0;
   shadow(player, 1);
   return 1;
}

stop_sparring_shadow() {
   adjust_exp();
   shadow(player, 0);
   destruct(this_object());
   return 1;
}

quit() {
   string junk1, junk2, where;
   
   where = file_name(environment(player));
   if(sscanf(where, "%s/molasar/sparring%s",junk1,junk2) != 2 ||
      !query_ip_number(player)) { 
     adjust_exp();
     shadow(player, 0);
     player->quit();
     return 1;
   }
   write("You may not quit in sparring room....\n");
   return 1;
}

hit_player(dam) {
   string junk1, junk2, where;
   
   where = file_name(environment(player));
   if(sscanf(where, "%s/molasar/sparring%s",junk1,junk2) != 2){
     write("You are no longer in the sparring area.\n");
     write("Destructing shadow.....\n");
     player->heal_self(100000);
     stop_sparring_shadow();
     return 1;
   }
   if(dam > MAXDAM)
     dam = MAXDAM;
   if(dam >= player->query_hp()) {
     tell_object(player,"\n\n      *****You have been defeated*****\n\n");
     environment(player)->stop_fight(player->query_real_name(),
            (player->query_attack())->query_real_name());
     return 1;
   } else
   player->hit_player(dam);
   return dam;
}

heal_self(arg) {
   add_hit_point(arg);
   add_spell_point(arg);
}

add_hit_point(arg) {
   if(arg < 0)
     return 1;
   if(total_hp >= MAXHP)
     return 1;
   if(arg + total_hp > MAXHP)
     arg = MAXHP - total_hp;
   player->add_hit_point(arg);
   total_hp += arg;
}

add_spell_point(arg) {
   if(arg < 0) {
     player->add_spell_point(arg);
     return 1;
   }
   if(total_sp >= MAXSP)
     return 0;
   if(arg + total_sp > MAXSP)
     arg = MAXSP - total_sp;
   player->add_spell_point(arg);
   total_sp += arg;
}

add_exp(amt) {
   write("You are in a sparring session. No experience gained.\n");
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
