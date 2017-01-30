/*
 nooneelse_ring.c - a general purpose wizard's toy
*/

inherit "/obj/armor";
#include "/players/nooneelse/ansi.h"


#define TITLE "the totally confused wizard"
#define ALIGNTITLE "don't ask me"
#define ALIGNMENT 0

string type, what, where, following_who, source, destination;
string who, msg, it, item, do_str, arg, cap_name, x1, x2, x3, x4, x5;
string s, s1, s2, tmp, str, str2, direction, directions, room, return_room_str;
string scd_who, directory, item_name_array;
string *guild_name, *guild_display, *guild_owner, guilds_list;
string *who_array;

int joined, lighted, count, check, i, n, n2, iarg, nbr, following;
int start_time, no_more, calc_xp, found, new_level, damage;
int item_counter, how_many, delete_item;
int WIZARD_LEVEL;

object rem_obj, old_rem_obj, last_arg, user_list_obj, snoop_obj;
object ob, obj, obj2, obj3, obj4, who_obj, what_obj, where_obj, live_obj;
object return_room_obj, following_obj, item, where_obj, item_obj_array;

reset(arg) {
  if (arg) return;
  :: reset(arg);

  WIZARD_LEVEL=21;
  set_value(5);
  set_weight(0);
  set_ac(1);
  set_type("ring");
  lighted = 0;
  directory="/players/nooneelse";
  item_obj_array=allocate(100);
  item_name_array=allocate(100);
  guild_name = allocate(21);
  guild_display = allocate(21);
  guild_owner = allocate(21);
  enable_commands();
}

query_weight() { return; }

id(str) { return (str == "ring" ||
                  str == "plastic ring" ||
                  str == "nooneelse_ring"); }

drop() { return 1; }

short() {
  if (lighted)
    return "Nooneelse's plastic ring (glowing)";
  else
    return "Nooneelse's plastic ring";
}

long() {
  if (this_player()->query_level()<WIZARD_LEVEL) {
    write("This is a wizard's toy, and you can't use it!\n");
    return;
  }
  write("For help use: rhelp  [rhelps (for short help)]\n");
  write("The ring's light is turned ");
  if (lighted)
     write("on.\n");
  else
     write("off.\n");
}

init() {
  if (this_player()->query_level()<WIZARD_LEVEL) return;

  if (guild_name[1]!="vampire fangs") load_guild_list();
  add_action("dump_guild_list",     "rdump");

  add_action("rhelp",     "rhelp");
  add_action("rhelps",    "rhelps");
  add_action("ralias",    "ralias");
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
  add_action("ralign",    "ralign");
  add_action("rpretitle", "rpretitle");
  add_action("rtitle",    "rtitle");
  add_action("rtrans",    "rtrans");
  add_action("rwho",      "rwho");
  add_action("ron",       "ron");
  add_action("roff",      "roff");
  add_action("rfrog",     "rfrog");
  add_action("rgender",   "rgender");
  add_action("rptitle",   "rptitle");
  add_action("rpalign",   "rpalign");
  add_action("rmail",     "rmail");
  add_action("rmail",     "rpost");
  add_action("rreturn",   "rreturn");
  add_action("rrlog",     "rrlog");
  add_action("rrmlog",    "rrmlog");
  add_action("rbug",      "rbug");
  add_action("rmbug",     "rmbug");
  add_action("rmove",     "rmove");
  add_action("rsummon",   "rsummon");
  add_action("rsilence",  "rsilence");
  add_action("rget",      "rget");
  add_action("rdrop",     "rdrop");
  add_action("rclone",    "rclone");
  add_action("rgoto",     "rgoto");
  add_action("rgoin",     "rgoin");
  add_action("rclean",    "rclean");
  add_action("rreset",    "rreset");
  add_action("rtrace",    "rtrace");
  add_action("rtrace",    "rfind");
  add_action("rlook",     "rlook");
  add_action("rpeek",     "rpeek");
  add_action("rblock",    "rblock");
  add_action("rmin",      "rmin");
  add_action("rmout",     "rmout");
  add_action("rmmin",     "rmmin");
  add_action("rmmout",    "rmmout");
  add_action("rvis",      "rvis");
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
  add_action("pwd",           "pwd");
/* ---------  logs & notes ---------------------------- */
  add_action("log_work",  "write");
/* ---------------------------------------------------- */
  add_action("tell",      "tell");
  add_action("echo",      "echo");
  add_action("echo_to",   "echoto");
  add_action("echo_all",  "echoall");
  add_action("rtell",     "rtell");
  add_action("recho",     "recho");
  add_action("zap_them",  "zap");
  add_action("rdemote",   "rdemote");
  add_action("rpromote",  "rpromote");
  add_action("rat",       "rat");
  add_action("rquiet",    "rquiet");
  add_action("force",     "force");
  add_action("rprison",   "rprison");
  add_action("rrelease",  "rrelease");
  add_action("rrelease",  "rfree");
  add_action("rpat",      "rpat");
  add_action("rfixme",    "rfixme");
}


