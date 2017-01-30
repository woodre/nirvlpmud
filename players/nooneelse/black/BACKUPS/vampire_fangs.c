/* VAMPIRE_FANGS.C */

#define VERSION "666.0.0"
query_version() { return VERSION; }

#define UPDATE "09/01/94"
query_update() { return UPDATE; }

#include "lib/defs.h"

/* this must be in the fangs or they won't work right  */
#undef MY_PLAYER
#define MY_PLAYER  environment(this_object())

#define CHUNK 20
string new_form_desc_stuff, form_description, new_form_description;
string form_owner_name, loginmsg, logoutmsg, last_time;
string following_name, guild_name, guild_display, call_time;
string target_name, hasted_command, more_file, pwd;

object alarm_bat_obj, wolf_obj, new_form_obj, form_obj, mapper_bat_obj;
object following_obj, servant_obj, old_room, vampire_speed_obj;

int hell_fire_pause, in_a_form, in_flight, demon_wrath_pause, glowing_eyes;
int disguise_on, nbr_remembered_rooms, telepathy_on, sanctuary_on, sanctuary_hp;
int monitor_self, old_hp, old_sp, old_intox, old_stuffed;
int sneak_seconds, told_em_i_died, vampire_mist, timer;
int vampire_hasted, haste_counter, more_line;

query_save_flag() { return 1; }

reset(arg) {
  if (arg) return 0;

  mapper_bat_obj = allocate(70);
  guild_name = allocate(21);
  guild_display = allocate(21);
  telepathy_on=1;
  in_flight=0;
  sanctuary_on=0;
  sanctuary_hp=25;
  disguise_on=0;
  demon_wrath_pause=time();
  if (!loginmsg) loginmsg = LOGINMSG;
  if (!logoutmsg) logoutmsg = LOGOUTMSG;
  call_out("fake_hb",5);
  call_out("checks",7);
  timer=1200;
}


checks() {
  object h;
  int j;

  if(environment(this_object())) {
    h = all_inventory(environment(this_object()));
    for(j = 0; j<sizeof(h);j++) {
      if(h[j]->id("nooneelse@vampire@fangs") && h[j] != this_object()) {
        destruct(this_object());
      }
    }
  }
  return 1;
}

extra_look() {
  string return_msg;
  if (MY_PLAYER->query_invis() > 0) return;
  if (!disguise_on)
    return_msg = MY_NAME_CAP+" is wearing a beautiful black silk cloak.\n";
  if (glowing_eyes)
    return_msg = return_msg+
                 capitalize(MY_PLAYER->query_possessive())+
                 " eyes are glowing a deep red.\n";
  if (vampire_mist)
    if (!disguise_on || glowing_eyes)
      return_msg = return_msg+
                   "A deep, blood-red mist surrounds "+MY_NAME_CAP+".\n";
  return return_msg;
}


set_loginmsg(arg) { loginmsg=arg; }
query_loginmsg() { return loginmsg; }

set_logoutmsg(arg) { logoutmsg=arg; }
query_logoutmsg() { return logoutmsg; }

set_call_time(arg) { call_time=arg; }
query_call_time() { return call_time; }

set_last_time(arg) { last_time=arg; }
query_last_time() { return last_time; }

set_form_description(arg) { form_description=arg; }
query_form_description() { return form_description; }

set_new_form_description(arg) { new_form_description=arg; }
query_new_form_description() { return new_form_description; }

set_form_owner_name(arg) { form_owner_name=arg; }
query_form_owner_name() { return form_owner_name; }

set_following_name(arg) { following_name=arg; }
query_following_name() { return following_name; }

set_following_obj(arg) {
  following_obj=arg;
  call_out("follow_someone", 2);
}
query_following_obj() { return following_obj; }

set_guild_name(arg) { guild_name=arg; }
query_guild_name() { return guild_name; }

set_guild_display(arg) { guild_display=arg; }
query_guild_display() { return guild_display; }

set_target_name(arg) { target_name=arg; }
query_target_name() { return target_name; }

set_alarm_bat_obj(arg) { alarm_bat_obj=arg; }
query_alarm_bat_obj() { return alarm_bat_obj; }

set_wolf_obj(arg) { wolf_obj=arg; }
query_wolf_obj() { return wolf_obj; }

set_new_form_obj(arg) { new_form_obj=arg; }
query_new_form_obj() { return new_form_obj; }

set_form_obj(arg) { form_obj=arg; }
query_form_obj() { return form_obj; }

set_mapper_bat_obj(arg, arg2) {
  int i;
  if (!arg || !arg2) return 0;
  i = arg2;
  if (!i) return 0;
  mapper_bat_obj[i]=arg;
}
query_mapper_bat_obj(arg) {
  int i;
  if (!arg) return 0;
  i = arg;
  if (!i) return 0;
  return mapper_bat_obj[i];
}


set_nbr_remembered_rooms(arg,arg2) {
  nbr_remembered_rooms = arg;
  mapper_bat_obj[nbr_remembered_rooms]=arg2;
}
query_nbr_remembered_rooms() { return nbr_remembered_rooms; }

