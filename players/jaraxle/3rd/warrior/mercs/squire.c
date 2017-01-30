
/* 
* Mercenary for Hire
* Bled from Squire code I did for
* Knights Templar.
*/

#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster";
#define DAEMON "/players/jaraxle/3rd/warrior/mercs/merc_daemon.c"
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
static int      extraexp, cost, ARROWS;     /* Training cost */
static int      spot, xp;           /* Mercenary Exp */
static int      s_coins;            /* Mercenary coin variable */

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
   set_gender("female");
   set_alt_name("mercenary");
   set_level(1);
   move_object(clone_object("/players/jaraxle/3rd/warrior/mercs/bow.c"),TO);

   msgin="walks in";
   msgout = "quickly follows behind";
   
   set_can_kill(1);
   set_dead_ob(this_object());
   
}

initiate_mercenary(){
   set_level(get_level(xp));
}

long(){ 
   
   write("A hired Mercenary of the Warrior Maidens.\n");
   write("Type "+HIW+"'"+HIR+"mercenary help"+HIW+"'"+NORM+" for commands.\n");
   write("She has ["+ARROWS+"] arrows in her quiver.\n");
   if(this_object()->query_hp() < this_object()->query_mhp()/10) {
      write("Mercenary is in "+HIR+"very bad shape"+NORM+".\n");
      return;
   }
   
   if(this_object()->query_hp() < this_object()->query_mhp()/5) {
      write("Mercenary is in "+RED+"bad shape"+NORM+".\n");
      return;
   }
   
   if(this_object()->query_hp() < this_object()->query_mhp()/2) {
      write("Mercenary is "+BLU+"somewhat hurt"+NORM+".\n");
      return;
   }
   
   if(this_object()->query_hp() < this_object()->query_mhp() - 10) {
      write("Mercenary is "+CYN+"slightly hurt"+NORM+".\n");
      return;
   }
   else
      write("Mercenary is in "+GRN+"good shape"+NORM+".\n");
   
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
   if (listen && owner) tell_object(owner, "Mercenary> " + txt);
}

#endif
   
status
monster_died(object me)
{
object death_coins;
  death_coins = clone_object("obj/money");
   say("\The Mercenary lets out a sharp cry as she falls dead.\n");
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
      if (att) tell_object(att, "mercenary::heart_beat() in root()\n");
   }
   
#endif
      
   if (!(root() || objectp(owner))) {
      say(query_name() + " leaves back to Third Earth.\n");
      DAEMON->set_mercenary_name(spot, name);
      DAEMON->set_mercenary_xp(spot, xp);
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
   tell_object(owner, GRN+">>> "+NORM+query_name()+GRN+" "+HIG+this_object()->query_hp()+NORM+" / "+HIG+this_object()->query_mhp()+NORM+" "+HIR+"~"+HIB+"*"+HIR+"~ "+HIM+spell_point+NORM+" / "+HIM+max_sp+NORM+"\n");
   }
   
   if(this_object()->query_attack() && (attacker_ob != owner)){
     xp += 3+random(6);
      if(get_level(xp) > level){ 
         tell_room(environment(), HIR+"Mercenary levels up!\n"+NORM);
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
      add_action("cmd_mercenary", "mercenary");
      add_action("cmd_mercenary", lower_case(query_name()));
   }
add_action("pkill_me","kill");
   ::init();
}


/* This command is called whenever the Mercenary
     is unable to follow an order */

void
confused()
{
   write(query_name() + " shakes " + query_possessive() + " head, 'I cannot do that'\n");
}

pkill_me(str){
if(str == query_name() || str == "mercenary"){
if(!TP->query_pl_k()){ write("You are not brave enough to attack this mercenary.\n");
return 1; }
}
}

status
cmd_follow(){
   
   if(follow_me == 1){
      write(query_name()+" is already following close behind.\n"); 
      return 1; }
   
   if(follow_me == 0){
      write(query_name()+" nods, and quickly takes her stand behind you.\n");
      follow_me =1;
      return 1; }
}


cmd_stop_follow(){
   
   if(follow_me == 0){
      write(query_name()+" is already holding her possition.\n"); 
      return 1; }
   
   if(follow_me == 1){
      write(query_name()+" nods, and quickly stands down.\n");
      follow_me =0;
      return 1; }
}

