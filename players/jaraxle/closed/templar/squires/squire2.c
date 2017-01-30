
/* 
* Squire for Knights Templar
* Adapted from Vertebraker's Skeleton
* that is used with Shardak guild.
* Help w/ coin function provided
* by Plasma. (Fucking sscanf [grumble])
*/

#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster";
#define DAEMON "/players/jaraxle/closed/templar/squires/squire_daemon.c"
#undef DEBUG

static object   owner;              /* the pet's master */
static status   listen;             /* convey catch_tells */
static status   aggr;               /* aggressive (join fight or not) */
static int      hp;                 /* hit_point values */
static int      max_sp;             /* spell_point values */
static int      spell_point;        /* spell_point values */
static int      SPELL_WAIT;         /* Pause time for casting */
static int      follow_me;          /* Follow command toggle */
static int      mon_on;             /* Monitor toggle*/
static int      extraexp, cost;     /* Training cost */
static int      spot, xp;           /* Squire Exp */
static int      s_coins;            /* Squire coin variable */

void
reset(int x)
{
   
   if(x) return;
   
   follow_me = 1;
   mon_on = 0;
   s_coins = 0;
   SPELL_WAIT = 0;
   
   ::reset();
   
   set_race("human");
   set_gender("male");
   set_alt_name("squire");
   set_level(1);
   
   msgin="sprints in";
   msgout = "quickly follows behind";
   
   set_can_kill(1);
   set_dead_ob(this_object());
   
}

initiate_squire(){
   set_level(get_level(xp));
}

long(){ 
   
   write("A Templar Squire.\n");
write(HIW+"'"+HIR+"squire help"+HIW+"'"+NORM+" for commands.\n");
   
   if(this_object()->query_hp() < this_object()->query_mhp()/10) {
      write("Squire is in "+HIR+"very bad shape"+NORM+".\n");
      return;
   }
   
   if(this_object()->query_hp() < this_object()->query_mhp()/5) {
      write("Squire is in "+RED+"bad shape"+NORM+".\n");
      return;
   }
   
   if(this_object()->query_hp() < this_object()->query_mhp()/2) {
      write("Squire is "+BLU+"somewhat hurt"+NORM+".\n");
      return;
   }
   
   if(this_object()->query_hp() < this_object()->query_mhp() - 10) {
      write("Squire is "+CYN+"slightly hurt"+NORM+".\n");
      return;
   }
   else
      write("Squire is in "+GRN+"good shape"+NORM+".\n");
   
}



set_level(int i){ 
   
if(i == 1){ hit_point = 50; max_hp = 50; spell_point = 5; max_sp = 5; } 
else if(i == 2){ hit_point = 60; max_hp = 60; spell_point = 10; max_sp = 10; } 
else if(i == 3){ hit_point = 70; max_hp = 70; spell_point = 15; max_sp = 15; } 
else if(i == 4){ hit_point = 80; max_hp = 80; spell_point = 20; max_sp = 20; } 
else if(i == 5){ hit_point = 90; max_hp = 90; spell_point = 30; max_sp = 30; } 
else if(i == 6){ hit_point = 100; max_hp = 100; spell_point = 45; max_sp = 45; } 
else if(i == 7){ hit_point = 110; max_hp = 110; spell_point = 60; max_sp = 60; } 
else if(i == 8){ hit_point = 120; max_hp = 120; spell_point = 70; max_sp = 70; } 
else if(i == 9){ hit_point = 130; max_hp = 130; spell_point = 80; max_sp = 80; } 
else if(i == 10){ hit_point = 140; max_hp = 140; spell_point = 100; max_sp = 100; } 
 else{ hit_point = 50; max_hp = 50; spell_point = 5; max_sp = 5; }
   
   level = i;
}


get_level(int i){
   
   if(i > 90000) return 10;   
   else if(i > 60000) return 9; 
   else if(i > 40000) return 8;  
   else if(i > 30000) return 7;
   else if(i > 15000) return 6;  
   else if(i > 6000) return 5; 
   else if(i > 3000) return 4;   
   else if(i > 2000) return 3; 
   else if(i >= 1500) return 2;  
   
   else return 1;
   
}


#ifdef DEBUG
   
void
catch_tell(string txt) {
   if (listen && owner) tell_object(owner, "Squire> " + txt);
}

#endif
   
status
monster_died(object me)
{
object death_coins;
  death_coins = clone_object("obj/money");
   say("\The Squire lets out a sharp cry as he falls dead.\n");
  if(s_coins >= 1){
    death_coins->set_money(s_coins);
    move_object(death_coins,environment(this_object()));
  }
   return 0;                   
}


