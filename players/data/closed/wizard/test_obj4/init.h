nic", 2);
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
	add_action("set_up", "ububu");
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

   add_action("gauge_cmd", "gauge");

	add_action("catch_all");  add_xverb("");


tell_object(USER, 
HIY+"\n\n\n\n\n  Okay, I need to ask that people restrict your guild titles\n"+
    "  to something that makes sense.  Reread 'warrior title' please.\n\n\n"+NORM+""+
    HIR+"  PEOPLE WHO ABUSE THE TITLES IN ANY WAY WILL BE PUNISHED SEVERELY.\n"+
    "  COLOR TITLES ARE A PRIVILEGE!"+NORM+"\n\n\n"+
    HIM+"  NEW SKILL(FREE):  You can now 'gauge' an item for how nice it is.\n"+
    "                    just 'gauge <item>' or 'gauge <item> on <who>'\n\n\n"+NORM);
tell_object(USER,
    HIY+"\n\n\n  Berserkers are now OPEN."+NORM+"  The book is somewhere in my area.  Good luck.\n\n\n");
	call_other(USER, "wear", this_object(), 1, "mine", ({"physical",0,0,"shield_bonus"}));
}


gauge_cmd(str){   
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	"/players/maledicta/closed/w/power/gauge.c"->main(str, TO, USER);
	return 1;
	}
nic", 2);
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
    add_action("guild_tell_history", "stone history");
	add_action("guild_tell", "stone");

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
	add_action("set_up", "ububu");
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

   add_action("gauge_cmd", "gauge");

	add_action("catch_all");  add_xverb("");


tell_object(USER, 
HIY+"\n\n\n\n\n  Okay, I need to ask that people restrict your guild titles\n"+
    "  to something that makes sense.  Reread 'warrior title' please.\n\n\n"+NORM+""+
    HIR+"  PEOPLE WHO ABUSE THE TITLES IN ANY WAY WILL BE PUNISHED SEVERELY.\n"+
    "  COLOR TITLES ARE A PRIVILEGE!"+NORM+"\n\n\n"+
    HIM+"  NEW SKILL(FREE):  You can now 'gauge' an item for how nice it is.\n"+
    "                    just 'gauge <item>' or 'gauge <item> on <who>'\n\n\n"+NORM);
tell_object(USER,
    HIY+"\n\n\n  Berserkers are now OPEN."+NORM+"  The book is somewhere in my area.  Good luck.\n\n\n");
	call_other(USER, "wear", this_object(), 1, "mine", ({"physical",0,0,"shield_bonus"}));
}


gauge_cmd(str){   
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	"/players/maledicta/closed/w/power/gauge.c"->main(str, TO, USER);
	return 1;
	}
