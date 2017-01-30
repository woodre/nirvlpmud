init(){
	if(!USER) return;
   if(USER != this_player()) return;
	gtype = "warrior";
	glvl = 1;
	skill_pts = 1;
	gxp = 0;
	restore_object(SAVE_PATH+USERRN);
	
	
	if(USER->query_level() < 20){
          if(!USER->query_guild_name()){
		USER->set_guild_name(gtype);
               }
	add_action("catch_all");  add_xverb("");
		add_action("no_spell", "sonic", 2);
		add_action("no_spell", "fireball", 2);
		add_action("no_spell", "shock", 2);
		add_action("no_spell", "missile", 2);
		add_action("no_spell", "pose");
		add_action("wimpy_check", "wimpy");
	}
	add_action("create_title", "title");
	add_action("save_prof", "psave");
	add_action("new_score", "score", 2);
	add_action("doc_help", "warrior");
	add_action("new_quit", "quit");
	add_action("convert_xp", "convert");
	add_action("raise_skill", "raise_skill");
	add_action("new_inventory", "inventory", 1);
    add_action("guild_tell", "stone");
    add_action("guild_tell_history", "stoneh");
	
	add_action("throw_cmd", "throw");
	add_action("strike_cmd", "strike");
	add_action("punch_cmd", "punch");
	add_action("kick_cmd", "kick");
	add_action("charge_cmd", "charge");
	add_action("bash_cmd", "bash");
	add_action("offhand_cmd", "offhand");
	
	add_action("pummel_cmd", "pummel");
	add_action("finish_cmd", "finish");
	add_action("firstaid_cmd", "firstaid");
	add_action("run_cmd", "run");
	
	add_action("save_prof", "psave");
	
	add_action("skill_listing", "skills");
	add_action("check_weapon", "check");
	add_action("set_up", "nanana");
	add_action("sense", "sense");
   add_action("leave_it", "leave_profession");
	/* MONK STUFF */
	add_action("xpunch_cmd", "xpunch", 2);
	add_action("xkick_cmd", "xkick", 2);
	add_action("meditate_cmd", "meditate");
	add_action("touch", "touch");
        add_action("touch", "mtouch");
   add_action("skill_list2", "skills2");
   add_action("monk_info", "monk");

	/* PALADIN STUFF */
   add_action("paladin_info", "paladin");
   add_action("corrupt_cmd", "corrupt");
	add_action("regen_aura_cmd", "regen");
	add_action("prot_good_cmd", "good");
	add_action("prot_evil_cmd", "evil");
	add_action("release_cmd", "release", 2);
	add_action("redeem_cmd", "redeem");
	add_action("holy_bolt_cmd", "hb");
	add_action("sacrifice_cmd", "sacrifice", 3);
	add_action("holy_bolt_cmd", "holybolt", 2);
   add_action("plague_cmd", "plague");
   add_action("cleanse_cmd", "cleanse");
   add_action("detect_cmd", "detect");

   /* Knight Stuff */
   add_action("knight_info", "knight");
   add_action("xstrike_cmd", "xstrike", 2);
   add_action("xbash_cmd",   "xbash", 2);
   add_action("bcommand_cmd","bcommand", 5);
   add_action("defend_cmd", "defend");
   add_action("study_cmd", "study");
 
  /* Berserker Stuff */
   add_action("rage_cmd", "rage");
   add_action("xcharge_cmd", "xcharge");
   add_action("berserker_info", "berserker");

  /* Assassin Stuff */
   add_action("riposte_cmd", "riposte");
   add_action("hide_cmd", "hide");
   add_action("backstab_cmd", "backstab");
   add_action("backstab_cmd", "bs");
   add_action("xthrow_cmd", "xthrow", 2);
   add_action("assassin_info", "assassin");


   add_action("gauge_cmd", "gauge");



tell_object(USER, 
HIY+"\n\n\n\n\n NEWS:\n"+
  "This guild has been restored in accordance with Nirvana's code policy.\n"+
  "Maledicta had closed this guild when he left, however over two months ago\n"+
  "he became a founding member of a new mud using a great deal of Nirvana's\n"+
  "code. Under the code policy this allowed restoration of the guild.\n");
  call_other(USER, "wear", this_object(), 1, "mine",({"physical",0,0,"shield_bonus"}));
}


gauge_cmd(str){   
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	"/players/data/closed/wizard/power/gauge.c"->main(str, TO, USER);
	return 1;
	}