/* 10/09/05 - Earwax - Added set_guild_file(PATH+"guildob.c") */
/* 10/09/05 - Earwax - Added guild_login() as well, and GI id */

/* THE BASE NECROMANCER OBJECT */

/* 11/29/06 - Rumplemintz - Converted to strict_types */

#include "./DEFS"

#define BAR  "\t<----------------------------------------------------------->\n"
#define SPACE "       "

int blood, eye, heart, skin, soul, spine, cdust, val, g_level, muffle;
string enter_msg, leave_msg;

static int icutmyself;

/* hidden */
int emdeaths, sacrifice, harvs, harvest;

int snow_idcheck(object obj){
    if(!obj)
	return 1;
    if((int)obj->armor_class() > 0){
	if((string)obj->query_type() == "armor"){
	    if(obj->query_weight() > 2)
		return 1;
	    else
		return 0;
	}
	if(obj->query_weight() > 1)
	    return 1;
    }
    return 0;
}

string cutstring(string str, int length){
    string str2;
    if(!length || length < 0)
	length = 20;
    str = str+"                                                                                  ";
    str2 = str[0..length];
    return str2;
}

int id(string str) {
    if(previous_object()) {
	if(!snow_idcheck(previous_object()))
	    return (str == "GI" || 
	      str == "necro_ob" || 
	      str == "skull" || 
	      str == "pouch" || 
	      str == "necro_pouch"
	    );
    }
    return (str == "GI" || 
      str == "necro_ob" || 
      str == "skull" || 
      str == "pouch" || 
      str == "necro_pouch" || 
      str == "notarmor"
    );
}

string short(){
    return "A small, brightly polished skull.\nComponent pouch";
}

string long(string str){
    string arg1,arg2;
    int int1,int2;
    if(!str)
	str = "skull";
    if(sscanf(str,"%s %s",arg1,arg2) != 2)
	arg1 = str;
    if(arg1 == "skull"){
	write("A skull taken from a treasured victory of long ago.\n"+
	  "The skull has been meticulously cleaned and taken\n"+
	  "care of. The symbol of a true Necromancer.  There seems\n"+
	  "to be some writings carved into the back.  You might be\n"+
	  "able to 'read' the 'skull'.\n");
    }
    if(arg1 == "pouch"){
	string msg;
	write("Darkened leather stained with many unknown substances makes\n"+
	  "up the component pouch that is used primarily to store spell\n"+
	  "components. A small drawstring holds it closed.\n");
	msg = "\tYour pouch currently contains:\n";
	if(blood){
	    msg += "\t  "+BOLD+blood+OFF+" vial";
	    if(blood > 1)
		msg += "s";
	    msg += " of blood\n";
	}
	if(skin){
	    msg += "\t  "+BOLD+skin+OFF+" skin";
	    if(skin > 1)
		msg += "s";
	    msg += "\n";
	}
	if(eye){
	    msg += "\t  "+BOLD+eye+OFF+" eye";
	    if(eye > 1)
		msg += "s";
	    msg += "\n";
	}
	if(spine){
	    msg += "\t  "+BOLD+spine+OFF+" spine";
	    if(spine > 1)
		msg += "s";
	    msg += "\n";
	}
	if(heart){
	    msg += "\t  "+BOLD+heart+OFF+" heart";
	    if(heart > 1)
		msg += "s";
	    msg += "\n";
	}
	if(soul){
	    msg += "\t  "+BOLD+soul+OFF+" soul";
	    if(soul > 1)
		msg += "s";
	    msg += "\n";
	}
	write(msg);
	say(this_player()->query_name()+
	  " searches through "+environment()->query_possessive()+
	  " component pouch for a moment.\n");
    } 
}

int drop(){ return 1; }
int get(){ return 1; }

void extra_look() {
    write(environment()->query_name()+" has a small "+BOLD+"skull"+OFF+
      " tattoo upon "+environment()->query_possessive()+" forehead.\n");
    if(icutmyself)
	write(environment()->query_name()+" has several lacerations across "+
	  environment()->query_possessive()+" wrists.\n");
}

