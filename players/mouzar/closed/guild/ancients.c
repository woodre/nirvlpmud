/*ver 3.0*/
#include "/players/mouzar/misc/color.h"
#include "/players/mouzar/closed/guild/include.h"
id(str){return str=="ancients";}
reset(arg) {
    int h;
    msgbuf = allocate(HISTORY +1);
    for(h = 0;h <= HISTORY; h++) {
	msgbuf[h] = "";
    }
}
buf(str) {
    msgbuf = ((sizeof(msgbuf) >=HISTORY) ? msgbuf[1..HISTORY-1] : msgbuf) + (({ str }));
}
do_history() {
    int l, max;
    max = sizeof(msgbuf);
    for(l=0; l < max; l++)
	write(msgbuf[l]);
    return 1;
}
ANSI_set() {
    if(ME->ANSI == 0) {
	ME->set_ANSI(1);
	write(PURPLE+"ANSI turned ON!\n"+END);
	return 1;
    } else {
	ME->set_ANSI(0);
	write("ANSI off :(\n");
	return 1;
    }
    return 1;
}
Rhelp() {
    cat("/players/mouzar/open/help.list");
    return 1;
}
Skills() {
    cat("/players/mouzar/open/skill.list");
    return 1;
}
Rules() {
    cat("/players/mouzar/open/skill.list");
    return 1;
}
Rhelp2() {
    if(TAT->glvl()<=10) return 0;
    cat("/players/mouzar/open/hr.list");
    return 1;
}
list_title() {
    cat("/players/mouzar/open/title.list");
    return 1;
}
Rnew() {
    cat("/players/mouzar/open/order.news");
    return 1;
}
sayit(str) {
    int x;
    object us;
    us=users();                     
    for(x=0;x<sizeof(us);x++)
	if(present("riskadh-tattoo",us[x])&&present("riskadh-tattoo",us[x])->query_muf()==0) {
	    if(us[x]->ANSI == 1)
		tell_object(us[x],BLUE+"{>"+NWHITE+"Grand Master Riskadh"+BLUE+"<}: "+str+""+END);
	    else
		tell_object(us[x],"{>Grand Master Riskadh<}: "+str);
	}
    return 1;
}
ot(str) {
    int x;
    object us, msg;
    if(!str) return;
    if(muf==1) {
	write("You may not do any tells to the order while you are muffled.\n");
	return 1;
    }
    us=users();
    buf("{>"+JN+"<}: "+str+"\n");
    for(x=0;x<sizeof(us);x++) {
	if(present("riskadh-tattoo",us[x])&&present("riskadh-tattoo",us[x])->query_muf()==0) {
	    if(us[x]->ANSI == 1)
		tell_object(us[x],BLUE+"{>"+END+""+NWHITE+""+JN+""+END+""+BLUE+"<}: "+LIGHT_BLUE);
	    else
		tell_object(us[x],"{>"+JN+"<}: ");
	    tell_object(us[x],implode(explode(sprintf("%-=64s",str),"\n"),"\n    ")+"\n");
	    if(us[x]->ANSI == 1) tell_object(us[x],END);
	}
    }
    if(random(10) == 1) no_guilder();
    return 1;
}
oe(str) {
    int x;
    object us, msg;
    if(!str) return;
    if(muf==1) {
	write("You may not do any emotes to the order while you are muffled.\n");
	return 1;
    }
    us=users();
    buf("{>"+JN+" "+str+"\n");
    for(x=0;x<sizeof(us);x++) {
	if(present("riskadh-tattoo",us[x])&&present("riskadh-tattoo",us[x])->query_muf()==0) {
	    if(us[x]->ANSI == 1)
		msg=BLUE+"{>"+END+""+NWHITE+""+JN+""+END+""+LIGHT_BLUE+" "+str+""+END;
	    else
		msg="{>"+JN+" "+str;
	    tell_object(us[x],implode(explode(sprintf("%-=70s",msg),"\n"),"\n    ")+"\n");
	}
    }
    if(random(10) == 1) no_guilder();
    return 1;
}
owho() {
    int x;
    object us,list;
    us=users();
    list=bubble_sort(us,"query_level"); 
    write("Name          Idle     G-Lvl    Location\n");
    write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for(x=0;x<sizeof(list);x++) {
	if(present("riskadh-tattoo",list[x])){
	    if(list[x]->query_invis()<=LVL) {
		write(CAP(list[x]->query_real_name()));
		if(strlen(list[x]->query_real_name())<8) write("\t\t"); else write("\t");
		write("\b\b"+query_idle(us[x])/60+" min\t"); 
		write(present("riskadh-tattoo",list[x])->query_marks()+"\t");
		write(env(list[x])->short());
		if(present("riskadh-tattoo",list[x])->query_muf()==1)
		    if(list[x]->ANSI == 1)
			write(YELLOW+" {Muffled}"+END);
		    else
			write(" {Muffled}");
		write("\n");
	    }
	}
    }
    return 1;
}
kdwho() {
    int x;
    object us;
    us=bubble_sort(users(),"query_number_killed");
    write("Name          K/D    \n");
    write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    for(x=0;x<sizeof(us);x++) {
	if(us[x]->query_invis()<=LVL&&us[x]->query_level()<27) {
	    write(capitalize(us[x]->query_real_name()));
	    if(strlen(us[x]->query_real_name())<8) write("\t\t"); else write("\t");
	    write("\b\b"+us[x]->query_number_killed()+"/"+us[x]->query_times_killed()+"\t"); 
	    write(us[x]->show_age()+"\b");
	}
    }
    return 1;
}

