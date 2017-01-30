inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object("/players/daranath/qualtor/wep/spik_club.c"),this_object());

     set_name("Huge Ogre");
     set_short("A huge ogre with a spiked club");
     set_alias("ogre");
     set_race("giant");
     set_gender("male");
     set_long("The Huge Ogre towers over everything else in this room. He\n"+
              "is an impressive specimen, eleven feet tall and every inch\n"+
              "packed with muscle. A massive club bounces easily upon\n"+
              "one shoulder, as if he is eager to put it to use.\n");
     set_level(20);

     init_command("wield club");

     set_ac(18);
     set_wc(30 + random(4));
     set_hp(650 + random(60));
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(25);
     load_chat("The Huge Ogre growls: Get out!\n");
     load_a_chat("Huge Ogre growls at you in a angry manner.\n");
     load_a_chat("Huge Ogre hits you with a bone crushing sound.\n");

   }
}
