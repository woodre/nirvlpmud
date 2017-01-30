
/*
 * SCROLL OF 3 MAGIC-USER SPELLS (3/19/94)
 * --sleep   Put monsters 10 lvls below player asleep
 * --stinking cloud  create cloud which will damage monsters
 * --faerie fire  Encircle the monster in flames, lowering their ac
 */

int sleep, cloud, fire;

reset(arg) {
   if(arg)
     return;
   sleep = 1;
   cloud = 1;
   fire = 1;
}

id(str) { return str == "scroll"; }

get() { return 1; }

query_value() {
   if(sleep + cloud + fire == 3)
     return 1000;
   if(sleep + cloud + fire == 2)
     return 666;
   return 333;
}

short() { return "A scroll of magic-user spells"; }

long() {
  write("A scroll written on fine parchment.\n");
  write("This scroll is empowered with magic-user spells.\n");
  if(sleep)
    write("--sleep            Will put low level monsters to sleep\n");
  if(cloud)
    write("--stinking cloud   Will create a cloud which will damage "+
          "all monsters\n");
  if(fire)
    write("--faerie fire      Will encircle monster in harmless flame "+
          "which reduces its ac\n");
}

init() {
   add_action("sleep","sleep");
   add_action("stinking","stinking");
   add_action("faerie","faerie");
}

sleep() {
   object invob, next_invob;
   object sleep_obj;
   int max_level, lvl;

   if(!sleep)
     return;
   lvl = this_player()->query_level();
   max_level = this_player()->query_attrib("mag");
   invob = first_inventory(environment(this_player()));
   say(capitalize(this_player()->query_name())+" reads from a scroll.\n");
   while(invob) {
     next_invob = next_inventory(invob);
     if(invob->query_npc()) {
       if(invob->query_level() < (lvl - 10)) {
         sleep_obj = clone_object("players/molasar/rowan/magic/obj/sleep");
         sleep_obj->set_short(invob->short());
         sleep_obj->set_target(invob);
         sleep_obj->set_duration(max_level*10);
         move_object(sleep_obj, environment(this_player()));
         move_object(invob, sleep_obj);
         tell_room(environment(this_player()),
             capitalize(invob->query_name())+" falls asleep.\n");
       }
     }
     invob = next_invob;
   }
   sleep = 0;
   if(!fire && !cloud)
     destruct(this_object());
   return 1;
}

stinking(str) {
   object cloud_obj;
   int mag;
   
   if(!str || str != "cloud" || !cloud)
     return;
   say(capitalize(this_player()->query_name())+" reads from a scroll.\n");
   cloud_obj = clone_object("players/molasar/rowan/magic/obj/cloud");
   mag = this_player()->query_attrib("mag");
   cloud_obj->set_duration(mag*10);
   cloud_obj->set_damage(mag);
   move_object(cloud_obj, environment(this_player()));
   cloud_obj->damage();
   tell_room(environment(this_player()),
       "A large sulphurous cloud forms.\n");
   cloud = 0;
   if(!fire && !sleep)
     destruct(this_object());
   return 1;
}

faerie(str) {
   object target;
   string sh_str, who;
   int ac;

   if(!fire)
     return;
   if(sscanf(str, "fire %s", who) != 1) {
     write("USAGE: faerie fire <target>\n");
     return 1;
   }
   target = find_living(who);
   if(!target || !present(target, environment(this_player()))) {
     write(capitalize(who)+" is not here.\n");
     return 1;
   }
   if(!target->query_npc()) {
     write("You may not use this spell against players.\n");
     return 1;
   }
   ac = target->query_ac();
   target->set_ac(ac-1);
   sh_str = target->short();
   target->set_short(sh_str+" (outlined in flames)");
   say(capitalize(this_player()->query_name())+" reads from a scroll.\n");
   tell_room(environment(this_player()), capitalize(who)+" is suddenly "+
       "outlined in a bright blue flame.\n");
   target->attack_object(this_player());
   fire = 0;
   if(!cloud && !sleep)
     destruct(this_object());
   return 1;
}

