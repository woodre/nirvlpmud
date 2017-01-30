#include "/players/mizan/esc.h"

/*
 * PolymorphDM.c [Release 2.0] Daemonized
 *
 * DO NOT CLONE THIS THING! It is meant to be loaded and accessed-
 * and that is IT! One big file that a whole bunch of smaller files
 * feed off from.
 *
 * Leave this header in here if you're going to use this code.
 * You can do whatever you want to improve it but i'd appreciate
 * improvement notices being mailed back to me.
 * Dont circulate off-nirvana. Mizan the wombat
 */

#define GUILD_ID "Mizan-guild-object"
#define MORPH_ID "Mizan-morph-object"
#define GUILDNAME "polymorph"
#define PATHNAME "/players/mizan/closed/poly/"
#define GUILDFILE "/players/mizan/closed/poly/gob.c"
#define HELPDIR "/players/mizan/closed/poly/help/"
#define HOME "/players/mizan/etheriel/ROOMS/linna"
#define LOGPATH "/players/mizan/logs/"
#define MOTD " >>\n >> Welcome to the guild! Make sure you read the news!\n    Information is constantly being updated there. 'info news' for help.\n"
#define GC 10


/* [2] */
#define POLY_SPUCKBALL_COST 60

#define POLY_GOLEM_COST 120
#define POLY_TREE_COST 200

#define POLY_WOMBAT_COST 50


/* [3] */
#define POLY_FUNGOID_COST 250
#define POLY_SPONGE_COST 250
#define POLY_SPR_COST 330


/* [4] */
#define POLY_REPLICANT_COST 500
#define POLY_PUFFBALL_COST 400
#define POLY_SHOUTBOX_COST 440


/* [5] */
#define POLY_TETRAPOD_COST 700
#define POLY_BOG_COST 550

/* [6] */
#define POLY_SPIRAL_COST 1400

/*
 * ORDER-> cmorph, sta, int, mag, str, ste, luck
 */


#define POLY_SPUCKBALL_STAT "spuckball#2#-20#-1#1#-3#2"


#define POLY_GOLEM_STAT "golem#4#-8#-20#4#-6#-2"
#define POLY_TREE_STAT "tree#2#-20#-20#0#-20#-7"

#define POLY_WOMBAT_STAT "wombat#-6#-17#-6#2#-16#10"

#define POLY_FUNGOID_STAT "fungoid#2#-18#-18#2#-6#-3"
#define POLY_SPONGE_STAT "sponge#" + (8+random(10)) + "#-18#-19#5#-16#1"
#define POLY_SPR_STAT "blobel#-6#3#3#-10#-6#0"

#define POLY_REPLICANT_STAT "replicant#3#3#3#3#3#3"
#define POLY_PUFFBALL_STAT "puffball#-11#3#7#-13#2#2"
#define POLY_SHOUTBOX_STAT "shoutbox#-6#-7#4#9#-13#-10"

#define POLY_TETRAPOD_STAT "tetrapod#6#-20#-20#5#-7#-4"
#define POLY_BOG_STAT "bogglemancer#-3#-2#6#-1#-1#8"

#define POLY_SPIRAL_STAT "spiral#-3#5#9#-5#-5#9"

/* ---- Spell costs --- */

#define ESCAPE_COST 20
#define ETHER_COST 20
#define SURVEY_COST 10

#define ATOMIZE_COST 15
#define REGAIN_COST 3
#define HELPME_COST 7


#define SPUCKBALL_SQUIT_COST 10
#define WOMBAT_BURROW_COST 5
#define WOMBAT_FORAGE_COST 16
#define WOMBAT_CHOMP_COST 8
#define FUNGOID_GRIBBLE_COST 12
#define FUNGOID_PUFF_COST 15
#define FUNGOID_SPOG_COST 18
#define BLOBEL_CONFUSION_COST 25

#define BLOBEL_UNFROG_COST 85
#define SHOUTBOX_SUPERBLINK_COST 15
#define SHOUTBOX_SHRILL_COST 25
#define SHOUTBOX_HOLLER_COST 18
#define SHOUTBOX_CURSE_COST 15
#define SHOUTBOX_CALM_COST 55
#define SHOUTBOX_REVERB_COST 60

#define PUFFBALL_FRY_COST 40

#define PUFFBALL_VAPORIZE_COST 45
#define BOG_SPEEDBALL_COST 42
#define BOG_ZOKWAVE_COST 45
#define BOG_CHARBROIL_COST 40
#define BOG_SANDBAG_COST 30
#define BOG_TREE_COST 36
#define BOG_LINT_COST 25
#define BOG_PIANO_COST 40
#define BOG_ANVIL_COST 32
#define TETRAPOD_BLITZ_COST 60
#define SPIRAL_SWITCH_COST 20
#define SPIRAL_MULTIHIT_COST 120



id(str) { return str == "toaster"; }

short() { return "A toaster"; }

long() {
  write("This is an ordinary looking toaster, but it seems to be busy,\n"+
  "doing the computational work of a desktop PC. It does not really want\n"+
  "to be bothered with.\n");
}

reset(arg) {
  move_object(this_object(), HOME);
  loadnews();
  if(!arg) {
  move_object(clone_object("/players/mizan/etheriel/environs/guild_sign"), HOME);
  }
}

init() {
  if(this_player() && living(this_player()) && environment(this_player()) == this_object()) {
    write("The toaster drops you.\n");
    say("The toaster drops the " + (this_player()->query_name()) + ".\n");
    move_object(this_player(), HOME);
  }
}

/* ---- GUILD FUNCTIONS NOW --- */

guild_function(str) {
  string testo;
  if(!str || str == "escape") {
    guild_escape();

    return 1;
  }
  if(str == "help") {
    info_function("guild");
    return 1;
  }
  if(str == "fix") {
    guild_fix();
    return 1;
  }
  if(str == "save") {
    object ob;
    ob=present(GUILD_ID, this_player());

    if(!ob) return 0;
  if(ob->query_current_morph() != "none") {
    write("You must not be polymorphed to do this.\n");
    return 1;
  }
    ob->record_attribs();
    this_player()->save_me();
    write("Character and guild stats saved.\n");
    return 1;
  }
  if(str == "who") { guild_fancy_who(); return 1; }
  if(str == "who /n") { guild_fancy_who("/n"); return 1; }
  if(str == "who /d") { guild_fancy_who("/d"); return 1; }
  if(str == "RETIRE!") {
    if(check_dead()) return 1;
    guild_deduct_stats();
    return 1;
  }
  if(sscanf(str, "banish %s", testo) == 1) {

    if(check_dead()) return 1;
    if(!check_level(GC)) return 1;
    guild_deduct_stats(testo);
    return 1;
  }

  if(sscanf(str, "vibe %s", testo) == 1 || sscanf(str, "tell %s", testo) == 1) {
    guild_tell(testo);
    return 1;
  }
  return 0;
}
guild_tell(str) {
  object ob,gob;
  string temp,temp2,temp3,temp4;
  int v;
  if(!str) {
    write("You must give a message.\n");
    return 1;
  }
/*
  gob=present(GUILD_ID, this_player());
 */
  gob = present(GUILD_ID, this_player());
  if(!gob) return 0;
  if(str == "list") {

    guild_tell_people();
    return 1;
  }
  if(str == "muffle") {
    toggle_function("muffle");
    return 1;

  }
  if(this_player()->query_ghost()) temp2 = "ghost";
  else temp2 = gob->query_morph_comm();
  if(!temp2) {
    temp2 = "vibe";
    if(sscanf(str, "%s?", temp3) == 1) temp2 = "wonder";
    else if(sscanf(str, "%s??", temp3) == 1) temp2 = "boggle";
    else if(sscanf(str, "%s??%s", temp3, temp4) == 2) temp2 = "interrogate";

    else if(sscanf(str, "%s!!", temp3) == 1) temp2 = "yell";
    else if(sscanf(str, "%s!!%s", temp3, temp4) == 2) temp2 = "thunder";
  }
  if(gob->query_muffle()) {
    write("You were muffled! Muffle overridden.\n");
    gob->toggle_muffle();
  }
  if(sscanf(str, ":%s", temp) == 1) {
    if(this_player()->query_invis() > 38)
      temp = ">> (" + temp2 + ")" + ESC + "[0m Someone " + temp + "\n";
      else temp = ">> (" + temp2 + ")" + ESC + "[0m " + capitalize(this_player()->query_real_name()) + " " + temp + "\n";
    } else {
      if(this_player()->query_invis() > 38) temp = ">> Someone " + temp2 + "s:" + ESC + "[0m " + str + "\n";
      else temp = ">> " + capitalize(this_player()->query_real_name()) + " " + temp2 + "s:" + ESC + "[0m " + str + "\n";
  }
  temp = format(temp, 70);

  ob=users();
  guild_echo(ESC + "[1m" + ESC + "[34m" + temp);
  return 1;
}

guild_tell_people() {
  object ob;
  string temp,a,b;
  int v;
  ob=users();

  temp = " ";
  for(v=0; v<sizeof(ob); v++) {
    object oc;
    oc=present(GUILD_ID, ob[v]);
    if(oc && !oc->query_muffle()) {
      if(!ob[v]->query_invis() || ob[v]->query_invis() < 19)
      temp = temp + capitalize(ob[v]->query_real_name()) + ", ";
    }
  }
  temp = "Players currently on the vibe channel:" + temp;
  temp = format(temp, 70);
  write(temp + "\n");
  return 1;
}

/* ---- i should make this static --- */

guild_echo(str) {
  object ob;
  int v;
  ob=users();
  for(v=0; v<sizeof(ob); v++) {
    object oc;
    string od;
    oc=present(GUILD_ID, ob[v]);
    if(oc && !oc->query_muffle()) tell_object(ob[v], str);
  }
}


/* Forces return from polymorph during save */


guild_fix() {
  object ock,odk,oek;

  if(check_dead()) return 1;
  ock=present(GUILD_ID, this_player());
  if(ock) {
    odk=present(MORPH_ID, this_player()); 
    if(odk) {
      odk->unstrap_all();
      undo_polymorph();
    }
    write("Old object destructed.\n");
    oek=clone_object(GUILDFILE);
    move_object(oek, this_player());
    oek->add_charge(ock->query_charge());
    oek->fake_beat();

    destruct(ock);
    write("Done.\n");
    this_player()->reset(1);
    do_score();

  }
  return 1;
}
guild_escape() {
  object room;
  string desta,test;
  if(check_dead()) return 1;
  if(this_player()->query_attack()) {
    write("You are too busy fighting to do this.\n");
    return 1;
  }
  if(!check_sp(ESCAPE_COST)) return 1;
  room = environment(this_player());
  if(room == environment(this_object())) {
    write("A toaster pokes you in the ribs.\n");
    return 1;
  }
  desta=creator(room);
  if(!desta || sscanf(file_name(room), "/room%s", test) == 1) {
    write("You fade into the environment and arrive in the guild room!\n\n");
    remote_say((this_player()->query_name()) + " fades from view.\n");
    move_object(this_player(), HOME);
    remote_say((this_player()->query_name()) + " drifts into view.\n");
    this_player()->add_spell_point(-ESCAPE_COST);
    this_player()->look();
    return 1;
  } 
  if(desta == "mizan" && sscanf(room->short(), "Plane of Etherie%s", test) == 1) {
    if(environment(this_player())->realm() != "NT" && 1 == random(8)) {
      write("The ether-muck is a bit too thick here.\n");

      return 1;
    }
    write("You fade into the environment, a swirling flotsam and jetsam\n"+
    "of utter chaos, and arrive somewhere else.\n\n");
    remote_say((this_player()->query_name()) + " suddenly turns transparent and drifts away.\n");
    move_object(this_player(), HOME);
    remote_say((this_player()->query_name()) + " drifts into view.\n");

    this_player()->look();
    return 1;
  }
  write("You are too far out of range. It would not be safe to try this.\n");
  return 1;
}

guild_deduct_stats(str,arg) {
  object thingy,victim;
  if(!str) victim = this_player();
  else victim=find_player(str);
  if(!victim) {
    write("That player is not currently logged in.\n");
    return 1;

  }
  if(victim->query_ghost()) {
    write("That player is dead.\n");
    return 1;

  }
  if(victim->query_guild_name() != GUILDNAME) {
    write("Tha a member of the guild.\n");
    return 1;
  }
  if(victim->query_real_name() == "mizan") {
    write("Funny.\n");
    return 1;
  }
  thingy=present(GUILD_ID, victim);
  if(!thingy) return 0;
  if(thingy->qh() != "none") undo_polymorph(victim);
  if(arg) {
    thingy->set_current_morph("[BANISHED]");
    write_file(LOGPATH + "POLY_BANISH",
    (this_player()->query_real_name()) + " banished " + str + " from the guild on " + ctime());
  } else {
    thingy->set_current_morph("[LEFT]");

    write_file(LOGPATH + "POLY_RETIRE",
    (this_player()->query_real_name()) + " left the guild on " + ctime());
  }
  thingy->record_attribs();
  destruct(thingy);    
  victim->set_guild_name(0);
  victim->set_guild_file(0);
  if(victim->query_exp()) victim->add_exp(-(victim->query_exp() / 3));
  victim->add_guild_exp(-victim->query_guild_exp());
  victim->add_guild_rank(-(victim->query_guild_rank()));

  call_other("room/adv_guild", "correct_level", victim);
  call_other("room/exlv_guild", "correct_extra_level", victim);
  victim->reset(1);
  victim->save_me();
  tell_object(victim,
  "Player stats recomputed.\n"+
  "You lose 1/3 of your current experience.\n"+
  "Guild name and files have been reset to zero.\n"+
  "If you wish to rejoin you must mail Mizan.\n"+
  "Good luck.\n");
  return 1;
}

/* ---- just what it does- guild fancy who

        long and bulky... i know... shut up  --- */

