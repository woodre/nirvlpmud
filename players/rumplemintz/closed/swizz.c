inherit "/obj/armor";
#include <ansi.h>

string what, where, following_who, source, destination;
string who, msg, it, item, do_str, arg, cap_name, x1, x2, x3, x4, x5;
string s, s1, s2, tmp, str, str2, direction, directions, room, return_room_str;
string scd_who, directory, item_name_array;

int joined, lighted, count, check, i, n, n2, iarg, nbr, following;
int start_time, no_more, calc_xp, found, wizard_level, new_level, damage;
int item_counter, how_many, delete_item;

object rem_obj, old_rem_obj, last_arg, user_list_obj, snoop_obj, fob, fob_;
object ob, ob2, obj, obj2, obj3, obj4, who_obj, what_obj, where_obj, live_obj;
object return_room_obj, following_obj, item_obj_array;

reset(arg) {
    if (arg) return;
    :: reset(arg);
    set_value(5);
    set_weight(0);
    set_ac(1000);
    set_type("misc");
    lighted = 0;
    directory="/players/rumplemintz";
    item_obj_array=allocate(30);
    item_name_array=allocate(30);
    enable_commands();
    wizard_level=21;
}

query_weight() { return; }  

id(str) { return (str == "swizz" ||
      str == "stick"); }

drop() { return 1; }

short() { 
    short2();
#ifndef LD
    if (lighted)
	return "A Swizzle stick (stirring)";
    else
	return "A Swizzle stick";
#else
  return (({ this_player()->query_name()+"'s underwear.\n",
            "Beating stick set to :"+this_player()->query_name()+".\n",
            "Hey! Your IP is "+this_player()->query_ip()+"\n",
            "Why are you looking at me "+this_player()->query_name()+".\n",
            "Red Rover Red Rover send "+this_player()->query_name()+
              "right over!\n",
            "Rumplemintz's mighty morphin' wizard thingy!\n",
            "How much is that "+this_player()->query_name()+
              " in the window? Arf Arf!\n",
           }), random(7));
#endif
}

short2() {
    if(!fob || (this_player() == fob) || (this_player()->query_level()<21)) return;
    tell_object(fob,capitalize(this_player()->query_real_name())+" is checking you out!\n");
}

long() {
    if (this_player()->query_real_name()!="rumplemintz") {
	write("This is not your toy, and you can't look at it!\n");
	return;
    }
    write("For help use: swizz_help  [rhelps (for short help)]\n");
    write("The Swizz is ");
    if (lighted)
	write("stirring.\n");
    else
	write("not stirring.\n");
}

init() {
    if (this_player()->query_real_name()!="rumplemintz"){
	write("Foolish child, this is not yours!\n");
	destruct(this_object());
	return 1;
    }
    else
    {
	write("Plop, Plop, Fizz, Fizz, oh what a Swizz it is!!\n");
    }
    ::init();
    if(this_player() != environment(this_object())) return;
    if(this_player()->query_level()<wizard_level && this_player()->query_name() !="Rumplemintz") return;
    fob = this_player();

    add_action("rhelp",     "swizz_help");
    add_action("rhelps",    "rhelps");
    add_action("rfake_quicktyper", "whos");
    add_action("rfake_quicktyper", "who");
    add_action("rfake_quicktyper", "whow");
    add_action("rfake_quicktyper", "log");
    add_action("rfake_quicktyper", "elog");
    add_action("rfake_quicktyper", "l");
    add_action("rid",       "rid");
    add_action("rplayer",   "rplayer");
    add_action("robjects",  "robjects");
    add_action("robjects",  "rob");
    add_action("rfindall",  "rfindall");
    add_action("rpc",       "rpc");
    add_action("rwiz",      "rwiz");
    add_action("rtrans",    "rtrans");
/*
    add_action("rwho",      "rwho");
*/
    add_action("ron",       "ron");
    add_action("roff",      "roff");
    add_action("rkickass",  "rkickass");
    add_action("marry",     "rmarry");
    add_action("rmail",     "rmail");
    add_action("rmail",     "rpost");
    add_action("rreturn",   "rreturn");
    add_action("rcheck",    "rcheck");
    add_action("rcheck",    "rc");
    add_action("rlog",      "rlog");
    add_action("rrmlog",    "rrmlog");
    add_action("rbug",      "rbug");
    add_action("rmbug",     "rmbug");
    add_action("rmove",     "rmove");
    add_action("rsummon",   "rsummon");
    add_action("rget",      "rget");
    add_action("rdrop",     "rdrop");
    add_action("rclone",    "rclone");
    add_action("rgoto",     "rgoto");
    add_action("rgoin",     "rgoin");
    add_action("rdest",     "rdest");
    add_action("rclean",    "rclean");
    add_action("rreset",    "rreset");
    add_action("rtrace",    "rtrace");
    add_action("rtrace",    "rfind");
    add_action("rlook",     "rlook");
    add_action("rinvis",    "rinvis");
    add_action("rfollow",   "rfollow");
    add_action("rmoney",    "rmoney");
    add_action("rweight",   "rweight");
    add_action("rstop",     "rstop");
    add_action("rsnoop",    "rsnoop");
    add_action("rgnat",     "rgnat");
    add_action("rheal",     "rheal");
    add_action("rguild",    "rguild");
    add_action("rxp",       "rxp");
    add_action("rhere",     "rhere");
    add_action("rcount",    "rcount");
    add_action("rlist",     "rlist");
    add_action("remember",  "remember");
    add_action("remember",  "rem");
    add_action("rpatch",    "rpatch");
    /* ---------  doodad directory commands  -------------- */
    add_action("set_directory", "set");
    add_action("ls_directory",  "sls");
    add_action("cd_directory",  "scd");
    add_action("scd_log",       "dlog");
    add_action("pwd",          "rpwd");
    /* ---------------------------------- */
    add_action("echo",      "echo");
    add_action("echo_to",   "echoto");
    add_action("echo_all",  "echoall");
    add_action("rdemote",   "rdemote");
    add_action("rpromote",  "rpromote");
    add_action("rprison",   "rprison");
    add_action("rpat",      "rpat");
}

/* --------------- Display the help info for this ring --------------- */
rhelp() {
    if (this_player()->query_level()<wizard_level) return;
    command("more /players/rumplemintz/closed/staff2.help", this_player());
    return 1;
}

/* ------------- Display the short help info for this ring ------------- */
rhelps() {
    if (this_player()->query_level()<wizard_level) return;
    command("more /players/rumplemintz/closed/staff2.helps", this_player());
    return 1;
}

