 inherit "/obj/monster";
  reset(arg) {
    ::reset(arg);
    if (!arg) {
  object ob;
     ob = clone_object("/players/arrina/treas/tusk.c");
 move_object(ob,this_object());
   ob = clone_object("/players/arrina/treas/tusk.c");
 move_object(ob,this_object());
       set_name("beast");
      set_short("Sorceror's Beast");
      set_race( "creature");
      set_long("A huge creature, the face pale and hairless, the\n"+
        "nose distended and flattened.  Long, curved tusks extend\n"+
        "up from the lower lip, and it has fangs like a wolf.\n");
      set_level(19);
      set_ac(16);
      set_wc(28);
      set_hp(475);
      set_al(-1000);
      set_aggressive(0);
      set_chat_chance(20);
       load_chat("An eerie, high-pitched scream echos through the cave.\n");
       load_chat("You smell a foul odor emanating from the cave depths.\n");
       load_chat("The darkness closes in on you, surrounding you with fear!\n");
       }
 }