set_servant_obj(arg) { servant_obj=arg; }
query_servant_obj() { return servant_obj; }

set_old_room(arg) { old_room=arg; }
query_old_room() { return old_room; }

set_hell_fire_pause(arg) { hell_fire_pause=arg; }
query_hell_fire_pause() { return hell_fire_pause; }

set_in_a_form(arg) { in_a_form=arg; }
query_in_a_form() { return in_a_form; }

set_in_flight(arg) { in_flight=arg; }
query_in_flight() { return in_flight; }

set_demon_wrath_pause(arg) { demon_wrath_pause=arg; }
query_demon_wrath_pause() { return demon_wrath_pause; }

set_glowing_eyes(arg) {
  if (arg==1 && !glowing_eyes) {
    glowing_eyes=arg;
    set_light(2);
    call_out("dim_eyes", timer);
  }
  if (!arg && glowing_eyes) {
    glowing_eyes=arg;
    set_light(-2);
    remove_call_out("dim_eyes");
    tell_object(MY_PLAYER, "\nYour eyes have stopped glowing.\n");
  }
}
query_glowing_eyes() { return glowing_eyes; }
dim_eyes() {
  glowing_eyes=0;
  set_light(-2);
  set_light(0);
  tell_object(MY_PLAYER, "\nYour eyes have stopped glowing.\n");
}

set_disguise_on(arg) { disguise_on=arg; }
query_disguise_on() { return disguise_on; }

set_telepathy(arg) { telepathy_on = arg; }
query_telepathy() { return telepathy_on; }

set_sanctuary_on(arg) { sanctuary_on=arg; }
query_sanctuary_on() { return sanctuary_on; }

set_sanctuary_hp(arg) { sanctuary_hp=arg; }
query_sanctuary_hp() { return sanctuary_hp; }

set_monitor_self(arg) { monitor_self=arg; }
query_monitor_self() { return monitor_self; }

set_old_hp(arg) { old_hp=arg; }
query_old_hp() { return old_hp; }

set_old_sp(arg) { old_sp=arg; }
query_old_sp() { return old_sp; }

set_old_intox(arg) { old_intox=arg; }
query_old_intox() { return old_intox; }

set_old_stuffed(arg) { old_stuffed=arg; }
query_old_stuffed() { return old_stuffed; }

set_sneak_seconds(arg) { sneak_seconds=arg; }
query_sneak_seconds() { return sneak_seconds; }

set_told_em_i_died(arg) { told_em_i_died=arg; }
query_told_em_i_died() { return told_em_i_died; }

set_vampire_mist(arg) {
  vampire_mist=arg;
  if (vampire_mist) {
    set_light(- 2);
    MY_PLAYER->set_ac((MY_AC)+1);
    MY_PLAYER->set_wc((MY_WC)+1);
    call_out("clear_vampire_mist", timer);
  }
  else {
    set_light(2);
    MY_PLAYER->set_ac((MY_AC)-1);
    MY_PLAYER->set_wc((MY_WC)-1);
    remove_call_out("clear_vampire_mist");
    tell_object(MY_PLAYER, "\nYour vampire's mist has dissolved.\n");
  }
}
query_vampire_mist() { return vampire_mist; }
clear_vampire_mist() {
  vampire_mist=0;
  set_light(2);
  MY_PLAYER->set_ac((MY_AC)-1);
  MY_PLAYER->set_wc((MY_WC)-1);
  tell_object(MY_PLAYER, "\nYour vampire's mist has dissolved.\n");
}

dismiss_a_servant() { servant_obj=0; }

dismiss_a_wolf() { wolf_obj=0; }

/* -------- Forget remembered rooms ---------- */
forget_rooms() {
  int i;
  for (i=0; i < 70; i++) {
    if (mapper_bat_obj[i]) {
      destruct(mapper_bat_obj[i]);
      mapper_bat_obj[i]=0;
    }
  }
  nbr_remembered_rooms=0;
  write("You have cleared your memory of remembered rooms.\n");
  return 1;
}

/* get list of guild objects and display names of guilds for 'who' */
load_guild_list() {
  int i;
  string tmp, tmp2, tmp3;
  for (i=1; i<21; i++) {
    guild_name[i]=" ";
    guild_display[i]=" ";
  }
  i=0;
  tmp="x";
  while (tmp) {
    i++;
    tmp=read_file("/players/nooneelse/black/guilds.list", i);
    if (tmp=="" || tmp==0)
      tmp=0;
    else {
      sscanf(tmp, "%s#%s\n", tmp2, tmp3);
      guild_name[i]=tmp2;
      guild_display[i]=tmp3;
    }
  }
}


check_guild(arg) {
  int i, found_it;
  if (guild_name[1]!="nooneelse vampire fangs") load_guild_list();
  found_it=0;
  for (i=1; i<21; i++) {
    if (guild_name[i]==" ") break;
    if (present(guild_name[i], find_player(arg))) {
      found_it=1;
      break;
    }
  }
  if (found_it)
    return guild_display[i];
  else
    return " ";
}

