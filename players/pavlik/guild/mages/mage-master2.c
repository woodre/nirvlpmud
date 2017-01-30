#include "/players/pavlik/guild/mages/macs2"

/* -= Non-Spells =- */
#include "/players/pavlik/guild/mages/spells2/mage_score"
#include "/players/pavlik/guild/mages/spells2/spell_fail"
#include "/players/pavlik/guild/mages/spells2/SPELL_LIST"
#include "/players/pavlik/guild/mages/spells2/mage_staff"
#include "/players/pavlik/guild/mages/spells2/guild_channel"
#include "/players/pavlik/guild/mages/spells2/mage_tell"
#include "/players/pavlik/guild/mages/spells2/mage_help"
#include "/players/pavlik/guild/mages/spells2/commander"
#include "/players/pavlik/guild/mages/spells2/guild_title"
#include "/players/pavlik/guild/mages/spells2/take_lead"
#include "/players/pavlik/guild/mages/spells2/mage_equip"

#include "/players/pavlik/guild/mages/spells2/devote"
#include "/players/pavlik/guild/mages/spells2/affluence"
#include "/players/pavlik/guild/mages/spells2/study_monster"
/* wizhat in this object */
#include "/players/pavlik/guild/mages/spells2/teach_mage"
#include "/players/pavlik/guild/mages/spells2/guild_rescue"
/* mtitle in this object */
/* gdiv in this object */
#include "/players/pavlik/guild/mages/spells2/reposit"
#include "/players/pavlik/guild/mages/spells2/meditate"
#include "/players/pavlik/guild/mages/spells2/sponsor"


/* -= Level 1 Spells =- */
#include "/players/pavlik/guild/mages/spells2/faerie_fire"
#include "/players/pavlik/guild/mages/spells2/werelite"
#include "/players/pavlik/guild/mages/spells2/chromatic_orb"
/* know alignment in this object */
#include "/players/pavlik/guild/mages/spells2/magic_missile"
#include "/players/pavlik/guild/mages/spells2/wizard_mark"
/* emote spell in this object */
#include "/players/pavlik/guild/mages/spells2/chill_touch"
#include "/players/pavlik/guild/mages/spells2/sacrifice"

/* -= Level 2 Spells =- */
#include "/players/pavlik/guild/mages/spells2/unseen_servant"
#include "/players/pavlik/guild/mages/spells2/wizard_eye"
#include "/players/pavlik/guild/mages/spells2/flame_sphere"
#include "/players/pavlik/guild/mages/spells2/make_bag"
#include "/players/pavlik/guild/mages/spells2/color_spray"
#include "/players/pavlik/guild/mages/spells2/energy_shield"
#include "/players/pavlik/guild/mages/spells2/blind"
#include "/players/pavlik/guild/mages/spells2/cure_wounds"

/* -= Level 3 Spells =- */
#include "/players/pavlik/guild/mages/spells2/acid_arrow"
#include "/players/pavlik/guild/mages/spells2/khirstel"
#include "/players/pavlik/guild/mages/spells2/alarm"
#include "/players/pavlik/guild/mages/spells2/empower"
#include "/players/pavlik/guild/mages/spells2/confuse"
#include "/players/pavlik/guild/mages/spells2/soul_crush"
#include "/players/pavlik/guild/mages/spells2/query_monster"

/* -= Level 4 Spells =- */
#include "/players/pavlik/guild/mages/spells2/sigil"
#include "/players/pavlik/guild/mages/spells2/dragon"
#include "/players/pavlik/guild/mages/spells2/create_food"
#include "/players/pavlik/guild/mages/spells2/detoxification"
#include "/players/pavlik/guild/mages/spells2/reveal"
#include "/players/pavlik/guild/mages/spells2/shadow_dagger"
#include "/players/pavlik/guild/mages/spells2/life_steal"

