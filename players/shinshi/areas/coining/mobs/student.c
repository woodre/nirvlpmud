inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	write_file("/players/shinshi/logs/spawn.txt", "Student(reg) spawned" + ctime()[4..15] + "\n");
	set_name("student");
	set_alt_name("kiddy");
	set_race("human");
	set_alias("shinshi_reg_mob");
	set_short("A Pre-K Student");
	set_long("\
	This kid is small with messy red hair\n\
	and small holes in the knees of his pants. His\n\
	nose drips with snot and he coughs without\n\
	covering his mouth.\n");
	set_level(19);
	set_hp(450 + random(100));
	set_ac(16 + random(5));
	set_wc(28 + random(10));
	set_al(-7000);
	set_chat_chance(2);
	load_chat(query_name()+" coughs loudly without covering her mouth.\n");
	load_chat(query_name()+"'s nose drips with snot.\n");
	add_spell("bite","#MN# "+HIR+"bites "+NORM+" your ankles!\n",
		"#MN# "+HIR+"bites "+NORM+" your ankles.\n",
	35,75,"other|physical");
}
