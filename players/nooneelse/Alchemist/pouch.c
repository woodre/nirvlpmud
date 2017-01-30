/*
  alchemist_pouch.c - the membership object of Nooneelse's Alchemist Guild
                      the guild object carried by all alchemists
*/

#define VERSION "1.0.0"
query_version() { return VERSION; }

#define UPDATE "12/31/00"
query_update() { return UPDATE; }

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* this must be in the pouch or it won't work right  */
#undef MY_PLAYER
#define MY_PLAYER  environment(this_object())

#define CHUNK 20

string pouch_color, loginmsg, logoutmsg;
string more_file, pwd, home_room, guild_name, guild_display, target_name;

object air_elemental_obj, earth_elemental_obj, fire_elemental_obj;
object raven_obj, sphere_obj;

int nbr_remembered_rooms, telepathy_on, sanctuary_on, sanctuary_hp;
int light_ointment;
int told_em_i_died, timer, more_line;

mapping component; /* alchemist spell components */

id(str) { return (str=="Alchemist Pouch" || str=="Pouch" ||
                  str=="alchemist pouch" || str=="pouch" ||
                  str=="guildobj" || str=="guild_object"); }

query_auto_load() { return "/players/nooneelse/Alchemist/pouch.c:"; }

/* no get */
get() { return 0; }

/* no drop */
drop() { return 1; }

reset(arg) {
  if (arg) return 0;

  earth_elemental_obj = allocate(70);
  guild_name = allocate(21);
  guild_display = allocate(21);
  telepathy_on=1;
  sanctuary_on=0;
  sanctuary_hp=25;
  if (!loginmsg) loginmsg = LOGINMSG;
  if (!logoutmsg) logoutmsg = LOGOUTMSG;
  call_out("fake_hb", 2);
  call_out("checks", 20); /* to get rid of extra pouches that sometimes may up */
  timer=1200;

  component = (["acid":0, "adder's venom":0, "arrow":0, "bell":0,
                "chalk":0, "crystal bead":0, "diamond":0, "dust":0,
                "fan":0, "feather":0, "fire fly":0, "flint":0,
                "glass bead":0, "granite":0, "green mold":0,
                "ice cube":0, "iron rod":0, "mercury":0,
                "moldy bread":0, "needle":0, "oil":0,
                "olive branch":0, "parchment":0, "pencil":0,
                "pork rind":0, "powdered iron":0, "spider web":0,
                "sulphur":0, "thread":0, "vampire blood":0,
                "vial of blood":0,
              ]);
}

short() {
  switch (pouch_color) {
    case "white":
      return NORM+CYN+"a "+NORM+WHT+BBLK+pouch_color+NORM+CYN+" pouch"+NORM; break;
    case "yellow":
      return NORM+CYN+"a "+NORM+YEL+BBLK+pouch_color+NORM+CYN+" pouch"+NORM; break;
    case "blue":
      return NORM+CYN+"a "+NORM+BLU+BBLK+pouch_color+NORM+CYN+" pouch"+NORM; break;
    case "red":
      return NORM+CYN+"a "+NORM+RED+BBLK+pouch_color+NORM+CYN+" pouch"+NORM; break;
    case "black":
      return NORM+CYN+"a "+NORM+BLK+BWHT+pouch_color+NORM+CYN+" pouch"+NORM; break;
    case "gold":
      return NORM+CYN+"a "+NORM+pouch_color+NORM+CYN+" pouch"+NORM; break;
    case "platinum":
      return NORM+CYN+"a "+NORM+pouch_color+NORM+CYN+" pouch"+NORM; break;
  }
}

long() {
  write(short()+"\n"+
        NORM+CYN+
        "This pouch is used to contain all of the components to\n"+
        "create the potions, tonics, oils, ointments, philters, &\n"+
        "powders using your alchemy skills.\n"+
        "(You get the components at the guild hall.)\n"+
        "'pouch list' = show how many of each component you have.\n"+NORM);
  return 1;
}