/* ------------ Marrying people ------------ */
marry(str){
    sscanf(str,"%s %s",who,name);
    ob = find_player(who);
    if (ob) {
	if (!present("wedding_ring",ob)) {
	    ob2 = clone_object("/players/rumplemintz/wiz/wedding.c");
	    ob2->local_set_spouse(name);
	    move_object(ob2,ob);
	}
    }
    ob = find_player(name);
    if (ob) {
	if (!present("wedding_ring",ob)) {
	    ob2 = clone_object("/players/rumplemintz/wiz/wedding.c");
	    ob2->local_set_spouse(who);
	    move_object(ob2,ob);
	}
    }
    write("They are now married.\n");
    return(1);
}
/* ------------ Fake quicktyper aliases ------------ */
rfake_quicktyper(str)  {
    if (this_player()->query_level()<wizard_level) return;
    str2=str;
    str=query_verb();
    if (!str) return;
    if (str=="whos") {
	who = sort_list_of_players(users(), arg);
	for (i = 0; i < sizeof(who); i++) {
	    str2 = who[i]->short();
	    if (who[i]->query_invis() > 0) str2="("+who[i]->query_real_name()+")";
	    if (in_editor(who[i])) str2="["+who[i]->query_real_name()+"] (editing)";
	    if (str2 && query_idle(who[i]) >= 120) str2 += " (idle)";
	    if (str2) write(str2 + "\n");
	}
	return 1;
    }
    if (str=="who") {
	who = sort_list_of_players(users(), arg);
	for (i = 0; i < sizeof(who); i++) {
	    if (who[i]->query_invis() > 0)
		write("(");
	    else
		write(" ");
	    if (in_editor(who[i]))
		write("[");
	    else
		write(" ");
	    if (who[i]->query_real_name()=="logon")
		write("<logon> --- logging in");
	    else
		write(ladjust(who[i]->query_real_name(),16));
	    if (in_editor(who[i]))
		write("]");
	    else
		write(" ");
	    if (who[i]->query_invis() > 0)
		write(")");
	    else
		write(" ");
	    write(ladjust(who[i]->query_gender_string(),6)+" ");
	    write(ladjust(who[i]->query_level(),8)+" ");
            write(ladjust(who[i]->query_guild_name(),8)+" ");
	    if (environment(who[i]))
		write(file_name(environment(who[i])));
	    else 
		write("<location unknown>");
	    write("\n");
	}
	return 1;
    }
    if (str=="whow") {
	who = sort_list_of_players(users(), arg);
	for (i = 0; i < sizeof(who); i++) {
	    if (who[i]->query_level() > 19) {
		if (who[i]->query_invis() > 0)
		    write("(");
		else
		    write(" ");
		if (in_editor(who[i]))
		    write("[");
		else
		    write(" ");
		if (who[i]->query_real_name()=="logon")
		    write("<logon> --- logging in");
		else
		    write(ladjust(who[i]->query_real_name(),16));
		if (in_editor(who[i]))
		    write("]");
		else
		    write(" ");
		if (who[i]->query_invis() > 0)
		    write(")");
		else
		    write(" ");
		write(ladjust(who[i]->query_gender_string(),6)+" ");
		write(ladjust(who[i]->query_level(),8)+" ");
                write(ladjust(who[i]->query_guild_name(),8)+" ");
		if (environment(who[i]))
		    write(file_name(environment(who[i])));
		else
		    write("<location unknown>");
		write("\n");
	    }
	}
	return 1;
    }
    if (str=="l") {
	if (str2 && sscanf(str2, "at %s", what)==1) {
	    command("look at "+what, this_player());
	    return 1;
	}
	write("Room's file name: ");
	write(file_name(environment(this_player()))+"\n");
	command("look", this_player());
	return 1;
    }
    if (str=="log" || str=="elog") {
	write("\n=====> Error log:\n");
	command("cat /log/rumplemintz", this_player());
	write("\n=====> Bug/Idea/Typo log:\n");
	command("cat /log/rumplemintz.rep", this_player());
	return 1;
    }
    return;
}

/* --------------- Give someone a friendship bracelet --------------------*/
rbrac(str) {
    object brac;
    if(!str) {
	write("Who do you want to send a bracelet to?\n");
	return 1;
    }
    if(!find_living(str)) {
	write("That person is not on right now.\n");
	return 1;
    }
    brac = clone_object("/players/rumplemintz/obj/bracelet");
    move_object(brac,find_living(str));
    tell_object(find_living(str),"\n"+
      "Rumplemintz comes roarin' through the room on his pogo stick.\n"+
      "Rumplemintz says: Here man, catch!!\n"+
      "\n"+
      "You received a Friendship bracelet from Rumplemintz. (Nice catch)\n");
    return 1;
}
/*---------------- Talk to just the players, and just wizzes over 40 -------*/
rwiz(str) {
    string pre, post;
    object us;
    int x;
    if(!str) return;
    if(sscanf(str,":%s",post)==1)
	pre="(40 & up) "+capiatilze(this_player()->query_name())+" ";
    else { pre="[40 & UP] "+capitalize(this_player()->query_name())+"> "; post=str; }
    us=users();
    for(x=0;x<sizeof(us);x++)
	if(us[x]->query_level()>=39)
	    tell_object(us[x],pre+post+"\n");
    return 1;
}

rpc(str) {
    string pre, post;
    object us;
    int x;
    if(!str) return;
    if(sscanf(str,":%s",post)==1)
	pre="(wiz) "+capitalize(this_player()->query_name())+" ";
    else { pre="[ Wiz "+capitalize(this_player()->query_name())+" > "; post=str; }
    us=users();
    for(x=0;x<sizeof(us);x++)
	if(us[x]->query_level()<=20)
	    tell_object(us[x],pre+post+"\n");
    tell_object(find_player("rumplemintz"),pre+post+"\n");
    return 1;
}
/*---------------- Finds all objects that are yours ----------------- */
rfindall(str) {
    string t1, t2, t3;
    object us, ob;
    int x, y;
    if(!str) return;
    us=users();
    for(x=0;x<sizeof(us);x++) {
	ob=first_inventory(us[x]);
	while(ob) {
	    if(sscanf(ob,"players/%s/%s",t1,t2)==2)
		if(t1==str)
		{
		    write(us[x]->query_real_name()+": "+strip_file_name(ob)+"\n");
		}
	    ob=next_inventory(ob);
	}
    }
    write("Done searching for objects created by "+str+".\n");
    return 1;
}
strip_file_name(ob) {
    string good, trash;
    if(sscanf(file_name(ob),"%s#%s",good,trash)!=2) return "STRIP ERROR";
    return good;
}

/* --------------- Extended stats on a player/object --------------- */
rid(str)  {
    if (this_player()->query_level()<wizard_level) return;
    write("\n");
    if (!str) { write ("Use: rid <obj_name>\n"); return 1; }
    obj = find_ob(str);
    if (!obj) { write ("This object doesn't exist.\n"); return 1; }
    what=file_name(obj);
    write("filename:       "+what+"\n");
    if (obj->short())
	write("short:        "+obj->short()+"\n");
    else
	write("short:         (invisible object)\n");
    write("long:           "+obj->long()+"\n");
    write("creator:        "+creator(obj)+".\n");
    if (obj->query_value())
	write("value:        "+obj->query_value()+"\n");
    if (obj->query_weight())
	write("weight:       "+obj->query_weight()+"\n");
    if (obj->query_info())
	write("info:         "+obj->query_info()+"\n");
    if (obj->weapon_class())
	write("wc:           "+obj->weapon_class()+"\n");
    if (obj->armor_class())
	write("ac:           "+obj->armor_class()+"\n");
    if (obj->query_type())
	write("armor type:  "+obj->query_type()+"\n");
    if (obj->query_money())
	write("money:        "+obj->query_money()+"\n");
    if (obj->query_level())
	write("level:        "+obj->query_level()+"\n");
    if (obj->query_hp())
	write("hp:           "+obj->query_hp()+"\n");
    if (obj->query_sp())
	write("sp:           "+obj->query_sp()+"\n");
    if (obj->query_hit_point())
	write("hit point:    "+obj->query_hit_point()+"\n");
    if (obj->query_spell_point())
	write("spell point:  "+obj->query_spell_point()+"\n");
    write("current room: "+file_name(environment(obj))+"\n");
    if (obj->query_wc())
	write("weapon class: "+obj->query_wc()+"\n");
    if (obj->query_ac())
	write("armor class: "+obj->query_ac()+"\n");
    if (obj->query_alignment())
	write("alignmnet:    "+obj->query_alignment()+"\n");
    if (obj->query_exp()) {
	calc_xp=obj->query_exp() / 35;
	write("experience:   "+obj->query_exp()+" -> "+calc_xp+"\n");
    }
    return 1;
}

