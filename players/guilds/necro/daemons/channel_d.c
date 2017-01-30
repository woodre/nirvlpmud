/* channel_d.c  -  Channel daemon  */
/* 11/30/2006 - Rumplemintz - strict_types */

#pragma combine_strings

#include <ansi.h>
#define BAR OFF+"        <----------------------------------------------------------->\n"+OFF

string *listeners, *members, *history;
int num_listeners, num_members;

void reset(status arg){
    if(arg)
	return;
    num_listeners = 0;
    listeners = ({});
    members = ({ });
    history = ({ });
}

string cutstring(string str,int i){
    str = str +"                                ";
    str = str[0..i-1];
    return str;
}

void addhistory(string str){
    if(sizeof(history) == 20){
	history -=({ history[0] });
    }
    str = str[18..strlen(str)];
    str = "       <"+HIR+"n"+OFF+">"+str;
    history += ({ str, });
}
void resetchannel(){
    int i,n;
    object *ppl;
    ppl = users();
    num_listeners = num_members = 0;
    listeners = members = ({});

    /* modified by illarion - 2 dec 2004
     * an error was preventing players from quitting
     */

    for (i=0,n=sizeof(ppl); i<n; i++){
        if(present("necro_ob", ppl[i])){
	    members += ({ ppl[i]->query_real_name(), });
            if(!present("necro_ob", ppl[i])->query_muffled()){
		listeners+=({ ppl[i]->query_real_name() });
		num_listeners++;
	    }
	    num_members++;
	}
    }
}

int force_tell_guild(string str, string arg){
    int i;
    object necro;
    for(i=0;i<sizeof(members);i++){
	necro = find_player(members[i]);
	if(necro)
	    tell_object(necro,str);
    }
    if(!arg)
	addhistory(str);
    return 1;
}

varargs int tell_guild(string str, string arg){
    int i;
    object necro;
    for(i=0;i<sizeof(listeners);i++){
	necro = find_player(listeners[i]);
	if(necro)
	    tell_object(necro,str);
    }
    if(!arg)
	addhistory(str);
    return 1;
}

