inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

     set_name("construct");
     set_short("A Magikal Construct");
     set_race("golem");
     set_gender("creature");
     set_long("Roughly human shaped, but bearing no facial features at all,\n"+
              "the construct appears to be made of a grey clay material.\n");
     set_level(18);
     set_ac(17);
     set_wc(25);
     set_hp(450 + random(100));
     set_al(-800);
     set_aggressive(0);
     set_chat_chance(15);
     set_a_chat_chance(30);
     load_chat("The construct moves about the area.\n");
     load_chat("The magikal creature turns torwards you.\n");
     load_a_chat("The construct attacks with blinding speed.\n");
     load_a_chat("The construct attacks without fear.\n");

   }
}