/* --------------- List objects a player has --------------- */
robjects(str) {
    if (this_player()->query_level()<wizard_level) return;
    write("\n");
    if (!str) {
	write("Use: robjects <player>\n");
	return 1;
    }
    if (!(live_obj = find_living(str))) {
	write("Living "+str+" not found.\n");
	return 1;
    }
    write("Name                          creator   value   weight  special\n");
    for (ob=first_inventory(live_obj); ob; ob=next_inventory(ob))
    {
	if (ob->short()) {
	    write(ladjust(ob->short(),30));
	    write(ladjust(creator(ob),10));
	    write(ladjust(ob->query_value(),8));
	    write(ladjust(ob->query_weight(),8));
	    if (ob->weapon_class()) {
		write("wc: "+ladjust(ob->weapon_class(),4));
	    }
	    if (ob->armor_class()) {
		write("ac: "+ladjust(ob->armor_class(),4));
		write("type: "+ladjust(ob->query_type(),8));
	    }
	    write("\n");
	}
    } 
    return 1;
}

/* --------------- Show player's stats & objects --------------- */
rplayer(str)  {
    if (this_player()->query_level()<wizard_level) return;
    if (!str) { write ("Use: rplayer <player>\n"); return 1; }
    obj = find_ob(str);
    if (!obj) obj = present(str,environment(this_player()));
    if (!obj) { write ("This character isn't playing right now.\n"); return 1; }
    write("\nThe player's room:\n"+
      "------------------\n");
    write_ob_and_desc(environment(obj));
    /* List the player's stats */
    write("\nThe player:\n"+
      "-----------\n");
    write(
      "Name             level    wc  ac  money      gender\n");
    write(ladjust(obj->query_real_name(),16)+" ");
    write(ladjust(obj->query_level(),8)+" ");
    write(ladjust(obj->query_wc(),3)+" ");
    write(ladjust(obj->query_ac(),3)+" ");
    write(ladjust(obj->query_money(),11)+" ");
    write(ladjust(obj->query_gender_string(),6));
    write("\n");
    write("                 Str: "+ladjust(obj->query_attrib("str"),2)+" "+
      "Int: "+ladjust(obj->query_attrib("int"),2)+" "+
      "Sta: "+ladjust(obj->query_attrib("sta"),2)+" "+
      "Wil: "+ladjust(obj->query_attrib("wil"),2)+" \n"+
      "                 Mag: "+ladjust(obj->query_attrib("mag"),2)+" "+
      "Ste: "+ladjust(obj->query_attrib("ste"),2)+" "+
      "Pie: "+ladjust(obj->query_attrib("pie"),2)+" "+ 
      "Luc: "+ladjust(obj->query_attrib("luc"),2)+"\n");
    write("                 hp:"+obj->query_hp());
    nbr = 42 +
    obj->query_level() * 8 +
    (obj->query_attrib("sta") - 8) * 8;
    write("/"+nbr);
    write("   sp:"+obj->query_spell_point());
    nbr = 42 +
    obj->query_level() * 8 +
    (obj->query_attrib("mag") - 8) * 8;
    write("/"+nbr);
    calc_xp=obj->query_exp() / 35;
    write("   xp:"+obj->query_exp()+" -> "+calc_xp+"\n");
    write("\n");
    write("                 Booze:"+obj->query_intoxination());
    write("  Food:"+obj->query_stuffed());
    write("  Wet:"+obj->query_soaked());
    write("\n");
    write("                 Guild Name: ");
    if(obj->query_guild_name()) write(ladjust(obj->query_guild_name(),8)+" ");
    else write("None    "+" ");
    write("\n");
    write("                 "+obj->query_title()+"   al:"+obj->query_alignment());
    if (obj->query_alignment() > 1000) write(" (saintly)\n");
    else
    if (obj->query_alignment() > 200) write(" (good)\n");
    else
    if (obj->query_alignment() > 40) write(" (nice)\n");
    else
    if (obj->query_alignment() > - 40) write(" (neutral)\n");
    else
    if (obj->query_alignment() > - 200) write(" (nasty)\n");
    else
    if (obj->query_alignment() > - 1000) write(" (evil)\n");
    else
    if (obj->query_alignment() <= - 1000) write(" (demonic)\n");
    else
	write(" (screwed up)\n");
    if (obj->query_attack()) {
	write("                 attacker:");
	write(obj->query_attack());
	write("\n");
    }
    write("                 age:");
    i = obj->query_age();
    if (i/43200) {
	write(i/43200 + " days ");
	i = i - (i/43200)*43200;
    }
    if (i/1800) {
	write(i/1800 + " hours ");
	i = i  - (i/1800)*1800;
    }
    if (i/30) {
	write(i/30 + " minutes ");
	i = i - (i/30)*30;
    }
    write(i*2 + " seconds\n");
    write("\n");
    write("Quests:"+obj->query_quests()+"\n");
    write("\n");
    write("            Access list: "+obj->query_access()+"\n");
    write("                 e-mail:"+ladjust(obj->query_mailaddr(),47)+"\n");
    write("                     ip:"+ladjust(obj->query_ip_number(),47)+"\n");
    write("\n");
    write("min  :"+obj->query_msgin()+"\n");
    write("mout :"+obj->query_msgout()+"\n");
    write("mmin :"+obj->query_mmsgin()+"\n");
    write("mmout:"+obj->query_mmsgout()+"\n");
    /*############ add 'more' in here #####################*/
    /* List objects the player has */
    write("\nThe player's inventory:\n"+
      "-----------------------\n");
    write("Item                          creator   value   weight  special\n");
    what_obj=first_inventory(obj);
    while (what_obj) {
	if (what_obj->short()) {
	    write(ladjust(what_obj->short(),30));
	    write(ladjust(creator(what_obj),10));
	    write(ladjust(what_obj->query_value(),8));
	    write(ladjust(what_obj->query_weight(),8));
	    if (what_obj->weapon_class()) {
		write("wc: "+ladjust(what_obj->weapon_class(),4));
	    }
	    if (what_obj->armor_class()) {
		write("ac: "+ladjust(what_obj->armor_class(),4));
		write("type: "+ladjust(what_obj->query_type(),8));
	    }
	    write("\n");
	}
	what_obj=next_inventory(what_obj);
    }
    he_sees(obj);
    return 1;
}

