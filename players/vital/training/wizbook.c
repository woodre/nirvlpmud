/******************************************************************************
 *  File:           wizbook.c
 *  Function:       Give New Wizards The Start They Need
 *  Author(s):      Eurale, Vertebraker, Vital@Nirvana
 *  Copyright:      Copyright (c) 2002 Nirvana
 *                  All Rights Reserved.
 *  Source:         29/02/2002
 *  Notes:          
 *  Change History: 07/05/2004 Vital-started updating the files for content
 *                  and readability.
 *                  08/05/2004 Vital-moved chapters to separate file for 
 *                  easier updating
 *****************************************************************************/

inherit "obj/treasure";

#include <ansi.h>

#define TEXT "/players/vital/training/wizbook.txt"

id(str) { return (::id(str) || (str=="eurale's funky wizbook")); }
drop() { return 1; }

reset(arg)
{
  if(arg) return;

  set_id("book");
  set_alias("handbook");
  set_short(HIR+"Wizard Handbook"+NORM);
  set_long(
  "  This is the standard "+HIR+"Wizard Handbook."+NORM+"  It is full \
of important information\nthat all wizards should know.  You can "+HIR+
"'read index'"+NORM+" to find out the topics\ncovered in this handbook \
and then "+HIR+"'read <topic>'"+NORM+" to get specifics about that\n\
topic.  You should familiarize yourself completely with this handbook \
before\nyou begin coding anything.\n");

  set_weight(1);
  set_value(1);
  set_save_flag();
}

init() {
  ::init();
  add_action("Read","read");
}

Read(str)
{
  int start, length;
  if(this_player()->query_level() < 21)
    notify_fail("The pages are too blurry to read.\n");
  switch(random(5))
  {
    case 0:  notify_fail("The book whispers: 'Read What?'\n"); break;
    case 1:  notify_fail("The book whispers: 'Which Page?'\n"); break;
    case 2:  notify_fail("The book whispers: 'That's Not In Here.'\n"); break;
    case 3:  notify_fail("The book whispers: 'Check The Index?'\n"); break;
    case 4:  notify_fail("The book whispers: 'Is That A Typo?'\n"); break;
  }

  switch(str)
  {
    case "index"        :
      start = 1;
      length = 10;
      break;
    case "welcome"      :
      start = 11;
      length = 19;
      break;
    case "terms1"       :
      start = 31;
      length = 13;
      break;
    case "interaction1" :
      start = 45;
      length = 18;
      break;
    case "interaction2" :
      start = 64;
      length = 23;
      break;
    case "interaction3" :
      start = 88;
      length = 22;
      break;
    case "rules1"       :
      start = 111;
      length = 14;
      break;
    case "rules2"       :
      start = 126;
      length = 13;
      break;
    case "rules3"       :
      start = 140;
      length = 16;
      break;
    case "creativity1"  :
      start = 157;
      length = 15;
      break;
    case "creativity2"  :
      start = 174;
      length = 17;
      break;
    case "area1"        :
      start = 191;
      length = 18;
      break;
    case "area2"        :
      start = 210;
      length = 24;
      break;
    case "area3"        :
      start = 235;
      length = 24;
      break;
    case "area4"        :
      start = 260;
      length = 18;
      break;
    default             : return 0;
  }
  cat(TEXT, start, length); write("\n");
/*   write(read_file(TEXT, start, length) + "\n"); */
  return 1;
}

