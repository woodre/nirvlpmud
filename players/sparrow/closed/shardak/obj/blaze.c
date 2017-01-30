#include "../def.h"
#include "/players/vertebraker/ansi.h"

int milkduds;

object caster, where;

#define DAMAGE 15 + random(9)


void start_shadow(object ob)
{
    where = ob;
    shadow(ob, 1);
    call_out("heyheyhey", 5);
}

void end_shadow()
{
    shadow(where, 0);
    destruct(this_object());
}

void heyheyhey()  /* it's fat albert ! */
{
    int    x, race;
    object *local_users, *criminals;
    string tmp, narf, msg;

    criminals = ({ });
    local_users = all_inventory(where);

    for(x = 0; x < sizeof(local_users); x ++)
      if((local_users[x]->is_player() && (local_users[x]->query_pl_k() || local_users[x]->query_fight_area())) || local_users[x]->is_npc())
        criminals += ({ local_users[x] });    

    milkduds ++;

    if(!caster || milkduds > 19 || !present(caster, where))
    {
      tell_room(where, "\
The flames die down, taking with them the warmth\n\
that has permeated the area...\n\
You are left feeling with an emptyness and a chill...\n");
      for(x = 0; x < sizeof(criminals); x ++)
        if((mixed)criminals[x]->query_guild_name() != GUILDNAME)
          criminals[x]->hit_player(8 + random(8), "other|fire");
      end_shadow();
      destruct(this_object());
      return;
    }

    if(0 == random(2))
    {
      if(0 == random(3)) 
        msg = "Waves of flame roll over the room...";
      else if(0 == random(3))
        msg = "The unholy blaze rages on...";
      else if(0 == random(3))
        msg = "Flames of darkness crackle and burn...";
      else if(0 == random(3))
        msg = "The blaze spreads across the area...";
      else
        msg = "Fire burns and crackles...";
      tell_room(where, RED + "\t" + msg + NORM + "\n");
      for(x = 0; x < sizeof(criminals); x++)
        if(!random(2))
        {
          tmp = (string)criminals[x]->query_race();

          if(!tmp) tmp = "heh";
          if(sscanf(tmp,"%sfire%s",narf,narf) || 
             sscanf(tmp,"%sflame%s",narf,narf) ||
             sscanf(tmp,"%shell%s",narf,narf) || 
             tmp == "efreeti" ||
             tmp == "ifrit" || tmp == "efreet") race = 1;

          tell_object(criminals[x], "The flames " +
(race ? "warm" : "scorch") + " your flesh...\n");

          tell_room(where, 
"The flames " + (race ? "warm" : "scorch") + " " +
(string)criminals[x]->query_name() + "...\n", ({ criminals[x] }));

            if((string)criminals[x]->query_guild_name() != GUILDNAME)
            criminals[x]->hit_player(DAMAGE, "other|fire");
            else criminals[x]->hit_player(DAMAGE - 8, "other|fire");
        }
    }

    call_out("heyheyhey", 3);   
}   
     
void set_caster(object ob)
{
    caster = ob;
}

string short()
{
return where->short() + RED + " (Blazing)" + NORM;
}

mixed long(string str)
{
    if(!str)
return where->long() + write(RED + "\n\tThe area is burning with an unholy blaze...\n" + NORM);
    else return where->long(str);
}

status query_shardak_blaze() { return 1; }