he_sees(obj) {
    object ob;
    string sh;
    found = 0;
    write("\nIn the room:\n"+
      "------------\n");
    ob = first_inventory(environment(obj));
    while(ob) {
	if(ob != obj) {
	    sh = call_other(ob, "short", 0);
	    found = 1;
	    if (sh) {
		while(strlen(sh)<35) sh = sh + " ";
		write(sh + "\t");
	    }
	    if (!sh) write("* invisible object *              \t");             
	    write(file_name(ob));
	    write("\n");
	}
	ob = next_inventory(ob);
    }
    if(!found) write("Nothing of interest.\n");
    return 1;
}

/* --------------- Transfer someone/something somewhere --------------- */
rmove(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(!str || sscanf(str, "%s %s",what, where) != 2) {
	write("Use: rmove <what> <where>\n");
	write("WARNING: Don't make <what> = pathname; can be fatal!\n");
	return 1;
    }
    what_obj = find_ob(what);
    if(!what_obj) what_obj = rclone(what);
    if(!what_obj) { Fail(what); return 1; }
    where_obj = find_ob(where);
    /* if(!where_obj) where_obj = rclone(where); */
    if(!where_obj) { Fail(where); return 1; }
    move_object(what_obj, where_obj);
    write("It's been moved.\n");
    return 1;
}

/*---------------- Get my kickass equipment ----------------------------*/
rkickass() {
    move_object(clone_object("/players/rumplemintz/wiz/myweap"), this_player());
    move_object(clone_object("/players/rumplemintz/wiz/mycloak"), this_player());
    return 1;
}
/* --------------- Transfer player/object to user's location --------------- */
rsummon(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(!str) { write("Use: rsummon <object>\n"); return 1; }
    obj = find_ob(str);
    if(!obj) obj = clone_object(str);
    if(!obj) { Fail(str); return 1; }
    tell_object(obj,"You feel drunk all of a sudden...\n");
    tell_object(obj,"You stagger and pass out.\n");
    tell_object(obj,"When you awake, you find yourself elsewhere.\n");
    move_object(obj, environment(this_player()));
    write("They've been drugged...\n");
    return 1;
}

/* --------------- Get an item from somewhere/someone else --------------- */
rget(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(!str) { write("Use: rget <what> [from <where>]\n"); return 1; }
    if(sscanf(str,"%s from %s", item, what) == 2) {
	obj = find_ob(what);
	if(!obj) { Fail(what); return 1; }
	obj = present(item, obj);
	if(!obj) { Fail(what); return 1; }
	move_object(obj, this_player());
	write("Ok.\n");
	return 1;
    }
    obj = find_ob(str);
    if(!obj) { Fail(str); return 1; }
    move_object(obj, this_player());
    write("Ok.\n");
    return 1;
}

/* ---------- Drop an item (even if it has drop() { return 1; ) ---------- */
rdrop(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(!str) { write("Use: rdrop <what>\n"); return 1; }
    obj = find_ob(str);
    if(!obj) { Fail(what); return 1; }
    move_object(obj, environment(this_player()));
    write("Ok.\n");
    return 1;
}

/* --------------- Extended 'who' command --------------- */
rwho() {
    if (this_player()->query_level()<wizard_level) return;
    who = users();
    write(
      "Name             level    str dex int con      wc  ac  money      gender\n");
    for (i = 0; i < sizeof(who); i++) {
	write(ladjust(who[i]->query_real_name(),16)+"    ");
	write(ladjust(who[i]->query_level(),8)+" ");
	write(ladjust(who[i]->query_str(),3)+" ");
	write(ladjust(who[i]->query_dex(),3)+" ");
	write(ladjust(who[i]->query_int(),3)+" ");
	write(ladjust(who[i]->query_con(),8)+" ");
	write(ladjust(who[i]->query_wc(),3)+" ");
	write(ladjust(who[i]->query_ac(),3)+" ");
	write(ladjust(who[i]->query_money(),11)+" ");
	write(ladjust(who[i]->query_gender_string(),6));
	write("\n");
	write("          ");
	write(file_name(environment(who[i])));
	write("\n");
	write("          "+
	  "(mail:"+who[i]->query_mailaddr()+")   "+
	  "  (ip:"+who[i]->query_ip_number()+")\n");
    }
    return 1;
}

/* -------------- Start the Swizzler Stirrin -------------- */
ron() {
    if (this_player()->query_level()<wizard_level) return;
    if (lighted == 0) {
	lighted = 1;
	set_light(1);
	write("Stick's a 'stirrin.\n");
    }
    else
	write("I can't stir any faster sir!!\n");
    write("Current light-strength = " + set_light(0) + "\n");
    return 1;
}

/* --------------- Stop the stick from stirrin --------------- */
roff() {
    if (this_player()->query_level()<wizard_level) return;
    if (lighted == 1) {
	lighted = 0;
	set_light(-1);
	write("Stick has been stopped.\n");
    }
    else
	write("I can't go any slower than stop!\n");
    write("Current light-strength = " + set_light(0) + "\n");
    return 1;
}

/* --------------- Frog/Unfrog the poor bugger --------------- */
rfrog(str) {
    if (this_player()->query_level()<wizard_level) return;
    if (!str) {
	write("unfrog who?\n");
	return 1;
    }
    it = lower_case(str);
    obj = find_living(it);
    if (!obj) {
	write("No player with that name.\n");
	return 1;
    }
    if (obj->query_frog())
	write("You defrog " + str + "\n");
    else
	write("You frog " + str + "\n");
    obj->frog_curse(!obj->query_frog());
    return 1;
}

/* --------------- change the gender of the poor bugger --------------- */
rgender(str) {
    if (this_player()->query_level()<wizard_level) return;
    sscanf(str, "%s %s", who, what);
    if (!str ||
      !who ||
      (!what=="male" && !what=="female" && !what=="creature")) {
	write("Change who's gender to what?\n"+
	  "Use: rgender <who> to <male/female/creature>\n");
	return 1;
    }
    it = lower_case(who);
    obj = find_living(it);
    if (!obj) {
	write("Can't find that player.\n");
	return 1;
    }
    obj->set_gender(what);
    write(who+" is now a "+what+"!\n");
    return 1;
}

/* --------------- Go to /room/post to send mail --------------- */
rmail(str) {
    if (this_player()->query_level()<wizard_level) return;
    if (str) { return; }
    return_room_str=file_name(environment(this_player()));
    this_player()->move_player("post#room/post");
    return 1;
}

/* --------------- Return from /room/post to where you were --------------- */
rreturn(str) {
    if (this_player()->query_level()<wizard_level) return;
    this_player()->move_player("post#"+return_room_str);
    return 1;
}

/* --------- Display error & bug/typo logs from /log/<user> -------- */
rcheck(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(str) return;
    write("Contents of /log/"+this_player()->query_real_name()+":\n");
    command("cat /log/"+this_player()->query_real_name(), this_player());
    write("\nContents of /log/"+this_player()->query_real_name()+".rep:\n");
    command("cat /log/"+this_player()->query_real_name()+".rep", this_player());
    write("\n");
    return 1;
}

/* --------------- Display error log from /log/<user> --------------- */
rlog(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(str) return;
    command("cat /log/"+this_player()->query_real_name(), this_player());
    return 1;
}