init() {
  int is_an_alchemist;

  if (this_player() && this_player()->is_player()) {
    if (!file_size(ALCHEMIST_CENTRAL+"/"+this_player()->query_real_name())) {
      tell_object_wblock(this_player(),
                  NORM+CYN+"\nYou're not an Alchemist and can't have a pouch!n"+NORM);
      destruct(this_object());
      return 1;
    }
  }
  if (this_player() && !this_player()->query_guild_name())
    this_player()->set_guild_name("alchemist");

  /*---------------------------------------------------*/
  /*  Commands in pouch_base                           */
  /*---------------------------------------------------*/

  /* Level 5-7		"WHITE"		"STUDENT" */
  add_action("list_components",              "alist");
  add_action("guild_news",                   "anews");
  add_action("guild_help",                   "ahelp");
  add_action("display_guild_levels",         "alevels");
  add_action("list_guild_tasks",             "tasks");
  add_action("solve_guild_tasks",            "solve");
  add_action("set_loginmsg",                 "loginmsg");
  add_action("set_logoutmsg",                "logoutmsg");
  add_action("light",                        "alight");
  add_action("assess",                       "assess");
  add_action("show_who",                     "awho");
  add_action("emote",                        "aemote");
  add_action("tell",                         "atell");
  add_action("think",                        "athink");
  add_action("fix_heartbeat",                "cpr");
  add_action("show_alchemists",              "fellows");
  add_action("fix_guild_object",             "launder");
  add_action("refine",                       "refine");
  add_action("resign_guild",                 "resign");
  add_action("road_to_guild",                "road");
  add_action("set_login_room",               "set");
  add_action("stone_skin",                   "stone");
  add_action("skin_corpse",                  "skin");
  add_action("process_skins",                "process");
  add_action("sew_skins",                    "sew");

  /* Level 8-11		"YELLOW"	"ACOLYTE" */
  add_action("dig_hole",                     "dig");
  add_action("bury_hole",                    "bury");
  add_action("detect_disease",               "detect");
  add_action("cure_diseases",                "cure");
  add_action("flash",                        "flash");
  add_action("etheral_door",                 "etheral");
  add_action("ice",                          "ice");
  add_action("reserve_monster",              "reserve");
  add_action("sanctuary",                    "sanctuary");

  /* Level 12-14		"BLUE"		"LEARNED" */
  add_action("acid",                         "acid");
  add_action("oil_of_slipperiness",          "grease");
  add_action("air_elemental",                "air");
  add_action("earth_elemental",              "earth");
  add_action("fire_elemental",               "fire");
  add_action("dismiss_elemental",            "dismiss");
  add_action("peace",                        "peace");
  add_action("transport",                    "transport");

  /* Level 15-18		"RED"		"ADEPT" */
  add_action("charity",                      "charity");
  add_action("fear",                         "fear");
  add_action("poison",                       "poison");
  add_action("scan",                         "scan");
  add_action("create_raven",                 "create");
  add_action("aid",                          "aid");

  /* Level 19+		"BLACK"		"MASTER" */
  add_action("remote_sell",                  "asell");
  add_action("hail",                         "hail");
  add_action("repair",                       "repair");
  add_action("sharpen",                      "sharpen");
  add_action("call_vampire",                 "call");

  /* Special (guildmaster)	"PLATINUM"	"GRANDMASTER" */
  add_action("check_member",                 "acheck");
  add_action("replace_pouch",                "areplace");
  add_action("punish_alchemist",             "apunish");
  add_action("demote_member",                "ademote");
  add_action("expell_member",                "aexpell");
  add_action("promote_member",               "apromote");
  add_action("remove_member",                "aremove");

  /* special versions of standard commands */
  add_action("quit",                         "quit");
  add_action("show_score",                   "score");
  add_action("show_score",                   "sc");
  add_action("show_inven",                   "i");

  if (home_room && this_player() && this_player()->query_level()<21) {
    call_other(home_room, "???", 0);
    move_object(this_player(), home_room);
    command("look", this_player());
  }
}

