
inherit "obj/monster";

reset(x) { if(x) return;
     set_name("prospector");
     set_alias("jedediah");
     set_short("An old prospector");
     set_level(10);
     set_hp(150);
     set_al(90);
     set_long("An old bent over prospector dressed in dusty garb.\n");
     set_ac(0);
     set_chat_chance(30);
     load_chat("The old prospector says:  I know there be gold here fer "+
         "as sure as my name is Jedediah.\n");
     load_chat("The old prospector digs away with his stonecutter.\n");
     load_chat("The old prospector says:  Yer not trying to steal my loot "+
         "is you?\n");
     load_chat("The old prospector looks at you suspiciously.\n");
     ::reset(0);
}