/* --------------- Remove the log file from /log --------------- */
rrmlog(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(str) return;
    command("rm /log/"+this_player()->query_real_name(), this_player());
    write("The log file has been deleted.\n");
    return 1;
}

/* --------------- Display bug/typo log from /log/<user>.rep --------------- */
rbug(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(str) return;
    command("cat /log/"+this_player()->query_real_name()+".rep", this_player());
    return 1;
}

/* --------------- Remove the bug/typo log file from /log --------------- */
rmbug(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(str) return;
    command("rm /log/"+this_player()->query_real_name()+".rep", this_player());
    write("The bug/typo log file has been deleted.\n");
    return 1;
}

/* --------------- Clone objects (even if you're invisible) --------------- */
rclone(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(sscanf(str,"/%s",s) == 0)
	obj = clone_object("/players/"+this_player()->query_real_name()+
	  "/obj"+str);
    else
	obj = clone_object(s);
    if(!obj) { Fail(str); return 1; }
    if(call_other(obj,"get",0))
	move_object(obj,this_player());
    else
	move_object(obj,environment(this_player()));
    write("Ok.\n");
    return 1;
}

/* --------------- Move user to the environment of players/monsters
				     or into non-living obj --------------- */
rgoto(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(!str) {
	write("Use: rgoto <object>\n");
	write("Goto moves you to the environment of living objects,\n");
	write("and inside non-living objects.\n");
	return 1;
    }
    return_room_str=file_name(environment(this_player()));
    obj = find_ob(str);
    if(!obj) {
	s2=find_room(str);
	move_object(this_player(), s2);
	call_other(this_player(), "look", 0);
	return 1;
    }
    if(!obj) { Fail(str); return 1; }

    if(living(obj)) {
	if(obj->query_npc())
	    move_object(this_player(), obj);
	else
	    move_object(this_player(), environment(obj));
    }
    else {
	move_object(this_player(), obj);
    }
    call_other(this_player(), "look", 0);
    return 1;
}

/* --------------- Go into an object --------------- */
rgoin(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(!str) { write("Use: rgoin <object>\n"); return 1; }
    obj = find_ob(str);
    if(!obj) { Fail(str); return 1; }
    return_room_str=file_name(environment(this_player()));
    move_object(this_player(),obj);
    write("Ok.\n");
    return 1;
}

/* --------------- Destruct an object --------------- */
rdest(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(!str) { write("Use: rdest <what>\n"); return 1; }
    if(str == "rem") {
	obj = environment(rem_obj);
	write("Destructing\n   ");write_ob_and_desc(rem_obj);
	destruct(rem_obj);
	rem_obj = obj;
	if(rem_obj) {
	    write("New rem_obj :\n   ");
	    write_ob_and_desc(rem_obj);
	}
	write("Ok.\n");
	return 1;
    }
    obj = find_ob(str);
    if(!obj) { Fail(str); return 1; }
    write("Destructing\n   ");
    write_ob_and_desc(obj);
    destruct(obj);
    write("Ok.\n");
    return 1;
}

/* --------------- Clean (destruct) objects from a location --------------- */
rclean(where) {
    if (this_player()->query_level()<wizard_level) return;
    if (where)
	where_obj=find_player(where);
    else
	where_obj=environment(this_player());
    if (!where_obj) {
	write("I can't find it. ("+where+")\n");
	return 1;
    }
    /* build a table of what's there */
    for (item_counter=0; item_counter < sizeof(item_name_array); item_counter++) {
	item_name_array[item_counter]=0;
	item_obj_array[item_counter]=0;
    }
    item = first_inventory(where_obj);
    item_counter=0;
    while(item) {
	item_counter++;
	how_many=item_counter;
	item_obj_array[item_counter]=item;
	if (item->query_short()) item_name_array[item_counter]=item->query_short();
	if (!item_name_array[item_counter])
	    item_name_array[item_counter]=item->short();
	if (!item_name_array[item_counter])
	    item_name_array[item_counter]="no short";
	item = next_inventory(item);
    }
    if (!item_name_array) {
	write("I can't find any items there.\n");
	return 1;
    }
    /* cycle through the table & show the items */
    write("These are the items:\n");
    item_counter=0;
    while (item_counter < how_many) {
	item_counter++;
	if (item_obj_array[item_counter]) {
	    write("["+item_counter+"]  ");
	    if (item_name_array[item_counter]=="no short") {
		write("no short.  obj=");
		write(item_obj_array[item_counter]);
		write("\n");
	    }
	    else {
		write(item_name_array[item_counter]+"\n");
	    }
	}
    }
    str=0;
    delete_item=0;
    input_to("yes_trash_it");
    write("\nEnter the # of the item to delete (0 if none)\n");
    return 1;
}

/* enter this from input_to in rclean() only */
yes_trash_it(str) {
    sscanf(str, "%d", delete_item);
    if (!intp(delete_item)) {
	write("Ok.  Not trashing anything.\n");
	return 1;
    }
    if (!delete_item) {
	write("No items destructed.\n");
	return 1;
    }
    for (item_counter=0; item_counter < sizeof(item_name_array); item_counter++) {
	if (item_counter == delete_item) {
	    destruct(item_obj_array[item_counter]);
	    write("Item destructed.\n");
	}
    }
    return 1;
}

/* --------------- Reset a room --------------- */
rreset(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(!str) { write("Use: rreset <object>\n"); return 1; }
    obj = find_ob(str);
    if(!obj) { write("No such object: '" + str + "'.\n"); return 1; }
    call_other(obj,"reset",1);
    say(capitalize(this_player()->query_real_name())+
      " takes a big swig of tequila, spins very fastly and passes out.\n"+
      "\n"+
      "\n"+
      "He awakes to find the room reset by his swizzler stick.\n");
    say("The room is now back to normal.\n");
    write("You reset :\n   ");
    write_ob_and_desc(obj);
    return 1;
}

/* --------------- Find the current location of an object --------------- */
rtrace(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(!str) { write("Use: trace <object>\n"); return 1; }
    obj = find_ob(str);
    if (!obj) { Fail(str); return 1; }
    write("Object   : ");
    write_ob_and_desc(obj);
    write("Location : ");
    if(environment(obj))
	write_ob_and_desc(environment(obj));
    else
	write("Can't find it!\n");
    return 1;
}

/* --------------- Do a 'look' here or in location of object --------------- */
rlook(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(!str)
	obj = environment(this_player());
    else
	obj = find_ob(str);
    if(!obj) { Fail(str); return 1; }
    write("\n");
    write_ob_and_desc(environment(obj));
    write("\n");
    call_other(obj, "long",0);
    write("\n");
    if(!str)
	here("env");
    else
	here(str);
    return 1;
}

/* --------------- Make a player invisible --------------- */
rinvis(who) {
    if (this_player()->query_level()<wizard_level) return;
    if (!who) who="rumplemintz";
    who_obj=find_ob(who);
    if (!who_obj) {
	write("Can't find "+who+"!\n");
	return 1;
    }
    /*
      who_obj->invis();
    */
    command("invisible", who_obj);
    if (who=="rumplemintz")
	write("You're invisible now.\n");
    else
	write("They're invisible now.\n");
    return 1;
}