guild_fancy_who(str) {
  object ob,oc;
  int v;
  ob=users();
  write("\n>>Polymorphs:-----------------------------------------------------------<<\n");
  write("Name\t\tLev GLev Sex Morph\t");
  if(str == "/n") write("Nickname\n");
  else if(str == "/d") write("Doing...\n");
  else write("Current location\n");
  for(v=0; v<sizeof(ob); v++) {
    string tempr,temps;
    int lv,glv;
    tempr="";
    oc=present(GUILD_ID, ob[v]);
    if(oc && environment(ob[v]) && ob[v]->query_invis() < 20) {
      if(query_idle(ob[v]) >= 5 * 60) tempr = tempr + "=";
      if(in_editor(ob[v])) tempr = tempr + "*";
      if(oc->query_muffle()) tempr = tempr + "!";
      tempr = tempr + capitalize(ob[v]->query_name()) + "\t";
      if(strlen(tempr) < 9) tempr = tempr + "\t";
      lv = ob[v]->query_level();
      glv = ob[v]->query_guild_rank();
      if(lv < 10) tempr = tempr + "  " + lv + "  ";
      if(lv > 9 && lv < 20) tempr = tempr + " " + lv + "  ";
      if(lv > 19) tempr = tempr + "Wiz  ";

      if(glv < GC) tempr = tempr + "  " + glv + "  ";
      if(glv > (GC - 1) && glv < 20) tempr = tempr + " GC  ";
      if(glv > 19) {
        if(ob[v]->query_real_name() == "mizan") tempr = tempr + "Moo  ";
          else if(ob[v]->query_real_name() == "bastion") tempr = tempr + "Eep ";
            else if(ob[v]->query_real_name() == "wizardchild") tempr = tempr + "Log  ";
        else tempr = tempr + "Wiz  ";
      }

      tempr = tempr + capitalize(extract((ob[v]->query_gender()), 0, 0)) + "   ";
      if(!oc->query_current_morph()) tempr = tempr + "none\t";
        else {
          temps = oc->query_current_morph();
          if(strlen(temps) > 7) tempr = tempr + extract(temps, 0, 6) + ".\t";
          else tempr = tempr + temps + "\t";
        }
      if(str == "/n") temps = oc->query_nickname();
      else if(str == "/d") temps = oc->query_doing();
      else temps = (environment(ob[v]))->short();
        if(temps && strlen(temps) > 34) tempr = tempr + extract(temps, 0, 34) + ".\n";
      else tempr = tempr + temps + "\n";
    }

  write(tempr);
  }
  write("\n>>-Prefixes: '*' is wizard editing, '=' is idle, '!' is channel muffle  <<\n");
  write(">>----------------------------------------------------------------------<<\n");
  return 1;
}


/* ---- POLYMORPH FUNCTIONS NOW --- */

polymorph_function(str) {
  object gob,ob;
  gob = present(GUILD_ID, this_player());
  if(!gob) return 0;
  if(check_dead()) return 1;
  if(this_player()->query_pregnancy()) {
    write("You cannot polymorph because you would kill your unborn child!\n");
    return 1;
  }
  if(!str) {
    if(gob->query_current_morph() == "none") {

      write("You are not currently polymorphed as anything.\n");
      return 1;
    }
    write("You are currently polymorphed as a " + (gob->query_current_morph()) + ".\n");
    return 1;
  }
  if(str == "help" || str == "info") {
    info_function("polymorph");
    return 1;
  }
  if(gob->query_current_morph() != "none") {
    write("You are already polymorphed as a " + (gob->query_current_morph()) + "!\n");
    return 1;
  }
  if(this_player()->query_attack()) {
    write("You are too busy fighting to concentrate.\n");
    return 1;
  }
  if(this_player()->query_level() < 20 && this_player()->query_invis()) {
    write("You must be visible to polymorph into things.\n");
    return 1;
  }
  record_stats();

 /* POLYMORPH SPUCKBALL [1] */

  if(str == "spuckball") {
    do_polymorph(1,POLY_SPUCKBALL_COST,"wobble",POLY_SPUCKBALL_STAT,
    "You implode and shape yourself to the form of a Spuckball.\n"+
    "Everything suddenly turns a bit blurrier and sloshy, but within\n"+
    "a few moments your new form adjusts to the environment.\n");
    return 1;

  }

/* POLYMORPH GOLEM [2] */


  if(str == "golem") {
    do_polymorph(2,POLY_GOLEM_COST,"rumble",POLY_GOLEM_STAT,
    "You expand and shape yourself to the form of a golem.\n");
    return 1;
  }

/* POLYMORPH TREE [2] */


  if(str == "tree") {
    do_polymorph(2,POLY_TREE_COST,"bark",POLY_TREE_STAT,
    "Everything suddenly goes stiff...\n");
    unready_items("armor","weapons");
    return 1;
  }


/* POLYMORPH WOMBAT [2] */


  if(str == "wombat") {
    do_polymorph(1,POLY_WOMBAT_COST,"bleat",POLY_WOMBAT_STAT,
    "You absorb the energy within the clay's matrix and\n"+

   "new power courses through your new form as a wombat\n\n" +
    "You suddenly get the urge to dig holes and graze.\n");
    unready_items("armor",0);
    return 1;
  }

/* POLYMORPH FUNGOID [3] */

  if(str == "fungoid") {
    do_polymorph(3,POLY_FUNGOID_COST,"spore",POLY_FUNGOID_STAT,
    "You concentrate and shape yourself to the form of a fungoid.\n");
    return 1;
  }

/* POLYMORPH SPONGE [3] */

  if(str == "sponge") {
    do_polymorph(3,POLY_SPONGE_COST,"foam",POLY_SPONGE_STAT,
    "You expand and shape yourself to the form of a sponge.\n");
   unready_items("armor","weapons");
    return 1;
  }

/* POLYMORPH SPR (Blobel) [3] */

  if(str == "blobel") {
    do_polymorph(3,POLY_SPR_COST,"blurble",POLY_SPR_STAT,
    "You concentrate intensely and shape yourself to the form of a blobel.\n");
    return 1;
  }

/* POLYMORPH PUFFBALL [4] */

  if(str == "puffball") {
    do_polymorph(4,POLY_PUFFBALL_COST,"puff",POLY_PUFFBALL_STAT,
    "You absorb the energy within the clay's matrix and\n"+
    "new power courses through your new form as a puffball.\n");
    unready_items("armor",0);
    return 1;
  }


/* POLYMORPH REPLICANT [4] */

  if(str == "replicant") {
    do_polymorph(4,POLY_REPLICANT_COST,"vibe",POLY_REPLICANT_STAT,

    "You absorb the energy within the clay's matrix and\n"+
    "new power courses through you as you suddenly feel stronger...\n"+
    "faster... better... but your appearances are all the same.\n");
    return 1;
  }

/* POLYMORPH SHOUTBOX [4] */

  if(str == "shoutbox") {
    do_polymorph(4,POLY_SHOUTBOX_COST,"bellow",POLY_SHOUTBOX_STAT,

    "You concentrate intensely and shape yourself to the form of a shoutbox.\n"+
    "Your mouth expands to gaping proportions, your lungs and chest expand\n"+
    "just the same. You feel bloody right dangerous, and like yelling\n"+
    "at someone.\n");
    unready_items("armor",0);

    return 1;

  }

/* POLYMORPH TETRAPOD [5] */

  if(str == "tetrapod") {
    if(this_player()->query_wimpy() || gob->query_wimpy_pct()) {
      write("You must have wimpy turned off to assume this polymorph.\n"+
      "Check regular wimpy and guild wimpy and try again.\n");
      return 1;
    }
    do_polymorph(5,POLY_TETRAPOD_COST,"growl",POLY_TETRAPOD_STAT,
    "You concentrate and assume the polymorph of a tetrapod.\n"+
    "New arms pop out from nowhere but after a bit of confusion, and\n"+
    "much scratching and waving, everything feels okay.\n");
    return 1;

  }

/* POLYMORPH BOG (Bogglemancer) [5] */

  if(str == "bogglemancer") {
    do_polymorph(5,POLY_BOG_COST,"gribble",POLY_BOG_STAT,
    "You absorb the energy within the clay's matrix and\n"+

    "reciting the Principles of Painless distraction, you suddenly drift\n"+
    "into a state of thoughtless awareness, and your new form.\n");
    return 1;
  }

/* POLYMORPH SPIRAL [6] */

  if(str == "spiral") {
    if(this_player()->query_gender() != "female") {
      write("What? You can't assume this polymorph!\n(And castration is not fun).\n");
      return 1;
    }
    if(this_player()->query_wimpy() || gob->query_wimpy_pct()) {
      write("You must have wimpy turned off to assume this polymorph.\n"+

      "Make sure regular and guild wimpy are both off.\n");
      return 1;
    }
    do_polymorph(10,POLY_SPIRAL_COST,"mutter",POLY_SPIRAL_STAT,
    "You concentrate and assume the polymorph likeness of Spiral.\n"+
    "New arms pop out from nowhere but after a bit of confusion, and\n"+
    "much scratching and waving, everything feels fluid and natural.\n");
     unready_items("armor",0);
    return 1;
  }

/* end morphing routines */


  write("That is not one of the polymorph forms you know.\n");
  return 1;
}

/* ---- TOGGLE FUNCTIONS NOW --- */

toggle_function(str) {
  object ob;
  ob = present(GUILD_ID, this_player());
  if(!ob) return 0;
  if(!str || str == "list") {
    write("\n>> Toggle settings: --------------<<\n\n");
    write("  autocharge\t");
    if(ob->query_autocharge()) write("ON\n"); else write("OFF\n");
    write("  drain\t\t");
    if(ob->query_drain()) write("MATTER\n"); else write("ENERGY\n");
    write("  entry\t\t");
    if(this_player()->query_home()) write("ETHER-MUCK\n"); else write("CHURCH\n");
    write("  eval\t\t");
    if(ob->query_eval()) write("ON\n"); else write("OFF\n");

    write("  invis\t\t");
    if(ob->query_invis()) write("ON\n"); else write("OFF\n");

    write("  max\t\t");
    if(ob->query_max()) write("ACTIVE\n"); else write("OFF\n");
    write("  moncharge\t");
    if(ob->query_moncharge()) write("ADDED\n"); else write("OFF\n");
    write("  monitor\t");
    if(ob->query_monitor()) write("ON\n"); else write("OFF\n");
    write("  msg\t\t");
    if(ob->query_msg()) write("ON\n"); else write("OFF\n");
    write("  muffle\t");
    if(ob->query_muffle()) write("ON\n"); else write("OFF\n");
    write("  news\t\t");
    if(ob->query_news_announce()) write("ON\n"); else write("OFF\n");
/*
    write("  window\t");
    if(ob->query_window()) write("ON\n"); else write("OFF\n");
 */
    write(">>--------------------------------<<\n");
    return 1;
  }    
  if(str == "autocharge") {
    if(ob->query_autocharge()) write("Autocharge OFF.\n");
    else write("Autocharge ON.\n");
    ob->toggle_autocharge();
    return 1;
    }
  if(str == "drain") {
    if(ob->query_drain()) write("Corpse drain / charge transfers set to ENERGY.\n");
    else write("Corpse drain / charge transfers set to MATTER.\n");
    ob->toggle_drain();
    return 1;
  }
  if(str == "entry") {
    if(this_player()->query_home()) {
      write("Login toggled to the village church.\n");
      this_player()->set_home(0);
    } else {
      write("Login toggled to the Plane of Etheriel.\n");
      this_player()->set_home("players/mizan/etheriel/ROOMS/linna");
    }
    return 1;
  }
  if(str == "eval") {
    if(ob->query_eval()) write("Combat spell evaluation OFF.\n");
    else write("Combat spell evaluation ON.\n");
    ob->toggle_eval();
    return 1;
  }
  if(str == "invis") {
    if(ob->query_invis()) write("The lump of clay fades into view.\n");
    else write("The lump of clay fades from view.\n");
    ob->toggle_invis();
    return 1;
  }
  if(str == "max") {
    if(ob->query_max()) write("Monitor will remain active throughout.\n");
    else write("Monitor will go idle when HP+SP maxmized.\n");
    ob->toggle_max();
    return 1;
  }
  if(str == "moncharge") {
    if(ob->query_moncharge()) write("Monitor charge add-on turned OFF.\n");
    else write("Monitor charge add-on ADDED.\n");
    ob->toggle_moncharge();
    return 1;
  }
  if(str == "monitor") {
    if(ob->query_monitor()) write("Monitor turned OFF.\n");
    else write("Monitor turned ON.\n");
    ob->toggle_monitor();
    ob->fake_beat();
    return 1;
  }
  if(str == "muffle") {
    if(ob->query_muffle()) write("Muffle turned OFF (Channels open).\n");
    else write("Muffle ON.\n");
    ob->toggle_muffle();
    return 1;
  }
  if(str == "msg") {
    if(ob->query_msg()) write("Entry-exit messages toggled OFF.\n");
    else write("Entry-exit messages toggled ON.\n");
    ob->toggle_msg();
    return 1;
  }
  if(str == "news") {
    if(ob->query_news_announce()) write("Announcing of news text completions turned OFF.\n");
    else write("Announcements of news updates ON.\n");
    ob->toggle_news_announce();
    return 1;
  }
/*
  if(str == "window") {
    if(ob->query_window()) write("Window turned OFF.\n");
    else write("Window turned " + ESC + "[5m" + ESC + "[32m" + "ON" + ESC + "[0m.\n");
    ob->toggle_window();

    return 1;
  }
 */

  return 0;
}
/* ---- SET FUNCTION NOW --- */

set_function(str) {
  object gob;
  string varstr;
  int varint;
  gob = present(GUILD_ID, this_player());
  if(!gob) return 0;
  if(str) {
    if(sscanf(str, "msgin %s", varstr) == 1) {
      gob->set_msgin(varstr);
      write("Entry message emote set to: " + (this_player()->query_name()) + " " + varstr + "\n");
    }
    if(sscanf(str, "msgout %s", varstr) == 1) {
      gob->set_msgout(varstr);
      write("Exit message emote set to: " + (this_player()->query_name()) + " " + varstr + "\n");
    }
    if(sscanf(str, "panic %s", varstr) == 1) {
      gob->set_panic_key(varstr);
      write("Panic set to '" + varstr + "'.\n");
      gob->init();
    }
    if(sscanf(str, "nickname %s", varstr) == 1) {
      gob->set_nickname(varstr);
      write("Nickname set to '" + varstr + "'.\n");
    }
    if(sscanf(str, "statkey %s", varstr) == 1) {
      gob->set_superstat_key(varstr);
      write("Quick-stat key set to '" + varstr + "'.\n");
      gob->init();
    }
    if(sscanf(str, "sig %s", varstr) == 1) {
      write("Signature on newsgroups set to:\n" + varstr + "\n");
      gob->set_sig(varstr);
      return 1;
    }
    if(sscanf(str, "pretitle %s", varstr) == 1) {
    if(gob->query_current_morph() != "none") {
      write("You must not be polymorphed to do this.\n");
      return 1;
    }
    this_player()->set_pretitle(varstr);
      gob->set_pretitle(varstr);
      write("Pretitle set to '" + varstr + "'.\n");
    }
    if(sscanf(str, "title %s", varstr) == 1) {

    if(!check_level(2)) return 1;
    if(gob->query_current_morph() != "none") {
      write("You must not be polymorphed to do this.\n");
      return 1;
    }
    if(strlen(varstr) > 99) varstr = extract(varstr, 0, 99);
      write("Title set to '" + varstr + "'.\n");
      this_player()->set_title(varstr);
      gob->set_title(varstr);
    }
/*
    if(sscanf(str, "lines %d", varint) == 1) {

      write("Screen height (lines) set to " + varint + ".\n");
      gob->set_screen_height(varint);
    }
 */
    if(sscanf(str, "doing %s", varstr)) {
      if(strlen(varstr) > 35) varstr = extract(varstr, 0, 35);
    write("Doing set to '" + varstr + "'.\n");
      gob->set_doing(varstr);
    }
    if(sscanf(str, "monitor %d", varint) == 1) {
      if(varint < 3 || varint > 1000) {

        write("Monitor range is 3 - 1000.\n"); return 1;
      }
      write("Monitor interval set to " + varint + " (" + (varint * 2) + " seconds).\n");
      write("Monitor speeds up to update every round in combat.\n");
      gob->set_monitor_interval(varint);
    }
    if(sscanf(str, "wimpy %d", varint) == 1) {
      if(check_morph("tetrapod")) return 1;
      if(check_morph("spiral")) return 1;
      if(varint < 0 || varint > 90) {
        write("Wimpy percentage range is 0 - 90. Zero turns guild wimpy OFF.\n"); return 1;
      }
      write("Wimpy percentage set to " + varint + "%.\n");
      if(!varint) write("Guild wimpy now turned OFF.\n");
      gob->set_wimpy_pct(varint);
    }
  gob->record_attribs();
  return 1;
  }

  write("\n");
  write(">> Variable settings: ------------<<\n\n");
  write("  doing      " + (gob->query_doing()) + "\n");

/*
  write("  lines      " + (gob->query_screen_height()) + "\n");
*/
  write("  msgin      " + (gob->query_msgin()) + "\n");
  write("  msgout     " + (gob->query_msgout()) + "\n");
  write("  monitor    " + (gob->query_monitor_interval()) + "\n");
  write("  nickname   " + (gob->query_nickname()) + "\n");
  write("  panic      " + (gob->query_panic_key()) + "\n");
  write("  pretitle   " + (this_player()->query_pretitle()) + "\n");
  write("  statkey    " + (gob->query_superstat_key()) + "\n");
  write("  sig        " + (gob->query_sig()) + "\n");
  write("  title      " + (this_player()->query_title()) + "\n");
  write("  wimpy      " + (gob->query_wimpy_pct()) + "\n");

  write(">>--------------------------------<<\n");
  return 1;
}