tattoo(str) {
    if(!str) return;
    if(TAT->glvl()<=10) return 0;
    if(!find_living(str)) {
	write("I could not find: "+str+"\n");
	return 1;
    }
    if(find_living(str)->query_level()<4) {
	write(CAP(str)+" is not high enough level to be given a tattoo.\n");
	return 1;
    }
    if(present("riskadh-tattoo",find_living(str))) {
	write(CAP(str)+" already has a tattoo.\n");
	return 1;
    }
    if(present("guild_object",find_living(str)) && find_living(str)->query_level()<30) {
	write(CAP(str)+" is already in a guild!\n");
	return 1;
    }
    move_object(clone_object("/players/mouzar/closed/guild/tattoo"),find_living(str));
    tell_object(find(str),"You feel a pain in your arm!\n"+RN+" has given you a tattoo of the Riskadh...wear it proudly.\n");
    write_file("/players/mouzar/closed/guild/log/tat",RN+" gave "+CAP(str)+" a tattoo.\n");   
    write("You have just given "+CAP(str)+" a Riskadh Tattoo.\n");
    return 1;
}
banish(str) {
    if(!str) return;
    if(TAT->glvl()<=11) return 0;
    if(!find_living(str)) {
	write("You could not find: "+CAP(str)+"\n");
	return 1;
    }
    if(find_living(str)->query_real_name() == "mouzar") {
	write("Grand Master Riskadh tells you:  WHAT THE FUCK ARE YOU TRYING TO DO!\n");
	tell_object(find_living(str),RED+""+RN+" tried to banish you!\n"+END);
	return 1;
    }
    if(find_living(str)->query_level() > 26) {
	write("Grand Master Riskadh tells you:  I can't let you take a Wizzies tattoo away.\n");
	return 1;
    }
    if(!present("riskadh-tattoo",find_living(str))) {
	write("That person does not have a tattoo.\n");
	return 1;
    }
    destruct(present("riskadh-tattoo",find(str)));
    tell_object(find(str),RN+" has banished you from all guilds.\n");
    find(str)->set_guild_name("Banished");
    write("You have just banished "+CAP(str)+" from all guilds.\n");
    write_file("/players/mouzar/closed/guild/log/banish",RN+" banished "+str+"!\n");
    return 1;
}
detattoo(str) {
    if(!str) return;
    if(TAT->TAT->glvl()<=10) return 0;
    if(str == rn) {
	write("You can't take away your tattoo!\n");
	return 1;
    }
    if(!find_living(str)) {
	write("I could not find: "+CAP(str)+"\n");
	return 1;
    }
    if(find_living(str)->query_real_name() == "mouzar") {
	write("Grand Master Riskadh tells you:  WHAT THE FUCK ARE YOU TRYING TO DO!\n");
	tell_object(YELLOW+"mouzar",RN+" tryed to take way your tattoo!\n"+END);
	return 1;
    }
    if(!present("riskadh-tattoo",find_living(str))) {
	write("That person does not have a tattoo.\n");
	return 1;
    }
    if(find_living(str)->qeury_level() >= 1000) {
	write("Don't think so!\n");
	return 1;
    }
    destruct(present("riskadh-tattoo",find_living(str)));
    tell_object(find_living(str),RN+" has just rubbed your tattoo off.\n");
    write("You have just rubbed "+CAP(str)+"'s tattoo off.\n");
    write_file("/players/mouzar/closed/guild/log/detat",RN+" rubbed "+str+"'s tat off!\n");
    return 1;
}
newmark(str) {
    string target;
    object fin;
    int r,new;
    if(TAT->glvl()<=10) return 0;
    if(!str) return;
    if(sscanf(str,"%s %d",target,r)!=2) return;
    fin = find_living(target);
    if(present("riskadh-tattoo",fin))
	fin->add_guild_rank(r);
    new = present("riskadh-tattoo",fin)->query_marks();
    tell_object(fin, RN+" has changed the marks on your tattoo.\n");
    write_file("/players/mouzar/closed/guild/log/marks",RN+" changed "+r+" marks on "+str+" Glvls.("+new+")\n");
    write("You have just changed "+str+"'s marks.\n");
    return 1;
}
newcloaker() {
    object ob;
    ob=clone_object("/players/mouzar/closed/guild/cloaker");
    CLK=ob;
    ob->set_owner(this_player()->query_real_name());
    move_object(ob,env(ME));
    write("You bow your head in concentration and summon a Cloaker.\n");
    TAT->SAY(RN+" bows "+ME->query_possessive()+" head in concentration and summons a Cloaker.\n");
    return 1;
}

CLOAKER(str) {
    string one,two,three;
    if(!str) {
	write("                        The Commands for the Cloaker\n");
	write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	write("  cloaker summon ..... Summon a cloaker to your side (100sp)\n");
	write("  cloaker bring ...... Bring the cloaker to you\n");
	write("  cloaker leave ...... Let the cloaker return to a dark cave\n");
	write("  cloaker stop ....... Makes your cloaker back away from a fight\n");
	write("  cloaker stay ....... Makes your cloaker stay in a room\n");
	write("  Kill <target> ...... Commands the cloaker to kill <target>\n");
	write("  rename ............. Name the cloaker whatever you want\n");
	return 1;
    }
    if(TAT->glvl()<5) return 0;
    if(str=="summon") {
	if(SP<100&&LVL<30) {
	    write("You don't have the mental strength to do that!\n");
	    return 1;
	}
	if(!TAT->query_CLK()) {
	    newcloaker();
	    lessp(100);
	    TAT->set_CLK(CLK);
	    return 1;
	}
	write("You already have a Cloaker!\n");
	return 1;
    }
    if(!TAT->query_CLK()) {
	write("You do not have a Cloaker.\n");
	return 1;
    }
    if(str=="leave") {
	TAT->query_CLK()->SAY("A Cloaker flies off to find a dark cave somewhere.\n");
	destruct(TAT->query_CLK());
	write("Your Cloaker flies off.\n");
	return 1;
    }
    if(str=="bring") {
	TAT->query_CLK()->SAY("A Cloaker flies off.\n");
	move_object(TAT->query_CLK(),env(ME));
	TAT->query_CLK()->set_move(0);
	TAT->query_CLK()->SAY("A Cloaker flies into the room.\n");
	return 1;
    }
    if(str=="stop") {
	TAT->query_CLK()->stop_fight();
	TAT->query_CLK()->SAY("A Cloaker backs away from the fight.\n");
	return 1;
    }
    if(str=="stay") {
	TAT->query_CLK()->set_move(1);
	TAT->query_CLK()->SAY("A Cloaker flies into a corner.\n");
	return 1;
    }
}

lessp(x) {
    if(SP<x) return 0;
    if(LVL>30) return;
    ME->add_spell_point(-x);
    return 1;
    ME->add_spell_point(-x);
    return 1;
}

frenzy(str) {
    object hur;
    if(str) hur = str;
    if(!str && ME->query_attack()) {
	str = ME->query_attack();
	hur = ME->query_attack()->query_name();
    }
    if(!str) return;
    if(!hur) return;
    if(str==rn) {
	write("You idiot!  Why would you want to do that?\n");
	return 1;
    }
    if(!pse) {
	write("That is not here.\n");
	return 1;
    }
    if(!living(pse)) {
	write("That is not alive!\n");
	return 1;
    }
    if(!pse->PK && pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  This player doesn't have PK set.\n");
	return 1;
    }
    if(pse->query_npc() == 0 && TAT->query_PK_flag() == 1) {
	write("You must wait a bit.\n");
	return 1;
    }
    if(!ME->PK && pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  You dont have your pk set wimp.\n");
	return 1;
    }
    if(SP<TAT->glvl()*3 && LVL<30) {  
	write("You do not have the mental power to do that.\n");
	return 1;
    }
    if(peace_room()) return 1;
    if(!DELAY()) return 0;
    if(!pse->query_npc()) {
	write_file("/players/mouzar/closed/guild/log/frenzy",RN+" went crazy on "+hur+" at "+ctime(time())+".\n");
	TAT->set_PK_flag(1);
	call_out("PK_can_again",2);
    }
    lessp(TAT->glvl()*3);
    write("You cut up "+hur+"!\n");
    TAT->SAY(RN+" goes into a fighting frenzy and cuts up "+CAP(hur)+"!\n");
    pse->hit_player(TAT->glvl()*3);
    return 1;
}