status
cmd_add_arrows(string str){
  string what, where;
  int add_arrows;
  int COST;
  COST == add_arrows*100; 
   if (!str) {
     write(query_name()+" asks, 'How many arrows do you want me to buy?\n");
      return 0; }
   
   if(sscanf(str,"%d",add_arrows) != 1) {
     write(query_name()+" asks, 'How many arrows do you want me to buy?\n");
      return 0; }

   if(this_player()->query_money() < add_arrows*100){
     write(query_name()+" says, 'You don't have enough coins.'\n");
      return 0; }

   if((add_arrows + ARROWS) > 24){ 
     write(query_name()+" cannot hold more than 24 arrows in her quiver.\n");
      return 0; }

   if(add_arrows < 1){
      confused();
      return 0; }

  tell_object(owner, "You purchase "+add_arrows+" for your Mercenary.\n");
  tell_object(owner, "The cost to you is "+add_arrows*100+" coins.\n");
  ARROWS+=add_arrows;
call_other(owner, "add_money", - (add_arrows*100));
  return 1;
}


status
cmd_arrow(string str){
   object target;
   if (!str) return 0;
  if(ARROWS <= 0){ write(query_name()+" needs more arrows to fire.\n"); return 1; }
  if(SPELL_WAIT >=1){ write(query_name()+" cannot fire another arrow yet.\n"); return 1; }
 
   target = present(str, environment(this_object()));
   if (!target || !living(target) || !target->query_npc()) {
     write(query_name()+" does not see that.\n");
      return 1;
   }

   tell_object(owner, query_name()+" fires an arrow.\n");
   tell_room(environment(), "\t"+query_name()+" fires an arrow into "+target->query_name()+"!\n");
/* this_object()->attack_object(target); */
  this_object()->spell_object(target,"arrow", 1+random(5),0,"\n","\n","\n");
   SPELL_WAIT +=1;
   ARROWS -=1;
   call_out("spell_wait", 15);
   return 1;
}


status
cmd_light(){
object light;
if(spell_point <= 4){ write(query_name()+" needs ["+HIC+"5"+NORM+"] sp to cast light.\n"); return 1; }
light = clone_object("obj/torch");
        call_other(light, "set_name", "light");
        call_other(light, "set_short", ""+HIW+"A smal candle of light"+NORM);
        call_other(light, "set_fuel",100);
        call_other(light, "set_weight", 0);
        call_other(light, "set_value",0);
        call_other(light, "set_out_desc", "Your candle of light winks out.\n");
      move_object(light,this_object());
        command("light light",this_object());
tell_room(environment(), query_name()+" summons "+HIW+"light"+NORM+"!\n");
   SPELL_WAIT +=1;
   spell_point -=5;
   call_out("spell_wait", 10);
return 1; }

cmd_heal(string str){
   int amt;
   
if(!str){
   write("You must tell "+query_name()+" how many sp to use to heal.\n");
return 1; }
   
if(sscanf(str, "%d", amt) != 1) { 
   write("You must tell "+query_name()+" how many sp to"+
         " use to heal.\n");
return 1; }

if(amt < 1) { 
   write("You must tell "+query_name()+" how many sp to use to heal.\n");
return 1; }

if(spell_point < amt){ 
   write(query_name()+" can use up to "+HIM+spell_point+NORM+" sp to"+
         " heal.\n"); return 1; }
   this_object()->heal_self(1+random(amt));
   tell_object(owner, query_name()+" uses "+amt+" of sp to heal himself.\n");
   spell_point -=amt;
 return 1; }


status
cmd_spells(){
   write(HIG+"-"+NORM+"\n"+

"  Level     "+HIG+"~"+NORM+"     Spell     "+HIG+"~"+NORM+"     Cost     "+HIG+"~"+NORM+"     Comment\n"+
"  All       *     heal      *     ["+HIC+"varies"+NORM+"] *     Mercenary can heal herself\n"+
"  All       *     light     *     ["+HIC+"5"+NORM+"]      *     Mercenary casts a light ball\n"+
"  All       *     fire      *     ["+HIC+"varies"+NORM+"] *     Mercenary fires an arrrow\n"+
"            "+HIG+"~"+NORM+"               "+HIG+"~"+NORM+"              "+HIG+"~"+NORM+"\n");
   write(HIG+"-\n\n"+NORM);
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

  tell_object(owner, "You hand your Mercenary "+newcoins+" coins.\n");
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
  
  tell_object(owner, "Your Mercenary hands you "+newcoins+" coins.\n");
  s_coins-= newcoins;
  call_other(this_player(), "add_money",  newcoins);
  return 1; 
}


