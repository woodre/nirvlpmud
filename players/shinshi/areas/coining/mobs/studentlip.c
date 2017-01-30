inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	object item;
	::reset(arg);
	if(arg) return;
	item = clone_object("/players/shinshi/areas/coining/obj/lipstick.c");
	move_object(item,this_object());
	set_name("student");
	set_alt_name("kiddy");
	set_race("human");
	set_alias("shinshi_lip_mob");
	set_short("A Pre-K Student");
	set_long("\
	This kid is small with messy blonde hair\n\
	and small holes in the knees of his pants. His\n\
	nose drips with snot and he coughs without\n\
	covering his mouth.\n");
	set_level(19);
	set_hp(450 + random(100));
	set_ac(16 + random(5));
	set_wc(28 + random(10));
	set_al(-7000);
	set_chat_chance(2);
	load_chat(query_name()+" coughs loudly without covering his mouth.\n");
	load_chat(query_name()+"'s nose drips with snot.\n");
	add_spell("bite","#MN# "+HIR+"bites "+NORM+"your ankles!\n",
		"#MN# "+HIR+"bites "+NORM+" your ankles.\n",
	35,75,"other|physical");
}
