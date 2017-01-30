inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("floyd");
   set_race("human");
   set_alias("floyd");
      set_short("Dr. Floyd");
     set_long("Dr. Floyd is in charge of the whole space mission.  His silvery suit\n"+
              "has some signs which recall his governmental affiliation.  He is a \n"+
              "distinguished member of the National Astronautical Council. A person\n"+
              "which does not speak much yet of a great charisma.  All the briefings\n"+
              "he coordinates always reach their goal. Slim and tall, he stands about\n"+
              "6 feet and weights about 140 lbs.\n");
   set_level(15);
   set_hp(250);
   set_al(0);
   set_wc(20);
   set_ac(12);
   set_chat_chance(10);
   load_chat("Dr. Floyd mumbles:  Mr. Halvorsen is really a great guy.\n");
   load_chat("Dr. Floyd mumbles:  Lemme see this Monolith, then we will take a decision.\n");
   move_object(clone_object("/players/francesco/2001/items/envelope.c"),this_object());
}
