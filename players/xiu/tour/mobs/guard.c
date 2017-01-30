inherit "/obj/monster";
#include <ansi.h>

reset(arg)
{
if(arg) return;
    ::reset(arg);
    if(arg) return;
set_name("guard");
set_alias("security");
set_short("A Security Guard");
set_long("A buff security guard stands at attention.\n"+
"His shirt says SECURITY in bold letters on the back.\n"+
"He seems to take his job very seriously.\n");
set_level(20);
set_hp(600);
    set_al(-11);
set_wc(35);
set_ac(17);
add_spell("punch",
"#MN#'s punches you in the stomach!\n",
"#MN# calls for backup.\n"+
"#MN# delivers a swift punch to his opponent.\n",
12,18,"physical",7);
    set_chat_chance(10);
load_chat("The security guard checks backstage passes.\n");
load_chat("The security guard glances across the nearby crowd.\n");
 add_money(random(200)+5000);
}