void
set_owner(object o)
{
   owner = o;
}

object
query_the_owner()
{
   return owner;
}


heart_beat()
{
   
   object att, weap;
   
#ifdef DEBUG
      if (root()) {
      att = find_player("jaraxle");
      if (att) tell_object(att, "squire::heart_beat() in root()\n");
   }
   
#endif
      
   if (!(root() || objectp(owner))) {
      say(query_name() + " leaves back to Fortress Stone.\n");
      DAEMON->set_squire_name(spot, name);
      DAEMON->set_squire_xp(spot, xp);
      DAEMON->set_not_taken(spot);
      destruct(this_object());
      return;
   }
   
   if (environment(owner) && !present(owner, environment()) && follow_me != 0) {
      move_player("after " + owner->query_name()+"#"+file_name(environment(owner)));
   }
   
   if (!attacker_ob && !query_attack() &&
         (att = (object) owner->query_attack()) &&
      (weap = query_weapon()) && !att->is_player())
   {
      
      tell_object(att, query_name() + " lets out a cry as he attacks you with his " +
         weap->query_name() + ".\n");
say(query_name() + " follows "+owner->query_name()+" into battle.\n", att);
      attacker_ob = att;
   }
   
   if(owner && mon_on == 1 && this_object()->query_attack()) {
   tell_object(owner, HIC+">>> "+NORM+query_name()+HIC+" "+HIG+this_object()->query_hp()+NORM+" / "+HIG+this_object()->query_mhp()+NORM+" "+HIR+"~"+HIB+"*"+HIR+"~ "+HIM+spell_point+NORM+" / "+HIM+max_sp+NORM+"\n");
   }
   
   if(this_object()->query_attack() && (attacker_ob != owner)){
     xp += 3+random(11);
      if(get_level(xp) > level){ 
         tell_room(environment(), HIR+"Squire levels up!\n"+NORM);
         set_level(get_level(xp)); 
      }
   }
   
   if(!this_object()->query_attack()){
      this_object()->heal_self(random(4));
   }
  if(!this_object()->query_attack() && spell_point < max_sp){
      spell_point +=random(2);
}
   
   ::heart_beat();
   
}


init()
{
   
   if (objectp(owner) && this_player() == owner) {
      add_action("cmd_squire", "squire");
      add_action("cmd_squire", lower_case(query_name()));
   }
   ::init();
}


/* This command is called whenever the Squire
     is unable to follow an order */

void
confused()
{
   write(query_name() + " lowers " + query_possessive() + " head, 'I cannot do that'\n");
}


status
cmd_follow(){
   
   if(follow_me == 1){
      write(query_name()+" is already following close behind.\n"); 
      return 1; }
   
   if(follow_me == 0){
      write(query_name()+" nods, and quickly takes his stand behind you.\n");
      follow_me =1;
      return 1; }
}


cmd_stop_follow(){
   
   if(follow_me == 0){
      write(query_name()+" is already holding his possition.\n"); 
      return 1; }
   
   if(follow_me == 1){
      write(query_name()+" nods, and quickly stands down.\n");
      follow_me =0;
      return 1; }
}

status
cmd_heal(string str){
   int amt;
   
 if(!str){ write("You must tell "+query_name()+" how many sp to use to heal.\n");
return 1; }
 if(sscanf(str, "%d", amt) != 1) { write("You must tell "+query_name()+" how many sp to"+
  " use to heal.\n");
return 1; }
if(amt < 1) { write("You must tell "+query_name()+" how many sp to use to heal.\n");
return 1; }
if(spell_point < amt){ write(query_name()+" can use up to "+HIM+spell_point+NORM+" sp to"+
  " heal.\n"); return 1; }
  this_object()->heal_self(1+random(amt));
 tell_object(owner, query_name()+" uses "+amt+" of sp to heal himself.\n");
   spell_point -=amt;
 return 1; }

status
cmd_shield(){

  if(present("magi@shield", this_object())){ write(query_name()+" already has a defensive field.\n"); return 1; }
  if(spell_point <= 30){ write(query_name()+" needs ["+HIC+"40"+NORM+"] sp to shield himself.\n"); return 1; }
  tell_room(environment(), "With a clap of his hands "+query_name()+" summons a defensive field.\n");
   MOCO("/players/jaraxle/closed/templar/squires/shield.c"), this_object());
   spell_point -=30;
   call_out("stop_shield", 30);
   return 1; }