void guild_login() {
    string news;
    string *news_array;
    int i,a,b,c;
    this_player()->set_guild_file(PATH+"/guildob.c"); /* Earwax */
    news = read_file(PATH+"/NEWS");
    news_array = explode(news, "\n");
    b = sizeof(news_array);
    write("\n"); 
    write("\t<"+HIR+"Necromantic News"+OFF+
      ">----------------------------------------->\n");
    for(i=0;i<b;i++){
	write(SPACE+BOLD+BLK+cutstring(news_array[i],70)+OFF+"\n");
    }
    write(BAR);
    write("\n");
    call_out("intro",2);
}

void intro(){
    tell_object(environment(this_object()),BOLD+
      "\n\nYou awake in the center of the Necromancer Guildhall.\n\n"+OFF);
    command("look", environment(this_object()));
    tell_object(environment(this_object()),"->>");
}

int deathcheckme(){
    DEATH_D->newdeathcheck();
    return 1;
}

void wimpycall(){
    if(environment(this_object())->query_wimpy()){
	tell_object(environment(this_object()),
	  "<"+HIR+"RoD"+OFF+"> The Realm of Death distains your cowardice.\n");
	tell_object(environment(this_object()),
	  BOLD+"You are stricken with pain as your heart constricts.\n"+OFF);
	environment(this_object())->add_hit_point(-((int)environment(this_object())->query_level() * 3));
    }
    call_out("wimpycall", random(1000));
}

void deathcall(){
    while(remove_call_out("deathcall") != -1);  /* 07/19/06 Earwax */
    if(!environment())
	return;  /* 07/19/06 Earwax */
    command("deathcheckme", environment(this_object()));
    call_out("deathcall", 20);
}

int necro_title() {
    string title;
    switch(g_level){
    case 1:
	title = "\b, the Apprentice Necromancer";
	break;
    case 2..3:
	title = "\b, "+YEL+"the Harvester of the Dead"+OFF;
	break;
    case 4..5:
	title = "\b, the "+HIR+"Defiler"+OFF+" of "+HIR+"Graves"+OFF;
	break;
    case 6..8:
	title = "\b, "+BOLD+BLK+"the Necromancer"+OFF;
	break;
    case 9:
	title = "\b, "+BOLD+"the Minister of Souls"+OFF;
	break;
    }
    if((string)this_player()->query_real_name() == "sebastian")
	title = "\b, "+BOLD+BLK+"the Necromanic Scribe"+OFF;
    this_player()->set_title(title);
    write("<"+HIW+"NECRO"+NORM+"> Necromancer Title Set.\n");
    return 1; 
}