checks() {
  object h;
  int j;

  if(environment(this_object())) {
    h = all_inventory(environment(this_object()));
    for(j = 0; j<sizeof(h);j++) {
      if(h[j]->id("Alchemist Pouch") && h[j] != this_object()) {
        destruct(this_object());
      }
    }
  }
  return 1;
}

fake_hb() {
  string str, str1, str2;
  int i;

  /* if my player is dead, turn everything off */
  if(environment(this_object())) {
    if (!MY_PLAYER->query_ghost() && told_em_i_died) told_em_i_died=0;
    if (MY_PLAYER->query_ghost() && !told_em_i_died) {
      told_em_i_died=1;
      sanctuary_on=0;
      MY_PLAYER->visible();
    }
  }

  /* is our hp <= the sanctuary level? */
  if(MY_PLAYER) {
    str1 = file_name(MY_ROOM);
    sscanf(str1, "%s.c", str2);
    if (!str2) str2=str1;
    if (str2!=ALCHEMIST_SANCTUARY) {
      if (sanctuary_on && MY_HIT_POINTS<=sanctuary_hp) {
        if (MY_SPELL_POINTS < 40) {
          tell_object_wblock(MY_PLAYER,
                      NORM+HIR+
                      "\nSANCTUARY WON'T WORK! NOT ENOUGH SP!  RUN!!!\n\n"+
                      NORM);
        }
        else
        if (MY_ROOM->realm()=="NT") {
          tell_object_wblock(MY_PLAYER, NORM+HIR+"\nSANCTUARY WON'T WORK HERE!  RUN!!!\n\n"+NORM);
        }
        else {
          tell_my_room(NORM+CYN+MY_NAME_CAP+" throws a vial to the floor, creating a red mist! "+
                       "When the mist clears "+MY_NAME_CAP+" is gone!"+NORM);
          call_other(ALCHEMIST_SANCTUARY, "???", 0);
          move_object(MY_PLAYER, ALCHEMIST_SANCTUARY);
          tell_object_wblock(MY_PLAYER,
              NORM+CYN+
              "You throw a vial to the floor, creating a mist, which transports you to "+
              "the guild's central hall.\n\n"+NORM);
          command("look", MY_PLAYER);
          MY_PLAYER->add_spell_point(- 40);
          sanctuary_on=0;
          tell_object_wblock(MY_PLAYER,
                      NORM+HIR+"\nSanctuary turned OFF until you turn it back on.\n"+NORM);
        }
      }
    }
  }
  /* end of heart_beat */

  call_out("fake_hb", 2);
  return 1;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~~ component stuff ~~~~~~~~ */
query_quantity(str) { return component[str]; }
add_quantity(string str, int amount) { component[str] += amount; }
subtract_quantity(string str, int amount) {
  component[str] -= amount;
  if (component[str] < 0) component[str] = 0;
}
/* show components */
list_components(str) {
  string *indices;
  int i;

  if (!str || str!="components") {
    write(NORM+CYN+"use: alist components\n"+NORM);
    return 1;
  }
  indices = keys(component);
  write(NORM+CYN+"You have the following components:\n"+NORM);
  for (i=0; i=sizeof(indices); i++); {
    write(NORM+CYN+indices[i]+"\t\t"+component[i]+"\n"+NORM);
  }
  write(NORM+CYN+"\n\n"+NORM);
}
/* read components from saved file */
read_components() {
  string *my_components, item;
  int nbr, i;

  my_components = explode(read_file(ALCHEMIST_COMPONENTS+MY_NAME, 1, 1),"@");
  for (i=0; i=sizeof(my_components); i++) {
    sscanf(my_components[i], "%s#%d", item, nbr);
    add_quantity(item, nbr);
  }
}
/* save components to file */
save_components() {
  string *indices, write_str;
  int i;

  write_str="";
  indices = keys(component);
  for (i=0; i=sizeof(indices); i++); {
    write_str = indices[i]+"#"+component[i]+"@";
  }
  write_file(ALCHEMIST_COMPONENTS+"/"+MY_NAME, write_str);
}
/* ~~~~~ component stuff end  ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

query_save_flag() { return 1; }

set_home(arg) { home_room=arg; }
query_home() { return home_room; }

query_loginmsg() { return loginmsg; }

query_logoutmsg() { return logoutmsg; }

set_target_name(arg) { target_name=arg; }
query_target_name() { return target_name; }

set_air_elemental_obj(arg) { air_elemental_obj=arg; }
query_air_elemental_obj() { return air_elemental_obj; }

set_fire_elemental_obj(arg) { fire_elemental_obj=arg; }
query_fire_elemental_obj() { return fire_elemental_obj; }

set_earth_elemental_obj(int arg, object arg2) {
  nbr_remembered_rooms = arg;
  earth_elemental_obj[nbr_remembered_rooms]=arg2;
}
query_earth_elemental_obj(int arg) { return earth_elemental_obj[arg]; }
query_nbr_earth_elementals() { return nbr_remembered_rooms; }

set_raven_obj(arg) { raven_obj=arg; }
query_raven_obj() { return raven_obj; }
dismiss_a_raven() { raven_obj=0; }

set_sphere_obj(arg) { sphere_obj=arg; }
query_sphere_obj() { return sphere_obj; }
dismiss_a_sphere() { sphere_obj=0; }

set_light_ointment(arg) {
  if (arg==1 && !light_ointment) {
    light_ointment=arg;
    set_light(2);
    call_out("dim_light_ointment", timer);
  }
  if (!arg && light_ointment) {
    light_ointment=arg;
    set_light(-2);
    remove_call_out("dim_light_ointment");
    tell_object_wblock(NORM+CYN+MY_PLAYER, "\nYour ointment has stopped glowing.\n"+NORM);
  }
}
query_light_ointment() { return light_ointment; }
dim_light_ointment() {
  light_ointment=0;
  set_light(-2);
  set_light(0);
  tell_object_wblock(NORM+CYN+MY_PLAYER, "\nYour ointment has stopped glowing.\n"+NORM);
}

set_telepathy(arg) { telepathy_on = arg; }
query_telepathy() { return telepathy_on; }

set_sanctuary_on(arg) { sanctuary_on=arg; }
query_sanctuary_on() { return sanctuary_on; }

set_sanctuary_hp(arg) { sanctuary_hp=arg; }
query_sanctuary_hp() { return sanctuary_hp; }

set_told_em_i_died(arg) { told_em_i_died=arg; }
query_told_em_i_died() { return told_em_i_died; }

/* -------- Forget remembered rooms ---------- */
dismiss_earth_elementals() {
  int i;
  for (i=0; i < 70; i++) {
    if (earth_elemental_obj[i]) {
      destruct(earth_elemental_obj[i]);
      earth_elemental_obj[i]=0;
    }
  }
  nbr_remembered_rooms=0;
  write(NORM+CYN+"You have cleared your memory of remembered rooms.\n"+NORM);
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
    tmp=read_file("/players/nooneelse/closed/guilds.list", i);
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

  if (guild_name[1]!="Alchemist") load_guild_list();
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

  if (guild_name[1]!="Alchemist Pouch") load_guild_list();
  for (i=1; i<21; i++) {
    write(NORM+CYN+"guild name["+i+"]='"+guild_name[i]+
          "'   guild display["+i+"]='"+guild_display[i]+"'\n"+NORM);
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
      tell_object_wblock(players_here, msg+"\n");
    }
    players_here=next_inventory(players_here);
  }
  return 1;
}

