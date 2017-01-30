
/*
 * Lady Morgana (4/30/94)
 */

inherit "obj/monster";

int shackled;

reset(arg) {
   if(arg)
     return;
   set_name("morgana");
   set_alias("lady");
   set_alt_name("wench");
   set_level(8);
   set_wc(3);
   set_ac(0);
   set_al(350);
   set_short("An old wretched wench");
   set_long("She sits next to the wall hunched over in almost a fetal\n"+ 
   "position. Her thin grey hair is matted together and covered in soot.\n"+ 
   "An old flour sack serves as her only source of clothing, leaving\n"+
   "the majority of her grey withered flesh exposed.\n"+
   "Cast iron shackles keep her chained in her cell.\n");
   shackled = 1;
   ::reset();
}

#define TELL(x) tell_room(environment(this_object()), x)
#define SPEAK(x) tell_room(environment(this_object()), "The Lady says: "+x)
#define WRITE(x) tell_room(environment(this_object()), "               "+x)

remove_shackles() {
   string pl_name;
   pl_name = this_player()->query_name();

   if(!shackled) {
     write("The woman is no longer shackled.\n");
     return 1;
   }
   shackled = 0;
   TELL(pl_name+" removes the shackles that chain the old wench.\n");
   TELL("Suddenly the image of the old woman seems to fade in and out....\n");
   TELL("The woman seems to change shape and grow younger.......\n");
   TELL("As the change ends you find yourself staring into the eyes of a\n");
   TELL("young maiden, barely out of adolescence.\n");
   TELL("\n");
   TELL("The young woman curtseys to "+pl_name+".\n"); 
   if(this_player()->query_gender() == "female") {
     SPEAK("Thank you my Lady. Your gesture of kindness has released me.\n");
   } else { 
     SPEAK("Thank you kind Sir. Your gesture of kindness has released me.\n");
   }
   TELL("The young woman looks at you with a face of innocence.\n");
   SPEAK("I am the Lady Morgana Praxus, wife of Lord Ariand Praxus.\n");
  TELL("Morgana turns her head looking upward, a glazed look in her eyes.\n");
   TELL("She abruptly returns her attention back to you.\n");
   SPEAK("You have freed me from my imprisonment so I shall free you.\n");
   WRITE("Ariand is dead only in flesh. His spirit lives on. You can\n");
   WRITE("only escape if you destroy it! Go to the meeting chamber, you\n");
   WRITE("will find a jar which contains his spirit. You must free it\n");
   WRITE("then destroy it. Good luck. I must leave now.\n");
   TELL("The Lady Morgana gives you a thoughtful look, then slowly fades\n");
   TELL("from sight.\n");
   call_other("/players/molasar/rowan/drake/mansion/mt_chmbr","set_jar",1);
   destruct(this_object());
   return 1;
}

