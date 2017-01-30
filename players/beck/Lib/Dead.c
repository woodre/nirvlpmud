
Died(){
   object corpse;
/* We died ! */
   dieing = 1;
   if (hunter)
      call_other(hunter, "stop_hunter");
   hunter = 0;
   hunted = 0;
   say(cap_name + " died.\n");
   attacker_ob->Killed(this_object(),this_object()->query_name());
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
      HitPoint = max_hp/3;
hit_point = max_hp/3;
   else
      HitPoint = 10;
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

