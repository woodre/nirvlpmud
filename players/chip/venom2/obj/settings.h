
get(){ return 1; }
drop(){ return 1; }
query_weight(){ return 0; }
query_value(){ return 0; }




/************************************************************
*******  Guild Title Setting  (With Color) ******************
************************************************************/
set_gtitle(str){
	string ntitle;
	if(control < 4) return 0;
	if(!str){ write("gtitle <title>\n"); return 1; }
	ntitle = str;
	ntitle = extract(str, 0, 60);
	ntitle = "/players/maledicta/closed/class/color"->filter_msg(ntitle);
	USER->set_title(ntitle);
	write("->>>  "+USER->short()+"\n");
	return 1;
}



/*************************************************************
**      Color customization                                 **
*************************************************************/
query_color(){ return gcolor; }

set_color(str){
/* if(gcolor != NORM) return 0; */
if(!str){
   write("Choose by typing: setcolor <color>\n");
   return 1;
   }
	if(str == "red"){ gcolor = RED; }
	else if(str == "grey"){ gcolor = BOLD; }
	else if(str == "bred"){ gcolor = HIR; }
        else if(str == "bblack"){ gcolor = HIW; }
	else if(str == "blue"){ gcolor = BLU; }
	else if(str == "yellow"){ gcolor = YEL; }
	else if(str == "magenta"){ gcolor = MAG; }
	else if(str == "cyan"){ gcolor = CYN; }
	else if(str == "green"){ gcolor = GRN; }
	else if(str == "bblue"){ gcolor = HIB; }
	else if(str == "byellow"){ gcolor = HIY; }
	else if(str == "bmagenta"){ gcolor = HIM; }
	else if(str == "bcyan"){ gcolor = HIC; }
	else if(str == "bgreen"){ gcolor = HIG; }
	else{ gcolor = NORM; }
   if(gcolor == NORM){ write("Please choose a color.\n"); return 1; }
   else{ write("You have chosen "+gcolor+str+NORM+".\n"); return 1; }
   
}

/***************************************************************
**       Extra Sets and Queryies                              **
***************************************************************/
set_venom_name(str){ symb_name = str; }
query_venom_name(){ return symb_name; }
query_symbiote(){ return symb_name; }
set_spell_delay(str){ spell_delay = str; }
query_spell_delay(){ return spell_delay; }
set_delay(int i){ delay_bad = i; }
query_delay(){ return delay_bad; }
query_glvl(){ return glvl; }
set_glvl(int i){ glvl = i; }
add_body(int i){ body += i; }
query_body(){ return body; }
set_pet(ob){ pet = ob; }
query_pet(){ return pet; }

query_max_mp(){ return 300 + (glvl * 10) - query_used_mp(); }
query_used_mp(){ return used_mp; }
query_mp(){ if(USER->query_level() > 19) return 600; return mp; }
set_mp(int i){ if(USER->query_level() > 19) mp = query_max_mp(); mp = i; }
add_mp(int i){
   if(USER->query_level() > 19) mp = query_max_mp();
   else mp += i;
	if(mp > query_max_mp()) mp = query_max_mp();
	save_venom(1);
}


query_burnoff(){ return burnoff; }
set_burnoff(int i){ burnoff = i; }
query_regen(){ return regen; }
set_regen(int i){ regen = i; }
query_hypermode(){ return hypermode; }
set_hypermode(int i){ hypermode = i; }
set_wep_damage(int i){ wep_damage = i; }
query_wep_damage(){ return wep_damage; }
set_block(int i){ block = i; }
query_block(){ return block; }

query_lair(){ return lair; }
set_lair(str){ lair = str; }

add_recruit(int i){ recruit += i; }
query_recruit(){ return recruit; }

set_shaped(int i){ shaped = i; }
query_shaped(){ return shaped; }

set_shaped_form(string str){ shaped_form = str; }
query_shaped_form(){ return shaped_form; }
