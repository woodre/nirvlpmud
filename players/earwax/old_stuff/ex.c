inherit "/obj/armor";

#define TITLE "hates Greenbeans!"
#define ALIGNTITLE "devious"
#define ALIGNMENT 0

string type, what, where, following_who, source, destination;
string who, msg, it, item, do_str, arg, cap_name, x1, x2, x3, x4, x5;
string s, s1, s2, tmp, str, str2, direction, directions, room, return_room_str;
string quests, mailaddr, title, al_title, pretitle, called_from_ip;
string lastime, auto_load, description, gender;
 int dmg, level, age, experience, money;
string scd_who, directory, item_name_array;

int joined, lighted, count, check, i, n, n2, iarg, nbr, following;
int start_time, no_more, calc_xp, found, wizard_level, new_level, damage;
int item_counter, how_many, delete_item;

object rem_obj, old_rem_obj, last_arg, user_list_obj, snoop_obj;
object ob, obj, obj2, obj3, obj4, who_obj, what_obj, where_obj, live_obj;
object return_room_obj, following_obj, item, where_obj, item_obj_array;
  query_auto_load() {
return("players/earwax/closed/ex.c:");
   }
reset(arg) {
  if (arg) return;
  :: reset(arg);

  set_value(5);
  set_weight(0);
  set_ac(1);
  set_type("armor");
  lighted = 0;
  directory="/players/earwax";
  item_obj_array=allocate(30);
  item_name_array=allocate(30);
  enable_commands();
  wizard_level=21;
     set_heart_beat(1);
}

query_weight() { return; }  


id(str) { return (str == "cloak" ||
                  str == "shadow cloak" ||
                  str == "cloak of shadows"); }

drop() { return 1; }
     
short() {
  if (lighted)
  return "The Cloak of Shadows (glowing)";
  else
  return "The Cloak of Shadows";
}

long() {
  if (this_player()->query_level()<wizard_level) {
  write("This is the Cream's magical cloak.\n");
write("You are too weak to harness it's awesome magical abilities.\n");
write("You should really drop this item before it destroys you!\n");
    return;
  }
  write("Cream's magical cloak.  It is covered with powerful runes.\n");
  write("To get a list of commands type: Chelp.\n");
  write("The ring's light is turned ");
  if (lighted)
     write("on.\n");
  else
     write("off.\n");
}

init() {
  if (this_player()->query_level()<wizard_level) return;

  add_action("rhelp",     "chelp");
 add_action("rfake_quicktyper",     "whow");
  add_action("rid",       "iden");
  add_action("ralign",    "align");
  add_action("rpretitle", "pretitle");
  add_action("rtitle",    "title");
  add_action("ron",       "lon");
  add_action("roff",      "loff");
  add_action("rfrog",     "frog");
  add_action("rgender",   "gender");
  add_action("rptitle",   "ptitle");
  add_action("rpalign",   "palign");
  add_action("rmail",     "gopost");
  add_action("rreturn",   "rreturn");
  add_action("anchor_control", "glue");
  add_action("rmove",     "move");
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
  add_action("gst",  "ghst");
  add_action("rgst",  "rmghst");
  add_action("zap",    "zap");
  add_action("chch",   "chch");
  add_action("qit",    "qit");
  add_action("silence", "silence");
  add_action("rgoin",     "goin");
  add_action("rdest",     "sdest");
  add_action("rclean",    "iclean");
  add_action("rtrace",    "trace");
  add_action("rtrace",    "find");
  add_action("rlook",     "atlook");
  add_action("rpeek",     "peek");
  add_action("rblock",    "block");
  add_action("rvis",      "pvis");
  add_action("rmoney",    "money");
  add_action("rstop", "NO");
  add_action("rheal",     "heal");
  add_action("rxp",       "axp");
  add_action("rpatch",    "patch");
  add_action("echo",      "echo");
  add_action("echo_to",   "echoto");
  add_action("echo_all",  "echoall");
  add_action("zap_them",  "zp");
  add_action("rat",       "act");
  add_action("rquiet",    "quiet");
  add_action("force",     "force");
  add_action("rprison",   "dungeon");
  add_action("rfixme",    "fixme");
}


