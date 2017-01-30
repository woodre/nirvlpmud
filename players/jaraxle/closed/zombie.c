/* Corpse slave for Elec Sigil */

/* This was used with permission from Vertebraker (Thanks Dood!) */
/* The corpse slave code is a 'slight' rework and rewrite of */
/* the Shardak skeleton code. */


inherit "obj/monster";

static object   owner;              /* the pet's master */
static status   listen;             /* convey catch_tells */
static status   aggr;               /* aggressive (join fight or not) */

void
reset(status arg)
{
   if(arg) return;
   ::reset();
   msgout = "lurches";
   set_dead_ob(this_object());
   set_can_kill(1);
}
   
status
monster_died(object me)
{
   object ob;
   if (ob = present("corpse", environment()))
      destruct(ob);
   say("\
      As the spirit of " + query_name() + " departs, the corpse collapses onto\n\
      itself. Immediately the corpse rots away.\n");
   
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

void
heart_beat()
{
   object att, weap;
   
      if(!objectp(owner)) {
      say(query_name() + " collapses into a heap of flesh.\n");
      destruct(this_object());
      return;
   }
   if (environment(owner) && !present(owner, environment())) {
      move_player(environment(owner), "after " + owner->query_name());
   }
   if (!kill_ob && !query_attack() &&
         (att = (object) owner->query_attack()) &&
      (weap = (object)query_weapon()) && !att->is_player())
   {
      tell_object(att, query_name() + " approaches you with a lifted " +
         weap->query_name() + ".\n");
      say(query_name() + " approaches " + att->query_name() +
         " with a lifted " + weap->query_name() + ".\n", att);
      kill_ob = att;
   }
   ::heart_beat();
}

void
init()
{
   if (objectp(owner) && this_player() == owner) {
      add_action("cmd_skeleton", lower_case((string)query_name()));
      if ((int) owner->query_alignment() > -40
            ||  random((int)query_wc()) > (int) owner->query_attrib("wil"))
      kill_ob = owner;
   }
   if (!interactive(this_player())
         &&  query_weapon()
      &&  ((object) this_player()->query_owner() == owner))
   kill_ob = this_player();        /* don't allow more pets */
   
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
   if ((int) owner->query_alignment() > -40
         ||  random(query_wc() + 4) > (int) owner->query_attrib("wil")) {
      kill_ob = owner;
      return;
   }
   
   /* we hate other pets */
   ob = first_inventory(environment());
   while (ob) {
      if ((ob != this_object()) && living(ob) &&
            ((object) ob->query_owner() == owner &&
             (status)ob->is_pet())) {
         kill_ob = ob;
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
   if (!weapon->query_wielded()) {
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
if ((string) armour->query_type() != "shield" && 
    (string) armour->query_type() != "armor") {

      write(query_name() + " can only wear main armor and shields.\n");
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
   
   if (transfer(ob, environment())) {
      write(query_name() + " failed to drop it.\n");
      return 0;
   }
   say(query_name() + " drops " + str + ".\n");
   return 1;
}

status
cmd_skeleton(string str)
{
   string cmd, arg;
   cmd = str;
if(!str){
write("You can command your slave to do the following:\n"+
      "wield <weapon> : wear <item>\n"+
      "drop <item>    : get <item>\n");
return 1; }

   
   sscanf(str, "%s %s", cmd, arg);
   
   listen = 1;
   switch (cmd) {
      case "wield":
      cmd_wield(arg);
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
      
      case "awake":
      kill_ob = 0;
      set_heart_beat(1);
      break;
      
      default:
         confused();
      break;
   }
   listen = 0;
   return 1;
}

