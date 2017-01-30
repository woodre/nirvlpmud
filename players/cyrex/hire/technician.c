
inherit "obj/monster";
reset(arg) {
        ::reset(arg);
        if(arg) return;

        set_name("technician");
        set_alias("technician");
        set_level(15);
        set_wc(20);
        set_ac(10);
        set_hp(250);
        set_short("a technician");
        set_long("This is one of Cyrex's technician. He has the brain and\n"+
                 "the body to whip your ass if you try to get pass him\n"+
                 "without authorization.\n");
}

init() {
   add_action("block", "up");
   ::init();
}
block() {
   write("The technician prevents you from going up!\n");
   write("The technician grunts: Where the hell do you think your going?!\n");
   write("The technician slaps you!\n");
   return 1;
}