status
cmd_missile(string str){
   object target;
   if (!str) return 0;
  if(spell_point <= 40){ write(query_name()+" needs ["+HIC+"40"+NORM+"] sp to do this.\n"); return 1; }
  if(SPELL_WAIT >=1){ write(query_name()+" cannot cast another spell yet.\n"); return 1; }
 
   target = present(str, environment(this_object()));
   if (!target || !living(target) || !target->query_npc()) {
     write(query_name()+" does not see that.\n");
      return 1;
   }

   tell_object(owner, query_name()+" fires a magic missile.\n");
  tell_room(environment(), "\t"+query_name()+" casts a magic missile at "+target->query_name()+"!\n");
   this_object()->attack_object(target);
   target->add_hit_point(-1-random(20));
   SPELL_WAIT +=1;
   spell_point -=40;
   call_out("spell_wait", 10);
   return 1;
}

status
cmd_shock(string str){

   object target;
   if (!str) return 0;
   if(spell_point <= 50){ write(query_name()+" needs ["+HIC+"50"+NORM+"] sp to use this.\n"); return 1; }
   if(SPELL_WAIT >=1){ write(query_name()+" cannot cast another spell yet.\n"); return 1; }
 
   target = present(str, environment(this_object()));
   if (!target || !living(target) || !target->query_npc()) {
      write(query_name()+" does not see that.\n");
      return 1;
   }

  tell_object(owner, query_name()+" fires a static shock.\n");
   tell_room(environment(), "\t"+query_name()+" casts a static shock at "+target->query_name()+"!\n");
   this_object()->attack_object(target);
   target->add_hit_point(-1-random(30));
   SPELL_WAIT +=1;
   spell_point -=50;
   call_out("spell_wait", 10);
   return 1;
}

status
cmd_light(){
object light;
if(spell_point <= 5){ write(query_name()+" needs ["+HIC+"5"+NORM+"] sp to cast light.\n"); return 1; }
light = clone_object("obj/torch");
        call_other(light, "set_name", "light");
        call_other(light, "set_short", ""+HIW+"A smal crystal of light"+NORM);
        call_other(light, "set_fuel",200);
        call_other(light, "set_weight", 0);
        call_other(light, "set_value",0);
        call_other(light, "set_out_desc", "Your crystal of light winks out.\n");
      move_object(light,this_object());
        command("light light",this_object());
tell_room(environment(), query_name()+" summons "+HIW+"light"+NORM+"!\n");
   SPELL_WAIT +=1;
   spell_point -=5;
   call_out("spell_wait", 10);
return 1; }

status
cmd_fireball(string str){

   object target;
   if (!str) return 0;
   if(spell_point <= 60){ write(query_name()+" needs ["+HIC+"60"+NORM+"] sp to use this.\n"); return 1; }
   if(SPELL_WAIT >=1){ write(query_name()+" cannot cast another spell yet.\n"); return 1; }
 
   target = present(str, environment(this_object()));
   if (!target || !living(target) || !target->query_npc()) {
      write(query_name()+" does not see that.\n");
      return 1;
   }

  tell_object(owner, query_name()+" fires a fireball.\n");
   tell_room(environment(), "\t"+query_name()+" casts a fireball at "+target->query_name()+"!\n");
   this_object()->attack_object(target);
   target->add_hit_point(-1-random(40));
   SPELL_WAIT +=1;
   spell_point -=60;
   call_out("spell_wait", 10);
   return 1;
}

status
cmd_spells(){
   write(HIB+"-"+NORM+"\n"+

"  Level     "+HIB+"~"+NORM+"     Spell     "+HIB+"~"+NORM+"     Cost     "+HIB+"~"+NORM+"     Comment\n"+
"  All       *     heal      *     ["+HIC+"varies"+NORM+"] *     Squire can heal himself\n"+
"  All       *     light     *     ["+HIC+"5"+NORM+"]      *     Squire casts a light ball\n"+
"  3         *     missile   *     ["+HIC+"15"+NORM+"]     *     Squire casts a magic missile\n"+
"  5         *     shield    *     ["+HIC+"30"+NORM+"]     *     Squire casts a magical field\n"+
"  7         *     shock     *     ["+HIC+"50"+NORM+"]     *     Squire casts a static shock\n"+
"  9         *     fireball  *     ["+HIC+"60"+NORM+"]     *     Squire casts a fireball\n"+
"            "+HIB+"~"+NORM+"               "+HIB+"~"+NORM+"              "+HIB+"~"+NORM+"\n");
   write(HIB+"-\n\n"+NORM);
return 1; }

