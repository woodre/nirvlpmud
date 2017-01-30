/* Orginal code from Bern's Clerics, 
   Modified to become The Knight's Templar by Boltar.
*/

#include "security.h"
#include "/players/boltar/things/esc.h"
#include "/players/dragnar/closed/ansi.h"
#define USER environment()
#define ATT USER->query_attack()
#define AT USER->query_attack()
#define AAT USER->query_alt_attack()
#define level USER->query_level()
#define extralevel USER->query_extra_level()
#define AT USER->query_attack()
#define AAT USER->query_alt_attack()
#define TP this_player()
#define CHUNK 20
#define num_skill 22
#define CRIM "/players/boltar/templar/daemon/Criminal.c"
#define ALLY "players/boltar/templar/daemon/Ally.c"
#define LOG "/players/boltar/templar/log/Ally"
#define USOB environment(this_object())
#include "/players/boltar/templar/lib/_bow.h"
#include "/players/boltar/templar/lib/_salute.h"
#include "/players/boltar/templar/lib/_warn.h"

/* Awards that a Knight can obtain:
  1 The Crystal Shield   - Died for someone else in pk. (6)
  2 The Platinum Circlet - Pked a criminal.             (4)
  3 The Silver Circlet   - Assisted a Pk on a criminal. (2)
  4 The Emerald Droplet  - Misc. Assistance/other.      (1)
*/ 

string *sayings;
string *has_read;
int KPTS;
int award1;
int award2;
int award3;
int award4;
int total_awards;
int elite;
int sword,knife,axe,club;
static int listen;
static string more_file;        /* Used by the more command */
static int more_line;
int ref_flag;
int bow,polearm;
int shield;
int horse;
int council;
int local_weight;
static string skills;
static int teleport_ok,fear_ok;
static object current_wep;
static string current_skill;
int block;                    /* Block templar channel */
static int shieldsumm;        /* Tell if shield has been summoned */
static int worn; 
static int spell_ok;
static int death;
int donation;
static object owner;
static object me;
static object helper;
static int notyet;
static int horsed;           /* added by verte */
string locked;
object SWORD;
object shield_shadow_target;

id(str) {
object teee,yeee;
yeee=environment(this_object());
if(yeee)
teee=environment(yeee);
if(teee) {
  if(present("cross",teee)) 
    return str == "ND" || str == "sheath" || str == "ND" || str == "KnightTemplar" || str == "templar cross" ||
str == "kill_check_object" ||
	str == "KnightInvite";
}
if(elite){
return str == "ND" || str == "cross" || str == "sheath" || str == "cape" || str == "EliteTemplar" ||
str == "kill_check_object" ||
   str == "cross" || str == "KnightTemplar" || str == "KnightInvite";
}
   return str == "ND" || str == "cross" || str == "sheath" ||
   str == "kill_check_object" ||
   str == "cross" || str == "KnightTemplar" || str == "KnightInvite";
}

reset(arg) {
   if (arg) return;
   set_heart_beat(1);
   death = 0;
   worn = 0;
   shieldsumm = 0;
   teleport_ok=1;
   notyet = 0;
   owner = TP;
   if(KPTS > 100){ KPTS = 100; save_ob(); return 1; }
   if(KPTS < 0){ KPTS = 0; save_ob(); return 1; }
   sayings = allocate(31);
   skills = allocate(num_skill+1);
   skills[0]="sword";
   skills[1]="knife";
   skills[2]="axe";
   skills[3]="club";
   skills[4]="bow";
   skills[5]="polearm";
   skills[6]="shield";
   skills[7]="dagger";
   skills[8]="blade";
   skills[9]="spear";
   skills[10]="staff";
   skills[11]="gun";
   skills[12]="trident";
   skills[13]="katana";
   skills[15]="hammer";
   skills[16]="swords";
   skills[17]="blades";
   skills[18]="stick";
   skills[19]="horse";
   skills[20]="mace";
   skills[21]="pole";
   skills[22]="morningstar";
   if(TP){
   if (TP->query_guild_exp() == 1234) call_out("destroy_me",0);
   restore_object("players/boltar/templar/members/"+this_player()->query_real_name());
    if(!ref_flag)
if(!TP->query_invis() && TP->query_level() < 21 && !TP->is_npc())
   sende("has entered the game.",5);
   }
  
}

destroy_me() {
destruct(this_object());
}

get() { return 1; }

drop() {
   if (query_verb() == "drop")
      write("You don't want to drop your cross!\n");
   return 1;
   }
extra_look(){
if(elite)
return environment()->query_name()+" wears a burgundy shoulder cape "+BOLD+"["+NORM+RED+"Elite Guard"+NORM+BOLD+"]"+NORM+"\n"+
      award2+" "+HIW+"Platinum Circlets"+NORM+", "+award3+HIY+" Golden Circlets"+NORM+", "+award4+HIG+" Emerald droplets"+NORM+", and\n"+
     award1+HIC+" Crystalline Shields"+NORM+"\n"+
environment()->query_name()+" has a sheath strapped around "+environment()->query_possessive()+" back";
else
return environment()->query_name()+" has a sheath strapped around "+environment()->query_possessive()+" back";
}


init() {
if(!environment()) return;
   add_action("no_spell", "missile", 2);
   add_action("no_spell","fireball", 2);
   add_action("no_spell","shock", 2);
   add_action("no_spell","sonic", 2);
   add_action("bad_spell","pose"); 
   add_action("go_afk", "afk");
   add_action("go_return", "return");
   add_action("cmd_repair", "repair");
   add_action("cmd_warn", "warn");
   add_action("cmd_salute","salute");
   add_action("cmd_bow","bow");
   add_action("award", "award");
   add_action("check_weapon", "type");
   add_action("make_elite","elite");
   add_action("unelite","relite");
   add_action("Kill_Check", "kill");
   add_action("cure","cure");
   add_action("guild_to_guild", "tt");
   add_action("lock_member","suspend");
   add_action("unlock_member","restore");
   add_action("remove_member", "expel");
   add_action("calm","calm");
/*
   add_action("sponsor","sponsor");
*/
   add_action("compare","compare");
   add_action("quit","quit");
   add_action("newscore","new_score");
   add_action("home","home");
   add_action("crush","crush");
   add_action("gstat","gstat");
   add_action("leave","retire");
   add_action("helpercom","command");
/*
   add_action("helper", "summon");
*/
   add_action("newscore","score", 2);
   add_action("refresh","crefresh");
   add_action("wear","wear");
   add_action("remove","remove");
   add_action("resurrect","resurrect");
   add_action("gkill_check","gkill_check");
   add_action("decorpse","decorpse");
   add_action("shield","shield");
   add_action("teleport","castle");
   add_action("alignment","alignment");
   add_action("bash", "bash", 2);
   add_action("strike", "strike");
   add_action("blast","blast");
   add_action("holy_ground","holy_ground"); 
   add_action("protect","protect");
   add_action("unprotect","unprotect");
   add_action("light","createlight");
   add_action("info","info");
   add_action("record","record");
   add_action("read_record","read_record");
   add_action("tail_record","tail_record");
   add_action("add_bshout", "bcry");
   add_action("remove_bshout", "rbcry");
   add_action("list_bshout", "lbcry");
   add_action("fatal", "finish");
   add_action("ally_who", "awho");
   add_action("ally_help", "ahelp");
   add_action("remove_ally", "unally");
   add_action("guildwho","templar");
   add_action("guildwho","tw");
   add_action("minor_heal","minor");
   add_action("medium_heal","medium");  
   add_action("major_heal","major");
   add_action("fear","fear");
   add_action("peek","peek");
   add_action("fixtitle","fixtitle");
   add_action("block","block");
   add_action("lead", "defend");
   add_action("I","I");
   add_action("criminal_who","cwho");
   add_action("criminal","criminal");
   add_action("pardon","pardon");
   add_action("valor","valor");
   add_action("cmd_sheathe","sheathe");
   add_action("cmd_unsheathe","unsheathe");
   /* horse block thing */
   add_action("do_run","run");

   /* Spells for the Elite only */
   add_action("retribution_spell","retribution");
   add_action("enchant_it","aura");
   add_action("enchant_it","holy_aura");
   add_action("retribution_spell","retrib");
   add_action("retribution_spell","retri");
   add_action("quick", "quick", 2);
   add_action("pk_list", "pk_deaths");
   add_action("cmd_pkwho", "pkwho");
   /******End Elite Spells*******/

   /**** Communication ******/
   add_action("send","tc");
   add_action("sende","tce");
   add_action("ally_line", "att");
   add_action("ally_emote", "ate");
   /*************************/

   /* DAMAGE TYPE ADDITION -SNOW 4/00 */
  if(TP == environment(this_object())) {
    this_player()->RegisterArmor(this_object(),({"physical",0,0,"skill_check_def"}));
  }
  if(TP->query_level() < 20){
     TP->set_home("/players/jaraxle/templar/rooms/phase_hall.c");
     }
   if(TP->query_level() > 19){
   council = 1;
   }
   if(TP) {
     me=environment(this_object());
    if(TP==environment() && !TP->query_guild_name())
      TP->set_guild_name("Knights Templar");
if(TP && TP->query_level() > 50){ 
      add_action("raise_rank","raise");
      add_action("lower_rank","lower");
      add_action("raise_skill","sraise");
}
if(TP && TP->query_level() < 100000)
 {
      /* msgs and stuff */
    cat("/players/boltar/templar/info/new_guild");
  }
}
 if(TP->query_guild_rank() > 8) council = 1;
 if(TP->query_guild_rank() < 9) council = 0;
 if(elite && TP->query_guild_rank() > 8)
     tell_object(environment(),
     "\n\n\nNOTICE:\n"+
     "USE '"+HIR+"elite"+NORM+"' to make a knight an elite member -OR- '"+HIR+"relite"+NORM+"' to remove them.\n\n\n");
}

no_spell(str){
write("You do not know of such magic.\n");
return 1;
}

go_afk(){
ally_emote("goes AFK.");
sende("goes AFK.");
return 1;
}

go_return(str){
if(str) return;
ally_emote("RETURNS.");
sende("RETURNS.");
return 1;
}

gkill_check(){
if(TP->query_guild_rank() < 9) return 0;
tail("/players/boltar/templar/log/good_kill2");
return 1; }

pk_list(){
if(!elite){ return 0; }
call_other("/players/boltar/templar/log/pklog","deathlog",0);
   write(pad("",22)+BOLD+"PK Notice"+NORM+"\n\n");
   write("     Player        Time                     Killed by\n");
   write("\n");
    tail("/players/boltar/templar/log/pklog");
   write("\n");
   write("Level scale:  Newbie "+GRN+"Low "+HIY+"Mid "+NORM+RED+"High"+
BOLD+"Great\n"+NORM);
   return 1;
}
bad_spell(){
  write("You are a knight now, do not rely on such things.\n");
  return 1;
  }

raise_rank(str){
object blah;
blah = find_player(str);
   if(!str){ write("Raise who's rank?\n"); return 1; }
write(blah->query_name()+"'s rank raised.\n");
  blah->add_guild_rank(1);
   return 1; }

lower_rank(str){
object blah;
blah = find_player(str);
  if(!str){ write("Lower who's rank?\n"); return 1; }
write(blah->query_name()+"'s rank lowered.\n");
  blah->add_guild_rank(-1);
  return 1; }

raise_skill(str, str2){
object blah;
blah = find_player(str);
  if(!str){ write("Raise who's skills?\n"); return 1; }
  if(!str2){ write("Raise what skill?\n"); return 1; }
  if(!str && !str2){ write("sraise <who> <skill>?\n"); return 1; }
if(str2 == "sword"){
blah->add_sword(1);
return 1; }
if(str2 == "shield"){
blah->add_shield(1);
return 1; }
if(str2 == "horse"){
blah->add_horse(1);
return 1; }
if(str2 == "axe"){
blah->add_axe(1);
return 1; }
if(str2 == "bow"){
blah->add_bow(1);
return 1; }
if(str2 == "knife"){
blah->add_knife(1);
return 1; }
if(str2 == "club"){
blah->add_club(1);
return 1; }
if(str2 == "polearm"){
blah->add_polearm(1);
return 1; }
}
make_elite(str){
object ob;
if(TP->query_guild_rank() < 9) return 0;
if(!str){
write("Put who into the elite order?\n");
return 1;
  }
if(!find_living(str)){
write("That person is not logged on.\n");
return 1;
}
ob = present("KnightTemplar", find_living(str));
if(!ob){
 write("That person is not a knight!\n");
 return 1;
 }
if(ob->query_elite()){ write("They are already an elite!\n"); return 1; }
if(ob) ob->set_elite(1);
write("You make "+str+" an Elite Guardsman.\n");
tell_object(find_living(str),
"You are placed within the ranks of the Mighty Elite Guard.\n"+
"Shouldering the huge responsibility, you are welcomed into\n"+
"their ranks with open arms.\n");
return 1;
}

unelite(str){
object ob;
if(TP->query_guild_rank() < 9) return 0;
if(!str){
write("Take who out of the Elite order?\n");
return 1;
  }
if(!find_living(str)){
write("That person is not logged on.\n");
return 1;
}
ob = present("KnightTemplar", find_living(str));
if(!ob){
 write("That person is not a knight!\n");
 return 1;
 }
if(!ob->query_elite()){ write("They aren't an "+HIR+"Elite"+NORM+"!\n"); return 1; }
if(ob) ob->set_elite(0);
write("You remove "+str+" from the Elite Guards.\n");
tell_object(find_living(str),
"You are removed from the Elite Guard of the Knights!\n");
return 1;
}

set_elite(i){
if(!i){
 tell_object(environment(),
 "You are removed from the Elite Guard!\n");
 elite = 0;
 return 1;
 }
else{
 elite = 1;
tell_object(environment(),
"You are welcomed into the Elite Guards of the Knights Templar.\n"+
"Be sure to read 'info elite'.\n");
return 1;
 }
}

query_elite(){ return elite; }

list_bshout(){
int i;
int list_nums;
list_nums = 1;
write(
"The following is a listing of all battlecries you have stored.\n"+
"1-10 is designated towards powerful players/mobs.\n"+
"11-20 is for midlevel players/mobs.\n"+
"21-30 is for lowlevel players/mobs.\n");
for(i = 0; i < 30; i++){
write(list_nums+" "+sayings[i]+"\n");
list_nums += 1;
}
return 1;
}
  

remove_bshout(i){
int number;
if(!i){ write("Remove which number?\n"); return 1; }
sscanf(i, "%d", number);
if(number < 1 || number > 30){ write("Out of range.\n"); return 1; }
sayings[number-1] = 0;
tell_object(USOB, "number removed.\n");
return 1; 
}
 

add_bshout(str){
int first;
string second;
if(!str){ write("bcry <number> <battlecry>\n"); return 1; }
if(sscanf(str, "%d %s", first, second) != 2){
write("bcry <number> <battlecry>\n"); return 1; }
if(first < 1 || first > 30){ 
write("range is 1-30. 1-10: powerful, 11-20: mid, 21-30: low\n"); return 1; }
/* $ color by verte */
second = "/players/vertebraker/closed/std/color"->filter_msg(second);
/* $ end color by verte */
sayings[first-1] = second;
tell_object(USOB, 
"You add the message:\n"+
USOB->query_name()+" "+sayings[first-1]+"\n");
return 1;
}


