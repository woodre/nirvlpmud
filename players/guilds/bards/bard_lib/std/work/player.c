#define INTERVAL_BETWEEN_HEALING	9

static object paladin_shield; 
static object second_weapon;
static int second_wc;
string autoload;
int brief;

zap_object(ob)
{
    call_other(ob, "attacked_by", this_object());
    checked_say(cap_name + " summons a flash from the sky.\n");
    write("You summon a flash from the sky.\n");
    if (!call_other(ob, "query_npc", 0))
	shout("There is a big clap of thunder.\n\n");
    ob->hit_player(100000,this_object());
}

missile_object(ob)
{
    /* If this is a player, make sure they are entitled to attack this person */
    if (!valid_attack(ob)) {
	write("You can't attack " + call_other(ob, "query_name", 0) + "!\n");
	return 0;
    }
    if (spell_points < 10) {
	write("Too low on power.\n");
	return;
    }
    spell_name = "magic missile";
    spell_dam = random(20);
    spell_cost = 10;
    attacker_ob = ob;
}

shock_object(ob)
{
    /* If this is a player, make sure they are entitled to attack this person */
    if (!valid_attack(ob)) {
	write("You can't attack " + call_other(ob, "query_name", 0) + "!\n");
	return 0;
    }
    if (spell_points < 15) {
	write("Too low on power.\n");
	return;
    }
    spell_name = "shock";
    spell_dam = random(30);
    spell_cost = 15;
    attacker_ob = ob;
}

fire_ball_object(ob)
{
    /* If this is a player, make sure they are entitled to attack this person */
    if (!valid_attack(ob)) {
	write("You can't attack " + call_other(ob, "query_name", 0) + "!\n");
	return 0;
    }
    if (spell_points < 20) {
	write("Too low on power.\n");
	return;
    }
    spell_name = "fire ball";
    spell_dam = random(40);
    spell_cost = 20;
    attacker_ob = ob;
}

lower_attrib() {
    int la,ok,i;
    string las;
    ok = 0;
    i=0;
    while (ok < 1) {
	la = random(8);
	i=i+1;
	if(i>70) return 1;
	if (la == 8) return 1;
	if (la == 7) las = "strength";
	if (la == 6) las = "will_power";
	if (la == 5) las = "magic_aptitude";
	if (la == 4) las = "piety";
	if (la == 3) las = "stamina";
	if (la == 2) las = "stealth";
	if (la == 1) las = "luck";
	if (la == 0) las = "intelligence";
	if (call_other(this_object(), "query_attrib", extract(las,0,2)) > 1)
	    ok = 1;
    }
    call_other(this_object(), "raise_" + las, -1);
    return 1;
}

/* This is used by the shop etc. */
add_money(m) {
    if (this_player() && this_player() != this_object() &&
      query_ip_number(this_player()) && query_ip_number(this_object()) &&
      call_other(this_player(), "query_level",0) > 20 &&
      level < 20)
    {
	log_file("ADD_MONEY", file_name(environment(this_object())));
	log_file("ADD_MONEY", ctime(time()) + " " +name + "(" + level + 
	  ") " + m + " money by " + this_player()->query_real_name() +
	  "(" + this_player()->query_level() + ")\n");
    }
    money = money + m;
    if (money > 80000) 
	money = 80000;
    if (!query_npc() && level <= 19)
	add_worth(m);
}
force_us(cmd) {
    if(this_player() != this_object())
	if (level >= call_other(this_player(), "query_level")) {
	    tell_object(this_object(), call_other(this_player(), "query_name") +
	      " tried to force you to " + cmd + ".\n");
	    return;
	}
    tell_object(this_object(), call_other(this_player(), "query_name") +
      " forced you to '" + cmd + "'.\n");
    command(cmd);
}

heal_self(h) {
    object thypl;
    int liv_infuse,LIV_INFUSE_LIMIT;
    if (!h)
	return;
    thypl = this_player();
    if(thypl)
	if(this_object()->query_interactive())
	    if (level < EXPLORE && thypl->query_interactive() && thypl != this_object()){
		if(thypl->query_level() > EXPLORE)
		    log_file("POINTS", name + " heal_self "+ h + call_other(thypl, "query_real_name", 0) + " " + ctime(time()) + "\n");
		else {
		    if(environment(thypl) != environment(this_object())) {
			h = 0;
			tell_object(thypl,cap_name+" is not here.\n");
			/*
			tell_object(thypl,"Player to Player Healing transfers are not allowed.\n");
			*/
			tell_object(this_object(),"Attempted Healing transfer Aborted.\n");
			return 1;
		    }
		    liv_infuse = this_object()->query_infuse();
		    LIV_INFUSE_LIMIT = this_object()->query_infuse_limit();
		    if(LIV_INFUSE_LIMIT < liv_infuse+6*h/2 || liv_infuse > LIV_INFUSE_LIMIT/2) {
			int blah;
			blah = (LIV_INFUSE_LIMIT - liv_infuse)/3;
			tell_object(thypl,cap_name+" must wait before absorbing "+h+" healing.\n");
			if(liv_infuse < LIV_INFUSE_LIMIT/2 && blah > 0 )
			    tell_object(thypl,cap_name+" may absorb up to "+blah+" healing.\n");
			tell_object(this_object(),"You must wait before absorbing more healing.\n");
			h = 0;
			return 1;
		    }
		    if(h > 0)
			this_object()->add_infuse(6*h/2);
		}
	    }
    if(!is_npc)
	if(!this_object()->query_interactive()) {
	    say(cap_name+" is disconnected.\n");
	    stop_fight(); this_player()->stop_fight();
	    return 0;
	}
	/*
	  if(h < -30) { 
	    if(previous_object() && previous_object() != this_object())
	    log_file("BIGDMG",h+" "+file_name(previous_object())+" "+creator(previous_object())+" "+query_verb()+"\n");
	   }
	*/
    hit_point += h;
    if (hit_point > max_hp)
	hit_point = max_hp;
    spell_points += h;
    if (spell_points > max_spell)
	spell_points = max_spell;
    if(h < 0) hit_player(1);
}