/* --------------- Display the help info for this ring --------------- */
rhelp() {
  if (this_player()->query_level()<WIZARD_LEVEL) return;

  command("more /players/nooneelse/closed/nooneelse_ring.help", this_player());
  return 1;
}

/* ------------- Display the short help info for this ring ------------- */
rhelps() {
  if (this_player()->query_level()<WIZARD_LEVEL) return;

  command("more /players/nooneelse/closed/nooneelse_ring.helps", this_player());
  return 1;
}

/* -------- check a player's quicktyper aliases -------------------- */
ralias(str) {
  object obj;
  if (!str) {
    write("Use: ralias <who>\n");
    return 1;
  }
  if (!find_player(str)) {
    write(capitalize(str)+" isn't playing now.\n");
    return 1;
  }
  obj=present("quicktyper", find_player(str));
  if (!obj) {
    write(capitalize(str)+" doesn't have a quicktyper.\n");
    return 1;
  }
  obj->alias();
  write("\n");
  return 1;
}

/* -------- part of rfake -------- */
whoX() {
  string r1, r2, r3, tmp, tmp1, str1, aline, edstr1, edstr2, invisstr1, invisstr2;
  object TP;

  if (guild_name[1]!="vampire fangs") load_guild_list();
  TP = environment(this_object());
  tell_object(TP, "\n------------------------------------------------------\n");
  for (i = 0; i < sizeof(who_array); i++) {
	aline="";
    if (who_array[i]->query_invis() > 0) {
      invisstr1="(";
      invisstr2=")";
    }
    else {
      invisstr1=" ";
      invisstr2=" ";
    }
    if (in_editor(who_array[i])) {
      edstr1="[";
      edstr2="]";
    }
    else {
      edstr1=" ";
      edstr2=" ";
    }
    aline=aline+invisstr1+edstr1;
    if (who_array[i]->query_real_name()=="logon")
      aline=aline+"<logon> --- logging in";
    else
      aline=aline+ladjust(who_array[i]->query_real_name(),16);
    aline=aline+invisstr2+edstr2;
    aline=aline+ladjust(who_array[i]->query_gender_string(),6)+" ";
    if (who_array[i]->query_level()<WIZARD_LEVEL && who_array[i]->query_extra_level()>0)
      aline=aline+ladjust(who_array[i]->query_level(),2)+"("+
            ladjust(who_array[i]->query_extra_level(),2)+")   ";
    else
      aline=aline+ladjust(who_array[i]->query_level(),8)+" ";
/*@@@@@*/
    list_all_guilds(who_array[i]);
    aline=aline+guilds_list;
    if (environment(who_array[i])) {
      r1=file_name(environment(who_array[i]));
      if (sscanf(r1, "%s/nooneelse/closed/guild_form#%s", r2, r3)==2)
        aline=aline+abreviate_room(file_name(environment(environment(who_array[i]))));
      else
        aline=aline+abreviate_room(file_name(environment(who_array[i])));
    }
    else
        aline=aline+"<location unknown>";
    aline=aline+"\n";
    tell_object(TP, aline);
  }
  tell_object(TP, "------------------------------------------------------\n");
  return 1;
}