int save_me(){
    g_level = (int)environment(this_object())->query_guild_rank();
    save_object(SAVE+environment(this_object())->query_real_name());
    return 1;
}
void init() {
    if(environment(this_object()) == this_player()){
	if(!restore_object(SAVE+this_player()->query_real_name())){
	    if(restore_object(SAVE+"bak/"+this_player()->query_real_name())){
		write("We are no longer testing the necromancer guild.\n"+
		  "Thank you for your time.\n");
		this_player()->set_home("/room/church");
		this_player()->set_guild_rank(0);
		this_player()->set_guild_exp(0);
		this_player()->set_guild_name();
		move_object(this_player(),"/room/church");
		this_player()->save_me();
		destruct(this_object());
		return;
	    }
	    blood = 25;
	    eye = 0;
	    heart = 0;
	    skin = 0;
	    soul = 0;
	    spine = 0;
	    cdust = 0;
	    g_level = 1;
	    save_object(SAVE+this_player()->query_real_name());
	}
	if(this_player()->query_level() < 20){
	    this_player()->set_guild_name("necromancer");
	    if((int)this_player()->query_guild_rank() != g_level)
		this_player()->set_guild_rank(g_level);
	    this_player()->set_home(PATH+"/room/necro2.c");
	    this_player()->set_pretitle("|");
	    necro_title();
	    if(this_player()->query_guild_file() != (PATH+"/guildob.c"))
		this_player()->set_guild_file(PATH+"/guildob.c");
	    write("<"+BOLD+"NECRO"+OFF+"> Guild Status Restored.\n");
	    save_me();
	    this_player()->save_character();
	}
	CHAT_D->resetchannel();

	/***  BASIC GUILD ABILITES ***/
	add_action("spell_hook");add_xverb("");
	add_action("cmd_hook");add_xverb("");
	add_action("emote_hook");add_xverb("");
        if (this_player()->query_level() > 20 ||
            (string)this_player()->query_real_name() == "rump") {
	    add_action("admin_hook");add_xverb("");
	}
	add_action("deathcheckme","deathcheckme");
	deathcall();
	wimpycall();
	add_action("sub_comp","get");
	add_action("sub_comp","take");
	add_action("add_comp","put");
	add_action("move_pouch","give");
	add_action("quit","quit");
	add_action("necro_quit","leave_guild");
	add_action("necro_save","nsave");
	add_action("necro_update","nupdate");
	add_action("necro_title","ntitle");
	add_action("necro_block","missile");
	add_action("necro_block","mi");
	add_action("necro_block","shock");
	add_action("necro_block","sh");
	add_action("necro_block","fireball");
	add_action("necro_block","fi");
	add_action("necro_block","sonic");
	add_action("necro_block","so");
	add_action("necro_block","invisible");
	add_action("necro_block","invis");
	add_action("necro_block","pose");
	add_action("read_me","read");
	add_action("polish_me","polish");
	add_action("necro_obit", "deaths");
	add_action("newsay");add_xverb("'");
    }
}

int newsay(string str){
    command("say "+str, this_player());
    return 1;
}

string query_guild_title() {
    string title;
    /* changed from if(g_level) verte */
    if(intp(g_level)){
	switch(g_level){
	case 1:
	    title = "the Apprentice Necromancer";
	    break;
	case 2..3:
	    title = YEL+"the Harvester of the Dead"+OFF;
	    break;
	case 4..5:
	    title = "the "+HIR+"Defiler"+OFF+" of "+HIR+"Graves"+OFF;
	    break;
	case 6..8:
	    title = BOLD+BLK+"the Necromancer"+OFF;
	    break;
	case 9:
	    title = BOLD+"the Minister of Souls"+OFF;
	    break;
	}
	if((string)this_player()->query_real_name() == "sebastian")
	    title = BOLD+BLK+"the Necromanic Scribe"+OFF;
	return title;
    }
}

void set_muffle(int m){ muffle = m; }
int query_muffled(){ return muffle; }


int necro_save(){
    save_me();
    tell_object(environment(this_object()),
      "You begin to meticulously clean your skull until it shines.\n"+
      "<"+HIR+"NECRO"+OFF+"> Guild status saved.\n");
    return 1;
}

int polish_me(string str){
    if(!str){
	notify_fail("What would you like to polish?\n");
	return 0;
    }
    if(str != "skull"){
	notify_fail("That is not something you can polish.\n");
	return 0;
    }
    necro_save();
    return 1;
}

int necro_update(){
    save_me();
    write("<"+HIR+"NECRO"+OFF+"> Guild Status Saved.\n");
    move_object(clone_object(PATH+"/guildob.c"),this_player());
    write("<"+BOLD+BLK+"NECRO"+NORM+"> Guild Status Updated.\n");
    destruct(this_object());
    return 1;
}


