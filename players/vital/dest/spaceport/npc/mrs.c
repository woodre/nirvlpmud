/******************************************************************************
 *  
 *  File:           mrs.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  portions by Eurale@Nirvana
 *                  All Rights Reserved. 
 *  Source:			Started 1/5/01.
 *  
 *  Notes:			
 *  
 *  Change History: 1/5/01
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "/players/vital/closed/std/monster";

object buyer,item;

int value,m;

reset(arg) {
  ::reset(arg);
  if(arg) return;

set_name("woman");
set_alias("c");
set_race("human");
set_short("Mrs. C");
set_long("  "+short_desc+"\n\
This is an elderly looking woman who has undoubtably been on the \n\
N.U.T.S. for a long time. The woman probably has many stories to tell \n\
and secrets to hide. She has holed up here in this converted maintenance\n\
closet for years waiting for people to find her. She is dressed in \n\
piles of rags and smells like musty body odor gone too long ignored.\n");

set_level(20);
set_hp(500);
set_al(999);
set_wc(30);
set_ac(17);
set_no_clean(1);
add_money(4500+random(500));

set_chat_chance(10);
  load_chats( ({
    "Mrs. C says: How did you get in here?\n",
    "The woman says: Ask me about my ancient story.\n"
  }) );

set_chance(10);
set_spell_dam(5+random(20));

set_spell_mess1(
  ""+TPN+" shows her super strength in battle.\n");
set_spell_mess2(
  "You are \n\t\t\tTHROWN\nagainst the walls.\n");
}

init() {
add_action("ask","ask");
}

ask(str) {
if(str == "woman" || str == "mrs. c" || str == "story" || str == "about story" || str == "c" ) {
  write("  I have been here for a long, long time. I have seen many things go on at this portal to the stars. Do you know that once shuttles used solid fuel? That was long ago. \n\n  I have now seen some 4000 lunar phases. I was part of the first wave of longevity experiments. I was the recipient of a much slower metabolism, a stronger physical form, and the worst of appearances. \n\n  Things have changed since that time. Nothing around here is what it appears.\n");
  return 1; }
notify_fail("What or who are you trying to ask?\n");
return 0;
}

id(str) { return str == "mrs. c" || str == "mrs" || str == name || str == alias || str == race || str == alt_name; }