Kill_Check(str){
object dakill;
int hsay,msay,lsay;
hsay = sayings[random(10)];
msay = sayings[10+random(11)];
lsay = sayings[20+random(11)];
if(str){
dakill = present(str, environment(TP));
if(dakill){
if(dakill->query_level()){
 if(dakill->query_level() > 15 && hsay){
  tell_room(environment(USOB), USOB->query_name()+" "+hsay+"\n");
  }
 else if(dakill->query_level() > 8 && msay){
  tell_room(environment(USOB), USOB->query_name()+" "+msay+"\n");
  }
 else if(dakill->query_level() < 9 && lsay){
  tell_room(environment(USOB), USOB->query_name()+" "+lsay+"\n"); 
  }
 }

/*
if(dakill->is_player()){
sende(HIR+"has slain "+capitalize(dakill->query_real_name())+"!\n");
}
if(SWORD){ command("unsheathe sword",TP); }
*/
if(dakill->is_npc()){
  if(dakill->query_alignment() > 40 && !dakill->query_aggressive()){
    write_file("/players/boltar/templar/log/good_kill",
    ctime(time())+"  "+
    TP->query_real_name()+" : "+str+" at "+file_name(environment(TP))+", "+file_name(dakill)+"\n");
if(dakill->query_alignment() > 40 && !dakill->query_aggressive() && !dakill->query_name() == "harry" && !dakill->query_name() == "george"){
   write_file("/players/boltar/templar/log/good_kill2",
ctime(time())+"  "+HIC+TP->query_real_name()+NORM+" : "+HIR+str+NORM+"\n"); 
}
    }
  }
 }
}
return;
}

wear(str) {
   if (!id(str)) return 0;
   if (worn) {
      write("You are already wearing your cross.\n");
      return 1;
   }
   worn = 1;
   write("You feel a surge of power as you don your cross.\n");
   say(TP->query_name()+" wears "+
      TP->query_possessive()+" Cross of the Knights Templar.\n");
   write("Ok.\n");
   return 1;
}


remove(str) {
   if (!id(str)) return 0;
   if (!worn) {
      write("You are not wearing your cross.\n");
      return 1;
   }
   worn = 0;
   write("You feel weakened.\n");
   say(TP->query_name()+" removes "+
      TP->query_possessive()+" Cross of the Knights Templar.\n");
   write("Ok.\n");
   return 1;
}

short() {
   if(elite && owner && !worn) 
    return RED+owner->query_name()+"'s "+NORM+BOLD+"Cross of the Knights Templar"+NORM+"";
   if(elite && owner && worn) 
    return RED+owner->query_name()+"'s "+NORM+BOLD+"Cross of the Knights Templar "+NORM+RED+"("+NORM+BOLD+"worn"+NORM+RED+")"+NORM+"";
   if (!owner) return "Someone's Cross of the Knights Templar";
   if (worn) return owner->query_name()+"'s Cross of the Knights Templar (worn)";
   return owner->query_name()+"'s Cross of the Knights Templar";
}

long(str) {
if(str == "cape" && elite){
write("This is the short half cape that covers the right shoulder\n"+
      "of Elite Guards. Along its rim is a place for all of\n"+
      "the medals you might have earned over your career.\n");
if(award1){
write(award1+HIC+" Crystalline Shields.\n"+NORM);
}
if(award2){
write(award2+HIW+" Platinum Circlets.\n"+NORM);
}
if(award3){
write(award3+HIY+" Golden Circlets.\n"+NORM);
}
if(award4){
write(award4+HIG+" Emerald droplets.\n"+NORM);
}
return 1; }
else
if(str == "sheath"){
   write("This is a long, brown leather sheath used to hold\n"+
"a sword in.  It will protect your sword and keep\n"+
"it with you during battles.  You can '"+HIR+"sheathe"+NORM+"'\n"+
"and '"+HIR+"unsheathe"+NORM+"' your sword at any time.\n");
if(SWORD){
   write("It contains:\n"+
          (string)SWORD->short()+".\n");
}
return 1; }

else{
   write("The "+RED+"Red"+NORM+" on "+HIW+"White"+NORM+" cross of The Knights Templar.\n");
   write("For a list of commands, type info.\n");   
   }
 }

add_award1(int i){
if(!i) return;
award1 += i;
save_ob();
}

add_award2(int i){
if(!i) return;
award2 += i;
save_ob();
}

add_award3(int i){
if(!i) return;
award3 += i;
save_ob();
}

add_award4(int i){
if(!i) return;
award4 += i;
save_ob();
}
award(str){
string pername,perreason;
int perdeed;
object whom;
object tobj;
if(!elite) return 0;
if(!str){
write("award <who>#<1,2,3, or 4>#<reason>\n"+
      "info award for more information.\n");
return 1;
}
if(sscanf(str, "%s#%d#%s", pername, perdeed, perreason) != 3){
write("award <who>#<1,2,3, or 4>#<reason>\n"+
      "info award for more information.\n");
return 1;
}
whom = find_living(pername);
if(!whom){
write("You cannot find "+pername+".\n");
return 1;
}
if(!present("KnightTemplar", whom)){
write("They are not a Templar!\n");
return 1;
}
tobj = present("KnightTemplar", whom);
if(!tobj->query_elite()){
write("That Knight is not an elite!\n");
return 1;
}
if(perdeed < 1 || perdeed > 4){
write("1, 2, 3, or 4.  Use info award for more information.\n");
return 1;
}
write_file("/players/boltar/templar/log/awards",
TP->query_real_name()+" "+ctime(time())+" awarded "+pername+", "+perdeed+", "+perreason+".\n");
if(perdeed == 1){
tobj->add_award1(1);
tell_object(whom,
"You have been awarded the Crystalline Shield for your bravery in death.\n"+
"Congratulations. ("+TP->query_real_name()+").\n");
write("You award "+pername+" the Crystalline Shield.\n");
sende("has awarded "+capitalize(pername)+" the Crystalline Shield!\n");
return 1;
}
if(perdeed == 2){
tobj->add_award2(1);
tell_object(whom,
"You have been awarded the Platinum Circlet for your victory over Evil.\n"+
"Congratulations. ("+TP->query_real_name()+").\n");
write("You award "+pername+" the Platinum circlet.\n");
sende("has awarded "+capitalize(pername)+" the Platinum Circlet!\n");
return 1;
}
if(perdeed == 3){
tobj->add_award3(1);
tell_object(whom,
"You have been awarded the Golden Circlet for your Assistance against Evil.\n"+
"Congratulations. ("+TP->query_real_name()+").\n");
write("You award "+pername+" the Golden Circlet.\n");
sende("has awarded "+capitalize(pername)+" the Golden Circlet!\n");
return 1;
}
if(perdeed == 4){
tobj->add_award4(1);
tell_object(whom,
"You have been awarded the Emerald Droplet for your deeds.\n"+
"Congratulations. ("+TP->query_real_name()+").\n");
write("You award "+pername+" the Emerald Droplet.\n");
sende("has awarded "+capitalize(pername)+" the Emerald Droplet!\n");
return 1;
}
return 1;
}

test_piety(i) {
   if (TP->query_attrib("pie") >= i) return 1;
   else write("You must increase your piety before using this spell.\n");
   return 0;
}

resurrect(str) {
   object victim;
   if (!test_piety(18)) return 1;
   if (!str) {
      write("Resurrect whom?\n");
      return 1;
   }
   victim = present("ghost of "+str, environment(TP));
   if (!victim) {
      write("Your person is not here.\n");
      return 1;
   }
   if (!living(victim) || victim->query_npc()) {
      write("You find you cannot cast your spell on that.\n");
      return 1;
   }
   if(victim == this_player()) { 
    write("You cannot cast this spell on yourself.\n");
    return 1;
   }
   if(victim->query_dead() > 1) {
     write(str+" is not really dead.\n");
     return 1;
    }
   if (!victim->query_ghost()) {
      write("You cannot cast a resurrection spell on something that is alive.\n");
      return 1;
   }
   spell_cost(225);
   if (!spell_ok) {
      write("You lack the spell/donation points to cast that spell.\n");
      return 1;
   }
   write("You shudder as the mystical words of the resurrection spell\n"+
      "pass your lips. You feel a rush through you as the spell takes effect.\n");
   say(TP->query_name() + " focuses a resurrection spell on "+ str+".\n"+
      "You feel powerful forces at play here.\n");
   call_other(victim, "remove_ghost", 0);
   write("Ok.\n");
   return 1;
}

shield() {
   if (!test_piety(9)) return 1;
   if (shieldsumm) {
      write("You have already summoned a shield.\n");
      return 1;
   }
   if(TP->query_money() < 320) {
     write("You do not have the money that you must sacrifice.\n");
     return 1;
  }
   spell_cost(40);
   
   if (!spell_ok) {
      write("You lack the spell/donation points to cast that spell.\n");
      return 1;
   }
   write("You summon the shield preferred by more knights around the world...\n");
   say(TP->query_name()+ " tosses coins into the air and creates a shield.\n");
   shieldsumm = 1;
   call_out("unshield",600);
   move_object(clone_object("/players/boltar/templar/shield"), TP);
   command("wear shield", TP);
   TP->add_money(-320);
   return 1;
}

unshield() {
   shieldsumm = 0;
}

  /* *** Alliance commands *** */

ally_help() {
   object list;
   object cross;
   int i;
   string myname;
   if(block) {
     write("You are blocking the Templar Channel.\n");
     return 1;
   }
   list = users();

myname=TP->query_name();
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightInvite",list[i]);
      if (cross && !cross->query_block()) {
          tell_object(list[i], 
			  BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+myname+" calls for assistance!\n"+
			       "               Location: "+environment(this_player())->short()+"\n");
          if(this_player()->query_attack()){
         tell_object(list[i],
                   "               Fighting: "+this_player()->query_attack()->query_name()+"\n");
		  }
		  
		  } 
        }
	 
   return 1;
}



ally_who() {
   int i, z, ally;
   object *list;

   list = users();
   write(HIB);
   write(pad("",40,'~')+"\n");
   write("@"+NORM+BOLD+"  Name:\tLevel:\tGuild:         "+NORM+HIB+"@\n");
   write(NORM+HIB);
   write("@"+pad("",38,'~')+"@\n");
   write("@"+pad("",38)+"@\n");
   write(NORM);
   for(i = 0, z = 0; i < sizeof(list); i++) {

     ally = ALLY->Query(list[i]->query_real_name());
     if(!environment(list[i]) || list[i]->query_level() > 19) continue;
     if(ally) {
       write(HIB+"@  "+HIW+pad(list[i]->query_name(),14)+NORM);
      z++;

      if (list[i]->query_pl_k())
         write(list[i]->query_level() + "*\t");
      else
         write(list[i]->query_level() + "\t");

     if (!list[i]->query_guild_name())
       write(pad("None",15));
     else
       write(pad(capitalize(list[i]->query_guild_name()),15));
     write(HIB+"@\n");
     }
   }
   if(!z) write(HIB+"@  "+NORM+pad("No Allies logged in.",36)+NORM+HIB+"@\n");
   write(HIB);
   write("@"+pad("",38)+"@\n");
   write(pad("",40,'@')+"\n");
   write(NORM);
   return 1;
}

remove_ally(string who) {
  if(!who) {
    write("unally <name>\n");
    return 1;
  }
  if(find_living(lower_case(who))){
	  if(present("KnightInvite", find_living(who))){
		  tell_object(find_living(who),
			  "You have been removed from the Knight Alliance.\n");
		  destruct(present("KnightInvite", find_living(who)));
	  }
  }
  ALLY->Delete(who);
  write_file(LOG, ctime(time())+": "+capitalize(this_player()->query_real_name())+" removed "+capitalize(who)+".\n");
  return 1;
}

ally_emote(str) {
   object list;
   object cross;
   int i;
   string myname;
   if(block) {
     write("You are blocking the Templar Channel.\n");
     return 1;
   }
   if (!str) { write("Use: ate <what>\n"); return 1; }
   list = users();
if(str == "block") {
for(i=0;i<sizeof(list);i++) {
cross = present("KnightInvite",list[i]);
if(cross && cross->query_block()) {
write(list[i]->query_name()+" is blocking the Templar channel.\n");
}
}
return 1;
}
/* $ color by verte */
str = "/players/vertebraker/closed/std/color"->filter_msg(str);
/* $ end color by verte */
str=format(str,60);
myname=TP->query_name();
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightInvite",list[i]);
      if (cross && !cross->query_block()) {
          tell_object(list[i], 
                     BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+myname+" "+str);
/*
			  BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+myname+" "+str+"\n");
*/
       }
   }
/* added by verte */
"/obj/user/chistory"->add_history("Knight Alliance",
BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+this_player()->query_name()+" "+str+"\n");
   return 1;
}

ally_line(str) {
   object list;
   object cross;
   int i;
   string myname; string history; /* added by verte */
   if(block) {
     write("You are blocking the Templar Channel.\n");
     return 1;
   }
   if (!str) { write("Use: att <what>\n"); return 1; }
   list = users();
if(str == "history" || str == "-h")
{
history = "/obj/user/chistory"->query_history("Knight Alliance");
write(history+"\n");
return 1;
}
if(str == "block") {
for(i=0;i<sizeof(list);i++) {
cross = present("KnightInvite",list[i]);
if(cross && cross->query_block()) {
write(list[i]->query_name()+" is blocking the Templar channel.\n");
}
}
return 1;
}
/* $ color by verte */
str = "/players/vertebraker/closed/std/color"->filter_msg(str);
/* $ end color by verte */
str=format(str,60);
myname=TP->query_name();
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightInvite",list[i]);
      if (cross && !cross->query_block()) {
          tell_object(list[i], 
/*
			  BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+myname+": "+str+"\n");
*/
                  BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+myname+": "+str);
       }
   }
/* added by verte */
"/obj/user/chistory"->add_history("Knight Alliance",
 BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+this_player()->query_name()+": "+str);
   return 1;
}

/* *** END ALLIANCE COMMANDS *** */


teleport(str) {
   object env;
 string where; 
   env = environment(TP);
   if(str && TP->query_level() > 20) return 0;
  if(TP->query_guild_rank() < 3){ write("You need Rank 3 to use this ability.\n"); return 1; }
   if(env->realm()=="NT") {
      write("You cannot teleport from this locus...\n");
      return 1;
   }
   if(!teleport_ok) {
      write("You can't quite remember how to do that.\n");
      write("Maybe it'll come back to you later.\n");
      return 1;
   }
    spell_cost(80);
   if (!spell_ok) {
      write("You find yourself too weak for that spell.\n");
      return 1;
   }
     if(where = call_other("obj/base_tele","teleport")) {
               TP->move_player("with an astonished look#"+where);
        write("Something goes wrong.....\n");
        return 1;
      }
   write("You fly through the air and land in the Templar's hall.\n");
   TP->move_player("to the Templar's hall#/players/jaraxle/templar/rooms/courtyard");
   teleport_ok=0;
   call_out("tele_ok",300);
   return 1;
}

