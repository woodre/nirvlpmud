
/*
 * CALL (4/17/94)
 * Allow paladin to summon a warhorse
 */

call(call_time) {
   object warhorse, pack;
   int cmod;
   string name;

   if(this_player()->query_attack())
     notify_fail("You cannot cast this during combat.");
   if(!verify_use())
     return 1;
   if(this_player()->query_level() < 21 && time() < call_time + 900)
     notify_fail("You must rest before you can use this power again.");
   name = this_player()->query_name();
   cmod = previous_object()->query_combat_mod("mounted");
   warhorse = clone_object("players/sandman/paladin/obj/warhorse");
   warhorse->set_owner(this_player()->query_real_name());
   warhorse->set_level((cmod*2)/3);
   warhorse->set_wc(cmod);
   warhorse->set_ac(cmod/3);
   pack = clone_object("players/sandman/paladin/obj/pack");
   move_object(pack, warhorse);
   move_object(warhorse, environment(this_player()));
   TELL(name+" whistles softly.\n");
   TELL("A warhorse arrives.\n");
   previous_object()->set_call_time(time());
   return 1;
}
