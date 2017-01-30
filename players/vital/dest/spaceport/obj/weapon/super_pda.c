/******************************************************************************
 *  File:           super_pda.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 1/4/01.
 *  Notes:          a really nice pda
 *  Change History: 2/28/01(Updated message_hit); 3/2/01(major portions of the
 *                  room code by vertebraker); 3/6/01(made super);
 *                  2005.10.22 [strict_type'd and fixed ids]
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>
#include "/players/vital/dest/include/spaceport.h"

#define COST 10
#define WEAPON_COST 40
#define ARMOR_COST 50

inherit "/obj/weapon.c";
int x;

status room_info();

void
reset(status arg)
{
  ::reset(arg);
  x = 18;
  if (arg) return;
  set_id("super_pda");
  set_name("pda");
  set_alias("organizer");
  set_short("A hi-tech PDA");
  set_long("This Personal Digital Assistant is perhaps the only tool you \n\
will ever need to use again. The tiny screen can give you a lot of \n\
information. All you have to do is \'learn about\' an object.\n");
  set_type("knife");
  set_class(12);
  set_params( "other|electrical", 18, "weapon_hit");
  set_params( "other|laser", 10 );
  set_weight(1);
  set_value(5000 + random(1500));
  set_info("This PDA is a dynamic learning tool to understand better the \n\
world around you. It can provide you with additional information \n\
about many things as well as who is responsible for certain things. \n\
Knowledge is power and information is the foundational key that \n\
opens the door.\n");
  set_hit_func(this_object());
  message_hit =
  ({
    HIY + "EleCtrOcuteD" + NORM,
      " with the rechargeable lithium-ion battery power",
    YEL + "shocked" + NORM,
      " with your hi-tech prowess",
    "repeatedly " + HIR + "berated" + NORM,
      " with messages from the portable thesaurus",
    "gouged",
      " with the corner of the PDA",
    "confused",
      " with appointments from the last " + HIC + "fiscal" + NORM + " quarter",
    "jabbed",
      " with the stylus",
    "poked"," in the chest with a haughty laugh at your mental superiority",
  });
}

void
init()
{
  ::init();
  add_action("get_info","learn");
  x = (int) this_player()->query_attrib("int");
  if(x < 20) x = 20;
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
  if(p <= COST)
  {
    notify_fail("You don't have enough battery power to learn anything right now.\n");
    return 1;
  }
  if(sscanf(str,"about %s",thing) == 1)
  {
    if(thing == "room") { room_info(); return 1; }
    if(!(a = environment())) return 0;
    if(!(b = present(thing, a)) && (c = environment(a)))
    {
      b = present(thing, c);
    }
    if(!b)
    {
      notify_fail("The PDA is unable to locate the "  +  thing  +  " here.\n");
      return 0;
    }
    if(l <= 20) this_player()->add_spell_point(-COST);
    if(b->is_armor() && p <= ARMOR_COST)
    {
      notify_fail("You don't have enough battery power to learn anything right now.\n");
      return 0;
    }
    if(l <= 20) this_player()->add_spell_point(-ARMOR_COST);
    if(b->is_weapon() && p <= WEAPON_COST)
    {
      notify_fail("You don't have enough battery power to learn anything right now.\n");
      return 0;
    }
    if(!wiz) wiz = "anonymous";
    wiz = creator(b);
    what = (string) b->query_info();
    if(!what) what = "No additional information available";
    write(what + "\n");
    write("This was coded by: " + capitalize(wiz) + "\n");
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
  if(p <= COST)
  {
    write("You don't have enough battery power to learn anything right now.\n"); 
    return 1;
  }
  if(!(e = environment(this_player())))
  {
    notify_fail("\
The area around you is void...\n\
Nothing seems to make any sense.\n");
    return 0;
  }

  r = (string)e->realm();

  if(r == "LA" || (r == "NT" && !e->okay_follow()))
  {
    write("This room requires manual movement.\n");
    f = 1;
  }
  if(r == "NT")
  {
    write("This room is not a good place to be if you wanted to fly away.\n");
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

int
weapon_hit(object attacker)
{
  int r, z;
  string name;
  r=random(100);
  z=random(7);
  if(z > 3)
  {
    if(r <= 25)
    {
      write("The PDA screen " + BLINK + "flashes" + NORM + 
        " with information about the attacker.\n");
      say("The PDA " + BLINK + "flashes" + NORM + 
        " in the hands of " + this_player()->query_name() + ".\n");
      return 6;
    }
    if(r > 25 && (r <= 95))
    {
      write("The PDA " + HIY + "ZZZzzzaaaappps " + NORM + 
        attacker->query_name()  +  "\n\n");
      say(this_player()->query_name() + " uses the PDA to " + HIY +
        "ZZZzzzaaaappp" + NORM + " " + attacker->query_name() + "\n\n");
      return 3;
    }
    if(r > 95)
    {
      write("The PDA is working to your time and effort into " + HIG +
        "money" + NORM + "!\n\n");
      say(this_player()->query_name() +
        " utilizes the PDA to turn the pain of " +
        attacker->query_name() + " into hard currency!\n");
      this_player()->add_money(random(10) + random(10) + 5);
      this_player()->hit_player(this_player(), "other|electrical", 8);
      return 2;
    }
  }
}