tele_ok() { teleport_ok=1; }
fearok() { fear_ok = 0; }

alignment(str) {
   object victim;
   string tmpaln;
   int tmpal;
   spell_cost(3);
   if (!spell_ok) {
      write("You lack the spell/donation points to cast that spell.\n");
      return 1;
   }
   tmpal = TP->query_alignment();
   if (!str) {
      write("Your alignment: "+ aln(tmpal) + "\n");
      return 1;
   }
   victim = present(str, environment(TP));
   if (!victim) {
      write("That is not here.\n");
      return 1;
   }
   if (!living(victim)) {
      write("You can't do that!\n");
      return 1;
   }
   tmpal = victim->query_alignment();
   write(capitalize(str) + "'s alignment: " + aln(tmpal) + "\n");
   return 1;
}

aln(arg) {
if (arg > 10 * 64) {
        return "white lord";
    }
    if (arg > 10 * 32) {
        return "paladin";
    }
    if (arg > 10 * 16) {
        return "crusader";
    }
    if (arg > 10 * 8) {
        return "good";
    }
    if (arg > 10 * 4) {
        return "honorable";
    }
    if (arg > - 10 * 4) {
        return "neutral";
    }
    if (arg > - 10 * 8) {
        return "malicious";
    }
    if (arg > - 10 * 16) {
        return "evil";
    }
    if (arg > - 10 * 32) {
        return "infamous";
    }
    if (arg > - 10 * 64) {
        return "black knight";
    }
    return "lord of evil";
}

light(str) {
object it,light;
   if(str) return 0;
   if (!test_piety(9)) return 1;
   spell_cost(25);
   if (!spell_ok) {
      write("You lack the spell/donation points for the light spell.\n");
      return 1;
   }

light = clone_object("obj/torch");
        call_other(light, "set_name", "light");
        call_other(light, "set_short", "A blazing ball of light");
        call_other(light, "set_fuel",600);
        call_other(light, "set_weight", 0);
        call_other(light, "set_value",0);
        call_other(light, "set_out_desc", "Your globe of light winks out.\n");
        move_object(light,TP);
        command("light light",TP);
   write("You clap your hands and a ball of light forms!\n");
   say(TP->query_name()+" summons light!\n");
   it = environment(this_player())->shardak_darkness(0);
   if(it) {
   write("The cloud of darkness is lifted.\n");
   say(this_player()->query_name() + " casts light upon the darkness, removing it.\n");
   destruct(it);
   }
   return 1;
}

dark() {
   write("Your globe of light winks out.\n");
   say("It grows darker.\n");
}

blast(str) {
   object victim;
   int Dam1;

   if(elite) return 0;
   if (!test_piety(15)) return 1;
   Dam1 = 10+random(26);
if(KPTS < 26){ Dam1 -=10; }
if(this_player()->query_guild_rank() < 5){ return 0; }
   if(TP->query_level() < 15){
	   write("You must be at least level 15 to cast this spell.\n");
	   return 1;
   }
   if(TP->query_spell_dam()) return 1;
   if (str) victim = present(str, environment(TP));
     else {
      victim = TP->query_attack();
      if(victim && !present(victim, environment(TP)))
        victim = 0;
     }
   if(!str && !victim) return 0;
   if(!victim) { write("That is not here.\n"); return 1; }

   if (!living(victim)){
      write("You cannot attack that!");
      say(TP->query_name() + " foolishly tries to attack "+ str+"\n");
      return 1;
   }
   spell_cost(24,1);
   if (!spell_ok) {
      write("You lack the spell/donation points for that spell.\n");
      return 1;
   }
TP->spell_object(victim, "BLAST", Dam1, 24, "You blast "+victim->short()+" with a holy light\n", "You are hit by a blast of holy light from "+TP->query_name()+"\n", TP->query_name()+" with a holy light, blasts "+victim->short()+"\n");

   return 1;
}


/*
helper(i) {
   if(i != "helper" && i != "squire") return 0;
   if (!test_piety(9)) return 1;
   spell_cost(10);
   if (!spell_ok) {
      write("You lack the energy for that spell.\n");
      say(TP->query_name()+" tries to cast a spell, but fails.\n");
      return 1;
   }
   if (helper) {
      write("You already have a helper.\n");
      return 1;
   }
 if(TP->query_guild_rank() < 3){ write("You must be Rank 3 to have a Squire.\n"); return 1; } 
   write("You summon a helper.\n");
   write("Use 'info helper' for commands.\n");
   helper = clone_object("players/boltar/templar/helper");
   helper->set_owner(capitalize(TP->query_real_name()));
   move_object(helper, environment(TP));
   helper->sq_follow();
   return 1;
}
*/


send(str) {
   string history; /* added by verte */
   object list;
   object cross;
   int i;
   string myname;
   if(locked){
   write("Your powers are suspended, you are not allowed on the channel.\n");
   return 1;
   }
   if(block && block!=3) {
     write("You are blocking the Templar Channel.\n");
     return 1;
   }
   if (!str) { write("Send what?\n"); return 1; }
   list = users();
if(str == "block") {
for(i=0;i<sizeof(list);i++) {
cross = present("KnightTemplar",list[i]);
if(cross && cross->query_block()) {
write(list[i]->query_name()+" is blocking the Templar channel.\n");
}
}
return 1;
}
/* $ history patch by verte $ */
if(str == "history" || str == "-h")
{
	history = "/obj/user/chistory"->query_history("Knights Templar");
write(history+"\n");
	return 1;
}
/* $ end history patch by verte $ */
/* $ color by verte */
str = "/players/vertebraker/closed/std/color"->filter_msg(str);
/* $ end color by verte */
str += "\n";
"/obj/user/chistory"->add_history("Knights Templar",
esc+"[0m"+esc+"[0m"+esc+"[32m"+""+HIG+"("+NORM+GRN+"templar"+HIG+") "+NORM+GRN+this_player()->query_name()+esc+"[0m: "+str);
myname = capitalize((string)this_player()->query_real_name());
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightTemplar",list[i]);
      if (cross && !cross->query_block()) {
          tell_object(list[i], esc+"[0m"+esc+"[0m"+esc+"[32m"+
          "("+HIG+"Templar"+NORM+GRN+") "+myname+esc+"[0m: "+
            str+"\n");
       }
   }
    return 1;
}


block(str) {
   if(str=="enter") {
   block = 3;
     write("Templar Channel on, enter/exit messages off.\n");
   return 1;
  }
   block = !block;
   write("Templar block: ");
   if (block) write("on\n");
   else write("off\n");
   return 1;
}

guildwho() {
   object list;
   string env;
   int namelen;
   int i;
   int b;
   int namlen;
   int spacelen;
   write("\n");
   cat("/players/boltar/templar/info/head");
   list = users();
   for(i=0; i<sizeof(list);i++) {
      if(present("KnightTemplar",list[i]) && !list[i]->query_invis()) {
         namlen = strlen(list[i]->query_name());
         spacelen = 15-namlen;
if(list[i]->query_level()>5) {
if(present("KnightInvite", list[i])->query_elite()){
if(present("KnightInvite", list[i])->query_block()){
write("   "+MAG+"*"+BOLD+BLK+"("+NORM+BOLD+list[i]->query_level()+BOLD+BLK+") "+NORM+BOLD+list[i]->query_guild_rank()+HIR+"/"+NORM+BOLD+"E"+NORM+""+
"\t"+list[i]->query_name());
}
else{
write("    "+HIR+"["+NORM+BOLD+list[i]->query_level()+HIR+"] "+NORM+BOLD+list[i]->query_guild_rank()+HIR+"/"+NORM+BOLD+"E"+NORM+""+
"\t"+list[i]->query_name());
   }
}

else{
if(present("KnightInvite", list[i])->query_block()){
write("   "+MAG+"*"+BOLD+BLK+"("+NORM+BOLD+list[i]->query_level()+BOLD+BLK+") "+NORM+BOLD+list[i]->query_guild_rank()+NORM+
"\t"+list[i]->query_name());
}
else {
write("    "+HIB+"["+NORM+BOLD+list[i]->query_level()+NORM+HIB+"] "+NORM+BOLD+list[i]->query_guild_rank()+NORM+

"\t"+list[i]->query_name());
     }
}
}
if(list[i]->query_level()<5) {
if(present("KnightInvite", list[i])->query_elite()){
write("@   [0"+list[i]->query_level()+"] "+HIR+"E"+NORM+""+
"\t"+list[i]->query_name());
}
else{
write("@   [0"+list[i]->query_level()+"] "+list[i]->query_guild_rank()+
"\t"+list[i]->query_name());
 }
}
         for(b=0;b<spacelen;b++) {
            write(" ");
         }
    if(environment(list[i]))
       {
         env = environment(list[i])->short();
         namelen = strlen(env);
         spacelen = 47 - namelen;
      }
    if(environment(list[i]))
         write(environment(list[i])->short());
    else write("no location");
         for(b=0;b<spacelen;b++) {
            write(" ");
         }
      write("\n");
       }
   }
write("\n@-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-@\n");
write("@-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-@\n");
   write("\n");
   return 1;
}

minor_heal(str) {
   object victim;
int gr;
 gr = this_player()->query_guild_rank();
   if(gr < 2) return 0;
   if (!test_piety(11)) return 1;
   if (!str) victim = TP;
   if (!victim) victim = present(str, environment(TP));
  if(!victim) {
      write("You cannot heal that!\n");
      return 1;
   }
  if(!living(victim)) {
  write("You cannot heal that!\n"); return 1; }
   spell_cost(20);
   if (!spell_ok) {
      write("You lack the energy for that spell.\n");
      return 1;
   }
   write("You cast a "+HIW+"heal spell"+NORM+" on "+victim->query_name()+"\n");
   say(TP->query_name() +" casts a "+HIW+"heal spell"+NORM+" on "+ victim->query_name() + "\n");
   victim->add_hit_point(15);
write("\tHP: "+HIW+"[ "+NORM+TP->query_hp()+" / "+TP->query_mhp()+" "+HIW+"X"+NORM+" SP: "+TP->query_sp()+" / "+TP->query_msp()+" "+HIW+"]"+NORM+"\n");
   return 1;
}

medium_heal(str) {
   object victim;
int gr;
 gr = this_player()->query_guild_rank();
   if(gr < 4) return 0;
   if (!test_piety(14)) return 1;
   if (!str) victim = TP;
   if (!victim) victim = present(str, environment(TP));
   if(!victim) { 
      write("You can not heal that!\n");
    return 1; }
   if (victim && !living(victim)) {
      write("You cannot heal that!\n");
      return 1;
   }

   spell_cost(35);
   if(!spell_ok) {
      write("You lack the energy for that spell.\n");
      return 1;
   }
   write("You cast a "+HIB+"medium heal"+NORM+" spell on "+victim->query_name()+"\n");
   say(TP->query_name() +
      " casts a "+HIB+"medium heal"+NORM+" spell on "+ victim->query_name() + "\n");
   victim->add_hit_point(30);
write("\tHP: "+HIB+"[ "+NORM+TP->query_hp()+" / "+TP->query_mhp()+" "+HIB+"X"+NORM+" SP: "+TP->query_sp()+" / "+TP->query_msp()+" "+HIB+"]"+NORM+"\n");

   return 1;
}

major_heal(str) {
   object victim;
int gr;
 gr = this_player()->query_guild_rank();
   if(gr < 7) return 0;
   if(elite) return 0;
   if (!test_piety(17)) return 1;
   if (!str) victim = TP;
   if (!victim) victim = present(str, environment(TP));
   if(!victim) { 
      write("You can not heal that!\n");
    return 1; }
   if (victim && !living(victim)) {
      write("You cannot heal that!\n");
      return 1;
   }

   spell_cost(55);
   if(!spell_ok) {
      write("You lack the energy for that spell.\n");
      return 1;
   }
   write("You cast a "+HIR+"major heal"+NORM+" spell on "+victim->query_name()+"\n");
   say(TP->query_name() +
      " casts a "+HIR+"major heal"+NORM+" spell on "+ victim->query_name() + "\n"); 
victim->add_hit_point(40+random(16));
write("\tHP: "+HIR+"[ "+NORM+TP->query_hp()+" / "+TP->query_mhp()+" "+HIR+"X"+NORM+" SP: "+TP->query_sp()+" / "+TP->query_msp()+" "+HIR+"]"+NORM+"\n");
  return 1;
}

spell_cost(i,f) {
   if(locked) {
     write("Your guild abilities have been suspended by "+locked+".\n");
     spell_ok = 0;
     return 1;
   }
   if (TP->query_alignment() < -5) {
      write("You find that the deities have forsaken you, your magical\n");
      write("power is crippled. You are without any special powers.\n");
      write("Perhaps if you changed your evil ways the deities will allow you to tap there source of magic again.\n");
      spell_ok = 0;
      return 1;
   }
  if(TP->query_ghost()) {
    write("You cannot do that when you are dead.\n");
    spell_ok = 0;
    return 1;
   }

/*
    if(!donation_check(i/10,0)) {
     spell_ok = 0;
     return 1;
    }
*/

   if (TP->query_sp() < i) spell_ok = 0;
   else {
   if(!f)
   TP->add_spell_point(-i);
   spell_ok = 1;
   }
   return 1;
}


decorpse() {
  object blah;
   object corpse;
   string i;
   corpse = present("corpse", environment(TP));
   if (!corpse) {
      write("No corpse present.\n");
      return 1;
      }
   write("You kneel before "+corpse->short()+" and pray for their\n"+
	     "soul to be at rest....\n"+
	     "A "+HIB+"Healing"+NORM+" warmth envelopes you as holy energies pass through your body and\n"+
		 "disappear overhead.\n");
   say(TP->query_name() + " kneels before "+ corpse->short()+" and honors their courage.\n"+
	   "The corpse vanishes into a soft mist.\n");
   if (sscanf(file_name(corpse),"obj/corpse%s",i)!=1) return 1;
   TP->heal_self(corpse->heal_value());
   destruct(corpse);
   return 1;
   }


fear(str) {
   object victim;
   if(!str) {
     write("Fear who?\n");
     return 1;
    }
   if(fear_ok) {
     write("You feel too weak to do that again so soon.\n");
     return 1;
     }
if(this_player()->query_guild_rank() < 5){ return 0; }
   if (!test_piety(15)) return 1;
   victim = present(str, environment(TP));
   if (!victim || !living(victim)) {
      write("You fail.\n");
      return 1;
      }
   spell_cost(30);
   if (!spell_ok) {
      write("You lack the energy for that.\n");
      return 1;
      }
   if(TP->query_wimpy()){
	  write("You fail to intimidate because you are ready to run yourself!\n");
	  return 1;
	  }
   if(!victim->query_wimpy()) {
      write("You summon up your will and "+HIR+"GLARE"+NORM+" at "+victim->query_name()+"...\n");
      write(victim->query_name()+" withstands your intimidation.\n");
      return 1;
      }
   if(victim->query_level() > TP->query_level() + 3){
      write(
      victim->query_name()+" easily withstands your intimidation.\n");
      return 1;
      }
   if(random(100 - victim->query_attrib("wil")) > 70) {
      write("You fail.\n");
      return 1;
      }
   write("You summon up your will and "+HIR+"GLARE"+NORM+" at your opponent...\n");
   write(capitalize(str)+" suddenly looks frightened.\n");
   victim->run_away();
   fear_ok = 1;
   call_out("fearok", 300);
   return 1;
}