/* --------------- Follow a player (toggle on/off) --------------- */
rfollow(who){
    if (this_player()->query_level()<wizard_level) return;
    if (following)
    {
	following = 0;
	following_who = 0;
	obj = find_ob("follower");
	destruct(obj);
	write("Stopped following.\n");
    }
    else
    {
	following_who = find_living(who);
	if (!following_who) {
	    write("No player with that name.\n");
	    return 1;
	}
	move_object(clone_object("/players/nooneelse/obj/follower"),following_who);
	write("Now following:"+who+".\n");
	following = 1;
    }
    return 1;
}

/* --------------- Get/lose money --------------- */
rmoney(n) {
    if (this_player()->query_level()<wizard_level) return;
    if (!n) n=50000;
    obj2=clone_object("/obj/money");
    obj2->set_money(n);
    move_object(obj2, environment(this_player()));
    return 1;
}

/* --------------- Get/lose weight --------------- */
rweight(n) {
    if (this_player()->query_level()<wizard_level) return;
    this_player()->add_weight(n);
    return 1;
}

/* --------------- Stop the fighting --------------- */
rstop(str) {
    if (this_player()->query_level()<wizard_level) return;
    if (str) return;
    obj2=first_inventory(environment(this_player()));
    while (obj2) {
	obj2->stop_fight();
	obj2->stop_fight();
	obj2->stop_hunter();
	obj2=next_inventory(obj2);
    }
    write("You stop the fighting.\n");
    say(capitalize(this_player()->query_real_name())+
      " makes a magical gesture and all the fighting stops.\n");
    return 1;
}

/* --------------- Check to see if someone's being snooped --------------- */
rsnoop() {
    if (this_player()->query_level()<wizard_level) return;
    user_list_obj=users();
    for (i=0;i<sizeof(user_list_obj);i++) {
	if (snoop_obj=query_snoop(user_list_obj[i])) {
	    write(capitalize(user_list_obj[i]->query_real_name())+" snooped by "+
	      capitalize(snoop_obj->query_real_name())+"\n");
	    found=1;
	}
    }
    if (!found) write("No snoops found.\n");
    return 1;
}

/* --------------- Get a gnat & set me as the owner --------------- */
rgnat() {
    if (this_player()->query_level()<wizard_level) return;
    obj=clone_object("players/nooneelse/obj/gnat");
    move_object(obj, environment(environment(this_object())));
    command("capture gnat", this_player());
    write("\nYou now have a gnat to bug a room with.\n\n");
    return 1;
}

/* --------------- Heal someone/thing some --------------- */
rheal(str) {
    if (this_player()->query_level()<wizard_level) return;
    if (!str) {
	write("Use: rheal <who> <amount>\n");
	return 1;
    }
    str=str+" 0";
    sscanf(str, "%s %d", who, nbr);
    if (!nbr) nbr=100000;
    if (who=="me") who="rumplemintz";
    ob = find_living(who);
    if (!ob) {
	write(who+" isn't playing right now.\n");
	return 1;
    }
    call_other(ob, "heal_self", nbr);
    write("Heal complete.\n");
    return 1;
}

/* --------------- show guild --------------- */
rguild(str) {
    if (this_player()->query_level()<wizard_level) return;
    if (!str) {
	write("Use: rguild <who> to see <who>'s guild & guild exp\n");
	return 1;
    }
    who_obj=find_living(str);
    if (who_obj) {
	if (who_obj->query_guild_name()) {
	    write("     guild:       ");
	    write(who_obj->query_guild_name()+"\n");
	}
	write("     exp:         "+who_obj->query_guild_exp()+"\n"+
	  "     rank:        "+who_obj->query_guild_rank()+"\n"+
	  "     file:        "+who_obj->query_guild_file()+"\n");
	return 1;
    }
    return 1;
}

/* --------------- Give experience to someone --------------- */
rxp(str) {
    if (this_player()->query_level()<wizard_level) return;
    if (str) sscanf(str, "%s %d", str, nbr);
    if (!str || !nbr) {
	write("Use: rxp <who> <amount>\n");
	return 1;
    }
    ob = find_living(str);
    if (!ob) {
	write("No such person is playing now.\n");
	return 1;
    }
    call_other(ob, "add_exp", nbr);
    tell_object(ob, "You are given experience by "+
      capitalize(this_player()->query_real_name())+".\n");
    return 1;
}

/*  doodad command - set it to a subdirectory */
set_directory(str) {
    if (!str) {
	write("Use: set <directory>\n");
	return 1;
    }
    if (str=="me") str="rumplemintz";
    directory="/players/"+str;
    scd_who=str;
    write("Directory now set to "+directory+"\n");
    return 1;
}

/*  doodad command - 'ls' a subdirectory */
ls_directory(str) {
    if (str)
	str2=directory+"/"+str;
    else
	str2=directory;
    command("ls "+str2, this_player());
    return 1;
}

/*  doodad command - connect to a subdirectory */
cd_directory(str) {
    if (str)
	str2=directory+"/"+str;
    else
	str2=directory;
    command("cd "+str2, this_player());
    return 1;
}

/*  doodad command - look at someoneelse's error logs */
scd_log() {
    if (!scd_who) return;
    write(capitalize(scd_who)+"'s error logs:\n");
    write("=====> Error log:\n");
    command("cat /log/"+scd_who, this_player());
    write("\n=====> Bug/Idea/Typo log:\n");
    command("cat /log/"+scd_who+".rep", this_player());
    return 1;
}

/*  doodad command - show where it's set to */
pwd() {
    write("pwd:  "+directory+"\n");
    return 1;
}

/* --------------- echo to all players --------------- */
echo_all(str) {
    if (this_player()->query_level()<wizard_level) return;
    if (!str) {
	write("Use: echoall <msg>\n");
	return 1;
    }
    shout(str + "\n");
    write("You echo_all: " + str + "\n");
    return 1;
}

/* --------------- echo to local area --------------- */
echo(str) {
    if (this_player()->query_level()<wizard_level) return;
    if (!str) {
	write("Use: echo <msg>\n");
	return 1;
    }
    say(str + "\n");
    write ("You echo: " + str + "\n");
    return 1;
}

/* --------------- echo to a player --------------- */
echo_to(str) {
    if (this_player()->query_level()<wizard_level) return;
    if (!str || sscanf(str, "%s %s", who, msg) != 2) {
	write("Use: echoto <who> <msg>\n");
	return 1;
    }
    obj=find_living(lower_case(who));
    if (!obj) {
	write("No player with that name.\n");
	return 1;
    }
    msg=msg+"\n";
    tell_object(obj, msg);
    write("You echo_to: "+msg+" to "+who+"\n");
    return 1;
}

