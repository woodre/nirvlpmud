#include <ansi.h>
cmd_showdown(str)
{
  int rank, hp, sp;
  object tar, room, chatob;
  rank = (int)this_player()->query_guild_rank();
  if(rank < 7) {
    write("You have not gained enough power to bend the darkness in this way! "+HIC+"["+HIK+"Rank 7"+HIC+"]"+NORM+"\n");
	return 1;
  }
  sp = (int)this_player()->query_sp();
  hp = (int)this_player()->query_hp();
  if(sp < 50) {
    write("You lack the necessary spirit energy to invoke a showdown. "+HIK+"["+HIC+"50"+HIK+"]"+NORM+"\n");
    return 1;
  }
  if(hp < 51) {
    write("Invoking a showdown now would kill you due to the strain on your soul. "+HIK+"["+HIC+"50"+HIK+"]"+NORM+"\n");
    return 1;
  }
  if((int)environment(this_player())->query_light() > 0) {
    write("The room is too bright to open a portal to the "+BOLD+"S"+HIK+"hadow "+NORM+BOLD+"P"+HIK+"lane"+NORM+"!\n");  
    return 1;
  }
  tar = this_player()->query_attack();
  if(!tar) {
    write("You must initiate combat before you can request a showdown!\n");
	return 1;
  }
  room = find_object("/players/sparrow/closed/guild/obj/showdown.c");
  if(!room || room->query_occupied()) {
    room = clone_object("/players/sparrow/closed/guild/obj/showdown.c");
  }
  tell_room(environment(this_player()),
    "\n\nA large portal of "+HIK+"swirling shadows"+NORM+" opens up!\n");
  tell_room(environment(this_player()),
    this_player()->query_name()+" is sucked into the "+BOLD+"portal"+NORM+"!\n"+
    tar->query_name()+" is sucked into the "+BOLD+"portal"+NORM+"!\n");	
  tell_room(environment(this_player()),
    "The "+BOLD+"portal"+NORM+" suddenly collapses in upon itself, disappearing from existance!\n\n\n");
  room->set_origin(file_name(environment(this_player())));
  move_object(this_player(), room);
  move_object(tar, room);
  tell_room(environment(this_player()),
    "You suddenly find yourself elsewhere!\n");
  room->set_occupied();
  room->set_combatants(this_player(), tar);
  this_player()->add_hp(-50);
  this_player()->add_sp(-50);
  chatob = "/players/sparrow/closed/guild/obj/chatob";
  chatob->emote("has initiated a showdown with "+tar->query_name()+"!");
  return 1;
}