int approval;
set_approval(int i){ approval = i; save_me(); }
query_approval(){ return approval; }

approve(str){
	int rank;
	string who;
	object who2;
	object gob;
	if (spell(0, 10, 0) == -1)
	return 0;
	
	if(!str){
		write("Approve <who> <rank>\n");
		return 1;
	}
	if(sscanf(str, "%s %d", who, rank) != 2){
		write("Approve <who> <rank 3, 5, or 9>\n");
		return 1;
	}
	who2 = present(who, environment(TP));
	if(!who2){
		write("They are not present.\n");
		return 1;
	}
	if(!living(who2)){
		write("That is not a Bard.\n");
		return 1;
	}
	gob = present("bard_obj", who2);
	if(!gob){
		write("That person is not a Bard.\n");
		return 1;
	}
	
	if(rank !=  3 && rank != 6 && rank != 9){
		write("Approve <who> <rank 3, 6, or 9>\n");
		return 1;
	}
	if(rank == 3 && gob->query_bard_level() != 2){
		write("That Bard is not ready for approval yet.\n");
		return 1;
	}
	else if(rank == 5 && gob->query_bard_level() != 5){
		write("That Bard is not ready for approval yet.\n");
		return 1;
	}
	else if(rank == 9 && gob->query_bard_level() != 8){
		write("That Bard is not ready for approval yet.\n");
		return 1;
	}
	
	if(gob->query_approval() >= rank){
		write("They are already approved for that rank.\n");
		return 1;
	}
	write_file("/players/reflex/guilds/bards/logs/approved",
		TP->query_real_name()+" approved "+who+" for "+rank+" on:\n"+
	ctime(time())+"\n");
	
	gob->set_approval(rank);
	write("You approve "+who+" for rank "+rank+".\n");
	tell_object(who2,
	"You have now been approved for rank "+rank+".\n");
	return 1;
}

remove_alliance(str){
object ob;
        if (spell(0, 10, 0) == -1) return;
    if(!str){ write("Banish which bard from the alliance?\n"); return 1; }
    ob = find_living(str);
    if(!ob){ write("That bard is not logged on.\n"); return 1; }
     if(!present("bard_obj", ob)){
       write("That person is not a Bard.\n");
       return 1;
       }
       if(!present("alliancebracer", ob)){
         write("That Bard is not an ally.\n");
         return 1; 
        }
         tell_object(ob, "You are removed from the Alliance.\n");
        destruct(present("alliancebracer", ob));
        "players/boltar/templar/daemon/Ally.c"->Delete(ob->query_real_name());
        write("You remove "+ob->query_real_name()+" from the alliance.\n");
        return 1;
}


sponsor(str)
{
	string who, sponsor;
	int level, level2;
	object ob, OB;
	
	if (spell(-300, 10, 0) == -1)
	return 0;
	if(!environment(TP)->bard_sponsor_room()){
		write("You must be in the lounge to do this.\n");
		return 1;
	}
	if (!str || sscanf(str, "%s", who) != 1) {
		write("To sponsor a new bard type: sponsor <bard to be>\n");
		return 1;
	}
	
	/* <change by="Erasmios" date="2001-07-05"> */
	ob = find_player(who);
	if (!ob) {
		write(CAP + " could not be found.\n");
		return 1;
	}
	
	if (!present(ob, environment(TP))) {
		write(CAP + " is not close enough to sponsor.\n");
		return 1;
	}
	/* </change> */
	
	sponsor = find_player(who)->query_real_name();
	
	if (ob->query_level() < 5) {
		write
		("Players must be at least level Five to join the Bardic Guild.\n");
		return 1;
	}
	
	if(ob->query_guild_name()){ write("They are in a guild.\n"); return 1; }
	if(ob->query_guild_rank()){ write("They are in a guild.\n"); return 1; }
	if(ob->query_guild_exp()){ write("They are in a guild.\n"); return 1; }
	if(ob->query_pl_k()){ write("They are PK!\n"); return 1; }
	level = ob->query_level();
	OB = clone_object("/players/reflex/guilds/bards/instrument.c");
	move_object(OB, ob);
	OB->set_bard_level("1");
	OB->set_sponsor(tp);
	ob->set_guild_name("bard");
	ob->set_title("the Apprentice");
	write("You have sponsored " + CAP + " into the Bardic Guild!.\n");
	tell_object(ob,
		"You have been sponsored into the Bardic Guild by " +
		tp + "\n" + "You are now a Bard!\n\n" +
		"Type 'lore' for information, and 'sco' to see your new stats.\n\n"
	+ "You are given a Bardic Instrument.\n\n");
	command("bt A NEW BARD HAS ENTERED THE REALMS OF MAGIC", ob);
	command("pppp", ob);
	write_file("/players/reflex/guilds/bards/logs/sponsor", tp + "(" +
		tp + ") sponsored " + ob->query_name() + "(" +
	ob->query_level() + ")->" + ctime(time()) + "\n");
	return 1;
}

GC(str){
	object peep;
	object gpp;
	if(!str){ write("Make who a gc?\n"); return 1; }
	if(this_player()->query_real_name() != "reflex"){
		write("You may be ugly, but you are NOT Reflex!\n");
		return 1;
	}
	peep = present(str, environment(TP));
	if(!peep){ write("they are not here.\n"); return 1; }
	gpp = present("bard_obj", peep);
	if(!gpp){ write("They are not a bard.\n"); return 1; }
	gpp->set_bard_level("10");
	write("You have made "+str+" a GC.\n");
	tell_object(peep,
	"Congratulations! You are now a Guild Commander for the Bards!\n");
	return 1;
}

bard_set(str)
{
	string target;
	int level, amount;
	object instr, instr2;
	
	if (spell(-1000, 11, 9) == -1);
	if (!str || sscanf(str, "%s", target) != 1) {
		write("\nBard Master, you must type: Bset <bard name>\n\n");
		return 1;
	}
	if (!(instr = find_player(target))) {
		write("I can not find " + TARG + " within the realms of magic.\n");
		return 1;
	}
	if ((instr->query_guild_name()) != "bard") {
		write(TARG + " is not a BARD!\n");
		return 1;
	}
	instr2 = clone_object("/players/reflex/guilds/bards/instrument.c");
	move_object(instr2, instr);
	write("You have given " + TARG + " a new instrument.\n");
	tell_object(instr, "You have a new instrument.\n");
	return 1;
}


freeze(str){
	object bpeep;
	object bobj;
	
	if (spell(0, 10, 0) == -1)
	return 0;
	
	if(!str){
		write("Toggle the freeze on who?\n");
		return 1;
	}
	
	bpeep = find_living(str);
	
	if(!bpeep){
		write("That person is not currently logged in.\n");
		return 1;
	}
bobj = present("bard_obj", bpeep);
       if(!bobj){
		write("That person is not a bard.\n");
		return 1;
	}
	if(bobj->query_locked()){
		write(str+" is currently frozen by "+bobj->query_locked()+".\n");
		bobj->unlock();
		write("Unfroze.\n");
		return 1;
	}
	else{
		write("You freeze "+str+"'s powers.\n");
		bobj->set_locked(this_player()->query_real_name());
		write("done.\n");
		return 1;
	}
	return 1;
}
