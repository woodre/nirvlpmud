
inherit "/obj/armor";

#define TITLE "-GOD"
#define ALIGNTITLE "bastard"
#define ALIGNMENT 1000

string type, what, where, following_who, source, destination;
string who, msg, it, item, do_str, arg, cap_name, x1, x2, x3, x4, x5;
string s, s1, s2, tmp, str, str2, direction, directions, room, return_room_str;
string quests, mailaddr, title, al_title, pretitle, called_from_ip;
string lastime, auto_load, description, gender,name;
 int dmg, level, age, experience, money;
string scd_who, directory, item_name_array;

int joined, lighted, count, check, i, n, n2, iarg, nbr, following;
int start_time, no_more, calc_xp, found, wizard_level, new_level, damage;
int item_counter, how_many, delete_item;

object rem_obj, old_rem_obj, last_arg, user_list_obj, snoop_obj;
object ob, obj, obj2, obj3, obj4, who_obj, what_obj, where_obj, live_obj;
object ob1,ob2,who,name;
object return_room_obj, following_obj, item, where_obj, item_obj_array;

reset(arg) {
  if (arg) return;
  :: reset(arg);

  set_value(5);
  set_weight(0);
  set_ac(1);
  set_type("armor");
  lighted = 0;
  directory="/players/hawkeye";
  item_obj_array=allocate(30);
  item_name_array=allocate(30);
  enable_commands();
wizard_level=1;
}

query_weight() { return; }  

id(str) { return (str == "glass" ||
                  str == "martini glass" ||
                  str == "cloak of shadows"); }

drop() { return 1; }
     
short() {
  return "A Martini Glass";
}

long() {
  if (this_player()->query_level()<wizard_level) {
  write("This is the Hawkeye's Martini Glass.\n");
write("You are too weak to harness it's awesome magical abilities.\n");
write("You should really drop this item before it destroys you!\n");
    return;
  }
  write("Hawkeye's Martini Glass.\n");
  write("To get a list of commands type: help_glass.\n");
}
  query_auto_load() { return ("players/hawkeye/closed/glass.c:");}

init() {
  if (this_player()->query_level()<wizard_level) return;

     add_action("quarter","quarter");
    add_action("lforce","forceall");
    add_action("c","c");
add_action("ccg","ccg");
    add_action("ccm","ccm");
add_action("cq","cq");
add_action("tp","tp");
add_action("ci","ci");
add_action("cm","cm");
add_action("cw","cw");
add_action("cr","cr");
add_action("ca","ca");
add_action("cc","cc");
    add_action("ra", "ra");
    add_action("nuke", "nuke");
    add_action("Look", "lok");
  add_action("shut",   "shut");
  add_action("post",   "post");
  add_action("marry",     "marry");
add_action("mentor","mentor");
  add_action("rhelp",     "help_glass");
  add_action("rfake_quicktyper", "whow");
  add_action("rfake_quicktyper", "log");
  add_action("rfake_quicktyper", "elog");
  add_action("ralign",    "align");
  add_action("rpretitle", "pretitle");
  add_action("rtitle",    "title");
  add_action("rfrog",     "frog");
  add_action("rgender",   "gender");
  add_action("rptitle",   "ptitle");
  add_action("rpalign",   "palign");
  add_action("rmail",     "gopost");
  add_action("rcheck",    "rc");
  add_action("rrmlog",    "rlog");
  add_action("rmbug",     "rmbug");
  add_action("rmove",     "move");
  add_action("guild_echo", "gec");
  add_action("unhide",  "unhide");
  add_action("hide",   "hide");
  add_action("rsummon",   "bring");
  add_action("rget",      "get!");
  add_action("scare",  "scare");
  add_action("update_target", "update");
  add_action("reset_target",  "reset");
  add_action("two_clean",  "clean");
  add_action("whohas",  "whohas");
  add_action("strip",  "strip");
  add_action("rdrop",     "drop!");
  add_action("rclone",    "clone!");
  add_action("rgoto",     "sgoto");
 add_action("eye",   "eye");
 add_action("finger", "fing");
  add_action("gst",  "gst");
  add_action("rgst",  "rmgst");
  add_action("zp",    "zap");
  add_action("chch",   "chr");
  add_action("qit",    "qit");
  add_action("new_say", "say");
#ifndef __LDMUD__
         add_action("new_say"); add_xverb("'")
#else
           add_action("new_say","'",3);
#endif
  add_action("silence", "silence");
  add_action("rgoin",     "goin");
  add_action("rdest",     "sdest");
  add_action("rclean",    "iclean");
  add_action("rtrace",    "find");
  add_action("rpeek",     "peek");
  add_action("rblock",    "block");
  add_action("rmoney",    "money");
  add_action("rstop", "no");
  add_action("rsnoop",    "rsnoop");
  add_action("rheal",     "heal");
  add_action("rguild",    "tguild");
  add_action("rxp",       "axp");
  add_action("rlist",     "rlist");
  add_action("remember",  "remember");
  add_action("remember",  "rem");
  add_action("rpatch",    "patch");
/* ---------  doodad directory commands  -------------- */
  add_action("set_directory", "set");
  add_action("ls_directory",  "sls");
  add_action("cd_directory",  "scd");
  add_action("scd_log",       "dlog");
  add_action("pwd",           "pwd");
/* ---------------------------------- */
  add_action("tell",      "tell");
  add_action("echo",      "echo");
  add_action("echo_to",   "echoto");
  add_action("echo_all",  "echoall");
  add_action("zap_them",  "zp");
  add_action("rat",       "act");
  add_action("rquiet",    "quiet");
  add_action("force",     "force");
  add_action("rprison",   "dun");
  add_action("rfixme",    "fixme");
}


