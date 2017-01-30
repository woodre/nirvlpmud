/*
 * New version, does constant
 * dmg rather than insta
 */

#include "../include/ansi.h"
#include "../def.h"

mapping junked;

status get() { return 0; }

reset(x) {
  if(x) return;
  junked=([]);
}

int
alTotal(object x)
{
    int al;
    object c;
    c = first_inventory(x);
    while(c)
    {
      if(c->is_player())
      if(c != this_player()) al += (int)c->query_alignment();
      c = next_inventory(c);
    }

    return al;
}

init()
{
    object x;
    if(!environment()) return;
    if((x=this_player()) && (x->is_player()) &&
       interactive(x) && (x->query_guild_name() == GUILDNAME) &&
       (x->query_level() < 20) && !x->query_ghost())
    {
      holy_blast(this_player());
    }
}

void holy_blast(object Shard)
{
  object y;

  if(!Shard || !present(Shard) || Shard->query_ghost())
  {
    junked[Shard]=0;
    return;
  }

  if(!junked[Shard])
  {
    emit_channel("junk", "The heavens part above "+environment()->short()
                  +" and light floods down...\n");
    junked[Shard]++;
  }
  tell_object(Shard,
    HIW+"\n\tHOLY ENERGY TEARS THROUGH YOUR DEMONIC FORM!\n\n"+NORM);
  tell_room(environment(),
    HIW+"\n\tHOLY ENERGY TEARS THROUGH "+(string)Shard->query_name()
    +"!\n\n"+NORM);

  y = clone_object("/obj/monster");
  y->set_level(1);
  y->set_name("The Gods of Nirvana");
  move_object(y, environment());
  Shard->attacked_by(y);
  Shard->hit_player(100+random(100), "other|good");
  if(y)
    destruct(y);
  call_out("holy_blast", 3, Shard);
}

id(str) { return str == "holy_blast"; }

string
short()
{
    object a;
    if((a = this_player()) && (string)a->query_guild_name() == GUILDNAME)
    return HIW + "The area has been blessed by the gods" + NORM;
}

