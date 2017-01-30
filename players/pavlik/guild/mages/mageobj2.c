#include "/players/pavlik/guild/mages/macs2"
#include "/players/pavlik/guild/mages/spells2/calculate_exp"
#define STAT_MAX 120
#define GUILD_HOME "/players/pavlik/guild/mages/rooms/guild_room5"
#define MAGEWEPS ({"staff","dagger","knife"})

static int failed;
static object castob;
static int CAST;
static int randn;
static int shield;
static object OBJ;
static object alarm;
static int casting;
static int meditate;
static int is_loaded;

/* static: guild stat bonuses */
static int int_bonus, wis_bonus, wil_bonus, pow_bonus;

/* static: guild school bonuses */
static int conj_bonus, ench_bonus, evoc_bonus;
static int illu_bonus, necr_bonus, weap_bonus;

/* guild player stats */
int intelligence, wisdom, will_power, power;

/* guild school stats */
int conjuration, enchantment, evocation;
int illusion, necromancy, weapons;

/* list of the spells we know */
string spells;

/* ability to learn new stuff */
int training_sessions, new_spells;

/* store guild pet stats */
string dragon_stats;
string dragon_descrip;
static object dragon;

/* commands executed at login */
string login_cmds;
static int login_cmds_exec;

/* who have we sponsored for the guild */
string sponsor;

/* vorpal heal numbers */
int vheal_amount;
int vheal_rate;

/* random guild stuffs */
string staff_spells;
int muffled;
int my_exp, divd;
int donation, balance;

/* timers for spells */
int next_heal;
int next_dmg;
int next_prot;
int next_alter;

reset(arg) {
 if(arg)
   return;

casting = 0;
spells = "NO";
divd = 50;
my_exp = 0;
shield = 0;
meditate = 0;
donation = 0;
balance = 0;
dragon_stats = "dragon#1#1#1#1#1";
dragon_descrip = "the#none";
staff_spells = "0#0#0#0#0#0";
sponsor = "0#0+";
login_cmds = 0;
login_cmds_exec = 0;
vheal_amount = 0;
vheal_rate = 0;
call_out("mon", 5);

}

mage_autosave(){
  if(en->query_level()<20) call_other(en, "set_al_title", rancol2("MAGE"));
  if(!spells || spells == "NO"){
	return 1;
  }
  save_object(SAVE_PATH+en->query_real_name());
  return 1;
}

load_data() {
  restore_object(SAVE_PATH+en->query_real_name());
}

set_OBJ(ob){ OBJ = ob; }
query_OBJ(){ return OBJ; }

set_new_spell_list(str){ spells = str; }
learn_spell(str){ spells = spells+"#"+str; return 1; }
query_spells(){ return spells; }

set_alarm(str){ alarm = str; }
query_alarm(){ return alarm; }

set_divd(str){ divd = str; }
query_divd(){ return divd; }

set_muffled(str){ muffled = str; }
query_muffled(){ return muffled; }

/* flag for guild shield spell */
set_shield(i){ shield = i; }
query_shield(){ return shield; }

/* used to track players experience */
set_my_exp(str){ my_exp = str; }
query_my_exp(){ return my_exp; }

/* are we already casting a spell */
set_casting(str){ casting = str; }
query_casting(){ return casting; }

set_sponsor(str){ sponsor = str; }
query_sponsor(){ return sponsor; }
add_sponsor(str){ sponsor += str; }

query_donation(){ return donation; }
add_donation(num){
  donation = donation + num; if(donation >= 48000+random(3000)) PAV->max_donation();
}

/* cmds automaticaly executed on login */
set_login_cmds(str){ login_cmds = str; }
query_login_cmds(){ return login_cmds; }
set_login_cmds_exec(i){ login_cmds_exec = i; }
query_login_cmds_exec(){ return login_cmds_exec; }

query_balance(){ return balance; }
add_balance(bal){ balance = balance + bal; }