int necro_quit() {
    this_player()->set_guild_name(0);
    this_player()->add_exp(this_player()->query_guild_exp());
    this_player()->set_guild_exp(0);
    this_player()->set_guild_rank(0);
    this_player()->set_home("/room/church");
    this_player()->set_guild_file(0); /* Earwax 10/09/05 */
    this_player()->add_exp(-((int)this_player()->query_exp() /2));
    this_player()->set_attrib("sta",1);
    this_player()->reset(1);
    command("save",this_player());
    write(BOLD+"The Spirits tell you, \""+OFF+"FOOL!"+BOLD+"\"\n");
    CHAT_D->sub_membr(this_player());
    CHAT_D->chat_line("has left the guild",this_player()->query_real_name(),1);
    rm("/"+SAVE+this_player()->query_name()+".o");
    destruct(this_object());
    return 1; 
}

void quit(){
    /*
	necro_save();
    */
    CHAT_D->resetchannel();
}

int necro_block() {
    if(this_player()->query_level() < 20) {
	write("<"+HIR+"RoD"+OFF+">  The Realm of Death disdains the use of "+
	  "that spell.\n");
	this_player()->add_hit_point(-random(10));
	return 0; 
    }
}

int read_me(string str){
    string msg;
    int gl;
    if(!str){
	notify_fail("What would you like to read?\n");
	return 0;
    }
    if(str != "skull"){
	notify_fail("That is not something you can read here.\n");
	return 0;
    }
    write("The carvings on the back of the skull read:\n\n");
    write("Basic   -  necro(nc), necro who(necros), nupdate, polish skull, "+
      "leave_guild\n"+
      "            ntitle, muffle necro, channel necro\n");
    write("Level 1 -  chill, harvest, claim dagger, embalm corpse, evoke "+
      "ghouls, dismember\n"+
      "            consider\n");
    if(g_level > 1)
	write("Level 2 -  consume corpse, embrace death, grasp, excavate corpse\n");
    if(g_level > 2)
	write("Level 3 -  dig grave, drain, animate skeleton, consecrate "+
	  "gravesite\n");
    if(g_level > 3)
	write("Level 4 -  summon ghastly stench, cloak, anguish, echo\n");
    if(g_level > 4)
	write("Level 5 -  disease, graft, siphon\n");
    if(g_level > 5)
	write("Level 6 -  bloodmoon, raise portal\n");
    if(g_level > 6)
	write("Level 7 -  summon pestilence, decay\n");
    if(g_level > 7)
	write("Level 8 -  abandon, animate zombie\n");
    if(g_level > 8)
	write("Level 9 -  reanimate, wither\n");
    msg = "";
    if(sacrifice){
	msg = "Other   -  ";
	if(sacrifice)
	    msg += "sacrifice ";
	write(msg+"\n");
    }
    write("\n");
    return 1;
}

int comp_cost() {
    cat(DOCS+"/comp_costs.txt");
    return 1;
}

int checklev(int gl, int lev){
    if(!environment(this_object()))
	return 0;
    if(gl > environment(this_object())->query_guild_rank()){
	tell_object(environment(this_object()),
	  "You do not have the knowledge for that spell.\n");
	return 0;
    }
    if(lev > environment(this_object())->query_level()){
	tell_object(environment(this_object()),
	  "You aren't experienced enough to use that spell.\n");
	return 0;
    }
    return 1;
}

int spell_hook(string str){
    int i;
    string temp, arg1, arg2;
    if(!str)
	return 0;
    if(sscanf(str, "%s %s", arg1, arg2) != 2)
	arg1 = str;
    if(arg1 == "")
	return 0;
    i = strlen(arg1);
    if(arg1[i-1] == 046)
	return 0;
    temp = SPELLS+"/"+arg1+".c";
    if(file_size(temp) > 0){
	if(this_player()->query_dead()){
	    notify_fail("You have no control over the dark arts as one of the dead.\n");
	    return 0;
	}
	if(this_player()->test_dark()){
	    notify_fail("You can not see your component pouch.\n");
	    return 0;
	}
	if(temp->cmd(arg2))
	    return 1;
    }
    return 0;
}