dump_guild_list() {
  int i;
  if (guild_name[1]!="nooneelse vampire fangs") load_guild_list();
  for (i=1; i<21; i++) {
    write("guild name["+i+"]='"+guild_name[i]+
          "'   guild display["+i+"]='"+guild_display[i]+"'\n");
  }
  return 1;
}

/* tell my room, but not me */
tell_my_room(msg, ignore) {
  string players_here;

  players_here = first_inventory(MY_ROOM);
  while (players_here) {
    if (living(players_here) &&
        !players_here->query_npc() &&
        players_here != MY_PLAYER &&
        players_here->query_real_name() != ignore) {
      tell_object(players_here, msg+"\n");
    }
    players_here=next_inventory(players_here);
  }
  return 1;
}

query_auto_load() { return "/players/nooneelse/black/vampire_fangs.c:"; }

init_arg() {
  last_time = ctime(time());
  write(">>>\n"+
        ">>>\n"+
        ">>> Type 'guild news' to see what's new in the guild.\n"+
        ">>>\n"+
        ">>>\n");
  return 0;
}

get() { return 0; }

drop() { return 1; }

id(str) { return (str=="nooneelse@vampire@fangs" || str=="fangs" ||
                  str=="vampire fangs"); }

short() {
  if ((environment() && environment()==find_player("mythos")) ||
      (this_player() && this_player()==find_player("mythos") &&
      (!environment() || !living(environment()))))
    destruct(this_object());
  return;
}

