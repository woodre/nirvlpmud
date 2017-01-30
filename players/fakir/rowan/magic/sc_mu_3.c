
/*
 * SCROLL OF 3 MAGIC-USER SPELLS (1/24/94)
 * --flesh to stone   Turn monster into stone (must be 5 lvls lower)
 * --stone to flesh   Return player to flesh
 * --fear             Cause monster to run away (must be 5 lvls lower)
 */

int flesh, stone, fear;

reset(arg) {
   if(arg)
     return;
   flesh = 1;
   stone = 1;
   fear = 1;
}

id(str) { return str == "scroll"; }

get() { return 1; }

query_value() {
   if(flesh + stone + fear == 3)
     return 600;
   if(flesh + stone + fear == 2)
     return 400;
   return 200;
}

short() { return "A scroll of magic-user spells"; }

long() {
   write("A scroll written on fine parchment.\n");
   write("It is a scroll of magic-user spells.\n");
   if(flesh) 
     write("--flesh to stone   Turns monster to stone\n");
   if(stone)
     write("--stone to flesh   Returns stoned object to flesh\n");
   if(fear)
     write("--fear             Causes monster to run away\n");
}

init() {
   add_action("turn_to_stone","flesh");
   add_action("turn_to_flesh","stone");
   add_action("fear","fear");
}

fear(who) {
   int lvl;
   object target;

   if(!who) {
     write("Who would you like to cast the spell against?\n");
     write("Usage: fear <monster>\n");
     return 1;
   }
   target = present(who, environment(this_player()));
   if(!target) {
     write(capitalize(who)+" is not here.\n");
     return 1;
   }
   if(!target->query_npc()) {
     write("You may not use this spell against players.\n");
     return 1;
   }
   lvl = this_player()->query_level();
   lvl -= 5;
   if(target->query_level() >= lvl) {
     write(capitalize(who)+" is too powerful for you to scare.\n");
     return 1;
   }
   say(capitalize(this_player()->query_name())+" reads from a scroll.\n");
   tell_room(environment(this_player()), capitalize(who)+
       " screams in fear and bolts for the nearest exit.\n");
   target->run_away();
   fear = 0;
   if(!stone && !flesh)
     destruct(this_object());
   return 1;
}

turn_to_stone(str) {
   object target, statue;
   int lvl;
   string who;

   if(!flesh)
     return;
   if(sscanf(str, "to stone %s", who) != 1) {
     write("USAGE: flesh to stone <target>\n");
     return 1;
   }
   target = present(who, environment(this_player()));
   if(!target) {
     write(capitalize(who)+" is not here.\n");
     return 1;
   }
   if(!target->query_npc()) {
     write("This spell may not be used against players.\n");
     return 1;
   }
   lvl = this_player()->query_level();
   lvl -= 5;
   if(target->query_level() >= lvl) {
     write(capitalize(who)+" is too powerful to turn to stone.\n");
     return 1;
   }
   say(capitalize(this_player()->query_name())+" reads from a scroll.\n");
   tell_room(environment(this_player()), capitalize(who)+
       " hardens to stone!\n");
   statue = clone_object("players/molasar/rowan/magic/obj/stone");
   statue->set_short(target->short());
   statue->set_target(target);
   statue->set_duration(200);
   move_object(statue, environment(this_player()));
   move_object(target, statue);
   flesh = 0;
   if(!stone && !fear)
     destruct(this_object());
   return 1;
}

turn_to_flesh(str) {
   object statue;

   if(!str || str != "to flesh" || !stone)
     return;
   statue = present("stoned_object", environment(this_player()));
   if(!statue) {
     write("There is no stoned object here.\n");
     return 1;
   }
   say(capitalize(this_player()->query_name())+" reads from a scroll.\n");
   statue->set_duration(0);
   statue->awaken();
   stone = 0;
   if(!flesh && !fear) 
     destruct(this_object());
   return 1;
}

