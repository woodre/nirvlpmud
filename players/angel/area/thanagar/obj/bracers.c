/*                                                                    *
 *    File:             /players/angel/area/thanagar/room/bracers.c   *
 *    Function:         obj                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2008 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/08/08                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

#define CREST "crest"

#define FULL_GLO "/players/angel/area/thanagar/obj/hbracers.c"

inherit "/obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("bracers");
   set_short("A pair of bracers");
   set_long("A pair of gold bracers once worn worn by Hawkman.\n");
   set_ac(1);
   set_type("bracelet");
   set_weight(1);
   set_value(500);
}



void init(){
  ::init();
   /* action to change the armor */
   add_action("attach","attach");
}

attach(str){
  object crest, new_armor;
  if(!environment(this_object())) return;
  if(worn)
    command("unwear bracers", this_player());
  if(!str || str != "crest") return 0;
  crest = present(CREST, this_player());
  if(!crest){
    notify_fail("You don't have the crest.\n");
    return 0;
}

  destruct(crest);
  new_armor = clone_object(FULL_GLO);
  move_object(new_armor, this_player());
  command("wear bracers", this_player());
    write("A transformation occurs as you attach the crest to the bracers.\n");
    say(capitalize(this_player()->query_name())+" attaches the crest to the bracers.\n");
      destruct(this_object());
        return 1;
}