/* ---- INFO FUNCTIONS NOW --- */

info_function(str) {
  string testj, temp, tempd;
  if(!str) {
    cat(HELPDIR + "info");
    return 1;
  }
  if(str) {
    if(sscanf(str, "guild %s", testj) == 1) temp = HELPDIR + "guild_" + testj;
    if(sscanf(str, "polymorph %s", testj) == 1) temp = HELPDIR + "poly_" + testj;
    if(sscanf(str, "poly %s", testj) == 1) temp = HELPDIR + "poly_" + testj;
    if(!temp) {
      temp = HELPDIR + str;
    }

  }
  cat(temp);
  return 1;
}

/* ---- GUT FUNCTIONS NOW --- */

/* ---- The part that actually processes new stats --- */


do_polymorph(lv,cost,chan,str,arg) {
  object morpho,gob;
  string gfile,passes,rchan;
  int rstat,cnt,strtemp,strtemp2,rcost;
  if(!check_level(lv)) return 1;
  gob = present(GUILD_ID, this_player());
  if(!gob) return 0;
  rcost = cost;
  rchan = chan;
  rstat=allocate(6);
  cnt=0;
  if(gob->query_charge() < rcost) {
    write("There is'nt enough energy in the clay to help you polymorph.\n"+
    "This form requires [" + rcost + "] charges.\n");
    return 1;
  }
  if(sscanf(str, "%s#%d#%d#%d#%d#%d#%d", gfile, rstat[0], rstat[1], rstat[2],
    rstat[3], rstat[4], rstat[5]) != 7) return 0;

  passes=allocate(6);
  passes[0]="stamina";
  passes[1]="intelligence";
  passes[2]="magic_aptitude";
  passes[3]="strength";
  passes[4]="stealth";

  passes[5]="luck";

  morpho=clone_object(PATHNAME + gfile);
  move_object(morpho, this_player());
  remote_say((this_player()->query_name()) + " contorts and polymorphs into a " + gfile + ".\n");

/* BREAK for strength-carry checking. */

  strtemp = call_other(this_player(), "query_attrib", "str");
  strtemp2 = strtemp + rstat[3];
  if(strtemp2 < strtemp) check_inventory_weight(strtemp - strtemp2);

  while(cnt < 5) {
    int tempv,tempw;
    tempv = call_other(this_player(), "query_attrib", extract(passes[cnt], 0, 2));
    tempw = tempv + rstat[cnt];
    if(tempw < 1) tempw = 1;
    call_other(this_player(), "set_attrib", extract(passes[cnt], 0, 2), tempw);
    cnt ++;
  }

  gob->add_charge(-rcost);
  gob->set_morph_comm(rchan);
  gob->set_current_morph(gfile);
  gob->set_title(this_player()->query_title());

  if(this_player()->query_pretitle()) gob->set_pretitle(this_player()->query_pretitle());

  this_player()->set_pretitle("|");
  this_player()->set_title("the " + gfile);
  this_player()->reset(1);

  if(arg) write(arg);

  write("Type 'class' to see your new abilities.\n");
  
  gob->record_attribs();
  morpho->tick();
  check_points();
  write("\n->> ");
  return 1;
}



/* ---- bring a player back from polymorph --- */

undo_polymorph(arg) {
  object morpho,gob,vic;
  string gfile,passes,gtemp;
  int rstat,cnt,strtemp;
  cnt=0;
  rstat=allocate(6);

  if(arg) vic = arg;
  else vic = this_player();
  gob=present(GUILD_ID, vic);
  if(!gob) return 0;
  if(gob->query_current_morph() =="none" || !gob->query_current_morph()) {
    tell_object(vic, "You are not polymorphed as anything.\n");
    return 1;
  }
  gfile=gob->query_main_stats();
  if(sscanf(gfile, "%s#%d#%d#%d#%d#%d#%d", gtemp, rstat[0], rstat[1], rstat[2], 
    rstat[3], rstat[4], rstat[5]) != 7) return 0;

  passes=allocate(6);
  passes[0]="stamina";
  passes[1]="intelligence";

  passes[2]="magic_aptitude";
  passes[3]="strength";
  passes[4]="stealth";
  passes[5]="luck";

  morpho = present(MORPH_ID, vic);
  while(morpho) {
    destruct(morpho);
    morpho = present(MORPH_ID, vic);
  }

  remote_say("A " + (gob->query_current_morph()) + " fades and melts into " + (vic->query_name()) + ".\n");
  write("You relax and return to your normal shape.\n");

/* BREAK for strength-carry checking. */

  strtemp = call_other(vic, "query_attrib", "str");
  strtemp = strtemp - rstat[3];
  if(strtemp > 0) check_inventory_weight(strtemp,vic);

  while(cnt < 5) {
    int tempv;
    tempv = call_other(vic, "query_attrib", extract(passes[cnt], 0, 2));
    call_other(vic, "set_attrib", extract(passes[cnt], 0, 2), rstat[cnt]);
    cnt ++;
  }


  if(!present("soul", vic)) move_object(clone_object("obj/soul.c"), vic);
  gob->set_current_morph("none");
  if(gob->query_pretitle()) vic->set_pretitle(gob->query_pretitle());
  if(gob->query_title()) vic->set_title(gob->query_title());
  gob->set_morph_comm("vibe");
  gob->record_attribs();
  vic->reset(1);
  vic->set_heart_beat(1);
  check_points();
  return 1;
}

/* ---- compile attribs into a string to be broken down accessed whenever */

record_stats(arg) {
  object gob,vic;
  string tempq;
  if(arg) vic = arg;
  else vic = this_player();
  gob=present(GUILD_ID, vic);

  if(!gob) return 0; 
  tempq = gob->query_current_morph() + "#";
  tempq = tempq + vic->query_attrib("sta") + "#" +
  vic->query_attrib("int") + "#" +
  vic->query_attrib("mag") + "#" +
  vic->query_attrib("str") + "#" +
  vic->query_attrib("ste") + "#" +
  vic->query_attrib("luc");
  vic->set_guild_file(GUILDFILE);
  if(vic->query_pretitle())

    gob->set_pretitle(vic->query_pretitle());

  gob->set_title(vic->query_title());
  gob->set_main_stats(tempq);
  check_points(vic);
  gob->record_attribs();

  vic->save_me();
}

/* ---- when a player dies --- */

deduct_attrib(arg) {
  object ob,vic;
  if(arg) vic = arg;
  else vic = this_player();
  ob=present(GUILD_ID, vic);
  if(ob) return 0;
  undo_polymorph(vic);
  record_stats(vic);
  vic->reset(1);
}

/* ---- minor check sequences --- */

check_points(arg) {
  object vic;
  if(arg) vic = arg;
  else vic = this_player();
  if(vic->query_hp() > vic->query_mhp()) {
    vic->add_hit_point(-(vic->query_hp() - vic->query_mhp()));
  }
  if(vic->query_sp() > vic->query_msp()) {
    vic->add_spell_point(-(vic->query_sp() - vic->query_msp()));
  }
}

check_level(arg) {
  if(this_player()->query_pl_k() && this_player()->query_level() < 20) {
    write("You fail.\n(You are a playerkiller!)\n");
    return 0;
  }
  if(this_player()->query_guild_rank() < arg) {
    if(arg > 9) write("You fail.\n");
    else write("You must be guild level [" + arg + "] to do this.\n");
    return 0;
  } else return 1;
}

check_sp(arg) {
  if(this_player()->query_sp() < arg) {
    write("You feel too drained to attempt this.\n");
    return 0;
  } else return 1;
}


check_dead() {
  if(this_player()->query_ghost()) {
    write("You are phased as a ghost.\n");

    return 1;
  } else return 0;
}

check_morph(str) {

  object gob;
  gob = present(GUILD_ID, this_player());
  if(!gob) return 0;
  if(gob->query_current_morph() == str) {
    write("You cannot do that in your current polymorph.\n");
    return 1;

  } else return 0;
}

/* ---- compensates and recalcs weight for when player's strength
        changes as a result of polymorph ---*/

check_inventory_weight(str,arg) {
  object vic,ob,next_ob;
  int rem_weight,new_max,new_str,max;
  int lev,curr_str;

  new_str = str;
  if(arg) vic = arg;
  else vic = this_player();

/* First count up how much stuff player has, since no provision is made

 * in the living.c or player.c
 */

  ob = first_inventory(vic);
  while(ob) {
    next_ob = next_inventory(ob);
    rem_weight = rem_weight + (ob->query_weight());
    ob = next_ob;
  }

/* Determine carry limits before and after.
 */

  lev = vic->query_level();

  curr_str = vic->query_attrib("str");
  max = lev + 6 + (curr_str / 5);
  new_max = lev + 6 + ((curr_str - new_str) / 5);
  if(vic->query_frog()) {
    max = max / 2;
    new_max = new_max / 2;
  }
  if(rem_weight > new_max) {

/* Now drop items until new weight limit is satisfied. */

    ob = first_inventory(vic);
    while(ob) {
      next_ob = next_inventory(ob);
      if(rem_weight > new_max && !ob->drop()) {
        rem_weight = rem_weight - (ob->query_weight());
        move_object(ob, environment(vic));
        remote_say((vic->query_name()) + " drops " + lower_case(ob->short()) + ".\n");

        write((ob->short()) + " is too heavy.\n");
        this_player()->add_weight(-(ob->query_weight()));
      }
      ob = next_ob;

    }
  }
  return 1;
}

/* ---- remove weapons or armor or both --- */


unready_items(armor,weapon) {
  object ob;
  if(armor) write("You remove your worn armors.\n");
  if(weapon) {
    write("You unready your wielded weapon.\n");
    this_player()->stop_wielding();
  }
  ob = first_inventory(this_player());
  while(ob) {
    object oc;

    oc = ob;

    ob = next_inventory(ob);
    if(armor && oc->armor_class()) oc->drop("silently");
  }
}

/* ---- return living object, shortens code --- */

get_living(arg,str) {
  object ob;
  ob = present(arg, environment(this_player()));
  if(!ob) {
    write("You ponder.\nThere is no such creature nearby.\n");
    return 0;
  }

  if(!living(ob)) {
    write((ob->short()) + " is not a living thing!\n");
    write("You cringe in bogglement.\n");
    return 0;
  }
  if(str && ob->query_npc()) {
    write((ob->query_name()) + " is not a player!\n");
    return 0;
  }
  return ob;
}

/* ---- player can 'say' to environment. --*/

remote_say(str) {
  this_player()->remote_say(str);
  return 1;
}

/* ---- called when player enters the game --- */

entrance(arg) {
  object gob,ob;
  ob = arg;
  gob=present(GUILD_ID, ob);

  if(!gob) return 0;
  if(gob->query_current_morph() == "[LEFT]" || gob->query_current_morph() == "[BANISHED]") {
    ob->set_guild_file(0);
    destruct(gob);
    return 1;
  }
  if(ob->query_pl_k() && ob->query_level() < 20) {
    tell_object(ob, " >> You are a PLAYERKILLER!\n"+

    "    You will be unable to use most guild powers.\n");

  }
  if(ob->query_pregnancy()) {
    tell_object(ob, " >> You are pregnant!\n"+
    "    You will be unable to polymorph until you give birth.\n");
  }
/*
  undo_polymorph(ob);
 */
  command("revert", ob);
  tell_object(ob, MOTD + "\n->> ");
  return 1;
}

/* ---- WIZARD - GC POWER SPELLS NOW --- */

promo_player(str) {

  object vct,gob;
  string plyr;
  int amt_promo,temp;
  if(!str) return 0;
  if(this_player()->query_level() < 20) return 0;
  if(sscanf(str, "%s %d", plyr, amt_promo) != 2) {
    write("Format: promo <plyr> <levels>\n");
    return 1;
  }
  vct = find_player(plyr);
  if(!vct) {
    write("Player not found.\n");
    return 1;

  }
  gob=present(GUILD_ID, vct);
  if(!gob) {

    write("That player is not in the guild.\n");

    return 1;
  }
  temp = vct->query_guild_rank() + amt_promo;
  if(temp < 1 || temp >= GC) {
    write("That is an invalid amount.\n");
    return 1;
  }
  vct->add_guild_rank(amt_promo);
  record_stats(vct);

  write_file(LOGPATH + "PROMOS", (this_player()->query_real_name()) + " promoted " +
    (vct->query_real_name()) + " " + amt_promo + " levels to glevel " + (vct->query_guild_rank()) +
    " on " + ctime() + "\n");
  write("Done.\n");
  return 1;
}

all_player_charges() {
  object ob;
  string temp;
  int i;
  temp = ">>--------------------------------------<<\nPlayer\tCharges\n";
  ob = users();
  for(i = 0; i < sizeof(ob); i++) {

    object gob;
    gob = present(GUILD_ID, ob[i]);
    if(gob)
      temp = temp + capitalize(ob[i]->query_real_name()) + "\t[" + gob->query_charge() + "]\n";
    i++;
  }
  write(temp +">>--------------------------------------<<\n");
}

/* ---- GUILD POWER SPELLS NOW --- */

/* ---- FOLLOW A PLAYER --- */

