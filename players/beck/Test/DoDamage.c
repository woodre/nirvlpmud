mapping Objects;

void RegisterObject(object gear, mixed *params){
   if(Objects == 0){ Objects = ([ ]); }
   Objects[gear] = params;
}

RemoveObject(object gear){
   if(Objects == 0){ Objects = ([ ]); }
   Objects[gear] = 0;
}


/*
 * This function is called from other players when they want to make
 * damage to us. We return how much damage we received, which will
 * change the attackers score. This routine is probably called from
 * heart_beat() from another player.
 */
DoDamage(int *damage, string *method){
   int i, j, k;
   string type;
   int dam, total, class, res, temp, itemp;
   string cat,subcat;
   mixed *armors2;
   object *armors;
   
/***********************************/
/*  BEGIN ADDITIONS FOR MULTIPLE   */
/*  TYPES OF DEFENSE               */
/*  Coded by Beck                  */
/***********************************/
   if(!damage) return 0;
   for(i=0; i<sizeof(damage); i++){
      if(damage[i]){
         dam = damage[i];
         class = 0;
         res = 0;
         if(method[i]){
            type = method[i];
            if(sscanf(type, "%s|%s",cat,subcat) !=2){
               if(type != "physical" && type != "magical") type = "physical";
            }
            else if(cat != "other") type = "physical";
         }
         else type = "physical";
/* Add in individual object modifications from mapping Objects */
         if(Objects){
            armors = keys(Objects);
            for(k=0; k<sizeof(armors); k++){
               if(Objects[armors[k]]){
                  armors2 = Objects[armors[k]];
                  itemp = member_array(type,armors2);
                  if(itemp != -1){
                     class += armors2[itemp+1];
                     res += armors2[itemp+2];
                     if(armors2[itemp+3]){
                        temp = call_other(armors[k],armors2[itemp+3]);
                        res += temp/100;
                        class += temp - ((temp/100)*100);  
                     }
                  }
               }     
            }
         }
         if(res > 100) res = 100;
/* Calculate new damage */
         res = 100 - res;
         dam = res*dam;
         dam = dam/100;
         dam -= random(class + 1);
         total += dam;  
         say("Type: "+type+" Dam: "+dam+" Res: "+res+"\n");
      }
      
   }
   if (total <= 0)
      return 0;
/* PUT a cap on damage a player can do in one hit. */
   if(this_object()->query_attack())
      if(query_attack()->query_level() < WIZARD && query_attack()->is_player()){
         if(total > 56) total = 56;
      }
   hit_point -= total;   
   if (hit_point<0) {
      this_object()->Died();
      destruct(this_object());
   }
   return total;
}

Died(){
   object corpse;
/* We died ! */
   dieing = 1;
   if (hunter)
      call_other(hunter, "stop_hunter");
   hunter = 0;
   hunted = 0;
   say(cap_name + " died.\n");
/* If this is a player, log the death for future reference */
   if(!is_npc && environment(this_object())->query_spar_area())
      log_file("DEATHS","Spar-> ");
   if (!is_npc) 
      if (attacker_ob)
         log_file("DEATHS", ctime(time()) + " " + name + " " + experience + " exp " + money + " gold killed by " +
            call_other(attacker_ob, "query_real_name", 0) + ".\n");
   else {
      log_file("DEATHS", ctime(time()) + "  " + name + " " + experience + " exp "+money + " gold - killer unknown.\n");
      if(this_player()) log_file("DEATHS","this_player is "+this_player()->query_real_name() +"   "+this_player()->query_name()+"\n");
   }
   if (!is_npc){
      tell_object(this_object(), "\n\nYou feel very weak as your badly damaged body falls to the ground to die.\n");
      if(!environment(this_object())->query_spar_area()) {
         experience = (experience * 3) / 4;  /* Take away 1/4 of exp. */
         lower_attrib();
      }
      call_other(this_object(), "clear_crime");
      call_other(this_object(),"rm_pk",0);
   }
   if (max_hp)
      hit_point = max_hp/3;
   else
      hit_point = 10;
   corpse = clone_object("obj/corpse");
   call_other(corpse, "set_name", name);
   call_other(corpse, "set_corpse_level", level);
   if(!is_npc) { 
      set_ghost(1);
      move_object(corpse, environment(this_object()));
   }
   transfer_all_to(corpse);
   if(!is_npc) set_ghost(0);
   if (!attacker_ob)
      attacker_ob = alt_attacker_ob;
   if (!is_npc) {
      see_if_other(3); /* prevent cheating */
      this_object()->save_me();
   }
/* The player killing us will update his alignment */
/* and experience if he exists. */
/* Note that you get no experience for killing other players! */
/* that last line was not true before.. it is now. */
   else if(attacker_ob && is_npc) {
      int wa_bonus, exp_diff, exp_bonus, base_bonus;
      object party;
      call_other(attacker_ob, "add_alignment", ADJ_ALIGNMENT(alignment));
/* Give some more experience for staying in your alignment
 * All the following basically works out to
 * exp_bonus = abs(monster's align - player's align)/75000 * exp;
 * Of course we can't just say that because of underflow problems.
*/
      if (is_npc && experience > 1000000) {
/*
     log_file("EXTRA_EXP", name + " " + creator(this_object()) + call_other(attacker_ob, "query_name",0) + "\n");
*/
         experience = 1000000;
      }
      exp_diff = (alignment - call_other(attacker_ob,"query_alignment",0));
      if (exp_diff < 0)
         exp_diff = -exp_diff;   /* Get absolute value */
      exp_diff /= 10;   /* Scale this down so we don't overflow! */
      exp_bonus = experience / 100;
      exp_bonus *= exp_diff;
      exp_bonus /= ALIGN_EXP_DIVISOR;
/* Base bonus regardless of alignment is experience/75 */
      base_bonus = experience/EXP_DIVISOR;
/* Don't let the alignment bonus exceed 1/2 the base bonus */
      if (exp_bonus > base_bonus/2)
         exp_bonus = base_bonus/2;
      exp_bonus += base_bonus;
      wa_bonus = weapon_class * armor_class * WA_FACTOR;
      if (wa_bonus > base_bonus/3)
         wa_bonus = base_bonus/3;
      exp_bonus += wa_bonus;
      party=present("party object", attacker_ob);
      if(party) exp_bonus = 24*exp_bonus/30;
      if(!no_exp_value) {
         if (party) party->share_exp(exp_bonus);
         if(!party)
            call_other(attacker_ob, "add_exp", exp_bonus);
      }
   }
   move_object(corpse, environment(this_object()));
   dieing = 0;
call_other(this_object(), "second_life",0);
}

hit_player(dam1, type1, dam2, type2,zap) {
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
