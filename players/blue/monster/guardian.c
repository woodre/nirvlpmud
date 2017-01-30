inherit"obj/monster";

reset(arg) {

   if(!arg) {

   set_level(15);
   set_name("warrior");
   set_short("A Warrior of the Planes");
   set_long(
"This is a mighty warrior who guards these planes from those seeking\n"+
"treasure.  He is dressed in complete blackness and stares at you with silent "+
   "\nintesnsity.\n");
   
   set_level(15);
   set_wc(18);
   set_ac(12);
/* Changed from 25! to 250 hp - Snow */
   set_hp(250);
   set_chat_chance(30);
   set_a_chat_chance(30);
   load_chat("The great warrior looks down at you.\n");
   load_chat("The warrior begins to chant.\n");
 load_a_chat(capitalize(this_object()->query_name()) + " lets out a war cry.\n");
   load_a_chat(capitalize(this_object()->query_name()) + " scowls.\n");
   }
}