init() {
  int is_a_vampire;
  if (environment(this_object()) &&
      environment(this_object())->query_real_name()=="mythos") {
    destruct(this_object());
    return 1;
  }
  if (this_player() && this_player()->is_player()) {
    call_other(GUILD_MEMBER, "???");
    is_a_vampire=call_other(GUILD_MEMBER, "query_member",
                                this_player()->query_real_name());
    if (!is_a_vampire &&
        GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER) {
      tell_object(this_player(),
                  "\nYou're not a vampire and can't have fangs!n");
      destruct(this_object());
      return 1;
    }
  }
  if (this_player() && !this_player()->query_guild_name())
    this_player()->set_guild_name("vampire");
  if (this_player() && !this_player()->query_guild_exp())
    this_player()->add_guild_exp(666);
  if (this_player() && this_player()->query_level()>=21) {
    this_player()->add_guild_exp(-this_player()->query_guild_exp());
    this_player()->add_guild_exp(672);
  }


  /*---------------------------------------------------*/
  /*  Commands in vampire_fangs_base                   */
  /*---------------------------------------------------*/
  add_action("alarm_bat",         "msg");
  add_action("assess",            "assess");
  add_action("awaken","awaken");
  add_action("backhand_enemy",    "backhand");
  add_action("backhand_enemyx",    "backhandx");
  add_action("bite_player",       "bite");
  add_action("bury_hole",         "bury");
  add_action("call_wolf",         "call");
  add_action("calm_fighters",     "calm");
  add_action("cancel_summons",    "cancel");
  add_action("charity_item",      "charity", 4);
  add_action("check_player",      "check");
  add_action("create_form",       "mist");
  add_action("create_form",       "bat");
  add_action("create_form",       "wolf");
  add_action("guild_news",        "guild");
  add_action("cure_disease",      "cure");
  add_action("damn",              "damn");
  add_action("defend_me",         "defend");
  add_action("defile_object",     "defile");
  add_action("demon_wrath",       "demon");
  add_action("dig_hole",          "dig");
  add_action("disguise_self",     "disguise");
  add_action("dismiss_bat",       "dismiss");
  add_action("drain_corpse",      "drain");
  add_action("emit_mist",         "emit");
  add_action("emote",             "emote", 3);
  add_action("eyes_light",        "eyes");
  add_action("cause_fear",        "fear");
  add_action("fly_direction",     "fly");
  add_action("forget_rooms",      "forget", 3);
  add_action("forbid_entry",      "forbid");
  add_action("list_guild_tasks",  "tasks", 4);
  add_action("hell_fire",         "hellfire", 4);
  add_action("list_vampires",     "friends", 3);
  add_action("glance",            "glance", 2);
  add_action("go_home",           "gohome", 3);
  add_action("grasp_enemy",       "grasp", 3);
  add_action("grasp_enemyx",       "graspx", 3);
  add_action("show_health",       "health");
  add_action("guild_help",        "help");
  add_action("illusion",          "illusion", 3);
  add_action("infuse",            "infuse");
  add_action("leave_guild",       "leave");
  add_action("loginmsg",          "login");
  add_action("logoutmsg",         "logout");
  add_action("magic_dart",        "magic");
  add_action("paralyze",          "paralyze", 3);
  add_action("process_skins",     "process", 3);
  add_action("punish_vampire",    "punish");
  add_action("regenerate",        "regenerate");
  add_action("remember_rooms",    "remember", 3);
  add_action("rip_throat",        "rip");
  add_action("scan_monster",      "scan");
  add_action("make_servant",      "servant", 3);
  add_action("scratch_enemy",     "scratch", 3);
  add_action("scratch_enemyx",     "scratchx", 3);
  add_action("sew_skins",         "sew");
  add_action("sharpen_fangs",     "sharpen");
  add_action("shift_hp",          "shift");
  add_action("skin_corpse",       "skin");
  add_action("solve_guild_tasks", "solve");
  add_action("sanctuary",         "sanctuary", 3);
  add_action("start_up",          "startup");
  add_action("summon",            "summon");
  add_action("telekenetics",      "telekenetics");
  add_action("telekenetics",      "tk");
  add_action("telepathy",         "telepathy");
  add_action("telepathy",         "te");
  add_action("telepathy",         "tel");
  add_action("telepathyfeel",     "telepathyfeel");
  add_action("telepathyfeel",     "tf");
  add_action("telepathyfeel",     "tfl");
  add_action("telepathyfeel",     "tt");
  add_action("fix_title",         "fix");
  add_action("transfer_item",     "transfer");
  add_action("translate_item",    "translate");
  add_action("vampire_speed",     "vampire");
  add_action("wraith_form",       "wraith");

  /* special versions of standard commands */
  add_action("quit",              "quit");
  add_action("show_score",        "score");
  add_action("show_score",        "sc");
  add_action("show_inven",        "i");
  add_action("show_whov",         "whov");
  add_action("show_player",       "look", 1);
  add_action("show_player",       "examine", 2);
  add_action("spell_missile",     "missile");
  add_action("spell_shock",       "shock");
  add_action("spell_fire_ball",   "fireball");
  add_action("spell_blast",       "blast");

  /* make up some soul actions for use in the forms */
  add_action("nope",              "applaud");
  add_action("nope",              "blush");
  add_action("nope",              "bounce");
  add_action("nope",              "bow");
  add_action("nope",              "burp");
  add_action("nope",              "cackle");
  add_action("nope",              "chuckle");
  add_action("nope",              "clap");
  add_action("nope",              "comfort");
  add_action("nope",              "cough");
  add_action("nope",              "cry");
  add_action("nope",              "cuddle");
  add_action("nope",              "curtsey");
  add_action("nope",              "dance");
  add_action("fart",              "fart");
  add_action("nope",              "flip");
  add_action("nope",              "fondle");
  add_action("nope",              "french");
  add_action("generic",           "frown");
  add_action("nope",              "gasp");
  add_action("nope",              "giggle");
  add_action("generic",           "grin");
  add_action("nope",              "groan");
  add_action("nope",              "grope");
  add_action("generic",           "growl");
  add_action("nope",              "hiccup");
  add_action("nope",              "hug");
  add_action("nope",              "kick");
  add_action("vkiss",             "vkiss");
  add_action("vglare",            "vglare");
  add_action("nope",              "knee");
  add_action("laugh",             "laugh");
  add_action("lick",              "lick");
  add_action("nope",              "love");
  add_action("nope",              "moan");
  add_action("nope",              "nibble");
  add_action("nod",               "nod");
  add_action("nope",              "poke");
  add_action("nope",              "pout");
  add_action("nope",              "puke");
  add_action("nope",              "purr");
  add_action("nope",              "ruffle");
  add_action("nope",              "scream");
  add_action("shake",             "shake");
  add_action("nope",              "shiver");
  add_action("shrug",             "shrug");
  add_action("sigh",              "sigh");
  add_action("nope",              "sing");
  add_action("nope",              "slap");
  add_action("nope",              "smirk");
  add_action("smile",             "smile");
  add_action("nope",              "snap");
  add_action("nope",              "sneeze");
  add_action("nope",              "snicker");
  add_action("sniff",             "sniff");
  add_action("nope",              "snore");
  add_action("nope",              "snuggle");
  add_action("nope",              "spit");
  add_action("nope",              "squeeze");
  add_action("nope",              "stare");
  add_action("nope",              "strut");
  add_action("nope",              "sulk");
  add_action("thank",             "thank");
  add_action("think",             "think", 3);
  add_action("nope",              "twiddle");
  add_action("nope",              "whistle");
  add_action("nope",              "wiggle");
  add_action("nope",              "wink");
  add_action("yawn",              "yawn");

  /*---------------------------------------------------*/
  /* Guild Lieutenants Commands (in vampire_fangs_base)*/
  /*---------------------------------------------------*/
  add_action("repair_exp",        "repair");
  add_action("replace_fangs",     "replace");
  add_action("hop_to_office",     "office");
  add_action("remove_fangs",      "remove");
  add_action("return_from_office","back");

  /*---------------------------------------------------*/
  /*  Guild Assistant Commands (in vampire_fangs_base) */
  /*---------------------------------------------------*/
  add_action("clairaudience",     "clairaudience");
  add_action("clairaudience",     "ca");
  add_action("expell_traitor",    "expell");

  /*---------------------------------------------------*/
  /*  Guild Master Commands (in vampire_fangs_base)    */
  /*---------------------------------------------------*/
  add_action("release_member",    "release");
  add_action("goto_guild",        "vboard");
  add_action("goto_office_board", "oboard");
  add_action("shelf_check",       "shelf");
}