/* -= Level 5 Spells =- */
#include "/players/pavlik/guild/mages/spells2/fireball"
#include "/players/pavlik/guild/mages/spells2/strangulation"
#include "/players/pavlik/guild/mages/spells2/bind"
#include "/players/pavlik/guild/mages/spells2/absorbtion"
#include "/players/pavlik/guild/mages/spells2/pacify"
#include "/players/pavlik/guild/mages/spells2/animate_dead"

/* -= Level 6 Spells =- */
#include "/players/pavlik/guild/mages/spells2/stone_skin"
#include "/players/pavlik/guild/mages/spells2/blister"
#include "/players/pavlik/guild/mages/spells2/resurrect"

/* -= Level 7 Spells =- */
#include "/players/pavlik/guild/mages/spells2/teleport"
#include "/players/pavlik/guild/mages/spells2/enchant_weapon"
#include "/players/pavlik/guild/mages/spells2/vorpal_heal"
#include "/players/pavlik/guild/mages/spells2/vorpal_heal2"
#include "/players/pavlik/guild/mages/spells2/mirror_image"
#include "/players/pavlik/guild/mages/spells2/curse"

#define MIN_SP -30

int spell_level;
string school;
string name;
int num;

reset(arg) {
  move_object(this_object(), "players/pavlik/guild/mages/rooms/master_room");
  call_out("mage_autosave", 50);
}

id(str){
  return str == "mage-master" || str == "mage_master";
}

drop(){ return 1; }
get(){ return 1; }
short(){ return "The Mage-Master"; }
long(){
  write("The Mage-Master.\n");
  return;
}