/*
 * Return true if there still is a fight.
 */
attack()
{
    int tmp;
    string mfight,thingone,thingtwo;
    int tmpk,pal_tmp,whit,weap_tmp;
    int knt_tmp,knt_tmp2;
    int intox_no;
    string name_alt_at;
    string name_of_attacker;
    object pro_object;     /* paladin object */
    object templar_ob;    /* templar object */
    pal_tmp = 0;
    knt_tmp = 0;
    knt_tmp2 = 0;
    if(is_npc) h_check = 0;
    hcnum = 1;
    if (!is_npc)
	intox_no = call_other(this_object(), "query_intoxination", 0)/5;
    else
	intox_no = 0;

    if(alt_attacker_ob) {
	if(alt_attacker_ob->query_ghost())
	    alt_attacker_ob = attacker_ob;
    }
    if (already_fight) 
    {
	return 0;
    }
    if (!attacker_ob) {
	spell_cost = 0;
	return 0;
    }
    /* Stop fighting if one party is disconnected */
    /* Stop player disconnected player from fighting */
    if (!is_npc && !call_other(this_object(), "query_interactive",0))
    {
	alt_attacker_ob=0;
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
    if (objectp(spell_dam)) {
	spell_dam = (int) call_other(spell_dam, spell_name, attacker_ob);
    }
    if (spell_cost) {
	if (level < 20) spell_points -= spell_cost;
	tell_object(attacker_ob, "You are hit by a " + spell_name + ".\n");
	write("You cast a " + spell_name + ".\n");
    }
    if(Weapon)
	whit = call_other(Weapon,"hit",attacker_ob);
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
    pro_object = present("pro_object", this_player());
    if(Weapon && pro_object && Weapon->query_pro_weapon()) {
	weap_tmp += call_other(Weapon, "proficiency_hit", pro_object);
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
    if(!is_npc && this_player()->query_guild_name()=="Knights Templar") {
	templar_ob=present("KnightTemplar", this_player());
	if(Weapon && templar_ob) {
	    knt_tmp = templar_ob->skill_check(Weapon);
	    knt_tmp2 = 2*knt_tmp/3;
	    knt_tmp = knt_tmp - knt_tmp2;
	    weap_tmp += knt_tmp2;
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
    if(whit != "miss" && attacker_ob)
	tmp = call_other(attacker_ob, "hit_player", 
	  knt_tmp+random(weap_tmp - intox_no) + spell_dam);
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
	if(!is_npc && Weapon) {
	    Weapon->count_misses();
	    if(Weapon->query_wear() > 60)
	    {
		if(!is_npc && random(4000000/Weapon->query_wear()) < 10)
		    Weapon->weapon_breaks();
	    }
	}
	return 1;
    }
    experience += tmp;
    tmp -= spell_dam;
    spell_cost = 0;
    spell_dam = 0;
    /* Does the enemy still live ? */
    if (attacker_ob &&
      call_other(attacker_ob, "query_name", 0) != NAME_OF_GHOST) {
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
	already_fight = 1;
	if(!is_npc && second_weapon && pro_object &&
	  pro_object->query_combat_method() == 3)
	    second_weapon->count_hit_made(pal_tmp);
	if(Weapon && !is_npc) {
	    Weapon->count_hit_made(pal_tmp);
	    if(!is_npc && Weapon->query_wear() > 1)
	    {
		if(!is_npc && random(4500000/Weapon->query_wear()) < 10)
		    Weapon->weapon_breaks();
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

/* 
 * Additions for Paladins
 * A couple off functions for handling offwielded weapons
 */

stop_offwielding() {
    if(!second_weapon) {
	log_file("offwield_bug", "Weapon not offwielded!\n");
	write("Bug! The weapon was marked as offwielded! (fixed)\n");
	return;
    }
    call_other(second_weapon, "un_wield", dead);
    second_weapon = 0;
    second_wc = 0;
}

offwield(w) {
    if(second_weapon)
	stop_offwielding();
    second_weapon = w;
    second_wc = call_other(w, "weapon_class", 0);
    say(cap_name + " offwields " + call_other(w,"query_name",0)+".\n");
    write("Ok.\n");
}

/* END PALADIN ADDITIONS */

/*
 * This function is called from other players when they want to make
 * damage to us. We return how much damage we received, which will
 * change the attackers score. This routine is probably called from
 * heart_beat() from another player.
 */
hit_player(dam,zap) {
    int i,dam2,ac_tmp;
    object pro_object;   /* paladin weapon pro & combat method object */
    object templar_ob; /*templar object*/

    /*
	if(dam > 45 && !zap && previous_object()) {
	if(this_player()->query_interactive() && this_player() != this_object())
	 log_file("BIGDMG",dam+" "+file_name(previous_object())+" "+creator(previous_object())+" "+query_verb()+"\n");
	}
    */
    if(!is_npc)
	if(!this_object()->query_interactive()) {
	    say(cap_name+" is disconnected.\n");
	    stop_fight(); this_player()->stop_fight();
	    return 0;
	}
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
    if (!is_npc && ArmourClass > 9) {
	ac_tmp = 9;
    } else {
	ac_tmp = ArmourClass;
    }
    if(!is_npc && this_object()->query_pregnancy()){
	i = age - this_object()->query_pregnancy();
	i = i/5000;
	ac_tmp = ac_tmp - i;
    }
    dam2 = dam;
    /************************************/
    /*    BEGIN PALADIN ADDITIONS       */
    /************************************/
    /*
	 if(!is_npc && this_player()->query_guild_name()=="paladin") {
    */
    pro_object = present("pro_object", this_object());
    //tell_object(this_object(), "pro_object: " + to_string(pro_object) + ".\n");
    if(pro_object && paladin_shield && pro_object->query_combat_method() == 2) {
	ac_tmp += call_other(paladin_shield, "shield_bonus", pro_object);
	//tell_object(this_object(), "ac_tmp: " + ac_tmp + ".\n");
    }
    /************************************/
    /*     END PALADIN ADDITIONS        */
    /************************************/
    /***********************************/
    /* START TEMPLAR ADD              */
    /**********************************/
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
    if(attacker_ob && zap && zap->query_level() < EXPLORE)
    {
	if (is_npc && dam > 50 && attacker_ob->query_level() < EXPLORE)
	{
	    if(dam < 56) dam=50;
	    if(dam > 55) dam=random(30);
	}
    }
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
	    save_object("players/" + name);
	    attacker_ob = 0;
	    alt_attacker_ob = 0;
	    /* zero out attackers, hopefully will cure death bug.*/
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
	    wa_bonus = WeaponClass * ArmourClass * WA_FACTOR;
	    if (wa_bonus > base_bonus/3)
		wa_bonus = base_bonus/3;
	    exp_bonus += wa_bonus;
	    party=present("party object", attacker_ob);
	    if(party) exp_bonus = 24*exp_bonus/30;
	    if (party) party->share_exp(exp_bonus);
	    if(!party)
		call_other(attacker_ob, "add_exp", exp_bonus);
	}
	move_object(corpse, environment(this_object()));
	if (!call_other(this_object(), "second_life", 0))
	    destruct(this_object());
    }
    if(this_player()&& is_npc)h_check=this_player();
    return dam;
}

hit_player() {
	if (this_object()->is_player() && !interactive(this_object()))
	    return 0;
}

run_away() {
    if (!is_npc) clear_follow();
    if (!whimpy_dir || is_npc || whimpy_dir == "random") {
    }
    if(whimpy_dir && whimpy_dir != "random") {
	int hp_tmp,sp_tmp,sp_new,hp_new,hp_chg,sp_chg;
	hp_tmp=HitPoints;
	sp_tmp=SpellPoints;
	command(whimpy_dir);
	hp_new=HitPoints;
	sp_new=SpellPoints;
	sp_chg=sp_new - sp_tmp;
	hp_chg=hp_new - hp_tmp;
	if(hp_chg > 10) { 
	    HitPoints = HitPoints - hp_chg +5;
	    if(sp_chg > 0)
		SpellPoints = SpellPoints - sp_chg;
	    tell_object(this_object(), "You fumble your heal in your haste.\n");
	    whimpy_dir="random";
	    run_away();
	}
	tell_object(this_object(), "Your legs run away with you!\n");
    }
}

void
show_stats() {
    mixed tmp;
    ::show_stats();
    if (query_level() > 19) {
	write("earmuffs: " + (query_muffled() ? "on\n" : "off\n"));
    }
    if (tmp = query_pregnancy()) {
	write("pregnancy: " + (age - tmp) + " / 16200 \n");
    }
    if (tmp = query_quests()) {
	write("Quests: \t" + tmp + "\n");
	write("Quest Points: \t" + query_quest_point() +"\n");
    }
}

attack() {
    if (AlreadyFought) return 0;
    /* Stop disconnected player from fighting */
    if (!interactive(this_object())) {
	AltAttacker = 0;
	Attacker = 0;
	return 0;
    }
    ::attack();
}

long(str) {
    string sh, gender;
    if ((sh = short()) && (gender = query_gender_string()))
      write(sh + " (" + gender + ")\n");
}
