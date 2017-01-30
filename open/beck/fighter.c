
/* 
* Squire Fighter for Knights Templar
* Adapted from Vertebraker's Skeleton
* for Shardak guild.
*/

inherit "/players/vertebraker/closed/std/monster";
#include "/players/jaraxle/define.h";
#undef DEBUG

static object   owner;              /* the pet's master */
static status   listen;             /* convey catch_tells */
static status   aggr;               /* aggressive (join fight or not) */
static int      hit_points;         /* hit_point values */
static int      follow_me;          /* Follow command toggle */
static int      mon_on;             /* Monitor toggle*/
static int      extraexp, cost;     /* Training cost */
void
reset(int x)
{
   if(x) return;
   
   follow_me = 1;
   mon_on = 0;
   hit_points = 20+random(6);
   
   ::reset();
   set_race("human");
   set_gender("male");
   set_name("squire");
   set_alias("fighter");
   set_alt_name("squire fighter");
   set_short("A Squire");
   set_hp(hit_points);
   msgin="sprints in";
   msgout = "quickly follows behind";
   set_can_kill(1);
   set_dead_ob(this_object());
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
   say("\
      The Squire lets out a sharp cry as he falls dead.\n");
   return 0;                   
}

void
set_owner(object o)
{
   owner = o;
}

object
query_owner()
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
      say(query_name() + " leaves.\n");
      destruct(this_object());
      return;
   }
   if (environment(owner) && !present(owner, environment()) && follow_me != 0) {
      move_player("after " + owner->query_name()+"#"+object_name(environment(owner)));
   }
   if (!attacker_ob && !query_attack() &&
         (att = (object) owner->query_attack()) &&
      (weap = query_weapon()) && !att->is_player())
   {
      tell_object(att, query_name() + " lets out a cry as he attacks you with his " +
         weap->query_name() + ".\n");
      say(query_name() + " lets out a battle cry as he attacks " + att->query_name() +
         " with his " + weap->query_name() + ".\n", att);
      attacker_ob = att;
   }
   
   if(owner && mon_on == 1 && this_object()->query_attack()) {
      tell_object(owner, HIC+">>> "+NORM+query_name()+HIC+" :"+HIG+this_object()->query_hp()+NORM+" / "+HIG+this_object()->query_mhp()+NORM+"\n");
   }
   ::heart_beat();
}

init()
{
   if (objectp(owner) && this_player() == owner) {
      add_action("cmd_squire", lower_case(query_name()));
   }
   
   ::init();
}

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
   if ((string) armour->query_type() != "shield" || (string) armour->query_type() != "armor" || (string) armour->query_type() != "boots" || (string) armour->query_type() != "misc") {
      write(query_name() + " cannot wear that.\n");
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
   
   if(str == "on"){ write("Squire combat monitor "+HIR+"on\n"+NORM); mon_on = 1; return 1; }
   
   if(str == "off"){ write("Squire combat monitor "+HIB+"off\n"+NORM); mon_on = 0; return 1; }
   
   if(!str){  tell_object(owner, HIC+">>> "+NORM+query_name()+" "+HIC+":"+NORM+" Level "+HIB+"["+HIY+this_object()->query_level()+HIB+"] "+HIG+this_object()->query_hp()+NORM+" / "+HIG+this_object()->query_mhp()+NORM+"\n"); return 1; }
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
cmd_train(){
   cost = 20000+random(5001);
   if(this_player()->query_extra_level() < 1)
extraexp = (int)owner->query_exp() - (int)"/room/exlv_guild"->get_next_exp((int)owner->query_level() - 1);
   else
extraexp = (int)owner->query_exp() - (int)"/room/adv_guild"->get_next_exp((int)owner->query_level() - 1);
   if(extraexp < cost){
      notify_fail("You lack the experience to train your Squire.\n");
      return 0;
   }
   if(this_object()->query_max_hp() > 90){
      notify_fail(cap_name+" needs no more training.\n");
      return 0;
   }
   
   switch(random(5)){
      case 0:  if((int)this_object()->query_level() == 1){
         hit_points += 15+random(11);
         this_object()->set_level(2);
         this_object()->save_me();
         break; }
      case 1:   if((int)this_object()->query_level() == 2){
         hit_points += 20+random(11);
         this_object()->set_level(3);
         this_object()->save_me();
         break; }
      case 2:  if((int)this_object()->query_level() == 3){
         hit_points += 25+random(11);
         this_object()->set_level(4);
         this_object()->save_me();
         break; }
      case 3:  if((int)this_object()->query_level() == 4){
         hit_points += 30+random(12);
         this_object()->set_level(5);
         this_object()->save_me();
         break; }
   }
   this_player()->add_exp(-cost);
   write_file("/players/jaraxle/closed/templar/squires/fighter.log",this_player()->query_real_name()+" Cost:"+cost+" Squire HP: "+hit_points+"\n");
   this_player()->add_xp(-cost);
   write("You begin training your Squire through mock combat.\n");
   if(this_object()->query_max_hp() > 90)
      write(cap_name+" is fully trained.\n");
   this_object()->save_me();
   return 1;
}

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
      
      case "train":
      cmd_train();
      break;
      case "mon":
      cmd_mon(arg);
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

save_me(){
   save_object("players/jaraxle/closed/templar/squires/owners/"+owner);
}

id(str) { return (::id(str) || str == "f_squire"); }
