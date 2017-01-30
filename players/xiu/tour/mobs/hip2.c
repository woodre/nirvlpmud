inherit "/obj/monster";
#include <ansi.h>

reset(arg)
{
if(arg) return;
    ::reset(arg);
    if(arg) return;
set_name("A dirty hippy");
set_alias("hippy");
set_short("A dirty Hippy");
set_long("This is a spaced out hippy with thick dreadlocks that\n"+
"hang to the middle of his back. He reaks of patchouli\n"+
"and his blood shot eyes stare off somewhere into space.\n");
set_level(19);
    set_al(-11);
set_wc(19);
    set_chat_chance(10);
load_chat("A dirty hippy stares off into space.\n");
load_chat("A dirty hippy adjusts one of his dreadlocks.\n");
    add_money(random(200)+600);
}
