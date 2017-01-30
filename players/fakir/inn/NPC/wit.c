inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {


     add_money(1850+random(150));
     set_name("wit");
     set_short("Wit Congar");
     set_race( "human");
     set_alias("congar");
     set_long(
              "The village troublemaker is a scrawny man with a sour expression on\n"+
              "his face.  Always poking his nose in other peoples business, he has\n"+
              "none-the-less secured a position on the village council and waits now\n"+
              "for the other members to arrive for a meeting.  He is concerned about\n"+
              "the poor crop harvest this year.\n");
     set_level(17);
     set_ac(11 + random(3));
     set_wc(15 + random(3));
     set_hp(390 + random(40));
     set_al(-400);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("Wit says: This is the worst harvest year ever.\n");
     load_chat("Wit scratches his head and frowns.\n");
     load_a_chat("Wit sidesteps and almost trips.\n");
     load_a_chat("Wit hits you with the back of his hand.\n");
   }
}
