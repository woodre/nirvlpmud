inherit"obj/monster";

object flame;

reset(arg) {

   ::reset(arg);

   if(!arg) {

   set_name("incinerator");
   set_short("Incinerator, the Supreme Controller of Fire");
   set_long(
"This looks like a vaguelly ogre-ish shaped being, at least ten feet tall.\n"+
"He wears a mean expression, and every move he makes throws fire in different"+
"\ndirections.  He is also not happy to meet you.\n");

   set_level(16);
   set_ac(14);
   set_hp(400);
   set_aggressive(1);
   set_alias("god");
   set_a_chat_chance(33);
   load_a_chat("The room fills with blinding light as Incinerator's thrower"+
               " shoots fire!!!\n");

   load_a_chat("Incinerator roars and you feel the walls shake!!!\n");
flame=clone_object("players/blue/weapons/flame_thrower");
   move_object(flame, this_object());
   command("wield flame thrower",this_object());
/* Set the wc since lev.16 -Snow */
   set_wc(25);
   }
}
   
