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
       USER->set_guild_file("/players/guilds/warriors/gobj");
		add_action("no_spell", "sonic", 2);
		add_action("no_spell", "fireball", 2);
		add_action("no_spell", "shock", 2);
		add_action("no_spell", "missile", 2);
		add_action("no_spell", "pose");
		add_action("wimpy_check", "wimpy");
	}
	add_action("create_title", "title");
        add_action("cmd_update", "gupdate");
	add_action("save_prof", "psave");
	add_action("new_score", "score", 2);
	add_action("doc_help", "warrior");
	add_action("new_quit", "quit");
	add_action("convert_xp", "convert");
	add_action("raise_skill", "raise_skill");
	add_action("new_inventory", "inventory");
        add_action("new_inventory", "i");
        add_action("inv_cmd","inv");
	
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
        add_action("firstaid_cmd", "first");   /* Rumplemintz - Dec-01-2009 */
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
        add_action("bcommand_cmd","bcommand", 2);
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
#ifndef __LDMUD__
	add_action("catch_all");  add_xverb("");
#else
	add_action("catch_all", "", 3);
#endif


tell_object(USER, 
HIY+"\n\n\n\n\n  Okay, I need to ask that people restrict your guild titles\n"+
    "  to something that makes sense.  Reread 'warrior title' please.\n\n\n"+NORM+""+
    HIR+"  PEOPLE WHO ABUSE THE TITLES IN ANY WAY WILL BE PUNISHED SEVERELY.\n"+
    "  COLOR TITLES ARE A PRIVILEGE!"+NORM+"\n\n\n"+
    HIM+"  NEW SKILL(FREE):  You can now 'gauge' an item for how nice it is.\n"+
    "                    just 'gauge <item>' or 'gauge <item> on <who>'\n\n"+NORM);

	call_other(USER, "wear", this_object(), 1, "mine", ({"physical",0,0,"shield_bonus"}));
}


gauge_cmd(str){   
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	"/players/guilds/warriors/power/gauge.c"->main(str, TO, USER);
	return 1;
	}

inv_cmd(str)
{
  object *inv;
  int y;

  if(!(y = sizeof(inv = all_inventory(this_player()))) || (y==1 && present("soul", this_player())))
    {
      write("You are not carrying anything.\n");
    }
    
    else 
    {
      object *armors, *heals, *containers, *special, wep, o_wep;
      int  *p, s, mf; string sh, *sws;
      int x;
      string el; object fg, ff;
      mixed *pl;
      
      
      armors = heals = containers = special = p = ({ });
      
      ff = first_inventory(this_player());
      while(ff) {
        fg = next_inventory(ff);
        if(el=(string)ff->extra_look()) write(el+".\n");
        ff = fg;
      }
      for(x = 0; x < y; x ++)
      {
        mf = 0;
        if((pl = process_list(armors,inv[x],"query_worn"))[1])
        {
          armors = pl[0]; mf = 1;
        }
        if((pl = process_list(heals,inv[x],"is_heal"))[1])
        {
          heals = pl[0]; mf = 1;
        }
        if(!inv[x]->id("mask_autoload"))
          if((pl = process_list(special,inv[x],"drop",1))[1])
          {
            special = pl[0]; mf = 1;
          }
        if(mf) p += ({ x });
      }
      
      s = sizeof(p);
      while(s --) {
        inv -= ({ inv[p[s]] });
      }
      
      sws = get_switches(str);
      
      if(!sws || member_array("autoloads", sws) == -1) {
        print_con("Autoloads:\n", special);
      }

      wep = (object)this_player()->query_weapon();
      o_wep = (object)this_player()->query_second_weapon();
      
      if(!sws || member_array("weapons", sws) == -1) 
      {
          if(wep && wep->short() && !wep->id("mask_weapon"))
          {
            write("\nWielded: \n     ");
            write((string)wep->short()+".\n");
            inv -= ({ wep });
          }
          if(o_wep && o_wep->short() && !o_wep->id("mask_weapon"))
          {
            write("     "+(string)o_wep->short()+".\n");
            inv -= ({ o_wep });
          }
      }
      
      if(!sws || member_array("armors", sws) == -1) {
        print_con("You are wearing:\n", armors);
      }
      if(!sws || member_array("heals", sws) == -1) {
        print_con("Heals:\n", heals);
      }
      if(!sws || member_array("other", sws) == -1) {
        print_con("Other:\n", inv);
      }
      write("\n");
      write("You are carrying "+
        (int)this_player()->query_pct_weight()+"% of maximum capacity.\n");
    }
  return 1;
}

void print_con(string msg, object *arr)
{
  int s, x, i;
  string sh;
  string stuff;
  string *m; int *a;
  m = ({ }); a = ({ });
  stuff = "";
  s = sizeof(arr);
  for(x = 0; x < s; x ++) {
    if(sh = (string)arr[x]->short()) {
      sh = implode(explode(sh, "\n"), ".\n    ");
      if((i = member_array(sh, m)) == -1) {
        m += ({ sh });
        a += ({ 1 });
      }
      else {
        a[i] ++;
      }
    }
  }
  s = sizeof(m);
  for(x = 0; x < s; x ++) {
    if(a[x] != 1) {
      stuff += "["+a[x]+"x] ";
    }
    else {
      stuff += "     ";
    }
    stuff += m[x]+".\n";
  }
    
  if(strlen(stuff)) {
      write("\n"+msg);
      write(stuff);
  }
}

varargs
mixed * process_list(object *arr, object ob, string fun, int a) {
  if((!a && call_other(ob, fun)) || 
     (a && (ob->query_auto_load() || ob->id("GI")))){
    return ({ arr + ({ ob }), 1 });
  }
  return ({ arr, 0 });
}

string * get_switches(string str) {
  if(str) {
    if(text_contains(str, "-")) {
      string *sws, *tws;
      int s;
      tws = ({ });
      sws = explode(str, "-"),
      s = sizeof(sws);
      while(s--) {
        if(stringp(sws[s])) {
          tws += ({ delete_spaces(sws[s]) });
        }
      }
      if(sizeof(tws)) return tws;
    }
  }
}

cmd_update()
{
  object ob;
  ob = clone_object("/players/guilds/warriors/gobj.c");
  destruct(this_object());
  move_object(ob, this_player());
  write(HIC+"\n  Warriors status updated.\n\n"+NORM);
  return 1;
}
   
