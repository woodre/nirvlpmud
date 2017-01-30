/* this is the same hit_player() as found in living.c
   with a few mnor changes.  those changes being that
   with the additions of multiple attacks etc the xp values
   are raised - mythos <2-17-97> */

hit_player(dam,zap) {
 int i,dam2,ac_tmp;
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
 if(this_player())
 if (this_player() && this_player() != this_object() && this_player()->query_level() < EXPLORE) {
    /* -= Protection =- */  
    if ( this_player()->is_player() &&
         this_player()->query_attack() != this_object() &&
         !this_player()->valid_attack( this_object()))
    { /* bad attack, could be logged */
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
  if (!is_npc && armor_class > 9) {
    ac_tmp = 9;
   } else {
   ac_tmp = armor_class;
   }
    if(!is_npc && this_object()->query_pregnancy()){
     i = age - this_object()->query_pregnancy();
     i = i/5000;
     ac_tmp = ac_tmp - i;
    }
 dam2 = dam;
/***********************************/
/* START TEMPLAR ADD              */
/**********************************/
  if(this_player())
  if(!is_npc && this_player()->query_guild_name()=="Knights Templar") {
    templar_ob = present("KnightTemplar", this_object());
    if(templar_ob)
      ac_tmp += templar_ob->skill_check_def();
     }
/***********************************/
/*  END TEMPLAR ADD                */
/***********************************/
  dam -= random(ac_tmp + 1);
  lucky = random(500);
  if(is_npc) luck = 0;
  if (lucky < luck) {
    tell_object(this_object(), "Your luck comes through for you.\n");
    if (luck < 12)
       dam = dam/2;
    if (luck > 11 && luck <16)
       dam = dam/3;
    if (luck > 15)
       dam = dam/5;
  }
   if (lucky > 494)
    {
	 dam = dam2*5/3;
      tell_object(this_object(), attacker_ob->query_name() + " hits you with a crushing blow.\n");
      }
  if(hit_point<0 && dam <=0) dam = 1;
  if(hit_point<0) hit_point = 0;
  if (dam <= 0)
    return 0;
/* PUT a cap on damage a player can do in one hit. */
   if(!zap) zap = attacker_ob;
   if(attacker_ob && zap && zap->query_level() < EXPLORE){
   if (is_npc && dam > 50 && attacker_ob->query_level() < EXPLORE){
   if (attacker_ob->is_player()){
   if(dam < 56) dam=50;
   if(dam > 55) dam=random(30);
   }}}
/* penalize multiple calls to hit_player() by the same player in one hb */
  if(this_player() && is_npc) { 
        if(this_player()->query_level() > 99) write("DAMAGE = "+dam+" \n");
     if(h_check==this_player()) { hcnum += 1; 
        if(hcnum > 2) dam = dam/(hcnum+2);
        if(this_player()->query_level() > 99) write("DAMAGE REDUCED to "+dam+" hcnum="+hcnum+"\n");
     }}
  if (dam > hit_point+1)
    dam = hit_point+1;
  hit_point = hit_point - dam;
  if (hit_point<0) {
    object corpse;
    /* We died ! */
    dieing = 1;
    if (hunter)
      call_other(hunter, "stop_hunter");
    hunter = 0;
    hunted = 0;
    say(cap_name + " died.\n");
    /* If this is a player, log the death for future reference */
    if (!is_npc)
      if (attacker_ob)
    log_file("DEATHS", ctime(time()) + " " + name + " " + experience + " exp " + money + " gold killed by " +
		 call_other(attacker_ob, "query_real_name", 0) + ".\n");
      else
           {
	log_file("DEATHS", ctime(time()) + "  " + name + " " + experience + " exp "+money + " gold - killer unknown.\n");
        if(this_player()) log_file("DEATHS","this_player is "+this_player()->query_real_name() +"   "+this_player()->query_name()+"\n");
           }
   if (!is_npc)
   {
tell_object(this_object(), "\n\nYou feel very weak as your badly damaged body falls to the ground to die.\n");
    if(!environment(this_player())->query_spar_area()) {
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
    if(!is_npc) { set_ghost(1);
    move_object(corpse, environment(this_object())); }
    transfer_all_to(corpse);
    if(!is_npc) set_ghost(0);
    if (!attacker_ob)
      attacker_ob = alt_attacker_ob;
    if (!is_npc) {
    see_if_other(3); /* prevent cheating */
      this_object()->save_me();
/*
      attacker_ob = 0;
      alt_attacker_ob = 0;
 zero out attackers, hopefully will cure death bug.*/
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
       
       /* bonus for mythos's additions such as multiple attacks etc */ 
       /* note there is a reduction if healing etc is jacked with */
       
       if(haunt_set) exp_bonus += 250;
       if(pet_command) exp_bonus += (500 + random(500));
       exp_bonus += (heal_rate * 500)/heal_intv;
       if(spell_chance > 0) exp_bonus += (spell_chance * spell_dam)/100;
       if(mass_chance > 0) exp_bonus += mass_chance/10 * mass_dam;
       if(mult_set) exp_bonus += mult_at * (mult_chance/10 * (2* mult_dam1 + mult_dam2));
       if(heal_rate < 1 || heal_intv > 700) exp_bonus /= 2;
       if(armor_class < 1 || weapon_class < 4) exp_bonus /= 2;
       
       /* end mythos's bonuses */
       
       party=present("party object", attacker_ob);
       if(party) exp_bonus = 24*exp_bonus/30;
       if (party) party->share_exp(exp_bonus);
       if(!party)
      call_other(attacker_ob, "add_exp", exp_bonus);
    }
    move_object(corpse, environment(this_object()));
    dieing = 0;
    if (!call_other(this_object(), "second_life", 0))
      destruct(this_object());
  }
   if(this_player()&& is_npc)h_check=this_player();
  return dam;
}