fake_hb() {
  string str, str1, str2;
  string wheree;
  int i;

  /* wizards always have max */
  if (this_player() && this_player()->query_level()>=21) {
    i = MY_PLAYER->query_guild_exp();
    MY_PLAYER->add_guild_exp(-i);
    MY_PLAYER->add_guild_exp(672);
  }

  /* if my player is dead, turn everything off */
  if(environment(this_object())) {
    if (!MY_PLAYER->query_ghost() && told_em_i_died) told_em_i_died=0;
    if (MY_PLAYER->query_ghost() && !told_em_i_died) {
      told_em_i_died=1;
      sanctuary_on=0;
      following_name=0;
      following_obj=0;
      glowing_eyes=0;
      sneak_seconds=0;
      MY_PLAYER->visible();
      monitor_self=0;
    }
  }

  /* is our hp <= the sanctuary level? */
  if(MY_PLAYER) {
    str1 = file_name(MY_ROOM);
    sscanf(str1, "%s.c", str2);
    if (!str2) str2=str1;
    if (str2!=GUILD_SANCTUARY_ROOM) {
      if (sanctuary_on && MY_HIT_POINTS<=sanctuary_hp) {
        if (MY_SPELL_POINTS < 40) {
          tell_object(MY_PLAYER, RED+
                      "\nSANCTUARY WON'T WORK! NOT ENOUGH SP!  RUN!!!\n\n"+NORM);
        }
        else
        if (MY_ROOM->realm()=="NT") {
          tell_object(MY_PLAYER, RED+"\nSANCTUARY WON'T WORK HERE!  RUN!!!\n\n"+NORM);
        }
        else {
  if(wheree = call_other("obj/base_tele","teleport")) {
      MY_PLAYER->move_player("with an astonished look#"+wheree); }
      else {
          tell_my_room(MY_NAME_CAP+" changes into a bat and flys away!");
          call_other(GUILD_SANCTUARY_ROOM, "???", 0);
          move_object(MY_PLAYER, GUILD_SANCTUARY_ROOM);
          tell_object(MY_PLAYER,
              "You alter your form to become a bat and fly to the guild's"+
              " lower hall.\n\n");
          command("look", MY_PLAYER); }
          MY_PLAYER->add_spell_point(-55-random(5));
          sanctuary_on=0;
          tell_object(MY_PLAYER,
                      "\nSanctuary turned OFF until you turn it back on.\n");
        }
      }
    }
  }


  /* are we in a coffin or underground regenerating ourselves? */
  /* (if yes, heal & get sober quicker) */
  if(MY_PLAYER) {
    str1 = file_name(MY_ROOM);
    sscanf(str1, "%s#%s", str2, str);
    if (!str2) str2=str1;
    str2 = "/"+str2;
/*
    if (str2==GUILD_COFFIN || str2==REGENERATE_ROOM) {
*/
/* taken out by order of boltar (till i research it to fix it & petition him about it)
    if (str2==GUILD_COFFIN) {
      if (MY_PLAYER->query_stuffed()>0) MY_PLAYER->add_stuffed(-50);
      if (MY_PLAYER->query_soaked()>0) MY_PLAYER->add_soaked(-50);
      if (MY_PLAYER->query_intoxination()>0) MY_PLAYER->add_intoxination(-50);
    }
*/
/*
    if (str2==REGENERATE_ROOM) {
      if (MY_HIT_POINTS < MY_PLAYER->query_mhp() ||
          MY_SPELL_POINTS < MY_PLAYER->query_msp())
        MY_PLAYER->heal_self(2);
    }
*/
  }
  /* end of heart_beat */

  call_out("fake_hb", 2);
  return 1;
}


/*---------------------------------------------------*/
/* Local Commands                                    */
/*---------------------------------------------------*/

/* 
  more command for showing files. extracted out of
  /closed/wiz_soul for me by boltar
*/
more(str) {
  string tmore;
  string tilda, blah;

  if (!pwd) pwd="";
  if (!str) return 0;
  tmore = str;
  blah = pwd;
  if (extract(blah,0,0)!="/") blah = "/"+blah;
  if (extract(tmore,0,0)=="~") {
    tilda = extract(tmore,1,strlen(tmore));
    tmore = "/players/nooneelse"->query_real_name()+tilda;
  }
  if (extract(tmore,0,0)!="/") tmore = blah+tmore;
  if (file_size(tmore) < 1) {
    write("That file does not exist.\n");
    return 1;
  }
  more_file = str;
  more_line = 1;
  if (cat(more_file, more_line, CHUNK)==0) {
    write("No such file\n");
    return 1;
  }
  input_to("even_more");
  write("More: (line " + (CHUNK + 1) + ") [q=quit] ");
  return 1;
}

even_more(str) {
  if (str == "" || str == "d")
    more_line += CHUNK;
  else if (str == "q") {
    write("Ok.\n");
    return;
  } else if (str == "u") {
    more_line -= CHUNK;
    if (more_line < 1)
      more_line = 1;
  }
  if (cat(more_file, more_line, CHUNK) == 0) {
    more_file = 0;
    write("EOF\n");
    return;
  }
  write("More: (line " + (more_line + CHUNK) + ") [q=quit] ");
  input_to("even_more");
}