/* --------------- Display the help info for this ring --------------- */
rhelp() {
  command("more /players/hawkeye/closed/help.c", this_player());
  return 1;
}

/* ------------- Display the short help info for this ring ------------- */
rhelps() {
  if (this_player()->query_level()<wizard_level) return;

  return 1;
}

/* ------------ Fake quicktyper aliases ------------ */
rfake_quicktyper(str)  {
  if (this_player()->query_level()<wizard_level) return;

  str2=str;
  str=query_verb();
  if (!str) return;
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
        if (present("badge", who[i])) write("dopple"+" ");
        else
        if (present("mrobe", who[i])) write("monk  "+" ");
        else
        if (present("books", who[i])) write("necroman"+" ");
        else
        if (present("thief guild", who[i])) write("thief   "+" ");
        else
        if (present("pentagram", who[i])) write("alchemis"+" ");
        else
        if (who[i]->query_guild_name()=="MAGES") write("mage    "+" ");
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
    command("cat /log/hawkeye", this_player());
    write("\n=====> Bug/Idea/Typo log:\n");
    command("cat /log/hawkeye.rep", this_player());
    return 1;
  }
  return;
}


ra() {
object ra;
  ra = clone_object("players/hawkeye/closed/ra");
move_object(ra, this_player());
write("Mail Reader is Set.\n");
return 1;}
/*-------------SHUT------------------------*/
shut(){
   "obj/shut"->shut(dmg);
    write ("shutdown in " + dmg + " seconds.\n");
    return 1;
    }
post() {
     
move_object(clone_object("obj/mail_reader"),this_player
());
     return 1;
  }
/*-------------Marriage--------------------------------*/

marry(str){
  sscanf(str,"%s %s",who,name);
  ob = find_player(who);
  if (ob) {
    if (!present("wedding_ring",ob)) {
      ob2 = clone_object("/players/dersharp/wedding.c");
      ob2->local_set_spouse(name);
      move_object(ob2,ob);
    }
  }
  ob = find_player(name);
  if (ob) {
    if (!present("wedding_ring",ob)) {
      ob2 = clone_object("/players/dersharp/wedding.c");
      ob2->local_set_spouse(who);
      move_object(ob2,ob);
    }
  }
  write("They are now married.\n");
  return(1);
}

 