follow(str) {
  object old_follow_ob,follow_ob,gob;
  gob = present(GUILD_ID, this_player());
  if(!gob) return 0;
  if(check_dead()) return 1;
  old_follow_ob = gob->query_follow_ob();
  if(old_follow_ob) {
    write("Follow turned OFF.\n");
    gob->set_follow_ob(0);
    if(!str) return 1;
  }
  follow_ob = find_player(str);
  if(!follow_ob) {
    write("There is no such player logged on.\n");
    return 1;
  }
  if(follow_ob == this_player()) {
    write("You chase your tail around the room.\n");
    return 1;
  }
  if(environment(follow_ob) != environment(this_player())) {
    write("That player must be in the same room first.\n");
    return 1;
  }
  if(environment(this_player())->query_realm() == "NT") {
    write("Something in this room is preventing you from following.\n");
    return 1;
  }
  write("You are now following " + capitalize(str) + ".\n");
  gob->set_follow_ob(follow_ob);
  return 1;
}


/* ---- REGAIN [1] convert a corpse into matter (some gold coins) or

        energy into the clay as charges --- */


regain_corpse() {
  object ob,gob;
  int x,i;
  if(check_dead()) return 1;
  if(check_morph("sponge")) return 1;
  if(!check_sp(REGAIN_COST)) return 1;
  ob=present("corpse", this_player());
  if(!ob) {
    ob=present("corpse", environment(this_player()));
    if(!ob) {
      write("There is no corpse to regain energy from present.\n");

      return 1;
    }
  } else {
    this_player()->add_weight(-(ob->query_weight()));
    remote_say((this_player()->query_name()) + " drops the corpse.\n");
  }
  this_player()->add_spell_point(-REGAIN_COST);
  gob = present(GUILD_ID, this_player());
  if(!gob) return 0;
  i = this_player()->query_attrib("wil") * 5;
  x= (i * ob->heal_value()) / 100;
  if(gob->query_drain()) {
    write("You phase the matter of the corpse into some gold coins.\n");
    remote_say((this_player()->query_name()) + " turns a corpse into some gold coins!\n");
    destruct(ob);
    ob=clone_object("obj/money");
    ob->set_money(x * 2);
    move_object(ob, environment(this_player()));
    return 1;
  } else {
    write("You charge the matter energy of the corpse into your sphere.\n"+
    "It begins to glow and shrink, as its matter is converted to pure energy.\n");
    remote_say((this_player()->query_name()) + " kneels to the ground next to " + lower_case(ob->short()) + ".\n");

  remote_say("It shrivels and disappears.\n");
    gob->add_charge(x);
    write("There are [" + (gob->query_charge()) + "] charges in the clay's matrix.\n");
    destruct(ob);
    return 1;


  }
}

/* ---- ATOMIZE [3] nuke objects for their worth in healing or gold --- */


fast_Do(str) {
  string a1,a2,a3,a4,a5;
  if(!str) {
    write("Usage is 'Do <cmd1>,<cmd2>,<cmd3>...'\n"+
    "  Directional commands such as 'n,s,e,w,u,d' are the only types allowable.\n"+
    "  Limits of execution are 5 commands at once.\n");
    return 1;

  }
  write("You phase yourself into a gas.\n");

  if(sscanf(str, "%s,%s,%s,%s,%s", a1, a2, a3, a4, a5) == 5) {
    exe(a1); exe(a2); exe(a3); exe(a4); exe(a5);
  } else if(sscanf(str, "%s,%s,%s,%s", a1, a2, a3, a4) == 4) {
    exe(a1); exe(a2); exe(a3); exe(a4);

  } else if(sscanf(str, "%s,%s,%s", a1, a2, a3) == 3) {
    exe(a1); exe(a2); exe(a3);
  } else if(sscanf(str, "%s,%s", a1, a2) == 2) {
    exe(a1); exe(a2);
  } else exe(str);
  write("You rephase yourself into a more solid form.\n");
  return 1;
}

static exe(str) {
  string cmd;
  cmd = str;
  if(!cmd) return 0;

  if(cmd == "n" || cmd == "s" || cmd == "e" || cmd == "w" || cmd == "u" || cmd == "d" ||
  cmd == "nw" || cmd == "ne" || cmd == "sw" || cmd == "se" || cmd == "in" || cmd == "out")
    command(cmd, this_player());
  else write("You fail.\n");

  return 1;
}


atomize_object(str) {
  object ob,gob;
  int x,i;
  if(check_dead()) return 1;
  if(check_morph("wombat")) return 1;
  if(check_morph("sponge")) return 1;
  if(!check_level(3)) return 1;
  gob = present(GUILD_ID, this_player());
  if(!gob) return 0;
  if(!str) {
    write("Atomize what?\n");
    return 1;
  }
  ob = present(str, this_player());
  if(!ob) {
    ob = present(str, environment(this_player()));
    if(!ob) {
      write("You have no such item.\n");
      return 1;
    }
    write("You must get it first!\n");
    return 1;
  }

  if(ob->drop() || !ob->get()) {
    write("You fail.\n");
    return 1;
  }
  if(!check_sp(ATOMIZE_COST)) return 1;
  i = this_player()->query_attrib("pie") * 5;
  x = (i * (ob->query_value())) / 100;
  remote_say((ob->short()) + " is systematically absorbed by " + (this_player()->query_name()) + ".\n");
  this_player()->add_weight(-(ob->query_weight()));
  if(gob->query_drain()) {
  x = ob->query_value();
  if(x > 1500) x = random(500) + 1000;
  this_player()->add_money(x);
    write("You phase the matter and energy contained within " + lower_case(ob->short()) +
    " into [" + x + "] gold coins.\n");
  } else {
    x = x / (70 - this_player()->query_attrib("wil"));
    this_player()->heal_self(x);
    write("The energy contained within " + lower_case(ob->short()) + " heals you somewhat.\n");
    superstat(this_player());
  }
  destruct(ob);
  return 1;
}


/* ---- CHARGE [1] charges vital for polymorph functions ---*/

charge_clay(arg) {
  object ob,gob;
  int x;
  if(check_dead()) return 1;
  gob = present(GUILD_ID, this_player());
  if(!gob) return 0;
  if(gob->query_current_morph() != "none") {
          if(gob->query_current_morph() != "wombat") {
    write("You must not be polymorphed to do this.\n");
    return 1;
    }
  }
  if(!arg) {
    write("You have [" + (gob->query_charge()) + "] charges in the clay.\n");
    return 1;
  }
  if(sscanf(arg, "%d", x) != 1) return 0;
  if(x < 1) {

    write("ZZZZZZZZZAAAAAPPP!!!\n\nOUCH!!\n");
    this_player()->add_exp(-500);
    return 1;
  }
  if(this_player()->query_sp() < x) {
    write("You don't have that many spell points!\n");
    return 1;
  }
  write("You divert [" + x + "] spell points of energy into the clay's matrix.\n");
  this_player()->add_spell_point(-x);
  gob->add_charge(x);
  write("There are [" + (gob->query_charge()) + "] charges in the clay.\n");
  return 1;
}

/* ---- SURVEY [2] scan room and nearby exits for stuff --- */

survey_area() {
  object room,temproom;
  string exits,tempg,temph,tempi;
  int i;
  if(check_dead()) return 1;
  if(!check_level(2)) return 1;
  if(!check_sp(SURVEY_COST)) return 1;
  room=environment(this_player());
  exits = room->query_dest_dir();
  if(!exits) {
    write("For some reason, you cannot survey this area.\n");
    return 1;
  }
  this_player()->add_spell_point(-SURVEY_COST);
  if(room->realm() == "NT" && 1 == random(3 + this_player()->query_guild_rank())) {
    write("You attempt to survey the area, but are suddenly distracted, and fail.\n");
    return 1;
  }
  write("You peer about intently.\n\n");
  remote_say((this_player()->query_name()) + " surveys the area carefully.\n");
  temph = environment(this_player())->short();

  if(temph && sscanf(temph, "Plane of Etherie%s", tempi) == 1) {
    while(i < sizeof(exits)) {
      temproom = find_object("/players/mizan/etheriel/ROOMS/" + exits[i]);
      if(temproom) {
        tempg = dump_inventory(temproom);
        if(tempg) write("Scanning " + exits[i] + " you find:\n" + tempg);
        else write("Scanning " + exits[i] + " find nothing.\n");
      }
      else write("Scanning towards " + exits[i] + " you find it is unexplored.\n");
      i++;
    }
  return 1;
  } else {
    i = 1;
    while(i < sizeof(exits)) {
      temproom = find_object(exits[i-1]);
      if(temproom) {
        tempg = dump_inventory(temproom);

        if(tempg) write("Looking " + exits[i] + " you find:\n" + tempg);
        else write("Looking " + exits[i] + " find nothing.\n");
      }
      else write("Looking " + exits[i] + " you find it is unexplored.\n");
      i = i + 2;
    }
    return 1;
  }
}

/* used by above */

static dump_inventory(arg) {

  object ob;
  string tempj;
  int lim;
  tempj = "";
  ob = first_inventory(arg);
  while(ob) {
    object oc;
    oc = ob;
    ob = next_inventory(ob);
    if(oc->short()) tempj = tempj + "\t" + (oc->short()) + ".\n";

    lim ++;
    if(lim > 12) {
      tempj = tempj + "\t[TRUNCATED]\n";
      break;
    }
  }
  return tempj;
}

/* ---- ETHER [3]
        players in my guild will have a natural edge over others
        in my castle. This spell allows fearsome movement. --- */

ether(str) {

  string temp,temp2;
  if(check_dead()) return 1;
  if(!check_level(3)) return 1;
  if(!check_sp(ETHER_COST)) return 1;
  this_player()->add_spell_point(-ETHER_COST);
  temp = environment(this_player())->short();


  if(!temp || sscanf(temp, "Plane of Etherie%s", temp2) != 1) {
    write("You are not within the ether-muck.\n");
    return 1;
  }
  if(str == "tempest") {
    write("A voice echoes: Doh! That would be HIGHLY stupid... Trust me.\n");
    return 1;
  }
/*
  Not TOO godlike... reduced to keep castle mem use in check */
  call_other("/players/mizan/etheriel/ROOMS/" + str, "???");
   if(!find_object("/players/mizan/etheriel/ROOMS/" + str)) {
/*
    write("A voice echoes: There is no such area within the ether-muck.\n");
 */
     write("You know such a place exists but are not too sure how to get there.\n");
     return 1;
  }
  write("You move your matter towards destination " + str + ".\nA voice echoes: Here ya go.\n");
  this_player()->move_player("somewhere#players/mizan/etheriel/ROOMS/" + str);
  return 1;
}

/* ---- HELPME [>3] spots your location so other guild members can help. */

helpme() {
  object ob,gob;
  int i;
  string tmp;
  gob = present(GUILD_ID, this_player());
  if(!gob) return 0;
  if(check_dead()) return 1;
  if(this_player()->query_guild_rank() > 3) {
    write("You are too powerful to use this ability now.\n");

    return 1;
  }
  if(!this_player()->query_attack()) {
    write("Relax! You're not fighting anything.\n");
    return 1;
  }
  if(this_player()->query_exp() < HELPME_COST) {
    write("You don't have enough experience!\n");
    return 1;
  }
  if(gob->query_muffle()) {
    write("You were muffled! Overriding muffle!\n");
    gob->toggle_muffle();
  }
  this_player()->add_exp(-HELPME_COST);
  ob = first_inventory(environment(this_player()));
  while(ob) {
    object oc;
    oc = ob;

    ob = next_inventory(ob);
    if(this_player()->query_attack() != oc && oc->query_attack() == this_player()) i ++;

  }
  tmp = "Help!! I'm fighting " + (this_player()->query_attack())->query_name();
  tmp = tmp + " at '" + (environment(this_player())->short()) + "'";
  if(i) tmp = tmp + " with " + i + " enemies present!\n";
  else tmp = tmp + "!\n";
  guild_tell(tmp);
  return 1;
}


/* ---- SUPERWHO [2] nasty and long and cpu-intensive.. but better
        than other shit-whos IMHO */

superwho(str) {
  object ob;
  string toast;
  int wizzes,peeps,v,unlock;
  if(!check_level(2)) return 1;
  ob=users();

  write("\n>>Superwho----------------------------------------------------------------<<\n");
  write("Name\t\t Lev Sex P/K  Guild      ");

/* parse cmd line */
  if(str) {
    if(sscanf(str, "%s -u", toast) == 1) unlock = 1;

    /* wizzes only get sitename or ip info */
    if(this_player()->query_level() > 20) {
      if(str == "/ip") write("IP Number");
      if(str == "/s") write("Sitename");
    }
    if(str == "/a") write("Attacker");
    if(str == "/c") write("Condition");
    if(str == "/p") write("Height (',\"), Weight (lbs)");
  } else write("Current location");

  write("\n");
  for(v=0; v<sizeof(ob); v++) {
    string tempr;
    string temps;
    int lv;
    tempr = "";
    if(environment(ob[v]) && ob[v]->query_name() && ob[v]->query_gender()) {
      if(!ob[v]->query_invis() || ob[v]->query_invis() < 19) {
      if(ob[v]->query_ghost()) tempr = tempr + "@";
      if(query_idle(ob[v]) >= 5 * 60) tempr = tempr + "=";
      if(in_editor(ob[v])) tempr = tempr + "*";
      tempr = tempr + capitalize(ob[v]->query_real_name()) + "\t";
      if(strlen(tempr) < 9) tempr = tempr + "\t";
      lv = ob[v]->query_level();
      if(lv < 10) tempr = tempr + "   " + lv + "  ";

      if(lv > 9 &&  lv< 20) tempr = tempr + "  " + lv + "  ";
      if(lv > 19) {
        if(lv == 20) tempr = tempr + "Frob  ";
        if(lv > 20 && lv < 60) tempr = tempr + " Wiz  ";

        if(lv > 59 && lv < 100) tempr = tempr + "EWiz  ";
        if(lv > 99 && lv < 1000) tempr = tempr + "SWiz  ";
        if(lv > 999 && lv < 10000) tempr = tempr + "Arch  ";
        if(lv > 9999 && lv < 50000) tempr = tempr + " God  ";
        if(lv > 49999) tempr = tempr + "GOD!  ";
        wizzes = wizzes + 1;
      }
      tempr = tempr + capitalize(extract(ob[v]->query_gender(), 0, 0)) + "   ";
      if(ob[v]->query_pl_k()) tempr = tempr + "Y   ";
      else tempr = tempr + "N   ";
      if(ob[v]->query_guild_name() && strlen(ob[v]->query_guild_name()) > 1) {
      if(!toast && strlen(ob[v]->query_guild_name()) > 7) tempr = tempr + extract((ob[v]->query_guild_name()), 0, 7) + ".\t";
      else tempr = tempr + (ob[v]->query_guild_name()) + "\t";
      } else tempr = tempr + "none\t";
        if(str) {
          if(str == "/ip" && this_player()->query_level() > 20) temps = "(" + query_ip_number(ob[v]) + ")";
          if(str == "/s" && this_player()->query_level() > 20) temps = query_ip_name(ob[v]);
          if(str == "/a") {
                object ty;
                ty = ob[v]->query_attack();
                temps = "";
                if(ty) {
                  temps = temps + superstat_colorize((ty->query_hp() * 100) / ty->query_mhp());
                  if(ty->short()) temps = temps + (ty->short());
                  else temps = temps + "Someone";
                }
              else temps = temps + "(Not fighting)";
              temps =  temps + ESC + "[0m";
          }
          if(str == "/p") {
            int ft,ic,lb;
            ft = ob[v]->query_phys_at(1);
            ic = ob[v]->query_phys_at(2);

            lb = ob[v]->query_phys_at(3);
            if(ob[v]->query_level() < 21) {
              temps = ft + " feet " + ic + " inches, " + lb + " lbs.";

            } else temps = "(Unknown)";
          }  
          if(str == "/c") {
            int tsa,tsm;
            tsa = ob[v]->query_hp();
            tsm = ob[v]->query_mhp();
            if(tsa < tsm/10) temps = superstat_colorize(10) + "In very bad shape.";
            if(tsa < tsm/5) temps = superstat_colorize(25) + "In bad shape.";

            if(tsa < tsm/2) temps = superstat_colorize(45) + "Is somewhat hurt.";
            if(tsa < tsm - 20) temps = superstat_colorize(85) + "Is slightly hurt.";

        if(tsm == tsa) temps = ESC + "[32m" + "In good shape.";
            if(ob[v]->query_ghost()) temps = "Dead.";
/* CHANGED by mizan, this spell should check for levels. */
            if(ob[v]->query_level() > this_player()->query_level()) temps = "(Unknown)";
            if(ob[v]->query_level() > 20) temps = "(Not applicable)";
          }
        } else temps = (environment(ob[v]))->short();
        if(!temps) if(str) temps = " "; else temps = "(not available)";

        if(!unlock && strlen(temps) > 34) tempr = tempr + (extract(temps, 0, 34)) + ".\n";
        else tempr = tempr + temps + "\n";
        peeps = peeps + 1;

      }
      write(tempr + ESC + "[0m");

    } else write("[Logon]\n");
  }
  write("\n>>- '*' is wizard editing, '=' is idle.                                -<<\n");
  write(">>-Players: [" + peeps + "] Wizards: [" + wizzes + "] Date [" + ctime() + "]          ");
  if(peeps < 10) write(" ");
  write("-<<\n");
  return 1;
}

