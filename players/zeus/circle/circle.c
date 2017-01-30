#include "defs.h"

#include "/players/zeus/circle/obj/variables.h"
#include "/players/zeus/circle/obj/weapon.h"
#include "/players/zeus/circle/obj/armor.h"
#include "/players/zeus/circle/obj/id.h"
#include "/players/zeus/circle/obj/reset.h"
#include "/players/zeus/circle/obj/hb.h"
#include "/players/zeus/circle/obj/nightmares.h"
#include "/players/zeus/circle/obj/function.h"
#include "/players/zeus/circle/obj/environment_check.h"
#include "/players/zeus/circle/obj/endurance_check.h"
#include "/players/zeus/circle/obj/ecolor.h"
#include "/players/zeus/circle/obj/light_check.h"
#include "/players/zeus/circle/obj/energy_check.h"
#include "/players/zeus/circle/obj/spell_failure.h"
#include "/players/zeus/circle/obj/settings.h"
#include "/players/zeus/circle/obj/quit.h"
#include "/players/zeus/circle/obj/init.h"
#include "/players/zeus/circle/power/chan.h"
#include "/players/zeus/circle/power/mud_spells.h"
#include "/players/zeus/circle/power/guild_updates.h"
#include "/players/zeus/circle/power/dark_ass.h"
#include "/players/zeus/circle/power/misc_funcs.h"
   /* verte monitor code */
/*
#include "/players/zeus/circle/obj/print_monitor.h"
*/

/* 03/24/06 Earwax: switched this to use lib guild code */
/*
query_auto_load(){ return "/players/guilds/fallen/circle.c:"; }
*/


void
print_monitor()
{
    int a, b, c, d, e, f, g, h, i, j;
    string bonk, k;
    object bzz;

    if(custom_monitor)
    {
      tell_object(USER, MASTER->m_decode(custom_monitor) + "\n");
      return;
    }
    else 
      if(bonk = (string)USER->query_monitor_string())
    {
      tell_object(USER, (string)USER->m_decode(bonk) + "\n");
      custom_monitor = bonk;
      save_circle(1);
      return;
    }

    a = (int)USER->query_level();
    b = (int)USER->query_hp();
    c = (int)USER->query_mhp();
    d = (int)USER->query_spell_point();
    e = (int)USER->query_msp();
    f = (int)USER->query_intoxination()*100 / ((int)USER->query_max_intox());
    g = (int)USER->query_stuffed()*100 / ((int)USER->query_max_stuff());
    h = (int)USER->query_soaked()*100 / ((int)USER->query_max_soak());
    i = (int)USER->query_infuse()*100 / ((a*9)/2);
    j = (int)MASTER->endurance_monitor();

    if(!(bzz = (object)USER->query_attack())) k = 0;

    else
      k = "AHP: " + 
       (((int)bzz->query_hp() * 10) / ((int)bzz->query_mhp())) + 
       "/10";

    tell_object(USER, 
      RED + "[fallen]" + NORM +
      " HP: " + b + "/" + c +"  SP: " + d + "/" + e + "  E: " + j +
      "% ["+f+"% "+g+"% "+h+"% "+i+"%] " + (k ? k : "") + "\n");
}

status
guild_monitor_only()
{
    return 1;
}
