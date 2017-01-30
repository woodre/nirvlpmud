/* 
* Skeleton warrior, a pet for the servants of shardak
*/
inherit "/obj/monster";
#undef DEBUG

static object   owner;              /* the pet's master */
static status   listen;             /* convey catch_tells */
static status   aggr;               /* aggressive (join fight or not) */

void
reset(int x)
{
   if(x) return;
    ::reset();
  set_race("demonling");
  set_gender("creature");
  set_name("soul demon");
  set_alias("soul");
  set_alt_name("soul demon");
  set_short("The Soul Demon");
  msgin="drifts in";
  msgout = "drifts";

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
      As the soul of " + query_name() + " leaves, its unstable body\n\
     falls to the ground, disintegrating instantly.\n");
   
   return 0;                   /* self destruct */
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
      att = find_player("vertebraker");
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
         (att = (object) owner->query_attack()) &&
      (weap = query_weapon()) && !att->is_player())
   {
      tell_object(att, query_name() + " visciously attacks with its " +
         weap->query_name() + ".\n");
      say(query_name() + " visciously attacks " + att->query_name() +
         " with its " + weap->query_name() + ".\n", att);
      attacker_ob = att;
   }
   ::heart_beat();
}

init()
{
   if (objectp(owner) && this_player() == owner) {
      add_action("cmd_skeleton", lower_case(query_name()));
      if(!random(666))
      attacker_ob = owner;
   }
   if (!interactive(this_player())
         &&  query_weapon()
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
   /* do we like our master? */
   if(!random(666))
   {
      attacker_ob = owner;
      return;
   }
   
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
   aggressor();
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
   if ((string) armour->query_type() != "shield") {
      write(query_name() + " can only employ shields.\n");
      return 0;
   }
   if (!command("wear " + what)) {
      write(query_name() + " failed to wear it.\n");
      return 0;
   }
   return 1;
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
cmd_skeleton(string str)
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
      
      case "unwield":
      command(str);
      break;
      
      case "drop":
      cmd_drop(arg);
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


id(str) { return (::id(str) || str == "soul demon"); }