int emote_hook(string str){
    int i;
    string temp, arg1, arg2;
    if(!str)
	return 0;
    if(sscanf(str,"%s %s",arg1,arg2) != 2)
	arg1 = str;
    if(arg1 == "")
	return 0;
    i = strlen(arg1);
    if(arg1[i-1] == 046)
	return 0;
    temp = EMOTES+"/"+arg1+".c";
    if(file_size(temp) > 0){
	if(temp->cmd(arg2))
	    return 1;
    }
    return 0;
}

int cmd_hook(string str){
    int i;
    string temp, arg1, arg2;
    if(!str)
	return 0;
    if(sscanf(str,"%s %s",arg1,arg2) != 2)
	arg1 = str;
    if(arg1 == "")
	arg1 = "blah";
    i = strlen(arg1);
    if(arg1[i-1] == 046)
	return 0;
    temp = CMDS+"/"+arg1+".c";
    if(file_size(temp) > 0){
	if(temp->cmd(arg2))
	    return 1;
    }
    return 0;
}

int admin_hook(string str){
    int i;
    string temp,arg1,arg2;
    if(!str)
	return 0;
    if(sscanf(str,"%s %s",arg1,arg2) != 2)
	arg1 = str;
    if(arg1 == "")
	return 0;
    i = strlen(arg1);
    if(arg1[i-1] == 046)
	return 0;
    temp = ADMIN+"/"+arg1+".c";
    if(file_size(temp) > 0){
	if(temp->cmd(arg2))
	    return 1;
    }
    return 0;
}

/*  COMPONENT POUCH */

void add_blood(int num){ blood += num; save_me();}
void add_skin(int num){ skin += num; save_me();}
void add_eye(int num){ eye += num; save_me();}
void add_spine(int num){ spine += num; save_me();}
void add_heart(int num){ heart += num; save_me();}
void add_soul(int num){ soul += num; save_me();}
void add_cdust(int num){ cdust += num; save_me();}
void add_val(int num) { val += num; save_me();}

int set_val(int arg){
    val = arg;
    necro_save();
    return 1;
}

int query_blood() {return blood; }
int query_skin() {return skin; }
int query_eye() {return eye; }
int query_spine() {return spine; }
int query_heart() {return heart; }
int query_soul() {return soul; }
int query_cdust() {return cdust; }
int query_val() { return val; }
int query_g_level() {return g_level; }

int add_comp(string str){
    string bodypart;
    object comp;
    if(!str)
	return 0;
    sscanf(str,"%s in pouch",bodypart);
    if(!bodypart)
	return 0;
    switch(bodypart){
    case "blood":    bodypart = "blood"; break;
    case "bloods":   bodypart = "blood"; break;
    case "vial":     bodypart = "blood"; break;
    case "vials":    bodypart = "blood"; break;
    case "skin":     bodypart = "skin";  break;
    case "skins":    bodypart = "skin";  break;
    case "eye":      bodypart = "eye";   break;
    case "eyes":     bodypart = "eye";   break;
    case "spine":    bodypart = "spine"; break;
    case "spines":   bodypart = "spine"; break;
    case "soul":     bodypart = "soul";  break;
    case "souls":    bodypart = "soul";  break;
    case "heart":    bodypart = "heart"; break;
    case "hearts":    bodypart = "heart"; break;
    default:
	write("There is no room for your "+bodypart+" in the component pouch.\n");
	break;
	return 1;
    }
    if(comp = present("necro_"+bodypart,this_player())){
	write("You put the "+bodypart+" in your component pouch.\n");
	say(this_player()->query_name()+
	  " puts some "+bodypart+" into "+
	  this_player()->query_possessive()+" pouch.\n");
	call_other(this_object(),"add_"+bodypart,comp->query_amount());
	save_me();
	destruct(comp);
	this_player()->recalc_carry();
	return 1;
    } else {
	write("There is no room for "+str+" in your component pouch.\n");
	return 1;
    }
}