/* count the number of valid target critters in the room */
count_critters() {
  int nbr_critters;
  object target_obj, next_target_obj;

  nbr_critters = 0;
  target_obj = first_inventory(MY_ROOM);
  while (target_obj) {
    next_target_obj=next_inventory(target_obj);
    if (target_obj != MY_PLAYER &&
        target_obj->query_npc() &&
        living(target_obj) &&
        !target_obj->am_i_a_servant() &&
        !target_obj->is_kid() &&
        !target_obj->is_pet())
      nbr_critters++;
    target_obj = next_target_obj;
  }
  return nbr_critters;
}

/* dissipate the vampire's alternate forms */
dissipate_form() {
  form_owner_name=0;
  form_description=0;
  in_a_form=0;
  return 1;
}

set_vampire_speed(arg) { vampire_speed_obj=arg; }
query_vampire_speed() { return vampire_speed_obj; }

start_wraith_form() {
  call_out("stop_wraith_form", query_sneak_seconds());
}

stop_wraith_form() {
  if (query_sneak_seconds() > 0) {
    set_sneak_seconds(0);
    if (MY_PLAYER->query_invis() > 0) MY_PLAYER->visible();
    write("You've changed back from wraith form to normal form.\n");
    tell_my_room(MY_NAME_CAP+" slowly fades into view...");
    MY_FANGS->remove_call_out("stop_wraith_form");
  }
}


/* show some of the guild stuff */
show_guild_stuff() {
  write("\nYou are a member of the vampire's guild.  "+
        "\nType 'help guild' to see guild abilities & commands.\n");
  if (sanctuary_on)
    write("Sanctuary ON and set for "+sanctuary_hp+"\n");
  else
    write("Sanctuary OFF and set for "+sanctuary_hp+"\n");
  return 1;
}

/*
  Set login & logout messages (stolen from Sandman's Paladin Guild)
*/
loginmsg(str) {
  if (!str) {
    loginmsg = LOGINMSG;
    write("Login message reset to default.\n");
  }
  else {
    loginmsg = str;
  }
  write("Your login message is now:\n"+
        MY_NAME_CAP+" "+loginmsg+"\n");
  return 1;
}

logoutmsg(str) {
  if (!str) {
    logoutmsg = LOGOUTMSG;
    write("Logout message reset to default.\n");
   }
   else {
     logoutmsg = str;
   }
   write("Your logout message is now:\n"+
         MY_NAME_CAP+" "+logoutmsg+"\n");
   return 1;
}


guild_info() {
  if (sanctuary_on)
    write("Sanctuary ON and set for "+sanctuary_hp+"\n\n");
  else
    write("Sanctuary OFF and set for "+sanctuary_hp+"\n\n");
  if (in_a_form)
    write("You're in a "+form_description+" form\n\n");
  if (glowing_eyes)
    write("Your eyes are glowing\n\n");
  if (disguise_on)
    write("You have the 'disguise' on (the cloak doesn't show "+
          "in your desc)\n\n");
  write("You have "+nbr_remembered_rooms+" rooms remembered\n\n");
  if (telepathy_on)
    write("Your vampire guild ears are ON\n\n");
  else
    write("Your vampire guild ears are OFF\n\n");
  if (sneak_seconds)
    write("You have "+sneak_seconds+" left in your wraith form\n\n");
  write("Guild Messages:\n"+
        "---------------\n"+
        "Login:\t"+loginmsg+"\n"+
        "Logout:\t"+logoutmsg+"\n\n");
   return 1;
}

/* Cutdown version of the sort written by Vaxman */
sort_list_of_players(str) {
  int i, j, sorted;
  object tmp;
  j = sizeof(str);
  sorted = 0;
  while(!sorted) {
    sorted = 1; j--;
      for (i=0; i < j; i++)
        if (str[i]->query_level() < str[i+1]->query_level()) {
          tmp=str[i];
          str[i]=str[i+1];
          str[i+1]=tmp;
          sorted = 0;
        }
   }
   return str;
}

nope() {
  if (!in_a_form) return 0;
  write("You can't do that while in "+form_description+" form.\n");
  return 1;
}

/* --- show the player's health & enemy's health (when they've changed) --- */
display_health() {
  int max_intox, max_stuffed;
  if (MY_HIT_POINTS != query_old_hp() ||
      MY_SPELL_POINTS != query_old_sp() ||
      MY_INTOXICATION != query_old_intox() ||
      MY_STUFFED != query_old_stuffed()) {
    max_intox = MY_LEVEL + 3;
    max_stuffed = MY_LEVEL * 8;
    tell_object(MY_PLAYER, "< Your: hp="+MY_HIT_POINTS+
                           "/"+MY_PLAYER->query_mhp()+
                           "  sp="+MY_SPELL_POINTS+"/"+MY_PLAYER->query_msp()+
                           "  intoxication="+MY_INTOXICATION+"/"+max_intox+
                           "  stuffed="+MY_STUFFED+"/"+max_stuffed+" >\n");
    set_old_hp(MY_HIT_POINTS);
    set_old_sp(MY_SPELL_POINTS);
    set_old_intox(MY_INTOXICATION);
    set_old_stuffed(MY_STUFFED);
  }
  return 1;
}

