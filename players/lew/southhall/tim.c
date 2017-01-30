inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

    set_name("tim");
    set_short("Tim");
    set_long("This is Tim Parton.  You wonder what the hell he is bitching\n"+
             "about.  But why not just kill him and not worry about it.");
    set_level(6);
    set_hp(85);
    set_wc(10);
    set_ac(3);
    set_chat_chance(50);
    load_chat("Tim screams: LISTEN YOU FAG!\n");
    load_chat("Tim say: The 'skins' suck.\n");
}
}