/* ------------ Fake quicktyper aliases ------------ */
rfake_quicktyper(str)  {
  object obj, next_obj;
  string r1, r2, r3, tmp, tmp1, str1;

  if (this_player()->query_level()<WIZARD_LEVEL) return;

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
    who_array = sort_list_of_players(users(), arg);
    call_out("whoX", 1);
    return 1;
  }
  if (str=="whow") {
    who = sort_list_of_players(users(), arg);
    for (i = 0; i < sizeof(who); i++) {
      if (who[i]->query_level() >= WIZARD_LEVEL) {
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
        if (who[i]->query_level()<WIZARD_LEVEL && who[i]->query_extra_level()>0)
          write(ladjust(who[i]->query_level(),2)+"("+
                ladjust(who[i]->query_extra_level(),2)+")   ");
        else
          write(ladjust(who[i]->query_level(),8)+" ");
        list_all_guilds(who[i]);
        if (environment(who[i]))
          write(abreviate_room(file_name(environment(who[i]))));
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
/*@#@#@#*/
    this_player()->look(0,1);
    return 1;
  }
  if (str=="log" || str=="elog") {
    write("\n=====> Error log:\n");
    command("cat /log/nooneelse", this_player());
    write("\n=====> Bug/Idea/Typo log:\n");
    command("cat /log/nooneelse.rep", this_player());
    write("\n=====> Wizard's log of work done in your area:\n");
    write("       (remove with 'rm /players/nooneelse/WORK_REPORT')\n");
    command("cat /players/nooneelse/WORK_REPORT", this_player());
    return 1;
  }
  return;
}

/* --------------- Extended stats on a player/object --------------- */
rid(str)  {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
  if (obj->query_extra_level())
    write("extra level:  "+obj->query_extra_level()+"\n");
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
  if (obj->query_level()<WIZARD_LEVEL && obj->query_extra_level()>0)
    write(ladjust(obj->query_level(),2)+"("+
          ladjust(obj->query_extra_level(),2)+")   ");
  else
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
  nbr = obj->query_extra_level()*2+42+
        obj->query_level()*8+(obj->query_attrib("sta")-8)*8;
  write("/"+nbr);
  write("   sp:"+obj->query_spell_point());
  nbr = 42+obj->query_extra_level()*3+
        obj->query_level()*8+(obj->query_attrib("mag")-8)*8;
  write("/"+nbr);
  calc_xp=obj->query_exp() / 35;
  write("   xp:"+obj->query_exp()+" -> "+calc_xp+"\n");
  write("\n");
  write("                 Booze:"+obj->query_intoxination());
  write("  Food:"+obj->query_stuffed());
  write("  Wet:"+obj->query_soaked());
  write("\n");
  write("                 Guild Name: ");
  list_all_guilds(obj);
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
  write("                     ip:"+ladjust(obj->query_hostname(),47)+"\n");
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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

/* --------------- Transfer player/object to user's location --------------- */
rsummon(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if(!str) { write("Use: rsummon <object>\n"); return 1; }
  obj = find_ob(str);
  if(!obj) obj = clone_object(str);
  if(!obj) { Fail(str); return 1; }
  tell_object(obj,"You are transported elsewhere!\n");
  move_object(obj, environment(this_player()));
  write("Ok.\n");
  return 1;
}

/* --------------- Silence a noisy pain-in-the-butt ---------------------- */
rsilence(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (!str) { write("Use: rsilence <who>"); return 1; }
  obj = find_player(str);
  if (!obj) {
    write(capitalize(str)+" can't be found.\n");
    return 1;
  }
  move_object(clone_object("/players/nooneelse/closed/shut_em_up"), obj);
  tell_object(obj, "\nYou have been silenced by a wizard!\n");
  write(capitalize(str)+" has been silenced.\n");
  return 1;
}

/* --------------- Get an item from somewhere/someone else --------------- */
rget(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if(!str) { write("Use: rdrop <what>\n"); return 1; }
  obj = find_ob(str);
  if(!obj) { Fail(what); return 1; }
  move_object(obj, environment(this_player()));
  write("Ok.\n");
  return 1;
}

/* --------------- Extended 'who' command --------------- */
rwho() {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  who = users();
  write(
  "Name             level    str dex int con      wc  ac  money      gender\n");
  for (i = 0; i < sizeof(who); i++) {
    write(ladjust(who[i]->query_real_name(),16)+"    ");
    if (who[i]->query_level()<WIZARD_LEVEL && who[i]->query_extra_level()>0)
      write(ladjust(who[i]->query_level(),2)+"("+
            ladjust(who[i]->query_extra_level(),2)+")   ");
    else
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
    write(abreviate_room(file_name(environment(who[i]))));
    write("\n");
    write("          "+
          "(mail:"+who[i]->query_mailaddr()+")   "+
          "  (ip:"+who[i]->query_hostname()+")\n");
  }
  return 1;
}

/* --------------- Turn the ring's light on --------------- */
ron() {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (lighted == 0) {
    lighted = 1;
    set_light(1);
    write("Light is on.\n");
  }
  else
    write("The light is already on!\n");
  write("Current light-strength = " + set_light(0) + "\n");
  return 1;
}

/* --------------- Turn the ring's light off --------------- */
roff() {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (lighted == 1) {
    lighted = 0;
    set_light(-1);
    write("Light is off.\n");
  }
  else
    write("The light is already off!\n");
  write("Current light-strength = " + set_light(0) + "\n");
  return 1;
}

/* --------------- Frog/Unfrog the poor bugger --------------- */
rfrog(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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

/* --------------- Change the user's alignment string --------------- */
ralign(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (!str) {
    write("Use: ralign <al_string>\n");
    return 1;
  }
  command("setal "+str, this_player());
  write("Your alignment has been changed...\n");
  return 1;
}

/* --------------- Change the user's pretitle string --------------- */
rpretitle(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (!str) {
    write("Use: rpretitle <pretitle_string>\n"); return 1;}
  call_other(this_player(),"set_pretitle",str);
  write("The pretitle has been changed...\n");
  return 1;
}

/* --------------- Change the user's title --------------- */
rtitle(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (!str) { write("Use: rtitle <title>\n"); return 1;}
  call_other(this_player(), "set_title",str);
  write("Your title has been changed...\n");
  return 1;
}

/* --------------- Set a player's title --------------- */
rptitle(str){
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (!str || sscanf(str, "%s %s",who,msg) != 2){
    write("Use: rptitle <player> <title>\n");
    return 1;
  }
  it = lower_case(who);
  obj = find_living(it);
  if (!obj) {
    write("No player with that name.\n");
    return 1;
  }
  call_other(obj,"set_title",msg);
  write("Ok.\n");
  return 1;
}

/* --------------- Change player's alignment message --------------- */
rpalign(str){
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (!str || sscanf(str, "%s %s",who,msg) != 2){
    write("Use: rpalign <player> <alignment message>\n");
    return 1;
  }
  it = lower_case(who);
  obj = find_living(it);
  if (!obj) {
    write("No player with that name.\n");
    return 1;
  }
  call_other(obj,"setal",msg);
  write("Their alignment message has been changed.\n");
  return 1;
}


/* --------------- Go to /room/post to send mail --------------- */
rmail(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (str) { return; }
  return_room_str=file_name(environment(this_player()));
  this_player()->move_player("post#room/post");
  return 1;
}

/* --------------- Return from /room/post to where you were --------------- */
rreturn(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  this_player()->move_player("post#"+return_room_str);
  return 1;
}

/* --------------- Display error log from /log/<user> --------------- */
rrlog(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if(str) return;
  command("cat /log/"+this_player()->query_real_name(), this_player());
  return 1;
}

/* --------------- Remove the log file from /log --------------- */
rrmlog(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if(str) return;
  command("rm /log/"+this_player()->query_real_name(), this_player());
  write("The log file has been deleted.\n");
  return 1;
}

/* --------------- Display bug/typo log from /log/<user>.rep --------------- */
rbug(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if(str) return;
  command("cat /log/"+this_player()->query_real_name()+".rep", this_player());
  return 1;
}

/* --------------- Remove the bug/typo log file from /log --------------- */
rmbug(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if(str) return;
  command("rm /log/"+this_player()->query_real_name()+".rep", this_player());
  write("The bug/typo log file has been deleted.\n");
  return 1;
}

/* --------------- Clone objects (even if you're invisible) --------------- */
rclone(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if(!str) { write("Use: rgoin <object>\n"); return 1; }
  obj = find_ob(str);
  if(!obj) { Fail(str); return 1; }
  return_room_str=file_name(environment(this_player()));
  move_object(this_player(),obj);
  write("Ok.\n");
  return 1;
}

/* --------------- Clean (destruct) objects from a location --------------- */
rclean(where) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (where && where=="me") where="nooneelse";
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if(!str) { write("Use: rreset <object>\n"); return 1; }
  obj = find_ob(str);
  if(!obj) { write("No such object: '" + str + "'.\n"); return 1; }
  call_other(obj,"reset",1);
  say(capitalize(this_player()->query_real_name())+
      " utters an ancient spell of unknown origin.\n");
  say("The plastic ring begins to glow brightly.\n");
  write("You reset :\n   ");
  write_ob_and_desc(obj);
  return 1;
}

/* --------------- Find the current location of an object --------------- */
rtrace(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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

/* --------------- Look a room to see it's exits --------------- */
rpeek(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if(!str)
    obj = environment(this_player());
  else
    obj = find_ob(str);
  if(!obj) { Fail(str); return 1; }
  call_other(obj, "long", 0);
  directions=obj->query_dest_dir();
  i = 0;
  no_more=0;
  if (!directions) return 1;
  nbr=sizeof(directions);
  direction=0;
  if (nbr) {
    write("The exit(s):\n");
    while(i < sizeof(directions)) {
      write("room=" + directions[i]);
      i += 1;
      write("   direction=" + directions[i] + "\n");
      i += 1;
    }
  }
  write("\n");
  return 1;
}

/* --------------- Block an exit from the current room --------------- */
rblock(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if(!str) {
    write("Use: rblock <dicrection>\n");
    return 1;
  }
  obj=clone_object("players/nooneelse/obj/roadblock");
  obj->set_direction(str);
  move_object(obj, environment(this_player()));
  return 1;
}

/* --------------- Set min on player --------------- */
rmin(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if(!str || sscanf(str, "%s %s",who, what) != 2) {
    write("Use: rmin <who> <what>\n");
    return 1;
  }
  who_obj = find_ob(who);
  if(!who_obj) {
    write("Can't find that player!\n");
    return 1;
  }
  who_obj->setmin(what);
  write("Their 'min' has been changed.\n");
  return 1;
}

/* --------------- Set mout on player --------------- */
rmout(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if(!str || sscanf(str, "%s %s",who, what) != 2) {
    write("Use: rmout <who> <what>\n");
    return 1;
  }
  who_obj = find_ob(who);
  if(!who_obj) {
    write("Can't find that player!\n");
    return 1;
  }
  who_obj->setmout(what);
  write("Their 'mout' has been changed.\n");
  return 1;
}

/* --------------- Set mmin on player --------------- */
rmmin(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if(!str || sscanf(str, "%s %s",who, what) != 2) {
    write("Use: rmmin <who> <what>\n");
    return 1;
  }
  who_obj = find_ob(who);
  if(!who_obj) {
    write("Can't find that player!\n");
    return 1;
  }
  who_obj->setmmin(what);
  write("Their 'mmin' has been changed.\n");
  return 1;
}

/* --------------- Set mmout on player --------------- */
rmmout(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if(!str || sscanf(str, "%s %s",who, what) != 2) {
    write("Use: rmmout <who> <what>\n");
    return 1;
  }
  who_obj = find_ob(who);
  if(!who_obj) {
    write("Can't find that player!\n");
    return 1;
  }
  who_obj->setmmout(what);
  write("Their 'mmout' has been changed.\n");
  return 1;
}

/* --------------- Make a player visible --------------- */
rvis(who) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  who_obj=find_ob(who);
  if (!who_obj) {
    write("Can't find "+who+"!\n");
    return 1;
  }
/*
  who_obj->vis();
*/
  command("visible", who_obj);
  write("They're visible now.\n");
  return 1;
}

/* --------------- Make a player invisible --------------- */
rinvis(who) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;

  if (!who) who="nooneelse";
  who_obj=find_ob(who);
  if (!who_obj) {
    write("Can't find "+who+"!\n");
    return 1;
  }
/*
  who_obj->invis();
*/
  command("invisible", who_obj);
  if (who=="nooneelse")
    write("You're invisible now.\n");
  else
    write("They're invisible now.\n");
  return 1;
}

/* --------------- Follow a player (toggle on/off) --------------- */
rfollow(who){
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
rmoney(arg) {
  int n;
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (!arg) arg=50000;
  sscanf(arg, "%d", n);
  if (!n) n=50000;
  obj2=clone_object("/obj/money");
  obj2->set_money(n);
  move_object(obj2, environment(this_player()));
  return 1;
}

/* --------------- Get/lose weight --------------- */
rweight(n) {
  int o;
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  sscanf(n, "%d", o);
  this_player()->add_weight(o);
  return 1;
}

/* --------------- Stop the fighting --------------- */
rstop(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  obj=clone_object("players/nooneelse/obj/gnat");
  move_object(obj, environment(environment(this_object())));
  command("capture gnat", this_player());
  write("\nYou now have a gnat to bug a room with.\n\n");
  return 1;
}

/* --------------- Heal someone/thing some --------------- */
rheal(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (!str) {
    write("Use: rheal <who> <amount>\n");
    return 1;
  }
  str=str+" 0";
  sscanf(str, "%s %d", who, nbr);
  if (!nbr) nbr=100000;
  if (who=="me") who="nooneelse";
  ob = find_living(who);
  if (!ob) {
    write(who+" isn't playing right now.\n");
    return 1;
  }
  call_other(ob, "heal_self", nbr);
  tell_object(ob, "You are healed by "+
              capitalize(this_player()->query_real_name())+".\n");
  return 1;
}

/* --------------- show guild --------------- */
rguild(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (!str) {
    write("Use: rguild <who> to see <who>'s guild & guild exp\n");
    return 1;
  }
  who_obj=find_living(str);
  if (who_obj) {
    write(capitalize(str)+"'s guild info:\n");
    write("     guild items & names: ");
    list_all_guild_items(who_obj);
    write("\n                          ");
    list_all_guilds(who_obj);
  write("\n");
    write("\n");
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
  if (str=="me") str="nooneelse";
  directory="/players/"+str;
  scd_who=str;
  write("Directory now set to "+directory+"\n\n\n");
  if (str!="nooneelse")
    write(">>>   Remember to use 'file <msg>' to tell 'em "+
          "what you did!   <<<\n");
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
  string tmp_dir;
  if (str=="keep") str="closed/keep";
  if (str=="magic_shop") str="closed/magic_shop";
  if (str=="lib") str="black/lib";
  if (str=="a") str="Alchemist";
  if (str=="al") str="Alchemist/lib";
  if (str=="ah") str="Alchemist/hlp";
  if (str=="ao") str="Alchemist/obj";
  if (str=="am") str="Alchemist/mon";
  if (str=="ar") str="Alchemist/room";
  if (str=="amem") str="Alchemist/member";
  if (str=="apro") str="Alchemist/prohibit";
  if (str=="safes") str="black/safes";
  if (str=="hlp") str="black/hlp";
  else
    tmp_dir=directory;
  if (str)
    str2=directory+"/"+str;
  else
    str2=tmp_dir;
  write("Connecting to "+str2+"\n");
  command("cd "+str2, this_player());
  return 1;
}

/* write log entry */
log_work(str) {
  string str2, str3;

  if (!str) {
    write("use: write <log/note>\n");
    return 1;
  }
  if (sscanf(str, "log %s", str2)==1) {
    str3="log";
  }
  else {
    if (sscanf(str, "note %s", str2)==1) {
      str3="note";
    }
    else {
      write("use: write <log/note>\n");
      return 1;
    }
  }
  if (str3=="log") {
    write_file("/players/nooneelse/WORK_REPORT",ctime()+" ** "+str+"\n");
    write("Logged.\n");
  }
  if (str3=="note") {
    write_file("/players/nooneelse/NOTES",ctime()+" ** "+str+"\n");
    write("Noted.\n");
  }
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
  write("\n=====> Wizard's log of work done in your area:\n");
  command("cat /players/"+scd_who+"/WORK_REPORT", this_player());
  return 1;
}

/*  doodad command - show where it's set to */
pwd() {
  write("pwd:  "+directory+"\n");
  return 1;
}

/* --------------- echo to all players --------------- */
echo_all(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (!str) {
    write("Use: echoall <msg>\n");
    return 1;
  }
  shout(str + "\n");
  write("You echo_all: " + str + "\n");
  return 1;
}

/* -------- tell someone something even when invisbile -------- */
tell(str) {
  if (lower_case(this_player()->query_real_name()) != "nooneelse") return 0;
  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Use: tell <who> <msg>\n");
    return 1;
  }
  obj=find_living(lower_case(who));
  if (!obj) {
    write("No player with that name.\n");
    return 1;
  }
  tell_object(obj, "Nooneelse tells you: "+msg+"\n");
  write("You tell "+capitalize(who)+": "+msg+"\n");
  return 1;
}

/* --------------- echo to local area --------------- */
echo(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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

/* tell someone with color */
rtell(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Use: rtell <who> <msg>\n");
    return 1;
  }
  obj=find_living(lower_case(who));
  if (!obj) {
    write("No player with that name.\n");
    return 1;
  }
  tell_object(obj, NORM+CYN+"Nooneelse tells you: "+msg+"\n"+NORM);
  write(NORM+CYN+"You rtell "+capitalize(who)+": "+msg+"\n"+NORM);
  return 1;
}

/* echo to someone with color */
recho(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Use: recho <who> <msg>\n");
    return 1;
  }
  obj=find_living(lower_case(who));
  if (!obj) {
    write("No player with that name.\n");
    return 1;
  }
  msg=msg+"\n";
  tell_object(obj, NORM+CYN+msg+NORM);
  write(NORM+CYN+"You recho: "+msg+" to "+who+"\n"+NORM);
  return 1;
}

/* --------------- zap command --------------- */
zap_them(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
  if (!str) {
    write("Use: zap <who> <damage>\n");
    return 1;
  }
  str=str+" 10000";
  sscanf(str, "%s %d", who, damage);
  who_obj=present(who, environment(this_player()));
  if (!who_obj || !damage) {
    write("Zap who?\n");
    return 1;
  }
  if (!damage) {
    write("Zap "+who+"for how much?\n");
    return 1;
  }
  if(who_obj == this_object()) {
    write("What?? Zap yourself??\n");
    return 1;
  }
  write("You zap "+who+" for "+damage+" points of damage.\n");
  who_obj->hit_player(damage);
  return 1;
}

/* --------------- demote a player --------------- */
rdemote(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;

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
  if(who_obj->query_level() >= WIZARD_LEVEL) {
/* me */
    if(this_player()->query_real_name() == "nooneelse") {
      who_obj->modify_wiz_level(new_level);
      command("save", who_obj);
      write(capitalize(who) + " demoted to level " + new_level + ".\n");
      tell_object(who_obj,
                  "You have been demoted to level " + new_level + ".\n");
      return 1;
    }
/* other wizards */
    if(this_player()->query_level() >= WIZARD_LEVEL) {
      who_obj->modify_wiz_level(new_level);
      command("save", who_obj);
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
/* --------------- (why is this in here too?) --------------- */
rpromote(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;

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
  if(who_obj->query_level() >= WIZARD_LEVEL) {
    if(this_player()->query_real_name() == "nooneelse") {
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

/* --------------- execute a command at <player's> location --------------- */
rat(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;

  if (!str || sscanf(str, "%s %s", who, do_str)!=2) {
    write("Use: at <player> <command>\n");
    return 1;
  }
  who_obj = find_player(who);
  if (!who_obj) {
    write("I can't find that player\n");
    return 1;
  }
  return_room_obj = environment(this_player());
  move_object(this_player(), environment(who_obj));
  command(do_str, this_player());
  move_object(this_player(), return_room_obj);
  write("OK.\n");
  return 1;
}

/* --------------- send a shout curse to someone --------------- */
rquiet(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;

  if (!str) {
    write("Use: rquiet <player>\n");
    return 1;
  }
  who_obj = find_player(str);
  if (!who_obj) {
    write("I can't find that player\n");
    return 1;
  }
  obj = clone_object("obj/shout_curse");
  obj->start(who_obj);
  write("OK.\n");
  return 1;
}

/* --------------- the force command --------------- */
force(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;

  if (!str)
    write("Use: force <who> <what>\n");
  else {
    sscanf(str, "%s %s", who, do_str);
    who_obj=find_living(who);
    command(do_str, who_obj);
  }
  return 1;
}

/* --------------- imprison a player --------------- */
rprison(arg) {
  string who, why;

  if (this_player()->query_level()<WIZARD_LEVEL) return;
  sscanf(arg, "%s %s", who, why);
  who_obj = find_living(who);
  if(!who_obj) {
    write(who+" is not in the game.\n");
    return 1;
  }
  command("imprison "+arg, this_player());
  write("You send "+who+" to prison because: "+why+"\n");
  return 1;
}

/* ----------------  free a player from prison -------------- */
rrelease(arg) {
  string who, why;

  if (this_player()->query_level()<WIZARD_LEVEL) return;
  sscanf(arg, "%s %s", who, why);
  who_obj = find_living(who);
  if(!who_obj) {
    write(who+" is not in the game.\n");
    return 1;
  }
  command("free "+arg, this_player());
  write("You free "+who+" from prison because: "+why+"\n");
  return 1;
}


/* --------------- fix my title/align/hp/etc --------------- */
rfixme() {
  int oldalign,adjust;

  if (this_player()->query_level()<WIZARD_LEVEL) return;
  oldalign = call_other(this_player(),"query_alignment");
  this_player()->set_title(TITLE);
  this_player()->setal(ALIGNTITLE);
  this_player()->heal_self(50000000);
  this_player()->add_intoxination(-50000000);
  if (this_player()->query_frog()) this_player()->frog_curse(0);
  write("Done.\n");
  return 1;
}

/* ----------------- call a function within something --------------------- */
rpatch(str) {
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
                               "/red/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/green/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/yellow/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/blue/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/black/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/sea/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/space/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/klingon/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/joust/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/board/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/closed/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/maze/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/gambling/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/closed/keep/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/closed/magic_shop/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/black/lib/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/black/safes/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/black/hlp/"+str);
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
  if (this_player()->query_level()<WIZARD_LEVEL) return;
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
  int i, j, l;
  object tmp;

  j = sizeof(who);
  if (!arg) arg="l";
  for (l=0; l < j; l++) {
    for (i=l; i < j; i++) {
      if (who[l]->query_level() < who[i]->query_level()) {
        tmp=who[l];
        who[l]=who[i];
        who[i]=tmp;
      }
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
  if (file_size("/players/"+s1+"/obj/"+str+".c") > 0)
    s2="/players/"+s1+"/obj/"+str;
  if (file_size("/players/"+s1+"/mon/"+str+".c") > 0)
    s2="/players/"+s1+"/mon/"+str;
  if (file_size("/players/"+s1+"/red/"+str+".c") > 0)
    s2="/players/"+s1+"/red/"+str;
  if (file_size("/players/"+s1+"/green/"+str+".c") > 0)
    s2="/players/"+s1+"/green/"+str;
  if (file_size("/players/"+s1+"/yellow/"+str+".c") > 0)
    s2="/players/"+s1+"/yellow/"+str;
  if (file_size("/players/"+s1+"/blue/"+str+".c") > 0)
    s2="/players/"+s1+"/blue/"+str;
  if (file_size("/players/"+s1+"/sea/"+str+".c") > 0)
    s2="/players/"+s1+"/sea/"+str;
  if (file_size("/players/"+s1+"/klingon/"+str+".c") > 0)
    s2="/players/"+s1+"/klingon/"+str;
  if (file_size("/players/"+s1+"/joust/"+str+".c") > 0)
    s2="/players/"+s1+"/joust/"+str;
  if (file_size("/players/"+s1+"/board/"+str+".c") > 0)
    s2="/players/"+s1+"/board/"+str;
  if (file_size("/players/"+s1+"/closed/"+str+".c") > 0)
    s2="/players/"+s1+"/closed/"+str;
  if (file_size("/players/"+s1+"/maze/"+str+".c") > 0)
    s2="/players/"+s1+"/maze/"+str;
  if (file_size("/players/"+s1+"/space/"+str+".c") > 0)
    s2="/players/"+s1+"/space/"+str;
  if (file_size("/players/"+s1+"/gambling/"+str+".c") > 0)
    s2="/players/"+s1+"/gambling/"+str;
  return s2;
}

/* get list of guild objects and display names of guilds for 'who' */
load_guild_list() {
  int i;
  string tmp, tmp2, tmp3, tmp4;

  for (i=1; i<21; i++) {
    guild_name[i]=" ";
    guild_display[i]=" ";
    guild_owner[i]=" ";
  }
  i=0;
  tmp="x";
  while (tmp) {
    i++;
    tmp=read_file("/players/nooneelse/closed/guilds.list", i);
    if (tmp=="" || tmp==0)
      tmp=0;
    else {
      sscanf(tmp, "%s#%s#%s\n", tmp2, tmp3, tmp4);
      guild_name[i]=tmp2;
      guild_display[i]=tmp3;
      guild_owner[i]=tmp4;
    }
  }
}

check_guild(arg) {
  int i, found_it;

  if (guild_name[1]!="vampire fangs") load_guild_list();
  found_it=0;
  for (i=1; i<21; i++) {
    if (guild_name[i]==" ") break;
    if (present(guild_name[i], arg)) {
      found_it=1;
      break;
    }
  }
  if (found_it)
    return guild_display[i];
  else
    return " ";
}

list_all_guilds(arg) {
  object obj, next_obj;
  string tmp, tmp1, str1;
  int i, found_one;

  guilds_list="";
  if (guild_name[1]!="vampire fangs") load_guild_list();
  found_one=0;
  for (i=1; i<21; i++) {
    if (guild_name[i]==" ") break;
    if (present(guild_name[i], arg)) {
      write(guild_display[i]+" ");
      guilds_list=guilds_list+guild_display[i]+" ";
      found_one=1;
    }
  }
  if (find_dark_mages(arg)) {
    found_one = 1;
    guilds_list=guilds_list+"{ dark mage  } ";
  }
  if (!found_one) {
    write("{            } ");
    guilds_list="{            } ";
  }
}

find_dark_mages(arg) {
  /*@#@#@#*/
  /* added all this extra shit to show mythos' stupid guild */
  object obj, next_obj;
  string tmp, tmp1, str1;
  int i, found_one;

  if (environment(arg)) {
    str1 = file_name(environment(arg));
    obj = first_inventory(arg);
    while(obj) {
      next_obj = next_inventory(obj);
      str1 = file_name(obj);
      sscanf(str1, "%s#%s", tmp, tmp1);
      if (tmp=="players/mythos/closed/guild/ob") break;
      obj = next_obj;
    }
    if (tmp=="players/mythos/closed/guild/ob") {
      write("{ dark mage  } ");
      return 1;
    }
  }
  return 0;
}


list_all_guild_items(arg) {
  int i, found_one;
  if (guild_name[1]!="vampire fangs") load_guild_list();
  found_one=0;
  guilds_list="";
  for (i=1; i<21; i++) {
    if (guild_name[i]==" ") break;
    if (present(guild_name[i], arg)) {
      write(guild_name[i]+" ");
      guilds_list=guilds_list+guild_name[i]+" ";
      found_one=1;
    }
  }
  if (!found_one) write("{            } ");
}

dump_guild_list() {
  int i;
  if (guild_name[1]!="vampire fangs") load_guild_list();
  write(NORM+CYN+"\tguldob id\t\tdisplay\t\t\towner\n"+NORM);
  for (i=1; i<21; i++) {
    if (guild_name[i]==" ") break;
    write(i+"\t"+guild_name[i]+"\t");
    if (strlen(guild_name[i])<=15) write("\t");
    if (strlen(guild_name[i])<7) write("\t");
    write(guild_display[i]+"\t\t"+guild_owner[i]+"\n");
  }
  return 1;
}

abreviate_room(arg) {
  string abrev_name;
  abrev_name=0;
  sscanf(arg, "players/%s", abrev_name);
  if (!abrev_name) sscanf(arg, "/players/%s", abrev_name);
  if (abrev_name)
    return "~"+abrev_name;
  else
    return arg;
}
