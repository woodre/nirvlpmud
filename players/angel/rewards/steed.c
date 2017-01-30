/*                                                                            *
 *      File:             /players/angel/rewards/steed.c                      *
 *      Function:         seller                                              *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           07/20/07                                            *
 *      Notes:                                                                *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include "/sys/lib.h"

inherit "obj/monster";

object mount;

reset(arg) {
  ::reset();
  if(arg) return;
  set_name("steed");
  set_aggressive(0);
  set_alias("steed");
  set_short("Angel's Steed");
  set_long("Angel's Majestic Riding Steed.\n" +
           this_player()->query_name() + " is mounted on top.\n");
  set_level(19);
  set_hp(10000);
  set_wc(100);
  set_ac(100);
  set_chance(0);
  set_spell_dam( );
  set_spell_mess1(" \n");
  set_spell_mess2(" \n");
  set_aggressive(0);
}

init() {
  add_action("Mount","mount");
  add_action("dismount","dismount");
  if (this_player()==mount) {
    add_action("look","l");
    add_action("look","look");
  }
  ::init();
}

look() {
write("not yet\n");
}
query_real_name() { return "steed"; }

Mount() {
string tpname;

  tpname=this_player()->query_name();
  if (tpname != "Angel") {
    write("Angel's mighty steed throws you\n");
    say("Angel's mighty steed throws " + tpname + "\n",this_player());
    return 1;
  }
  write("You mount the powerful beast\n");
  say(tpname + " mounts Angel's mighty steed\n",this_player());
  if (environment(this_object())==this_player())  {
    write("(You set the beast down first.)\n");
    move_object(this_object(),environment(this_player()));
  }
  move_object(this_player(),this_object());
  mount=this_player();
  set_long("Angel's Majestic Riding Steed.\n" +
           this_player()->query_name() + " is mounted on top.\n");
  return 1;
}

dismount() {

  if (environment(this_player()) != this_object()) {
    write("You aren't mounted on the beast!\n");
    return 1;
  }
  write("You carefully dismount the steed.\n");
  say(this_player()->query_name() + " steps down from atop Angel's Mighty Steed.\n",this_player());
  move_object(this_player(),environment(this_object()));
  if(this_player()==mount) mount=0;
  set_long("Angel's Majestic Riding Steed.\n" +
           mount->query_name() + " is mounted on top.\n");
  return 1;
}


query_auto_load() { return "/players/angel/rewards/steed.c:"; }

get() { return 1; }

drop() {
  write("You can't drop this steed.\n");
  return 1;
}
