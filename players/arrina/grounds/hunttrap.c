#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "room/room";
 
/* Variable to detect if coming from tunnels */
status hurt;

toggle_hurt() { hurt = !hurt; }

reset(arg)
{
  if(arg) return;
  set_light(1);
  short_desc=("Hunting Pit");
  long_desc=
"You are in a massive pit! There is blood spattered everywhere.\n\
You see wooden stakes have been set into the bottom of the pit,\n\
their sharp points awaiting their next victim. This is a hunting\n\
pit, built to capture prey. You feel very fortunate that you\n\
have only been slightly injured, landing on the very edge of the\n\
pit instead of on the sharp pikes that protrude everywhere. It\n\
is obvious that most others have not been so lucky. You see an\n\
open spot that might be a tunnel into the earth to your east.\n";
  items =
  ({
    "blood","There is blood everywhere, and you assume it must be both\n\
animal and human",
    "stakes","These blood-covered stakes are about as big around\n\
as a man's arm, and the ends have been carved into\n\
very sharp points",
  });
  dest_dir=
  ({
    "players/arrina/tunnel/tunnel1.c","east",
  });
}

init()
{
  ::init();
  add_action("search_room","search");
  add_action("climb","climb");
  if(this_player()) /* v */
    DoDamage(this_player());
}

DoDamage(object who)
{
/* If coming from tunnels, do not hurt */
  if(hurt) { hurt = !hurt; return 1; }
  tell_object(who, RED +
    "\t\n\n\n\nYou feel the ground give way beneath you!\n\n\n\n"+NORM);
  if(who->is_player())
  {
    who->hit_player(40);
/*
  if(find_player("arrina")) tell_object(find_player("arrina"), who->query_real_name() +" has fallen in the PIT"); 
*/
/*
  write_file("/players/arrina/PIT",ctime(time())+" "+who->query_real_name()+" fell in the pit.\n");
*/
  }
  return 1;
}

search_room()
{
  write("You search and see a place where you may be able to get a foothold.\n\
You could attempt to climb to try to get back out.\n");
  say(this_player()->query_name() +" searches the room.\n");
  return 1;
}

climb()
{
  int ste;
  ste = 6; /* one out of 6 chance of getting out */
  if (this_player()->query_attrib("ste") >= 19) ste = 3; /* better chance */
  if (random(ste) == 0)
  {
    write("You get a foothold and climb out of the pit.\n");
    call_other(this_player(),"move_player",
               "in#players/arrina/grounds/barren.c");
  }
  else
  {
    write("You fall on your butt. On a pike. Youch!\n");
    this_player()->hit_player(7 + random(9));
  }
  return 1;
}

/* no teleporting out! */
realm() { return "NT";}