/* ---- modified player score ---- */

do_score() {
  object gob;
  gob = present(GUILD_ID, this_player());
  if(!gob) return 0;
  if(check_dead()) return 1;
  this_player()->score();
  write("Guild rank:  \t[" + (this_player()->query_guild_rank()) + "]\n");
  write("Clay charges: \t[" + (gob->query_charge()) + "]\n");
  if(!gob->query_current_morph()) gob->set_current_morph("none");
  if(gob->query_current_morph() != "none") write("Current polymorph: [" +
    capitalize(gob->query_current_morph()) + "]\n");
  else write("You are not polymorphed.\n");
  if(gob->query_nickname() && gob->query_nickname() != "none")
    write("Your nickname is '" + (gob->query_nickname()) + "'.\n");
  write("Time: (USA CST) " + ctime() + "\n");
  if(gob->query_panic_key()) write("Panic key is '" + (gob->query_panic_key()) + "'.\n");
  if(gob->query_superstat_key()) write("Quick-Stat key is '" + (gob->query_superstat_key()) + "'.\n");
  if(gob->query_muffle()) write("Guild channel is OFF.\n");
  if(gob->query_invis()) write("Guild object is INVIS.\n");

  if(gob->query_drain()) write("Regain corpse toggled to MATTER.\n");
  else write("Regain corpse toggled to ENERGY.\n");
  return 1;
}

do_clock() {
  write("You look carefully at your clay and some words appear:\n");
  write("\nThe mud will reboot after 8 hours.\n");
  call_other("room/church","long","clock");
  write("\n");
  return 1;
}

superstat(moo, eep) {

  object atk,vc;
  string temp;
  int tpa,vh,vs,x,y;
  vc = moo;
  vh = (vc->query_hp() * 100) / vc->query_mhp();
  vs = (vc->query_sp() * 100) / vc->query_msp();
  temp = superstat_colorize(vh) + "HP<" + vc->query_hp() + "/" + vc->query_mhp() + "> ";
  temp = temp + superstat_colorize(vs) + "SP<" + vc->query_sp() + "/" + vc->query_msp() + "> ";

  if(vc->query_intoxination()) {
    y=vc->query_level() + 3;
    x=(vc->query_intoxination() * 100) / y;
    temp = temp + superstat_colorize_inv(x) + "I<" + x + "%> ";
  }
  if(vc->query_stuffed()) {
    y=vc->query_level() * 8;
    x=(vc->query_stuffed() * 100) / y;
    temp = temp + superstat_colorize_inv(x) + "F<" + x + "%> ";
  }
  if(vc->query_soaked()) {
    y=vc->query_level() + 3;
    x=(vc->query_soaked() * 100) / y;
    temp = temp + superstat_colorize_inv(x) + "S<" + x + "%> ";
  }
  if(vc->query_attack()) {
    atk=vc->query_attack();
    x=(atk->query_hp() * 10) / atk->query_mhp();
    temp = temp + superstat_colorize(x * 10) + "AHP<" + x + "/10 max>";
  }
  if(eep) {
    tpa = eep;
    temp = temp + superstat_colorize((tpa * 100) / 2300) + "CH[" + tpa + "]";
  }
  temp = temp + ESC + "[0m";
  tell_object(vc, temp + "\n");
}
superstat_window(arg,ht,eep) {
  object ob;
  ob = arg;
  tell_object(ob,

   ESC + "[H");
  superstat(ob, eep);
  tell_object(ob,
   ESC + "[H" +
   ESC + "[" + ht + "D");
}

superstat_colorize(x) {
  int j;
  j = x;
  if(j == 100) return ESC + "[32m";
  else if(j > 80) return ESC + "[1m" + ESC + "[32m";
  else if(j > 60) return ESC + "[33m";
  else if(j > 40) return ESC + "[1m" + ESC + "[33m";
  else if(j > 20) return ESC + "[31m";
  return ESC + "[5m" + ESC + "[31m";
}

superstat_colorize_inv(x) {
  int j;
  j = x;
  if(j == 100) return ESC + "[5m" + ESC + "[31m";
  else if(j > 80) return ESC + "[31m";
  else if(j > 60) return ESC + "[1m" + ESC + "[33m";
  else if(j > 40) return ESC + "[33m";

  else if(j > 20) return ESC + "[1m" + ESC + "[32m";
  return ESC + "[32m";
}

/* ---- SPDM.c  8< cut here--- */


/* ---- WOMBAT SPELLS --- */


spuckball_gobble(arg) {
  object mob, ob, room;
  mob = present(MORPH_ID, this_player());
  if(!mob) return 0;
  room = environment(this_player());
  if(!room) return 0;

  ob = present(arg, room);
  if(!ob) {
    write("You cringe in bogglement as there is no such item present.\n");
    return 1;

  }
  if(ob->drop() || !ob->get() || living(ob) || !ob->short()) {
    write("You cannot gobble that, for some reason.\n");
    return 1;
  }
  if(!mob->add_weight(ob->query_weight())) {
    write("Oof! You feel rather heavy already. Another item and you would burst.\n");
    return 1;
  }
  move_object(ob, mob);
  write("You gobble up " + lower_case(ob->short()) + "!\n");
  write("Yum.\n");
  remote_say((this_player()->query_name()) + " gobbles up " + lower_case(ob->short()) + "!\n");
  mob->burp_routine();

  return 1;
}

spuckball_spew(arg) {
  object mob, ob, room;
  mob = present(MORPH_ID, this_player());
  if(!mob) return 0;
  room = environment(this_player());
  if(!room) return 0;
  ob = present(arg, mob);
  if(!ob) {
    write("Funny, you don't remember gobbling up that item.\n");
    return 1;
  }
  mob->add_weight(-(ob->query_weight()));
  move_object(ob, room);
  write("You spew up " + lower_case(ob->short()) + "!\n");
  write("Ick.\n");
  remote_say((this_player()->query_name()) + " spews up " + lower_case(ob->short()) + "!\n");
  remote_say("It is covered in a thin layer of slimy goo. Ick.\n");
  return 1;
}

spuckball_squit(arg) {
  single_attack(SPUCKBALL_SQUIT_COST,arg,
  "You squit "," painfully up against a wall.",
  (this_player()->query_name()) + " squits "," painfully against a wall.");
  return 1;
}


wombat_sniff(str) {
  object ob;
  int i;
  if(!str) return 0;
  ob=present(str, environment(this_player()));
  if(!ob) {
    write("There is no '" + str + "' here.\n");

    return 1;
  }
  if(!living(ob)) {

    write((ob->short()) + " smells just like a " + str + ".\n");
    return 1;
  }
  write((ob->query_name()) + " ");
  i=ob->query_alignment();
  if(i > 750) write("smells like a bar of Ivory soap. Mmmm! 99 44/100% Pure!\n");
  if(i > 500 && i < 751) write("smells like a new air freshener. Pretty Good.\n");
  if(i > 250 && i < 501) write("smells like freshly done landry. It's okay.\n");

  if(i > 50 && i < 251) write("smells pretty nice.\n");
  if(i > 0 && i < 51) write("smells okay.\n");
  if(i == 0) write("has no detectable odor.\n");
  if(i > -50 && i < 0) write("smells somewhat okay, with a touch of nastiness.\n");

  if(i > -250 && i < -51) write("smells pretty grimy and generally unpleasant.\n");
  if(i > -500 && i < -251) write("carries a pretty heinous odor. Live in fear!\n");
  if(i > -750 && i < -501) write("bears evil like the foul stench of a decomposing tunafish.\n");

  if(i < -749) write("utterly reeks of evil, like a sewage treatment facility.\n");
  remote_say((this_player()->query_name()) + " sniffs " + (ob->query_name()) + " carefully.\n");
  tell_object(ob, (this_player()->query_name()) + " sniffs you from head to toe.\n");
  return 1;
}

#define WOMBAT_BURROW "players/mizan/closed/poly/wombat_burrow"
#define WOMBAT_BURROW_ENTRANCE "players/mizan/closed/poly/wombat_burrow_e"

wombat_dig() {
  object burrow,burrow_entrance,mob,room;
  if(check_dead()) return 1;
  if(!check_sp(WOMBAT_BURROW_COST)) return 1;
  mob = present(MORPH_ID, this_player());
  if(!mob) return 0;

  burrow = mob->query_burrow();
  if(!burrow) {
    burrow=clone_object(WOMBAT_BURROW);
    burrow->set_owner(this_player()->query_real_name());
    mob->set_burrow(burrow);
  }
  room = environment(this_player());
  if(!room) return 0;
  if(room->query_realm() == "NT") {
    write("Something in this room is preventing you from digging a tunnel.\n");
    remote_say((this_player()->query_name()) + " chomps on some dirt.\n");
    return 1;
  }
  this_player()->add_spell_point(-WOMBAT_BURROW_COST);
  if(this_player()->query_attack() && random(this_player()->query_attrib("ste")) < 5) {
    write("You are too busy fighting!\n");
    return 1;


  }
  if(!present("burrow", environment(this_player()))) {
  burrow_entrance=clone_object(WOMBAT_BURROW_ENTRANCE);
  burrow_entrance->set_owner(this_player()->query_real_name());
  move_object(burrow_entrance, environment(this_player()));
  }
  write("You begin digging furiously and arrive in your comfortable burrow.\n");
  remote_say((this_player()->query_name()) + " begins digging furiously and when the dust settles, disappears.\n");
  move_object(this_player(), burrow);
  remote_say((this_player()->query_name()) + " tumbles in.\n");
  command("look", this_player());
  return 1;
}


/* ---- WOMBAT DRAG --- */

#define LOOSEN_OBJECT "/players/mizan/closed/poly/wombat_drag.c"
#define LOOSEN_ID "drag_device"

wombat_drag(str) {

  object old_drag_ob,drag_ob,mob,testobj;
  mob = present(MORPH_ID, this_player());
  if(!mob) return 0;
  if(check_dead()) return 1;
  old_drag_ob = mob->query_drag_ob();
  if(old_drag_ob) {
    write("You stop dragging " + lower_case(old_drag_ob->short()) + ".\n");
    remote_say((this_player()->query_name()) + " stops dragging " + lower_case(old_drag_ob->short()) + ".\n");
    mob->set_drag_ob(0);
    testobj = present(LOOSEN_ID, old_drag_ob);
    if(testobj) destruct(testobj);
    if(!str) return 1;
  }
  drag_ob = present(str, environment(this_player()));
  if(!drag_ob) {

    write("There is no such object here.\n");

    return 1;
  }
  if(drag_ob == this_player()) {
    write("You pick yourself up by the rump and fall to the floor.\n");
    return 1;
  }
  if(!drag_ob->get()) {
    write("You can't drag that.\n");
    return 1;
  }
  write("You are now dragging " + lower_case(drag_ob->short()) + ".\n");
  remote_say((this_player()->query_name()) + " begins dragging " + lower_case(drag_ob->short()) + ".\n");
  mob->set_drag_ob(drag_ob);
  return 1;
}

wombat_forage() {
  if(!check_sp(WOMBAT_FORAGE_COST)) return 1;
  write("You dig the surrounding area furiously and find a potato!\n");
  remote_say((this_player()->query_name()) + " digs a hole carefully and finds a potato!\n");
  move_object(clone_object("players/mizan/etheriel/heals/raw-potato"), this_player());
  this_player()->add_spell_point(-WOMBAT_FORAGE_COST);
  return 1;
}

wombat_chomp(arg) {
  single_attack(WOMBAT_CHOMP_COST,arg,

  "You bare your teeth and viciously take chomp ","!",
  (this_player()->query_name()) + " chomps ", " and bites off some of its flesh!");
  return 1;
}

/* ---- SPONGE spells [3]--- */

sponge_sponge(arg) {
  object ob,atk;
  ob = get_living(arg);
  if(!ob) return 1;
  atk = ob->query_attack();
  if(!atk) {
    write((ob->query_name()) + " is not fighting anything.\n");
    return 1;
  }
/*  I disabled this for a reason.
    It is a defensive spell but is a guild power so it cannot be
    used in combat.
  if(!this_player()->valid_attack(atk)) return 1;
  But my guilders are not allowed to pk.
  So against logic and soundness of mind it has been disabled.
 */
  write("You are now sponging hits for " + (ob->query_name()) + ".\n");
  remote_say((this_player()->query_name()) + " slowly waddles in the way and starts sponging hits for " + (ob->query_name()) + ".\n");
  atk->attack_object(this_player());
  this_player()->attack_object(0);
  return 1;
}

/* ---- BLOBEL spells [3]--- */

blobel_confusion(arg) {
  single_attack(BLOBEL_CONFUSION_COST,arg,
  "You focus a bewildernoggling array of confusion and mentally assault ",".",
  (this_player()->query_name()) + " mentally fuzzles "," and leaves it a crying, whimpering mess.");
  return 1;
}