status
cmd_hold_coins(string str){
   string what, where;
  int newcoins;
   
   if (!str) {
      confused();
      return 0; }
   
   if(sscanf(str,"%d",newcoins) != 1) {
      confused();
      return 0; }

   if(this_player()->query_money() < newcoins){
      confused();
      return 0; }

   if((newcoins + s_coins) > 50000){ 
      confused();
      return 0; }

   if(newcoins < 1){
      confused();
      return 0; }

  tell_object(owner, "You hand your squire "+newcoins+" coins.\n");
  s_coins+=newcoins;
  call_other(this_player(), "add_money", - newcoins);
  return 1;
}
 

status
cmd_give_coins(string str){
 string what, where;
  int newcoins;
   
   if (!str) {
      confused();
      return 0; }

   if(sscanf(str,"%d",newcoins) != 1) {
      confused();
      return 0; }
   
  if(s_coins < newcoins){
      confused();
      return 0; }

   if(newcoins < 1){
      confused(); 
      return 0; }
  
  tell_object(owner, "Your squire hands you "+newcoins+" coins.\n");
  s_coins-= newcoins;
  call_other(this_player(), "add_money",  newcoins);
  return 1; 
}


status
cmd_help()
{
   write(HIB+"-"+NORM+"\n"+
   "Your squire can do the following commands:\n"+
      "Squire wield <weap> "+HIB+":"+NORM+" Allows the squire to wield a weapon.\n"+
      "Squire wear <armor> "+HIB+":"+NORM+" Allows the squire to wear equipment.\n"+
      "Squire mon on/off   "+HIB+":"+NORM+" Toggles the squires combat monitor.\n"+
      "                      (No argument will show current stats.)\n"+
      "Squire follow       "+HIB+":"+NORM+" Squire will follow you.\n"+
      "Squire halt         "+HIB+":"+NORM+" Squire will stop following.\n"+
      "Squire dismissed    "+HIB+":"+NORM+" Return the squire to Fortress Stone.\n"+
    "                      (Squire will drop all, including money\n"+
    "                       onto the floor at dismissal)\n"+
      "Squire chold <#>    "+HIB+":"+NORM+" Give your squire coins to hold.\n"+ 
      "                      (can only hold up to 50000 coins [50k])\n"+
      "Squire cgive <#>    "+HIB+":"+NORM+" Command your squire to give coins.\n"+ 
      "                      (your squire will give coins even if\n"+
      "                       you are at maximum coins)\n"+
       "Squire spells       "+HIB+":"+NORM+" List Squire spells available.\n"+
       "Squire drop         "+HIB+":"+NORM+" Squire will drop something from inventory.\n");
   write(HIB+"-\n\n"+NORM);
   return 1; }


status
cmd_wield(string arg)
{
   
   object weapon;
   string what, where;
   
   if (!stringp(arg)) {
      confused();
      return 0;
   }
   
   if (!sscanf(arg, "%s in %s", what, where)) what = arg;
   
   if (!(weapon = present(what, this_object()))) {
      write(query_name() + " does not have such a weapon.\n");
      return 0;
   }
   
   command("wield " + arg);
   if(!query_weapon()) {
      write(query_name() + " failed to wield it.\n");
      return 0;
   }
   return 1;
}


status
cmd_wear(string what)
{
   
   object armour;
   
   if (!stringp(what)) {
      confused();
      return 0;
   }
   
   if (!(armour = present(what, this_object()))) {
      write(query_name() + " does not have such a piece of armour.\n");
      return 0;
   }
   
   
   if (!command("wear " + what)) {
      write(query_name() + " failed to wear it.\n");
      return 0;
   }
   return 1;
}


status
cmd_mon(string str){
   
   if(str == "on"){
     write("Squire combat monitor "+HIR+"on\n"+NORM); 
     mon_on = 1;
     return 1; }
   
   if(str == "off"){
     write("Squire combat monitor "+HIB+"off\n"+NORM); 
     mon_on = 0;
     return 1; }
   
   if(!str){
      tell_object(owner, HIC+" >>>> "+NORM+query_name()+HIC+"\n"+
           " >>>> "+NORM+"Level:"+BOLD+BLK+"["+HIC+this_object()->query_level()+BOLD+BLK+"]\n"+
           HIC+" >>>> "+NORM+"HP:"+BOLD+BLK+"   ["+HIC+this_object()->query_hp()+NORM+BOLD+BLK+""+
           "/"+HIC+this_object()->query_mhp()+BOLD+BLK+"]\n"+
           HIC+" >>>> "+NORM+"SP: "+BOLD+BLK+"  ["+HIC+spell_point+NORM+BOLD+BLK+""+
          "/"+HIC+max_sp+BOLD+BLK+"]\n"+
           HIC+" >>>> "+NORM+"Exp:"+BOLD+BLK+"  ["+HIC+xp+BOLD+BLK+"]"+NORM+"\n"+
           HIC+" >>>> "+NORM+"Coins:"+BOLD+BLK+"["+HIC+s_coins+BOLD+BLK+"]"+NORM+"\n");
     return 1; }
}


