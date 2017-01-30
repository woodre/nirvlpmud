#include "defs.h"

status kspeech_off; /* wiz only variable */

mixed  *spell_profs;
mixed  *skill_profs;
mixed  *power_profs;
status gc;
status knighted;
string code;
string combat_mode;
string emblem;
int donation;
int maxed_striking;
int max_rage;
int skill_pts_spent;

static status restored;
static int striking;
static status flourished;
static int    extra_wc;
static int    this_round;
static int rage;
static object striked;
static int done;
static int total_skill_pts;
static object shadow;

void load_cmds(string path);
void save_me();
void subtract_donation(int x);
void process_hit();
void add_rage(int x);
void clear_rage();


void reset(int x){
  if(x || root()) return;
  set_heart_beat(1);
}

int id(string str){
  return (str == "knight_object" || str == "guild_object" ||
          str == "gob" || str == "coat of arms" ||
          str == "coat" || str == "generic_wc_bonus" ||
          str == "player_attack_object" || 
          str == (shadow && shadow->query_knight_halo() ? "halo" : "fdjhf"));
}

string short() {
  string sh;
  sh = "a Knight's Coat of Arms ["+emblem+"]"+
   (flourished ? " (flourished)" : "");
  if(this_player() && environment() &&
      environment()->query_knight_halo()){
    sh += ".\nA "+HIW+"heavenly halo"+NORM+" floats above "+
    (environment()==this_player()?"your":possessive(environment()))
    +" head";
  }
  return sh; 
}

void set_halo_light(int x){
  set_light(1);
}

void long(string str){
  if(str=="halo"){
    write("A brilliant white halo floats above your head.\n");
  }
  else {
  }
}

string query_auto_load() {
  return "/players/x/guilds/knights/gob:0";
}

void remove_object(){
  save_me();
}

void init_arg(string x){
  call_out("make_em_update", 1);
  if((int)this_player()->query_level() < 21) {
    tell_object(this_player(),
    "\n\tWelcome, Knight of Nirvana.\n\n");
  }
}

void make_em_update(){
  command("kupdate", environment());
}

int get() { return 1; }
int drop() { return 1; }

void display_critical(){
  object e, ee;
  
  tell_object((e=environment()),
    "You land a "+HIR+"CRITICAL HIT"+NORM+"!\n");
  if(ee = environment(e)){
    tell_room(ee,
      (string)e->query_name()+" lands a "+
      HIR+"CRITICAL HIT"+NORM+"!\n", ({e}));
  }
}

int gen_wc_bonus(){
  int total, qal;
  object atk;
  total = this_round;
  this_round = 0;
  if(combat_mode == "parry"){
    int wt;
    wt = (int)environment()->query_wc();
    wt *= 650; wt /= 1000;
    this_round -= wt;
  }
  if((atk=(object)environment()->query_attack()) &&
     (qal = (int)atk->query_alignment()) > 0){
    total -= (1 + (qal / 100));
  }  
  if(total && environment()->is_testchar()){
    write("Adding "+total+" wc.\n");
  }
  return total;
}

void add_critical(){
  this_round += 10;
  display_critical();
}

void process_hit(){
  object wep;

  if(wep = (object)environment()->query_weapon()){
    wep->hit((object)environment()->query_attack());
  }

  environment()->toggle_already_fight(1);
  environment()->attack();
}
  
varargs void extra_hit(int x, int critical){
  if(!environment()->query_attack()){
    return;
  }
  while(x--){
    if(critical || !random(2)){
      add_critical();
    }
    process_hit();
  }
}