blobel_unfrog(arg) {
  object ob;

  if(!check_sp(BLOBEL_UNFROG_COST)) return 1;
  if(!arg) ob = this_player();
  else ob = get_living(arg,"player");
  if(!ob) return 1;
  if(!ob->query_frog()) {
    write((ob->query_name()) + " is not a frog.\n");

    return 1;
  }

  this_player()->add_spell_point(-BLOBEL_UNFROG_COST);
  write("You concentrate and attempt to alter polymorph the frog curse.\n");
  remote_say((this_player()->query_name()) + " goes into a deep lapse and general stupor.\n");

  ob->frog_curse();
  return 1;
}
 
/* ---- FUNGOID spells [3]--- */

fungoid_gribble(arg) {

  single_attack(FUNGOID_GRIBBLE_COST,arg,
  "You gribble wildly at "," and pause in secret delight watching it suffer.",
  (this_player()->query_name()) + " gribbles violently at ","!");
  return 1;
}

fungoid_puff(arg) {
  single_attack(FUNGOID_PUFF_COST,arg,
  "You puff a poisonous spore at ",".",

  (this_player()->query_name()) + " zoks "," with a poisonous spore!");
  return 1;
}

fungoid_spog(arg) {
  single_attack(FUNGOID_SPOG_COST,arg,
  "You detach a highly infectious viral spog at ","!",
  (this_player()->query_name()) + " detaches an infectious spog at "," with lethal accuracy!");
  return 1;
}


fungoid_spore(arg) {
  area_attack(60,arg,"You wiggle excitedly and eject a cloud of poisonous spores!\n",
  "ejects a cloud of poisonous spores!\n",
  "choke violently on the cloud!\n",
  "chokes violently on the cloud!\n",
  "flee in panic from the cloud!\n",
  "flees in panic from the cloud!\n",
  "escapes harm for some reason.\n",
  "seems unaffected by the cloud.\n",
  "The cloud fades and thins out from view.\n",
  "grins evilly.\n",
  "You try to eject some spores but nothing happens.\n",
  "wiggles excitedly but nothing happens.\n");

  return 1;
}

/* ---- PUFFBALL spells [4]--- */

puffball_fry(arg) {
  single_attack(PUFFBALL_FRY_COST,arg,
  "You belch a few billion amperes of electricity at ",".",
  (this_player()->query_name()) + " makes a Crispy "," with a few billion amperes of electricity!");
  return 1;
}

puffball_vaporize(arg) {
  single_attack(PUFFBALL_VAPORIZE_COST,arg,
  "With great effort and concentration,\nyou vector a matter detonation at ",".",
  (this_player()->query_name()) + " vectors a nuclear matter detonation at ",
  "!\nImagine a cigarette lighter exploding in your face. Ouch!");
  return 1;
}

puffball_nova(arg) {
  area_attack(200,arg,
  "You concentrate with all your might and every single particle\n"+
  "nearby you converts to pure energy (e = mc^2)!\n",
  "explodes in a blinding flash!\n"+
  "\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n"+
  "\tBB    BB  OO    OO  OO    OO  MMM   MMM  !!  !!\n"+
  "\tBBBBBBB   OO    OO  OO    OO  MM MMM MM  !!  !!\n"+
  "\tBB    BB  OO    OO  OO    OO  MM  M  MM  \n"+
  "\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n\n",

  "is struck head-on by a few trillion watts of energy. Fearsome.\n",
  "is reduced to a carbon cinder by the blast!\n",
  "blasted clear across the room!\n",
  "is blasted clear across the room!\n",
  "escapes harm for some reason.\n",
  "hits the dirt and escapes harm.\n",
  "You struggle but reform back into your current polymorph.\n",
  "fades into view.\n",
  "You goof, and time your explosion incorrectly. No one is affected.\n",
  "suddenly energizes but fades away just as quickly. It looked painful.\n");
  return 1;

}


puffball_gain(str) {
  int testh;
  if(sscanf(str, "hp %d", testh) == 1) {
    if(testh < 1 || testh > 1000) return 0;
    if(testh > this_player()->query_sp()) {
      write("You only have [" + this_player()->query_sp() + "] spell points.\n");
      return 1;
    }
    this_player()->add_spell_point(-testh);
    this_player()->add_hit_point(testh);
    write("You transfer [" + testh + "] units of energy for hitpoint gain.\n");
    return 1;
  }
  if(sscanf(str, "sp %d", testh) == 1) {
    if(testh < 1 || testh > 1000) return 0;
    if(testh > this_player()->query_hp()) {
      write("You only have [" + this_player()->query_hp() + "] hitpoints.\n");
      return 1;

    }
    if(this_player()->query_hp() - testh < 20) {
      write("Somehow, you cannot bring yourself to do this.\n");
      return 1;
    }
    this_player()->add_hit_point(-testh);
    this_player()->add_spell_point(testh);
    write("You transfer [" + testh + "] units of energy for spell point gain.\n");
    return 1;
  }

  write("Usage: 'gain hp <X>' to transfer <X> spell points to hitpoints.\n"+
  "\t'gain sp <X>' to transfer <X> hitpoints to spell points.\n");
  return 1;
}


puffball_finish() {
  object ob;

  int x;
  ob = this_player()->query_attack();

  if(!ob) {
    write("You must be fighting something first.\n");
    return 1;
  }
  if(ob->is_player()) {
    write("You cannot use this ability against other players.\n");

    return 1;
  }
 /* Make it so spell can only be used if monster is weaker than 10% */
  x = (ob->query_hp() * 100) / ob->query_mhp();
  if(x > 10) { 
    write((ob->query_name()) + " needs to be weakened somewhat more.\n");
    return 1;
  }
 /* 65 hps the the most damage the spell can do... with player at glev 5 */
  if((25 + (this_player()->query_guild_rank() * 8)) < ob->query_hp()) {
    write((ob->query_name()) + " is still too strong.\n");
    return 1;
  }
  if(!check_sp((ob->query_hp()))) return 1;

  this_player()->add_spell_point(-(ob->query_hp()));


/* Chance of failure dependent on willpower. */

  if(1 == random(this_player()->query_attrib("wil"))) {
    write("Ack! You somehow screw up and the energy gathered explodes in your face!\n");
    remote_say((this_player()->query_name()) + " begins to glow brightly but suddenly implodes!\n");

    remote_say("\n* * B O O M  ! ! ! * * * \n\nYou curse violently.\n");
    return 1;
  }
  write("With a daring lunge, you convert most of your puffball mass into pure\n"+
  "energy to strike a finishing shot to " + (ob->query_name()) + ".\n");
  remote_say((this_player()->query_name()) + " begins to glow brightly and explodes at " + (ob->query_name()) + "!\n");
  remote_say((ob->query_name()) + " is struck by a critically hitting blast!\n"); 
  remote_say((this_player()->query_name()) + " triumphantly strikes down " + (ob->query_name()) + ".\n");
  ob->hit_player(ob->query_hp());
  return 1;
}

/* ---- SHOUTBOX spells [4]--- */

shoutbox_bellow(arg) {
  area_attack(100,arg,
  "You take a deep breath...\n"+
  "Your lungs stretch like a weather baloon and then you release!\n"+
  "You bellow: aaAAAAAAAAAUUUUUUUUUGGGGGGHHHH!!!!!!\n",
  "takes a DEEP breath and HOLLERS at everyone in the room!\n",
  "get torn apart by the thundering bass. Neato!\n",
  "is torn apart by the thunderring bass!\n",

  "flung across the room by the deafening noise!\n",
  "is flung across the room by the deafening noise!\n",
  "flattened by the sound but emerges unscathed.\n",
  "is flattened by the sound but emerges unscathed.\n",
  "You take a few deep breaths to recover.\n",
  "takes a few deep breaths to recover.\n",
  "Your throat is too dry and the spell fails.\n",
  "takes a DEEP breath and tries to scream loudly but snarfs and sputters.\n");
  return 1;
}

shoutbox_shrill(arg) {
  single_attack(SHOUTBOX_SHRILL_COST,arg,
  "You emit a screeching, ultrahigh frequency yowl at ","!",
  (this_player()->query_name()) + " emits a sound about as unpleasant as fingernails being\n"+
  "dragged across a chalkboard! AAaaaauuugh!\n"," screams and grasps its ears in rabid pain!");
  return 1;
}


shoutbox_curse(arg) {
  string lang;
  int i;
  i=random(8);
  if(i == 1) lang = "broken swahili";

  if(i == 2) lang = "icelandic";
  if(i == 3) lang = "swedish";
  if(i == 4) lang = "arabic";
  if(i == 5) lang = "greek";
  if(i == 6) lang = "yiddish";
  if(i == 7) lang = "german";

  if(i == 8) lang = "japanese";
  single_attack(SHOUTBOX_CURSE_COST,arg,
  "You swear and curse profusely in " + lang + " at ",".",
  (this_player()->query_name()) + " utterly insults "," in " + lang +
  " to the point that it begins to sulk and whine piteously!");
  return 1;
}

shoutbox_superblink(arg) {
  single_attack(SHOUTBOX_SUPERBLINK_COST,arg,
  "You blink loudly.\n"," is dealt a devastating blow and winces in pain!.",
  (this_player()->query_name()) + " blinks loudly at ",
  " and it suddenly is taken aback by the shock!\n\t*  *  *  B  O  O  M  !  !  !  *  *\n");
  return 1;
}

shoutbox_reverb(arg) {

  single_attack(SHOUTBOX_REVERB_COST,arg,
  "You channel a painful reverb directly at ","!",
  (this_player()->query_name()) + " channels a painful reverb at ",
  " and it is ripped inside out from the whippingly painful sound!\n");
  return 1;

}

shoutbox_holler(arg) {
  object ob;
  if(!check_sp(SHOUTBOX_HOLLER_COST)) return 1;
  if(this_player()->query_attack()) {
    write("You are too busy fighting to do this.\n");
    return 1;
  }
  ob = get_living(arg);
  if(!ob) return 1;
  this_player()->add_spell_point(-SHOUTBOX_HOLLER_COST);

  write("You holler loudly at " + (ob->query_name()) + "!\n");
  remote_say((this_player()->query_name()) + " hollers loudly at " + (ob->query_name()) + "!\n");
  if(1 == random(this_player()->query_attrib("wil"))) return 1;
  if(ob->query_level() < this_player()->query_level()) {
    remote_say((ob->query_name()) + " flees in panic!\n");
    ob->run_away();
  } else {
    remote_say((ob->query_name()) + " is rather annoyed.\n");
    if(ob->query_npc()) ob->attack_object(this_player());

  }
  return 1;
}

shoutbox_calm() {
  object ob;
  if(!check_sp(SHOUTBOX_CALM_COST)) return 1;
  write("You scream: 'S T O P   F I G H T I N G ! !' at the top your lungs...\n");
  remote_say((this_player()->query_name()) + " hollers: S T O P   F I G H T I N G ! !\n");

  this_player()->add_spell_point(-SHOUTBOX_CALM_COST);
  if(1 == random(this_player()->query_attrib("wil"))) return 1;
  ob = first_inventory(environment(this_player()));
  while(ob) {
    object oc;
    oc = ob;
    ob = next_inventory(ob);
    oc->attack_object();
    oc->attack_object();
    oc->stop_fight();
    oc->stop_fight();
    oc->stop_hunter();
    oc->stop_hunter();
  }

  write("That felt dandy, did'nt it?\n");
  remote_say((this_player()->query_name()) + " does the disco duck.\n");
  return 1;

}

/* ---- BOGGLEMANCER spells [5]--- */

bogglemancer_speedball(arg) {
  single_attack(BOG_SPEEDBALL_COST,arg,
  "You create a huge fuzzy speedball and charge it up with electricity.\n"+

  "With the flick of the wrist you deftly hurl it at",".",
  (this_player()->query_name()) + " blasts ",
  " with a giant speedball of supercharged dryer lint!\nZZzzzZZzzZzzZZzZzzzZZAAAPPP!!!\n\n");
  return 1;
}

bogglemancer_zokwave(arg) {

  single_attack(BOG_ZOKWAVE_COST,arg,
  "You unleash some happy radiation at the general direction of ","!",
  (this_player()->query_name()) + " unleases a fearsome barrage of funky new radioactive particles.\n",
  " seems to melt and crackle in a Spuck-like way.");
  return 1;
}

bogglemancer_charbroil(arg) {

  single_attack(BOG_CHARBROIL_COST,arg,
  "Fearsome tongues of flame erupt around you as you superheat the air surrounding ",".",
  (this_player()->query_name()) + " lights the air surrounding ",
  " aflame\nand sets cooks it to a medium-rare crisp!\n" + (this_player()->query_name()) + " giggles inanely.");
  return 1;
}

bogglemancer_sandbag(arg) {
  single_attack(BOG_SANDBAG_COST,arg,
  "With great effort you create a heavy bag of sand and hurl it at ","!",
  "A heavy bag of sand drops from the sky and whacks "," silly!");
  return 1;
}

bogglemancer_tree(arg) {
  single_attack(BOG_TREE_COST,arg,
  "You create a tree and stuff it into a convenient orifice on ",".",
  (this_player()->query_name()) + " creates a tree and shoves it painfully somewhere into ",
  " !\nYou cringe at the sight.");
  return 1;
}

bogglemancer_lint(arg) {
  single_attack(BOG_LINT_COST,arg,
  "You force a wad of dryer lint down ","'s throat!",
  (this_player()->query_name()) + " shoves a thick wad of dryer lint down ","'s throat!");

  return 1;
}

bogglemancer_piano(arg) {
  single_attack(BOG_PIANO_COST,arg,
  "Principles of Painless distraction take over fully, and a grand piano\n"+

  "materializes, falling out of the sky only to crash into ","!",
  "A grand piano pops out of nowhere and comes crashing down onto ",".\nThat looked stupidly painful. Eep.");
  return 1;

}

bogglemancer_anvil(arg) {
  single_attack(BOG_ANVIL_COST,arg,

  "An anvil falls from the sky and comes crashing down on ",".",
  "You boggle bemusedly as an anvil suddenly falls from the sky on ",".");
  return 1;
}

/* ---- TETRAPOD SPELLS [5] --- */

tetrapod_raar(str) {
  object mob;
  int mhp,hp,sp,i,j;
  mob = present(MORPH_ID, this_player());
  if(!mob) return 0;
  hp = this_player()->query_hp();
  sp = this_player()->query_sp();
  mhp = this_player()->query_mhp();
  if(hp == mhp) {
    write("You raar loudly but nothing happens.\n");
    return 1;
  }
  if(!str) i = (sp / 2);
  else if(sscanf(str, "%d", i) !=1) return 0;
  j = i * 2;
  if(!check_sp(j)) return 1;
  this_player()->add_spell_point(-j);
  this_player()->add_hit_point(i);
  write("You deep dig down and revitalize yourself with a burst of explosive energy!\n"+
  ESC + "[1m" + ESC + "[31m" + "You go: 'RAAAAAR!'\n" + ESC + "[0m");
  remote_say(ESC + "[1m" + ESC + "31m" + (this_player()->query_name()) + " goes: 'RAAAAR!'\n"+
  ESC + "[0m" + (this_player()->query_name()) + " suddenly appears revitalized!\n");
  return 1;
}