/* vorpal heal numbers */
add_vheal_amount(i) { vheal_amount += i; }
query_vheal_amount() { return vheal_amount; }
add_vheal_rate(i) { vheal_rate += i; }
query_vheal_rate() { return vheal_rate; }

/* meditate flag */
set_meditate(i) { meditate = i; }
query_meditate() { return meditate; }

/* spells stored in the mages staff */
set_staff_spells(str){ staff_spells = str; }
query_staff_spells(){ return staff_spells; }

/* stats for the dragon (guild pet) */
set_dragon_stats(str){ dragon_stats = str; }
query_dragon_stats(){ return dragon_stats; }
set_dragon_descrip(str){ dragon_descrip = str; }
query_dragon_descrip(){ return dragon_descrip; }

/* timers for spells that have lapses  */
set_next_heal(i) { int diff; next_heal=i; diff=i-time(); diff *= 3; diff /= 4; next_heal -= diff; }
query_next_heal(){ return next_heal; }
set_next_dmg(i) { int diff; next_dmg=i; diff=i-time(); diff *= 3; diff /= 4; next_dmg -= diff; }
query_next_dmg(){ return next_dmg; }
set_next_prot(i) { int diff; next_prot=i; diff=i-time(); diff *= 3; diff /= 4; next_prot -= diff; }
query_next_prot(){ return next_prot; }
set_next_alter(i) { int diff; next_alter=i; diff=i-time(); diff *= 3; diff /= 4; next_alter -= diff; }
query_next_alter(){ return next_alter; }

/* guild stats used for casting spells, etc */
raise_conjuration(str){
  conjuration += str; if(conjuration > 99) conjuration = 99; }
raise_enchantment(str){
  enchantment += str; if(enchantment > 99) enchantment = 99; }
raise_evocation(str){
  evocation += str;  if(evocation > 99) evocation = 99; }
raise_illusion(str){
  illusion += str; if(illusion > 99) illusion = 99; }
raise_necromancy(str){
  necromancy += str; if(necromancy > 99) necromancy = 99; }

query_conjuration(){ return conjuration; }
query_enchantment(){ return enchantment; }
query_evocation(){ return evocation; }
query_illusion(){ return illusion; }
query_necromancy(){ return necromancy; }
query_weapons(){ return weapons; }

query_total_conj(){ 
  if(conjuration + conj_bonus > STAT_MAX) return STAT_MAX;
  else return conjuration + conj_bonus; }
query_total_ench(){ 
  if(enchantment + ench_bonus > STAT_MAX) return STAT_MAX;
  else return enchantment + ench_bonus; }
query_total_evoc(){ 
  if(evocation + evoc_bonus > STAT_MAX) return STAT_MAX;
  else return evocation + evoc_bonus; }
query_total_illu(){ 
  if(illusion + illu_bonus > STAT_MAX) return STAT_MAX;
  else return illusion + illu_bonus; }
query_total_necr(){ 
  if(necromancy + necr_bonus > STAT_MAX) return STAT_MAX;
  else return necromancy + necr_bonus; }

/* guild attributes */
raise_intelligence(i){
  intelligence += i; if(intelligence > 99) intelligence = 99; }
raise_wisdom(i){
  wisdom += i; if(wisdom > 99) wisdom = 99; }
raise_will_power(i){
  will_power += i; if(will_power > 99) will_power = 99; }
raise_power(i){
  power += i;  if(power > 99) power = 99; }

query_intelligence(){ return intelligence; }
query_wisdom(){ return wisdom; }
query_will_power(){ return will_power; }
query_power(){ return power; }

query_total_int(){ 
  if(intelligence + int_bonus > STAT_MAX) return STAT_MAX;
  else return intelligence + int_bonus; }
query_total_wis(){ 
  if(wisdom + wis_bonus > STAT_MAX) return STAT_MAX;
  else return wisdom + wis_bonus; }
