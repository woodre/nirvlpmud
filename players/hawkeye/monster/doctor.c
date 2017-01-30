inherit "/obj/monster";
object ob;

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "doctor" );
     set_short("Witch Doctor");
   set_long("This is the leader of a tribe of natives of this jungle.\n" +
            "He is wearing a small grass skirt which you cant help but\n" +
        "laugh when you see. Dancing all about he looks like a small frog.\n" +
       "The stone he has in his possesion is said to be magical.\n");
     set_alias("doctor");
     set_level(20);
     set_ac(17);
     set_wc(30);
     set_hp(550);
     set_al(-1000);
     set_aggressive(0);
    set_a_chat_chance(35);
  load_a_chat("The Witch Doctor says: Unga Bunga, Bhaw!\n");
   load_a_chat("The Witch Doctor dances around you in circles\n");
load_a_chat("The Witch Doctor chants loudly unleashing a lightning bolt towards your head!\n");
  ob = clone_object("players/hawkeye/items/stone.c");
move_object(ob, this_object());
     money = (1000);
   }
}