tetrapod_blitz(arg) {
/* Gain an extra attack on monsters */
  int i;
  object ob,mob,victim,weapon;
  if(!check_sp(TETRAPOD_BLITZ_COST)) return 1;
  mob = present(MORPH_ID, this_player());
  if(!mob) return 0;
  if(!arg) victim = this_player()->query_attack();
  else {
    victim = get_living(arg);
    if(!this_player()->valid_attack(victim)) return 1;
    if(victim->is_player()) {
      write("You cannot use this ability against other players.\n");
      return 1;

    }
  }
    if(!victim) {
    write("Blitz who?\n");
    return 1;
  }
  weapon = mob->query_weapon_list();
  write("You explode into a furious frenzy!\n");
  remote_say((this_player()->query_name()) + " breaks into an uncontrollable fury!\n");
  while(i < sizeof(weapon)) {
    if(1 == random(3)) write("You scream loudly!\n");
    else if(1 == random(3)) write("You attack with a god-like fury!\n");
    else write("You descend upon your foe with a fearsome wrath!\n");
    if(weapon[i]) extra_hit((2 * weapon[i]->weapon_class()), i, victim);
    if(weapon[i] && 1 == random(2)) extra_hit(weapon[i]->weapon_class(), i,victim);
    i++;
  }
  this_player()->add_spell_point(-TETRAPOD_BLITZ_COST);
  remote_say("You cringe in terror.\n");
  write("You feel spent, but are gleeful at the pain and damage you have caused.\n");

  remote_say((this_player()->query_name()) + " begins panting heavily, and says: 'Wicked'.\n");
  return 1;
}

/* ---- SPIRAL SPELLS [6] --- */

spiral_xpower() {

/* Enhanced attack per round, uses all sps */
   object mob,victim;
  int pot_dam;
  pot_dam = this_player()->query_msp();
  mob = present(MORPH_ID, this_player());
  if(!mob) return 0;
  if(!check_sp(pot_dam)) return 1;
  victim = this_player()->query_attack();
  if(!victim) {
    write("You must be fighting something first.\n");
    return 1;
  }
  if(victim->is_player()) {
     write("You cannot use this ability against other players.\n");
     return 1;
  }
/* Charges the MOB for a certain amt of attacks */
  mob->charge_spiral_xpower(pot_dam / 60);
  this_player()->add_spell_point(-pot_dam);
  write("Zzzzzaaaap! Every spellpoint converts into a blinding burst\n"+
    "of explosive, crackling energy...\nYou throw your head back and cackle gleefully!\n");

  write("You explode into a headstrong, all out attack on " + (victim->query_name()) + "!\n");
  remote_say((this_player()->query_name()) + " is suddenly enveloped in a blinding, deafening flash!\n\n");
  remote_say((this_player()->query_name()) + " bursts into a rhythmic frenzy and all out assault on " +

  (victim->query_name()) + "!\n");
  return 1;
}

spiral_switch(arg) {
/* Switch places with another player attacking something */

  object ob, victim;
  if(!check_sp(SPIRAL_SWITCH_COST)) return 1;
  ob = present(arg, environment(this_player()));
  if(!ob) return 0;
  if(!living(ob)) {
    write("You boggle in discontent.\n");
    return 1;
  }
  victim = ob->query_attack();
  if(!victim) {
    write((ob->query_name()) + " is not fighting anything!\n");
    return 1;
  }
  if(!this_player()->valid_attack(victim)) return 1;
  write("You switch phases with " + (ob->query_name()) + "!\n");
  remote_say((this_player()->query_name()) + " begins a strange dance and bodies switch around.\n");
  ob->stop_fight();
  ob->stop_fight();
  ob->stop_hunter();
  ob->stop_hunter();
  this_player()->attack_object(victim);
  victim->attack_object(this_player());
  this_player()->add_spell_point(-SPIRAL_SWITCH_COST);
  return 1;
}

spiral_swords(arg) {
/* Turn weapons into missile objects */
  object junk,mob,victim;
  int i;
  mob = present(MORPH_ID, this_player());

  junk = arg;
  if(!mob) return 0;
  if(!junk) {
    write("You don't have any weapons strapped!\n");
    return 1;
  }
  victim = this_player()->query_attack();
  if(!victim) {
    write("You are not fighting anything!\n");
    return 1;
  }
  if(victim->is_player()) {
     write("You cannot use this ability against other players.\n");
     return 1;
  }
/* Begin attack */
  write("You release your strapped weapons as missiles against " + (victim->query_name()) + "!\n");
  remote_say((this_player()->query_name()) + " utters a short mantra... 'Dancing Swords!'\n");
  while(i < sizeof(junk)) {
    object ob;
    int dam;
/* Cycle through elements of array */
    ob = junk[i];
    if(ob) {
      dam = ob->query_value();
      if(dam) {

        dam = dam / 60;
        if(dam > 20) dam = 20;
/* Treat each attack as a separately cast spell */
        single_attack(dam,victim,
        (ob->short()) + " phases into a dancing sword and launches itself at ","!",
        (ob->short()) + " turns into a dancing sword and launches itself at ","!");
      } else {
        write((ob->short()) + " bounces harmlessly from " + (victim->query_name()) + ".\n");
        remote_say("A dancing sword bounces harmlessly away from " + (victim->query_name()) + ".\n");
      }
/* Recalc weight & destruct */
      this_player()->add_weight(-(ob->query_weight()));
      destruct(ob);
      junk[i] = 0;
    }
    i++; 
  }
  remote_say((this_player()->query_name()) + " smiles wickedly.\n");
  mob->set_weapon_list(junk);
  return 1;
}

spiral_multihit() {
/* Attacks everything in the room once with each limb */
  object mob,weapon,ob,room;
  int i;
  int dam;
  if(!check_sp(SPIRAL_MULTIHIT_COST)) return 1;

  
  room = environment(this_player());
  mob = present(MORPH_ID, this_player());
  if(!room || !mob) return 0;
  weapon = mob->query_weapon_list();
  ob = first_inventory(room);
    
/* Begin cycling attacks now... */
  write("You eye everything living in the room intently.\n");
  remote_say((this_player()->query_name()) + " sizes up everything living in the current room.\n");
  if(count_livings() < 6)
    write("You don't see enough visible targets to make the most of this attack.\n");
  while(ob) {
    object oc;
    oc = ob;
    ob = next_inventory(ob);
    if(living(oc)) {
      if(oc->is_pet() || oc->is_kid() || oc->is_player()) {
/* Spare kids, pets, and players */
        write("You decide to spare " + (oc->query_name()) + ".\n");
        remote_say((this_player()->query_name()) + " glares at " +
        (oc->query_name()) + " but suddenly turns away.\n"); 
      } else {
/* First hit goes to primary weapon */
        if(!i || i == 0) this_player()->attack_object(oc);
        else {
/* Strapped weapons or extra limbs */
          if(weapon[i]) {
            dam = weapon[i]->weapon_class();
            extra_hit(dam, i, oc, this_player());
          } else extra_hit(3, i, oc, this_player());
        oc->attack_object(this_player());
        i++;
        if(i > sizeof(weapon)) break;
        }
      }
    }
  }
  this_player()->add_spell_point(-SPIRAL_MULTIHIT_COST);
  return 1;
}

/* ---- COMBAT SPELL DRIVERS --- */

area_attack(limit,arg,swm,ssm,vwm,vsm,wwm,wsm,hwm,hsm,finwm,finsm,fwm,fsm) {
  object foo,gob;

  int dam_divisor,dam_charges;
  gob = present(GUILD_ID, this_player());
  if(!gob) return 0;
  if(!arg) dam_charges = limit / 2;
  else if(sscanf(arg, "%d", dam_charges) != 1) return 0;
  if(dam_charges < 2 || dam_charges > limit) {
    write("A voice echoes: That is out of range. Limits are 2 - " + limit + " sps.\n");
    return 1;
  }
  if(!check_sp(dam_charges)) return 1;
  this_player()->add_spell_point(-dam_charges);
  if(1 == random(this_player()->query_attrib("wil")) * 2) {
    write(fwm);
    remote_say((this_player()->query_name()) + " " + fsm);
    return 1;
  }
  dam_divisor = count_livings();

  if(dam_divisor > 2) dam_divisor = dam_divisor - 1;
  dam_charges = dam_charges / dam_divisor;
/* DAMAGE CAP! Yes! See! I put one in! Pachung! */

 if(dam_charges > 50) dam_charges = 50;
  foo=first_inventory(environment(this_player()));
  write(swm);
  remote_say((this_player()->query_name()) + " " + ssm);
  while(foo) {
    object foo2;
    foo2=foo;
    foo=next_inventory(foo);
    if(living(foo2) && foo2 != this_player()) {
      if(foo2->query_npc() && !foo2->is_kid() && !foo2->is_pet()) {
        int foo_hp,foo_damage;
        foo_hp=foo2->query_hp();
        foo_damage=random(dam_charges);
        if(foo_hp < foo_damage || foo_hp == foo_damage) foo_damage = foo_hp - 1;

        write("You see " + capitalize(foo2->query_name()) + " " + vwm);
        remote_say(capitalize(foo2->query_name()) + " " + vsm);
        foo2->attack_object(this_player());
        foo2->hit_player(foo_damage);
        if(gob->query_eval()) evaluate_hit(foo_damage);
      } else {
        if(1==random(3) && foo2->query_level() < 30) {
          write("You see " + capitalize(foo2->query_name()) + " " + wwm);
          remote_say(capitalize(foo2->query_name()) + " " + wsm);
          foo2->run_away();
        } else {
          write(capitalize(foo2->query_name()) + " " + hwm);

          remote_say(capitalize(foo2->query_name()) + " " + hsm);
        }

      }
    }
  }
  write(finwm);
  remote_say((this_player()->query_name()) + finsm);
  return 1;
}

single_attack(limit,arg,swm,swpm,ssm,sspm) {
  object gob,ob;
  gob = present(GUILD_ID, this_player());
  if(!gob) return 0;
  if(check_dead()) return 1;
  if(!check_sp(limit)) return 1;

  if(!arg) {
    ob = this_player()->query_attack();
    if(!ob) {
      write("Attack who?\n");
      return 1;
    }
  }
  if(arg && !ob) {
    ob = present(arg, environment(this_player()));
    if(!ob) {
      write("There is no such creature present.\n");
      return 1;
    }

  }
  if(!living(ob)) {
    write("You are left in a steep bogglement.\n");
    return 1;
  }
  if(ob->is_player()) {
    write("You cannot use guild powers against other players!\n");
    return 1;
  }
  if(!this_player()->valid_attack(ob)) return 1;
/* recalc, randomized and 'bonus' potential damage */
  this_player()->add_spell_point(-limit);
/* Chance of failure dependent on willpower */
  if(random(this_player()->query_attrib("wil") * 2) == 1) {
    write("You goofed and screw up.\n");
    return 1;

   }

  write(swm + (ob->query_name()) + swpm + "\n");
  remote_say(ssm  + (ob->query_name()) + sspm +"\n");
/* Whos is right? Standard formula is spcost = 2x + y when dam = x + random(y)
   Boltar and Saber think spcost = x when dam = random(2x) */
  limit = random(2 * limit);
/* For now my guild is at the higher setting to match others and compete with
   the living.c spell_object spells. */
/*
  limit = random(limit / 2);
 */
  ob->hit_player(limit);
  if(gob->query_eval()) evaluate_hit(limit);
  if(ob && !ob->query_attack()) ob->attack_object(this_player());
  return 1;
}

/* ---- COMBAT SPELL DRIVER GUTS --- */

count_livings() {
  object moo;
  int whees;
  moo=first_inventory(environment(this_player()));
  while(moo) {
    object squish;
    squish = moo;
    moo = next_inventory(moo);
    if(living(squish) && squish->query_npc() && !squish->is_kid()
    && !squish->is_pet()) whees = whees + 1;
  }
  return whees;
}

evaluate_hit(arg) {
  string tmp;
  tmp = "devastating";
  if(arg < 40) tmp = "bone crushing";
  if(arg < 30) tmp = "smashing";
  if(arg < 20) tmp = "very hard";
  if(arg < 10) tmp = "some hard";
  if(arg < 5) tmp = "some";
  if(arg < 3) tmp = "grazing";
  if(arg == 1) tmp = "tickling";
  if(arg == 0 || !arg) tmp = "no";
  write("**You feel you did " + tmp + " damage from that spell.\n");
  return 1;
}

static string msgs;

critical_hit_msg() {
  if(!msgs) {
    msgs=({"spins about dizzily.","is beaten to a blind stupor.",
    "appears ready to die.","is critically hit!",
    "collapses to the ground with a heavy *thunk*","begins mumbling incoherently.",
    "wheezes and sputters violently.","begins twitching and convulsing in a Spuck-like way.",
    "staggers and stumbles in pain.","begins foaming at the mouth."
    });
  }
  return msgs[random(sizeof(msgs))];
}

/* MULTIPLE HIT-WIELD DRIVERS */

/* ---- arg = damage, inum = attack type, atk = attacker object --- */
extra_hit(dpi,inum,atk,me,escsq) {
  object ob,person;
  string how,what,type,escape_seq;
  int dam,tmp;
  type = get_type(inum);
  tmp = dpi;
  if(tmp) {
  if(1 == random(3)) dam = random(2 * tmp);
    else dam = random(tmp);
    }
  if(me) person = me;
  else person = this_player();
  if(escsq) {
    escape_seq = escsq;
    tell_object(person, escape_seq);
  }

 if(random(person->query_attrib("ste")) < 6) {
    tell_object(person, "Your " + type + " attack missed.\n");
    person->remote_say((person->query_name()) + " misses " +
    (person->query_possessive()) + " " + type + " attack.\n");

    return;
  }
/*
  dam = random(person->query_level());
 */
   how = " to small fragments"; what = "massacre";
  if(dam < 30) { how = " with a bone crushing sound"; what = "smashed"; }
  if(dam < 20) { how = " very hard"; what = "hit"; }
  if(dam < 10) { how = " hard"; what = "hit"; }
  if(dam < 5) { how = ""; what = "hit"; }
  if(dam < 3) { how = ""; what = "grazed"; }
  if(dam == 1) { how = " in the stomach"; what = "tickled"; }
  ob = atk;
  if(!ob || ob->query_dead()) return 0;
  if(ob->is_player()) {
    tell_object(person, "Your " + type + " attack bounces harmlessly from " + (ob->query_name()) + ".\n");
    person->remote_say((person->query_name()) + "'s " + type + " attack grazes " + (ob->query_name()) + ".\n");
    return;
  }
  tell_object(person, "You " + what + " " + (ob->query_name()) +  how + " with your " + type + " attack.\n");

  person->remote_say((person->query_name()) + " " + what + " " + (ob->query_name()) + how +
  " with " + (person->query_possessive()) + " " + type + " attack.\n");
  if(ob->query_hp() < dam) {
    tell_room(environment(person), (ob->query_name()) + " " + critical_hit_msg() + "\n");
    dam = ob->query_hp() - 1;
  }
  if(escape_seq) tell_object(person, ESC + "[0m");
  ob->hit_player(dam);
}

