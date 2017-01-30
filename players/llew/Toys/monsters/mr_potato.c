inherit "obj/monster";

object quest_caller;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("Mr. Potato Head");
   set_level(8);
   set_alias("potato head");
   set_race("potato");
   set_hp(120);
   set_al(65);
   set_short("Mr. Potato Head");
   set_long("Mr. Potato head is a jumble of misorganized parts.  His\n"+
      "lips don't match his eyes, nor nose, but he is fun to look\n"+
      "at nonetheless.  His arm seems a bit out of place though, even\n"+
      "considering what a conglomeration he already is.\n");
   set_wc(12);
   set_ac(7);
   set_alt_name("mr potato head");
   set_chat_chance(9);
   set_a_chat_chance(15);
   load_chat("Mr. Potato Head frowns.\n");
   load_chat("Mr. Potato Head searches through his bucket of parts.\n");
   load_chat("Mr. Potato Head says, \"This arm doesn't fit very well.\"\n");
   load_chat("Mr. Potato Head says, \"Where did I put my real arm?\"\n");
   load_a_chat("Mr. Potato Head gets mashed.\n");
   load_a_chat("Mr. Potato Head throws his parts about wildly.\n");
   load_a_chat("Mr. Potato Head screams!\n");
   move_object(clone_object("/players/llew/Toys/misc/rand_potato_part"),this_object());
   move_object(clone_object("/players/llew/Toys/misc/rand_potato_part"),this_object());
}

init() {
   ::init();
   if(present("potato_arm",this_player())) {
      quest_caller=this_player();
      call_out("quest",5);
   }
}

quest() {
   if(environment(quest_caller) && environment(quest_caller) == environment() && present("potato_arm",quest_caller)) {
      tell_room(environment(),"Mr. Potato Head says, \"My arm!\"\n");
      tell_object(quest_caller,"Mr. Potato Head takes the potato arm from you.\n");
      say("Mr. Potato Head takes a potato arm from "+quest_caller->query_name()+".\n",quest_caller);
      move_object(present("potato_arm",quest_caller),this_object());
      call_out("quest2",5);
   }
}

quest2() {
   tell_room(environment(),"Mr. Potato Head plunks his arm back in it's socket.\n");
   call_out("quest3",5);
}

quest3() {
   tell_room(environment(),"Mr. Potato Head says, \"I won't need this useless arm anymore.\"\n");
   move_object(clone_object("/players/llew/Toys/quest/arm"),environment());
   tell_room(environment(),"Mr. Potato Head drops lego arm.\n");
   quest_caller=0;
   destruct(present("potato_arm"));
}