query_total_wil(){
  if(will_power + wil_bonus > STAT_MAX) return STAT_MAX;
  else return will_power + wil_bonus; }
query_total_pow(){ 
  if(power + pow_bonus > STAT_MAX) return STAT_MAX;
  else return power + pow_bonus; }

/* bonuses to guild stats */
add_conj_bonus(i){ conj_bonus += i; }
query_conj_bonus(){ return conj_bonus; }
add_ench_bonus(i){ ench_bonus += i; } 
query_ench_bonus(){ return ench_bonus; }
add_evoc_bonus(i){ evoc_bonus += i; } 
query_evoc_bonus(){ return evoc_bonus; }
add_illu_bonus(i){ illu_bonus += i; } 
query_illu_bonus(){ return illu_bonus; }
add_necr_bonus(i){ necr_bonus += i; } 
query_necr_bonus(){ return necr_bonus; }

/* bonuses to guild stats */
add_int_bonus(i){ int_bonus += i; }
query_int_bonus(){ return int_bonus; }
add_wis_bonus(i){ wis_bonus += i; }
query_wis_bonus(){ return wis_bonus; }
add_wil_bonus(i){ wil_bonus += i; }
query_wil_bonus(){ return wil_bonus; }
add_pow_bonus(i){ pow_bonus += i; }
query_pow_bonus(){ return pow_bonus; }

/* ability to learn new skills */
add_training_sessions(i){ training_sessions += i; }
query_training_sessions(){ return training_sessions; }
add_new_spells(i){ new_spells += i; }
query_new_spells(){ return new_spells; }

#define IDS ({"mageobj","mageobj2","mageobj_OLD","no_spell","spellbook",\
              "guild_object","GI","generic_wc_object",\
              "generic_hp_bonus","generic_sp_bonus",\
              })
              
id(str) {
  if(member_array(str, IDS) > -1) {
	return 1;
  }
  else if(str=="notarmor") {
	object c;
	if((c=caller()) && c->is_armor()) {
		string a;
		if((a=(string)c->query_type()) && (a=="helmet" || a=="shield") &&
		  (!c->id("wiz_hat") && !c->id("mage_belt"))) {
			return 1;
		}
		else if((int)c->query_weight() > 1) {
			return 1;
		}
	}
  }
}

/* this is a guild object, treat accordingly! */
is_gob(){ return 1; }

int gen_wc_bonus() {
  int    bonus;
  object wep;
  
  bonus -= (random(5));		/* general mage deduction */
  
  if(wep=(object)environment()->query_weapon()) {
	int s, found;
	s = sizeof(MAGEWEPS);
	while(s-- && !found) {
		if(wep->id(MAGEWEPS[s]))
		found = 1;
	}
	if(!found)
	bonus -= (random(5));
  }
  return bonus;
}

int gen_hp_bonus() {
  int bonus;
  
  bonus -= (int)environment()->query_level() * 4;
  bonus -= (int)environment()->query_extra_level() * 2;
  
  return bonus;
}

int gen_sp_bonus() {
  int bonus;
  
  bonus += (int)environment()->query_level() * 3;
  bonus += (int)environment()->query_extra_level() * 2;
  
  return bonus;
}
        
int display_notarmor_msg() {
  write(
    "As a mage, you may only wear light armors.\n" +
    "You are also denied the usage of shields and helmets.\n");
  return 1;
}

drop(){ return 1; }
get(){ return 1; }

short(){
  if(tp == environment()) return CYN+"Your magic spellbook [*]"+NORM;
  else return CYN+Me+"'s magic spellbook [*]"+NORM;
}

long(){
  write(
    "The spellbook is the "+MAG+"heart and soul"+NORM+" of a Mage.\n" +
    "This tome presents limitless power and possibilities without boundry.\n" +
    "Your knowledge of the arcane is recorded within the books thick leather\n" +
    "covers which have been careful bound with sigils of privacy and protection.\n" +
    "Type "+CYN+"mhelp"+NORM+" to uncover the books secrets.\n");
  return;
}