status
cmd_help()
{
   write(HIG+"-"+NORM+"\n"+
   "Your Mercenary can do the following commands:\n"+
      "Mercenary wear <armor>  "+HIG+":"+NORM+" Allows the mercenary to wear equipment.\n"+
      "Mercenary mon on/off    "+HIG+":"+NORM+" Toggles the mercenarys combat monitor.\n"+
      "                          (No argument will show current stats.)\n"+
      "Mercenary buy_arrow <#> "+HIG+":"+NORM+" Mercenary buy arrows to fire.\n"+
      "Mercenary follow        "+HIG+":"+NORM+" Mercenary will follow you.\n"+
      "Mercenary halt          "+HIG+":"+NORM+" Mercenary will stop following.\n"+
      "Mercenary dismissed     "+HIG+":"+NORM+" Return the mercenary to Fortress Stone.\n"+
      "                          (Mercenary will drop all, including money\n"+
      "                          onto the floor at dismissal)\n"+
      "Mercenary chold <#>     "+HIG+":"+NORM+" Give your mercenary coins to hold.\n"+ 
      "                          (can only hold up to 50000 coins [50k])\n"+
      "Mercenary cgive <#>     "+HIG+":"+NORM+" Command your mercenary to give coins.\n"+ 
      "                          (your mercenary will give coins even if\n"+
      "                          you are at maximum coins)\n"+
      "Mercenary spells        "+HIG+":"+NORM+" List Mercenary spells available.\n"+
      "Mercenary drop          "+HIG+":"+NORM+" Mercenary will drop something from inventory.\n");
   write(HIG+"-\n\n"+NORM);
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
   if(arg != "maiden bow" || arg != "maiden dagger"){
     write(query_name() + " cannot wield that.\n");
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
     write("Mercenary combat monitor "+HIR+"on\n"+NORM); 
     mon_on = 1;
     return 1; }
   
   if(str == "off"){
     write("Mercenary combat monitor "+HIB+"off\n"+NORM); 
     mon_on = 0;
     return 1; }
   
   if(!str){
      tell_object(owner, GRN+" >>>> "+NORM+query_name()+GRN+"\n"+
           " >>>> "+NORM+"Level:"+BOLD+BLK+"["+GRN+this_object()->query_level()+BOLD+BLK+"]\n"+
           NORM+GRN+" >>>> "+NORM+"HP:"+BOLD+BLK+"   ["+GRN+this_object()->query_hp()+NORM+BOLD+BLK+""+
           "/"+GRN+this_object()->query_mhp()+BOLD+BLK+"]\n"+
           NORM+GRN+" >>>> "+NORM+"SP: "+BOLD+BLK+"  ["+GRN+spell_point+NORM+BOLD+BLK+""+
          "/"+GRN+max_sp+BOLD+BLK+"]\n"+
           NORM+GRN+" >>>> "+NORM+"Exp:"+BOLD+BLK+"  ["+GRN+xp+BOLD+BLK+"]"+NORM+"\n"+
           NORM+GRN+" >>>> "+NORM+"Coins:"+BOLD+BLK+"["+GRN+s_coins+BOLD+BLK+"]"+NORM+"\n");
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
      write(query_name() + " says, 'Thank you for the fine campain.'\n"+
         "\t\tI will now return to Third Earth a Warrior Maiden.'\n");
         destruct(this_object());
         return 1; }

     
   if(s_coins >= 1){
     write(query_name()+" drops "+s_coins+" coins on the ground.\n");
     dismiss_coins->set_money(s_coins);
     move_object(dismiss_coins,environment(this_object()));
}

   DAEMON->set_mercenary_name(spot, name);
   DAEMON->set_mercenary_xp(spot, xp);
   DAEMON->set_not_taken(spot);
   write("The mercenary nods then heads back to Third Earth.\n");
   destruct(this_object());
   return 1; }


status
cmd_mercenary(string str)
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
      
      case "buy_arrow":
      cmd_add_arrows(arg);
      break;

      case "dismissed":
      cmd_dismiss();
      break;
      
      case "mon":
      cmd_mon(arg);
      break;
      
      case "fire":
      cmd_arrow(arg);
      break;

      case "heal":
      cmd_heal(arg);
      break;

      case "spells":
      cmd_spells();
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


id(str) { return (::id(str) || str == "hired_mercenary" || str == "merc" || str == "maiden"); }

set_spot(int i){ spot = i; }

set_xp(int i){ xp = i; }

      /* The following it so Mercenarys lvl 6-10 will take side attacks, */
      /* Hoth monster will not like them too much, and anything that  */
      /* affects "pets" will have effect on them.                     */

/*
is_pet(){
   if(hit_point > 99)
   return 1;
   return 0;
}
*/


spell_wait(){
   SPELL_WAIT -=1;
  tell_object(owner, query_name()+" is ready to fire another arrow.\n");
   remove_call_out("spell_wait");
return 1; }

