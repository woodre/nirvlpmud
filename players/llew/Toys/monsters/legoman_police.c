#include "/players/llew/closed/ansi.h"
#define QUEST_VERBS ({"assemble","fix","make","combine","unite","join","bind","fasten","link","mend","repair","restore","build","construct","form"})
inherit "obj/monster";

object quest_caller;
string quest_verb;
int quest_done;

reset(arg) {
   no_clean=1;
   ::reset(arg);
   set_chat_chance(10);
   set_a_chat_chance(15);
   if(arg) return;
   quest_done=0;
   quest_verb=QUEST_VERBS[random(sizeof(QUEST_VERBS)-1)];
   set_name("Police Legoman");
   set_level(9);
   set_alias("police");
   set_race("legoman");
   set_hp(135);
   set_al(100);
   set_short("A Police Legoman");
   set_long("The Police legoman is dressed in a blue police uniform and black hat.\n"+
            "He carries a nightstick with him to protect the legopeople citizens.\n"+
            "The Police legoman doesn't look very happy.\n");
   set_wc(13);
   set_ac(7);
   set_chance(15);
   set_spell_mess1("The legoman bashes away with his nightstick.\n");
   set_spell_mess2("The legoman bashes away with his nightstick.\n");
   set_spell_dam(8);
   load_chat("The Police Legoman says, \"We need to rescue our King.\"\n");
   load_chat("The Police Legoman says, \"Our King was taken by pirates, and his body scattered.\"\n");
   load_chat("The Police Legoman says, \"It's lucky I recovered the King's legs.\"\n");
   load_chat("The Police Legoman says, \"If only I could get the rest of our King,\n"+
             "                          he could be made whole again.\"\n");
   load_chat("The Police Legoman frowns unhappily.\n");
   load_chat("The Police Legoman says, \"Where could the pieces to our King be?\"\n");
   load_a_chat("The Police Legoman sighs.\n");
   load_a_chat("The Police Legoman says, \"No not me!  We must save our King!\"\n");
   load_a_chat("The Police Legoman tries to keep the peace.\n");
   load_a_chat("The Police Legoman waves his nightstick menacingly.\n");
   move_object(clone_object("/players/llew/Toys/misc/lego"),this_object());
   move_object(clone_object("/players/llew/Toys/misc/whistle"),this_object());
   move_object(clone_object("/players/llew/Toys/quest/legs"),this_object());
   set_alt_name("police_legoman");
}

init() {
   int parts;
   parts=0;
   ::init();
   add_action("finish_quest",quest_verb);
   if(quest_done) return;
   if(present("toy_quest_head",this_player())) parts++;
   if(present("toy_quest_body",this_player())) parts++;
   if(present("toy_quest_arm",this_player())) parts++;
   if(present("toy_quest_crown",this_player())) parts++;
   if(parts > 0 && parts < 4) {
      if(!quest_caller) {
         quest_caller=this_player();
         call_out("some_quest_object",5);
      }
   }
   if(parts==4) {
      if(!quest_caller) {
         set_chat_chance(0);
         set_a_chat_chance(0);
         quest_caller=this_player();
         call_out("quest",5);
      }
   }
}

some_quest_object() {
   if(environment(quest_caller) && environment(quest_caller) == environment()) {
      init_command("blow whistle");
      tell_room(environment(),"The Police Legoman says, \"Hey! You there!\"\n");
      tell_object(quest_caller,"The Police Legoman points at you.\n");
      say("The Police Legoman points at "+quest_caller->query_name()+".\n",quest_caller);
      call_out("some_quest_object2",5);
   }
   else quest_caller=0;
}

some_quest_object2() {
   if(environment(quest_caller) && environment(quest_caller) == environment()) {
      tell_room(environment(),"The Police Legoman says, \"You've got some of our King.  If you bring back\n"+
         "                          the rest of him, I could help put him back together.\"\n");
      call_out("some_quest_object3",5);
   }
   else {
      tell_room(environment(),"The Police Legoman says, \"Hmmph, leave then, but who will save our King?\n");
      quest_caller=0;
   }
}