init() {

  if(environment() && !is_loaded) {
	is_loaded=1;
	if(environment()->query_level() < 21) {
		environment()->set_guild_file(basename(this_object()));
		environment()->RegisterArmor(this_object(), ({"physical",0,-32,0}));
		call_other(environment(), "set_al_title", rancol2("MAGE"));
		call_other(environment(), "set_home", GUILD_HOME);
	}
  }


/* -= Log Commands =- */
add_action("mage_log_bug", "mbug");
add_action("mage_log_comment", "mlog");

/* -= Basic Commands =- */
add_action("pavlik","mhelp");
add_action("pavlik","mhelp2");
add_action("pavlik","msc");
add_action("pavlik","spells");
add_action("pavlik","spells2");
add_action("pavlik","commands");
add_action("pavlik","gt");
add_action("pavlik","mage");
add_action("pavlik","ge");
add_action("pavlik","gc");
add_action("pavlik","gw");
add_action("pavlik","mw");
add_action("renew","renew");
add_action("pavlik","front");
add_action("pavlik","fixme");
add_action("pavlik","tow");
add_action("pavlik","dlead");
add_action("pavlik","gtitle");
add_action("pavlik","mequip");
add_action("pavlik","lcmds");
add_action("pavlik","lcmds?");
add_action("calculate_exp","calcxp");
if(tp->query_level() < 20) add_action("pavlik","tell");

/* -= Mage Skills =- */
add_action("pavlik","affluence"); /* 1  */
add_action("pavlik","devote");    /* 1  */
add_action("pavlik","study");     /* 4  */
add_action("pavlik","wizhat");    /* 6  */
add_action("pavlik","teach");     /* 11 */
add_action("pavlik","rescue");    /* 12 */
add_action("pavlik","mtitle");    /* 15 */
add_action("pavlik","gdiv");      /* 18 */
add_action("pavlik","reposit");   /* 18 */
add_action("pavlik","redraw");    /* 18 */
add_action("pavlik","relist");    /* 18 */
add_action("pavlik","meditate");  /* 26 */
add_action("pavlik","magestaff"); /* 34 */
add_action("pavlik","sponsor");   /* 40 */

/* -= Level 1 Spells =- */
add_action("pavlik","ffire");
add_action("pavlik","werelite");
add_action("pavlik","orb");
add_action("pavlik","knowal");
add_action("pavlik","mssle");
add_action("pavlik","mark");
add_action("pavlik","emote");
add_action("pavlik",">");
add_action("pavlik","ctouch");
add_action("pavlik","sac");

/* -= Level 2 Spells =- */
add_action("pavlik","userv");
add_action("pavlik","wizeye");
add_action("pavlik","wizeye");
add_action("pavlik","flame");
add_action("pavlik","mbag");
add_action("pavlik","spray");
add_action("pavlik","eshield");
add_action("pavlik","blind");
add_action("pavlik","cure");

/* -= Level 3 Spells =- */
add_action("pavlik","acid");
add_action("pavlik","khirstel");
add_action("pavlik","alarm");
add_action("pavlik","empower");
add_action("pavlik","confuse");
add_action("pavlik","crush");
add_action("pavlik","query");

/* -= Level 4 Spells =- */
add_action("pavlik","sigil");
add_action("pavlik","dragon");
add_action("pavlik","food");
add_action("pavlik","detox");
add_action("pavlik","reveal");
add_action("pavlik","sdagger");
add_action("pavlik","steal");

/* -= Level 5 Spells =- */
add_action("pavlik","fball");
add_action("pavlik","strangle");
add_action("pavlik","bind");
add_action("pavlik","absorb");
add_action("pavlik","pacify");
add_action("pavlik","andead");

/* -= Level 6 Spells =- */
add_action("pavlik","rift");
add_action("pavlik","stoneskin");
add_action("pavlik","blister");
add_action("pavlik","sshift");
add_action("pavlik","resurrect");

/* -= Level 7 Spells =- */
add_action("pavlik","tlp");
add_action("pavlik","enchant");
add_action("pavlik","vheal");
add_action("pavlik","vheal2");
add_action("pavlik","mimage");
add_action("pavlik","curse");

/* -= Guild Commanders =- */
if(PAV->is_gc()) {
add_action("pavlik","ct");
add_action("pavlik","ce");
add_action("pavlik","mfix");
add_action("pavlik","mstat");
add_action("pavlik","mspells");
add_action("pavlik","mcheck");
add_action("pavlik","mrank");
add_action("pavlik","mxp");
add_action("pavlik","mdonation");
add_action("pavlik","mschool");
add_action("pavlik","mbonus");
add_action("pavlik","mexpell");
add_action("pavlik","mteach");
add_action("pavlik","mforget");
add_action("pavlik","mnewspells");
add_action("pavlik","msessions");
add_action("pavlik","mreset");
}
/* -= MISC COMMANDS =- */
add_action("mage_quit","quit");
add_action("learn_spell","lspell");
/* cannot use standard commands */
add_action("no_standard","advance");
add_action("no_standard","raise");
}

