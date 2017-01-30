#include <ansi.h>
inherit "/obj/treasure.c";
reset (arg) {
	set_id("setter");
	set_short("Guild And Race Setter");
	set_long("  This is a little tool that you can use to change\n"+
                 "your guild name.  To use it just 'title_me'.\n");
}
init() {
	::init();
        add_action("titler","title_me");
	if(environment() && interactive(environment()))
	if(this_player()->query_real_name() != "tallosspawn") {
		write("Sorry, but you are not Tallosspawn. \n");
		destruct (this_object());
		return 1;
	}
}
titler() {
	if(this_player()->query_level() < 20) { return 1; }
         this_player()->set_guild_name("Barbarian"); 
         this_player()->set_race("Lacky");
        return 1;
}
drop() { return 1;}
/* This is a copy of Fred's guildset.c.  Thanks Fred. */