int sub_comp(string str){
    string bodypart,temp;
    if(!str)
	return 0;
    sscanf(str,"%s from pouch",bodypart);
    if(!bodypart)
	return 0;
    if(bodypart != "blood" && 
      bodypart != "skin"  && 
      bodypart != "eye"   && 
      bodypart != "spine" &&
      bodypart != "soul"  && 
      bodypart != "heart"){
	write("There is no "+bodypart+" in the component pouch.\n");
	return 1;
    }
    if(call_other(this_object(),"query_"+bodypart) > 0){
	if(!this_player()->add_weight(1)){
	    write("You can not carry the "+bodypart+".\n");
	    return 1;
	}
	write("You remove some "+bodypart+" from the component pouch.\n");
	say(this_player()->query_name()+" removes some "+bodypart+
	  " from the component pouch.\n");
	call_other(this_object(),"add_"+bodypart,-1);
	save_me();
	temp = BODYPARTS+"/"+bodypart+".c";
	move_object(clone_object(temp),this_player());
	this_player()->recalc_carry();
	return 1;
    } else {
	write("There is no "+bodypart+" in the component pouch.\n");
	return 1;
    }
} 

int move_pouch(string str){
    string what,who;
    if(!str)
	return 0;
    sscanf(str,"%s to %s",what,who);
    if(!what || !id(what))
	return 0;
    if(!who || who != (string)this_player()->query_real_name())
	return 0;
    move_object(this_object(),this_player());
    return 1;
}

/* HIDDEN SPELLS */
int add_harvs(int i){
    harvs += i;
    if(harvs > 1000 && !harvest){
	write(BOLD+
	  "Through much dedication and practice you feel have gained the skill\n"+
	  "to harvest with a larger weapon.\n"+OFF);
	harvest = 1;
    }
}

void add_emdeaths(int i){
    string file; 
    emdeaths += i;
    if(emdeaths >= 2 && !sacrifice )
	call_out("add_spell",10,({ "sacrifice", }) );
} 

void set_emdeaths(int i){ emdeaths = i; }
void set_sacrifice(int i){ sacrifice = i; }
void set_harvest(int i){ harvest = i; }

int query_emdeaths(){ return emdeaths; }
int query_sacrifice(){ return sacrifice; }
int query_harvest(){ return harvest; }

void add_spell(string arg){
    tell_object(environment(this_object()),"<"+HIR+"RoD"+OFF+
      ">  The realm of death is pleased with your dedication.  \n"+
      BOLD+"      You have been empowered with a new spell.\n"+OFF);
    tell_object(environment(this_object()),"You can now cast "+arg[0]+".\n");
    call_other(this_object(),"set_"+arg[0],1);
    save_me();
}

/* ATMOSPHERE */ 
void add_icutmyself(int i){ icutmyself = icutmyself+i; }
void set_icutmyself(int i){ icutmyself = i; }
int query_icutmyself(){ return icutmyself;}

void amihealed(){
    remove_call_out("amihealed");
    icutmyself--;
    if(icutmyself < 1){
	tell_object(environment(),"The wounds on your wrists have healed.\n");
	environment()->remote_say("The wounds on "+environment()->query_name()+
	  "'s wrists have healed.\n");
    } else {
	call_out("amihealed",40);
    }
}

int necro_obit(){
    "/players/guilds/necro/obj/deathlog"->deathlog(0);
    write("  <"+HIR+"Necromantic Death Notice"+OFF+
      ">------------------------------------------------->\n\n");
    write("     Player        Time                Killed by\n\n");
    tail("/players/guilds/necro/log/deathlog");
    write("\n");
    write("  Level scale:  "+GRN+"Low  "+HIY+"Mid  "+NORM+RED+"High  "+BOLD+
      "Great  "+MAG+"Legendary\n"+OFF);
    write(BOLD+"  *"+OFF+" - Killed by Sparring.\n\n");
    write("  <-------------------------------------------------------------------------->\n");
    return 1;
}
