attack()
{
   int tmp;
   string mfight,thingone,thingtwo;
   int tmpk,pal_tmp,whit,weap_tmp;
   int knt_tmp,knt_tmp2;
   int intox_no;

   string style;

   string name_alt_at;
   string name_of_attacker;
   object pro_object;     /* paladin object */
   object templar_ob;    /* templar object */
   pal_tmp = 0;
   knt_tmp = 0;
   knt_tmp2 = 0;
   if(is_npc) h_check = 0;
   hcnum = 1;
   if (!is_npc) {
      intox_no = call_other(this_object(), "query_intoxination", 0);
      if(intox_no > 0) {
         intox_no = 5 - ( (level + 4) / intox_no );
         if(intox_no < 0) intox_no = 0;
      }
   }
   else
      intox_no = 0;
  
   if(alt_attacker_ob) {
      if(alt_attacker_ob->query_ghost())
         alt_attacker_ob = attacker_ob;
   }
   if (already_fight){
      return 0;
   }
   if (!attacker_ob) {
      spell_cost = 0;
      return 0;
   }
/* fight_are pk check */
   if(!is_npc && attacker_ob->is_player())
      if(!this_object()->query_pl_k() || !attacker_ob->query_pl_k())
         if(!this_object()->check_fight_area()){
            if(!attacker_ob->check_fight_area()) attacker_ob->clear_fight_area();
            attacker_ob =0;
            alt_attacker_ob=0;
            return 0;
         }
 /* Stop fighting if one party is disconnected */
  /* Stop player disconnected player from fighting */
   if (!is_npc && !call_other(this_object(), "query_interactive",0)){
      attacker_ob =0;
      return 0;
   }
  /* stop monster from fighting disconnected player */
   if (is_npc && !call_other(attacker_ob, "query_interactive",0) && !call_other(attacker_ob, "query_npc", 0))
      stop_fight();
  /* stop player from fighting disconnected player */
   if(!is_npc && !call_other(attacker_ob, "query_interactive",0) && !call_other(attacker_ob, "query_npc", 0))
      stop_fight();
   if (attacker_ob)
      name_of_attacker = call_other(attacker_ob, "query_name", 0);
   if ((!name_of_attacker) || 
      (name_of_attacker == NAME_OF_GHOST) ||
      (environment(attacker_ob) != environment(this_object()))) {
      if (!hunter && name_of_attacker &&
         !call_other(attacker_ob, "query_ghost", 0)) {
	 tell_object(this_object(), "You are now hunting " +
	    call_other(attacker_ob, "query_name", 0) + ".\n");
	 hunted = attacker_ob;
	 hunting_time = 10;
      }
      attacker_ob = 0;
      if (!alt_attacker_ob)
         return 0;
      attacker_ob = alt_attacker_ob;
      alt_attacker_ob = 0;
      if (attack()) {
         tell_object(this_object(), "You turn to attack " +
	    call_other(attacker_ob, "query_name", 0) + ".\n");
         already_fight=1;
         return 1;
      }
      return 0;
   }
   call_other(attacker_ob, "attacked_by", this_object());
   if (spell_cost) {
      if (level < 20) spell_points -= spell_cost;
      if(!asf && !vsf && !rsf) {
         tell_object(attacker_ob, "You are hit by a " + spell_name + ".\n");
         write("You cast a " + spell_name + ".\n");
      }
      asf = 0; vsf = 0; rsf = 0;
   }
   if(name_of_weapon)
      whit = call_other(name_of_weapon,"hit",attacker_ob);
/* use weap_tmp as a weapon class limit as wizards dont listen.*/
   weap_tmp = weapon_class;
   if (!is_npc && this_object()->query_level() < 20 && weapon_class > 20) {
      weap_tmp = 20;
   }
   if(whit) {
      weap_tmp = weap_tmp + whit;
      if(!is_npc && this_object()->query_level()<20 && 1*weap_tmp > 30)
         weap_tmp = 10 + random(12);
      if(!is_npc && this_object()->query_level() <20 && weap_tmp > 24){
	 weap_tmp = 24;
      }
      if(this_object()->is_kid() && weap_tmp > 15) weap_tmp = 15;
   }
   pal_tmp=weap_tmp;
/******************************/
/*  BEGIN PALADIN ADDITIONS   */
/******************************/
/*
     if(!is_npc && this_player()->query_guild_name()=="paladin") {
*/
   if(this_player())
      pro_object = present("pro_object", this_player());
   if(name_of_weapon) if(pro_object) if(name_of_weapon->query_pro_weapon()) {
      weap_tmp += call_other(name_of_weapon, "proficiency_hit", pro_object);
   }
   if(second_weapon && pro_object && pro_object->query_combat_method() == 3) {
      weap_tmp += call_other(second_weapon, "dual_hit", pro_object);
   }
/******************************/
/*   END PALADIN ADDITIONS    */
/******************************/
/******************************/
/*   TEMPLAR ADDITIONS        */
/******************************/
   if(this_player())
      if(!is_npc && this_player()->query_guild_name()=="Knights Templar") {
         templar_ob=present("KnightTemplar", this_player());
         if(name_of_weapon && templar_ob) {
            knt_tmp = templar_ob->skill_check(name_of_weapon);
            knt_tmp2 = 2*knt_tmp/3;
            knt_tmp = random(knt_tmp - knt_tmp2);
            weap_tmp += knt_tmp2;
         }
         if(mounted) {
            int mnt,mnt2;
            mnt = templar_ob->query_skill("horse");
            mnt2=random(mnt/2);
/*
       weap_tmp += random(mnt/2);
*/
            weap_tmp += mnt2;
            if(name=="numberthree") write("mounted bonus ="+mnt2+">>>"+mnt+"\n");
         }
      }
/******************************/
/*   END TEMPLAR SECTION      */
/******************************/
   if(alt_attacker_ob)
      if(!alt_attacker_ob->query_name()) alt_attacker_ob = attacker_ob;
   if(alt_attacker_ob && alt_attacker_ob != attacker_ob){
      if(whit != "miss")
         if(present(alt_attacker_ob))
            hit_pet(weap_tmp,spell_dam);
   }
   
   if(name_of_weapon)
      style = name_of_weapon->query_style();
   else style = "physical";

   if(whit != "miss" && attacker_ob)
      tmp = call_other(attacker_ob, "hit_player", 
         knt_tmp+random(weap_tmp - intox_no), style,
         spell_dam, "magical");
   else
      tmp = 0;
   if (tmp == 0) {
      tell_object(this_object(), "You missed.\n");
      checked_say(cap_name + " missed " + name_of_attacker + ".\n");
      spell_cost = 0;
      spell_dam = 0;
      already_fight = 1;
      if(!is_npc && second_weapon && pro_object &&
         pro_object->query_combat_method() == 3)
         second_weapon->count_misses();
      if(!is_npc && name_of_weapon) {
         name_of_weapon->count_misses();
         if(name_of_weapon->query_wear() > 60){
            if(!is_npc && random(4450000/name_of_weapon->query_wear()) < 10)
               name_of_weapon->weapon_breaks();
         }
      }
      return 1;
   }
   if(!is_npc && attacker_ob && !attacker_ob->query_no_exp_value())
      this_object()->add_exp(tmp);
   tmp -= spell_dam;
   spell_cost = 0;
   spell_dam = 0;
  /* Does the enemy still live ? */
   if (attacker_ob &&
      call_other(attacker_ob, "query_name", 0) != NAME_OF_GHOST) {
/*
    string how, what;
    how = " to small fragments";
    what = "massacre";
    if (tmp < 30) {
      how = " with a bone crushing sound";
      what = "smashed";
    }
    if (tmp < 20) {
      how = " very hard";
      what = "hit";
    }
    if (tmp < 10) {
      how = " hard";
      what = "hit";
    }
    if (tmp < 5) {
      how = "";
      what = "hit";
    }
    if (tmp < 3) {
      how = "";
      what = "grazed";
    }
    if (tmp == 1) {
      how = " in the stomach";
      what = "tickled";
    }
    tell_object(this_object(), "You " + what + " " + name_of_attacker +
		how + ".\n");
    if (query_invis() >= INVIS_ACTION)
      tell_object(attacker_ob, cap_name + " " + what + " you" + how +
		  ".\n");
    checked_say(cap_name + " " + what + " " + name_of_attacker + how +
		".\n");
*/
      string *mess;
      if(name_of_weapon) mess = name_of_weapon->query_message_hit(tmp); 
      else mess = query_message_hit(tmp);
      if(!mess) mess = query_message_hit(tmp);
      tell_object(this_object(), "You " + mess[1] + " " + name_of_attacker +
                mess[0] + ".\n");
      if (query_invis() >= INVIS_ACTION)
         tell_object(attacker_ob, cap_name + " " + mess[1] + " you" + mess[0] +
            ".\n");
      checked_say(cap_name + " " + mess[1] + " " + name_of_attacker + mess[0] +
            ".\n");
      already_fight = 1;
      if(!is_npc && second_weapon && pro_object &&
         pro_object->query_combat_method() == 3)
         second_weapon->count_hit_made(pal_tmp);
      if(name_of_weapon && !is_npc) {
         name_of_weapon->count_hit_made(pal_tmp);
         if(!is_npc && name_of_weapon->query_wear() > 1){
            if(!is_npc && random(4500000/name_of_weapon->query_wear()) < 10)
               name_of_weapon->weapon_breaks();
         }
      }
      return 1;
   }
   tell_object(this_object(), "You killed " + name_of_attacker + ".\n");
   attacker_ob = alt_attacker_ob;
   alt_attacker_ob = 0;
   already_fight = 1;
   if (attacker_ob)
      return 1;
}
