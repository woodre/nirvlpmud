 inherit "/obj/monster";
  reset(arg) {
    ::reset(arg);
    if (!arg) {
    object ob;
  ob = clone_object("/players/arrina/treas/onyx.c");
 move_object(ob,this_object());
         set_name("guard");
      set_short("Ghost Guard");
      set_race( "spirit");
      set_long("A spectral guard who has had the lifeblood sucked out\n"+
        "of his body, leaving only this ghostly apparition.\n");
      set_level(13);
      set_ac(8);
      set_wc(17);
      set_hp(220);
      set_al(-900);
      set_aggressive(0);
      set_chat_chance(20);
       load_chat("Guard says: We used to protect this castle.\n");
      load_chat("The guard is barely visible as he weaves around you.\n");
      load_chat("Guard says: Some dark force has taken my soul.\n");
      load_chat("Guard says: This was our home..we failed our master.\n");
    }
 }
