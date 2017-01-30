inherit "obj/monster";

object quest_caller;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("sergeant");
   set_level(10);
   set_short("A G.I.Joe Sergeant");
   set_race("action figure");
   set_alias("joe");
   set_long("The Joe Sergeant looks a little distressed.  He wears\n"+
            "a frown over his normally proud smiling face.  He is\n"+
            "carrying an oddly shaped red and yellow torso under his arm.\n");
   set_ac(8);
   set_hp(150);
   set_wc(14);
   set_al(100);
   set_alt_name("joe_sergeant");
   set_chat_chance(15);
   set_a_chat_chance(15);
   load_chat("Sergeant says, \"I'm very upset that I've lost my beret.\"\n");
   load_chat("Sergeant looks around.\n");
   load_chat("Sergeant frowns.\n");
   load_chat("Sergeant says, \"Fall in, men!\"\n");
   load_chat("Sergeant says, \"I really want to have my beret back.\"\n");
   load_a_chat("Sergeant pokes you with his plastic weapon.\n");
   load_a_chat("Sergeant says, \"What are you doing?\"\n");
   load_a_chat("Sergeant says, \"Don't bother me now, I need to get my beret back.\"\n");
   move_object(clone_object("/players/llew/Toys/misc/rand_joe_weapon"),this_object());
   move_object(clone_object("/players/llew/Toys/misc/rand_joe_weapon"),this_object());
}

init() {
   ::init();
   if(present("sergeant_beret",this_player())) {
      quest_caller=this_player();
      call_out("quest",5);
   }
}

quest() {
   if(!quest_caller) return;
   if(environment(quest_caller) && environment(quest_caller) == environment() && present("sergeant_beret",quest_caller)) {
      tell_room(environment(),"Sergeant says, \"Hey! That's my beret.  I've been looking for that.\"\n");
      tell_object(quest_caller,"Sergeant takes the beret from you.\n");
      say("Sergeant takes the beret from "+quest_caller->query_name()+".\n",quest_caller);
/*  Added check for query_worn() - Rumplemintz - 11/24/2007  */
      if(present("sergeant_beret", quest_caller)->query_worn())
         present("sergeant_beret", quest_caller)->remove("sergeant_beret");
      move_object(present("sergeant_beret",quest_caller),this_object());
      init_command("wear beret");
      call_out("quest2",5);
   }
   else quest_caller=0;
}

quest2() {
   tell_room(environment(),"Sergeant says, \"Here, take this that we captured from some evil pirates.\n"+
      "               \"I don't know what it is, myself,\"\n");
   move_object(clone_object("/players/llew/Toys/quest/body.c"),environment());
   tell_room(environment(),"Sergeant drops the lego body.\n");
   quest_caller=0;
}
