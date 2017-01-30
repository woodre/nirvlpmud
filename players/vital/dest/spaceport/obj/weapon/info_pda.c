/******************************************************************************
 *  File:           info_pda.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2001, 2005 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 2001.01.04
 *  Notes:          simple weapon for boring npcs
 *  Change History: 2001.01.28 (Updated message_hit);
 *                  2001.02.01 (major portions of the room code by vertebraker);
 *                  2005.10.23 [strict_type'd and fixed ids]
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>

#define COST 15

inherit "obj/weapon.c";

status room_info();
status get_info(string str);

void
reset(status arg)
{
  ::reset(arg);
  if (arg) return;
  set_id("info_pda");
  set_name("pda");
  set_alias("organizer");
  set_short("A hi-tech PDA");
  set_long(format("This Personal Digital Assistant is the ultimate \
travel-warrior's weapon. The tiny screen can give you a lot of \
information. All you have to do is \'learn about\' an object.\n"));
  set_type("knife");
  set_class(15);
  set_params("other|electrical", 2 );
  set_weight(1);
  set_value(50 + random(150));
  set_info(format("This PDA is a dynamic learning tool to understand better \
the world around you. It can provide you with additional information about \
any things as well as who is responsible for certain things. Knowledge is \
power and information is the foundational key that opens the door.\n"));
  message_hit =
  ({
    HIY + "EleCtrOcuteD" + NORM," with the limited battery power",
    "shocked"," with your hi-tech prowess",
    "repeatedly " + HIR + "berated" + NORM,
      " with messages from the portable thesaurus",
    "gouged"," with the corner of the PDA",
    "confused"," with appointments from the last fiscal quarter",
    "jabbed"," with the stylus",
    "poked"," in the chest",
  });
}

void
init()
{
  ::init();
  add_action("get_info","learn");
}

status
get_info(string str)
{
  string wiz, what, thing;
  object a, b, c;
  int l, p;
  if(!str)
  {
    notify_fail("You have to \'learn about\' something.\n");
    return 0;
  }
  p = (int) this_player()->query_spell_point();
  l = (int) this_player()->query_level();
  if(p <= COST) { write("You don't have enough battery power to learn anything right now.\n"); return 1; }
  if(sscanf(str,"about %s",thing) == 1)
  {
    if(thing == "room") { room_info(); return 1; }
    if(!(a = environment())) return 1;
    if(!(b = present(thing, a)) && (c = environment(a)))
    {
      b = present(thing, c);
    }
    if(!b) return 0;
    wiz = creator(b);
    if(!wiz) wiz = "anonymous";
    what = (string) b->query_info();
    if(!what) what = "No additional information available";
    write(what + "\n");
    write("This was coded by: " + capitalize(wiz) + "\n");
    if(l <= 20) this_player()->add_spell_point(-COST);
    return 1;
  }
  write(info + "\n");
  return 1;
}

status
room_info()
{
  int f, l, p;
  object e;
  string r, a, wiz;
  p = (int) this_player()->query_spell_point();
  l = (int) this_player()->query_level();
  if(p <= COST) { write("You don't have enough battery power to learn anything right now.\n"); return 1; }

  if(!(e = environment(this_player())))
  {
    notify_fail("\
The area around you is void...\n\
Nothing seems to make any sense.\n");
    return 0;
  }

  r = (string) e->realm();

  if(r == "LA" || (r == "NT" && !e->okay_follow()))
  {
    write("This room requires manual movement.\n");
    f = 1;
  }
  if(r == "NT")
  {
    write("This room is not a good place to be if you wanted fly away.\n");
    f = 1;
  }
  if(r && r != "NT" && r != "LA" && r != "NM")
  {
    write("This is an odd room.\n");
    f = 1;
  }
  if((status)e->query_no_fight())
  {
    write("This is a peaceful place.\n");
    f = 1;
  }
  if((status)e->query_spar_area())
  {
    write("There could be sparring in this area.\n");
    f = 1;
  }
  if(a = (string)this_player()->query_fight_area())
  {
    if(a == file_name(e))
      write("This is a dangerous area to be in.\n");
    else this_player()->clear_fight_area();
    f = 1;
  }
  if((status)e->query_NM() || r == "NM")
  {
    write("Your abilities are dampened by this room.\n");
    f = 1;
  }
  if(!f)
    write("There is nothing to learn about this area.\n");

  wiz = creator(e);
  write("This room was created by: " + capitalize(wiz) + "\n");
  this_player()->add_spell_point(-(COST + 5));
  return 1;
}