void player_attack(){
  object att;
  object env;
  if(!environment()) {
    return;
  }
  env = environment(environment());
  if(!env)
    return;
  if(environment()->is_testchar()){
    tell_object(environment(),
      HIR+"---"+NORM+
      "begin knight attack"+
      HIR+"---\n"+NORM);
  }
  if((att = (object)environment()->query_attack()) &&
     present(att, env)){
    int att_al;
    if((att_al = (int)att->query_alignment()) > 0){
      if(!random(8)){
        tell_object(environment(),
          "You feel your audience with the Gods waning.\n");
      } 
      subtract_donation(1 + att_al / 3);
    }
    if(knighted){
      if(striking) {
        if(striked != att){
          if(striked){
            tell_object(environment(),
            "\tYou are no longer striking "+
            (string)striked->query_name()+".\n");
            striked = 0;
            striking = 0;
          }
        }
        else if(++ striking == maxed_striking){
          tell_object(environment(),
            "\tYou penetrate "+(string)att->query_name()
           +"'s defenses!\n");
          tell_room(env,
            (string)environment()->query_name()+
           " penetrates "+(string)att->query_name()
          +"'s defenses!\n", ({ att }));
          tell_object(att,
            (string)environment()->query_name()+
          " penetrates your defenses!\n");
          extra_hit(1, 1);
          striking = 0;
        }
      }
      extra_hit(1);
      if(!random(2)){
        add_critical();
      }
    }
  }
  if(environment()->is_testchar()){
    tell_object(environment(),
      HIR+"---"+NORM+
      "end knight attack"+
      HIR+"---\n"+NORM);
  }
}

void heart_beat(){
  object att;
  object env;
  if(!environment()) {
    return;
  }
  env = environment(environment());
  if(!env)
    return;
  done = 0;
  /* if not in combat */
  if(!(att = (object)environment()->query_attack())){
    clear_rage();
  }
}
    

void restore_me(){
  restore_object(SAVE+(string)environment()->query_real_name());
}

void init(){
  
  if(!environment()){
    return;
  }

  if(!CHANNEL->is_people(environment())){
    CHANNEL->add_people(environment());
  }
  
  if(!restored){
    restore_me();
    restored = 1;

    if(!emblem){
      emblem = HIY+"-|--"+NORM;
    }
    if(!combat_mode) {
      combat_mode = "parry";
    }
    if(!maxed_striking) {
      maxed_striking = 11;
    }
    
    if(!shadow){
      if(environment()->knight_shadowed()){
        environment()->end_knight_shadow();
      }
      shadow = clone_object("/players/x/guilds/knights/obj/player_shadow");
      shadow->start_knight_shadow(environment());
    }
    
    total_skill_pts = 1000;
    
    environment()->RegisterArmor(this_object(),
      ({"physical", 0,0, "knight_hit"}));
  }

  add_action("cmd_say"); add_xverb("'");
  load_cmds(CMDS);
  load_cmds(SPELLS);
  load_cmds(POWERS);
  load_cmds(EMOTES);
  
  if((int)environment()->query_level() >= 21) {
    load_cmds(WIZ);
  }
  
  if(gc) {
    load_cmds(GC);
  }
}

