init(){
	if(!USER) return;
   if(USER != this_player()) return;
	gtype = "warrior";
	glvl = 1;
	skill_pts = 1;
	gxp = 0;
	restore_object(SAVE_PATH+USERRN);
	
	
	if(USER->query_level() < 20){
		USER->set_guild_name(gtype);
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
	
tell_object(USER, HIM+"\n\nIF YOU ABUSE TITLES, YOU WILL BE PUNISHED."+NORM+"\n\n\n");
tell_object(USER, 
HIY+"\n\n\n\n\n  Okay, I need to ask that people restrict your guild titles\n"+
    "  to something that makes sense.  Reread 'warrior title' please.\n\n\n"+NORM+""+
    HIB+" ALSO:  I keep hearing a request for a guild channel.  This is NOT a\n"+
        "        guild. This is just a job.  All of you have no ties to the other\n"+
        "        Warriors unless you WANT a tie.  If you do, then make a chatline.\n"+
        "        This guild will never have a chat line.\n\n\n"+NORM);

	call_other(USER, "wear", this_object(), 1, "mine", ({"physical",0,0,"shield_bonus"}));
}