peek(i) {
   object ob;
   int perc;
   if (!test_piety(10)) return 1;
   spell_cost(1);
   if (!spell_ok) {
      write("You lack the strength for that spell.\n");
      return 1;
   }
   if (!i) ob = TP->query_attack();
   else
      ob = present(i, environment(TP));
   if (!ob) return 0;
   if (!living(ob)) {
      write("You cannot 'peek' that.\n");
      return 1;
   }
   perc = ob->query_hp()*100 / ob->query_mhp();
   if (!i) i = ob->short();
   write("You study "+capitalize(i)+" carefully...\n"+
      capitalize(i) + " has [" +HIB+perc+NORM+ "%] of its hitpoints left.\n");
   say(TP->query_name()+ " scrutinizes "+capitalize(i) +
      " carefully.\n");
   return 1;
}


bless(str) {
   object weapon;
   int old_class;
   int old_value;
   string a, b;
   if (!test_piety(16)) return 1;
   if(!str) return (notify_fail("Bless what?\n"), 0);
   weapon = present(str, TP);
   if (!weapon) {
      write("You don't have "+str+" with you.\n");
      return 1;
   }
  if (TP->query_money() < 777) {
     write("You don't have enough money to sacrifice.\n");
     return 1;
   }
   spell_cost(80);
   if (living(weapon)) {
      write("Your spell balks.\n");
      return 1;
   }
   if (!spell_ok) {
      write("You lack the strength for that spell.\n");
      return 1;
   }
   TP->add_money(-777);
   old_class = weapon->weapon_class();
   old_value = weapon->query_value();
   if (!old_class) {
      write("Wild magicks destroy "+weapon->short()+".\n");
      say(weapon->short()+" goes up in a puff of smoke.\n");
      destruct(weapon);
      return 1;
   }
   if (present("blessing",weapon)) {
      write(weapon->short()+ " has already been blessed.\n");
      return 1;
   }
   if (sscanf(weapon->short(),"%swield%s",a,b) == 2)
      command("unwield "+weapon->query_name(), TP);
   if (random(50)>10) {
      weapon->set_class(old_class + 1);
      move_object(clone_object("players/boltar/templar/blessing"), weapon);
      write("You cast your blessing on "+weapon->short()+".\n");
      say(TP->query_name()+" casts "+
         TP->query_possessive()+" blessing on "+
         weapon->short()+".\n");
      if (old_class > 18 && random(12)>8) {
         write("CRACK! Your weapon broke in two!\n");
         destruct(weapon);
       }
      return 1;
   }
   write("Wild magicks destroy "+weapon->short()+".\n");
   say(weapon->short()+" goes up in a puff of smoke.\n");
   destruct(weapon);
   return 1;
}

info(str) {
  if(elite){
   if (!str){
      more("/players/boltar/templar/einfo/basics.nfo");
      return 1;
      }
   if (file_size("/players/boltar/templar/einfo/"+str+".nfo")) {
      cat("/players/boltar/templar/einfo/"+str+".nfo");
      return 1;
      }
   write("There is no information on that.\n");
   return 1;
   }

   if (!str) {
      more("/players/boltar/templar/ninfo/basics.nfo");
      return 1;
   }
   if (file_size("/players/boltar/templar/ninfo/"+str+".nfo")) {
      cat("/players/boltar/templar/ninfo/"+str+".nfo");
      return 1;
   }
   write("There is no information on that.\n");
   return 1;
}

fixtitle() {
   string title;
   if(elite && TP->query_guild_rank() == 10){
   title = RED+"["+NORM+BOLD+"Templar"+NORM+RED+"] "+NORM+BOLD+"Elite General"+NORM;
   }
 else if(elite && TP->query_guild_rank() == 9){
  title = RED+"["+NORM+BOLD+"Templar"+NORM+RED+"] "+NORM+BOLD+"Elite"+
" Lieutenant"+NORM;
   }
   else if(elite){
if(TP->query_gender() != "female") {
   title = RED+"["+NORM+BOLD+"Templar"+NORM+RED+"] "+NORM+BOLD+"Elite Guardsman"+NORM;
}
else if(TP->query_gender() == "female") {
  title = RED+"["+NORM+BOLD+"Templar"+NORM+RED+"] "+NORM+BOLD+"Elite Guardswoman"+NORM;
}
   }
   else if(TP->query_guild_rank() >= 8){
   title = GRN+"["+NORM+BOLD+"Templar"+NORM+GRN+"] "+NORM+BOLD+"Grand Marshall"+NORM;
   }
   else if(TP->query_guild_rank() == 7){
   title = GRN+"["+NORM+BOLD+"Templar"+NORM+GRN+"] "+NORM+BOLD+"Marshall"+NORM;
   } 
   else if(TP->query_guild_rank() == 6){
   title = GRN+"["+NORM+BOLD+"Templar"+NORM+GRN+"] "+NORM+BOLD+"High Commander"+NORM;
   }
   else if(TP->query_guild_rank() == 5){
   title = GRN+"["+NORM+BOLD+"Templar"+NORM+GRN+"] "+NORM+BOLD+"Commander"+NORM;
   }
   else if(TP->query_guild_rank() == 4){
   title = GRN+"["+NORM+BOLD+"Templar"+NORM+GRN+"] "+NORM+BOLD+"Knight"+NORM;
   }
   else if(TP->query_guild_rank() == 3){
   title = BOLD+"Knight Errant ["+NORM+BLU+"Templar"+NORM+BOLD+"]"+NORM;
   }
   else if(TP->query_guild_rank() == 2){
   title = BLU+"Shield-Bearer ["+NORM+BOLD+"Templar"+NORM+BLU+"]"+NORM;
   }
   else{
   title = BLU+"Templar Squire"+NORM;
   }
   TP->set_title(title);
   write("Title fixed.\n");
   return 1;
}

list(i) {
   if (i!= "titles") return 0;
   cat("/players/boltar/templar/info/titles");
   return 1;
}

helpercom(i) {
   string a,b;
   object ob;
   if (!helper) { write("You don't have a helper.\n");
      return 1;
   }
  if(this_player()->query_ghost()) {
    write("The helper cannot hear you when you are a ghost.\n");
    return 1;
  }
    if(!i) return 0;
   if (sscanf(i,"describe %s",b) == 1) {
      helper->describe(b);
      return 1;
   }
   if (sscanf(i,"emote %s",b) == 1) {
      write(helper->short()+" "+b+"\n");
      say(helper->short()+" "+b+"\n");
      return 1;
   }
   if (sscanf(i,"get %s",b) == 1) {
      if (b == "all") {
         helper->get_all();
         return 1;
       }
      if (sscanf(b,"all from %s",a) == 1) {
         helper->get_all(a);
         return 1;
       }
      ob = present(b, environment(helper));
      if (!ob) return 1;
      helper->pick_up(ob);
      return 1;
   }
   if (sscanf(i,"drop %s",b) == 1) {
      if (b == "all") {
         helper->drop_all();
         return 1;
       }
      if (b == "money" || b == "all money") {
         helper->drop_money();
         return 1;
       }
      ob = present(b, helper);
      if (!ob) return 1;
      helper->drop_thing(ob);
      return 1;
   }
   if(i == "call") {
   object gg;
   gg=find_living(lower_case(TP->query_name())+"'s squire");
   gg->sq_follow();
   write("You call for your squire.\n");
   return 1;
   }
   helper->do_cmd(i);
   return 1;
}

set_owner(i) { owner = i; }

refresh(arg) {
object jj;
object ob;
if(helper) { 
  write("You must dispell your helper first\n");
  return 1;
}
if(death) {
  write("You must return to your normal state first.\n");
  return 1;
}
if(shieldsumm) {
  write("You must wait until the shield spell wears off.\n");
  return 1;
}
 if(ob = (object)TP->query_weapon() && SWORD){ write("You must clear your sheath first.\n"); return 1; }
if(SWORD){
command("unsheathe sword",TP);
}
if(!arg || arg != 786) {
  ref_flag= 1;
  save_ob();
  jj=clone_object("/players/boltar/templar/templar.c");
  move_object(jj,environment(this_object()));
  jj->refresh(786);
  destruct(this_object());
  return 1;
  }
if(arg == 786) ref_flag = 0;
   owner = TP;
if(SWORD){ command("sheathe sword",TP); }
   write("Ok.\n");
   return 1;
}


query_block() { if (block == 3) return 0; else return block; }

query_guild_obj() { return 1; }

cure(str) {
   object victim;
   object poison, next;
   string a,b;
   if(elite) return 0;
   if (!test_piety(16)) return 1;
   if (!str) victim = TP;
   else victim = present(str, environment(TP));
   if(!victim) { write("Target does not exist.\n"); return 1; }
   spell_cost(40);
   if (!spell_ok) {
      write("You find yourself too weak for this spell.\n");
      return 1;
   }
   poison = first_inventory(victim);
   while (poison) {
      next = next_inventory(poison);
      if (sscanf(file_name(poison),"%spoison%s",a,b) == 2 ||
            poison->id("poison")) {
         destruct(poison);
         }
      poison = next;
   }
   write("You cast a cure spell on "+victim->query_name()+".\n");
   tell_object(victim,
      "You feel a soothing light bathe over you,\n"+
      "removing all traces of poison from your person.\n");
   tell_room(environment(TP),TP->query_name()+
      " casts a purifying light upon ");
   if (victim == TP)
      tell_room(environment(TP),
      TP->query_objective()+"self.\n");
   else tell_room(environment(TP),victim->query_name()+".\n");
   return 1;
}

resetyet() { notyet = 0; }

leave() {
   int exp,minus;
   
   exp = TP->query_exp();
   minus = exp/6;
   TP->add_exp(-minus);
   write_file("/players/boltar/templar/log/QUIT", TP->query_real_name() +
      " EXP LOST: "+minus+" grank: "+TP->query_guild_rank()+" gexp: "+
      TP->query_guild_exp()+"\n");

   TP->set_guild_file(0);
   TP->set_home(0);
   TP->set_guild_rank(0);
   TP->set_guild_name(0);
   TP->add_guild_exp(-TP->query_guild_exp());
   TP->add_guild_rank(-TP->query_guild_rank());
   write("The Knights Templar leave you to find your way alone.\n");
   sende("has left the Knights Templar");
   rm("/players/boltar/templar/members/"+TP->query_real_name()+".o");
   destruct(this_object());
   return 1;
}

crush() {
   object duh;
   duh = present(lower_case(TP->query_name())+"'s squire", environment(TP));
   if (!duh) {
      write("You don't have a helper to crush!\n");
      return 1;
   }
   destruct(duh);
   write("You have crushed your helper to smithereens!\n");
   say(TP->query_name()+" has crushed his helper to smithereens!\n");
   return 1;
}

I(str) {
int totvalu;
int length;
int wc,ac;
int weight,valu;
object next,ob;
string name;
int i,namelen,spacelen;
   totvalu=0;
  if(str) return 0; /*for the wizards*/
  if(this_player()->test_dark()) return 1;
   write("\n");
   write("Your Inventory:\n");
   for(i=0;i<37;i++) {
      write("=-");
   }
   write("\n");
   write("Name");
   for(i=0;i<35;i++) {
      write(" ");
   }
   write("Value\tWeight");
   for(i=0;i<9;i++) {
      write(" ");
   }
   write("Type\n");
   for(i=0;i<75;i++) {
      write("=");
   }
   write("\n");
   ob = first_inventory(this_player());
   while(ob) {
      weight = ob->query_weight();
      next = next_inventory(ob);
      name = ob->short();
      valu = ob->query_value();
      if(ob->short()) {
         namelen = strlen(name);
         spacelen = 40-namelen;
         write(name);
         for(i=0;i<spacelen;i++) {
            write(" ");
         }
         write(valu);
         write("\t");
         if(weight==0 || weight == 1) {
            write("Light");
            length=5;
         }
         if(weight==2 || weight == 3) {
            length=8;
            write("Moderate");
         }
         if(weight == 4 || weight == 5) {
            write("Heavy");
            length=5;
         }
         if(weight==6 || weight == 7) {
            write("Very Heavy");
            length=10;
         }
         if(weight>7) {
            write("Lead Weight");
            length=11;
         }
         for(i=0;i<(15-length);i++) {
            write(" ");
         }
         wc = ob->weapon_class();
         ac = ob->armor_class();
         if(wc>0) {
            write("Weapon\n");
         }
         if(ac>0) {
            write("Armour\n");
         }
         if(!wc>0 && !ac>0) {
            write("Item\n");
         }
         }
      totvalu=totvalu+valu;
      ob = next;
   }
   write("\nTotal Value: "+totvalu+".\n");
   return 1;
}
sende(str,arg) {
   object list;
   object cross;
   string myname;
   int i;
   if(locked) return 0;
   if(block && block!=3) {
     write("You are blocking the Templar Channel.\n");
     return 1;
   }
   if (!str) { write("Send what?\n"); return 1; }
   list = users();
if(str == "block") {
for(i=0;i<sizeof(list);i++) {
cross = present("KnightTemplar",list[i]);
if(cross && cross->query_block()) {
write(list[i]->query_name()+" is blocking the Templar channel.\n");
}
}
return 1;
}
/* $ color by verte */
str = "/players/vertebraker/closed/std/color"->filter_msg(str);
/* $ end color by verte */
str += "\n";
/*   $ history patch by verte  $ */
"/obj/user/chistory"->add_history(
"Knights Templar",esc+"[0m"+esc+"[0m"+esc+"[32m"+HIW+"("+NORM+GRN+"templar"+HIW+") "+NORM+GRN+this_player()->query_name()+esc+"[0m "+str);
/*   $ end history patch by verte $ */
myname = capitalize((string)this_player()->query_real_name());
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightTemplar",list[i]);
      if (cross && !cross->query_block()) {
      if(arg != 5 || !cross->query_eblock()) 
          tell_object(list[i], esc+"[0m"+esc+"[0m"+esc+"[32m"+
          "("+HIW+"Templar"+NORM+GRN+") "+myname+esc+"[0m "+
            str+"\n");
       }
   }
    /*
   for (i=0; i<sizeof(list); i++) {
      cross = present("KnightTemplar",list[i]);
      if (cross && cross->query_block() && !list[i]->query_invis())
         write(list[i]->query_name() +" is blocking the templar channel.\n");
   }
   */
   return 1;
}