/*---------------------------------------------------*/
/*  Guild Command (in vampire_fangs_base.c)          */
/*---------------------------------------------------*/
alarm_bat(str) { return VAMPIRE_FANGS_BASE->alarm_bag(str); }
assess(str) { return VAMPIRE_FANGS_BASE->assess(str); }
awaken(str) { return VAMPIRE_FANGS_BASE->awaken(str); }
backhand_enemy(str) { return VAMPIRE_FANGS_BASE->backhand_enemy(str); }
backhand_enemyx(str) { return VAMPIRE_FANGS_BASE->backhand_enemyx(str); }
bite_player(str) { return VAMPIRE_FANGS_BASE->bite_player(str); }
bury_hole(str) { return VAMPIRE_FANGS_BASE->bury_hole(str); }
call_wolf(str) { return VAMPIRE_FANGS_BASE->call_wolf(str); }
calm_fighters(str) { return VAMPIRE_FANGS_BASE->calm_fighters(str); }
cancel_summons(str) { return VAMPIRE_FANGS_BASE->cancel_summons(str); }
charity_item(str) { return VAMPIRE_FANGS_BASE->charity_item(str); }
create_form(str) { return VAMPIRE_FANGS_BASE->create_form(str); }
clairvoyance(str) { return VAMPIRE_FANGS_BASE->clairvoyance(str); }
guild_news(str) {
  if(str == "info") { guild_info(); return 1; }
  return VAMPIRE_FANGS_BASE->guild_news(str); }
cure_disease(str) { return VAMPIRE_FANGS_BASE->cure_disease(str); }
damn(str) { return VAMPIRE_FANGS_BASE->damn(str); }
defend_me(str) { return VAMPIRE_FANGS_BASE->defend_me(str); }
defile_object(str) { return VAMPIRE_FANGS_BASE->defile_object(str); }
demon_wrath(str) { return VAMPIRE_FANGS_BASE->demon_wrath(str); }
dig_hole(str) { return VAMPIRE_FANGS_BASE->dig_hole(str); }
disguise_self(str) { return VAMPIRE_FANGS_BASE->disguise_self(str); }
dismiss_bat(str) { return VAMPIRE_FANGS_BASE->dismiss_bat(str); }
drain_corpse(str) { return VAMPIRE_FANGS_BASE->drain_corpse(str); }
emit_mist(str) { return VAMPIRE_FANGS_BASE->emit_mist(str); }
emote(str) { return VAMPIRE_FANGS_BASE->emote(str); }
eyes_light(str) { return VAMPIRE_FANGS_BASE->eyes_light(str); }
cause_fear(str) { return VAMPIRE_FANGS_BASE->cause_fear(str); }
fly_direction(str) { return VAMPIRE_FANGS_BASE->fly_direction(str); }
forbit_entry(str) { return VAMPIRE_FANGS_BASE->forbid_entry(str); }
list_guild_tasks(str) { return VAMPIRE_FANGS_BASE->list_guild_tasks(str); }
hell_fire(str) { return VAMPIRE_FANGS_BASE->hell_fire(str); }
list_vampires(str) { return VAMPIRE_FANGS_BASE->list_vampires(str); }
glance(str) { return VAMPIRE_FANGS_BASE->glance(str); }
go_home(str) { return VAMPIRE_FANGS_BASE->go_home(str); }
grasp_enemy(str) { return VAMPIRE_FANGS_BASE->grasp_enemy(str); }
static grasp_enemyx(str) { return VAMPIRE_FANGS_BASE->grasp_enemyx(str); }
guild_help(str) { return VAMPIRE_FANGS_BASE->guild_help(str); }
illusion(str) { return VAMPIRE_FANGS_BASE->illusion(str); }
infuse(str) { return VAMPIRE_FANGS_BASE->infuse(str); }
leave_guild(str) { return VAMPIRE_FANGS_BASE->leave_guild(str); }
magic_dart(str) { return VAMPIRE_FANGS_BASE->magic_dart(str); }
make_servant(str) { return VAMPIRE_FANGS_BASE->make_servant(str); }
process_skins(str) { return VAMPIRE_FANGS_BASE->process_skins(str); }
regenerate(str) { return VAMPIRE_FANGS_BASE->regenerate(str); }
remember_rooms(str) { return VAMPIRE_FANGS_BASE->remember_rooms(str); }
rip_throat(str) { return VAMPIRE_FANGS_BASE->rip_throat(str); }
scan_monster(str) { return VAMPIRE_FANGS_BASE->scan_monster(str); }
scratch_enemy(str) { return VAMPIRE_FANGS_BASE->scratch_enemy(str); }
scratch_enemyx(str) { return VAMPIRE_FANGS_BASE->scratch_enemyx(str); }
sew_skins(str) { return VAMPIRE_FANGS_BASE->sew_skins(str); }
shadow(str) { return VAMPIRE_FANGS_BASE->shadow(str);                       }
sharpen_fangs(str) { return VAMPIRE_FANGS_BASE->sharpen_fangs(str); }
shift_hp(str) { return VAMPIRE_FANGS_BASE->shift_hp(str); }
skin_corpse(str) { return VAMPIRE_FANGS_BASE->skin_corpse(str); }
solve_guild_tasks(str) { return VAMPIRE_FANGS_BASE->solve_guild_tasks(str); }
sanctuary(str) { return VAMPIRE_FANGS_BASE->sanctuary(str);                 }
start_up(str) { return VAMPIRE_FANGS_BASE->start_up(str);                   }
summon(str) { return VAMPIRE_FANGS_BASE->summon(str);                       }
telekenetics(str) { return VAMPIRE_FANGS_BASE->telekenetics(str);           }
telepathy(str) { return VAMPIRE_FANGS_BASE->telepathy(str);                 }
telepathyfeel(str) { return VAMPIRE_FANGS_BASE->telepathyfeel(str);         }
fix_title(str) { return VAMPIRE_FANGS_BASE->fix_title(str);                 }
transfer_item(str) { return VAMPIRE_FANGS_BASE->transfer_item(str);         }
translate_item(str) { return VAMPIRE_FANGS_BASE->translate_item(str);       }
vampire_speed(str) { return VAMPIRE_FANGS_BASE->vampire_speed(str);         }
wraith_form(str) { return VAMPIRE_FANGS_BASE->wraith_form(str);             }