pavlik(str){ PAV->pavlik(str); return 1; }
knowit(str){ if(PAV->knowit(str)) return 1; else return 0; }

guild_login() { renew(); }

/* -- RENEW -- */
renew() {

  object obj;
  int estat;

  if(tp->query_level() < 20)
  {
	call_other(tp, "set_al_title", rancol2("MAGE"));
	call_other(tp, "set_home", GUILD_HOME);
  }

  if(spells == "NO") {
	if(tp->query_level() < 20)
	{
		write(HIC);
		cat("/players/pavlik/guild/mages/helps2/news");
		write(NORM);
	}
	PAV->tell_enter();
	write("Loading Mage Stats ... ok\n");
	restore_object(SAVE_PATH+rlname);
	if(weapons < 1) weapons = 1;
	if(divd < 5) divd = 50;
	return 1;
  }

  save_object(SAVE_PATH + rlname);
  write("Saving Mage Stats ...\n");
  obj = clone_object("players/pavlik/guild/mages/mageobj2");
  move_object(obj, tp);
  write("Mage Soul renewed.\n");
  obj->restore_my_stats();
  if(casting) obj->set_casting(1);
  obj->set_login_cmds_exec(login_cmds_exec);
  obj->set_alarm(alarm);
  obj->set_casting(casting);
  obj->add_conj_bonus(conj_bonus);
  obj->add_ench_bonus(ench_bonus);
  obj->add_evoc_bonus(evoc_bonus);
  obj->add_illu_bonus(illu_bonus);
  obj->add_necr_bonus(necr_bonus);
  obj->add_int_bonus(int_bonus);
  obj->add_wis_bonus(wis_bonus);
  obj->add_wil_bonus(wil_bonus);
  obj->add_pow_bonus(pow_bonus);
  obj->set_dragon(dragon);

  destruct(this_object());
  return 1;
}

/* MON */
mon() {
  if(en) {
 if(en->query_level()<20) call_other(en, "set_al_title", rancol2("MAGE"));
    if(vheal_amount > 0) {
      en->heal_self(-vheal_rate);
      vheal_amount -= vheal_rate;
      if(vheal_amount < 1) {
          vheal_amount = 0;
          vheal_rate = 0;
      }
    }
    /* sp_regen with meditatation spell */
    /* we also cannot recover hp's when meditate is in effect */
    if(meditate) {
        if(en->query_attack() ||  en->query_sp()==en->query_msp()) {
          command("meditate", en);
        }
      else {
        en->add_spell_point(5 + random(6 * power/33));
	if(en->query_hp() < meditate) {
	   meditate = en->query_hp();
	   if(meditate < 0) meditate = 0;
	}
        if(en->query_hp() > meditate) {
	   en->add_hit_point(meditate - en->query_hp());
	}
     }
    }
    en->add_spell_point(power/33);
    call_out("mon", 6);
  }
}