/* pavlik */
pavlik(str) {

  string what;
  what = query_verb();

/* basic commands */
if(what == "msc"){ mage_score(); return 1; }
if(what == "mhelp"){ mage_help(str); return 1; }
if(what == "mhelp2"){ mage_help(str); return 1; }
if(what == "spells"){ spell_list2(str); return 1; }
if(what == "commands"){ mage_commands(str); return 1; }
if(what == "gt"){ guild_tell(str); return 1; }
if(what == "mage"){ guild_tell(str); return 1; }
if(what == "ge"){ guild_emote(str); return 1; }
if(what == "gc"){ muffles(str); return 1; }
if(what == "gw"){ guild_who(); return 1; }
if(what == "mw"){ mud_who(); return 1; }
/* renew in mage object */
if(what == "fixme"){ beat_fix(); return 1; }
/* calcxp in mage object */
if(what == "gtitle"){ guild_title(); return 1; }
if(what == "mequip"){ mage_equip(); return 1; }
if(what == "dlead"){ DONATOR->donations(); return 1; }
if(what == "tow"){ if(check_sp(tp)) go_tower(); return 1; }
if(what == "front"){ take_lead(); return 1; }
if(what == "lcmds"){ set_my_login_commands(str); return 1; }
if(what == "lcmds?"){ query_my_login_commands(); return 1; }
if(what == "convert"){ convert_xp(str); return 1; }
if(what == "tell"){ t_tell(str); return 1; }

/* other commands */
if(what == "haste"){ haste(str); return 1; }
if(what == "devote"){ devote(str); return 1; }
if(what == "affluence"){ affluence(str); return 1; }
if(what == "study"){ study_monster(str); return 1; }
if(what == "wizhat"){ wizard_hat(); return 1; }
if(what == "teach"){ teach_mage(str); return 1; }
if(what == "rescue"){ guild_rescue(); return 1; }
if(what == "mtitle"){ my_title(str); return 1; }
if(what == "gdiv"){ set_guild_div(str); return 1; }
if(what == "reposit"){ reposit(str); return 1; }
if(what == "redraw"){ redraw(str); return 1; }
if(what == "relist"){ relist(str); return 1; }
if(what == "meditate"){ meditate(); return 1; }
if(what == "magestaff"){ create_mage_staff(); return 1; }
if(what == "sponsor"){ sponsor(str); return 1; }

/*
 * Check_Sp required on all spells that use Spell Points
 * Also checks to make sure the no_casting flag is clear
 */
if(!check_sp(tp)) return 1;

/* Level 1 Spells */
if(what == "ffire") { faerie_fire(str); return 1; }
if(what == "werelite"){ werelite(); return 1; }
if(what == "orb") { chromatic_orb(str); return 1; }
if(what == "knowal"){ know_alignment(str); return 1; }
if(what == "mssle"){ magic_missile(str); return 1; }
if(what == "mark"){ wizard_mark(str); return 1; }
if(what == "emote" || what == ">"){ emote(str); return 1; }
if(what == "ctouch"){ chill_touch(str); return 1; }
if(what == "sac"){ sacrifice(); return 1; }

/* Level 2 Spells */
if(what == "userv"){ unseen_servant(str); return 1; }
if(what == "wizeye"){ wizard_eye(str); return 1; }
if(what == "flame"){ flame_sphere(str); return 1; }
if(what == "mbag"){ make_bag(); return 1; }
if(what == "spray"){ color_spray(); return 1; }
if(what == "eshield"){ energy_shield(str); return 1; }
if(what == "blind"){ blind(str); return 1; }
if(what == "cure"){ cure_wounds(str); return 1; }

/* Level 3 Spells */
if(what == "acid"){ acid_arrow(str); return 1; }
if(what == "khirstel"){ khirstel(); return 1; }
if(what == "kwhistle"){ kwhistle(); return 1; }
if(what == "alarm"){ alarm(str); return 1; }
if(what == "empower"){ empower(str); return 1; }
if(what == "confuse"){ confuse(str); return 1; }
if(what == "crush"){ soul_crush(str); return 1; }
if(what == "query"){ mage_query(str); return 1; }

/* Level 4 Spells */
if(what == "sigil"){ sigil(str); return 1; }
/* dragon commands in object */
if(what == "dragon"){ dragon_command(str); return 1; }
if(what == "food"){ create_food(str); return 1; }
if(what == "detox"){ detoxification(str); return 1; }
if(what == "reveal"){ reveal(); return 1; }
if(what == "sdagger"){ shadow_dagger(str); return 1; }
if(what == "steal"){ life_steal(str); return 1; }

/* Level 5 Spells */
if(what == "fball"){ fireball(); return 1; }
if(what == "strangle"){ strangulation(str); return 1; }
if(what == "bind"){ bind(str); return 1; }
if(what == "absorb"){ absorbtion(str); return 1; }
if(what == "pacify"){ pacify(str); return 1; }
if(what == "andead"){ animate_dead(); return 1; }

/* Level 6 Spells */
if(what == "stoneskin"){ stone_skin(str); return 1; }
if(what == "blister"){ blister(str); return 1; }
if(what == "resurrect"){ resurrect(str); return 1; }

/* Level 7 Spells */
if(what == "tlp"){ mage_teleport(str); return 1; }
if(what == "enchant"){ enchant_weapon(str); return 1; }
if(what == "vheal"){ vorpal_heal(str); return 1; }
if(what == "vheal2"){ vorpal_heal2(str); return 1; }
if(what == "mimage"){ mirror_image(str); return 1; }
if(what == "curse"){ curse(str); return 1; }

/* Guild Commanders */
if(what == "ct"){ council_tell(str); return 1; }
if(what == "ce"){ council_emote(str); return 1; }
if(what == "mfix"){ gc_fix(str); return 1; }
if(what == "mstat"){ gc_stat(str); return 1; }
if(what == "mspells"){ gc_spell_list(str); return 1; }
if(what == "mcheck"){ gc_check(str); return 1; }
if(what == "mrank"){ gc_promote(str); return 1; }
if(what == "mreset"){ gc_reset(str); return 1; }
if(what == "mxp"){ gc_exp(str); return 1; }
if(what == "mdonation"){ gc_donation(str); return 1; }
if(what == "mschool"){ gc_school(str); return 1; }
if(what == "mexpell"){ gc_expell(str); return 1; }
if(what == "mteach"){ gc_teach(str); return 1; }
if(what == "mforget"){ gc_forget_spell(str); return 1; }
if(what == "mbonus"){ gc_stat_bonus(str); return 1; }
if(what == "mnewspells"){ gc_new_spells(str); return 1; }
if(what == "msessions"){ gc_training_sessions(str); return 1; }

  return 0;
}