status
cmd_drop(string str)
{
   
   object ob;
   
   if (!stringp(str)) {
      confused();
      return 0;
   }
   
   if (!(ob = present(str, this_object()))) {
      write(query_name() + " does not have such a thing.\n");
      return 0;
   }
   
   if((status)ob->drop()) return (write(query_name() + " can't drop that!\n"), 0);
   move_object(ob, environment());
   if(ob)
      this_object()->add_weight(-((int)ob->query_weight()));
   say(query_name() + " drops " + str + ".\n");
   return 1;
}


status
cmd_dismiss(){
   object dismiss_coins;
   dismiss_coins = clone_object("obj/money");
   if(xp > 120000){
      write(query_name() + " says, 'Thank you for the fine training I have received.'\n"+
         "\t\tI shall now return to Fortress Stone, a Knight Templar.'\n");
         destruct(this_object());
         return 1; }

     
   if(s_coins >= 1){
     write(query_name()+" drops "+s_coins+" coins on the ground.\n");
     dismiss_coins->set_money(s_coins);
     move_object(dismiss_coins,environment(this_object()));
}

   DAEMON->set_squire_name(spot, name);
   DAEMON->set_squire_xp(spot, xp);
   DAEMON->set_not_taken(spot);
   write("The squire nods then heads back to Fortress Stone.\n");
   destruct(this_object());
   return 1; }


status
cmd_squire(string str)
{
   
   string cmd, arg;
   
   if(!str) return 0;
   cmd = str;
   sscanf(str, "%s %s", cmd, arg);
   
   listen = 1;
   switch (cmd) {
      
      case "wield":
      cmd_wield(arg);
      break;
      
      case "heal":
      cmd_heal(arg);
      break;

      case "dismissed":
      cmd_dismiss();
      break;
      
      case "mon":
      cmd_mon(arg);
      break;
      
      case "missile":
      cmd_missile(arg);
      break;

      case "shock":
      cmd_shock(arg);
      break;

      case "fireball":
      cmd_fireball(arg);
      break;

      case "spells":
      cmd_spells();
      break;

     case "shield":
     cmd_shield();
     break;

      case "light":
      cmd_light();
      break;

      case "unwield":
      command(str);
      break;
      
      case "wear":
      cmd_wear(arg);
      break;
      
      case "drop":
      cmd_drop(arg);
      break;
      
      case "halt":
      cmd_stop_follow();
      break;
      
      case "follow":
      cmd_follow();
      break;
      
      case "awake":
      attacker_ob = 0;
      set_heart_beat(1);
      break;
      
      case "help":
      cmd_help();
      break;
      
      case "chold":
     cmd_hold_coins(arg);
      break;

      case "cgive":
     cmd_give_coins(arg);
      break;

      default:
#ifdef DEBUG
#ifdef __VERSION__
         printf("weapon: %O\n", query_weapon());
#endif
#endif
         confused();
      break;
   }
   listen = 0;
   return 1;
}


id(str) { return (::id(str) || str == "templar_squire"); }

set_spot(int i){ spot = i; }

set_xp(int i){ xp = i; }

      /* The following it so Squires lvl 6-10 will take side attacks, */
      /* Hoth monster will not like them too much, and anything that  */
      /* affects "pets" will have effect on them.                     */

/*
is_pet(){
   if(hit_point > 99)
   return 1;
   return 0;
}
*/

stop_shield(){
   object shield;
   shield = present("magi@shield",this_object());
   destruct(shield);
   tell_object(owner, "The "+HIM+"defensive field"+NORM+" dissipates from your Squire.\n");
   remove_call_out("stop_shield");
   return 1; }


spell_wait(){
   SPELL_WAIT -=1;
  tell_object(owner, query_name()+" is ready to cast another spell.\n");
   remove_call_out("spell_wait");
return 1; }