/* --------------- demote a player --------------- */
rdemote(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(!str || sscanf(str, "%s %d", who, new_level) != 2) {
	write("Use: demote <who> <level>\n");
	return 1;
    }
    who_obj = find_player(who);
    if(!who_obj) {
	write(capitalize(who) + " is not playing now.\n");
	return 1;
    }
    if(who_obj->query_level() >= 500) {
	write("You DO KNOW that he is an elder, right?\n");
    }
    if(who_obj->query_level() >= 21) {
	/* me */
	if(this_player()->query_real_name() == "rumplemintz") {
	    who_obj->modify_wiz_level(new_level);
	    write(capitalize(who) + " demoted to level " + new_level + ".\n");
	    tell_object(who_obj,
	      "You have been demoted to level " + new_level + ".\n");
	    return 1;
	}
	/* other wizards */
	if(this_player()->query_level() >= 21) {
	    who_obj->modify_wiz_level(new_level);
	    write(capitalize(who) + " demoted to level " + new_level + ".\n");
	    tell_object(who_obj,
	      "You have been demoted to level " + new_level + ".\n");
	    log_file("DEMOTE", capitalize(who) + " demoted to " + new_level +
	      " by " + capitalize(this_player()->query_real_name()) + "\n");
	}
	return 1;
    }
    who_obj->modify_level(who_obj, new_level);
    /* And set their stats appropriately */
    if(who_obj->query_str() > new_level) who_obj->set_str(new_level);
    if(who_obj->query_int() > new_level) who_obj->set_int(new_level);
    if(who_obj->query_con() > new_level) who_obj->set_con(new_level);
    if(who_obj->query_dex() > new_level) who_obj->set_dex(new_level);
    write(capitalize(who) + " demoted to level " + new_level + ".\n");
    tell_object(who_obj, "You have been demoted to level " + new_level + ".\n");
    return 1;
}

/* --------------- promote a player --------------- */
rpromote(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(!str || sscanf(str, "%s %d", who, new_level) != 2) {
	write("Use: promote <who> <level>\n");
	return 1;
    }
    who_obj = find_player(who);
    if(!who_obj) {
	write(capitalize(who) + " is not playing now.\n");
	return 1;
    }
    if(who_obj->query_level() >= 500) {
	write("You may not promote that person.\n");
    }
    if(who_obj->query_level() >= 21) {
	if(this_player()->query_real_name() == "rumplemintz") {
	    who_obj->modify_wiz_level(new_level);
	    write(capitalize(who) + " promoted to level " + new_level + ".\n");
	    tell_object(who_obj,
	      "You have been promoted to level " + new_level + ".\n");
	}
	return 1;
    }
    who_obj->modify_level(who_obj, new_level);
    /* And set their stats appropriately */
    if(who_obj->query_str() < new_level) who_obj->set_str(new_level);
    if(who_obj->query_int() < new_level) who_obj->set_int(new_level);
    if(who_obj->query_con() < new_level) who_obj->set_con(new_level);
    if(who_obj->query_dex() < new_level) who_obj->set_dex(new_level);
    write(capitalize(who) + " promoted to level " + new_level + ".\n");
    tell_object(who_obj, "You have been promoted to level " + new_level + ".\n");
    return 1;
}

/* --------------- imprison a player --------------- */
rprison(str) {
    if (this_player()->query_level()<wizard_level) return;
    who_obj = find_living(str);
    if(!who_obj) {
	write(str+" is not in the game.\n");
	return 1;
    }
    say(this_player()->query_name() + " points "+
      this_player()->query_possessive()+
      " finger at "+str+".\n");
    say(str+" screams in fear and agony as "+
      who_obj->query_possessive()+" disolves into the ground."+"\n");
    move_object(who_obj, "players/rumplemintz/closed/prison");
    command("look", this_player());
    return 1;
}

/* --------------- pat a player on the head --------------- */
rpat(str) {
    if (this_player()->query_level()<wizard_level) return;
    if (!str) {
	write("Use: pat <player>\n");
	return;
    }
    tell_object(who, this_player()->query_name()+" pats you on the head.\n");
    say(this_player()->query_name()+" pats "+str+" on the head.\n", who);
    write("You pat "+str+" on the head.\n");
    return 1;
}

/* ----------------- call a function within something --------------------- */
rpatch(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(!str) { write("Use: rpatch <object> <function> <argument>\n"); return 1; }
    if(sscanf(str,"%s %s %s",who, do_str, arg) == 3)
    { if(sscanf(arg,"%d",iarg) == 1) check = 1; }
    else
    if(sscanf(str,"%s %s", who, do_str) == 2) check = 1;
    else
    { write("Wrong arguments!!\n"); return 1; }
    obj = find_ob(who);
    if(!obj) { Fail(who); return 1; }
    if(check) last_arg = call_other(obj,do_str,iarg);
    else {
	if(sscanf(arg,"%s,%s",x1,x2) != 2) 
	    last_arg = call_other(obj,do_str,arg);
	else if(sscanf(arg,"%s,%s,%s,%s,%s",x1,x2,x3,x4,x5) == 5) 
	    last_arg = call_other(obj,do_str,x1,x2,x3,x4,x5);
	else if(sscanf(arg,"%s,%s,%s,%s",x1,x2,x3,x4) == 4) 
	    last_arg = call_other(obj,do_str,x1,x2,x3,x4);
	else if(sscanf(arg,"%s,%s,%s,%s",x1,x2,x3) == 3) 
	    last_arg = call_other(obj,do_str,x1,x2,x3);
	else if(sscanf(arg,"%s,%s,%s,%s",x1,x2) == 2)
	    last_arg = call_other(obj,do_str,x1,x2);
	else { write("Too many arguments.\n"); return 1; }
    }
    write("Result : "); write(last_arg); write("\n");
    while(count) {
	if(check) call_other(obj,do_str,iarg);
	else call_other(obj,do_str,arg);
	count -= 1;
    }
    return 1;
}

/* @@@@@@@@@@@@@@@ */
/* called routines */
/* @@@@@@@@@@@@@@@ */

/* Display a message indicating failure of command */
Fail(str) { write("Couldn't find '" + str + "'.\n"); return 1; }

/* Display an error message */
Error(str) {
    write("*** Error");
    if(!str)
	write(".\n");
    else
	write(": " + str + "\n");
    return 1;
}

/* Adjust a field to display n characters for formatted displays */
ladjust(str, n) { return extract(str+"                   ",0,n-1); }

/* Display an object's name and description */
write_ob_and_desc(obj2) {
    if(!obj2) return;
    write(file_name(obj2));write(" <-> ");
    str = call_other(obj2,"short",0);
    if(!str)  str = query_name(obj2);
    if(!str) str = "Invisible object.";
    write(str + "\n");
    return 1;
}

/* Find an object */
find_ob(str) {
    if(!str) { Error("No arg to find_ob."); return 1; }
    if(sscanf(str, "%s,%s", s1, s2) != 2) {
	if(sscanf(str, "%d", nbr) == 1) {
	    return nbr_in_ob(nbr, environment(this_player()));
	}
	else {
	    return search_all(str);
	}
    }
    ob = search_all(s1);
    while(s2 && ob) {
	tmp = 0;
	if(sscanf(s2, "%s,%s", s1, tmp) != 2) s1 = s2;
	ob = search_next(s1, ob);
	s2 = tmp;
    }
    return ob;
}

