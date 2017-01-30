/* added if(find_player(me)) checks sprinkled
   throughout. 6.19.01 verte */

inherit "obj/monster";

reset(x) { if(x) return;
   set_name("mage");
   set_alias("galileo");
   set_short("Galileo the mage");
   set_long("A very wise and powerful old mage.\n");
   set_level(10);
   set_hp(300);
   set_ac(0);
   set_wc(3);
   set_al(200);
   set_chat_chance(40);
   load_chat("Galileo says:  I know this experiment will work!\n");
   load_chat("Galileo says:  Oh what is it?  I am a very busy man.\n");
   load_chat("Galileo thinks carefully.\n");
   load_chat("Galileo paces back and forth, muttering to himself.\n");
   load_chat("Galileo says:  Yes yes what do you want?\n");
   load_chat("Galileo sighs.\n");
   load_chat("Galileo says:  I have no time for idle chit chat, begone!\n");
   ::reset(0);
}

int check;
string be;

catch_tell(str) {
   string a, b, c;
   be = this_player()->query_real_name();

   if(sscanf(str, "%sorc%stunnels%s", a, b, c) == 3 ||
      sscanf(str, "%sorc%stunnel%s", a, b, c) == 3 ||
      sscanf(str, "%stunnels%s", a, b) == 2 ||
      sscanf(str, "%stunnel%s", a, b) == 2) {
      this_object()->set_chat_chance(0);
     call_out("move_to_quest", 3);
     return 1;
   }
   if(check == 1 && sscanf(str, "%syes%s", a, b) == 2) {
     say("Galileo says:  Very well....it is your life.\n");
     check = 0;
     call_out("move_to_info", 5);
     return 1;
   }
   if(check == 1 && sscanf(str, "%sno%s", a, b) == 2) {
     say("Galileo says:  I think you chose wisely.\n");
     say("Galileo says:  Feel free to come back when you are more trained.\n");
     check = 0;
     set_chat_chance(40);
     return 1;
   }
}

move_to_quest() {
      if(!find_player(be))return;
      if(find_player(be)->query_invis() > 0) {
       say("Galileo says:  You're invisible!  How can I help you if I "+
           "can't see you??\n");
       this_object()->set_chat_chance(40);
       return 1;
     }
      if(find_player(be)->query_ghost() == 1) {
       say("Galileo says:  What??  You're dead!!  Come back when you're "+
           "in better shape.\n");
       this_object()->set_chat_chance(40);
       return 1;
     }
     say("Galileo says: Ahhhhh....you planning on going on a quest?\n");
     say("Galileo says: hmmmmmmmm.\n");
     call_out("test_levels", 5);
     return 1;
}

test_levels() {
      if(!find_player(be)) return;
      if(find_player(be)->query_level() < 10) {
       say("Galileo peers at you quizically.\n");
       say("Galileo says:  I think you are perhaps too inexperienced for this quest.\n");
       say("Galileo says:  Are you sure you want go through with this?\n");
       check = 1;
       return 1;
     } else
     say("Galileo says:  It is a difficult task......\n");
     say("Galileo looks over you carefully.\n");
     say("Galileo says:  Very well....I shall send you on your way.\n");
     call_out("move_to_info", 5);
     return 1;
}

move_to_info() {
     say("Galileo says:  Retrieve the brass rod that was taken from this "+
         "world by\n");
     say("               the wraith.  Then search out the orc tunnels  "+
         "on the northern\n");
     say("               side of the mountain.  There you must find the hidden"+
         " item and\n");
     say("               give it to its rightful owner.  You will then  "+
         "be sent onto the \n");
     say("               final leg of the quest.  Good luck.\n");
     say("\n");
     say("Galileo smirks.\n");
     say("Galileo begins to murmer a spell.\n");
     call_out("move_to_quest2", 10);
     return 1;
}

move_to_quest2() {
     say("Dark clouds begin to form overhead.\n");
     say("Lightning crackles nearby causing you to jump.\n");
     call_out("move_to_quest3", 5);
     return 1;
}

move_to_quest3() {
     say("Galileo raises his hands and speaks in an unknown language.\n");
     call_out("move_to_quest4", 5);
     return 1;
}

move_to_quest4() {
      if(!find_player(be)) return;
      tell_object(find_player(be), "A pain rockets through your body.\n");
      tell_object(find_player(be), "You lose consciousness.\n");
      say(capitalize(be)+" doubles over in agonizing pain and disappears.\n");
      move_object(clone_object("players/molasar/OBJ/qstob1"), find_player(be));
      move_object(find_player(be), "/players/molasar/WORLD/entry");
     /* keep two players from working on same quest */
     say("Galileo disappears in a puff of smoke.\n");
     destruct(this_object());
     return 1;
}

 

