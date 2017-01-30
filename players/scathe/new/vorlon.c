inherit "/obj/monster";
reset(arg)   {
   ::reset(arg);
   if(!arg)  {

   set_name("Kosh");
   set_short("Kosh, The Vorlon Ambassador");
   set_race("vorlon");
   set_alias("vorlon");
   set_long("Ambassador Kosh is the mysterious and reclusive representative\n"+
      "of the powerful Vorlon Empire.  Kosh is inside an encounter suit\n"+
      "that is multicolored and prevents you from seeing what he really\n"+
      "looks like.  He turns the head of the encounter suit to watch you\n"+
      "as his viewing aperture changes size.\n");
   set_level(20);
   set_ac(17);
   set_wc(30);
   set_hp(500);
   set_al(250);
   set_aggressive(0);
   set_chat_chance(20);
   set_a_chat_chance(25);
   load_chat("You are not ready.\n");
   load_chat("You do not understand.  Understanding is a three edged sword.\n");
   load_a_chat("You are irrelevant!\n");
   load_a_chat("Go before you die.\n");
   }
}
