/*                                                                    *
 *    File:             /players/sami/area/carnival/room/entrance.c   *
 *    Function:         room                                          *
 *    Author(s):        Sami@Nirvana                                  *
 *    Copyright:        Copyright (c) 2008 Sami                       *
 *                              All Rights Reserved.                  *
 *    Source:           11/08/08                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
/*if( !present("abk", this_object()) )
    move_object(clone_object("/players/sami/area/carnival/obj/abk.c"), this_object());*/
  if(arg) return;
  set_light(-1);
  short_desc = "Carnival of Carnage";
  long_desc =
"  This is a very large tent with a single admission stand in\n\
the center of the room. The walls are coverd in red and yellow\n\
posters. you can vaguely make out the face of a clown behind the\n\
counter, resembeling that of the posters. To the north you see a\n\
small cloth made door. The only other obvious exit is out.\n";
  items =
    ({
    "poster",
    "This is a average 8x11 poster. You can barely make out a clown's face\n\
     on the dirty surface of the thick glass it is encased in",
    "counter",
    "This is a very old redwood counter. Time has not been nice to the counter,\n\
     chips in the ancient wood along with small termite holes are noticeable",
    "door",
    "You laugh as you notice a raggity make-shift\n\
     door made of red and yellow cloth",
     });
     dest_dir =
    ({
	  "/player/sami/area/carnival/room/hall_of_passage.c",     "enter",
    });
}

init() {
  ::init();
  add_action("enter","enter");
  add_action("pay","pay");
}

enter() {
  object ob;
    ob = present("abk");
  if(present("abk")) {
        write("Abk says:  Pay up Punk! \n");
        say("Abk prevents "+capitalize(this_player()->query_real_name())+" from entering. \n");
  return 1; }

  if(!present("abk")) {
    call_other(this_player(),"move_player",
        "enter#players/sami/area/carnival/room/hall_of_passage.c");
  return 1; }
}

pay(str) {
object abk;
int amt;
abk = present("abk",this_object());
  if(!str) {write("Who do you want to pay? \n"); return 1; }
  if(present("abk") && (str == "abk")) {
    amt = 2000;
  if(this_player()->query_money() < 2000) {
    write("Abk Screams:, 'Come back when you have money, mutant.'\n");
    return 1; }
    write("Thanks.... have a blast! \n");
    this_player()->move_player("pay#players/sami/area/carnival/room/hall_of_passage.c");
    this_player()->add_money(-amt);
if(abk)abk->add_money(amt);
    return 1; }
return 1;
}