mind_blast(str) {
    object hur;
    int intel;
    if(str) hur = str;
    if(!str && ME->query_attack()) {
	str = ME->query_attack();
	hur = ME->query_attack()->query_name();
    }
    if(!str) return;
    if(!hur) return;
    if(TAT->glvl()<6) return 0;
    if(str==rn) {
	write("You idiot!  Why would you want to do that?!!\n");
	return 1;
    }
    if(!pse) {
	write("That is not here!\n");
	return 1;
    }
    if(!pse->PK && pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  This player doesn't have PK set.\n");
	return 1;
    }
    if(pse->query_npc() == 0 && TAT->query_PK_flag() == 1) {
	write("You must wait a bit.\n");
	return 1;
    }
    if(!ME->PK && pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  You dont have your pk set wimp.\n");
	return 1;
    }
    if(SP<50&&LVL<30) {
	write("You do not have the mental strength to do that.\n");
	return 1;
    }
    lessp(50);
    if(!living(pse)) {
	write("That is not alive!\n");
	return 1;
    }
    if(peace_room()) return 1;
    if(!DELAY()) return 0;
    if(!pse->query_npc()) {
	write_file("/players/mouzar/closed/guild/log/mb",RN+" mind blasted "+hur+" at "+ctime(time())+".\n");
	TAT->set_PK_flag(1);
	call_out("PK_can_again",2);
    }
    write("You fry "+hur+"'s mind with a powerful blast.\n");
    TAT->SAY("You see "+CAP(hur)+"'s eyes flip and "+pse->query_pronoun()+" go into some spasms.\n");
    intel = ME->query_int();
    pse->hit_magic(45+random(intel/8));
    return 1;
}

shield() {
    if( TAT->glvl()<5) return 0;
    if(TAT->query_shield_flag() == 1) {  
	write("You already doing that!\n");
	return 1;
    }
    if(SP<60&&LVL<30) {
	write("You do not have the mental strength to do that.\n");
	return 1;
    }
    ME->add_ac(3);
    TAT->set_shield_flag(1);
    lessp(60);
    write("You start using your Riskadh ability of blocking to it's fullest.\n");
    TAT->SAY(RN+" puts in a second effort at blocking "+ME->query_possessive()+" enemy.\n");
    call_out("shield_off",60);
    return 1;
}

shield_off() {
    if(ME->ANSI == 1)
	tell_object(env(TAT),GREEN+"You slow down your defence.\n"+END);  
    else
	tell_object(env(TAT),"You slow down on your defence.\n");
    env(TAT)->add_ac(-3);
    TAT->set_shield_flag(0);
    TAT->SAY(RN+" gets tired of defending "+ME->query_possessive()+" and slows down.\n");
    return 1;
}
balance(){
    int SPdif, HPdif, tog, mid;
    if(TAT->glvl()<6) return;
    SPdif = ME->query_msp() - SP;
    HPdif = ME->query_mhp() - HP;
    tog = HPdif+SPdif;
    mid = SPdif/2;
    if (mid>SP) {
	ME->add_hit_point(SP-1);
	ME->add_spell_point(-SP+1);
	return 1; 
    } else {
	if (mid>HP) {
	    ME->add_spell_points(HP-1);
	    ME->add_hit_point(-HP+1);
	    return 1; 
	}
    }
    if (HPdif>SPdif) {
	ME->add_spell_points(-mid);
	ME->add_hit_points(SPdif-mid); 
    } else {
	ME->add_spell_point(mid);
	ME->add_hit_point(-SPdif+mid);
    }
    write("last\n");
    return 1;
}

swap(str) {
    int amt;
    string points;

    if( TAT->glvl()<4) return 0;
    if((!str) || ((sscanf(str,"%s %d",points,amt) !=2))) { 
	write("Swap what?\n");
	return 1;
    }
    if (points=="sp") {
	if(amt>SP) {
	    write("Grand Master Riskadh tells you: i can not let you do that.\n");
	    return 1;
	}
	if(HP == ME->query_mhp()) {
	    write("You do not need any Hit Point healing.\n");
	    return 1;
	}
	if(HP+amt>ME->query_mhp()) amt=ME->query_mhp()-HP;
	ME->add_spell_point(-amt);
	ME->add_hit_point(amt);
	write("You use your mental strength to make physical strength.\n");
	return 1;
    }
    if (points=="hp") {
	if(amt>HP) {
	    write("Grand Master Riskadh tells you: i can not let you do that.\n");
	    return 1;
	}
	if(SP==ME->query_msp()) {
	    write("You do not need any Spell Point healing.\n");
	    return 1;
	}
	if(SP+amt>ME->query_msp()) amt=ME->query_mhp()-HP;
	ME->add_hit_point(-amt);
	ME->add_spell_point(amt);
	write("You use your physical strength to make mental strength.\n");
	return 1;
    }
} 

poison(str) {
    object ob;
    object hur;
    if(str) hur = str;
    if(!str && ME->query_attack()) {
	str = ME->query_attack();
	hur = ME->query_attack()->query_name();
    }
    if(!str) return;
    if(!hur) return;
    if( TAT->glvl()<10) return 0;
    if(str==rn) {
	write("Why would you want to do that?\n");
	return 1;
    }
    if(!present(str,env(ME))) {
	write("That is not here.\n");
	return 1;
    }
    if(!pse->PK && pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  This player doesn't have PK set.\n");
	return 1;
    }
    if(pse->query_npc() == 0 && TAT->query_PK_flag() == 1) {
	write("You must wait a bit.\n");
	return 1;
    }
    if(!ME->PK && pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  You dont have your pk set wimp.\n");
	return 1;
    }
    if(present("poison",pse)) {
	write("You may only poison something once.\n");
	return 1;
    }
    if(SP<50&&LVL<30) {
	write("You do not have the mental strength to do that.\n");
	return 1;
    }
    if(peace_room()) return 1;
    if(!pse->query_npc()) {
	write_file("/players/mouzar/closed/guild/log/poison",RN+" poisoned "+hur+" at "+ctime(time())+".\n");
	TAT->set_PK_flag(1);
	call_out("PK_can_again",2);
    }
    ob=clone_object("/players/mouzar/closed/guild/poison");
    ob->set_STR(10);
    move_object(ob,present(str,env(ME)));
    write("You throw a poisoned dart at "+CAP(hur)+"!\n");
    TAT->SAY(RN+" throws a dart at "+CAP(hur)+" and grins evilly.\n",pse);
    present(str,env(ME))->attack_object(ME);
    lessp(50);
    return 1;
}

break_bone(str) {
    object hur;
    if(str) hur = str;
    if(!str && ME->query_attack()) {
	str = ME->query_attack();
	hur = ME->query_attack()->query_name();
    }
    if(!str) return;
    if(!hur) return;
    if( TAT->glvl()<3) return 0;
    if(!pse) {
	write(CAP(str)+" not found.\n");
	return 1;
    }
    if(!pse->PK && pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  This player doesn't have PK set.\n");
	return 1;
    }
    if(pse->query_npc() == 0 && TAT->query_PK_flag() == 1) {
	write("You must wait a bit.\n");
	return 1;
    }
    if(!ME->PK && pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  You dont have your pk set wimp.\n");
	return 1;
    }
    if(SP< TAT->glvl()*6&&LVL<30) {
	write("You do not have enough spell points for that.\n");
	return 1;
    }
    if(peace_room()) return 1;
    if(!DELAY()) return 0;
    if(!pse->query_npc()) {
	write_file("/players/mouzar/closed/guild/log/skedarh",RN+" broke "+hur+" bone at "+ctime(time())+".\n");
	TAT->set_PK_flag(1);
	call_out("PK_can_again",2);
    }
    write("You find a weak spot in you oppenents bone and you break it!\n");
    TAT->SAY(RN+" lashes out with a strong kick and you hear a crack!\n");
    pse->hit_player( TAT->glvl()*6);
    lessp( TAT->glvl()*6);
    return 1;
}

