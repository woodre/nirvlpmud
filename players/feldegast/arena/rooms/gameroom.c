/******************************************************************
File: /players/feldegast/arena/rooms/gameroom.c
Author: Feldegast/CAS
Date: 8/13/99
Description: A virtual room where players can assemble for a spar.
There will be a way to create these rooms in ~/arena/rooms/inner.c
******************************************************************/
#include "/players/feldegast/defines.h"

inherit ROOM;


string maker;
string *invites;
int ready;

object arena;
int arena_type;

void reset(int arg)
{
  if(arg) return;
  set_short("Gameroom");
  set_no_fight(1);
  set_light(1);
  set_no_teleport(1);
}

void init()
{
  if(!maker) maker=(string)this_player()->query_real_name();


  add_action("cmd_enter","enter");
  add_action("cmd_leave","leave");

  if(maker==(string)this_player()->query_real_name() || (int)this_player()->query_level() > 39)
  {
    add_action("cmd_invite","invite");
    add_action("cmd_ready","ready");
    add_action("cmd_arena","arena");
  }
}

void long()
{
  int i;
  write("Maker: "+capitalize(maker)+"\n");
  write("Arena: ");
  if(arena_type==0) write("The Pit\n");
  if(arena_type==1) write("Feldaria\n");
  write("Invitees: ");
  if(invites)
    for(i=0; i < sizeof(invites); i++)
      write(invites[i]);
  else
    write("All\n");
  write("\n");
  write(
"  This is a simple chamber deep beneath the coliseum.  A pair of\n\
tapestries depicting great victories of the gladiators of old hang\n\
from the walls perpendicular to the entrance.  Opposite of the\n\
entrance is a doorway shrouded in shadow that leads into an arena.\n"
  );

  if(maker==(string)this_player()->query_real_name() || (int)this_player()->query_level() > 39)
    write("Commands: leave, enter, arena_help, invite, uninvite, ready\n");
  else
    write("Commands: leave, enter\n");
}

int cmd_enter(string arg)
{
  if(environment(this_player())==environment())
  {
    if(invites && member_array((string)this_player()->query_real_name(),invites)==-1)
    {    
      write("You must be invited.\n");
      return 1;
    }
    say(TPN+" enters a side tunnel.\n");
    move_object(TP,this_object());
    command("look",TP);
    say(TPN+" arrives.\n");
    return 1;
  }      

  if(!ready)
  {
    write("The match isn't ready to start yet.\n");
    say(TPN+" tries to walk through the door and fails.  Ouch!\n");
    return 1;
  }
  if(!arena)
  {
    if(arena_type==0)
      arena=clone_object("/players/feldegast/arena/rooms/arena.c");
    else
      arena=clone_object("/players/feldegast/arena/melee/map.c");
  }
  say(TPN+" enters the arena.\n");
  move_object(TP,arena);
  command("look",TP);
  return 1;
}
    
int cmd_invite(string str)
{
  object play;
  notify_fail("Usage: invite <player>\n");
  if(!str) return 0;
  if(str=="all")
  {
    invites=0;
    write("You wipe the guest list and invite everybody.\n");
  }
  play=find_player(str);
  if(!play) return 0;
  if(!invites) invites=({ });
  invites+=({ str });
  write("You invite "+(string)play->query_name()+" to the gameroom.\n");
  tell_object(play,TPN+" has invited you to a sparring match.\n");
  return 1;
}  

int cmd_uninvite(string str)
{
  object play;
  notify_fail("Usage: uninvite <player>\n");
  if(!str) return 0;
  if(member_array(str,invites)==-1) return 0;
  invites-=({ str });
  write("You uninvite "+capitalize(str)+".\n");
  play=find_player(str);
  if(play) tell_object(play,TPN+" has uninvited you to the sparring match.\n");
  return 1;
}
  
int cmd_ready(string str)
{
  ready=!ready;
  tell_room(this_object(),(ready)?("The entrance to the arena opens.\n"):("The entrance to the arena closes.\n"));
  return 1;
}

int cmd_arena(string str)
{
  if(arena)
  {
    write("This can no longer be changed.\n");
    return 1;
  }
  arena_type=!arena_type;
  write("Current arena is: ");
  if(arena_type==0) write("The Pit.\n");
  if(arena_type==1) write("Feldaria.\n");
  return 1;
}