/* MAGE QUIT */
mage_quit() {

  if(castob) {
	destruct(castob);
	castob = 0;
  }

  if(casting)
	casting = 0;

  if(!spells || spells == "NO"){
	write("Bug!  No stats are being saved.\n");
  } else {
	save_object(SAVE_PATH+tp->query_real_name());
	write("Saving Mage Stats ... ok.\n");
  }
  PAV->tell_leave();
  destruct(this_object());
}

/* RESTORE MY STATS */
restore_my_stats(){
  restore_object(SAVE_PATH + rlname);
  return 1;
}

/* SAVE MY STATS */
save_my_stats(){
  if(!spells || spells == "NO") return 1;
  save_object(SAVE_PATH + rlname);
  return 1;
}

query_spendable_exp(){
  int base, spend;
  base = ADVANCE->rank_costs(tp->query_guild_rank());
  spend = tp->query_guild_exp() - base;
  return spend;
}

set_castob(ob) {castob=ob;}

manual_clear_casting() {
 string junka,junkb;

 /* make sure we are in mages tower to do this */
 if(sscanf(object_name(environment(this_player())), "%spavlik/guild/mages/room%s",junka,
junkb) != 2) {
  write("You must be within the mages tower to clear your casting.\n");
  return 1;
  }
  casting = 0;
  write("casting cleared.\n");
  return 1;
}

no_standard() { 
  string junka, junkb;
 
  if(sscanf(object_name(env), "%spavlik/guild/mages/room%s", junka, junkb) != 2) { 
    write("You cannot do this here.\n");
    write("You must be in the Mages Tower to do this.\n"); 
    return 1; 
  } 
}

reset_stats() {
  conjuration = 0;   enchantment = 0;   evocation = 0;
  illusion = 0;      necromancy = 0;    intelligence = 0;
  will_power = 0;    wisdom = 0;        power = 0;
  conj_bonus = 0;    ench_bonus = 0;    evoc_bonus = 0;
  illu_bonus = 0;    necr_bonus = 0;    int_bonus = 0;
  wil_bonus = 0;     wis_bonus = 0;     pow_bonus = 0;
}

do_login_cmds()
{
  string c1, c2;
  int cont;

  if(login_cmds_exec > 0)
	return 1;

  login_cmds_exec = 1;

  if(!login_cmds) return 1;

  write(CYN+"Executing login commands: " + login_cmds + "\n"+NORM);

  c2 = login_cmds;
  for(cont=0; cont<5; cont++){
        if(sscanf(c2, "%s,%s", c1, c2)==2)
	{
		write(CYN+"executing: '"+c1+"'\n"+NORM);
                command(c1, tp);
        }
        else
	{
		write(CYN+"executing: '"+c2+"'\n"+NORM);
                command(c2, tp);
		cont = 10;
        }
  }
  write(CYN+"Login command complete.\n"+NORM);
  return 1;
}

mage_log_comment(str)
{
  write_file(COMMENTLOG, "["+ctime()[4..15]+"] "+capitalize(tp->query_real_name())+": "+str+"\n");
  write("Your "+HIY+"comment"+NORM+" has been "+HIY+"logged"+NORM+".\n");
  return 1;
}

mage_log_bug(str)
{
  write_file(BUGLOG,
"["+ctime()[4..15]+"] "+capitalize(tp->query_real_name())+" "+basename(environment(tp))+": "+str+"\n");
  write("Your "+HIR+"bug report"+NORM+" has been "+HIY+"logged"+NORM+".\n");
  return 1;
}

set_dragon(x) { dragon=x; }
query_dragon() { return dragon; }