void create_say(object necro, string str){
    string msg, verb;
#ifdef __LDMUD__
    switch(str[<1]){
#else
	switch(str[strlen(str)-1]){
#endif
	case '?': verb = "asks"; break;
	case '!': verb = "exlaims"; break;
	default: verb = "says"; break;
	}
	msg = "<"+HIR+"NeCRo"+OFF+"> "+necro->query_name()+" "+verb+", \""+NORM+str+OFF+"\"\n"+NORM;
	if(((string)necro->query_real_name() == "wocket" ||
	    (string)necro->query_real_name() == "") &&
	  necro->query_invis() > 20){
#ifdef __LDMUD__
	    switch(str[<1]){
#else
		switch(str[strlen(str)-1]){
#endif
		case '?': verb = "ask"; break;
		case '!': verb = "exclaim"; break;
		default: verb = "say"; break;
		}
		msg = "<"+HIR+"NeCRo"+OFF+"> "+BOLD+"The Spirits "+OFF+verb+", \""+NORM+str+OFF+"\"\n"+NORM;
	    }
            tell_guild(msg);
	}

	int create_emote(object necro,string str){
	    string em, arg, file, msg;
#ifdef __LDMUD__
	    str = str[1..];
#else
	    str = str[1..-1];
#endif
	    if(sscanf(str, "%s %s", em, arg) != 2)
		em = str;
	    em = implode(explode(em, "."), "");
	    if(file_size(file="/bin/soul/_"+em+".c") > 0)
		return (int)file->guildcast("necromancer", arg);
	    msg = "<"+HIR+"NeCRo"+OFF+"> "+necro->query_name()+" "+str+"\n"+NORM;
	    if(((string)necro->query_real_name() == "wocket" ||
		(string)necro->query_real_name() == "") &&
	      necro->query_invis() > 20)
		msg = "<"+HIR+"NeCRo"+OFF+"> "+BOLD+"The Spirits "+OFF+str+"\n"+NORM;
	    tell_guild(msg);
  return 1; /* Rumplemintz */
	}

	void create_echo(object necro,string str){
	    string msg;
	    int i;
	    i = strlen(str)-1;
	    str = str[1..i];
	    msg = "<"+HIR+"NeCRo"+OFF+"> "+str+" ("+OFF+necro->query_name()+OFF+")\n"+OFF;
	    if(((string)necro->query_real_name() == "wocket" ||
		(string)necro->query_real_name() == "") &&
	      necro->query_invis() > 49)
		msg = "<"+HIR+"NeCRo"+OFF+"> "+str+"\n"+OFF;
	    tell_guild(msg);
	}

	void create_think(object necro,string str){
	    string msg;
	    int i;
	    i = strlen(str)-1;
	    str = str[1..i];
	    msg = "<"+HIR+"NeCRo"+OFF+"> "+necro->query_name()+" . o O ("+NORM+str+OFF+")\n"+NORM;
	    if(((string)necro->query_real_name() == "wocket" ||
		(string)necro->query_real_name() == "") &&
	      necro->query_invis() > 20)
		msg = "<"+HIR+"NeCRo"+OFF+"> "+BOLD+"The Spirits "+OFF+" . o O ("+NORM+str+OFF+")\n"+NORM;
	    tell_guild(msg);
	}

	void guildwho(){
	    object mage,guildob;
	    int i, n, seenmembers;
	    int hp_percent;
	    string msg, name;
	    msg = "\t<"+HIR+"Necromantic Guild Who"+OFF+
	    ">------------------------------------->\n";
	    msg += BOLD+BLK+
	    "       Name         Level  Gender   Line    Hp    Sp       Oppt\n"+NORM;
	    members = sort_array(members,"greater_fun",this_object());
	    seenmembers = 0;
	    for(i=0,n=sizeof(members);i<n;i++){
		mage = find_player(members[i]);
		if(mage){
		    guildob = present("necro_ob", mage);
		    if(!guildob){
			members -= ({ mage });
			mage = 0;
		    }
		}
		if(mage && mage->query_interactive() &&
		  ( (string)mage->query_real_name() != "wocket") ){
		    if(mage->query_invis() < this_player()->query_level()){ 
			seenmembers++;
			msg += " ";
			if(in_editor(mage) && (this_player()->query_level() > 20))
			    msg += HIM+"]"+OFF;
			else
			    msg += " ";
			if(mage->query_dead())
			    msg += HIY+"*"+OFF;
			else
			    msg += " ";
			if(mage->query_invis())
			    msg += HIB+"*"+OFF;
			else
			    msg += " ";
			if(environment(mage) && (string)environment(mage)->realm() == "NT")
			    msg += HIB+"X"+OFF;
			else
			    msg += " ";
			if(query_idle(mage) > 300)
			    msg += BOLD+"i"+OFF;
			else
			    msg += " ";
			if(mage->query_fight_area())
			    msg += HIR+"*"+OFF;
			else
			    msg += " ";
			name = cutstring((string)mage->query_name(), 12);
			if(mage->query_pl_k())
			    name = HIR+name+OFF;
			msg += name+" ";
			if(mage->query_level() > 20)
			    msg += BOLD+"wiz  "+OFF;
			else {
			    msg += cutstring((string)mage->query_level(), 2);
			    if(mage->query_extra_level())
				msg += "+" + cutstring((string)mage->query_extra_level(), 2);
			    else
				msg += "   ";
			}
			msg += "  ";
			msg += cutstring((string)mage->query_gender(), 6);
			msg += "   ";
			if(guildob->query_muffled())
			    msg += "deaf";
			else
			    msg += "on  ";
			msg += "   ";
			msg += cutstring( ""+(((int)mage->query_hp()*100)/((int)mage->query_mhp()*10))+"/10",6);
			msg += " ";
			msg += cutstring(""+(((int)mage->query_sp()*100)/((int)mage->query_mhp()*10))+"/10",6);
			msg += "   ";
			if(mage->query_attack())
			    msg += cutstring((string)mage->query_attack()->query_name(), 13)+" "+OFF;
			msg += "\n";
		    }
		} 
	    }
	    msg += BOLD+BLK+"       There are currently "+HIR+seenmembers+OFF+BOLD+BLK+
	    " members online\n"+OFF; 
	    msg += BAR;
	    write(msg+NORM);
	}

	void on_channel(){
	    string msg;
	    int i,a;
	    object mage,guildob;
	    msg = BOLD+BLK+"The members on the Necro Channel are "+OFF; 
	    for(i=0,a=sizeof(members);i<a;i++){
		mage = find_player(members[i]); 
		if(mage){
		    guildob = present("necro_ob",mage);
		    if(!guildob){ 
			members -= ({ mage });   /* 12/02/2006 - Rumplemintz */
			mage = 0;
		    }
		}
		if(mage){
		    if(mage->query_invis() < this_player()->query_level()){ 
			if(!guildob->query_muffled()){
			    if(i == 0) 
				msg += (string)mage->query_name();
			    else { 
				if(i == (a-1))
				    msg += " and "+mage->query_name();
				else
				    msg += ", "+mage->query_name();
			    }
			}
		    }
		} 
	    }
	    write(msg+".\n");
	}


	int viewhistory(){
	    int i,a;
	    string msg;
	    msg = "\n";
	    msg += "\t<"+HIR+"Necromantic Channel History"+OFF+
	    ">------------------------------->\n";
	    for(i=0,a=sizeof(history);i<a;i++){
		msg += history[i];
	    }
	    msg += BAR;
	    write(msg); 
	    return 1;
	}

	int greater_fun(string o,string t){
	    object one,two;
	    one = find_player(o);
	    two = find_player(t);
	    if(!one || !two)
		return 0;
	    if(one->query_level() == two->query_level()) 
		return one->query_extra_level() < two->query_extra_level();
	    else
		return one->query_level() < two->query_level();
	}

	string query_tag() {
	    return "<"+HIR+"NeCRo"+OFF+">";
	}

	string *query_listeners(){
	    int i;
	    i = sizeof(listeners);
	    return listeners[0..i];
	}