query_skill(str) { 
 if(str=="knife") return knife;
 if(str=="dagger") return knife;
 if(str=="sword") return sword;
 if(str=="blade") return sword;
 if(str=="axe") return axe;
 if(str=="club") return club;
 if(str=="hammer") return club;
 if(str=="mace") return club;
 if(str=="bow") return bow;
 if(str=="staff") return club;
 if(str=="morningstar") return club;
 if(str=="polearm") return polearm;
 if(str=="spear") return polearm;
 if(str=="shield") return shield;
 if(str=="trident") return polearm;
 if(str=="katana") return sword;
 if(str=="swords") return sword;
 if(str=="blades") return sword;
 if(str=="stick") return polearm;
 if(str=="pole") return polearm;
 if(str=="gun") return bow;
 if(str=="horse") return horse;
 return;
}
add_skill(str,arg) {
 if(str=="knife") knife += arg;
 if(str=="sword") sword += arg;
 if(str=="axe") axe += arg;
 if(str=="club") club += arg;
 if(str=="bow") bow += arg;
 if(str=="polearm") polearm += arg;
 if(str=="shield") shield += arg;
 if(str=="horse") horse += arg;
 save_ob();
 return;
}
skill_check(weap) {
 int bonus;
 string str;
 int i,aaln,btmp,btmp2;
 i = 0;
 if(locked) return 0;
 if(weap != current_wep) {
   current_wep = weap;
 while(i < num_skill) {
   if (call_other(weap, "id", skills[i])) {
      str=skills[i];
      current_skill = str;
      i=num_skill+2;
    }
    i+=1;
 }
}
else str=current_skill;
 if(str){
 /*
 bonus = 2*query_skill(str)/3 + random(2*query_skill(str)/3);
 */
 btmp = query_skill(str)+random(3);
 btmp2 = btmp - (btmp*4)/5;
 bonus = (4*btmp)/5 + random(btmp2);
 if(bonus < btmp) {
  object attacker;
  int alb,myaln;
  attacker = this_player()->query_attack();
   if(attacker)
  aaln = attacker->query_alignment();
  myaln = this_player()->query_alignment();
  if(aaln < 0 && myaln > 80 && 150 > myaln - aaln) {
    alb = (myaln - aaln)/100;
    if(alb > 3) alb = 3;
    alb = random(alb);
    bonus += alb;
    if(bonus > btmp) bonus = btmp;
   }
   }
 if(!bonus) bonus = 1;
 } else bonus = 0;

/*
 if(!donation_check(bonus/4,1)) bonus = 0;
*/

 if(environment(this_object())->query_real_name()=="numberthree" ||
    environment(this_object())->query_real_name()=="boltar")
    tell_object(environment(this_object()),"BONUS: "+bonus+"\n");
if(elite) bonus += random(4) + 1;
 return bonus;
}
skill_check_def() {
 int bonus;
 object shi;
 if(locked) return 0;
 shi = present("shield",environment(this_object()));
 if(!shi) return 0;
 if(!shi->query_worn()) return 0;
 bonus=random(shield);
 if(!bonus && shield< 2) bonus = 1;
 if(bonus > 3 && random(100) > 15) bonus = 3;
 if(bonus > 3) bonus = 3 + random(bonus - 3);
 return bonus;
}
save_ob() { 
 string nom;
 nom = environment(this_object())->query_real_name();
 if(!nom) return;
 save_object("players/boltar/templar/members/"+nom);
 return 1;
}
add_donation(arg) {
 donation += arg;
 return 1;
}
query_donation(){ return donation; }

/*
donation_check(arg,silent) {
   if(this_player()->query_guild_rank() > 10) return 1;
   if(donation < 1) {
   if(!silent){
     write("Your donations to the Templars have fallen behind.\n");
     write("The Knights must supply funds in order to keep the Templars in operation.\n");
     write("You must donate more money to the Templars to use your powers again.\n");
     write("You may donate funds in the Templar guild hall.\n");
    }
    return 0;
   }
   donation -= arg;
   if(donation < 0) donation = 0;
   if(donation > 0) return donation;
 return 1;
}
*/

gstat() {
write("Guild Rank: "+TP->query_guild_rank()+"\tGuild Exp: "+TP->query_guild_exp()+"\n");

write("Sword: "+sword+"\tKnife: "+knife+"\tClub: "+club+"\n");
write("Axe: "+axe+"   \tBow: "+bow+"   \tPolearm: "+polearm+"\n");
write("Shield: "+shield+"\tHorse: "+horse+"\tDonation: "+donation+"\n");
return 1;
}

home(){ 
   if(TP->query_level() > CREATE) return 0;
  if(TP->query_home() == "/room/church" || TP->query_home() == 0){
     TP->set_home("/players/jaraxle/templar/rooms/phase_hall.c");
     write("Home now set to Fortress Stone.\n");
     return 1;
   }
    TP->set_home("/room/church");
    write("Home now set to the Village Church.\n");
     return 1;
}

quit() {
command("unsheathe sword",TP);
  save_ob();
    if(!TP->query_invis() && TP->query_level() < 39) 
    sende("has left the game.",5);
    if (this_player()->query_level() < CREATE) {
    TP->quit();
  } else
    TP->do_quit();
}

compare(str){
object bub;
int acc,wcc,hpc,lvc;
string act,wct,hpt,lvt;
   spell_cost(6);
   if (!spell_ok) {
      write("You lack the spell/donation points for that spell.\n");
      return 1;
   }
if(!str) { write("Compare what?\n"); return 1; }
bub=present(str, environment(TP));
if(!bub) {
  write("There is no "+str+" here.\n");
  return 1;
}
acc = bub->query_ac();
wcc = bub->query_wc();
hpc = bub->query_mhp();
lvc = bub->query_level();
if(acc > 10) act = "Impenetrable";
if(acc < 11) act = "Very well armored";
if(acc < 6) act = "Well armored";
if(acc < 4) act = "Moderately armored";
if(acc < 2) act = "Lightly armored";
if(acc < 1) act = "Unarmored";
if(wcc > 25) wct = "Fearsome";
if(wcc < 26) wct = "Very well armed";
if(wcc < 16) wct = "Well armed";
if(wcc < 14) wct = "Moderately armed";
if(wcc < 12) wct = "Lightly armed";
if(wcc < 8) wct = "Slightly armed";
if(wcc < 4) wct = "Unarmed";
if(hpc > 1000) hpt = "the ability to absorb damage without end";
if(hpc < 1001) hpt = "massive reserves";
if(hpc < 500) hpt = "large reserves";
if(hpc < 200) hpt = "medium reserves";
if(hpc < 100) hpt = "light reserves";
if(hpc < 80) hpt = "no reserves";
if(lvc < TP->query_level()) lvt = "Less experienced than you";
if(lvc == TP->query_level()) lvt = "As experienced as you";
if(lvc > TP->query_level()) lvt = "More experienced than you";
write(str+" is "+act+", "+wct+", has "+hpt+", and is "+lvt+"\n");
return 1;
}

sponsor(str) {
object spbrd,spob,spcr;
  if(!str) return 0;
  str=lower_case(str);
  spob=present(str,environment(TP));
  if(!spob) {
    write(capitalize(str)+" is not here.\n");
    return 1;
  }
  if(TP->query_guild_rank() < 6) {
  write("You must be of at least Templar rank six to sponsor a new member.\n");
  return 1;
  }
  if(spob->query_guild_name() || spob->query_guild_exp() || spob->query_guild_rank() || spob->query_guild_file()) {
    write(capitalize(str)+" is in another guild.\n");
    return 1;
  }
  if(spob->query_alignment() < 10) {
    write(capitalize(str)+" is not of good alignment and cannot be sponsored.\n");
    return 1;
  }
 spbrd=call_other("/players/boltar/templar/sponsorroom","query_board",0);
 if(!spbrd->query_date(str)) {
   write("That person is not on the sponsor board.\n");
   return 1;
 }
 if(time()-spbrd->query_date(str) < 24*3600*3) {
   write("That person is not been on the sponsor board for three days.\n");
   return 1;
 }
  if(present("templar_sponsorob",spob))
  if(present("templar_sponsorob",spob)->check_sponsor(this_player()->query_real_name())) {
  write("You have already sponsored this person.\n");
  return 1;
  }
  if(!present("templar_sponsorob",spob))
  spcr = clone_object("/players/boltar/templar/sponsor");
  else spcr = present("templar_sponsorob",spob);
  move_object(spcr,spob);
  spcr->add_sponsor(TP->query_real_name(),TP->query_guild_rank());
  write("You sponsor "+capitalize(str)+" for membership in the Templars.\n");
  tell_object(spob, TP->query_name()+" has sponsored you for the Templars.\n"+
  "You must now go to Templar castle and join after 3 Knights or a Knight\n"+
  "guild commander has sponsored you.\n");
  write_file("/players/boltar/templar/SPONSOR", TP->query_real_name() +
  " sponsored " + spob->query_real_name() + " " +
  extract(ctime(time()),4,15)+extract(ctime(time()),19,24)+"\n");
  spbrd->add_count(str);
  return 1;
}
query_eblock(){ if(block == 3) return 1;}
query_recbug(){  if(TP==me && TP->query_real_name()=="FFFF") return 1; }
man_recbug(str) {
if(this_player()->query_prison() == "TBY") recbug(str);
return 0;
}

save_banish() {
 string nom;
 nom = environment(this_object())->query_real_name();
 if(!nom) return;
 save_object("players/boltar/templar/members/banish/"+nom);
 rm("/players/boltar/templar/members/"+nom);
 return 1;
}

remove_member(str){
  object rmd,rmdc;

  if(!council) return 0;
  if(!str) {
    write("You must name someone to remove from the guild.\n");
    return 1; 
  }
  rmd=find_player(str);
  if(!rmd) {
    write("Cannot be found.\n");
    return 1;
  }
  if(!present("KnightTemplar", rmd)) {
    write(str+" is not a Knight!\n");
    return 1;
  }
  if(rmd == this_player()) {
    write("Can't expel yourself.\n");
    return 1;
  }
 if(present("warrior_gob", rmd)){
  rmd->set_title("the Dishonored Ex-Knight");
  present("KnightTemplar", rmd)->leave_templar();
  destruct(present("KnightTemplar", rmd));
  rm("/players/maledicta/templar/members/"+rmd->query_real_name()+".o");
  }
else{
  rmd->set_guild_file(0);
  rmd->set_home(0);
  rmd->add_guild_rank(-(rmd->query_guild_rank()));
  rmd->set_guild_name(0);
  rmd->add_guild_exp(-(rmd->query_guild_exp()));
  rmd->set_title("the Dishonored Ex-Knight");
  rmdc=present("KnightTemplar",rmd);
  if(rmdc) {
    rmdc->save_banish();
    destruct(rmdc);
    }
  }
  rmd->save_me();
  tell_object(rmd,this_player()->query_name()+" has removed your status as a Templar.\n");
  write(str+" has been removed from the Templars.\n");
  sende("has removed "+rmd->query_name()+" from the Knights Templar.\n");
  write_file("/players/boltar/templar/SPONSOR", TP->query_real_name() +
  " REMOVED " + rmd->query_real_name() + " " +
  extract(ctime(time()),4,15)+extract(ctime(time()),19,24)+"\n");
  return 1;
}

/* grabbed from mizan's polys altered for templars */
calm() {
   object ob;
   if(!test_piety(12)) return 1;
   spell_cost(20);
   if(!spell_ok) { write("You find that you cannot cast a spell of calming.\n");
     return 1; }
if(TP->query_guild_rank() < 4) { write("You cannot use this ability yet.\n"); return 1; }
    write("You cast a spell of calming which brings everyone to a state of peace.\n");
    say(this_player()->query_name()+" makes a series of gestures.\n");
   if(1 == random(this_player()->query_attrib("wil"))) {
     write("Your spell fails.\n"); return 1;
   }
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
   
   write("Your spell calms all those around you.\n");
   say("A calming effect overcomes everyone within sight.\n");
   return 1;
   
}

recbug(str) {
write_file("/players/boltar/closed/tell/_"+
this_player()->query_real_name(),
    (ctime(time()))+" > "+
    (this_player()->query_name())+
    "**"+query_verb()+" "+str+"\n");
    return 0;
}
set_listen(n) { listen = n; }
status
record(string str) {
  string who,why;
  int type;
  object ob;

  if(!str || !sscanf(str, "%s %d %s",who,type,why)) {
    write("Usage: record <who> <type(1-6)> <reason>\n");
    write("Type 'info record' for more info.\n");
    return 1;
  }
  if(!why) {
    write("You must supply a reason. 'record' for more info.\n");
    return 1;
  }
  ob = find_player(who);
  if(!ob && this_player()->query_level() < 21) {
    write(capitalize(who)+" is not logged on.\n");
    return 1;
  }
  if(ob && ob->query_level() > 19) {
    write("Wizards can't be logged.\n");
    return 1;
  }
  write_file("/players/boltar/templar/log/record",extract(ctime(time()),4,15)+extract(ctime(time()),19,24)+" From: "+TP->query_real_name()+" > "+who+" "+type+" "+why+"\n");
  write("Adding "+who+" to the list.\n");
  CRIM->Insert(who, type);
  return 1;
}

read_record() {
  more("/players/boltar/templar/daemon/criminal_record");
  return 1;
}

tail_record() {
tail("/players/boltar/templar/daemon/criminal_record");
return 1;
}
more(str) {
  string tmore;
  string pwd,tilda,blah;
     if(!pwd) pwd="";
    if (!str)
	return 0;
   tmore = str;
   blah = pwd;
   if(extract(blah,0,0)!="/") blah = "/"+blah;
   if(extract(tmore,0,0)=="~") {
     tilda=extract(tmore,1,strlen(tmore));
     tmore = "/players/"+TP->query_real_name()+tilda;
    }
   if(extract(tmore,0,0)!="/") tmore = blah+tmore;
   if(file_size(tmore) < 1) {
       write("That file does not exist.\n");
       return 1;
    }
    more_file = str;
    more_line = 1;
    if (cat(more_file, more_line, CHUNK) == 0) {
	write("No such file\n");
	return 1;
    }
    input_to("even_more");
    write("More: (line " + (CHUNK + 1) + ") ");
    return 1;
}

static even_more(str) {
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
    write("More: (line " + (more_line + CHUNK) + ") ");
    input_to("even_more");
}

tail_file(path)
{
    if (!path)
	return 0;
    if (!tail(path))
	return 0;
    return 1;
}

set_locked(str) { locked = str; }
clear_locked() { locked = 0; }
query_locked() { return locked; }
lock_member(str) {
  object loc,locgo;

  if(!council) return 0;
  if(!str) { write("Who?\n"); return 1; }
  loc = find_player(str);
  if(!loc) {
    write("cannot find "+str+".\n");
    return 1;
  }
  locgo=present("KnightTemplar",loc);
  if(!locgo) {
    write(str+" does not have a cross.\n");
    return 1;
  }
  if(locgo->query_locked()) {
    write(capitalize(str)+" is already suspended.\n");
    return 1;
  }
  locgo->set_locked(this_player()->query_real_name());
  write(str+"'s guild abilities have been suspended.\n");
  tell_object(loc,"Your guild abilities have been suspended by "+
    this_player()->query_name()+"\n");
  write_file("/players/boltar/templar/log/Suspend",ctime(time())+" "+this_player()->query_name()+" suspended "+capitalize(str)+".\n");
  return 1;
}

