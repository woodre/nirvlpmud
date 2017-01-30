inherit "/obj/monster";
#include "/players/pestilence/define.h"
#undef DEBUG

static object   owner;              /* the pet's master */
static status   listen;             /* convey catch_tells */
static status   aggr;               /* aggressive (join fight or not) */
int GUARD;
object ob;

void
reset(int x)
{
   if(x) return;
    GUARD = 0;
    ::reset();
  set_race("rodent");
  set_gender("male");
  set_name(""+HIK+"Possessed Wolverine"+NORM+"");
  set_alias("wolverine");
  set_alt_name("possessed wolverine");
  set_short(""+HIK+"Possessed Wolverine"+NORM+""); 
set_message_hit( ({""+HIR+"tears"+NORM+"into"," with a tremendous attack",
""+HIR+"lacerates"+NORM+""," with a devastating slash with it's claws",
"devastates"," with a series of bites",
"slashes"," with its' claws",
"scraped"," with a solid bite",
"skinned"," with a weak attack",
"missed"," with a bite"}) );
  msgin="runs in";
  msgout = "runs";

   set_can_kill(1);
   set_dead_ob(this_object());
}

#ifdef DEBUG
   void
catch_tell(string txt) {
   if (listen && owner) tell_object(owner, "Spinal> " + txt);
}
#endif
   
status
monster_died(object me)
{
   object ob;
   if (ob = present("corpse", environment()))
      destruct(ob); 
   say("\
      " + query_name() + " vanishes back into darkness as it dies.\n");
   
   return 0;                   /* self destruct */
}

is_pet() { return 1;}
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
      att = find_player("pestilence");
      if (att) tell_object(att, "skeleton::heart_beat() in root()\n");
   }
#endif
      if (!(root() || objectp(owner))) {
      say(query_name() + " crumbles to dust.\n");
      destruct(this_object());
      return;
   }
   if (environment(owner) && !present(owner, environment())) {
      move_player("after " + owner->query_name()+"#"+file_name(environment(owner)));
   }
   if (!attacker_ob && !query_attack() &&
         (att = (object) owner->query_attack()) &&  (GUARD = 1) &&
         !att->is_player())
   {
      tell_object(att, query_name() + " visciously attacks.\n");
      say(query_name() + " visciously attacks " + att->query_name() +".\n", att);
      attacker_ob = att;
   }
  if(TO->query_attack()){
    tell_object(owner, 
     HIY+"Wolverine-> "+((hit_point * 10)/max_hp)+" / 10"+NORM+"\n");
  } 
   ::heart_beat();
}

init()
{
   if (objectp(owner) && this_player() == owner) {
      add_action("cmd_skeleton", lower_case(query_name()));
   }
   if (!interactive(this_player()) 
      && (!this_player()->neopet())
      &&  ((object) this_player()->query_owner() == owner))
   attacker_ob = this_player();        /* don't allow more pets */
   
   ::init();
}

void
confused()
{
   write(query_name() + " shakes " + query_possessive() + " head in confusion.\n");
}

void
aggressor()
{
   object ob;
   
   /* if (!query_weapon()) return; */   
   /* we hate other pets */
   ob = first_inventory(environment());
   while (ob) {
      if ((ob != this_object()) && living(ob) &&
            (!ob->neopet())
             &&
            ((object) ob->query_owner() == owner)) {
         attacker_ob = ob;
         break;
         }
      ob = next_inventory(ob);
   }
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

cmd_kill(string arg) {
  object meat;
  if(this_player() != owner) return 0;

  if(!arg) { 
    write("Kill what?\n"); 
    return 1; 
    }
  meat = present(arg,(environment(this_player())));
  if(!meat) {
    write("There is no "+capitalize(arg)+" present!\n");
    return 1;
  }
  if(!meat->query_npc()) {
    write("Wolverine will not attack players!\n");
    return 1;
  }
  if(meat == this_object()) {
    write("Your "+capitalize((string)this_object()->query_name()) +
      " will not attack itself!\n");
    return 1;
  }
  tell_room(environment(this_object()),"Wolverine begins to attack!\n");
  this_object()->attack_object(meat); 
  return 1;
}

cmd_stop() {
  object meat, premeat;
    meat = this_object()->query_attack();
    if(!this_object()->query_attack()) {
      write("Your "+capitalize((string)this_object()->query_name()) + 
        " is not fighting!\n"); 
      return 1; 
    }
    write("Your "+capitalize((string)this_object()->query_name())+
      " stops fighting.\n");
    if(meat->query_attack() == this_object()) {
      meat->stop_fight();
      meat->stop_fight();
      meat->stop_hunter();
    }
    if(meat->query_attack()) {
      premeat = meat->query_attack();
      meat->stop_fight();
      meat->stop_fight();
      meat->attack_object(premeat);
    }
    this_object()->stop_fight();
    this_object()->stop_fight();
    this_object()->stop_hunter();
    return 1;
  }

cmd_release() {
    write("You command your " + 
      capitalize((string)this_object()->query_name()) + 
      " to return to Darkness.\n"+"\n");
    tell_room(environment(this_object()),this_player()->query_name()+"'s " + 
      capitalize((string)this_object()->query_name())+
      " leaves into the darkness!\n");
    destruct(this_object());
    return 1;
  }

cmd_guard() {
if(GUARD = 0){
    write("You command your " + 
      capitalize((string)this_object()->query_name()) + 
      " to guard you.\n"+"\n");
    GUARD += 1;
    return 1;
}
else {
    write("You command your " + 
      capitalize((string)this_object()->query_name()) + 
      " to stop guarding you.\n"+"\n");
    GUARD += 0;
    return 1;
}
}
status
cmd_skeleton(string str)
{
   string cmd, arg;
   
   if(!str) return 0;
   cmd = str;
   sscanf(str, "%s %s", cmd, arg);
    
   listen = 1;
   switch (cmd) {

      case "drop":
      cmd_drop(arg);
      break;
      
      case "awake":
      attacker_ob = 0;
      set_heart_beat(1);
      break;
      
      case "kill":
      cmd_kill(arg);
      break;

      case "stop":
      cmd_stop();
      break;

      case "guard":
      cmd_guard();
      break;

      case "release":
      cmd_release();
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


id(str) { return (::id(str) || str == "wolverine"); }
