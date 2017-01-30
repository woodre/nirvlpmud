inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

    set_name("wade");
    set_short("Wade Cross");
    set_long("Some tall dude that lives here.  He is way too happy.\n"+
             "So just kill him.  Watch out though.  He has a powerfull\n"+
             "moon.\n");
    set_level(8);
    set_wc(5);
    set_ac(4);
    set_chance(30);
    set_spell_mess1("Wade bends over and moons you.\n");
    set_spell_mess2("Wade bends over and moons you.\n");
    set_spell_dam(15);
    set_chat_chance(50);
    load_chat("Wade screams: SHUT THE F**K UP!\n");
    load_chat("Wade says: Hey Murry. Look at my sack.\n");
    load_chat("Wade pulls his pants down and walks around letting\n"+
              "it all hang out.\n"+
              "You get really sick.\n");
}
}
