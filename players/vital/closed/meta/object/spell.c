#include "../def.h"

int hp_cost, red_cost, cre_cost, coe_cost, tel_cost, far_cost;

void
set_hp_cost(int x)
{
    hp_cost = x;   
}

void
set_red_cost(int x)
{
    red_cost = x;
}

void
set_cre_cost(int x)
{
    cre_cost = x;
}

void
set_coe_cost(int x)
{
    coe_cost = x;
}

void
set_tel_cost(int x)
{
    tel_cost = x;
}

void
set_far_cost(int x)
{
    far_cost = x;
}

void
execute_spell()
{
    this_player()->add_hit_point(-hp_cost);
    if(red_cost) GOBJ->add_mental_point("red",-red_cost);
    if(cre_cost) GOBJ->add_mental_point("cre",-cre_cost);
    if(coe_cost) GOBJ->add_mental_point("coe",-coe_cost);
    if(tel_cost) GOBJ->add_mental_point("tel",-tel_cost);
    if(far_cost) GOBJ->add_mental_point("far",-far_cost);
    if(((int)this_player()->query_hp() < 1) ||
       !GOBJ->query_mp("red") ||
       !GOBJ->query_mp("cre") ||
       !GOBJ->query_mp("coe") ||
       !GOBJ->query_mp("tel") ||
       !GOBJ->query_mp("far"))
     if((int)this_player()->query_level() < 20) 
       GOBJ->psychic_suicide();
}

status
guild_wizard(object w)
{
    int i;  string r;
    if(!w) return 0;
    r = (string)w->query_real_name();
    if(member_array(r, GWIZ) != -1) return 1;
    else return 0;
}
