inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("drakganoth");
	set_alt_name("drak'ganoth");
	set_race("orc");
	set_alias("specialist");
	set_short(HIK+"Drak'Ganoth"+NORM+", the "+HIG+"poison"+NORM+" specialist");
	set_long("\
	Drak'Ganoth is a very large and seasoned orc veteran. He\n\
	wears a dark leather hood that hides his face except for\n\
	his bright red eyes and yellow teeth that show through the\n\
	shadows of his hood. Deep scars run through his arms.\n\
	Perhaps you could 'ask about poisons'.\n");
	set_level(99);
	set_hp(99999);
	set_ac(99999);
	set_wc(99999);
	set_al(0);
}