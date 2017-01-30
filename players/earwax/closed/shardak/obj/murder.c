/* 
   Ring of Murder:
   initially created by balowski, recoded by
   vertebraker 

 - Advantages: 20% chance of 5-10 hit_player damage

 - Disadvantages: 
   ac 0, requires max stealth stat to work best,
   will only work if user is not "tanking",
   unusable by nonguild members
*/

#include "/players/vertebraker/define.h"

#include "../include/def.h"
inherit "/obj/armor.c";

void reset(int arg)
{
    if(arg) return;
    ::reset();
    set_name("ring of murder");
    set_alias("murder ring");
    set_short(RED+"Ring of Murder"+NORM);
    set_long("\
A miniature stilleto is soldered onto this slim silver ring.  The\n\
stiletto travels along the finger on which it is worn, so a clenched\n\
fist would expose less than a nail's length of the sharp point.\n");
    set_weight(1);
    set_value(275);
    set_type("ring");
    set_ac(0);
    silently = 1;
}

status wear(string str)
{
    int w;
    if(!id(str)) return 0;
    if(USER == TP && !worn && (string)TP->query_guild_name() != GUILDNAME)
    {
      write("As you try to wear it, the ring burns "+HIR+"red hot!\n"+NORM);
      TP->hit_player(5 + random(10), "other|fire");
      return 1;
    }
    w = worn;
    ::wear(str);
    if(worn) set_heart_beat(1);
    if(!w && worn)
      write("The ring's blade glimmers menacingly.\n");   
    return 1;
}

status drop()
{
    if(worn) command("remove ring of murder", USER);
    return (int)::drop(silently);
}

status remove(string str)
{
    int w;
    if(!id(str)) return 0;
    w = worn;
    ::remove(str);
    if(!worn) set_heart_beat(0);
    if(w && !worn)
      write("The ring's blade darkens in colour...\n");
    return 1;
}
      
void heart_beat()
{
    object enemy;
    if(!USER || !USER->is_player() || !worn)
    {
      set_heart_beat(0);
      return;
    }
    enemy = (object) USER->query_attack();
    if(!environment(USER)) return;
    if(!enemy || ((object)enemy->query_attack()) == USER || (!present(enemy, environment(USER)))) return;
    if((int)USER->query_attrib("ste") > random(100))
    {
      tell_object(USER,
"You sneak up behind " + enemy->QN + " and stab " + 
objective(enemy) + " in the back with a bladed fist.\n");
      tell_object(enemy,
USER->QN + " sneaks up behind you and stabs you in the back\n\
with a bladed fist.\n");
      USER->remote_say(
USER->QN + " sneaks up behind " + enemy->QN + " and stabs " +
objective(enemy) + " in the back with a bladed fist.\n");
/* Next two lines recoded by beck to use damage types which is better 4/26/02 */
if(enemy->is_player()) enemy->hit_player(1+random(5), "other|vertebraker");
else enemy->hit_player(1+random(5), "other|vertebraker");
/*
      if(enemy->is_player()) enemy->add_hit_point(-(1 + random(5)));
      else enemy->heal_self(-(1 + random(5)));
*/
    }
}