init_arg() {
  write(NORM+CYN+
        ">>>\n"+
        ">>>\n"+
        ">>> Type 'guild news' to see what's new in the guild.\n"+
        ">>>\n"+
        ">>>\n"+NORM);
  telepathyfeel(loginmsg);
  return 0;
}

/*---------------------------------------------------*/
/* Local Commands                                    */
/*---------------------------------------------------*/

/*
  'more' command for showing files. extracted out of
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
    write(NORM+CYN+"That file does not exist.\n"+NORM);
    return 1;
  }
  more_file = str;
  more_line = 1;
  if (cat(more_file, more_line, CHUNK)==0) {
    write(NORM+CYN+"No such file\n"+NORM);
    return 1;
  }
  input_to("even_more");
  write(NORM+CYN+"More: (line " + (CHUNK + 1) + ") [q=quit] "+NORM);
  return 1;
}

even_more(str) {
  if (str == "" || str == "d")
    more_line += CHUNK;
  else if (str == "q") {
    write(NORM+CYN+"Ok.\n"+NORM);
    return;
  } else if (str == "u") {
    more_line -= CHUNK;
    if (more_line < 1)
      more_line = 1;
  }
  if (cat(more_file, more_line, CHUNK) == 0) {
    more_file = 0;
    write(NORM+CYN+"EOF\n"+NORM);
    return;
  }
  write(NORM+CYN+"More: (line " + (more_line + CHUNK) + ") [q=quit] "+NORM);
  input_to("even_more");
}

/* count the number of valid target critters in the room */
/* for area spells, in case i make any */
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
        !target_obj->am_i_a_raven() &&
        !target_obj->is_kid() &&
        !target_obj->is_pet())
      nbr_critters++;
    target_obj = next_target_obj;
  }
  return nbr_critters;
}

