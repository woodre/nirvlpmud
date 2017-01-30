inherit "obj/monster";

reset() {
   set_name("shir-ta the seer");
   set_alias("seer");
   set_short("Shir-ta the Seer");
   set_long("An old stooped man. His visage is gut wrenching to behold.\n"
+           "He stumbles barefoot in a torn dirt stained robe. Most\n"
+           "shocking is his eyes, or rather lack of them. As a seer, his\n"
+           "eyes were put out at birth. He is doomed forever to see into the\n"
+           "mists of time.\n");
   set_level(2);
   set_hp(15);
   set_ac(1);
   set_wc(5);
   set_al(300);
   set_chat_chance(20);
   load_chat("Seer growls: Ask and I shall tell thee what will be!\n");
   load_chat("Seer scowls at you, staring with his sightless eyes.\n");
   load_chat("Seer moans: I know what will be, ask and I will tell.\n");
   ::reset(0);
}

catch_tell(str) {
   string a, b, c;
   if(sscanf(str, "%sFuture%s", a, b) == 2 ||
      sscanf(str, "%sfuture%s", a, b) == 2) {
      this_object()->set_chat_chance(0);
      call_out("move_to_info", 3);
      return 1;
   }
   say("Seer looks at you a second, then continues his stumbling.\n");
   return 1;
}

move_to_info() {
   say("The Seer stops, and stands straight up, gazing at you from his\n");
   say("sockets.\n\n");
   say("Seer says: I see two swords!!!!\n");
   say("Seer says: The first, red with the blood of Medenna, and black\n");
   say("           with the evil of Azrah.\n");
   say("Seer says: The second sings with the voice of the prophet.\n");
   say("           Its blade the champion of our city.\n");
   say("Seer says: One must burn in the pit of Ra, so that the other might\n");
   say("           be freed, and in turn our people with it.\n");
    this_object()->set_chat_chance(20);
   return 1;
}
