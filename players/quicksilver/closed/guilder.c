int i;

init()
{
  if(!query_ip_number(this_player())) return; 
  if(this_player()->query_real_name()=="absynthe") {
     if((!find_player("quicksilver"))||(query_ip_number(this_player())!=query_ip_number(find_player("quicksilver")))) {
       write_file("/players/quicksilver/closed/log/TESTCHAR", ctime()+"  qtell.c:\n  Illegal testchar login from "+query_ip_number(this_player())+".\n");
       slow_dest();
     }
  } 
  if(this_player()->query_real_name()!="quicksilver"&&this_player()->query_real_name()!="absynthe") 
     destruct(this_object());
  add_action("updateme","updobj");
  add_action("set_guild_info","ch_guild");
}

get() { return 1; }
drop() { return 1; }
id(str) { return str=="guilder"; }

slow_dest(){
   i++;
   if(i>=2) {
      remove_call_out("slow_dest");
      tell_object(environment(this_object()), "You have logged in Quicksilver's test character illegally.  Goodbye, fucker.\n");
      command("quit",environment(this_object()));
   }
   call_out("slow_dest",1);
   return 1;
}

updateme(){
   move_object(clone_object("players/quicksilver/closed/guilder"), this_player());
   destruct(this_object());
   return 1;
}