int knight_hit(object owner){
  object att, env;
  int    return_val; 
  if(!owner || !(env = environment(owner)))
    return 0;
  if((att=(object)owner->query_current_attacker()) &&
     present(att, env) && living(att)){
    object wep;
    if(knighted){
      if(rage == 9){
        tell_object(environment(),
          HIR+"You become enraged!\n"+NORM);
        tell_room(env, HIR+
          (string)environment()->query_name()
          +" becomes enraged!\n"+NORM,
          ({ owner }));
      }
      else if(rage == 19 || rage == 29 ||
              rage == 39 || rage == 49){
        tell_object(environment(),
          HIR+"Your rage increases!\n"+NORM);
        tell_room(env, HIR+
          (string)environment()->query_name()
          +"'s rage increases!\n"+NORM,
          ({ owner }));
      }
      add_rage(1);
      if(environment()->is_testchar()){
        tell_object(environment(),
        "Rage: "+rage+"\n");
      }
      if(rage == max_rage){
        tell_object(environment(),
          RED+"You are quaking with anger.\n"+NORM);
      } 
    }
    
    if(combat_mode == "parry" &&
       (wep=(object)environment()->query_weapon())){
      string implement, msg, nsg, osg, att_wep_name;
      object ob, oc, att_wep;
      status is_shield;
      
      ob = first_inventory(environment());
      while(ob && !implement){
        oc = next_inventory(ob);
        if(ob->is_armor() && (string)ob->query_type()=="shield" &&
           ob->query_worn()){
          implement = (string)ob->query_name();
          is_shield = 1;
        }
        ob = oc;
      }
      if(!is_shield){
        implement = (string)wep->query_name();
      }
      if(!(att_wep = (object)att->query_weapon())){
        att_wep_name = "attack";
      }
      else {
        att_wep_name = (string)att_wep->query_name();
      }
      
      switch(random(8)){
        case 0:
          msg = "You anticipate "+(string)att->query_name()
               +"'s "+att_wep_name+" and deflect "+objective(att)
               +" with your "+implement+".\n";
          nsg = (string)environment()->query_name()+
              " anticipates "+(string)att->query_name()
             +"'s "+att_wep_name+" and deflects "+objective(att)
            +" with "+possessive(environment())+" "+implement
            +".\n";
          osg = (string)environment()->query_name()+
            " anticipates your "+att_wep_name+" and deflects you "
            +"with "+possessive(environment())+" "+implement
            +".\n";
          break;
        case 1:
          msg = "You avoid "+(string)att->query_name()
               +"'s "+att_wep_name+" with a swift parry from "+
               "your "+implement+".\n";
          nsg = (string)environment()->query_name()+
               " avoids "+(string)att->query_name()+
               "'s "+att_wep_name+" with a swift parry"+
               " from "+possessive(environment())+" implement.\n";
          osg = (string)environment()->query_name()+
               " avoids your "+att_wep_name+" with a swift parry"+
               " from "+possessive(environment())+" "+implement
               +".\n";
          break;
        case 2:
          msg = "You fend off "+(string)att->query_name()
               +"'s "+att_wep_name+" with a quick riposte.\n";
          nsg = (string)environment()->query_name()+
               " fends off "+(string)att->query_name()+
               "'s "+att_wep_name+" with a quick riposte.\n";
          osg = (string)environment()->query_name()+
               " fends off your "+att_wep_name
               +" with a quick riposte.\n";
          break;
        case 3:
          msg = "You lean into "+(string)att->query_name()
              +" and repel "+possessive(att)+" "+
              att_wep_name+"!\n";
          nsg = (string)environment()->query_name()+
              " leans into "+(string)att->query_name()
              +" and repels "+possessive(att)+" "+
              att_wep_name+"!\n";
          osg = (string)environment()->query_name()+
              "leans into you and repels your "+
              att_wep_name+"!\n";
          break;
        case 4:
          msg = "You rebuke "+(string)att->query_name()+
                "'s "+att_wep_name+" with a deft block "+
                "from your "+implement+".\n";
          nsg = (string)environment()->query_name()
               +" rebukes "+(string)att->query_name()+
               "'s "+att_wep_name+" with a deft block "+
               "from "+possessive(environment())+" "+
               implement+".\n";
          osg = (string)environment()->query_name()
               +" rebukes your "+att_wep_name
               +" with a deft block from "+
               possessive(environment())+" "+implement+".\n";
          break;
        case 5:
          msg = "You answer "+(string)att->query_name()+
                "'s incoming "+att_wep_name
               +" with defensive retaliation from your "+
               implement+".\n";
          nsg = (string)environment()->query_name()
               +" answers "+(string)att->query_name()
              +"'s incoming "+att_wep_name
              +" with defensive retaliation from "
              + possessive(environment())
              +" "+implement+".\n";
          osg = (string)environment()->query_name()
               +" answers your incoming "+att_wep_name
               +" with defensive retaliation from "
               +possessive(environment())
               +" "+implement+".\n";
          break;
        case 6:
          msg = "You meet "+(string)att->query_name()
               +"'s "+att_wep_name
               +" with a loud CLANG from your "+
               implement+".\n";
          nsg = (string)environment()->query_name()
               +" meets "+(string)att->query_name()
               +"'s "+att_wep_name
               +" with a loud CLANG from "
               +possessive(environment())
               +" "+implement+".\n";
          osg = (string)environment()->query_name()
               +" meets your "+att_wep_name
               +" with a loud CLANG from "
               +possessive(environment())
               +" "+implement+".\n";
          break;
        case 7:
          msg = "You counter "+(string)att->query_name()
               +"'s "+att_wep_name+" with your "+
               implement+" in a CRASH OF "+HIK
               +"METAL"+NORM+".\n"+
               HIY+"Sparks"+NORM+" fly everywhere!\n";
          nsg = (string)environment()->query_name()
               +" counters "+(string)att->query_name()
               +"'s "+att_wep_name+" with "
               +possessive(environment())+" "+implement
               +" in a CRASH of "+HIK+"METAL"+NORM+".\n"+
               HIY+"Sparks"+NORM+" fly everywhere!\n";
          osg = (string)environment()->query_name()
               +" counters your "+att_wep_name+
               " with "+possessive(environment())
               +" "+implement+" in a CRASH of "+
               HIK+"METAL"+NORM+".\n"+
               HIY+"Sparks"+NORM+" fly everywhere!\n";
          break;
      }
      tell_object(environment(), 
        (string)"/players/x/fc"->format_colour(msg, 65));
      tell_room(env, 
        (string)"/players/x/fc"->format_colour(nsg, 65), ({environment(),att}));
      tell_object(att, 
        (string)"/players/x/fc"->format_colour(osg, 65));  
           
      return_val += 3500;
      if(is_shield) {
        return_val += 1500;
      }
    }
    if(flourished){
      if(!random(8)){
        string shd;
        shd = "Coat of Arms ["+emblem+"]";
        tell_object(environment(),
          "Your "+shd+" billows around you.\n");
        tell_room(env,
         (string)environment()->query_name()
         +"'s "+shd+" billows around "
         +objective(environment())+".\n", ({environment()}));
      }
      return_val += 1;
    }
  }
  if(rage){
    return_val -= (rage * 100);
  }
  if(environment()->is_testchar()){
    tell_object(environment(),
      "Resisting: "+return_val/100+"%\n");
  }
  return return_val;
}