/* AUTOSAVE */
mage_autosave(){
 object ob, obj;
 int i;
 ob = users();
 for(i=0; i<sizeof(ob); i++){
   if(ob[i])
   if(environment(ob[i])) {   /* added in this check to ensure
                                 present check can be made  - mythos <1-29-98> */
  obj = present("mageobj2", ob[i]);
  if(obj){
   obj->calculate_exp();
   if(!in_editor(ob[i])) tell_object(ob[i], "Autosaving Mage Soul ...ok.\n");
   obj->mage_autosave();
  } }
 }
 call_out("mage_autosave", 600);
 return 1;
}

/* SET LOGIN CMDS */
set_my_login_commands(str){
  if(!str || str == "none"){
    write("You clear all login commands.\n");
    guild->set_login_cmds(0);
    return 1;
    }
  write("You set your login cmds to: "+HIM+str+NORM+"\n");
  write("These commands will be executed automaticaly when you next logon.\n");
  guild->set_login_cmds(str);
  return 1;
}

query_my_login_commands(){
  string cmds;
  if(!guild->query_login_cmds()){
    write("You have not set any login commands.\n");
    return 1;
    }
  write("Your login commands are: "+HIM+guild->query_login_cmds()+NORM+"\n");
  return 1;
}

/* LOGIN CMDS */
do_login_cmds(str){
  string path, rest;
  int cont;
  rest = str;
  for(cont=0; cont<5; cont++){
    if(sscanf(rest, "%s,%s", path, rest)==2){
      command(path, this_player());
    } else {
      command(rest, this_player());
      write(CYN+"Login command complete.\n"+NORM);
      return 1;
      }
  }
  return 1;
}

/* KNOWIT */
knowit(str){
 string rest, tmp, rest_tmp;
  int i, knowit;

  if(tp->query_guild_rank() > 71)  return 1;
 
  knowit = 0;
  rest = guild->query_spells();
  while(rest){
    i = sscanf(rest, "%s#%s", tmp, rest_tmp);
        if(i < 2){
          tmp = rest;
          rest_tmp = 0;
        }
    if(tmp == str){
      knowit = 1;
    }
    rest = rest_tmp;
  }
return knowit;
}

/* This is used to check another players spell list */
knowit_other(player, str){
  string rest, tmp, rest_tmp;
  int i, knowit;

  if(player->query_guild_rank() > 71) return 1;

  knowit = 0;
  rest = present("mageobj", player)->query_spells();
  while(rest){
    i = sscanf(rest, "%s#%s", tmp, rest_tmp);
        if(i < 2){
          tmp = rest;
          rest_tmp = 0;
        }
    if(tmp == str) knowit = 1;
    rest = rest_tmp;
  }
  return knowit;
}

/* VALID SPELL - various legalities of spell casting */
valid_spell(str) {
  object ob;

  if(guild->query_casting()) {
    write("You are already casting a spell.\n");
    return 0;
  }

  if(tp->is_ghost()) {
    write("You cannot cast spells while your dead!\n");
    return 1;
  }

  if(tp->query_sp() < -101) {
    write("You are too tired to cast another spell.\n");
    return 0;
  }

  if(!tp->query_attack()) {
    write("You must be fighting before you may cast this spell.\n");
    return 0;
  }

  if(!str)
    ob = tp->query_attack();
  else
    ob = present(str, env);

  if(!ob)
    return 0;

  if(environment(ob)->query_arena() || ob->query_pl_k() > 1)
    return ob;

  if(!ob->query_npc()) return 0;

  /* if we made it this far everything is AOK! */
  return ob;
}

/* BEAT_FIX */
beat_fix(){
  write("Attempting to fix annoying HB errors ... done.\n");
  tp->set_heart_beat(1);
  call_other(tp, "reset", 1);
  this_player()->recalc_quest();
  this_player()->recalc_carry();
  return 1;
}