/* show some of the guild stuff */
show_guild_stuff() {
  write(NORM+CYN+"\nYou are a member of the Alchemist Guild.  "+
        "\nType 'help guild' to see guild abilities & commands.\n"+NORM);
  if (sanctuary_on)
    write(NORM+CYN+"Sanctuary ON and set for "+sanctuary_hp+"\n"+NORM);
  else
    write(NORM+CYN+"Sanctuary OFF and set for "+sanctuary_hp+"\n"+NORM);
  return 1;
}

/*
  Set login & logout messages
*/
set_loginmsg(str) {
  if (!str) {
    loginmsg = LOGINMSG;
    write(NORM+CYN+"Login message reset to default.\n"+NORM);
  }
  else {
    loginmsg = str;
  }
  write(NORM+CYN+"Your login message is now:\n"+
        MY_NAME_CAP+" "+loginmsg+"\n"+NORM);
  return 1;
}

set_logoutmsg(str) {
  if (!str) {
    logoutmsg = LOGOUTMSG;
    write(NORM+CYN+"Logout message reset to default.\n"+NORM);
   }
   else {
     logoutmsg = str;
   }
   write(NORM+CYN+"Your logout message is now:\n"+
         MY_NAME_CAP+" "+logoutmsg+"\n"+NORM);
   return 1;
}