unlock_member(str) {
  object loc,locgo;

  if(!council) return 0;
  if(!str) { write("Who?\n"); return 1; }
  loc = find_player(str);
  if(!loc) {
    write("cannot find "+str+".\n");
    return 1;
  }
  locgo=present("KnightTemplar",loc);
  if(!locgo) {
    write(str+" does not have a cross.\n");
    return 1;
  }
  if(!locgo->query_locked()) {
    write(capitalize(str)+" is not suspended.\n");
    return 1;
  }
  locgo->clear_locked(this_player()->query_real_name());
  write(str+"'s guild abilities have been restored.\n");
  tell_object(loc,"Your guild abilities have been restored by "+
    this_player()->query_name()+"\n");
  write_file("/players/boltar/templar/log/Suspend",ctime(time())+" "+this_player()->query_name()+" restored "+capitalize(str)+".\n");
  return 1;
}

guild_to_guild(str) {
object env,towho;
string where;
  if(!str) return 0;
  if(TP->query_guild_rank() < 5) { write("You cannot use this ability until Rank 5.\n"); return 1; }
 towho=find_player(str);
 if(!towho) {
   write("No such player.\n");
   return 1;
 }
if(towho->query_level() > 19){
write("That person is a wizard!\n");
return 1;
}
if(!present("KnightInvite", towho)){
   write("That person is not a knight or ally.\n");
   return 1;
 }
   env = environment(TP);
   if(env->realm()=="NT" || environment(towho)->realm()=="NT") {
      write("You cannot teleport to "+str+"\n");
return 1;
   }
   if(!teleport_ok) {
      write("You can't quite remember how to do that.\n");
      write("Maybe it'll come back to you later.\n");
      return 1;
   }
    spell_cost(150);
   if (!spell_ok) {
      write("You find yourself too weak for that spell.\n");
      return 1;
   }
     if(where = call_other("obj/base_tele","teleport")) {
               TP->move_player("with an astonished look#"+where);
        write("Something goes wrong.....\n");
        return 1;
      }
   write("You grasp your cross and concentrate...\n"+
         "Closing your eyes you feel the world shift around you.\n");
   say(TP->query_name()+" phases out of view.\n");
   move_object(TP,environment(towho));
   write("You arrive elsewhere...\n");
   command("look", TP);
   teleport_ok=0;
   call_out("tele_ok",300);
   return 1;
}
add_council(arg) {
  if(!this_player()) return;
  if(this_player()->query_guild_name() != "Knights Templar") return;
  if(this_player()->query_guild_rank() < 10 ) return;
  council += arg;
  return 1;
}
query_council() { return council; }

/* criminal_who rewritten by verte to support locations, et al */

criminal_who() {
   int i, z, crim, verte_desc;
   object *us;
   us = users();
   write(GRN);
   write(pad("",69,'~')+"\n");
   write("@"+NORM+BOLD+"  Name:\tLevel:\tGuild:\t\tLocation:\t\t"+NORM+GRN+"    @\n");
   write(NORM+GRN);
   write("@"+pad("",67,'~')+"@\n\n");
   write(NORM);
   for(i = 0, z = 0; i < sizeof(us); i++) {      
      crim = "/players/boltar/templar/daemon/Criminal"->Query(us[i]->query_real_name());
      if(!environment(us[i]) || us[i]->query_level() > 19 || "/players/boltar/templar/daemon/Ally"->Query(us[i]->query_real_name())) continue;
if(us[i]->query_invis() && us[i]->query_level() >= this_player()->query_level()) continue;
      if(crim || (us[i]->query_level() > 8 && us[i]->query_alignment() < -40)) {
         if(!environment(us[i]) || !environment(us[i])->short()) verte_desc = "Logging In";
         else verte_desc = environment(us[i])->short();
         if(crim)
            if(us[i]->query_attack())
            write(GRN+"  "+BOLD+RED+"*"+pad(us[i]->query_name(),14)+NORM);
         else
            write(GRN+"   "+BOLD+RED+pad(us[i]->query_name(),14)+NORM);
         else 
            if(us[i]->query_attack())
            write(GRN+"  "+NORM+HIR+"*"+NORM+pad(us[i]->query_name(),14));
         else
            write(GRN+"   "+NORM+pad(us[i]->query_name(),14));
         z++;
         if (us[i]->query_pl_k())
            write(us[i]->query_level() + "*\t");
         else
            write(us[i]->query_level() + "\t");
         if (!us[i]->query_guild_name())
            write(pad("None",15));
         else
            write(pad(capitalize(us[i]->query_guild_name()),15));
         if(!us[i]->query_invis() || (us[i]->query_level() <= this_player()->query_level())) write(verte_desc+"\n");
         else write("\n");
       }
   }
   if(!z) write(GRN+"  "+NORM+pad("No Criminals logged in.",36)+"\n");
   write(GRN+"\n");
   write(pad("",69,'@')+"\n");
   write(NORM);
   write(HIR+"Red"+NORM+": criminals  White: Evil players\n");
   return 1;
}

status
criminal(string str) {
  if(!str) return 0;
  if(CRIM->Query(str)) write(CRIM->DetailedQuery(str));
  else write(capitalize(str)+" is not a criminal.\n");
  return 1;
}

status
pardon(string str) {
  string who,why;

  if(!str) return 0;
if(TP->query_guild_rank() < 9) return 0;
  if(sscanf(str,"%s %s",who,why)) {
    write_file("/players/boltar/templar/log/pardon",extract(ctime(time()),4,15)+extract(ctime(time()),19,24)+" From: "+TP->query_real_name()+" > "+who+" "+why+"\n");
    CRIM->Delete(who);
    return 1;
  }
  else {
    write("Usage: pardon <who> <reason>\n");
    return 1;
  }
}

lead(string str){

object lwho;
object aided;
object aided2;
object att1,att2;
if(!elite) return 0;
if(!test_piety(12)) return 1;

spell_cost(12);

if(!str){
  tell_object(environment(),
  "Defend who?\n");  
  return 1;
  }

lwho = find_living(str);
if(!lwho) { tell_object(environment(),"That person is not here.\n"); return 1; }
aided = present(lwho, environment(environment()));

if(!aided){
  tell_object(environment(),
  "That person is not here.\n");
  return 1;
  }
if(aided->query_attack() == this_player()){
write("You can't defend against yourself!\n");
return 1;
}
att1 = aided->query_attack();
att2 = aided->query_alt_attack();

if(!att1){
tell_object(TP,
"That person is not fighting.\n");
return 1;
}
if(att1->query_attack() == this_player()){
write("You are already leading the fight!\n");
return 1;
}   
tell_room(environment(TP),
TP->query_name()+" rushes to intercept "+capitalize(str)+"'s attacker!\n", ({ aided }));

tell_object(aided,
"You fall back as "+TP->query_name()+" valiantly charges to the head of the fight!\n");

TP->attack_object(att1);
att1->attack_object(TP);
if(att2)
att2->attack_object(TP);
if(att2)
att2->attack_object(TP);
if(att2)
att2->attack_object(TP);
return 1;
}

/************************ Bash ****************************************/
/* [ All knights are now able to use Bash, [Jaraxle] */

bash(str) {
   object victim;
   string b1,b2;
   string bash_mess1;
   string bash_mess2;
   int Dam1;
   int gr;
   gr = this_player()->query_guild_rank();
  if(gr < 2) return 0;
   Dam1 = 5+random(26);
   if(KPTS < 51){ Dam1 =- 13; }
   if(sscanf(file_name(environment(TP)),"%stemplar%s",b1,b2) == 2){
   Dam1 += 6;
   }  
   
   if (!test_piety(9)) return 1;
   if(TP->query_spell_dam()) return 1;
   if (str) victim = present(str, environment(TP));
     else {
      victim = TP->query_attack();
      if(victim && !present(victim, environment(TP)))
        victim = 0;
     }
   if(!str && !victim) return 0;
   if(!victim) { write("That is not here.\n"); return 1; }

   if (!living(victim)) {
      write("You cannot attack that!\n");
      say(TP->query_name() + " foolishly tries to attack "+ str+"\n");
      return 1;
   }
   spell_cost(14,1);
   if (!spell_ok) {
      write("You lack the spell/donation points for that spell.\n");
      return 1;
   }
if(!shield_check()){
write("You must have a shield worn to Shield Bash!\n");
return 1;
}   

switch(Dam1){
case 21..100:
bash_mess1 = ""+HIR+"PULVERIZE"+NORM+"";
bash_mess2 = ""+HIR+"PULVERIZES"+NORM+"";
break;
case 17..20:
bash_mess1 = ""+HIR+"SLAM"+NORM+"";
bash_mess2 = ""+HIR+"SLAMS"+NORM+"";
break;
case 10..16:
bash_mess1 = "Strike";
bash_mess2 = "Strikes";
break;
case 5..9:
bash_mess1 = "Hit";
bash_mess2 = "Hits";
break;
case 1..4: 
bash_mess1 = "bruise";
bash_mess2 = "bruises";
break;
default:
bash_mess1 = "miss";
bash_mess2 = "misses";
break;
}
     	
TP->spell_object(victim,"shield bash", Dam1,14,
   "You "+bash_mess1+" "+victim->query_name()+" with a shield bash.\n",
   TP->query_name()+" "+bash_mess2+" you with a Shield bash.\n",
   "");
   return 1;
}
/***************************************************************/

shield_check(){
object inv;
int x;
inv = all_inventory(environment(this_object()));

   for(x = 0; x < sizeof(inv); x++){
     if(inv[x]->query_worn() && inv[x]->query_type() == "shield"){
	return 1;
	}	
      }
  return 0;
 } 

/******************* Quick *************************************/
quick(str) {
   object victim;
   string b1,b2;
   int Dam1;
   int ncost;
   string *mess;
   object user;
   object wep;
   user = environment(this_object());
   wep = user->query_weapon();
   if(!elite) return 0;
   if (!test_piety(15)) return 1;
   if(TP->query_spell_dam()) return 1;
 
   if(TP->query_guild_rank() >= 6){
   Dam1 = random(32) + 14;
   }
   else{
   Dam1 = random(24) + 10;
   }   
   if(KPTS < 51){ Dam1 -= 10; }
   if(sscanf(file_name(environment(TP)),"%stemplar%s",b1,b2) == 2){
   Dam1 += 10;
   }  

   if (str) victim = present(str, environment(TP));
     else {
      victim = TP->query_attack();
      if(victim && !present(victim, environment(TP)))
        victim = 0;
     }
   if(!str && !victim) return 0;
   if(!victim) { write("That is not here.\n"); return 1; }

   if (!living(victim)){
      write("You cannot attack that!");
      say(TP->query_name() + " foolishly tries to attack "+ str+"\n");
      return 1;
   }
   if(!TP->query_weapon()){
     write("You must be wielding a weapon to attack in this style!\n");
     return 1;   
     }
   
   mess = wep->query_message_hit(Dam1 + 1);
   if(TP->query_guild_rank() >= 6){
   spell_cost(30,1);
   ncost = 30;
   }
   else{      
   spell_cost(24,1);
   ncost = 24;
   }
   if (!spell_ok) {
      write("You lack the spell/donation points for that spell.\n");
      return 1;
   }

write(HIR+"  [FAST ATTACK] "+NORM+"\n");
TP->spell_object(victim, "quick attack", Dam1, ncost,
"You "+mess[1]+" "+victim->query_name()+""+mess[0]+".\n",
TP->query_name()+" "+mess[1]+" "+victim->query_name()+""+mess[0]+".\n",
"");
   return 1;
}
/***************************************************************/

/* $ start horse junk added by verte $ */
set_horsed(x)
{
horsed = x;
}

query_horsed()
{
return horsed;
}
/* $ end horse junk added by verte $ */

do_run(x)
{
    if(TP->query_mounted())
    {
      write("You cannot run while on horseback!\n");
      return 1;
    }
}

/************************ Strike ****************************************/
/* [This is to replace Ice, [Jaraxle] */

