
/*
 * Lord Ariand (4/30/94)
 */

inherit "obj/monster";

reset(arg) {
   object plate;
   if(arg)
     return;
   set_name("ariand");
   set_alias("lord");
   set_level(25);
   set_wc(30);
   set_ac(15);
   set_al(-500);
   set_hp(500);
   set_short("Lord Ariand");
   set_long("The Lord Ariand is covered in the type of garb you'd\n"+
   "expect for royalty. He wears a full suit of platemail with a cape\n"+
   "drapped over his back. He wears the medallion off the Paladins around\n"+
   "his neck, however you notice something different about it. It's made\n"+
   "of some jet black substance. Perhaps he will tell you his <story>\n");
   set_dead_ob(this_object());
/*
   plate = clone_object("players/molasar/rowan/drake/obj/full_pl");
   move_object(plate, this_object());
*/
   init_command("wear plate", this_object());
   ::reset();
}

init() {
   add_action("story","story");
}

#define TELL(x) tell_room(environment(this_object()), x)
#define SPEAK(x) tell_room(environment(this_object()), "Ariand says: "+x)
#define WRITE(x) tell_room(environment(this_object()), "             "+x)

story() {
   TELL("Ariand looks at "+this_player()->query_name()+" and nods.\n");
   SPEAK("You wish to now my story? Very well.....\n");
   WRITE("I was a Paladin, a captain of my company, the local militia\n"); 
   WRITE("in charge of the protection for Drakeshore. I wanted more power\n");
   WRITE("but was constantly overlooked, being passed over many times\n");
   WRITE("for less experienced Paladins.\n");
   TELL("Ariand pauses for a moment and takes a deep breath.\n");
   SPEAK("Then one night a strange figure came to me. A person so evil\n"); 
   WRITE("it caused me to shake uncontrollably by it's mere presence.\n");
   WRITE("It offered me the power I sought. The complete control of\n");
   WRITE("Drakeshore and all it's inhabitants. For my part of the deal\n");
   WRITE("I had to move my company inside the mansion and lock the gates.\n");
   TELL("Ariand hesitates for a moment.\n");
   SPEAK("And one....other minor item.\n");
   WRITE("When I opened the gates the next morning the dark figure said\n");
   WRITE("the city would be mine.\n");
   TELL("Ariand gives a wry grin.\n");
   SPEAK("When the gates were opened we found the city sacked. Nothing\n");
   WRITE("left standing except the Governor's Manse. The dark figure\n");
   WRITE("greeted me and made me Governor of Drakeshore, a ghosttown now.\n");
   TELL("Ariand gives you an evil grin and a shrug.\n");
   return 1;
}

monster_died(ob) {
   call_other("/players/molasar/rowan/drake/mansion/mt_chmbr","set_guard",1);
   return 0;
}
