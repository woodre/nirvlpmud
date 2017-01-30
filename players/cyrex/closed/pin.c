/*
nooneelse_ring.c - a general purpose wiz toy [copied for my use :-)] - Cyrex
*/

inherit "/obj/armor";

#define TITLE "the totally confused wizard"
#define ALIGNTITLE "don't ask me"
#define ALIGNMENT 0

string type, what, where, following_who, source, destination;
string who, msg, it, item, do_str, arg, cap_name, x1, x2, x3, x4, x5;
string s, s1, s2, tmp, str, str2, direction, directions, room, return_room_str;

int joined, lighted, count, check, i, n, n2, iarg, nbr, following;
int start_time, no_more, calc_xp, found, wizard_level, new_level, damage;

object rem_obj, old_rem_obj, last_arg, user_list_obj, snoop_obj;
object ob, obj, obj2, obj3, obj4, who_obj, what_obj, where_obj, live_obj;
object return_room_obj;

reset(arg) {
  if (arg) return;
  :: reset(arg);

  set_value(5);
  set_weight(0);
  set_ac(5);
  set_type("misc");
  lighted = 0;
  enable_commands();
  wizard_level=21;
}

query_weight() { return; }  

id(str) { return (str == "ring" ||
                  str == "pin" ||
                  str == "communicator pin" ||
                  str == "plastic ring" ||
                  str == "nooneelse_ring"); }

get() {if(this_player()->query_real_name() == "cyrex") return 1;}
drop() { return 1; }
     
short() {
  if (lighted)
    return "A communicator pin (activated)";
  else
    return "A communicator pin";
}

long() {
  if (this_player()->query_level()<wizard_level) {
    write("This is a wizard's toy, and you can't use it!\n");
    return;
  }
  write("For help do: tap [(taps) for brief help]\n");
  write("The Communicator pin is currently ");
  if (lighted)
      write("activated.\n");
  else
      write("deactivated.\n");
}

init() {
if(this_player()->query_level()<wizard_level) return;

  add_action("hid",         "tap");
  add_action("hids",        "taps");
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
  add_action("rcheck",    "rcheck");
  add_action("rcheck",    "rc");
  add_action("rlog",      "rlog");
  add_action("rrmlog",    "rrmlog");
  add_action("rbug",      "rbug");
  add_action("rmbug",     "rmbug");
   add_action("comlist",   "comlist");
  add_action("comm",      "com");
  add_action("comsend",   "comsend");
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
/* ---------------------------------- */
  add_action("echo",      "echo");
  add_action("echo_to",   "echoto");
  add_action("echo_all",  "echoall");
  add_action("zap_them", "death");
  add_action("rdemote",   "rdemote");
  add_action("rpromote",  "rpromote");
  add_action("rat",       "rat");
  add_action("rquiet",    "rquiet");
  add_action("force",     "force");
  add_action("rprison",   "rprison");
  add_action("code_room", "code");
  add_action("rpat",      "rpat");
  add_action("rfixme",    "rfixme");
}


code_room() {
    object ob;
    string file;
    
    if (!str) ob = environment(this_player());
    else if (!(ob = present(str, this_player())))
       ob = present(str, environment(this_player()));
    if (!ob) {
        write("No such object present.\n");
        return 1;
    }
    file = read_file("/" + base_name(ob) + ".c");
    if (!file) {
       write("Unable to read the file for that.\n");
       return 1;
    }
    this_player()->more(explode(file, "\n"));
    return 1;
}
/* --------------- Display the help info for this ring --------------- */
hid() {
  if (this_player()->query_level()<wizard_level) return;

  command("more /players/cyrex/id.help", this_player());
  return 1;
}