ewho(){
    string gu;
    object us,people;
    int x, noi;
    people=users();
    us=bubble_sort(people,"query_level");
    write("-Level-=Name=-=-=-=Sex=Guild=-=-Location=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for(x=0;x<sizeof(us);x++){
	if(us[x]->query_invis()<=LVL) {   
	    noi = noi + 1;
	    write("{"+us[x]->query_level()+"}");
	    if(us[x]->query_level()<100000){write("\t");}
	    write(capitalize(us[x]->query_real_name()));
	    if(strlen(us[x]->query_real_name())>7)
		write("\t");else write("\t\t");
	    write("\b\b\b\b\b");
	    if(us[x]->query_gender()==1)
		write(" M  ");
	    else
	    if(us[x]->query_gender()==2)
		write(" F  ");
	    else
		write(" C  ");
	    if(us[x]->query_level()>29){
		gu = "";
		if(present("head-MAGNUS",us[x])){
		    gu = gu + "I ";
		}
		if(present("tattoo",us[x])){
		    gu = gu + "R ";
		}
		if(present("agbag",us[x])){
		    gu = gu + "S ";
		}
		if(present("marauder_obj",us[x])){
		    gu = gu + "M ";
		}
		if(present("fangs",us[x])){
		    gu = gu + "V ";
		}
		if(present("psychic-power",us[x])){
		    gu = gu + "P ";
		}
		if(present("amulet-RAJAH",us[x])){
		    gu = gu + "E ";
		}
		if(gu=="") {
		    write("None");
		} else { 
		    write(gu); 
		}
	    }  
	    if(us[x]->query_level()<30){
		if(present("amulet-RAJAH",us[x]))
		    write("Element");
		else
		if(us[x]->query_guild_name())
		    write(capitalize(us[x]->query_guild_name()));
		else
		    write("None");
	    }  
	    write("\t");
	    if(!env(us[x]))write("Logging in");
	    else 
		write(env(us[x])->short());
	    write("\n");
	}
    }   
    write("-=-=-=-=-=-=-=-=-=-=-=-Players currently logged on: "+noi);
    if(noi<10)write("-");
    write("=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    return 1;
}

call_ancients(){
    object junk;
    int i;
    if( TAT->glvl()<8) return 0;
    if(SP<50&&LVL<30) {
	write("You do not have the mental strength to do that.\n");
	return 1;
    }
    if(peace_room()) return 1;
    if(!DELAY()) return 0;
    write("You call upon the ancients to help you kill all your enemies.\n");
    lessp(50);
    TAT->SAY(RN+" mummers some words and some how all of "+ME->query_possessive()+" enemies double\n"+
      "double over in pain.\n");
    junk=all_inventory(env(ME));
    while (i <sizeof(junk))
	damage(junk[i++]);
    return 1;
}

damage(ob) {
    if(ob->query_pet()) return 1;
    if(ob->query_npc()||ob->query_pet()) {
	ob->hit_magic(10+random(30));
    }
}

hide() {
    object aggr;
    int i;
    if( TAT->glvl()<3) return 0;
    if(SP<25&&LVL<30) {
	write("You do not have the mental strength to do that.\n");
	return 1;
    }
    write("You throw down a smoke bomb and hide in the shadows.\n");
    TAT->SAY(RN+" throws down a smoke bomb, hiding you from the your attackers.\n");
    lessp(25);
    aggr = all_inventory(env(ME));
    while(i <sizeof(aggr)) 
	peace(aggr[i++]);  
    ME->stop_fight();
    return 1;
}

peace(ob) {  
    if(ob->query_attack())
	ob->query_attack()->stop_fight();
    ob->stop_fight();
    ob->stop_fight();
}

gateway(){
    if(TAT->glvl()<2) return 0;
    if(TAT->query_medit()) return;
    /*
      if(gflag>time()) {
	write("The Ancients just helped you...wait a little while.\n");
	return 1;
      }
    */
    if(SP<60&&LVL<29) {
	write("You do not have the mental strength to do that.\n");
	return 1;
    }
    if(env(ME)->realm() == "NT") {
	write("Something keeps the Ancients from hearing your call.\n");
	return 1;
    }
    if(env(ME)->query_short() != "Village church" &&
      env(ME)->query_short() != "Riskadh's Medetation Room" &&
      env(ME)->query_short() != "The Mighty Oracle" &&
      env(ME)->query_short() != "lockers" &&
      env(ME)->query_short() != "The Shop [w,e,d]")
	lessp(15);
    else
	lessp(60);
    gflag = time()+till_again;
    TAT->SAY(RN+" slowly disappears from your view.\n");
    move_object(this_player(),"/players/mouzar/closed/guild/gateway.c");
    write("The Ancients hear your call and take you to the gateway.\n");
    return 1;
}

check(str){
    object test, WC, AC, lvl, good;
    int qwc, qac, hmax, hcur, smax, scur, PH, PS;
    if(TAT->glvl()<3) return 0;
    if (!str) return;
    if(SP<15&&LVL<30){
	write("You do not have the mental strenght to do this.\n");
	return 1;
    }
    if(!pse) {
	write("Asuras tells you:  "+CAP(str)+" is not here.\n");
	return 1;
    }else{
	test = pse;
	qwc = test->query_wc();
	qac = test->query_ac();
	hcur = test->query_hp();
	hmax = test->query_mhp();
	scur = test->query_sp();
	smax = test->query_msp();
	PH = 100*hcur/hmax;
	if(smax) PS = 100*scur/smax;
	if(qwc <= 3)
	    WC = "Very bad.";
	if(qwc >= 4 && qwc <= 5)  
	    WC = "Poor.";
	if(qwc >= 6 && qwc <= 10)
	    WC = "Decent.";
	if(qwc >= 11 && qwc <= 15)
	    WC = "Good.";
	if(qwc >= 16 && qwc <= 18)
	    WC = "Very good.";
	if(qwc >= 19 && qwc <= 24)
	    WC = "Very very good.";
	if(qwc >= 25 && qwc <= 29)
	    WC = "Excellent.";
	if(qwc >= 30 && qwc <= 34)
	    WC = "Very Excellent.";
	if(qwc >= 35)
	    WC = "Beyond Excellence.";
	if(qac<=2) 
	    AC = "Very bad.";
	if(qac >= 3 && qac <= 6)  
	    AC = "Poor.";
	if(qac >= 7 && qac <= 8)
	    AC = "Decent.";
	if(qac >= 9 && qac <= 10)
	    AC = "Good.";
	if(qac >= 11 && qac <= 12)
	    AC = "Very good.";
	if(qac >= 13 && qac <= 19)
	    AC = "Very very good.";
	if(qac >= 20 && qac <= 29)
	    AC = "Excellent.";
	if(qac >= 30 && qac <= 39)
	    AC = "Very Excellent.";
	if(qac >= 40)
	    AC = "Beyond Excellence.";
	lvl = test->query_level();
	if(lvl < LVL)
	    good = "Is lower than your's.";
	if(lvl > LVL)
	    good = "Is greater than your's.";
	write("Asuras tells you:  "+CAP(str)+"'s stats are\n"+
	  "\t\t   Align:  "+test->query_alignment()+"\n"+
	  "\t\t   HP:     "+PH+"%\n"+
	  "\t\t   SP:     "+PS+"%\n"+ 
	  "\t\t   WC      "+WC+"\n"+
	  "\t\t   AC:     "+AC+"\n"+ 
	  "\n");
	lessp(15);
	return 1;
    }
    return 1;
}

send(str) { 
    string stuff,plr;
    object stuff1,plr1;
    if( TAT->glvl()<6) return 0;
    if((!str) || ((sscanf(str,"%s %s",stuff,plr) !=2))) {   
	write("You fail to send "+stuff+" to "+plr+".\n");
	return 1;
    }
    if(SP<20&&LVL<30) {
	write("You do not have the mental strength to do that.\n");
	return 1;
    }
    if(!present(stuff,ME) || !find_living(plr)) {   
	write(stuff+" or "+plr+" not present.\n");
	return 1;
    }
    if(present(stuff,ME)->query_auto_load() || present(stuff,ME)->query_drop()){
	write("You can't send that.");
	return 1;
    }
    if(present(stuff,ME)->query_retain()) {
	write("You have that marked as retained so it can't be sent.\n");
	return 1;
    }
    if(!call_other(find_living(plr), "add_weight",
	call_other(present(stuff,ME), "query_weight"))) {
	write("That person can't carry that much.\n");
	return;
    }
    if(!present("riskadh-tattoo",find_living(plr))) {
	write("That person does not have a tattoo.\n");
	return 1;
    }
    plr1=find_living(plr);
    stuff1=present(stuff,ME);
    move_object(stuff1,plr1);
    if(plr1->ANSI == 1)
	tell_object(plr1,BLUE+""+stuff+" suddenly appears in your inventory. It was sent by "+NWHITE+""+RN+".\n");
    else
	tell_object(plr1,stuff+" suddenly appears in your inventory. It was sent by "+RN+"'.\n");
    write( "Ok.\n" );
    lessp(20);  return 1;
}

health_monitor2() {
    int hp,maxhp,sp,maxsp,stuff,maxstuff,intox,maxintox;
    string color;
    stuff=ME->query_stuffed();
    intox=ME->query_intoxication();
    hp=ME->query_hp();
    sp=ME->query_sp();
    maxhp=ME->query_mhp();
    maxsp=ME->query_msp();
    maxstuff=ME->query_level()*8;
    maxintox=ME->qeury_level()+3;
    if(hp<20 && ME->ANSI == 1) 
	color=RED;
    if(hp>20 && ME->ANSI == 1)
	color=GREEN;
    if(ME->ANSI == 1)
	write(color);
    write("HP{"+hp+"|"+maxhp+"}   SP{"+sp+"|"+maxsp+"}");
    if(stuff)
	write(" Stuff{"+stuff+"|"+maxstuff+"}");
    if(intox)
	write(" Inotx{"+intox+"|"+maxintox+"}");
    write("\n");
    if(ME->ANSI == 1)
	write(END);
    return 1;
}
guild_title() {
    if(TAT->glvl() == 1) {
	ME->set_title("the Student Riskadh.");
	write("Your title now reads 'the Student Riskadh'.\n");
	return 1;
    }
    if(TAT->glvl() == 2) {
	ME->set_title("the Novice Riskadh.");
	write("Your title now reads 'the Novice Riskadh'.\n");
	return 1;
    }
    if(TAT->glvl() == 3) {
	ME->set_title("the Initiate Riskadh.");
	write("Your title now reads 'the Initiate Riskadh'.\n");
	return 1;
    }
    if(TAT->glvl() == 4) {
	ME->set_title("the Master of Body.");
	write("Your title now reads 'the Master of Body'.\n");
	return 1;
    }
    if(TAT->glvl() == 5) {
	ME->set_title("the Master of Mind.");
	write("Your title now reads 'the Master of Mind'.\n");
	return 1;
    }
    if(TAT->glvl() == 6) {
	ME->set_title("the Master of Weaponry.");
	write("Your title now reads 'the Master of Weaponry'.\n");
	return 1;
    }
    if(TAT->glvl() == 7) {
	ME->set_title("the Master of Elements.");
	write("Your title now reads 'the Master of Elements'.\n");
	return 1;
    }
    if(TAT->glvl() == 8) {
	ME->set_title("the Master of Seasons.");
	write("Your title now reads 'the Master of Seasons'.\n");
	return 1;
    }
    if(TAT->glvl() == 9) {
	ME->set_title("the Riskadh.");
	write("Your title now reads 'the Riskadh'.\n");
	return 1;
    }
    if(TAT->glvl() == 10) {
	ME->set_title("the Master Riskadh.");
	write("Your title now reads 'the Master Riskadh'.\n");
	return 1;
    }
    if(TAT->glvl() == 11) {
	ME->set_title("the High Riskadh.");
	write("Your title new reads 'the High Riskadh'.\n");
	return 1;
    }
    if(TAT->glvl() == 12) {
	ME->set_title("the Grand Riskadh.");
	write("Your title now reads 'the Grand Riskadh'.\n");
	return 1;
    }
    if(TAT->glvl() == 500) {
	ME->set_title("the Elder Riskadh.");
	write("Your title has been set Master!\n");
	return 1;
    }            

}
kick(str) {
    object hur;
    if(str) hur = str;
    if(!str && ME->query_attack()) {
	str = ME->query_attack();
	hur = ME->query_attack()->query_name();
    }
    if(!str) return;
    if(!hur) return;
    if(str==rn) {
	write("You idiot!  Why would you want to do that?!!\n");
	return 1;
    }
    if(!pse) {
	write("That is not here!\n");
	return 1;
    }
    if(!pse->PK && pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  This player doesn't have PK set.\n");
	return 1;
    }
    if(pse->query_npc() == 0 && TAT->query_PK_flag() == 1) {
	write("You must wait a bit.\n");
	return 1;
    }
    if(!ME->PK && pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  You dont have your pk set wimp.\n");
	return 1;
    }
    if(SP<20&&LVL<30) {
	write("You do not have the mental strength to do that.\n");
	return 1;
    }
    if(!living(pse)) {
	write("That is not alive!\n");
	return 1;
    }
    if(peace_room()) return 1;
    if(!DELAY()) return 0;
    if(!pse->query_npc()) {
	write_file("/players/mouzar/closed/guild/log/rkick",RN+" rkicked "+hur+" at "+ctime(time())+".\n");
	TAT->set_PK_flag(1);
	call_out("PK_can_again",2);
    }
    write("You jump up smash "+CAP(hur)+"'s face with a quick kick.\n");
    lessp(20);
    TAT->SAY(RN+" leaps in the air and smashes "+CAP(hur)+"'s face with a powerful kick.\n");
    pse->hit_player(20);
    return 1;
}

throw_sand(str){
    object target;
    object hur;
    if(str) hur = str;
    if(!str && ME->query_attack()) {
	str = ME->query_attack();
	hur = ME->query_attack()->query_name();
    }
    if(!str) return;
    if(!hur) return;
    if( TAT->glvl()<6) return 0;  
    if(str==rn) {
	write("You idiot!  Why would you want to do that?!!\n");
	return 1;
    }
    if(!pse) {
	write("That is not here!\n");
	return 1;
    }
    if(!pse->query_npc() == 0 && TAT->query_PK_flag() == 1) {
	write("You must wait a bit.\n");
	return 1;
    }
    if(!pse->PK && pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  This player doesn't have PK set.\n");
	return 1;
    }
    if(!ME->PK && pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  You dont have your pk set wimp.\n");
	return 1;
    }
    if(SP<30&&LVL<30) {
	write("You do not have the mental strength to do that.\n");
	return 1;
    }
    if(!living(pse)) {
	write("That is not alive!\n");
	return 1;
    }
    if(peace_room()) return 1;
    if(!DELAY()) return 0;
    if(!pse->query_npc()) {
	TAT->set_PK_flag(1);
	call_out("PK_can_again",2);
    }
    target = pse;
    write("You throw some sand into "+hur+"'s eyes.\n");
    TAT->SAY(RN+" throws something into "+CAP(hur)+"'s eyes blinding it.\n"+
      RN+" quickly steps forward to take advantage of "+CAP(hur)+"!\n");
    if(!target) return 1;
    if(!pse->query_npc())
	target->reduce_hit_point(random(ME->query_wc()+random(2)));
    else
	target->reduce_hit_point(random(ME->query_wc()+random(10)));
    TAT->SAY(RN+" lands a nice solid blow to "+CAP(hur)+"!\n");
    write("You step up and take advantage of "+CAP(hur)+" while he can't see!\n");
    write("You land a nice solid blow to "+CAP(hur)+"!\n");   
    if(!target) return 1;
    if(!pse->query_npc())
	target->reduce_hit_point(random(ME->query_wc()+random(2)));
    else
	target->reduce_hit_point(random(ME->query_wc()+random(10)));
    write("You weapon slams into "+hur+" with deadly force!\n");
    TAT->SAY(RN+"'s weapon slams into "+hur+" with deadly force!\n");
    if(!target) return 1;
    if(!pse->query_npc())
	target->hit_player(random(ME->query_wc()+random(2)));
    else
	target->hit_player(random(ME->query_wc()+random(10)));
    write("Your last free attack strikes "+hur+" with amazing force!\n");
    TAT->SAY(RN+" strikes "+hur+" with amazing force!\n");
    if(!target) return 1;
    write(hur+" SCREAMS in anger as it finally gets the sand out of it's eyes!\n");
    TAT->SAY(hur+" SCREAMS in anger as it finally regains it's eye sight!\n");
    lessp(30);
    return 1;
}
offer() { 
    if(!present("corpse", env(ME))&&!present("corpse",ME)){ 
	write("There is no corpse in this room.\n"); 
	return 1; 
    }
    if(present("corpse", env(ME)) && present("corpse", env(ME))->id("link dead corpse")){
	write("You are not allowed to drain the link dead corpses.\n");
	return 1;
    }
    if(present("corpse",env(ME))){
	ME->heal_self(present("corpse", env(ME))->query_level()*2);
	destruct(present("corpse", env(ME)));
	write("You show respect to the corpse by offering it to the ancients.\n");
	TAT->SAY(RN+" offers the corpse to the ancients.\n");
	return 1;
    }
    if(present("corpse",ME)){
	ME->heal_self(present("corpse", ME)->query_level()*2);
	destruct(present("corpse", ME));
	write("You show respect to the corpse by offering it to the ancients.\n");
	TAT->SAY(RN+" offers the corpse to the ancients.\n");
	return 1;
    }
}
hrt(str) {
    int x;
    object us;
    if(!str) return;
    if( TAT->glvl()<=199) {write("You are not high enough for this channel!\n"); return 1;}
    if(muf==1) {
	write("You may not do any tells to the order while you are muffled.\n");
	return 1;
    }
    us=users();
    for(x=0;x<sizeof(us);x++) {
	if(present("riskadh-tattoo",us[x])
	  &&present("riskadh-tattoo",us[x])->query_muf()==0
	  &&present("riskadh-tattoo",us[x])->query_marks()>=200) {
	    if(us[x]->ANSI == 1)
		tell_object(us[x],implode(explode(sprintf("%-=70s",GREEN+""+RN+""+PURPLE+"**}-- "+YELLOW+""+str+"\n"+END),"\n"),"\n    ")+"\n");
	    else
		tell_object(us[x],implode(explode(sprintf("%-=70s",RN+"**}-- "+str),"\n"),"\n    ")+"\n");
	}
    }
    return 1;
}

hre(str) {
    int x;
    object us;
    if(!str) return;
    if( TAT->glvl()<=199) {write("You are not high enough for this channel!\n"); return 1;}
    if(muf==1) {
	write("You may not do any emotes to the order while you are muffled.\n");
	return 1;
    }
    us=users();
    for(x=0;x<sizeof(us);x++) {
	if(present("riskadh-tattoo",us[x])
	  &&present("riskadh-tattoo",us[x])->qeruy_muf()==0
	  &&present("riskadh-tattoo",us[x])->query_marks()>=200) {
	    if(us[x]->ANSI == 1)
		tell_object(us[x],implode(explode(sprintf("%-=70s",PURPLE+"**}-- "+GREEN+""+RN+" "+str),"\n"),"\n    ")+"\n");
	    else
		tell_object(us[x],implode(explode(sprintf("%-=70s","**}-- "+RN+" "+str),"\n"),"\n    ")+"\n");
	}
    }
    return 1;
}
cc(str) {
    int x;
    object us;
    if(!str) return;
    if( TAT->glvl()<=10) {write("You are not high enough for this channel!\n"); return 1;}
    if(muf==1) {
	write("You may not do any tells to the order while you are muffled.\n");
	return 1;
    }
    us=users();
    for(x=0;x<sizeof(us);x++) {
	if(present("riskadh-tattoo",us[x])
	  &&present("riskadh-tattoo",us[x])->query_muf()==0
	  &&present("riskadh-tattoo",us[x])->query_marks()>=11) {
	    if(us[x]->ANSI == 1)
		tell_object(us[x],implode(explode(sprintf("%-=70s",RED+"*"+NWHITE+""+RN+""+RED+"*: "+LIGHT_BLUE+""+str+""+END),"\n"),"\n    ")+"\n");
	    else
		tell_object(us[x],implode(explode(sprintf("%-=70s","*"+RN+"*: "+str),"\n"),"\n    ")+"\n");
	}
    }
    return 1;
}

ce(str) {
    int x;
    object us;
    if(!str) return;
    if( TAT->glvl()<=10) {write("You are not high enough for this channel!\n"); return 1;}
    if(muf==1) {
	write("You may not do any emotes to the order while you are muffled.\n");
	return 1;
    }
    us=users();
    for(x=0;x<sizeof(us);x++) {
	if(present("riskadh-tattoo",us[x])
	  &&present("riskadh-tattoo",us[x])->query_muf()==0
	  &&present("riskadh-tattoo",us[x])->query_marks()>=11) {
	    if(us[x]->ANSI == 1)
		tell_object(us[x],implode(explode(sprintf("%-=70s",RED+"<*>: "+NWHITE+""+RN+""+LIGHT_BLUE+" "+str+""+END),"\n"),"\n    ")+"\n");
	    else
		tell_object(us[x],implode(explode(sprintf("%-=70s","<*>: "+RN+" "+str),"\n"),"\n    ")+"\n");
	}
    }
    return 1;
}

remote_sell(item) {
    object ob, where;
    if(!item) return 0;
    if(!TAT->query_CLK()) {
	write("You dont have a Cloaker.\n");
	return 1;
    }
    if(SP<20&&LVL<30) {
	write("You do not have the mental strength to do that.\n");
	return 1;
    }
    if(item == "everything") {
	object next;
	ob = first_inventory(ME);
	while(ob) {
	    next = next_inventory(ob);
	    if(!ob->drop() && ob->query_value()) {
		write(ob->short() + ":\t");
		do_sell(ob);
	    }
	    ob = next;
	}
	lessp(20);
	return 1;
    }
    ob = present(item, ME);
    if(sscanf(item,"all from %s",where)==1&&present(where,ME)) {
	object *list;
	int x;
	list=({});
	ob=first_inventory(present(where,ME));
	while(ob) {
	    list+=({ob});
	    ob=next_inventory(ob);
	}
	for(x=0;x<sizeof(list);x++) {
	    present(where,ME)->add_weight(-list[x]->query_weight());
	    do_sell(list[x]);
	}
	lessp(20);
	return 1;
    }
    if(!ob)
	ob = present(item, this_object());
    if(!ob) {
	write("The Cloaker says:  "+item+" here.\n");
	return 1;
    }
    do_sell(ob);
    lessp(20);
    return 1;
}

do_sell(ob) {
    int p,g,e,s,c;
    string all_vals;
    int value, do_destroy;
    all_vals=ob->query_all_values();
    if(all_vals)
	sscanf(all_vals,"%d#%d#%d#%d#%d",c,s,e,g,p);
    value = ob->query_value();
    if(!value&&!c&&!s&&!e&&!g&&!p) {
	write("Your Cloaker says:  "+ob->short()+" has no value.\n");
	return 1;
    }
    if(env(ob) == ME) {
	int weight;
	if(call_other(ob, "drop", 0)|| ob->query_retain() == 1) {
	    write("Your Cloaker says:  I can't take it from you!\n");
	    return 1;
	}
	weight = call_other(ob, "query_weight", 0);
	call_other(ME, "add_weight", - weight);
    }
    write("Your Cloaker takes "+ob->short()+" from you and flys away.\n");
    TAT->SAY(RN+"'s Cloaker takes something from it's master and flies off.\n");
    if(value>3000||c>200000||s>40000||e>4000||g>3000||p>400) {
	write("Your Cloaker says:  Sorry the shop didn't give me the full value.\n");
	TAT->SAY(RN+"'s Cloaker returns and gives it's master some money.\n");
	if(value>3000) value=3000;
	if(c>200000) c=200000;
	if(s>40000) s=40000;
	if(e>4000) e=4000;
	if(g>3000) g=3000;
	if(p>400) p=400;
    }  
    if(value>0) {
	write("Your Cloaker gives you:\n\t"+value+" gold coins.\n");
    } else {
	write("Your Cloaker gives you:\n");
	if(p>0) write("\t"+p+" platinum coins\n");
	if(g>0) write("\t"+g+" gold coins\n");
	if(e>0) write("\t"+e+" electrum coins\n");
	if(s>0) write("\t"+s+" silver coins\n");
	if(c>0) write("\t"+c+" copper coins\n");
    }  
    if(value>0) { g=value; value=0; }
    if(p>0) ME->add_platinum(p);
    if(g>0) ME->add_gold(g);
    if(e>0) ME->add_electrum(e);
    if(s>0) ME->add_silver(s);
    if(c>0) ME->add_copper(c);
    STORE->store(ob);
    return 1;
}

presure(amt) {
    if(!intp(amt)) sscanf(amt,"%d",amt);
    TAT->set_pamt(amt);
    if(TAT->pamt() >  TAT->glvl()*10) TAT->set_pamt(TAT->glvl()*10);
    if(TAT->pamt() < 1) TAT->set_pamt(1);
    write("You have set your amount of pressure at "+TAT->pamt()+"\n");
    return 1;
}
presure_point(str) {
    object hur;
    if(str) hur = str;
    if(SP<TAT->pamt()&&LVL<30) {
	write("You do not have the mental strenth to do that.\n");
	return 1;
    }
    if(!str && ME->query_attack()) {
	str = ME->query_attack();
	hur = ME->query_attack()->query_name();
    }
    if(!str) return;
    if(!hur) return;
    if(str==rn) {
	write("You idiot!  Why would you want to do that?!!\n");
	return 1;
    }
    if(!pse) {
	write("That is not here!\n");
	return 1;
    }
    if(!living(pse)) {
	write("That is not alive!\n");
	return 1;
    }
    if(!pse->PK && pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  This player doesn't have PK set.\n");
	return 1;
    }
    if(pse->query_npc() == 0 && TAT->query_PK_flag() == 1) {
	write("You must wait a bit.\n");
	return 1;
    }
    if(!ME->PK && pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  You dont have your pk set wimp.\n");
	return 1;
    }
    if(peace_room()) return 1;
    if(!DELAY()) return 0;
    if(!pse->query_npc()) {
	write_file("/players/mouzar/closed/guild/log/PK_pressure",RN+" threw sand at "+hur+" at "+ctime(time())+".\n");
	TAT->set_PK_flag(1);
	call_out("PK_can_again",2);
    }
    write_file("/players/mouzar/closed/guild/log/pressure",RN+" applied "+pamt+" pressure to "+hur+"\n");
    write("You extend your finger and poke "+CAP(hur)+" in the neck.\n");
    lessp(TAT->pamt());
    TAT->SAY(RN+" pokes "+CAP(hur)+" in the neck with an extended finger.\n");
    pse->hit_player(TAT->pamt());
    return 1;
}
inv(){
    string tmp,trash,oldtab;
    int x, max_weight;
    object who,ob,max;
    ob=first_inventory(ME);
    if(!ob){
	write("You are carring nothing.\n");
	return 1;
    }
    x=0;
    while(ob){
	x=x+1;
	if(ob->query_retain()){
	    if(ME->ANSI ==  1)
		write(PURPLE+"#"+END);
	    else
		write("#");
	}
	if(ob->short())
	    write(ob->short()+"\n");
	else 
	if(ob->query_name())
	    write(ob->query_name()+"\n");
	else 
	if(ob->query_real_name())
	    write(ob->query_real_name()+"\n");
	max_weight = max_weight + ob->query_weight();
	ob=next_inventory(ob);
    }
    if(ME->ANSI == 1)
	write(PURPLE+"You are carrying "+100*max_weight/((LVL+(ME->query_str()/2)/4)+5)+"% of max.\n"+END);
    else
	write("You are carrying "+100*max_weight/(LVL+ME->query_str()/4)+"% of max.\n");
    return 1;
}

sharpen(str) {
    object nshort, blah, b;
    int new;
    if(!str) return;
    if( TAT->glvl()<7) return;
    if(!present(str,ME)) {
	write("You can't sharpen what isn't here.\n");
	return 1;
    }
    if(present(str,ME)->weapon_class() >= 18) {
	write("You can't get it that sharp.\n");
	return 1;
    }
    if(present(str,ME)->query_retain()) {
	write("You must unretain it first.\n");
	return 1;
    }
    if(sscanf(present(str,ME)->short(),"%s(wielded)", blah) == 1) {
	write("You must unwield it first.\n");
	return 1;
    }
    if(!present(str,ME)->weapon_class()) {
	write("You can't sharpen that!\n");
	return 1;
    }
    if(SP<80&&LVL<30) {
	write("You do not have the mental strenght to do that.\n");
	return 1;
    }
    write("You sharpen your "+str+" some.\n");
    TAT->SAY(JN+" sharpens a "+str+".\n");
    lessp(80);
    new = present(str,ME)->weapon_class() + 1;
    write_file("/players/mouzar/closed/guild/log/sharpen",RN+" sharpened "+str+" to "+new+"\n");
    if(!sscanf(present(str,ME)->short(),"%s(Sharpened)", b) == 1) {
	nshort = present(str,ME)->short() +" (Sharpened)";
	present(str,ME)->set_short(nshort);
    }
    present(str,ME)->set_class(new);
    return 1;
}
vr(str) {
    int x;
    object us, emote;
    if(!str) return;
    if(TAT->query_guild_channel()==0) {
	write("You may not do any tells to the two guilds while you are muffled.\n");
	return 1;
    }
    us=users();
    if(sscanf(str,":%s", emote) == 1) {
	for(x=0;x<sizeof(us);x++) {
	    if(present("riskadh-tattoo",us[x])||present("fangs-SCOOTER",us[x])) {
		if(present("guild_object",us[x])->query_guild_channel() == 1
		){
		    if(us[x]->ANSI == 1)
			tell_object(us[x],implode(explode(sprintf("%-=70s",YELLOW+"<{ "+LIGHT_BLUE+""+RN+" "+NWHITE+""+emote+""+END),"\n"),"\n    ")+"\n");
		    else
			tell_object(us[x],implode(explode(sprintf("%-=70s","<{ "+RN+" "+emote),"\n"),"\n    ")+"\n");
		}
	    }
	}
	if(random(10) == 1) no_guilder();
	return 1;
    }
    for(x=0;x<sizeof(us);x++) {
	if(present("riskadh-tattoo",us[x])||present("fangs-SCOOTER",us[x])) {
	    if(present("guild_object",us[x])->query_guild_channel()==1){
		if(us[x]->ANSI == 1)
		    tell_object(us[x],implode(explode(sprintf("%-=70s",YELLOW+"<{ "+LIGHT_BLUE+""+RN+""+YELLOW+" }>: "+NWHITE+""+str+""+END),"\n"),"\n    ")+"\n");
		else
		    tell_object(us[x],implode(explode(sprintf("%-=70s","<{ "+RN+" }>: "+str),"\n"),"\n    ")+"\n");
	    }
	}
    }
    if(random(10) == 1) no_guilder();
    return 1;
}
vrw() {
    int x;
    object us, color;
    us=users();
    write("Name           Idle    G-Rank   Location\n");
    write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for(x=0;x<sizeof(us);x++) {
	if(present("fangs-SCOOTER",us[x])||present("riskadh-tattoo",us[x])) {
	    if(present("fangs-SCOOTER",us[x]) && ME->ANSI == 1)
		color=RED;
	    if(present("riskadh-tattoo",us[x]) && ME->ANSI == 1)
		color=BLUE;
	    if(ME->ANSI == 1)
		write(color);
	    if(us[x]->query_invis()<=LVL) {
		write(capitalize(us[x]->query_real_name()));
		if(strlen(us[x]->query_real_name())<8) write("\t\t"); else write("\t");
		write("\b\b"+query_idle(us[x])/60+" min\t"); 
		if(present("risakdh-tattoo",us[x]))
		    write(present("risakdh-tattoo",us[x])->query_marks());
		else
		    write(us[x]->query_guild_rank()+"\t");
		write(env(us[x])->short());
		if(present("guild_object",us[x])->query_guild_channel()==0)
		    write(" {Muffled}");
		if(ME->ANSI == 1)
		    write(END);
		write("\n");
	    }
	}
    }
    return 1;
}
no_guilder() {  
    object ob;
    int i;
    ob = first_inventory(env(ME));
    while(ob) {
	if(!present("guild_object",ob) && !ME->query_invis() && !ob->query_invis())
	    tell_object(ob,"You hear a faint whispering in the background.\n");
	ob = next_inventory(ob);
    }
    return 1;
}
nullspell() {
    write("You are not allowed to do that in this Order.\n");
    return 1;
}
peace_room() {
    if(query_realm("NK",env(ME))) {
	write("The Ancients prevent you from doing that here.\n");
	return 1;
    }
    return;
}
PK_can_again() {
    TAT->set_PK_flag(0);
    return 1;
}

disarm(str) {
    object hur, dex;
    if(str) hur = str;
    if(!str && ME->query_attack()) {
	str = ME->query_attack();
	hur = ME->query_attack()->query_name();
    }
    if(!str) return;
    if(!hur) return;
    if(str==rn) {
	write("Why you want to disarm yourself you putz?\n");
	return 1;
    }
    if(!pse) {
	write("That is not here!\n");
	return 1;
    }
    if(pse->query_npc() == 0 && TAT->query_PK_flag() == 1) {
	write("You must wait for an opening.\n");
	return 1;
    }
    if(!pse->PK && pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  This player doesn't have PK set.\n");
	return 1;
    }
    if(!ME->PK &&pse->query_npc() == 0) {
	write("Grand Master Riskadh tells you:  You dont have your pk set wimp.\n");
	return 1;
    }
    if(SP<20&&LVL<30) {
	write("You do not have the mental strength to do that.\n");
	return 1;
    }
    if(!living(pse)) {
	write("That is not alive!\n");
	return 1;
    }
    dex = ME->query_dex() + 100;
    if(random(dex) <= pse->query_dex()) {
	write("You fail to disarm "+CAP(hur)+".\n");
	TAT->SAY(JN+" tried to disarm "+CAP(hur)+".\n");
	lessp(10);
	return 1;
    }
    if(peace_room()) return 1;
    if(!DELAY()) return 0;
    if(!pse->query_npc()) {
	TAT->set_PK_flag(1);
	call_out("PK_can_again",2);
    }
    write_file("/players/mouzar/closed/guild/log/disarm",RN+" disarmed "+hur+" at "+ctime(time())+".\n");
    if(ME->ANSI == 1)
	write(LIGHT_BLUE+"With a flick of your weapon you disarm"+CAP(hur)+".\n");
    else
	write("With a flick of your weapon you disarm "+CAP(hur)+".\n");
    lessp(20);
    TAT->SAY(JN+" moves his weapon with blinding speed and disarms "+CAP(hur)+"!\n");
    pse->stop_wielding();
    pse->attack_object(ME);
    return 1;
}
coins() {
    if(ME->ANSI == 1) {
	write(YELLOW+"Platinum: "+LIGHT_BLUE+""+ME->query_platinum()+""+YELLOW+" Gold: "+LIGHT_BLUE+""+ME->query_gold()); 
	write(YELLOW+" Electrum: "+LIGHT_BLUE+""+ME->query_electrum()+""+YELLOW+" Silver: "+LIGHT_BLUE+""+ME->query_silver()); 
	write(YELLOW+" Copper: "+LIGHT_BLUE+""+ME->query_copper()+"\n"+END);
    } else {
	write("Platinum: "+ME->query_platinum()+" Gold: "+ME->query_gold()+" Electrum: "+ME->query_electrum()+" Silver: "+ME->query_silver()+" Copper: "+ME->query_copper()+"\n");
    }
    return 1;
}
quit() {
    if(TAT->query_medit()) return;
    if(LVL<28&&ME->query_invis()) VIS->cmd_vis();
    if(ME->query_invis() == 0 && LVL < 1000) {
	sayit(RN+" has left us.\n");
	say(RN+" says a prayer and is taken up to the gods.\n");
    }
    return 0;
}

DELAY() {
    if(time() - (present("riskadh-tattoo",ME)->query_delay()) < 2) {
	write("You may only do one spell per round.\n");
	return 0;
    } else {
	present("riskadh-tattoo",ME)->set_delay(time());
	return 1;
    }
    return 1;
}