/* GO TOWER */
go_tower(){
  if(creator(env) == 0){
    tp->add_spell_point(-15);
      write(HIC+"You teleport back to the Mage's tower.\n"+NORM);
    say(ME+" whispers a magical command and disappears.\n");
    move_object(tp, "players/pavlik/guild/mages/rooms/guild_room5");
    command("look", tp);
    say(ME+" teleports in.\n");
    return 1;
    }
  write("You cannot do that from here.\n");
  return 1;
}

/* EMOTE */
emote(str){
  if(!KNOW("emote")){
  return (int)"/bin/play/_emote"->cmd_emote(str);
  }

  write(HIC+"You Emote:\n"+NORM);
  tell_room(env, rancol2(ME+" "+str)+NORM+"\n");
  return 1;
}

/* MY TITLE */
my_title(str){
  if(tp->query_guild_rank() < 15){
    write("What?\n");
    return 1;
  }
 
  if(!str){
    write("Set your title to what?\n");
    return 1;
  }

  if(str=="the dork"||str=="the Dork"||str=="The Dork"){
    write("Pavlik says: wannabe.  Make-up your own title!\n");
    return 1;
  }

  tp->set_title(str);
  write("You change your title.\n");
  write("You are now:\n"+tp->short()+"\n");
  return 1;
}

/* WIZ HAT */
wizard_hat(){
  object obj;

  if(tp->query_guild_rank() < 6){
    write("What?\n");
    return 1;
  }

  if(present("wiz_hat", tp)){
    write("You already have a hat!\n");
    return 1;
  }

  obj = clone_object("players/pavlik/guild/mages/obj/wiz_hat");
  move_object(obj, tp);
  write
  ("You pull an old beat up hat from your robes.\n"+
  "You dust off the shapeless cloth and place it on your head.\n"+
  "You smile.\n");
  say(
  ME+" pulls an old beat up hat from "+PO+" robes.\n"+
  ME+" places the shapeless mass on "+PO+" head.\n"+
  ME+" smiles.\n");
  return 1;
}

/* SET DIVD - GDIV */
set_guild_div(str){
  int mydiv;

  if(tp->query_guild_rank() < 18){
    write("What?\n");
    return 1;
  }

  if(!str){
    write("Set Guild Dividend to what?\n");
    return 1;
  }

  sscanf(str, "%d", mydiv);

  if((mydiv < 1) || (mydiv > 100)){
   write("You must set Guild Div to a percent [5-100].\n");
   return 1;
  }

  if(mydiv < 5){
    write("Minimum Guild Div is 5%.\n");
    mydiv = 5;
  }

  guild->set_divd(mydiv);
  write("Setting Guild Div to "+mydiv+" percent.\n");
  write(mydiv+"% of all earned XP will go to the guild.\n");
  return 1;
}

/* KNOW ALIGNMENT */
know_alignment(str){
  object obj;
  string aura, aln;
  int al;

  if(!KNOW("knowal") && !KNOW("know_alignment")) {
    write("What?\n");
    return 1;
  }

  if(!str) obj = tp->query_attack();
  else obj = present(str, env);

  if(!obj){
    write("That is not here.\n");
    return 1;
    }

  write("You cast a "+CYN+"Know Alignment"+NORM+" spell...\n");

  if(spell_fail2(1, "ench", "wis")) {
    write("You are unable to detect "+IT+"'s alignment.\n");
    tp->add_spell_point(-5);
    return 1;
  }

  if(!living(obj)){
    write(capitalize(obj->query_name())+" is neutral ... "+
    " very neutral.\n");
    tp->add_spell_point(-5);
    return 1;
  }

  al = obj->query_alignment();
  if(al > 800){
    aura = HIW+"brilliant white"+NORM;  aln = HIW+"a Saint"+NORM; }
  else if(al > 400){
    aura = HIC+"sky blue"+NORM;  aln = HIC+"Very Good"+NORM; }
  else if(al > 200){
    aura = HIB+"blue"+NORM;  aln = HIB+"Good"+NORM; }
  else if(al > 50){
    aura = CYN+"faint blue"+NORM;  aln = CYN+"with good intentions"+NORM; }
  else if(al < 50 && al > -50){
    aura = "somber grey";  aln = "neutral";  }
  else if(al < -50){
    aura = MAG+"faint red"+NORM;  aln = MAG+"with evil intentions"+NORM; }
  else if(al < -200){
    aura = RED+"red"+NORM;  aln = RED+"Evil"+NORM; }
  else if(al < -400){
    aura = HIR+"blood red"+NORM;  aln = HIR+"Very Evil"+NORM; }
  else if(al < -800){
    aura = "jet black";  aln = "the Embodiment of Evil";  }
  else {
    aura = "somber grey";  aln = "neutral";  }

  tell_room(env,
  ME+" says: Dustak pophures.\n"+
  "A "+aura+" aura appears around "+IT+".\n");
  write("Your spell reveals a "+aura+" aura.\n");
  write(IT+" is "+aln+".\n");
  tp->add_spell_point(-15);
  return 1;
}