/* ------------- Display the short help info for this ring ------------- */
hids() {
  if (this_player()->query_level()<wizard_level) return;

  command("more /players/cyrex/id.helps", this_player());
  return 1;
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
      if (present("vampire fangs", who[i])) write("vampire "+" ");
       else
      if (present("shadow-mark", who[i])) write("shadow  "+" ");
      else
       if (present("mrobe", who[i])) write("monk    "+" ");
      else
      if (present("seal", who[i])) write("mason   "+" ");
      else
      if (present("license", who[i])) write("assassin"+" ");
      else
      if (present("robes", who[i])) write("cleric  "+" ");
      else
      if (present("books", who[i])) write("necroman"+" ");
      else
      if (present("thief guild", who[i])) write("thief   "+" ");
      else
      if (present("badge", who[i])) write("dopple  "+" ");
      else
      if (present("mages_guild_object", who[i])) write("mages   "+" ");
      else
      if (present("pentagram", who[i])) write("alchemis"+" ");
      else
      write("         ");
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
        if (present("vampire fangs", who[i])) write("vampire "+" ");
        else
        if (present("seal", who[i])) write("mason   "+" ");
        else
        if (present("license", who[i])) write("assassin"+" ");
        else
        if (present("robes", who[i])) write("cleric  "+" ");
        else
        if (present("badge", who[i])) write("dopple  "+" ");
        else
        if (present("books", who[i])) write("necroman"+" ");
        else
        if (present("mages_guild_object", who[i])) write("mages   "+" ");
        else
        if (present("thief guild", who[i])) write("thief   "+" ");
        else
        if (present("pentagram", who[i])) write("alchemis"+" ");
        else
        write("         ");
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
    command("cat /log/cyrex", this_player());
    write("\n=====> Bug/Idea/Typo log:\n");
    command("cat /log/cyrex.rep", this_player());
    return 1;
  }
  return;
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
  if (present("vampire fangs", obj)) write("vampire "+" ");
  else
  if (present("seal", obj)) write("mason   "+" ");
  else
  if (present("badge" , obj)) write("dopple  "+" ");
  else
  if (present("license", obj)) write("assassin"+" ");
  else
  if (present("robes", obj)) write("cleric  "+" ");
  else
  if (present("books", obj)) write("necroman"+" ");
  else
  if (present("thief guild", obj)) write("thief  "+" ");
  else
  if (present("pentagram", obj)) write("alchemis"+" ");
  else
       if (present("shadow-mark", obj)) write("shadow  "+" ");
       else
       if (present("mrobe", obj)) write("monk    "+" ");
       else
  write("         ");
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

