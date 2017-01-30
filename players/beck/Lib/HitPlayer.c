query_hp(){ return this_object()->QHitPoint(); }

hit_player(dam1, zap, type1, dam2, type2) {
   int i,dam,dam3,ac_tmp;
   int type1class,type2class,type1res,type2res,j,temp;
   object pro_object;   /* paladin weapon pro & combat method object */
   object templar_ob; /*templar object*/
   if(dieing) {
      if(dieing < 8) return 0;
      dieing +=1;
   }
   /* if we are in the death sequence do not allow access to hit_player() */
   if(!is_npc)
      if(!this_object()->query_interactive()) {
         say(cap_name+" is disconnected.\n");
         stop_fight(); if(this_player()) this_player()->stop_fight();
         return 0;
      }
   if (this_player() && this_player() != this_object() && this_player()->query_level() < EXPLORE) {
      /* -= Protection =- */  
      if ( this_player()->is_player() &&
         this_player()->query_attack() != this_object() &&
         !this_player()->valid_attack( this_object())){
    /* bad attack, could be logged */
         write( "Your attack fails.\n");
         return 0;
      }
      if(this_object()->is_player() &&
         !is_npc && !this_object()->query_interactive())
         return 0;
      if ( attacker_ob == alt_attacker_ob || !alt_attacker_ob)
         attacked_by( this_player());
    /* -= Crime =- */
      if ( this_player()->query_level() < EXPLORE &&
         (!is_npc || this_object()->crime_to_attack()))
         if(!this_object()->query_crime() && !this_player()->query_crime())
            this_player()->set_crime();
   }
   if (level >= 21 && !is_npc)   /* You can't hit a wizard ! */
      return 0;
   if(ghost == 1) return 0; /* You cannot hit the dead! */

   return DoDamage(({dam1,dam2}),({type1,type2}));
}   
