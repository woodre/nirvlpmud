#include "def.h"
cmd_phase(str)
{
  object map;
  object *players;
  object *room_list;
  string *names;
  int i;

  room_list=ROOMS;
  players=({ });

  names=explode(str,",");
  for(i=0; i < sizeof(names); i++)
  {
    object curr;
    curr=find_player(names[i]);
    if(!curr)
    {
      write("Player "+names[i]+" not found.\n");
      return 1;
    }
    else
      players+=({ curr });
  }
  map=clone_object(PATH+"map.c");
  map->set_players(players);
  for(i=0; i < sizeof(players); i++)
  {
    move_object(players[i],(object)map->query_room(PATH+ (room_list[random(sizeof(room_list))]) ));
    write(pad((string)players[i]->query_name(),20)+" -> "+(string)environment(players[i])->short()+".\n");
    tell_object(players[i],"Your vision blurs for a moment.  You blink your eyes to clear them.\nWhen you open them again, you see you are somewhere else.\n");
    command("look",players[i]);
  }
  move_object(map,this_player());
  return 1;
}