/* --------------- Display the help info for this cloak --------------- */
rhelp() {

  command("more /players/earwax/closed/toy.help", this_player());
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
    command("cat /log/earwax", this_player());
    write("\n=====> Bug/Idea/Typo log:\n");
    command("cat /log/earwax.rep", this_player());
    return 1;
  }
  return;
}

/* --------------- Extended stats on a player/object --------------- */
rid(str)  {
  if (this_player()->query_level()<wizard_level) return;
  write("\n");
  if (!str) { write ("Use: iden <obj_name>\n"); return 1; }
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

/* --------------- Anchor the Staff To You --------------- */
anchor_control(str){   /* anchors this object to you */
   if(!str) return;
   if( str == "on" ){
      set_heart_beat(1);
      return 1;
   }
   if( str == "off" ){
      set_heart_beat(0);
      return 1;
   }
   return 0;
}

heart_beat() {
  object target, me;
   target = this_object();
   me = find_living("earwax");
     if(!me){
     destruct(this_object());
      }
   if( environment(target) !=me ) {
  tell_object(this_player(), "Nice try fuck nuts!\n");
    move_object(target, me);
      tell_object(me, "Your Cloak has Returned.\n");
   }
}
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
    "You are drawn into the shadows.  When next you open\n"+
    "your eyes, you realize you are in a new place.\n");
  tell_room(there, capitalize(str) + " is drawn into the shadows.\n");
  move_object(ob, environment(this_player()));
  say(capitalize(str) + " is deposited at Cream's feet.\n");
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
ralign(str) {
  if (this_player()->query_level()<wizard_level) return;
  if (!str) {
    write("Use: align <al_string>\n");
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

/* --------------- Reset a room --------------- */
rreset(str) {
  if (this_player()->query_level()<wizard_level) return;
  if(!str) { write("Use: rreset <object>\n"); return 1; }
  obj = find_ob(str);
  if(!obj) { write("No such object: '" + str + "'.\n"); return 1; }
  call_other(obj,"reset",1);
  say(capitalize(this_player()->query_real_name())+
  " weaves intricate and powerful runes in the air.\n" +
  "You sense a change in your environment.\n");
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
    write("Use: block <dicrection>\n");
    return 1;
  }
  obj=clone_object("players/pavlik/closed/block.c");
  obj->set_direction(str);
  move_object(obj, environment(this_player()));
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

/* --------------- Get/lose money --------------- */
rmoney(n) {
  if (this_player()->query_level()<wizard_level) return;

  if (!n) n=60000;
  obj2=clone_object("/obj/money");
  obj2->set_money(n);
  move_object(obj2, environment(this_player()));
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
 " commands peace in the room.  All the fighting stops.\n");
  return 1;
}

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
  if (who=="me") who="earwax";
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
   write("Done Deal!\n");
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
  if (this_player()->query_level()<wizard_level) return;

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
  move_object(who_obj, "players/pavlik/rooms/dungeon.c");
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

 /* ----------- Silence a Player ---------------- */
silence(str) {
  object ob;
   ob = find_living(str);
   if(ob == 0) {
 write("Noone by that name is playing now.\n");
   return 0;
 }
  call_other(ob, "add_spell_point", -1000);
  write("Done!\n");
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
   tell_object(ghob, "\n\n" +
  "Your souls has been captured!  The life drains out of your body.\n"+
    "You are a Ghost!\n");
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
 /* ------------- Call a Zap in a Player (Hp 10000 dmg --- */
zap(str) {
   object kilob;
   write(str + "\n");
   kilob = find_player(str);
   write(kilob); write("\n");
   call_other(this_player(), "zap_object", kilob);
   write(str + " has been zapped.\n");
   return 1;
}

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
if (this_player()->query_level() < 21) {
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
 write(capitalize(str) + " isn't here Bags.\n");
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