/* special versions of standard commands */
quit(str) { return VAMPIRE_FANGS_BASE->quit(str);                           }
show_score(str) { return VAMPIRE_FANGS_BASE->show_score(str);               }
show_inven(str) { return VAMPIRE_FANGS_BASE->show_inven(str);               }
show_who(str) { return VAMPIRE_FANGS_BASE->show_who(str);                   }
show_whov(str) { return VAMPIRE_FANGS_BASE->show_whov(str);                 }
show_player(str) { return VAMPIRE_FANGS_BASE->show_player(str);             }
spell_missile(str) { return VAMPIRE_FANGS_BASE->spell_missile(str);         }
spell_shock(str) { return VAMPIRE_FANGS_BASE->spell_shock(str);             }
spell_fire_ball(str) { return VAMPIRE_FANGS_BASE->spell_fire_ball(str);     }
spell_blast(str) { return VAMPIRE_FANGS_BASE->spell_blast(str);             }

/* make up some soul actions for use in the forms */
generic(str) { return VAMPIRE_FANGS_BASE->generic(str);                     }
vkiss(str) { return VAMPIRE_FANGS_BASE->vkiss(str);                         }
vglare(str) { return VAMPIRE_FANGS_BASE->vglare(str);                       }
fart(str) { return VAMPIRE_FANGS_BASE->fart(str);                           }
laugh(str) { return VAMPIRE_FANGS_BASE->laugh(str);                         }
lick(str) { return VAMPIRE_FANGS_BASE->lick(str);                           }
nod(str) { return VAMPIRE_FANGS_BASE->nod(str);                             }
shake(str) { return VAMPIRE_FANGS_BASE->shake(str);                         }
shrug(str) { return VAMPIRE_FANGS_BASE->shrug(str);                         }
sigh(str) { return VAMPIRE_FANGS_BASE->sigh(str);                           }
smile(str) { return VAMPIRE_FANGS_BASE->smile(str);                         }
sniff(str) { return VAMPIRE_FANGS_BASE->sniff(str);                         }
thank(str) { return VAMPIRE_FANGS_BASE->thank(str);                         }
think(str) { return VAMPIRE_FANGS_BASE->think(str);                         }

yawn(str) { return VAMPIRE_FANGS_BASE->yawn(str);                           }

/*---------------------------------------------------*/
/* Guild Lieutenants Commands (in vampire_fangs_base)*/
/*---------------------------------------------------*/
repair_exp(str) { return VAMPIRE_FANGS_BASE->repair_exp(str);               }
replace_fangs(str) { return VAMPIRE_FANGS_BASE->replace_fangs(str);         }
hop_to_office() { return VAMPIRE_FANGS_BASE->hop_to_office();               }
return_from_office() { return VAMPIRE_FANGS_BASE->return_from_office();     }
check_player(str) { return VAMPIRE_FANGS_BASE->check_player(str);           }
punish_vampire(str) { return VAMPIRE_FANGS_BASE->punish_vampire(str);       }
remove_fangs(str) { return VAMPIRE_FANGS_BASE->remove_fangs(str);       }

/*---------------------------------------------------*/
/*  Guild Assistant Commands (in vampire_fangs_base) */
/*---------------------------------------------------*/
clairaudience(str) { return VAMPIRE_FANGS_BASE->clairaudience(str);         }
expell_traitor(str) { return VAMPIRE_FANGS_BASE->expell_traitor(str);       }

/*---------------------------------------------------*/
/*  Guild Master Commands (in vampire_fangs_base)    */
/*---------------------------------------------------*/
release_member(str) { return VAMPIRE_FANGS_BASE->release_member(str);       }
goto_guild(str) { return VAMPIRE_FANGS_BASE->goto_guild(str);               }
goto_office_board(str) { return VAMPIRE_FANGS_BASE->goto_office_board(str); }
shelf_check(str) { return VAMPIRE_FANGS_BASE->shelf_check(str); }