some_quest_object3() {
   if(environment(quest_caller) && environment(quest_caller) == environment()) {
      tell_room(environment(),"The Police Legoman says, \"Be sure to bring back the head, crown, arm, and body of the King.\"\n");
   }
   quest_caller=0;
}

quest() {
   if(environment(quest_caller) && environment(quest_caller) == environment()) {
      init_command("blow whistle");
      tell_room(environment(),"The Police Legoman says, \"Stop there!\"\n");
      tell_object(quest_caller,"The Police Legoman points at you.\n");
      say("The Police Legoman points at "+quest_caller->query_name()+".\n",quest_caller);
      call_out("quest2",5);
   }
   else quest_caller=0;
}

quest2() {
   if(environment(quest_caller) && environment(quest_caller) == environment()) {
      tell_room(environment(),"The Police Legoman says, \"You've brought back the King!\"\n");
      call_out("quest3",5);
   }
   else {
      tell_room(environment(),"The Police Legoman says, \"No no no!\"\n");
      quest_caller=0;
   }
}

quest3() {
   if(environment(quest_caller) && environment(quest_caller) == environment()) {
      tell_room(environment(),"The Police Legoman says, \"Take these legs and "+quest_verb+" the King.\"\n");
      if(present("toy_quest_legs",this_object())) {
         move_object(present("toy_quest_legs"),environment());
         tell_room(environment(),"The Police Legoman drops lego legs.\n");
      }
      tell_room(environment(),"The Police Legoman says, \"Be sure to do it here, so I may help you.\"\n");
   }
   quest_caller=0;
   quest_done=1;
}

finish_quest(str) {
   if(!quest_done) return 0;
   if(!str || str != "king") {
      notify_fail(capitalize(quest_verb)+" what?\n");
      return 0;
   }
   if(present("toy_quest_legs",this_player())
      && environment(present("toy_quest_legs",this_player())) == this_player()
      && present("toy_quest_head",this_player())
      && environment(present("toy_quest_head",this_player())) == this_player()
      && present("toy_quest_arm",this_player())
      && environment(present("toy_quest_arm",this_player())) == this_player()
      && present("toy_quest_crown",this_player())
      && environment(present("toy_quest_crown",this_player())) == this_player()
      && present("toy_quest_body",this_player())
      && environment(present("toy_quest_body",this_player())) == this_player()
      ) {
      write("You deftly "+quest_verb+" the King.\n\n");
      say(this_player()->query_name()+" fiddles with some lego parts.\n",this_player());
      write("You complete the King of the Legopeople and place him down in front of you.\n");
      say(this_player()->query_name()+" drops the King of the Legopeople.\n",this_player());
      tell_room(environment(),"\nThe Police Legoman says, \"That's it! You've brought back our King!\"\n");
      init_command("blow whistle");
      tell_room(environment(),"The sound of the whistle brings life back to the King\n"+
         "of the Legopeople.  He stands up and walks over to "+this_player()->query_name()+".\n\n");
      tell_room(environment(),"The King says, \"Thank you, "+this_player()->query_name()+", for saving me.\"\n");
      write("The King smiles at you.\n");
      say("The King smiles at "+this_player()->query_name()+".\n",this_player());
      tell_room(environment(),"\nThere is a great cheer throughout the lego section in rejoice of their saved King.\n");
      tell_room(environment(),"The King of the legopeople walks away happily.\n");
      this_player()->set_quest("toy_store");
      destruct(present("toy_quest_legs",this_player()));
      destruct(present("toy_quest_head",this_player()));
      destruct(present("toy_quest_crown",this_player()));
      destruct(present("toy_quest_arm",this_player()));
      destruct(present("toy_quest_body",this_player()));
      write_file("/players/llew/closed/logs/toy_quest",BOLD+ctime(time())+" "+NORM+capitalize(this_player()->query_real_name())+", level "+this_player()->query_level()+", solved the quest.\n");
      return 1;
   }
   write("You don't have all the pieces in your hand.\n");
   return 1;
}