void save_me() {
  save_object(SAVE+(string)environment()->query_real_name());
}

void load_cmds(string path){
  int s;
  string *files;
  
  s = sizeof(files = get_dir(path));
  
  while(s--)
  {
    if(sscanf(files[s], "_%s.c", files[s])) {
      add_action("cmd_hook", files[s]);
    }
  }
}

int cmd_hook(string arg){
  string action, path;
  
  action = query_verb();
  
  if(file_size(path=(CMDS+"_"+action+".c")) > 0) {
    return (int)path->main(arg);
  }  
  if(file_size(path=(SPELLS+"_"+action+".c")) > 0) {
    return (int)path->main(arg);
  }
  if(file_size(path=(POWERS+"_"+action+".c")) > 0) {
    return (int)path->main(arg);
  }
  if(file_size(path=(EMOTES+"_"+action+".c")) > 0) {
    return (int)path->main(arg);
  }
  if((int)environment()->query_level() >= 21) {
    if(file_size(path=(WIZ+"_"+action+".c")) > 0) {
      return (int)path->main(arg);
    }
  }
  if(gc) {
    if(file_size(path=(GC+"_"+action+".c")) > 0) {
      return (int)path->main(arg);
    }
  }
}

mixed * query_skill_profs(){
  return skill_profs;
}

int query_skill_prof(string sk){
  int i,c;
  if(sscanf(sk,"%d",c) || (i=member_array(sk,skill_profs)) == -1)
    return -1;
  else {
    return skill_profs[i+1];
  }
}

