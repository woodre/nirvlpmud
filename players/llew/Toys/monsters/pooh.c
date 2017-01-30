inherit "obj/monster";

object quest_caller;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("Winnie the Pooh");
   set_level(7);
   set_alias("winnie");
   set_alt_name("pooh");
   set_race("bear");
   set_hp(100+random(30));
   set_al(100);
   set_short("Winnie the Pooh");
   set_long("The lovable friend of Cristopher Robin looks to be a little\n"+
         "depressed right now.  He is a cute, yellow stuffed bear with a\n"+
         "bright red shirt.  He seems to be carrying a yellow head with\n"+
         "a smiling face.\n");
   set_wc(11);
   set_ac(6);
   set_chat_chance(14);
   set_a_chat_chance(15);
   load_chat("Pooh says, \"Oh bother, I've lost my honey pot.\"\n");
   load_chat("Pooh's tummy rumbles loudly.\n");
   load_chat("Pooh says, \"Think... think, think... think...\"\n");
   load_chat("Pooh says, \"Would there happen to be any honey in that pot.\"\n");
   load_chat("Pooh says, \"Have you seen Christopher Robin?\"\n");
   load_chat("Pooh waddles about.\n");
   load_a_chat("Pooh says, \"Why are you attacking me?\"\n");
   load_a_chat("Pooh looks very sad.\n");
   load_a_chat("Pooh sighs.\n");
   move_object(clone_object("/players/llew/Toys/armor/redshirt.c"),this_object());
}

init() {
   ::init();
   if(present("pooh_honeypot",this_player())) {
      quest_caller=this_player();
      call_out("quest",5);
   }
}

quest() {
   if(environment(quest_caller) && environment(quest_caller) == environment() && present("pooh_honeypot",quest_caller)) {
      tell_room(environment(),"Pooh says, \"That is my honey pot you have.  Oh thank you\n"+
         "            very much.  There was a rumbly in my tumbly.\n");
      tell_object(quest_caller,"Pooh takes his honeypot from you.\n");
      say("Pooh takes the honeypot from "+quest_caller->query_name()+".\n",quest_caller);
      move_object(present("pooh_honeypot",quest_caller),this_object());
      call_out("quest2",5);
   }
   else quest_caller=0;
}

quest2() {
   tell_room(environment(),"Pooh says, \"You may have this empty honeypot I found.\"\n");
   move_object(clone_object("/players/llew/Toys/quest/head"),environment());
   tell_room(environment(),"Pooh drops the lego head.\n");
   destruct(present("pooh_honeypot"));
   quest_caller=0;
}