strike(str) {
  object victim, wep;
   string b1,b2,type;
   string strike_mess1;
   string strike_mess2;
   int Dam1;
   int plus_dam;
   int total_dam;

wep =(object)TP->query_weapon();
if(!wep){
   notify_fail("You must have a weapon wielded to strike!\n");
return 0; }
 plus_dam=((int)TP->query_weapon()->weapon_class()-random((int)TP->query_weapon()->weapon_class()/5));
   Dam1 = random(31);

   
 total_dam = plus_dam+Dam1; 
   
   if(KPTS < 51){ total_dam -= 20; }

   if(sscanf(file_name(environment(TP)),"%stemplar%s",b1,b2) == 2){
   Dam1 += 10;
   }  
   if(elite) return 0;
   
   if (!test_piety(17)) return 1;
   if(TP->query_guild_rank() < 6){ return 0; }
   if(TP->query_spell_dam()) return 1;
   if (str) victim = present(str, environment(TP));
     else {
      victim = TP->query_attack();
      if(victim && !present(victim, environment(TP)))
        victim = 0;
     }
   if(!str && !victim) return 0;
   if(!victim) { write("That is not here.\n"); return 1; }

   if (!living(victim)) {
      write("You cannot attack that!\n");
      say(TP->query_name() + " foolishly tries to attack "+ str+"\n");
      return 1;
   }
   spell_cost(30,1);
   if (!spell_ok) {
      write("You lack the spell/donation points for that spell.\n");
      return 1;
   }


wep = (object)this_player()->query_weapon();
if(wep) type = (string)wep->query_type();
else type = 0;


switch(Dam1){
type = (string)TP->query_weapon()->query_type();

case 20..35:

if(type == "sword"){
strike_mess1 = ""+HIR+"DELAMINATE"+NORM+"";
strike_mess2 = ""+HIR+"DELAMINATES"+NORM+""; }

if(type == "knife"){
strike_mess1 = ""+HIR+"GOUGE"+NORM+"";
strike_mess2 = ""+HIR+"GOUGES"+NORM+""; }

if(type == "axe"){
strike_mess1 = ""+HIR+"OBLITERATE"+NORM+"";
strike_mess2 = ""+HIR+"OBLITERATES"+NORM+""; }

if(type == "bow"){
strike_mess1 = ""+HIR+"DEMOLISH"+NORM+"";
strike_mess2 = ""+HIR+"DEMOLISHES"+NORM+""; }

if(type == "polearm" || type == "club"){
strike_mess1 = ""+HIR+"MASSACRE"+NORM+"";
strike_mess2 = ""+HIR+"MASSACRES"+NORM+""; }

if(!type || type != "sword" || type != "knife" || type != "polearm" || type != "mace" || type != "axe"){
strike_mess1 = ""+HIR+"DESTROY"+NORM+"";
strike_mess2 = ""+HIR+"DESTROYS"+NORM+""; }
break;

case 15..19:

if(type == "sword"){
strike_mess1 = ""+ RED +"Tear"+NORM+"";
strike_mess2 = ""+ RED +"Tears"+NORM+""; }

if(type == "knife"){
strike_mess1 = ""+ RED +"Stab"+NORM+"";
strike_mess2 = ""+ RED +"Stabs"+NORM+""; }

if(type == "axe"){
strike_mess1 = ""+ RED +"Pulverize"+NORM+"";
strike_mess2 = ""+ RED +"Pulverizes"+NORM+""; }

if(type == "bow"){
strike_mess1 = ""+ RED +"Smash"+NORM+"";
strike_mess2 = ""+ RED +"Smashes"+NORM+""; }

if(type == "polearm" || type == "club"){
strike_mess1 = ""+ RED +"Slam"+NORM+"";
strike_mess2 = ""+ RED +"Slams"+NORM+""; }

if(!type || type != "sword" || type != "knife" || type != "polearm" || type != "mace" || type != "axe"){
strike_mess1 = ""+ RED +"Slam"+NORM+"";
strike_mess2 = ""+ RED +"Slams"+NORM+""; }
break;

case 10..14:

if(type == "sword"){
strike_mess1 = ""+HIY+"Slash"+NORM+"";
strike_mess2 = ""+HIY+"Slashes"+NORM+""; }

if(type == "knife"){
strike_mess1 = ""+HIY+"Prod"+NORM+"";
strike_mess2 = ""+HIY+"Prods"+NORM+""; }

if(type == "axe"){
strike_mess1 = ""+HIY+"Hack"+NORM+"";
strike_mess2 = ""+HIY+"Hacks"+NORM+""; }

if(type == "bow"){
strike_mess1 = ""+HIY+"Whack"+NORM+"";
strike_mess2 = ""+HIY+"Whacks"+NORM+""; }

if(type == "polearm" || type == "club"){
strike_mess1 = ""+HIY+"Whack"+NORM+"";
strike_mess2 = ""+HIY+"Whacks"+NORM+""; }

if(!type || type != "sword" || type != "knife" || type != "polearm" || type != "mace" || type != "axe"){
strike_mess1 = ""+HIY+"Bash"+NORM+"";
strike_mess2 = ""+HIY+"Bashes"+NORM+""; }
break;

case 5..9:

if(type == "sword"){
strike_mess1 = ""+HIC+"slice"+NORM+"";
strike_mess2 = ""+HIC+"slices"+NORM+""; }

if(type == "knife"){
strike_mess1 = ""+HIC+"cut"+NORM+"";
strike_mess2 = ""+HIC+"cuts"+NORM+""; }

if(type == "axe"){
strike_mess1 = ""+HIC+"chop"+NORM+"";
strike_mess2 = ""+HIC+"chops"+NORM+""; }

if(type == "bow"){
strike_mess1 = ""+HIC+"scratch"+NORM+"";
strike_mess2 = ""+HIC+"scratches"+NORM+""; }

if(type == "polearm" || type == "club"){
strike_mess1 = ""+HIC+"thrust"+NORM+"";
strike_mess2 = ""+HIC+"thrusts"+NORM+""; }

if(!type || type != "sword" || type != "knife" || type != "polearm" || type != "mace" || type != "axe"){
strike_mess1 = ""+HIC+"club"+NORM+"";
strike_mess2 = ""+HIC+"clubs"+NORM+""; }
break;

case 0..4: 

if(type == "sword"){
strike_mess1 = "scratch";
strike_mess2 = "scratches"; }

if(type == "knife"){
strike_mess1 = "nip";
strike_mess2 = "nips"; }

if(type == "axe"){
strike_mess1 = "nick";
strike_mess2 = "nicks"; }

if(type == "bow"){
strike_mess1 = "prod";
strike_mess2 = "prods"; }

if(type == "polearm" || type == "club"){
strike_mess1 = "jab";
strike_mess2 = "jabs"; }

if(!type || type != "sword" || type != "knife" || type != "polearm" || type != "mace" || type != "axe"){
strike_mess1 = "bop";
strike_mess2 = "bops"; }
break;

}

/*  [ For testing shit, Jaraxle ]
if(wep)
write("type: "+type+".  wep: "+file_name(wep)+". sm1: "+strike_mess1+". sm2: "+strike_mess2+"\n");
else write("wep isn't defined, man.\n");
*/

TP->spell_object(victim,"strike", total_dam,30,
 "With a mighty swing you "+strike_mess1+" "+victim->query_name()+" with a vicious strike!\n",
   TP->query_name()+" "+strike_mess2+" into your flesh with a vicious strike from "+TP->query_possessive()+" weapon!\n",
   TP->query_name()+" "+strike_mess2+" "+victim->query_name()+" with a vicious strike from "+TP->query_possessive()+" weapon!\n");

/*
For testing damage.
write("/t"+HIR+Dam1+NORM+" / "+HIG+plus_dam+NORM+" / "+HIY+total_dam+NORM+"\n");
*/

   return 1;
}
/******************************* RETRIBUTION ***********************************/
retribution_spell() {
object target;
int damage, damage2;
string sm1, sm2, sm3, sm4;
string msg, msg2, msg3;

        if(USER->query_ghost()) return 0;
        if(USER->query_spell_dam()) return 1;
  if(!elite) return 0;
  if(!AT){
     tell_object(USER,"You can only use this while in combat!\n");
     return 1; 
         }
   spell_cost(40,1);
   if (!spell_ok) {
      write("You lack the spell/donation points for that spell.\n");
      return 1;
   }


  damage = 10+random(30); 
  damage2 = 10+random(30);
  if(KPTS < 51){ damage -= 10; damage2 -= 10; }

switch(damage){
case 45..1000:
  sm1 = ""+HIW+"Sealed the DOOM"+NORM+"";
 break;
case 40..44:
  sm1 = ""+HIW+"Shattered"+NORM+"";
  break;
case 33..39:
  sm1 = ""+HIW+"Ingulfed"+NORM+"";
 break;
case 27..32:
  sm1 = ""+HIW+"laid in ashes"+NORM+"";
 break;
case 17..26:
  sm1 = ""+HIW+"blasted"+NORM+"";
 break;
case 10..16:
sm1 = ""+HIW+"dismantled"+NORM+"";
 break;
case 5..9:
sm1 = ""+HIW+"enveloped"+NORM+"";
 break;
case 1..4:
sm1 = ""+HIW+"blinded"+NORM+"";
 break;
default:
sm1 = "missed";
        break;
   }

switch(damage2){
case 45..1000:
 sm3 = ""+HIW+"Sealed the DOOM"+NORM+"";
 break;
case 40..44:
  sm3 = ""+HIW+"Shattered"+NORM+"";
  break;
case 33..39:
  sm3 = ""+HIW+"Ingulfed"+NORM+"";
 break;
case 27..32:
  sm3 = ""+HIW+"laid in ashes"+NORM+"";
 break;
case 17..26:
  sm3 = ""+HIW+"blasted"+NORM+"";
 break;
case 10..16:
sm3 = ""+HIW+"dismantled"+NORM+"";
 break;
case 5..9:
sm3 = ""+HIW+"enveloped"+NORM+"";
 break;
case 1..4:
sm3 = ""+HIW+"blinded"+NORM+"";
 break;
default:
sm3 = "missed";
        break;
   }

switch(random(100)+1){
case 75..1000:
  sm4 = "tsunami of light";
 break;
case 50..74:
  sm4 = "fork of shining light";
  break;
case 25..49:
  sm4 = "wave of goodness";
 break;
case 1..24:
  sm4 = "sweeping arc of light";
 break;
default:
sm4 = "large blast of light";
        break;
   }

switch(random(100)+1){
case 75..1000:
  sm4 = "tsunami of light";
 break;
case 50..74:
  sm4 = "fork of shining light";
  break;
case 25..49:
  sm4 = "wave of goodness";
 break;
case 1..24:
  sm4 = "sweeping arc of light";
 break;
default:
sm4 = "large blast of light";
        break;
   }

tell_object(USER,
""+BOLD+"You grasp your cross, whispering a soft prayer..."+NORM+"\n\n");
tell_object(USER,
""+BOLD+"A blast of light screams from the cross!"+NORM+"\n");
tell_room(environment(USER),
                 USER->query_name()+"grasps "+TP->query_possessive()+" cross, whispering a soft prayer...\n"+
                  "A blast of light screams from "+USER->query_name()+"'s cross!\n", ({USER}));


tell_object(USER,
"You "+sm1+" "+AT->query_name()+" with a "+sm4+".\n");
if(AAT && AAT != AT)
tell_object(USER,
"You "+sm3+" "+AAT->query_name()+" with a "+sm4+".\n");

tell_room(environment(USER),
                  USER->query_name()+" "+sm1+" "+ATT->query_name()+" with a "+sm4+".\n", ({USER}));
if(AAT && AAT != AT)
tell_room(environment(USER),
                  USER->query_name()+" "+sm1+" "+ATT->query_name()+" with a "+sm4+".\n", ({USER}));
if(AAT && AAT != AT)
AAT->hit_player(damage2);

        msg = "";
        msg2 = "";
        msg3 = "";
if(AT)
        USER->spell_object(AT, "holy cone", damage, 40, 
        msg, msg2, msg3);
        return 1;
}

/****************************** WEAPON STUFF *******************/

club_check(dawep){
	if(call_other(dawep,"id", "mace") || call_other(dawep, "id", "club") ||
		call_other(dawep, "id", "flail") || call_other(dawep, "id", "hammer") ||
		call_other(dawep, "id", "morningstar") || call_other(dawep, "id", "staff")){
		return 1;
	}
	return 0;
}

knife_check(dawep){
	if(call_other(dawep,"id", "dagger") || call_other(dawep, "id", "knife")){
		return 1;
	   }
	return 0;
   }

sword_check(dawep){
	if(call_other(dawep, "id", "sword") ||  call_other(dawep, "id", "nodachi") || 
      call_other(dawep, "id", "katana") || call_other(dawep, "id", "blade") ||
		call_other(dawep, "id", "blades") || call_other(dawep, "id", "swords")){
		return 1;
	   }
	return 0;
   }

polearm_check(dawep){
	if(call_other(dawep,"id", "polearm") || call_other(dawep, "id", "halberd") ||
		call_other(dawep, "id", "stick") || call_other(dawep, "id", "pole") ||
		call_other(dawep, "id", "spear") || call_other(dawep, "id", "trident")){
		return 1;
	   }
	return 0;
   }

bow_check(dawep){
	if(call_other(dawep,"id", "bow") || call_other(dawep, "id", "gun")){
		return 1;
	   }
	return 0;
   }

axe_check(dawep){
	if(call_other(dawep,"id", "axe")){
		return 1;
	   }
	return 0;
   }


check_weapon(ob){
	object dawep;
	
	if(!ob){ write("check which weapon?\n"); return 1; }
	dawep = present(ob, USER);
	if(!dawep){ write("You do not see that here!\n"); return 1; }
	
	if(club_check(dawep)){
		write("The weapon is considered a club type.\n");
		return 1;
	}
	
	else if(sword_check(dawep)){
		write("The weapon is considered a sword type.\n");
		return 1;
	}
	
	else if(polearm_check(dawep)){
		write("The weapon is considered a Polearm type.\n");
		return 1;
	}
	
	else if(bow_check(dawep)){
		write("The weapon is considered a Bow type.\n");
		return 1;
	}
	else if(axe_check(dawep)){
		write("The weapon is considered an axe type.\n");
		return 1;
	}
	
	else if(knife_check(dawep)){
		write("The weapon is considered a knife type.\n");
		return 1;
	}
	else{
		write("You are unsure what type it is.\n");
		return 1;
	}
	return 1;
}

fatal(){
	object target, comp;
	int spamount;
	int cost;
	int gr;
	if(USER->query_ghost()) return 0;
   gr = this_player()->query_guild_rank();
   if(gr < 3) return 0;
   if(USER->query_attrib("pie") < 20){
    write("Your piety is too low for such a feat.\n");
    return 1;
    }

	if(!USER->query_attack()){
		tell_object(USER,
		"You can only do this in combat!\n");
		return 1;
	}
   if(!USER->query_weapon()){
      tell_object(USER,
      "You must have a weapon wielded!\n");
      return 1;
      }
	target = USER->query_attack();
	if(!target->query_npc()){
		tell_object(USER,
		"You cannot do this to players!\n");
		return 1;
	}
   if(!living(target)){
      tell_object(USER,
      "That didn't work.\n");
      return 1;
      }
	cost = target->query_hp()/3;
	if(cost > USER->query_sp()){
		tell_object(USER,
		"You are too weak.\n");
		return 1;
	}
	
	if(USER->query_attack() && ATT->query_hp() < 60){
		if((ATT->query_hp()*10)/(ATT->query_mhp()) < 1){
	
tell_object(USER,
GRN+"You find an opening in your opponents defenses"+HIW+"..."+NORM+"\n\n"+
GRN+"                       [  "+HIW+"F   A   T   A   L "+NORM+GRN+" ]\n\n"+
ATT->query_name()+" falls to your might!\n"+NORM);
   		USER->add_spell_point(-cost);
			target->heal_self(-(target->query_hp()));
			target->hit_player(gr * 20);
			return 1;
		}
		tell_object(USER, "Your opponent is still too strong.\n");
		return 1;
	}
	tell_object(USER, "Your opponent is still too strong.\n");
	return 1;
}
holy_ground(){
int gr;
int cost;
   object shadow;
   cost = 50;
   gr = this_player()->query_guild_rank();
   shadow = clone_object("/players/jaraxle/templar/doc/room_shadow.c");
   if(gr < 8) return 0;
   if(USER->query_attrib("pie") < 20){
    write("Your piety is too low for such a feat.\n");
    return 1;
    }
   if(KPTS < 75) return 0;

        if(cost > USER->query_sp()){
                tell_object(USER,
                "You are too weak.\n");
                return 1;
        }
if(present("holy@ground", environment(this_player()))){
write(HIW+"The ground has already been sanctified.\n"+NORM); return 1; }
 if( environment() && environment(environment()) ){
      if(!creator(environment(environment()))){ 
         write("You cannot santify this ground.\n");
         return 1; }
   }
   shadow->start(environment(this_player()));
   write("You kneel to the ground placing one hand upon it, fingers outstretched...\n"+
      "\tYou stretch your other palm out to the area and murmur...\n"+
      "\t\t'Sanctify this ground and may evil fear the aura...'\n");
  say(capitalize(TP->query_name())+" kneels to the ground placing one hand upon it, fingers outstretched...\n"+
      "\t"+capitalize(TP->query_name())+" stretches the other palm out to the area and murmurs...\n"+
      "\t\t'Sanctify this ground and may evil fear the aura...'\n");
                USER->add_spell_point(-cost);
   return 1;
}


protect(str){
  object ob, shad;
int gr;
gr = this_player()->query_guild_rank();
   if(gr < 7) return 0;
   if(USER->query_attrib("pie") < 20){
   write("Your piety is too low for such a feat.\n");
  return 1; }
   if(KPTS < 51){ write("Your honor needs to be higher to use this.\n"); return 1; }
       if(USER->query_sp() < 50){
               tell_object(USER,
               "You are too weak.\n");
               return 1; }
  if(!str) return 0;
  ob=find_player(str);
  if(!ob) return 0;
  if(shield_shadow_target)
  {
    if(shield_shadow_target == ob)
    {
      write("You are already protecting " +
      (string)ob->query_name() + " !\n");
     return 1;
   }
     write("You are already protecting someone.\n");
     return 1;
  }
  if(ob->query_shield_shadowed())
  {
     write(ob->query_name() + " is already protected.\n");
    return 1;
  }
USER->add_spell_point(-50);
  shield_shadow_target=ob;
   shad=clone_object("/players/jaraxle/templar/doc/shield_shadow");
  shad->start(ob, this_player());
write("You stand protectively near " + (string)ob->query_name() + ".\n");
  return 1;
}

