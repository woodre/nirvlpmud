inherit "/obj/treasure.c";
#include "/players/fred/ansi.h"
#define TP this_player()

reset (arg) {
	set_id("thingy");
	set_short("Title Changer Thingy");
	set_long("  This is a little tool that you can use to change\n"+
                 "your guild name.  To use it just 'title_me'.\n");
}
init() {
	::init();
        add_action("check","check");
	}


check(){
  int lvl, xlvl, woo, foo, cando;
  xlvl = TP->query_extra_level();
  lvl = TP->query_level();
    if(xlvl < 1)  
       woo = call_other("room/adv_guild","get_next_exp",lvl-1);
    if(xlvl > 0)
       woo = call_other("room/exlv_guild","get_next_exp",xlvl-1);
     write(woo+"\n");
    if(xlvl < 1)  
       foo = call_other("room/adv_guild","get_next_exp",lvl);
    if(xlvl > 0)
       foo = call_other("room/exlv_guild","get_next_exp",xlvl);
       write(foo+"\n");
    if(xlvl < 1)  
       cando = TP->query_exp() - call_other("room/adv_guild","get_next_exp",lvl-1);
    if(xlvl > 0)
       cando = TP->query_exp() - call_other("room/exlv_guild","get_next_exp",xlvl-1);
    write(cando+"\n");
    write(cando - (foo-woo));
    write("\n");
    return 1;
}