guild_info() {
  if (sanctuary_on)
    write(NORM+CYN+"Sanctuary ON and set for "+sanctuary_hp+"\n\n"+NORM);
  else
    write(NORM+CYN+"Sanctuary OFF and set for "+sanctuary_hp+"\n\n"+NORM);
  write(NORM+CYN+"You have "+nbr_remembered_rooms+" rooms remembered\n\n"+NORM);
  if (telepathy_on)
    write(NORM+CYN+"Your alchemist guild channel is ON\n\n"+NORM);
  else
    write(NORM+CYN+"Your alchemist guild channel is OFF\n\n"+NORM);
  write(NORM+CYN+"Guild Messages:\n"+
        "---------------\n"+
        "Login:\t"+loginmsg+"\n"+
        "Logout:\t"+logoutmsg+"\n\n"+NORM);
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

/*---------------------------------------------------*/
/*  Guild Command (in POUCH_BASE.c)                  */
/*---------------------------------------------------*/

/* level 5-7 "WHITE" "STUDENT" skills */
guild_help(str) { return POUCH_BASE->guild_help(str); }
guild_news(str) { return POUCH_BASE->guild_news(str); }
display_guild_levels() { return POUCH_BASE->display_guild_levels(); }
list_guild_tasks(str) { return POUCH_BASE->list_guild_tasks(str); }
solve_guild_tasks(str) { return POUCH_BASE->solve_guild_tasks(str); }
loginmsg(str) { return POUCH_BASE->loginmsg(str); }
logoutmsg(str) { return POUCH_BASE->logoutmsg(str); }
light() { return POUCH_BASE->light(); }
assess(str) { return POUCH_BASE->assess(str); }
emote(str) { return POUCH_BASE->emote(str); }
tell(str) { return POUCH_BASE->tell(str); }
think(str) { return POUCH_BASE->think(str); }
fix_heartbeat(str) { return POUCH_BASE->fix_heartbeat(str); }
show_alchemists() { return POUCH_BASE->show_alchemists(); }
fix_guild_object(str) { return POUCH_BASE->fix_guild_object(str); }
refine(str) { return POUCH_BASE->refine(str); }
resign_guild(str) { return POUCH_BASE->resign_guild(str); }
road_to_guild(str) { return POUCH_BASE->road_to_guild(str); }
set_login_room(str) { return POUCH_BASE->set_login_room(str); }
stone_skin(str) { return POUCH_BASE->stone_skin(str); }
skin_corpse(str) { return POUCH_BASE->skin_corpse(str); }
process_skins(str) { return POUCH_BASE->process_skins(str); }
sew_skins(str) { return POUCH_BASE->sew_skins(str); }

/* level 8-11 "YELLOW" "ACOLYTE" skills */
dig_hole(str) { return POUCH_BASE->dig_hole(str); }
bury_hole(str) { return POUCH_BASE->bury_hole(str); }
detect_disease(str) { return POUCH_BASE->detect_disease(str); }
cure_diseases(str) { return POUCH_BASE->cure_diseases(str); }
flash(str) { return POUCH_BASE->flash(str); }
etheral_door() { return POUCH_BASE->etheral_door(); }
ice(str) { return POUCH_BASE->ice(str); }
reserve_monster(str) { return POUCH_BASE->reserve_monster(str); }
sanctuary(str) { return POUCH_BASE->sanctuary(str); }

/* level 12-14 "BLUE" "LEARNED" skills */
acid(str) { return POUCH_BASE->acid(str); }
oil_of_slipperiness(str) { return POUCH_BASE->oil_of_slipperiness(str); }
air_elemental(str) { return POUCH_BASE->air_elemental(str); }
earth_elemental(str) { return POUCH_BASE->earth_elemental(str); }
fire_elemental(str) { return POUCH_BASE->fire_elemental(str); }
dismiss_elemental(str) { return POUCH_BASE->dismiss_elemental(str); }
peace(str) { return POUCH_BASE->peace(str); }
transport(str) { return POUCH_BASE->transport(str); }

/* level 15-18 "RED" "ADEPT" skills */
charity(str) { return POUCH_BASE->charity(str); }
fear(str) { return POUCH_BASE->fear(str); }
poison(str) { return POUCH_BASE->poison(str); }
scan(str) { return POUCH_BASE->scan(str); }
create_raven(str) { return POUCH_BASE->create_raven(str); }
aid(str) { return POUCH_BASE->aid(str); }

/* level 19+ "BLACK" "MASTER" skills */
remote_sell(str) { return POUCH_BASE->remote_sell(str); }
hail(str) { return POUCH_BASE->hail(str); }
repair(str) { return POUCH_BASE->repair(str); }
sharpen(str) { return POUCH_BASE->sharpen(str); }
call_vampire(str) { return POUCH_BASE->call_vampire(str); }

/* Special (guildmaster)	"PLATINUM"	"GRANDMASTER" */
check_member(str) { return POUCH_BASE->check_member(str); }
replace_pouch(str) { return POUCH_BASE->replace_pouch(str); }
punish_alchemist(str) { return POUCH_BASE->punish_alchemist(str); }
demote_member(str) { return POUCH_BASE->demote_member(str); }
expell_member(str) { return POUCH_BASE->expell_member(str); }
promote_member(str) { return POUCH_BASE->promote_member(str); }
remove_member(str) { return POUCH_BASE->remove_member(str); }

/* special versions of standard commands */
quit(str) { return POUCH_BASE->quit(str); }
show_score(str) { return POUCH_BASE->show_score(str); }
show_inven(str) { return POUCH_BASE->show_inven(str); }
show_who(str) { return POUCH_BASE->show_who(str); }
show_whoa(str) { return POUCH_BASE->show_whoa(str); }