int add_skill_prof(string sk, int value) {
  int i;
  if((i=member_array(sk,skill_profs))== -1) {
    skill_profs += ({ sk, value });
    return value;
  }
  else {
    skill_profs[i+1] += value;
    if(skill_profs[i+1] > 100)
    {
      skill_profs[i+1] = 100;
    }
    return skill_profs[i+1];
  }
}

mixed * query_spell_profs(){
  return spell_profs;
}

int query_spell_prof(string sk){
  int i,c;
  if(sscanf(sk,"%d",c) || (i=member_array(sk,spell_profs)) == -1)
    return -1;
  else {
    return spell_profs[i+1];
  }
}

int add_spell_prof(string sk, int value) {
  int i;
  if((i=member_array(sk,spell_profs))== -1) {
    spell_profs += ({ sk, value });
    return value;
  }
  else {
    spell_profs[i+1] += value;
    if(spell_profs[i+1] > 100)
    {
      spell_profs[i+1] = 100;
    }
    return spell_profs[i+1];
  }
}

mixed * query_power_profs(){
  return power_profs;
}

int query_power_prof(string sk){
  int i,c;
  if(sscanf(sk,"%d",c) || (i=member_array(sk,power_profs)) == -1)
    return -1;
  else {
    return power_profs[i+1];
  }
}

int add_power_prof(string sk, int value) {
  int i;
  if((i=member_array(sk,power_profs))== -1) {
    power_profs += ({ sk, value });
    return value;
  }
  else {
    power_profs[i+1] += value;
    if(power_profs[i+1] > 100)
    {
      power_profs[i+1] = 100;
    }
    return power_profs[i+1];
  }
}

int cmd_say(string str){
  return (int)"/players/x/guilds/knights/cmds/_say"->main(str);
}

void set_kspeech(int x){
  kspeech_off = x;
  save_me();
}

int kspeech_off() {
  return kspeech_off;
}

void set_code(string c){
  code = c;
}

string query_code(){
  return code;
}

void set_combat_mode(string c){
  combat_mode = c;
}

string query_combat_mode(){
  return combat_mode;
}

void set_emblem(string e){
  emblem = e;
}

string query_emblem(){
  return emblem;
}

void add_donation(int x){
  donation += x;
}

int query_donation(){
  return donation;
}

void subtract_donation(int x){
  donation -= x;
  if(donation < 0)
    donation = 0;
}

void set_flourished (int x){
  flourished=x;
}

status query_flourished(){
  return flourished;
}

void set_knighted(int x){
  knighted = x;
}

status query_knighted(){
  return knighted;
}

int query_rage(){
  return rage;
}

void add_rage(int x){
  rage += x;
  if(rage > max_rage) {
    rage = max_rage;
  }
}

void clear_rage(){
  if(rage >= 10){
    object env;
    tell_object(environment(),
      HIK+"Your rage subsides.\n"+NORM);
    if(env=environment(environment())){
      tell_room(env,
      HIK+(string)environment()->query_name()
      +"'s rage subsides.\n"+NORM, ({environment()}));
    }
  }
  rage = 0;
}

void set_striking(int x, object strike_obj){
  striking = x;
  striked  = strike_obj;
}

int query_striking(){
  return striking;
}

void add_maxed_striking(int x){
  maxed_striking += x;
}

int query_maxed_striking(){
  return maxed_striking;
}

object query_striked(){
  return striked;
}

int query_max_rage(){
  return max_rage;
}

void add_max_rage(int x){
  max_rage += x;
}

void set_max_rage(int x){
  max_rage = x;
}

void set_done(int x){
  done = x;
}

int query_done(){
  return done;
}

void add_skill_pts_spent(int x){
  skill_pts_spent += x;
}

int query_skill_pts_spent(){
  return skill_pts_spent;
}

int query_total_skill_pts(){
  return total_skill_pts;
}