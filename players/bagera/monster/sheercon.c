inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
       object item;
   item = clone_object("/players/bagera/weapons/claw.c");
move_object(item, this_object());
command("wield claw", this_object());
   set_name("Shere Khan");
   set_alias("shere khan");
   set_alt_name("shere");
   set_short("Shere Khan, a huge tiger");
  set_long("Shere Khan is a huge African tiger. His stripes are bright\n"+
           "and prominent. He is stalking through the tall grass, just\n"+
           "waiting to pounce on his prey. His claws are drawn and\n"+
           "his teeth bared. He is searching the forest for Mowgli,\n"+
           "the man-cub.\n");
   set_aggressive(2);
  set_ac(17);
   set_wc(30);
   set_level(21);
   set_race("animal");
   set_hp(530);
   set_al(-1000);
   set_chat_chance(10);
  load_chat("Shere Khan says: I'll find that man-cub yet.\n");
   set_chance(30);
   set_a_chat_chance(50);
   load_a_chat("Shere Khan sinks her teeth deep into your arm, ripping a piece of flesh out!\n");
   load_a_chat("Shere Khan claws at your face, shredding it to pulp!\n");
   set_spell_dam(90);
   set_spell_mess1("Shere Khan slashes into his enemy with his massive claws!\n");
   set_spell_mess2("Shere Khan slashes into you with his massive claws!\n");
  }
 }
