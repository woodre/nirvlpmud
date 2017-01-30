inherit "/obj/treasure.c";
reset (arg) {
	set_id("wand");
	set_short("Tox Test Wand");
	set_long("  A wand to play with toxes 'tox_me'.\n");
}
init() {
	::init();
        add_action("toxem","tox_me");
	}
toxem() {
	   this_player()->add_stuffed(5+random(10)); 
         this_player()->add_soaked(5+random(10));
         this_player()->add_toxed(2+random(10)); 
         write("Done!\n");
        return 1;
}
