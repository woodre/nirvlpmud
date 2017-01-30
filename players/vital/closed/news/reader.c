/******************************************************************************
 *  File:           reader.c
 *  Function:       
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2004 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         13/06/2004
 *  Notes:          
 *  Change History: 27/09/2005 modified to just call the vNews Daemon
 *****************************************************************************/

#include "/players/vital/closed/news/news.h"

inherit "/obj/newtreasure.c";

reset(arg)
{
  ::reset(arg);
  if (arg) reset;
  set_name("newspaper");
  set_alias("newsreader");
  set_alt_name("paper");
  set_weight(0);
  set_value(0);
  add_id("news");
  add_id("paper");
}

init()
{
  ::init();
  add_action("read_news", "read");
}

read_news()
{
  READER->read_it("news");
}