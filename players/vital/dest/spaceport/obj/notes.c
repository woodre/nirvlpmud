/******************************************************************************
 *  File:           notes.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 2001.01.07
 *  Notes:
 *  Change History: 2001.03.03 (added set_info());
 *                  2005.10.23 [strict_type'd and fixed ids]
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>
#include "/players/vital/dest/include/spaceport.h"

inherit "/obj/newtreasure.c";

void
reset(status arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("scanner");
  set_alias("machine");
  set_info("An ancient machine to let Vital know what you think, what you need or what you want. Vital will add in most anything you ask for. He may even give you credit for it.\n");
  set_short("An ancient retinal scanner");
  set_long("This is an ancient machine that upon scanning your retinal \n\
pattern, allows you to leave a specialized message for the \n\
administration. They always value your time and thoughts.\n\
So take a moment to \'scan\' your \<message\> into the machine.\n\
The administration thanks you.\n");
  set_weight(10000);
}

void
init()
{
  add_action("write_note","scan");
  add_action("review_notes","vital");
  if( (string) this_player()->query_guild_name() == "rangers")
    add_action("ranger_honor","honor");
}

status
write_note(string str)
{
  string name;
  if(!str)
  {
    notify_fail("The syntax is \'scan \<message\>\' to enter a message into \
the machine.\n");
    return 0;
  }
  name = (string) this_player()->query_real_name();
  write("You see a "+HIR+"red"+NORM+" light pass across you eye.\n");
  write_file(SPSAVE + "area.response", ctime(time()) + " " + HIR +
    name + " " + HIB + "\:" + NORM + " " + str + "\n");
  write("Your message has been entered.\n");
  return 1;
}

status
review_notes(string str)
{
  if( (string) this_player()->query_real_name() != "vital")
  {
    notify_fail("Nothing happens.\n");
    return 0;
  }
  else
    tail(SPSAVE+"area.response"); return 1;
}

status
ranger_honor(string str)
{
  object com, ob, who, next;
  if(!str)
  {
    notify_fail("Honor who?\n");
    return 0;
  }
  if(!(who = find_player(str)))
  {
    notify_fail(capitalize(str)+" is not logged on.\n");
    return 0;
  }
  if( (string) who->query_guild_name() == "shardak" ||
      (string) who->query_guild_name() == "cyberninja"||
      (string) who->query_guild_name() == "dark rangers")
  {
    notify_fail("That guild will never be an Ally of the Rangers!\n");
    return 0;
  }
  if(!present("honor_ranger_communicator"), who)
  {
    move_object( clone_object(
      "/players/guilds/Rangers/HonorRangerCommunicator.c"), who);
    command("rte has been added to the Ranger Allies.", who);
    write(capitalize(str)+" has been added to the Ranger Allies.\n");
    return 1; 
  }
  notify_fail("Operation failed.\n"); return 0;
}