strap_weapon(str) {
  int i,ok_flag;
  object mob, weapon, ob, oc;
  mob = present(MORPH_ID, this_player());
  if(!mob) return 0;
  weapon = mob->query_weapon_list();
  if(sizeof(weapon) < 2) return 0;
  if(!this_player()->query_weapon()) {
    write("You must wield a primary weapon first.\n");
    return 1;
  }
  if(!str) {
    write("Strap what?\n");
    return 1;
  }

/* Checks to find all strappable items in inventory */


/*
  if(str == "all") {
    if(this_player()->query_attack()) {
      write("You are too busy fighting!\n");
      return 1;
    }
    oc = first_inventory(this_player());
    while(oc) {
      if(oc->weapon_class() && this_player()->query_weapon() != oc) {
        while(i < sizeof(weapon)) {
          if(!weapon[i]) {
            weapon[i] = oc;
            write("You strap " + lower_case(oc->short()) + " as a " + get_type(i) + " weapon.\n");
            remote_say((this_player()->query_name()) + " wields " +
              lower_case(weapon[i]->short()) + " as a " + get_type(i) + " weapon.\n");
            move_object(weapon[i], mob);
          }
          i++;
        }
      }
      oc = next_inventory(oc);
    }
    mob->set_weapon_list(weapon);
    write("Ok.\n");
    return 1;
  }
 */


 /* Normal one-item strapping */

  ob = present(str, this_player());
  if(!ob) {
    write("You have no such item.\n");
    return 1;
  }
  if(!ob->weapon_class() || this_player()->query_weapon() == ob) {  
    write("You cannot strap that!\n");
    return 1;
  }
  while(i < sizeof(weapon)) {
    if(!weapon[i] && !ok_flag) {
      ok_flag = 1;
      weapon[i] = ob;
      write("You strap " + lower_case(ob->short()) + " as a " + get_type(i) + " weapon.\n");
      remote_say((this_player()->query_name()) + " wields " + 
        lower_case(weapon[i]->short()) + " as a " + get_type(i) + " weapon.\n");
      move_object(weapon[i], mob);
    }
    i++;
  }
  if(!ok_flag) write("You have no more free limbs.\n");
  else mob->set_weapon_list(weapon);
  return 1;
}

unstrap_weapon(str) {

  object mob,weapon,ob;
  int i,ok_flag;
  mob = present(MORPH_ID, this_player());
  if(!str || !mob) return 0;
  weapon = mob->query_weapon_list();
  if(!weapon) return 0;
/*
  if(str == "all") {
    unstrap_all(this_player());
    return 1;
  }
 */
  ob = present(str, mob);
  while(i < sizeof(weapon)) {
    if(weapon[i] && !ok_flag) {
      if(ob && ob == weapon[i]) {
        write("You unstrap " + lower_case(weapon[i]->short()) + " as a " + get_type(i) + " weapon.\n");

        remote_say((this_player()->query_name()) + " unwields " +
          lower_case(weapon[i]->short()) + " as a " + get_type(i) + " weapon.\n");
        move_object(weapon[i], this_player());
        weapon[i] = 0;
        ok_flag = 1;
      }
    }

    i++;
  }
  if(!ok_flag) write("You have no such weapon strapped.\n");
  else mob->set_weapon_list(weapon);

  return 1;
}

multiweapon_mob_short(arg, str) {
  object mob,weapon;
  string temp;
  int period_flag,a;
  mob = arg;
  if(!arg) return 0;
  weapon = mob->query_weapon_list();
  temp = "";
  while(a < sizeof(weapon)) {
    if(weapon[a]) {
      temp = temp + (weapon[a]->short()) + " (wielded " + get_type(a) + ").\n";

      period_flag = 1;
    }

    a++;
  }
  temp = temp + str;
  return temp;
}

unstrap_all(arg) {
  object person,mob,ob;
  int i;
  person = arg;
  if(!person) return 0;
  mob = present(MORPH_ID, person);
  if(!mob) return 0;

  ob = all_inventory(mob);
  for(i = 0; i < sizeof(ob); i ++) {
    if(ob[i]) {
      tell_object(person, "You unstrap " + lower_case(ob[i]->short()) + ".\n");
      person->remote_say((person->query_name()) + " stops wielding " + (ob[i]->query_name()) + " as a " +
      get_type(i) + " weapon.\n");
      move_object(ob[i], person);
      ob[i] = 0;
    }
  }
  mob->set_weapon_list(0);
}

get_type(arg) {
  string type;
  int num;
  num = arg;
  if(num == 0) type = "secondary";
  if(num == 1) type = "tertiary";
  if(num == 2) type = "quaternary";
  if(num == 3) type = "pentiary";
  if(num == 4) type = "hexiary";
  if(num == 5) type = "septiary";

  if(num == 6) type = "octiary";
  return type;
}


/* ----emote and say subroutines --- */

mod_say(str) {

  object gob;
  string vrb,tmpn,tmpo,tmpp;
  gob = present(GUILD_ID, this_player());
  if(!str || !gob) return 0;
  if(sscanf(str, "%s!", tmpo) == 1) vrb = "exclaim";
  else if(sscanf(str, "%s!!", tmpo) == 1) vrb = "scream";
  else if(sscanf(str, "%s!!!%s", tmpo, tmpp) == 2) vrb = "holler";
  else if(sscanf(str, "%s?", tmpo) == 1) vrb = "ask";
  else if(sscanf(str, "%s?%s", tmpo, tmpp) == 2) vrb = "postulate";
  else vrb = "say";
 if(gob->query_current_morph() == "none" || gob->query_current_morph() == "replicant")
  tmpn = (this_player()->query_name()) + " " + vrb + "s: " + str + "\n";
  else
  tmpn = (this_player()->query_name()) + " the " +
  (gob->query_current_morph()) + " " + vrb + "s: " + str + "\n";
  tmpn = format(tmpn, 70);
  this_player()->remote_say(tmpn);

  if(this_player()->query_brief()) write("Ok.\n");
  else write("You " + vrb + ": " + str + "\n");
  return 1;
}

mod_emote(str) {
  object gob;
  string tmpp;
  gob = present(GUILD_ID, this_player());
  if(!str || !gob) return 0;
  if(gob->query_current_morph() == "none" || gob->query_current_morph() == "replicant")
    tmpp = (this_player()->query_name()) + " " + str + "\n";
  else
    tmpp = (this_player()->query_name()) + " the " +

    (gob->query_current_morph()) + " " + str + "\n";
  remote_say(format(tmpp, 70));
  if(this_player()->query_brief()) write("Ok.\n");
  else write(tmpp);

  return 1;
}

/* ---- [NEWS READER STUFF] 8< cut here--- */

#define NEWSFILE "players/mizan/closed/poly/NEWSFILE"

string news_group;
string messages;
int num_messages;

loadnews() {
  if(!restore_object(NEWSFILE)) {
    news_group = allocate(5);
    news_group[0] = "guild.announce";
    news_group[1] = "guild.general";

    news_group[2] = "guild.bugs&ideas";
    news_group[3] = "anything.else";
/* Last group reserved for hilev guild + */
    news_group[4] = "guild.command";
    num_messages = allocate(5);
    messages = allocate(5);
    messages = ({"","","",""});
    save_object(NEWSFILE);
  }

}

news_grouplist() {
  int i;
  write("You study your lump of clay and some words appear on it:\n"+
  "\n>> Current available groups:\n\n");
  while(i < sizeof(news_group)) {
    if(i == (sizeof(news_group) - 1) && this_player()->query_guild_rank() < GC) break;
    write(" (" + (i + 1) + ")\t[" + news_group[i] + "] (" + num_messages[i] + ") messages.\n");
    i++;
  }
  return 1;
}


news_headers() {
  string hd, body, rest;
  int i,indx,tmp;
  i = 1;
  indx = index_number();
  if(!num_messages[indx]) {
    write("\n>> [" + news_group[indx] + "] is empty.\n");
    return 1;
  }
  rest = messages[indx];
  write("\n>> Postings in group [" + news_group[indx] + "]:\n");

  while(rest != 0 && rest != "") {
    tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);

    if(tmp != 2 && tmp != 3) {
      write("\n>> File corrupted.\n");
      return;
    }
    write(i + ":\t" + hd + "\n");
    i += 1;
  }
  return 1;

}
news_read(str) {
  string hd, body, rest;
  int i,indx,tmp;
  if(str == 0 || sscanf(str, "%d", i) != 1) return 0;
  indx = index_number();
  if(i > num_messages[indx]) {
    write("\n>> There are only (" + num_messages[indx] +") messages.\n");

    return 1;
  }

  rest = messages[indx];
  while(rest != 0 && rest != "") {
    i -= 1;
    tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
    if (tmp != 2 && tmp != 3) {
      write("Corrupt.\n");
      return;
    }
    if (i == 0) {
      write("\n>> The message is titled '" + hd + "':\n\n");
      write(body);
      write(">> End of message (" + i + ").\n");
      return 1;
    }
  }
  write("\n>> Hm. This should not happen.\n");

}

news_delete(str,arg) {
  string hd, body, rest;
  int i,indx,tmp;
  if(str == 0 || sscanf(str, "%d", i) != 1) return 0;
  indx = index_number();
  if(i > num_messages[indx]) {
    write(">> There are only [" + num_messages[indx] +"] postings.\n");

    return 1;
  }
  rest = messages[indx];
  messages[indx] = "";

  while(rest != 0 && rest != "") {
  i -= 1;
  tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
    if (tmp != 2 && tmp != 3) {
      write("\n>> File corrupted.\n");
      return;
    }
    if (i == 0) {
      if(!arg) write("\n>> Done.\n");
      messages[indx] = messages[indx] + rest;
      num_messages[indx] -= 1;
      save_object(NEWSFILE);
      return 1;
    }
    messages[indx] = messages[indx] + hd + ":\n**\n" + body + "\n**\n";
  }
  write("\n>> Hm. This should not happen.\n");
}


index_number() {
  object gob;
  int i;
  gob = present(GUILD_ID, this_player());
  if(!gob) return 0;
  i = gob->query_news_index();
  if(i >= sizeof(news_group)) {
    i = 0;
    gob->set_news_index(i);

  }
  return i;

}
news_next_group() {

  object gob;
  int i,max;
  gob = present(GUILD_ID, this_player());
  if(!gob) return 0;
  i = index_number();
  i++;
  if(i == (sizeof(news_group) - 1) && this_player()->query_guild_rank() < GC) i = 0;
  if(i >= sizeof(news_group)) i = 0;
  gob->set_news_index(i);
  write("\n>> Switching to group [" + news_group[i] + "], (" +

  num_messages[i] + ") messages.\n");
  return 1;
}

news_post_check(hd) {

  int indx;
  indx = index_number();
  if(!hd) {
    write(">> You must give a header.\n");
    return 0;
  }
  if(num_messages[indx] == 25) {

    news_delete("1","silent");
    return 1;
  }
  if(strlen(hd) > 55) {
    write("\n>> The header is too long.\n");
    return 0;
  }
  write("\n>> Posting to [" + news_group[indx] + "]:\n");
  write(">> Give message, ** to finish, ~q to abort.\n");
  return 1;
}

news_feed(arg,str) {

  object gob;
  string new_hd;
  int indx;
  indx = index_number();
  gob = present(GUILD_ID, this_player());
  new_hd = "[" + capitalize(this_player()->query_real_name()) +

  ", " + extract(ctime(time()), 4, 9)+ "]  " + arg;
  if(gob && gob->query_sig())
    messages[indx] = messages[indx] + new_hd + ":\n**\n" + str + "\n" +
    (gob->query_sig()) + "\n\n**\n";
  else
  messages[indx] = messages[indx] + new_hd + ":\n**\n" + str + "\n**\n";
  num_messages[indx] += 1;
  save_object(NEWSFILE);
  write("\n>> Message posted.\n");
  if(gob && gob->query_news_announce())
    if(indx != (sizeof(news_group) -1))

      guild_tell(":has completed a news message in [" + news_group[indx] + "].");
    else write("Announce message muffled due to newsgroup type.\n");
  return 1;
}

news_goto_group(arg) {
  object gob;
  int i;
  gob = present(GUILD_ID, this_player());
  if(!arg) return 0;
  if(!gob) return 0;
  if(sscanf(arg, "%d", i) != 1) return 0;
  i--;
  if(i < 0 || i > sizeof(news_group)) {
    write(">> Invalid newsgroup number.\n");
    return 1;
  }
  if(this_player()->query_guild_rank() < GC &&
    i == (sizeof(news_group) - 1)) {
    write(">> Invalid newsgroup number.\n");
    return 1;
  }
  write(">> Going to news group [" + news_group[i] + "], (" + num_messages[i] + ") messages.\n");
  gob->set_news_index(i);
  return 1;
}

news_add_group(str) {
  string msgtmp,grptmp;
  int numtmp;
  int i;
  if(!check_level(5)) return 1;
  if(strlen(str) > 30) {
    write(">> That header name is too long. 30 characters or less.\n");
    return 1;
  }
  msgtmp = messages;
  numtmp = num_messages;
  grptmp = news_group;
  messages = allocate(sizeof(msgtmp + 1));
  num_messages = allocate(sizeof(numtmp + 1));
  news_group = allocate(sizeof(grptmp + 1));
  while(i < sizeof(messages)) {
    if(i == (sizeof(messages) - 2)) {
      messages[i] = "";
      news_group[i] = str;
      messages[i+1] = msgtmp[i];
      news_group[i+1] = grptmp[i];
     num_messages[i+1] = numtmp[i];
      break;
    }
    else
    {
      messages[i] = msgtmp[i];
      news_group[i] = grptmp[i];
      num_messages[i] = numtmp[i];
    }
    i++;
  }
  write(">> New newsgroup formed.\n");
  guild_tell(": has created a new newsgroup [" + str + "]!\n");
  save_object(NEWSFILE);
  return 1;
}

news_delete_group(str) {
  string msgtmp, grptmp;
  string tmp;
  int numtmp, sel, i;
  if(!check_level(5)) return 1;
  if(sscanf(str, "%d", sel) != 1) return 0;
  if(sel == sizeof(news_group)) return 0;
  if(sel < 4) {
    write(">> You cannot delete that newsgroup.\n");
    return 1;
  }
  if(num_messages[sel]) {
    write(">> That newsgroup is not empty!\n");
    return 1;
  }
  msgtmp = messages;
  grptmp = news_group;
  numtmp = num_messages;
  tmp = news_group[(sel - 1)];
  messages = allocate(sizeof(msgtmp - 1));
  news_group = allocate(sizeof(grptmp - 1));
  num_messages = allocate(sizeof(numtmp - 1));
  while(i < sizeof(messages)) {
  if(i == sizeof(messages)) {
      messages[i] = msgtmp[i + 1];
      news_group[i] = grptmp[i + 1];
      num_messages[i] = numtmp[i + 1];
      break;
    }
    else
    {
      messages[i] = msgtmp[i];
      news_group[i] = grptmp[i];
      num_messages[i] = numtmp[i];
    }
    i++;
  }
  write(">> Deletion successful.\n");
  guild_tell(": has deleted newsgroup [" + tmp + "]!\n");
  save_object(NEWSFILE);
  return 1;
}