/* --------------- Transfer player/object to user's location --------------- */
rsummon(str) {
  if (this_player()->query_level()<wizard_level) return;
  if(!str) { write("Use: rsummon <object>\n"); return 1; }
  obj = find_ob(str);
  if(!obj) obj = clone_object(str);
  if(!obj) { Fail(str); return 1; }
  tell_object(obj,"A huge HAND appears from nowhere, grabs you and throws you elsewhere!\n");
  move_object(obj, environment(this_player()));
  write("Ok.\n");
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

/* --------------- Turn the ring's light on --------------- */
ron() {
  if (this_player()->query_level()<wizard_level) return;
  if (lighted == 0) {
    lighted = 1;
    set_light(9);
    write("Communicator is activated.\n");
  }
  else
    write("The Communicator is already activated!\n");
  write("Current light-strength = " + set_light(0) + "\n");
  return 1;
}

/* --------------- List all that have communicator ---------------- */
comlist(str) {
object ob;
int x;
if(!str) {
ob = users();
write("[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[=[\n");
write("Name:  \tLevel:  \tLocation:\t\n");
write("\n");
for (x = 0; x < sizeof(ob); x++) {
if(present("communicator pin",ob[x])) {
write(ob[x]->query_name() + "\t" + ob[x]->query_level() + "\t" + environment(ob[x])->short() + "\n");
}
}
}
write("]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]=]\n");
return(1);
}
/* --------------- Send Communicator ------------------- */
comsend(str) {
object ob, communicator;
if(!str) {
write("Send to who?\n");
return 1;
}
if(!(ob = find_player(str))) {
write("That person is not on at the moment.\n");
return 1;
}
write("You beamed over a communicator to "+capitalize(str)+".\n");
tell_room(environment(ob),
"A sparkling blue energy beam suddenly appears on "+str+"'s hand...\n" +
"with it, a communicator pin materializes!\n");
tell_object(ob,"A sparkling blue energy beam suddenly appears on your hand...\n"+
"with it, a communicator pin materializes. This pin was from Cyrex.\n");
communicator = clone_object("players/cyrex/cp");
move_object(communicator,ob);
return 1;
}
/* --------------- Communicator line ------------------- */
comm(str) {
string name, message;
object ob;
sscanf(str,"%s %s",name,message);
if(!str) {
write("Usage is: com <player> <message>.\n");
}
if(message==0) {
write("What do you want to communicate?\n");
return 0;
}
ob = find_player( name );
if(ob==0) {
write("Nothing by that name is functioning at this time.\n");
return 1;
}
if(present("communicator pin",ob)) {
write("You tap your communicator.\n");
write("You comtold "+name+" << "+message+" >>\n");
tell_object(ob,"Your communicator *Beeps* insistently.\n");
tell_object(ob,"You tap your communicator.\n");
tell_object(ob,""+name+" here...go ahead.\n");
tell_object(ob,call_other(this_player(),"query_name",0));
tell_object(ob," comtells you ");
tell_object(ob,"<<< "+message+" >>>");
tell_object(ob,"\n");
return 1;
}
if(!present("communicator pin",ob)) {
write("That player doesn't have a communicator.\n");
return 1;
}
return 1;
}
/* --------------- Turn the ring's light off --------------- */
roff() {
  if (this_player()->query_level()<wizard_level) return;
  if (lighted == 1) {
    lighted = 0;
    set_light(-9);
    write("Communicator is deactivated.\n");
  }
  else
    write("The Communicator is already deactivated!\n");
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

/* --------------- Change the user's alignment string --------------- */
ralign(str) {
  if (this_player()->query_level()<wizard_level) return;
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
  if (this_player()->query_level()<wizard_level) return;
  if (!str) {
    write("Use: rpretitle <pretitle_string>\n"); return 1;}
  call_other(this_player(),"set_pretitle",str);
  write("The pretitle has been changed...\n");
  return 1;
}

/* --------------- Change the user's title --------------- */
rtitle(str) {
  if (this_player()->query_level()<wizard_level) return;
  if (!str) { write("Use: rtitle <title>\n"); return 1;}
  call_other(this_player(), "set_title",str);
  write("Your title has been changed...\n");
  return 1;
}

/* --------------- Set a player's title --------------- */
rptitle(str){
  if (this_player()->query_level()<wizard_level) return;
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
  if (this_player()->query_level()<wizard_level) return;
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
rclean(str) {
  if (this_player()->query_level()<wizard_level) return;
  write("Cloning a trasher.\n");
  move_object(clone_object("players/nooneelse/trasher"),
              environment(this_object()));
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
      " utters an ancient spell of unknown origin.\n");
  say("The Id begins to glow brightly.\n");
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

/* --------------- Look a room to see it's exits --------------- */
rpeek(str) {
  if (this_player()->query_level()<wizard_level) return;
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
  if (this_player()->query_level()<wizard_level) return;
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
  if (this_player()->query_level()<wizard_level) return;
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
  if (this_player()->query_level()<wizard_level) return;
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
  if (this_player()->query_level()<wizard_level) return;
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
  if (this_player()->query_level()<wizard_level) return;
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
  if (this_player()->query_level()<wizard_level) return;
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
  if (this_player()->query_level()<wizard_level) return;

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
  obj=clone_object("players/cyrex/closed/gnat");
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
  if (this_player()->query_level()<wizard_level) return;
  if (!str) {
    write("Use: rguild <who> to see <who>'s guild & guild exp\n");
    return 1;
  }
  who_obj=find_living(str);
  if (who_obj) {
    write(capitalize(str)+"'s guild info:\n");
    write("     guild items: ");
    if (present("vampire fangs", who_obj)) write("vampire fangs ");
    if (present("seal", who_obj)) write("mason seal ");
    if (present("license", who_obj)) write("assassin license ");
    if (present("robes", who_obj)) write("cleric robes ");
    if (present("books", who_obj)) write("necromancer books ");
    if (present("thief guild", who_obj)) write("thief ");
    if (present("pentagram", who_obj)) write("alchemist ");
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

/* --------------- zap command --------------- */
zap_them(str) {
  if (this_player()->query_level()<wizard_level) return;
  if (!str) {
    write("Use: death <who> <damage>\n");
    return 1;
  }
  str=str+" 10000";
  sscanf(str, "%s %d", who, damage);
  who_obj=find_ob(who);
  if (!who_obj || !damage) {
    write("Think death upon who?\n");
    return 1;
  }
  if (!damage) {
    write("Think death upon "+who+" to what degree?\n");
    return 1;
  }
  if(who_obj == this_object()) {
    write("What?? think death upon yourself??\n");
    return 1;
  }
  write("You focus inwardly and death overcomes "+who+".\n");
  say("Cyrex focuses inwardly and death overcomes "+who+".\n");
  who_obj->hit_player(damage);
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
    if(this_player()->query_real_name() == "cyrex") {
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
/* --------------- (why is this in here too?) --------------- */
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
  if(who_obj->query_level() >= 26) {
    if(this_player()->query_real_name() == "cyrex") {
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
  if (this_player()->query_level()<wizard_level) return;

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
  if (this_player()->query_level()<wizard_level) return;

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
  if (this_player()->query_level()<wizard_level) return;

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
      who_obj->query_possessive()+" vaporizes into the air."+"\n");
  move_object(who_obj, "players/cyrex/prison");
  write("You have imprisoned "+str+".\n");
  tell_object(who_obj, "You have been transferred somewhere else.\n");
  return 1;
}

/* --------------- pat a player on the head --------------- */
rpat(str) {
  if (this_player()->query_level()<wizard_level) return;

  if (!str) {
    write("Use: pat <player>\n");
    return;
  }

  who_obj = present(str, environment(this_player()));
  if (!who_obj || !living(who_obj) || who_obj == this_player()) return;
  tell_object(who, this_player()->query_name()+" pats you on the head.\n");
  say(this_player()->query_name()+" pats "+str+" on the head.\n", who);
  write("You pat "+str+" on the head.\n");
  return 1;
}

/* --------------- fix my title/align/hp/etc --------------- */
rfixme() {
  int oldalign,adjust;

  if (this_player()->query_level()<wizard_level) return;
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
