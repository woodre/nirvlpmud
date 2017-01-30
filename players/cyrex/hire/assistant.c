inherit "obj/monster";
reset(arg) {
        ::reset(arg);
        if(arg) return;

        set_name("assistant");
        set_alias("assistant");
        set_level(16);
        set_wc(20);
        set_ac(10);
        set_hp(250);
        set_short("an assistant of Cyrex");
        set_long("This is one of Cyrex's assistant. He handles all the\n"+
                "business matters that needs to be done. He is built and\n"+
                "can pound your ass if you try to mess up Cyrex's business.\n");
  move_object(clone_object("players/cyrex/card.c"),this_object());
        set_chat_chance(20);
        load_chat("Assistant says: How the hell did you get up here?!\n");
        load_chat("Assistant shouts for the technician.\n");
        set_a_chat_chance(20);
        load_a_chat("Assistant screams: CYREX! HELP ME!\n");
        load_a_chat("Assistant says: You'll never get in!\n");
        load_a_chat("The assistant laughs loudly!\n");
}

init() {
   add_action("block", "up");
   ::init();
}
block() {
   write("The assistant prevents you from going up!\n");
   write("The assistant grunts: Where the hell do you think your going?!\n");
   write("The assistant smacks you across the face!\n");
   return 1;
}