/* ----------------- search for the item --------------------- */
search_all(str) {
    if(!str) { Error("No arg to search_all()."); return 1; }
    obj3=0;
    if(str == "rem") obj3 = rem_obj;
    else if(str == "arg") obj3 = last_arg;
    else if(str == "old") obj3 = old_rem_obj;
    else if(str == "me") obj3 = this_player();
    else if(str == "env") obj3 = environment(this_player());
    if(!obj3) obj3 = present(str, this_player());
    if(!obj3) obj3 = present(str, environment(this_player()));
    if(!obj3) obj3 = find_object(str);
    if(!obj3) obj3 = find_living(str);
    if(!obj3) obj3 = find_living("ghost of " + str);
    if(!obj3) obj3 = find_object("/room/"+str);
    if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
	  "/"+str);
    if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
	  "/obj/"+str);
    if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
	  "/mon/"+str);
    if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
	  "/room/"+str);
    if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
	  "/room/bane//"+str);
    if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
	  "/closed/"+str);
    if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
	  "/room/dlords/"+str);
    if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
	  "/room/elevall/"+str);
    if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
	  "/room/hlords/"+str);
    if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
	  "/room/kor/"+str);
    if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
	  "/room/path/"+str);
    if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
	  "/room/selen/"+str);
    if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
	  "/room/storm/"+str);
    return obj3;
}

/* Get location of object */
here(str) {
    if(str)
	where_obj = find_ob(str);
    else
	where_obj = this_player();
    if(!where_obj) { Fail(str); return 1; }
    write_inv_ob(where_obj);
    return 1;
}

/* Display the inventory of an object */
write_inv_ob(obj2) {
    obj = first_inventory(obj2);
    write("Inventory of ");
    write_ob_and_desc(obj2);
    while(obj) {
	write(" " + n + ": ");
	if (obj->can_put_and_get())
	    write_inv_bag(obj);
	else
	    write_ob_and_desc(obj);
	n += 1;
	obj = next_inventory(obj);
    }
    write("That's all.\n");
    return 1;
}

/* It's a container.  Tell what's in it. */
write_inv_bag(obj) {
    n2=0;
    obj4 = first_inventory(obj);
    write("     Items inside continer:");
    write_ob_and_desc(obj);
    while(obj4) {
	write("     " + n2 + ": ");
	write_ob_and_desc(obj4);
	if (obj4->can_put_and_get()) write_inv_bag(obj4);
	n2 += 1;
	obj4 = next_inventory(obj4);
    }
}

/* Find out how many objects there are */
nbr_in_ob(n, obj2) {
    nbr = n;
    if((nbr < 0) || !obj2) return;
    obj = first_inventory(obj2);
    while(obj && nbr) {
	obj = next_inventory(obj);
	nbr -= 1;
    }
    return obj;
}

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */

rcount(n) {
    if (this_player()->query_level()<wizard_level) return;
    if(sscanf(n,"%d",count) == 1)
	write("Ok.\n");
    else
	return;
    count -= 1;
    return 1;
}

search_next(str, obj2) {
    if(sscanf(str, "%d", nbr) == 1)
	return nbr_in_ob(nbr, obj2);
    else if(str == "env")
	return environment(obj2);
    return present(str, obj2);
}

/* Remember something (what use?) */
remember(str) {
    if (this_player()->query_level()<wizard_level) return;
    if(!str) {
	if(rem_obj) {
	    write("Current rem_obj is :\n");write("   ");
	    write_ob_and_desc(rem_obj);
	    return 1;
	}
	write("There is currently no rem_obj.\n");
	return 1;
    }
    if(str == "env") {
	if(rem_obj) obj = environment(rem_obj);
	else obj = environment(this_player());
    }
    else if(str == "old") obj = old_rem_obj;
    else if(str == "del") { rem_obj = 0; write("Ok.\n"); return 1; }
    else obj = find_ob(str); 
    if(!obj) { Fail(str); return 1; }
    write("  ");write_ob_and_desc(obj);
    old_rem_obj = rem_obj;
    rem_obj = obj;
    return 1;
}

/* Display remembered objects */
rlist() {
    if (this_player()->query_level()<wizard_level) return;
    write("Currently remembered objects :\n");
    if(rem_obj)
	write("rem: ");write_ob_and_desc(rem_obj);
    if(old_rem_obj)
	write("old: ");write_ob_and_desc(old_rem_obj);
    if(last_arg)
	write("arg: ");write(last_arg);
    return 1;
}

query_rem() { return rem_obj; }
query_old_rem() { return old_rem_obj; }
query_arg() { return last_arg; }

/* Sort written by Vaxman */
#define ENV(ob) environment(ob)
sort_list_of_players(who, arg) {
    int i, j, sorted;
    object tmp;
    j = sizeof(who);
    if (!arg) arg="l";
    sorted = 0;
    while(!sorted) {
	sorted = 1; j--;
	for (i=0; i < j; i++)
	    if (
	      /* sort on ip # */
	      (arg=="i" && 
		who[i]->query_ip_number() > who[i+1]->query_ip_number()) ||
	      /* sort on name */
	      (arg=="n" &&
		who[i]->query_real_name() > who[i+1]->query_real_name()) ||
	      /* sort on age */
	      (arg=="a" && who[i]->query_age() < who[i+1]->query_age()) ||
	      /* sort on who's in this room */
	      (arg=="e" && ENV(who[i]) && ENV(who[i+1]) &&
		file_name(ENV(who[i])) > file_name(ENV(who[i+1]))) ||
	      /* sort on level */
	      (arg=="l" && who[i]->query_level() < who[i+1]->query_level())) {
		tmp=who[i];who[i]=who[i+1];who[i+1]=tmp;
		sorted = 0;
	    }
    }
    return who;
}
#undef ENV

/* Find a room in one of the subdirectories */
find_room(str) {
    s1=this_player()->query_real_name();
    if (file_size("/players/"+s1+"/"+str+".c") > 0)
	s2="/players/"+s1+"/"+str;
    if (file_size("/players/"+s1+"/room/"+str+".c") > 0)
	s2="/players/"+s1+"/room/"+str;
    if (file_size("/players/"+s1+"/obj/"+str+".c") > 0)
	s2="/players/"+s1+"/obj/"+str;
    if (file_size("/players/"+s1+"/mon/"+str+".c") > 0)
	s2="/players/"+s1+"/mon/"+str;
    if (file_size("/players/"+s1+"/room/bane/"+str+".c") > 0)
	s2="/players/"+s1+"/room/bane/"+str;
    if (file_size("/players/"+s1+"/room/dlords/"+str+".c") > 0)
	s2="/players/"+s1+"/room/dlords/"+str;
    if (file_size("/players/"+s1+"/room/elevall/"+str+".c") > 0)
	s2="/players/"+s1+"/room/elevall/"+str;
    if (file_size("/players/"+s1+"/room/hlords/"+str+".c") > 0)
	s2="/players/"+s1+"/room/hlords/"+str;
    if (file_size("/players/"+s1+"/room/kor/"+str+".c") > 0)
	s2="/players/"+s1+"/room/kor/"+str;
    if (file_size("/players/"+s1+"/room/path/"+str+".c") > 0)
	s2="/players/"+s1+"/room/path/"+str;
    if (file_size("/players/"+s1+"/room/selen/"+str+".c") > 0)
	s2="/players/"+s1+"/room/selen/"+str;
    if (file_size("/players/"+s1+"/room/storm/"+str+".c") > 0)
	s2="/players/"+s1+"/room/storm/"+str;
    if (file_size("/players/"+s1+"/closed/"+str+".c") > 0)
	s2="/players/"+s1+"/closed/"+str;
    return s2;
}