unprotect(){
  if(!shield_shadow_target)
  {
    write("You aren't protecting anyone.\n");
    return 1;
  }
  if(!shield_shadow_target->query_shield_shadowed())
  {
write("That person is not protected.\n");
    return 1;
  }
  write("You stop protecting " +
    shield_shadow_target->query_name() + ".\n");
  tell_object(shield_shadow_target,
   this_player()->query_name() + " stops the protection.\n");
  shield_shadow_target->stop();
  shield_shadow_target=0;
  return 1;
}
query_horse() { return horse; }

enchant_it(str) {
   object arm;
   object ob;
   
   if(!elite) return 0;
   if (!str) return 0;
  if(TP->query_guild_rank() < 5) return 0;
  if(USER->query_attrib("pie") < 20){ write("Your piety is too low for such a feat.\n"); return 1; }
if(USER->query_alignment() < 500){ write("You must be more righteous to use this.\n"); return 1; }
       if(USER->query_sp() < 100){
               tell_object(USER,
               "You are too weak.\n");
               return 1; }
if(str != "shield") return 0;
   ob=present(str,this_player());
   if(!ob) ob = present(str,this_object());
   if(!ob) {
      write("You do not have that.\n");
      return 1;
   }
   
   if(!ob->armor_class()){ write("You don't think that is an armor.\n");
return 1; }
   
   if(ob->query_worn()){ 
    write("You must remove the shield before the aura can be cast.\n");
      
      return 1;
   }
  if(ob->query_shadowed()){ write(capitalize(str)+" already has additional properties added.\n"); return 1; }
   
  arm = clone_object("/players/jaraxle/templar/doc/elite_aura.c");
   arm->add_shadow(ob);
   write("You recite the words of the enchantment for an "+str+". . .\n"+
      "A "+HIM+"glowing aura"+NORM+" radiates from the "+str+".\n");
  say(capitalize(USER->query_name())+" recites the words of the Holy Aura for a "+str+". . .\n"+
     "A "+HIM+"glowing aura"+NORM+" begins to radiate from "+USER->query_possessive()+" shield.\n");
USER->add_spell_point(-100);
   return 1;
}

valor(string str){

object lwho;
object aided;
object aided2;
object att1;
object att2;
if(!test_piety(20)) return 1;
if(TP->query_guild_rank() < 6) return 0;

      if(USER->query_sp() < 30){ tell_object(USER, "You are too weak.\n"); return 1; }
if(!str){
tell_object(this_player(),
  "Give valor to who?\n");  
  return 1;
  }
lwho = find_living(str);

if(!lwho) { tell_object(environment(),"That person is not here.\n");
return 1; }

if(present("valor_object",lwho)){
tell_object(environment(),capitalize(str)+" is full of valor at the moment.\n");
return 1; }

if(!present("KnightInvite",lwho)){
tell_object(environment(), "You may only use valor with your brothers, or the Alliance.\n");
return 1; }

aided = present(lwho, environment(environment()));

if(!aided){
  tell_object(environment(),
  "That person is not here.\n");
  return 1;
  }

if(aided == this_player()){
write("You cannot valor yourself!\n");
return 1;
}
 
tell_room(environment(TP),
TP->query_name()+" places "+TP->query_possessive()+" hand on "+capitalize(str)+"'s back.\n"+TP->query_name()+" speaks words of encouragement to "+capitalize(str)+".\n", ({ aided }));

tell_object(aided,
TP->query_name()+" places "+TP->query_possessive()+" hand on your back.\n"+TP->query_name()+" speaks words of encouragement towards you.\n");
move_object(clone_object("/players/jaraxle/templar/items/valor_new.c"),lwho);
USER->add_spell_point(-55);

return 1;
}

add_has_read(hr) {
   if(!has_read) has_read = ({ });
   has_read += ({ hr });
}

remove_has_read(hr) {
   if(!has_read) has_read = ({ });
has_read -= ({hr });
}

query_has_read() { return has_read; }


newscore(){
#define MHP USER->query_mhp()
#define HP USER->query_hp()
#define SP USER->query_sp()
#define MSP USER->query_msp()
#define LEVEL USER->query_level()
#define XLEVEL USER->query_extra_level()
   int intox_level;
   int x, y, z;
int check;
string where, where2, blah;
   string tmp;
   int tmpp, foo, woo;
   int amt;
   
if(XLEVEL < 1)
where = call_other("room/adv_guild","get_next_exp",LEVEL-1);
if(XLEVEL > 0)
where = call_other("room/exlv_guild","get_next_exp",XLEVEL-1);
if(XLEVEL < 1)
where2 = call_other("room/adv_guild","get_next_exp",LEVEL);
if(XLEVEL > 0)
where2 = call_other("room/exlv_guild","get_next_exp",XLEVEL);
if(XLEVEL < 1)
blah = USER->query_exp() - call_other("room/adv_guild","get_next_exp",LEVEL-1);
if(XLEVEL > 0)
blah = USER->query_exp() - call_other("room/exlv_guild","get_next_exp",XLEVEL-1);

if(LEVEL == 19 && XLEVEL < 1){   check = USER->query_exp();   where2 = 2500000;   where = 2000000;   blah = (check-where);   }                      
 amt = ((where2-where)-blah);
if(elite){
if(TP->query_gender() != "female") {
   write(
   "    "+BOLD+"[ "+HIR+"TEMPLAR "+NORM+BOLD+"]"+HIR+"\n"+
   "______       ____\n"+
   "\\__         /  __\n"+
   "/_____"+NORM+BOLD+"LITE  "+NORM+HIR+"\\____|"+NORM+BOLD+"UARDSMAN"+NORM+"\n");
   }

if(TP->query_gender() == "female") {
   write(
   "    "+BOLD+"[ "+HIR+"TEMPLAR "+NORM+BOLD+"]"+HIR+"\n"+
   "______       ____\n"+
   "\\__         /  __\n"+
   "/_____"+NORM+BOLD+"LITE"+ 
   "  "+NORM+HIR+"\\____|"+NORM+BOLD+"UARDSWOMAN"+NORM+"\n");
   }

}

   write("\n");
   write(TP->short()+"\n");
   write("Guild Rank: "+TP->query_guild_rank()+"\t\t\tGuild Exp:  "+TP->query_guild_exp()+"\n");
   write("Level: "+LEVEL);
   if(XLEVEL) write("+"+XLEVEL);
   write("\t\t\tExpierence: "+TP->query_exp()+"\n");
   write("Coins: "+HIY+TP->query_money()+NORM);
 if(blah > (where2-where)){
   write("\t\t\tExp to Advance: None\n"); 
} else {
   write("\t\t\tExp to Advance: "+HIC+amt+NORM+"\n");
}
   write(HIW+"Hit points: "+HIR+HP+"/"+MHP+NORM+"     ");
   write("\t");
   write(HIW+"Spell points: "+HIB+SP+"/"+MSP+NORM+"\n");
   tmpp=TP->query_pregnancy();
   if(tmpp) {
     tmpp=TP->query_age()-tmpp;
     if(tmpp > 4000) write("You are Pregnant ("+tmpp+" / 16200)\n");
   }
   write("\n");
   write("Mag:    "+TP->query_attrib("mag")+"  Sta:    " +TP->query_attrib("sta") + "  Str:    "+TP->query_attrib("str")+"  Ste:    "+TP->query_attrib("ste")+"  Dex:    "+TP->query_attrib("dex")+"\n");
   write("Int:    "+TP->query_attrib("int")+"  Wil:    " +TP->query_attrib("wil") + "  Pie:    "+TP->query_attrib("pie")+"  Luc:    "+TP->query_attrib("luc")+"  Cha:    "+TP->query_attrib("cha")+"\n");
   write("[ "+YEL+"Intox: "+HIY+((TP->query_intoxination()*100)/(LEVEL+3))+NORM+"% ]  " );
   write("[ "+GRN+"Food: "+HIG+((TP->query_stuffed()*100)/(LEVEL*8))+NORM+"% ]  " );
   write("[ "+CYN+"Soak: "+HIC+((TP->query_soaked()*100)/(LEVEL*8))+NORM+"% ]  ");
   write("[ "+MAG+"Infuse: "+HIM+((TP->query_infuse()*100)/(9*LEVEL/2))+NORM+"% ]  ");
   write("\n\n");
   write("\tSword: "+sword+"\tKnife: "+knife+"\tClub: "+club+"\n");
   write("\tAxe: "+axe+"   \tBow: "+bow+"   \tPolearm: "+polearm+"\n");
   write("\tShield: "+shield+"\tHorse: "+horse+"\tDonation: "+donation+"\n");
   TP->show_age();
   if(TP->query_fight_area()) write(HIW+"\t\t[ "+HIR+"You are in a "+HIW+"PK"+HIR+" area "+HIW+"]\n"+NORM);
   write("\n");
   return 1;
}

add_kpts(int i){
if(!i) return;
KPTS += i;
if(KPTS > 100){ KPTS = 100; }
save_ob();
}

remove_kpts(int i){
if(!i) return;
KPTS -= i;
if(KPTS < 0){ KPTS =0; }
save_ob();
}

kill_check(ob) {
  int t_player;
  int this_kill;
  int guild_ob;

this_kill = (int)ob->calculate_evaluated_worth(environment());
t_player = environment(this_object());
guild_ob = present("KnightTemplar",t_player);

if(!this_kill) { return; }

if((int)ob->is_player()){ write("No pentalty/bonus for PK's\n"); return ; }

tell_object(t_player, "Exp for Kill: "+HIW+this_kill+NORM+"\n");
/*
if(!SWORD){ command("sheathe sword",TP); return 1; }
*/

if((int)ob->query_alignment() < 0) { guild_ob->add_kpts(5); }

if((int)ob->query_alignment() > 0) { guild_ob->remove_kpts(25); }

if((int)ob->is_player()){
            sende(HIR+" has slain "+capitalize((int)ob->query_real_name())+"!\n"); }

  save_ob();

/*
tell_object(t_player, ""+KPTS+"\n");
*/

}


cmd_repair(string str){
   string sh;
   object a, b;
   int gr;
   int Cost;

   gr = this_player()->query_guild_rank();

   if(gr >= 6){
   Cost = 500;
   }
   else{
   Cost = 1000;
   }

   if(gr < 3) return 0;
   spell_cost(100);
   if(TP->query_money() < Cost){ write("You do not have the funds.\n"); return 1; }
   if (!spell_ok) {
      write("You lack the energy for that.\n");
      return 1;
   }

   if(!str){
   write("You want to repair what?\n"); 
   return 1;  }

   if(!(a = present(lower_case(str), this_player()))){
   write("You don't have that armor!\n"); 
   return 1; }

   sh = (string)a->short();


   if(!a->armor_breaks()){
   write("That is not broken.\n");
   return 1; }

   a->fix_armor();
   write("You repair "+sh+"\n");
   TP->add_money(-Cost);
   return 1;
}

cmd_pkwho() {
   int i, no, color;
   int crim;
   object *list;

   list = users();
crim = "/players/boltar/templar/daemon/Criminal"->Query(list[i]->query_real_name());

   if(!elite){ return 0; }

   write(HIG+"~"+pad("",68,'~')+"~\n"+NORM);
 write(HIW+"   Name:\tLevel:\t  Guild:\t  Location:\n"+NORM);
      write(GRN+"~"+pad("",68,'~')+"~\n"+NORM);
   for (i = 0, no = 0; i < sizeof(list); i++) {
      if(list[i]->query_invis()) continue;

     if (!(list[i]->query_pl_k() && list[i]->query_level() < 20) &&
            !(environment(list[i]) && list[i]->query_fight_area() &&
 list[i]->query_level() < 20) )
      continue;

      write(++no + ". ");
if(crim) write(RED+"X "+NORM+list[i]->query_name());
else
     write(list[i]->query_name());

      if (no < 10)
         if (strlen(list[i]->query_name()) > 4)
         write("\t");
      else
         write("\t\t");
      else
         if (strlen(list[i]->query_name()) > 3)
         write("\t");
      else
         write("\t\t");

      if (list[i]->query_pl_k())
         write(list[i]->query_level() + HIR+"*\t"+NORM);
      else
   write(list[i]->query_level() + " \t");

      if (!list[i]->query_guild_name())
         write("None\t");
      else {
         write(extract(list[i]->query_guild_name(),0,11));
         write("\t");
        }

/*
      if (list[i]->query_gender() == "male") write("   M\t");
      else if (list[i]->query_gender() == "female") write("   F\t");
      else if (list[i]->query_gender() == "creature") write("   C\t");
*/

      if (!environment(list[i])) write("Logging In");
      else write(colour_pad(environment(list[i])->short(), 40));
     write("\n");
   }
  write("\n"+HIG+"@"+pad("",68,'@')+"@\n"+NORM);
   return 1;
}

cmd_sheathe(string str){
  object ob;
  notify_fail("Sheathe what?\n");
  if(!str) return 0;
  ob=present(str,this_player());
  notify_fail("You do not have that.\n");
  if(!ob) return 0;
  if(!(ob->id("sword")))
  {
    notify_fail("That is not a sword.\n");
    return 0;
  }
  if(SWORD)
  {
    notify_fail("There is already a weapon in your sheath.\n");
    return 0;
  }
  SWORD=ob;
  if((int)SWORD->query_wielded())
  command("unwield "+str,this_player());
  move_object(ob,this_object());
  this_player()->add_weight(-((int)ob->query_weight()));
  local_weight=((int)ob->query_weight() > 3)?3:(int)ob->query_weight();
  this_player()->recalc_carry();
  write("You carefully sheathe your "+(string)ob->short()+".\n");
  say((string)this_player()->query_name()+" sheathes "+(string)ob->short()+".\n");
  return 1;
}

cmd_unsheathe(string str){
object ob;
if(ob = (object)TP->query_weapon() && !TP->query_attack() && SWORD){ write("You have to unwield your current weapon in order to unsheathe.\n"); return 1; }
if(ob = (object)TP->query_weapon() && TP->query_attack()){ return 1; }

  if(!SWORD || (str && !((int)SWORD->id(str))))
  {
    notify_fail("There is no "+str+" in your sheath.\n");
    return 0;
  }
  if(!((int)this_player()->add_weight((int)SWORD->query_weight())))
  {
    notify_fail("That is too heavy for you.\n");
    return 0;
  }
  move_object(SWORD,this_player());
 write("As you unsheathe "+(string)SWORD->short()+" you ready it for battle.\n");
  say((string)this_player()->query_name()+" unsheathes "+(string)SWORD->short()+".\n");
  command("wield "+str,this_player());
  SWORD=0;
  local_weight=1;
  this_player()->recalc_carry();
  return 1;
}

heart_beat(){
object ob;
/*  taken out by verte 8-26-03
::heart_beat();
*/
/*
if(ob = (object)TP->query_weapon() && TP->query_attack() && SWORD){ return; }
else{ command("unsheathe sword",TP); }
if(ob = (object)TP->query_weapon() && !TP->query_attack() && !SWORD){ command("sheathe sword",TP); }
*/
}

query_save_flag() { return 1; }