/*
 * Make sure player has minimum amount of SPs to cast spell
 */
check_sp(whoob) {
  if(whoob->query_ghost()) {
     tell_object(whoob, "You find that you cannot cast a spell as a ghost.\n");
     return 0;
  }
  if(present("mageobj", whoob)->query_casting() ||
     present("mageobj", whoob)->query_meditate()) {
    write("You cannot cast spells right now.\n");
    return 0;
  }
  if(whoob->query_sp() < MIN_SP) {
     tell_object(whoob, "You are too weak to cast this spell.\n");
     return 0;
  }
  return 1;
}

/*
 * TELL DAMAGE
 * Emote message to player giving rough estimate of how much damage was done.
 */
tell_damage(amt,obj) {
  string what;
  if(amt > 60) what = HIR+"ANNIHILATES"+NORM;
  else if(amt > 50) what = HIR+"devastates"+NORM;
  else if(amt > 40) what = RED+"crushes"+NORM;
  else if(amt > 30) what = "pulverizes";
  else if(amt > 20) what = "smashes";
  else if(amt > 10) what = "hits";
  else if(amt > 4)  what = "nicks";
  else what = "annoys";

  write("Your spell "+what+" "+IT);
  say(ME+"'s spell "+what+" "+IT);

  if(amt > 20) {
    write("!");
    say("!\n");
  }
  else {
    write(".");
    say(".\n");
  }

  if(tp->query_level() > 20) {
     write(" ["+amt+"]\n");
  }
  else {
     write("\n");
  }

  return;
}

/*
 * Calculate % Pts of Guild Stat Increase
 */
stat_increase_amount(str) {
  int stat, amount;

  if(str == "wis") stat = guild->query_wisdom();
  if(str == "wil") stat = guild->query_will_power();

  amount = 0;

  /* if stat is really low then start amount at 3 */
  if(stat < 18) amount += 3;

  amount += 1 + random(stat)/6 + random(3);
  if(amount < 1) amount = 1;
  if(amount > 7) amount = 7 + random(3);
  
  return amount;
}

/*
 * MAX DONATION
 * If a Mage goes over 50,000 donation points the point total is reduced
 * and the player is rewarded with a sum of coins.
 */
max_donation() {
  object m;
  int i;
  i = 3000 + random(4000);
  if(!tp) return;
  write("You recieve "+i+" "+HIM+"guild exp"+NORM+" for your devotion to the guild.\n");
  write("Resetting Donation Points ... ok.\n");
  guild->add_donation(-(guild->query_donation()/2));
  tp->add_guild_exp(i);
  return 1;
}

/*
 * SPELL COMPONENTS
 */

get_component_name(str) {
  if(str == "test") return "Test Spell Component";
  else if(str == "amber_rod") return "Amber Rod";
  else if(str == "onyx_powder") return "Black Onyx Powder";
  else return "Unknown";
}

get_component_weight(str) {
  if(str == "test") return 1;
  else if(str == "amber_rod") return 2;
  else if(str == "onyx_powder") return 1;
  else return 0;
}


/* EOF */
