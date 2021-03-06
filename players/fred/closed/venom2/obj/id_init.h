
/****************************************************************
**  ID check and armor wearing(grafting)  ***********************
****************************************************************/
id(str){
if(previous_object())
if(previous_object()->is_armor() && check_armors(previous_object()->query_type())){
	return str == "new_venom_object" || str == "link" || str == "no_pet" ||
	str == "no_mini" || str == "no_spell" || str == "venom_object" || str == "pro_object" ||
	str == "venom_drag_object" || str == "guild_monitor" || str == "generic_wc_bonus" ||
   str == "link_comm" || str == "notarmor" || str == "kill_check_object";
}
else{
	return str == "new_venom_object" || str == "link" || str == "no_pet" ||
	str == "no_mini" || str == "no_spell" || str == "venom_object" || str == "pro_object" ||
	str == "venom_drag_object" || str == "guild_monitor" || str == "generic_wc_bonus" ||
   str == "link_comm" || str == "kill_check_object";
}
return str == "new_venom_object" || str == "link" || str == "no_pet" ||
	str == "no_mini" || str == "no_spell" || str == "venom_object" || str == "pro_object" ||
	str == "venom_drag_object" || str == "guild_monitor" || str == "generic_wc_bonus" ||
   str == "link_comm" || str == "kill_check_object";
}

string *pks;
int *pks_num;

kill_check(ob){
  if(query_ip_number(ob)){
   if(environment(USER)->query_spar_area() || environment(ob)->query_spar_area()) return;
     pks_add(ob->query_real_name());
     }
  }

pks_add(str){
int i;
int done;

for(i = 0; i < sizeof(pks); i ++){
  if(pks[i] == str){
     pks_num[i] += 1;
     return 1;
     }
  }

if(pks){
  pks += str;
  pks_num += ({ 1 });
  }
else{
  pks = ({ str });
  pks_num = ({ 1 });
  }
}      

list_pks(){
  int i;

  write(HIR+"PK LOG>>>>>>>\n"+HIB+"Name ["+NORM+BOLD+"Number of times"+NORM+HIB+"]"+NORM+"\n");
  
  for(i = 0; i < sizeof(pks); i++){
    write("("+(i + 1)+") "+pks[i]+" ["+pks_num[i]+"]\n");
    }
  write("\n\n");
  return 1;
  }  


  

/******************************************************************
**  Inititialization calls restore, sets guild name, and readies **
**  the player for armor specials.                               **
******************************************************************/
init(){
	if(done) return;
	if(!this_player()) return;
	if(!environment()) return;
	if(environment() != this_player()) return;
	glvl = 1;
	gxp = 0;
	skill_pts = 1;
	gcolor = NORM;
	mp = 300;
if(!symb_name) symb_name = "Unnamed";
	restore_object(SAVE_PATH+NAME);
	if(USER->query_level() < 20){
		USER->set_guild_name(GUILDNAME);
	}
	/* Armor bonuses */
	this_player()->RegisterArmor(this_object(), ({ "physical", 0, 0, "armor_special" }));
	if(this_player()->query_level() < 20){
		add_action("no_spell", "sonic", 2);
		add_action("no_spell", "fireball", 2);
		add_action("no_spell", "shock", 2);
		add_action("no_spell", "missile", 2);
		add_action("no_spell", "pose");
		add_action("no_spell", "invisible", 5);
	}
	add_action("store_mp", "store_mp");
	add_action("store_sp", "store_sp");
	add_action("store_coins", "store_mon");
	add_action("list_skills", "skills");
	add_action("link_help", "link");
	add_action("new_mon", "mon");
        add_action("cmd_chog", "chog");
	add_action("new_say", "say");
	add_action("new_say"); add_xverb("'");
	add_action("in_assign_tentacles", "assign");
	add_action("tent_list", "tentacles");
	add_action("set_gtitle", "gtitle");
	add_action("new_invis", "camouflage", 4);
	add_action("new_who", "threat");
	add_action("absorb", "absorb");
	add_action("mp_mon", "mp");
	add_action("save_venom2", "ssave");
	add_action("remove_sharmor", "remit");
	add_action("remove_grarmor", "ungraft");
	add_action("quit_out", "quit");
	add_action("inventory_cmd", "inventory", 1);
	add_action("new_score2", "sc2");
	add_action("new_score3", "score", 2);
	add_action("convert_xp", "convert");
	add_action("spend_pts", "raise_skill");
   add_action("set_color", "setcolor");
   add_action("list_pks", "pklist");
	add_action("catch_all");  add_xverb("");
	message_hit=({
			""+COLOR+"D E S T R O Y E D"+NORM+"", " with a frenzy of attacks",
			""+COLOR+"Mutilated"+NORM+"", "'s body into bloody ribbons",
			""+HIW+"Destroyed"+NORM+"", " with an onslaught of blows",
			""+HIW+"Massacred"+NORM+""," into small fragments",
			""+COLOR+"Slammed"+NORM+""," into the ground with bone shattering force",
			""+HIW+"Smashed"+NORM+""," with a bone crushing sound",
			""+HIW+"Hit"+NORM+""," very hard",
			""+HIW+"Hit"+NORM+""," hard",
			""+HIW+"Hit"+NORM+"","",
			""+HIW+"Grazed"+NORM+"","",
			""+HIW+"Tickled"+NORM+""," in the stomach",
	});
tell_object(USER, HIR+"\n\n\n\nPLEASE NOTE, LAIRS CAN NOW BE ENTERED BY ANYONE!"+NORM+"\n\n\n\n"+
         "NEWS:\n"+
  "This guild has been restored in accordance with Nirvana's code policy.\n"+    
  "Maledicta had closed this guild when he left, however over two months ago\n"+  
  "he became a founding member of a new mud using a great deal of Nirvana's\n"+
  "code. Under the code policy this allowed restoration of the guild.\n");
	done = 1;
}
query_slave_master(){ return USER->query_real_name(); }
/******************************************************************
**  This is the catch for the query_verb() to call skills of the **
**  new symbiote.                                                **
******************************************************************/
catch_all(str){
	string woo;
	string woot,woot2;
	if(delay_bad){ write("You are unable to do anything!\n"); return 1; }
	
	if(sscanf(str, "%s %s", woot, woot2) == 2){
		woo = SKEELLS+woot+".c";
		if(member_array(woot, skills) < 0) return;
                if(file_size(woo) > 0)
		woo->main(woot2, this_object(), this_player());
		return 1;
	}
	else{
		woo = SKEELLS+str+".c";
		if(member_array(str, skills) < 0) return;
               if(file_size(woo) > 0)
		woo->main(0, this_object(), this_player());
		return 1;
	}
	return;
}

/**************************************************************
**       Functions for no pet and no mini                    **
**************************************************************/
mini_dest(str){
	tell_object(USER,
	"Do not rely on such weak things!\n");
	return;
}

call_pet(){
	if(previous_object()->is_pet()){
		tell_room(environment(USER),
		"Your pet refuses to follow you and leaves.\n");
		destruct(previous_object());
		return 1;
	}
	return 1;
}