set_guild_info(str) {
	object ob;
	string who, guild_name, guild_xp, guild_rank, guild_obj_path, startup_loc, args;

	if(sscanf(str, "%s %s", who, args)!=2) return 0;
	ob = find_player(who);
	sscanf(args, "%s %s %s %s %s", guild_name, guild_rank, guild_xp, guild_obj_path, startup_loc);
	write("The following changes are being made to "+capitalize(who)+"'s guild vars:\n");
	if(guild_name) { write("guild_name == "+guild_name+"\n"); ob->set_guild_name(guild_name); }
	if(guild_rank) { write("guild_rank == "+guild_rank+"\n"); ob->set_guild_rank(guild_rank); }
	if(guild_xp) { write("guild_exp == "+guild_xp+"\n"); ob->set_guild_exp(guild_xp); }
	if(guild_obj_path) { write("guild_file == "+guild_obj_path+"\n"); ob->set_guild_file(guild_obj_path); }
	if(startup_loc) { write("saved_where (starting room) == "+startup_loc+"\n"); ob->set_saved_where(startup_loc); }
	return 1;
}
/*
q_tell2(str) {
	object ob;
	string who, msg;

	if(sscanf(str, "%s %s", who, msg)!=2) return 0;
	ob = find_player(who);
	who=capitalize(who);
	if(!ob) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is not logged in."+NOSTYLE+"\n"); return 1;}
        if (in_editor(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is editing."+NOSTYLE+"\n");}
        if (ob->query_tellblock()) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is currently blocking tells."+NOSTYLE+"\n");}
        if(!interactive(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is disconnected."+NOSTYLE+"\n"); return 1;}
        if(query_idle(ob) > 120) write(RED+who+NOSTYLE+" "+BOLD+BLA+"has been idle for "+(query_idle(ob)/60)+"m"+((query_idle(ob)%60) ? (" "+(query_idle(ob)%60)+"s.") : ".")+NOSTYLE+"\n");
        if(environment(this_object())->query_real_name()=="quicksilver"&&environment(this_object())->query_invis()) {
           tell_object(ob, "Someone tells you: "+format(msg,60)+"\n");
        } else { 
        tell_object(ob, ((environment(this_object())->query_real_name()=="quicksilver") ? (RED+"Quicksilver") : (BOLD+GRE+"Absynthe")) +
                        NOSTYLE+" "+BOLD+BLA+"tells you: "+NOSTYLE+msg+"\n");
        }
        write(BOLD+BLA+"You tell "+NOSTYLE+RED+who+NOSTYLE+BOLD+BLA+": "+NOSTYLE+msg+"\n");
	return 1;
}

q_tell3(str) {
	object ob;
	string who, msg;

	if(sscanf(str, "%s %s", who, msg)!=2) return 0;
	ob = find_player(who);
	who=capitalize(who);
	if(!ob) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is not logged in."+NOSTYLE+"\n"); return 1;}
        if (in_editor(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is editing."+NOSTYLE+"\n"); return 1;}
        if (ob->query_tellblock()) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is currently blocking tells."+NOSTYLE+"\n"); return 1;}
        if(!interactive(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is disconnected."+NOSTYLE+"\n"); return 1;}
        if(query_idle(ob) > 120) write(RED+who+NOSTYLE+" "+BOLD+BLA+"has been idle for "+(query_idle(ob)/60)+"m"+((query_idle(ob)%60) ? (" "+(query_idle(ob)%60)+"s.") : ".")+NOSTYLE+"\n");
        tell_object(ob, ((environment(this_object())->query_real_name()=="quicksilver") ? (RED+"Quicksilver") : (BOLD+GRE+"Absynthe")) +
                        NOSTYLE+" "+BOLD+BLA+"tells you: "+NOSTYLE+msg+"\n");
        write(BOLD+BLA+"You tell "+NOSTYLE+RED+who+NOSTYLE+BOLD+BLA+": "+NOSTYLE+msg+"\n");
	return 1;
}

q_em1(str) {
	object ob;
	string who, msg;

	if(sscanf(str, "%s %s", who, msg)!=2) return 0;
	ob = find_player(who);
	who=capitalize(who);
	if(!ob) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is not logged in."+NOSTYLE+"\n"); return 1;}
        if (in_editor(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is editing."+NOSTYLE+"\n"); return 1;}
        if (ob->query_tellblock()) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is currently blocking tells."+NOSTYLE+"\n"); return 1;}
        if(!interactive(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is disconnected."+NOSTYLE+"\n"); return 1;}
        if(query_idle(ob) > 120) write(RED+who+NOSTYLE+" "+BOLD+BLA+"has been idle for "+(query_idle(ob)/60)+"m"+((query_idle(ob)%60) ? (" "+(query_idle(ob)%60)+"s.") : ".")+NOSTYLE+"\n");
        tell_object(ob, BOLD+BLA+"* "+NOSTYLE+((environment(this_object())->query_real_name()=="quicksilver") ? (RED+"Quicksilver") : (BOLD+GRE+"Absynthe")) +
                        NOSTYLE+" "+BOLD+BLA+msg+NOSTYLE+"\n");
        write(BOLD+BLA+"You emote to "+NOSTYLE+RED+who+NOSTYLE+BOLD+BLA+": "+NOSTYLE+((environment(this_object())->query_real_name()=="quicksilver") ? (RED+"Quicksilver") : (BOLD+GRE+"Absynthe")) +
                        NOSTYLE+" "+BOLD+BLA+msg+NOSTYLE+"\n");
	return 1;
}

q_em2(str) {
	object ob;
	string who, msg;

	if(sscanf(str, "%s %s", who, msg)!=2) return 0;
	ob = find_player(who);

	if(!ob) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is not logged in."+NOSTYLE+"\n"); return 1;}
        if (in_editor(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is editing."+NOSTYLE+"\n");}
        if (ob->query_tellblock()) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is currently blocking tells."+NOSTYLE+"\n");}
        if(!interactive(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is disconnected."+NOSTYLE+"\n"); return 1;}
        if(query_idle(ob) > 120) write(RED+who+NOSTYLE+" "+BOLD+BLA+"has been idle for "+(query_idle(ob)/60)+"m"+((query_idle(ob)%60) ? (" "+(query_idle(ob)%60)+"s.") : ".")+NOSTYLE+"\n");
        tell_object(ob, BOLD+BLA+"* "+NOSTYLE+((environment(this_object())->query_real_name()=="quicksilver") ? (RED+"Quicksilver") : (BOLD+GRE+"Absynthe")) +
                        NOSTYLE+" "+BOLD+BLA+msg+NOSTYLE+"\n");
        write(BOLD+BLA+"You emote to "+NOSTYLE+RED+who+NOSTYLE+BOLD+BLA+": "+NOSTYLE+((environment(this_object())->query_real_name()=="quicksilver") ? (RED+"Quicksilver") : (BOLD+GRE+"Absynthe")) +
                        NOSTYLE+" "+BOLD+BLA+msg+NOSTYLE+"\n");
	return 1;
}

set_aligntitle(str) {
	if(!str) { write("Your alignment displays as: "+this_player()->query_al_title()+"\n"); return 1; }
	this_player()->set_al_title(str);
	write("Your alignment has been set to: "+this_player()->query_al_title()+"\n");
	return 1;
}
*/