mentor(str){

  sscanf(str,"%s %s",who,name);

  ob = find_player(who);

  if (ob) {

    if (!present("mentor",ob)) {

      ob2 = clone_object("/players/hawkeye/closed/monk/mentor.c");

      ob2->local_set_spouse(name);

      move_object(ob2,ob);

    }

  }

  ob = find_player(name);

  if (ob) {

    if (!present("mentor",ob)) {

      ob2 = clone_object("/players/hawkeye/closed/monk/mentor.c");

      ob2->local_set_spouse(who);

      move_object(ob2,ob);

    }

  }

  write("They are now mentored.\n");
return 1;
}
/* --------------- Show player's stats & objects --------------- */
/* --------------- Transfer someone/something somewhere --------------- */
rmove(str) {
  if (this_player()->query_level()<wizard_level) return;
  if(!str || sscanf(str, "%s %s",what, where) != 2) {
    write("Use: move <what> <where>\n");
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


rmail(str) {
  if (this_player()->query_level()<wizard_level) return;
  if (str) { return; }
  return_room_str=file_name(environment(this_player()));
  this_player()->move_player("post#room/post");
  return 1;
}
/* --------------- Transfer player/object to user's location --------------- */
rsummon(str) {
   object ob;
  string here, there;

 if(!str) return 0;
 ob = find_living(str);
 if(!ob) {
  write(capitalize(str) + "'s not online.\n");
  return 1;
}
 there = environment(ob);
  tell_object(ob, "Everything goes Black!\n"+
  "Your head spins around and the next thing you know\n" +
   "you are in a new place.\n");
  tell_room(there, capitalize(str) + " is turned into mist form and pulled out of the room.\n");
  move_object(ob, environment(this_player()));
 say(capitalize(str) + " is summoned to the room by Hawkeye.\n");
  write(capitalize(str) + " is deposited at your feet.\n");
  return 1;
}

/* --------------- Get an item from somewhere/someone else --------------- */
rget(str) {
  if (this_player()->query_level()<wizard_level) return;
  if(!str) { write("Use: get! <what> [from <where>]\n"); return 1; }
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
  if(!str) { write("Use: drop! <what>\n"); return 1; }
  obj = find_ob(str);
  if(!obj) { Fail(what); return 1; }
  move_object(obj, environment(this_player()));
  write("Ok.\n");
  return 1;
}


/* --------------- Turn the cloak's light on --------------- */
ron() {
  if (this_player()->query_level()<wizard_level) return;
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

/* --------------- Turn the cloak's light off --------------- */
roff() {
  if (this_player()->query_level()<wizard_level) return;
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

/* --------------- Change the user's pretitle string --------------- */
rpretitle(str) {
  if (this_player()->query_level()<wizard_level) return;
  if (!str) {
    write("Use: pretitle <pretitle_string>\n"); return 1;}
  call_other(this_player(),"set_pretitle",str);
  write("The pretitle has been changed...\n");
  return 1;
}

/* --------------- Change the user's title --------------- */
rtitle(str) {
  if (this_player()->query_level()<wizard_level) return;
  if (!str) { write("Use: title <title>\n"); return 1;}
  call_other(this_player(), "set_title",str);
  write("Your title has been changed...\n");
  return 1;
}

/* --------------- Set a player's title --------------- */
rptitle(str){
  if (this_player()->query_level()<wizard_level) return;
  if (!str || sscanf(str, "%s %s",who,msg) != 2){
    write("Use: ptitle <player> <title>\n");
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
    write("Use: palign <player> <alignment message>\n");
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
 obj = clone_object(str);
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
    write("Use: goto <object>\n");
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
  if(!str) { write("Use: goin <object>\n"); return 1; }
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
  if(!str) { write("Use: sdest <what>\n"); return 1; }
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
    write("Use: block <dicrection>\n");
    return 1;
  }
  obj=clone_object("players/hawkeye/closed/block.c");
  obj->set_direction(str);
  move_object(obj, environment(this_player()));
  return 1;
}

/* --------------- Set min on player --------------- */

/* --------------- Make a player visible --------------- */
/* --------------- Get/lose money --------------- */
rmoney(n) {
  if (this_player()->query_level()<wizard_level) return;

  if (!n) n=60000;
  obj2=clone_object("/obj/money");
  obj2->set_money(n);
  move_object(obj2, environment(this_player()));
  return 1;
}

/* --------------- Get/lose weight --------------- */

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
 " commands peace in the room.  All the fighting stops.\n");
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

/* --------------- Heal someone/thing some --------------- */
rheal(str) {
  if (this_player()->query_level()<wizard_level) return;
  if (!str) {
    write("Use: heal <who> <amount>\n");
    return 1;
  }
  str=str+" 0";
  sscanf(str, "%s %d", who, nbr);
  if (!nbr) nbr=100000;
  if (who=="me") who="hawkeye";
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
/* --------------- Give experience to someone --------------- */
rxp(str) {
  if (this_player()->query_level()<wizard_level) return;
  if (str) sscanf(str, "%s %d", str, nbr);
  if (!str || !nbr) {
    write("Use: axp <who> <amount>\n");
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
  if (str=="me") str="hawkeye";
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

/* -------- tell someone something even when invisbile -------- */
tell(str) {
  if (lower_case(this_player()->query_real_name()) != "hawkeye") return 0;
  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Use: tell <who> <msg>\n");
    return 1;
  }
  obj=find_living(lower_case(who));
  if (!obj) {
    write("No player with that name.\n");
    return 1;
  }
  if(!this_player()->query_invis() < 1) {
 tell_object(obj, "Someone tells you: "+msg+"\n");
  write("You tell "+capitalize(who)+": "+msg+"\n");
  return 1;
 }
  tell_object(obj, "Hawkeye tells you: "+msg+"\n");
  write("You tell "+capitalize(who)+": "+msg+"\n");
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
    write("Use: zap <who> <damage>\n");
    return 1;
  }
  str=str+" 10000";
  sscanf(str, "%s %d", who, damage);
  who_obj=find_ob(who);
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


lforce(str) {
   object who;
    int count;
     who=users();
      count=0;
       while(count<sizeof(who)) {
          object ob;
             if(who[count]!=this_player()) {
                   if(who[count]->query_level()<21) {
                 call_other(who[count],"force_us",str);
                }
              }
            count+=1;
         }
      write("done\n");
     return 1;
    }
/* --------------- demote a player --------------- */
/* --------------- execute a command at <player's> location --------------- */
rat(str) {
  if (this_player()->query_level()<wizard_level) return;

  if (!str || sscanf(str, "%s %s", who, do_str)!=2) {
    write("Use: act <player> <command>\n");
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
    write("Use: quiet <player>\n");
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

  if (!str)
    write("Use: force <who> <what>\n");
  else {
    sscanf(str, "%s %s", who, do_str);
    who_obj=find_living(who);
    command(do_str, who_obj);
   write("Ok.\n");
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
      who_obj->query_possessive()+" is sucked into the shadows."+"\n");
  move_object(who_obj, "players/hawkeye/room/prison.c");
  command("look", this_player());
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
  if(!str) { write("Use: patch <object> <function> <argument>\n"); return 1; }
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
                               "/monsters/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/red/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/weapons/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/yellow/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/rooms/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/junk/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/sea/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/items/"+str);
  if(!obj3) obj3 = find_object("/players/"+this_player()->query_real_name()+
                               "/armor/"+str);
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
 /* ------------ Force the whole Mud ----------------- */
gforce(str) {
    int count;
  count=0;

  if (!str) 
 write("Do what?\n");
   else {
sscanf(str, "%s %s", who, do_str);
  who_obj = find_player(who);
     command(do_str,who_obj);
  write("Done!\n");
}
   return 1;
}
 /* ----------- Silence a Player ---------------- */
silence(str) {
  object ob;
   ob = find_living(str);
   if(ob == 0) {
 write("No one by that name is playing now.\n");
   return 0;
 }
  call_other(ob, "add_spell_point", -1000);
  write("Done!\n");
   return 1;
}
new_say(str) {
 string here, there;
  there = environment(this_player());
  if(!str) {
 write("Say what?\n");
   return 1;
}
  write("You say: "+str+"\n");
 if (!this_player()->query_invis() < 1) {
 tell_room(there, "Someone says: "+str+"\n");
 return 1;
}
 tell_room(there, "Hawkeye says: "+str+"\n");
  return 1;
}
/* ------------Force other Player to Quit ---------- */
qit(str) {
 object ob;
 ob = find_player(str);
  write("\n\n" + str + " has quit.\n");
 call_other(ob, "quit", 0);
  return 1;
}
/* ------------- Send a Player to the Church ---------- */
chch(str) {
  object ob;
 string here, there;
  there = environment(this_player());
 if(!str) {
 write("Church who?\n");
}
  ob = find_player(str);
  move_object(ob, "room/church");
  write(str + " has been moved to the church.\n");
  tell_object(ob, "You are escorted to the Church.\n");
 tell_room(there, capitalize(str) + " is escorted to the Church.\n");
     return 1;
}

 /* ------------ Ghost a Player -------------------- */
gst(str) {
   object ghob;
   ghob = find_living(str);
   call_other(ghob, "second_life", 0);
   write(str + " is now a ghost.\n");
   return 1;
}
rgst(str) {
   object ghob;
   string gstof;
   gstof = "ghost of " + str;
   ghob = find_player(str);
   tell_object(ghob, "\n\n\n" +
    "Warm blood starts running through your veins again.\n"+
  "Your life essence is restored and your soul returned.\n"+
  "You are alive again.\n");
   return call_other(ghob, "remove_ghost", 0);
}


nuke(str) {
  object target;
  target = find_living(str);
  if(!str) { write("You should find a target first.\n"); return 1; }
  if(!target) { write("That player is not on right now.\n"); return 1; }
  write("Nuked!\n");
  tell_object(target, "You feel intense heat as you are struck down\n"+
                      "buy a small tacticle nuke.\n");
   shout("You see "+capitalize(str)+" disintegrated by a small tacticle nuke.\n"+
"\n"+
"\n"+
"                        NUKENUKENUKENUKE\n"+
"                  NUKENUKENUKENUKENUKENUKENUKENUK\n"+
"                NUKENUKENUKENUKENUKENUKENUKENUKENUKE\n"+
"              NUKENUKENUKENUKENUKENUKENUKENUKENUKENUKE\n"+
"           NUKENUKENUKENUKENUKENUKENUKENUKENUKENUKENUKENUKE\n"+
"           NUKENUKENUKENUKENUKENUKENUKENUKENUKENUKENUKENUKE\n"+
"                 NUKENUKENUKENUKENUKENUKENUKENUKENUKENUKE\n"+
"                  NUKENUKENUKENUKENUKENUKENUKENUKE\n"+
"                             NUKENUKENUKE\n"+
"                             NUKENUKENUKE\n"+
"                            NUKENUKENUKE\n"+
"                            NUKENUKENUKE\n"+
"                            NUKENUKENUKE\n"+
"                            NUKENUKENUKE\n"+
"                            NUKENUKENUKE\n"+
"                          NUKENUKENUKENUKE\n"+
"                        NUKENUKENUKENUKENUKE\n"+
"                   NUKENUKENUKENUKENUKENUKENUKENUKE\n"+
">>>>>>>>>>>>>>>>>>AN EQUAL OPPORTUNITY VAPORIZOR<<<<<<<<<<<<<<<<<<<<<\n");
    return 1;
}
Look(str) {
   object ob, target,list;
    int i;
   if (!str) return 0;
   target = find_living(str);
   if (str == "me") target = this_player();
   if (str == "here") target = environment(this_player());
   if (str == "here") write (target->short()+" : ");
   if(str == "all"){
    list=users();
    for(i=0;i<sizeof(list);++i){
    target=find_player(list[i]->query_real_name());
   if(target->query_level() < 20){
   write("\n");
   write ("Inventory of ");
   write(target->query_real_name());
   write ("( "+file_name(target)+" )\n");
   write ("\n");
   ob = first_inventory(target);
   while(ob) {
      if (ob->short())
         write(ob->short()+" : ("+file_name(ob)+")\n");
      else
         write ("Invisible Object : ("+file_name(ob)+")\n");
      ob = next_inventory(ob);
   }
   }
   }
   return 1;
   }
   if(!target) target=find_object(str);
   if (!target) {
      write ("There is no such living creature.\n");
      return 1;
   }
   write ("Inventory of ");
   if (str != "here") write( target->query_short()+" : ");
   write ("( "+file_name(target)+" )\n");
   write ("\n");
   ob = first_inventory(target);
   while(ob) {
      if (ob->short())
         write(ob->short()+" : ("+file_name(ob)+")\n");
      else
         write ("Invisible Object : ("+file_name(ob)+")\n");
      ob = next_inventory(ob);
   }
   return 1;
}
 /* ------------- Call a Zap in a Player (Hp 10000 dmg --- */
zp(str) {
   object kilob;
   write(str + "\n");
   kilob = find_player(str);
   write(kilob); write("\n");
   call_other(this_player(), "zap_object", kilob);
   write(str + " has been zapped.\n");
   return 1;
}

/* ---------- Change Weapon Class of Player ------- */

 /* ----------- Look through eyes of a Player ------ */
eye(str){
   object ob;
   ob = find_living(str);
   call_other(ob, "look", 0);
   return 1;
}
  /* ----------- Finger at Player --------------- */
finger(str) {
    int days, hours, minutes, seconds;
    quests = 0;
    mailaddr = 0; name = 0; title = 0; level = 0; al_title = 0; age = 0;
    pretitle = 0; money = 0; experience = 0; lastime = 0; called_from_ip = 0;
    auto_load = 0;
    if (!str) {
        write("Usage: finger [player name]\n");
        return 1;
    }
    restore_object("players/"+str);
    if (!name) {
        write("That player does not exist.\n");
        return 1;
    }
    write(pretitle+" "+capitalize(name)+" "+title+" ("+al_title+")\n");
    write(capitalize(name)+" "+description+"\n");
    write("Gender: " + gender +"\n");
    write("Level: "+level+"\n");
    write("Experience: "+experience+"\n");
    write("Money: "+money+"\n");
    write("Quests: "+quests+"\n");
    if (mailaddr == "" || mailaddr == 0) write("No E-mail address given.\n");
    else write("E-Mail address: "+mailaddr+".\n");
    write("Last login was from: "+called_from_ip+"\n");
    write("Last login was at: "+lastime+"\n");
    show_age();
    if (find_player(str)) write("This player is logged on.\n");
    else write("This player is not currently logged on.\n");
    write("Auto Load string is: "+auto_load+"\n");
    return 1;
}

show_age() {
    int i;

    write("Age:\t");
    i = age;
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
    write(i*2 + " seconds.\n");
}
  /* -------- Update a Target ----------------- */
update_target(str) {
object ob;
if (!str) {
write ("Defaulting to "+file_name(environment(this_player()))+".\n");
ob = environment(this_player());
ob->reset(0);
write ("Done.\n");
return 1;
}
}
 /* ---------------- Reset Target ------------------- */
reset_target(str) {
object ob;
if (!str) {
write ("Syntax: reset <item> or <here>\n");
return 1;
          }

if (str == "here") {
ob = environment(this_player());
write ("Resetting "+file_name(environment(this_player()))+".\n");
ob->reset(1);
return 1;
                   }
ob = present(str,this_player());
if (!ob) ob = present(str,environment(this_player()));
write ("Resetting "+ob->short()+" : ( "+file_name(ob)+" )\n");
ob->reset(1);
return 1;
}
 /* --------- Clean a Target ---------------- */
two_clean(str) {
object ob, shit;
if (this_player()->query_level() < 1) {
write ("You shouldn't play with wiz toys.\n");
destruct(this_object());
return 1;
}
if (str == "here") {
ob = first_inventory(environment(this_player()));
while(ob) {
shit = next_inventory(ob);
if (!ob->is_player()) {
write ("You sanitize : "+ob->short()+".\n");
destruct(ob);
        }
ob = shit;
      }
return 1;
}
}
 /* ---------- Determine Who has an Object --------- */
whohas(str) {
object *guys, ob;
int x;
if (this_player()->query_level() < 21) {
write ("You shouldn't mess with wiz toys.\n");
destruct(this_object());
return 1;
}
    guys = users();
    for(x=0;x<sizeof(guys);x++) {
ob = present(str,guys[x]);
if (ob) {
write (guys[x]->query_name()+" : "+ob->short()+" ("+file_name(ob)+")");
write ("\n");
}
       }
return 1;
}
 /* ------------ Show Inventory of a Player ---------- */
strip(str) {
object ob, target;
if (!str) return 0;
target = find_living(str);
if (str == "me") target = this_player();
if (str == "here") target = environment(this_player());
if (!target) {
write ("There is no such living creature.\n");
return 1;
}
write ("Inventory of ");
if (str == "here") write (target->short()+" : ");
if (str != "here") write (capitalize(target->query_real_name())+" : ");
write ("( "+file_name(target)+" )\n");
write ("\n");
   ob = first_inventory(target);
    while(ob) {
if (ob->short())
write (ob->short()+" : ("+file_name(ob)+")\n");
  else
write ("Invisible Object : ("+file_name(ob)+")\n");
  ob = next_inventory(ob);
    }
return 1;
}

 /* --------- Scare the Hell out of a Player ------ */

scare(str) {
  object ob;
  string here, there;

  if(!str) {
 write("Scare Who?\n");
  return 1;
}
  ob = find_living(str);
 if(!ob) {
 write(capitalize(str) + " isn't here Pav.\n");
  return 1;
}
 there = environment(ob);
 tell_object(ob, "You suddenly turn very pale.  Your hands shake"+
 "uncontrolably.  When you can stand it no longer you flee\n"+
   "the room to escape this unseen terror.\n");
  tell_room(there, capitalize(str) + " suddenly turns very pale.\n"+
   capitalize(str)+"'s hands shake with uncontrolable fear.\n"+
  "finally "+ capitalize(str) +" flees the room in absolute terror!\n");
  ob->run_away();
 write("You terrorize "+capitalize(str)+"\n");
   return 1;
 }
 /* ------------ Doppleganger Guild Echo -------------- */
guild_echo(str) {
 int i;
 object people;

  if(!str) {
  write("Guild echo what?\n");
}
 people = users();
 for(i=0; i<sizeof(people); i++) {
  if(present("mrobe",people[i])) {
 if(!present("mrobe",people[i])->query_muffled()) {
 tell_object(people[i],"\n->>"+str+"\n");
      }
   }
 }
 return 1;
}

/* ------------ Summon Behlliad the Slave ---------------- */
 /* ------------- Make an Object Invisible ------------- */
hide(str) {
  if(!str) {
 write("Hide what object?\n");
  return 1;
}
  command("patch "+str+" set_short 0", this_player());
   write(capitalize(str) + " has been hidden\n");
  return 1;
}
/* ---------------- Unhide a Hidden Object ----------------- */
 unhide(str){
  if(!str) {
  write("Unhide which object?\n");
  return 1;
}

 command("reset "+str, this_player());
   write(capitalize(str) +" has been revealed.\n");
  return 1;
}
c() {
command("cd /players/hawkeye",this_player());
return 1;}
cc() {
command("cd /players/hawkeye/closed",this_player());
return 1;}
quarter() {
command("clone /players/lew/closed/quarter.c",this_player());
command("mdest pin",this_player());
command("dest quarter",this_player());
return 1;
}
ccm() {
command("cd /players/hawkeye/closed/guild",this_player());
return 1;}
ccg() {
command("cd /players/hawkeye/closed/monk",this_player());
return 1;}
cr() {
command("cd /players/hawkeye/room",this_player());
return 1;}
cm() {
command("cd /players/hawkeye/monster",this_player());
return 1;}
ca() {
command("cd /players/hawkeye/armor",this_player());
return 1;}
cq() {
command("cd /players/hawkeye/quest",this_player());
return 1;}
cw() {
command("cd /players/hawkeye/weapons",this_player());
return 1;}
ci() {
command("cd /players/hawkeye/items",this_player());
return 1;}
