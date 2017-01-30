#include "/players/fred/ansi.h"

object *in_arena, *rooms, plr, atk;
int a,b;
string *died, *nms;

void reset(mixed arg){
  if(arg) return;

  rooms =({
    "players/fred/closed/bloodfist/r/arena_room1",
    "players/fred/closed/bloodfist/r/arena_room2",
    "players/fred/closed/bloodfist/r/arena_room3",
    "players/fred/closed/bloodfist/r/arena_room4",
  });

  set_heart_beat(1);

  in_arena = ({ });
  died = ({ });
  nms =({ "Jethro Hunter", "Giant Desert Fiend", "Christian", "Trugen",
    "Atheos", "Bruteus Faust", "Haemon", "Erilon", });
}

/* Used with the arena in reclaiming corpses */
add_dead(string str){
  if(!query_dead(str))
    return died += ({ str, });
  return 0;
}

rm_dead(string str){
  if(query_dead(str))
    return died -= ({ str, });
  return 0;
}

query_dead(string str){
  if(!died || !sizeof(died)) return 0;
  if(index(died, str) > -1) return str;
  return 0;
}

void move_arena_contents() 
{
  int a,b,c;
  object *inv;
  for(a = 0; a < 4; a++)
  {
    inv = all_inventory(rooms[a]);
    if((c = sizeof(inv) > 0))
    {
      for(b = 0; b < c; b++)
      {
        if(call_other(inv[b], "id", "bftrial_mob"))
        {
          move_object(inv[b], "/room/void.c");
          destruct(inv[b]);
        }
        else if(call_other(inv[b], "id", "white tunnel"))
        {
          move_object(inv[b], "/room/void.c");  
        }
        else if(call_other(inv[b], "id", "bftrial_mob_erilon"))
        {
          move_object(inv[b], "/players/fred/closed/bloodfist/r/meeting.c");
        }
        else if(call_other(inv[b], "id", "corpse"))
        {
          inv[b]->add_decay(100);
          move_object(inv[b], "/players/fred/closed/bloodfist/r/backroom.c"); 
        }
        else
        {
          move_object(inv[b], "/players/fred/closed/bloodfist/r/backroom.c");
        }
      }
    }
    tell_room(rooms[a],
      "\nA few warriors run by you quickly as they clean up the arena.\n"+
      "A warrior says, \"Go bow to Atheos after you feel better.\"\n\n");
  }
}

mixed person(object who, int how){
  object gob;
  if(!who) return 0;
  if(how == 1) /* remove */
  {
    if(index(in_arena, who) > -1)
    {
      if(who->query_ghost() && !query_dead(who->query_real_name()))
      {
        gob = present("bloodfist_gob", who);
        if(gob)  /* LOG IT */
        {
          write_file("/players/fred/closed/bloodfist/log/arena_deaths",
          ctime()[4..23]+"   "+
            pad(capitalize((string)who->query_real_name()), 13)+"[");
          if(who->query_extra_level() > 0)
          {
            write_file("/players/fred/closed/bloodfist/log/arena_deaths",
            pad(who->query_level()+"+"+who->query_extra_level(),7)+"]");
          }
          else {
            write_file("/players/fred/closed/bloodfist/log/arena_deaths",
            pad((string)who->query_level()+"]",7));
          }
          write_file("/players/fred/closed/bloodfist/log/arena_deaths",
            " was defeated by "+nms[(int)gob->query_glevel()]+".\n");
        }

     /* move_arena_contents(); */
        add_dead(who->query_real_name());
      }
      return in_arena -= ({ who, });
    }
  }
  else if(how == 2) /* add */
  {
    if(index(in_arena, who) < 0 && who->is_player())
    {
      if(!who->query_ghost() && query_dead(who->query_real_name()))
        rm_dead(who->query_real_name());
      return in_arena += ({ who, });
    }
  }
  return 0;
}

mixed occupants(){ if(sizeof(in_arena) > 0) return in_arena; return 0; }

mixed gfp(){ if(sizeof(in_arena) == 1) return in_arena[0]; return 0; }

int clean_arena()
{
  int a,b,c;
  object *inv;
  if(occupants()) return 0;
  for(a = 0; a < 4; a++)
  {
    inv = all_inventory(rooms[a]);
    if((c = sizeof(inv) > 0))
    {
      for(b = 0; b < c; b++)
      {
        if(call_other(inv[b], "id", "bftrial_mob_atheos"))
        {
          move_object(inv[b], "/players/fred/closed/bloodfist/r/arena.c");
        }
        else if(call_other(inv[b], "id", "bftrial_mob_erilon"))
        {
          move_object(inv[b], "/players/fred/closed/bloodfist/r/meeting.c");
        }
        else if(call_other(inv[b], "id", "bftrial_mob"))
        {
          move_object(inv[b], "room/void");
          destruct(inv[b]);
        }
        else
        {
          move_object(inv[b], "/players/fred/closed/bloodfist/r/backroom.c");
        }
      }
    }
  }
  return 1;
}

heart_beat()
{
  if(!(plr = gfp())) return;
  if(!(atk = (object)plr->query_attack())) return;
  a = (plr->query_hp() * 10) / plr->query_mhp();
  b = (atk->query_hp() * 10) / atk->query_mhp();
  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c",
    BOLD+BLK+ "[A]"+NORM+HIR+">>> "+NORM+
    pad(capitalize((string)plr->query_real_name()),14)+
    pad(a+"/10",8)+BOLD+BLK+"VS   "+NORM);
  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c",
    pad(atk->query_name(),14)+
    pad(b+"/10",8)+HIR+"<<<\n"+NORM);
}

