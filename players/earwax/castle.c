#define NAME "Earwax"
#define DEST "/room/mine/tunnel_room"
#include "/players/earwax/defs.h"
#include <ansi.h>
/* this is in simul_efun now
inherit "/players/earwax/lib/waxfuns.c";
*/

/* Globals */
string *Okay;
status Flag_open;

int is_castle() { return 1; }

status id(string str) {
  return ( str == "wax" || str == "earwax" || str == "gate" || str == "gates" );
}

short() {
  return HIW + "A massive gate stands " + (Flag_open ? "open" : "closed") + " to the north" + NORM + NORM;
}

long(str) {
  if (!Flag_open) 
    write(line_wrap("This is an immense wrought-iron gate with Earwax's sigil upon it.  It's closed, but doesn't appear to be locked.  Perhaps you can '" + HIW + "open gate" + NORM + NORM + "' and proceed north through it.\n"));
  else write(line_wrap("The massive, wrought-iron gate is open.  You may proceed " + HIW + "north" + NORM + NORM + " through it.\n"));
}

status do_open(string arg) {

  if (!id(arg)) {
    notify_fail("What is it that you're trying to open?\n");
    return 0;
  }

  if (Flag_open) {
    notify_fail("The gate is already open.  Just go "+HIW+"north"+NORM+NORM+" to enter Earwax's realm.\n");
    return 0;
  }

  write("The gate slides open surprisingly easily, considering its weight.\nYou may proceed "+HIW+"north"+NORM+NORM+".\n");
  say((string)this_player()->query_name() + " opens the massive iron gate.\n", this_player());
  Flag_open = 1;
  return 1;
}

status do_close(string arg) {

  if (!id(arg)) {
    notify_fail("What is it you wish to close?\n");
    return 0;
  }

  if (!Flag_open) {
    notify_fail("The gate is already closed.\n");
    return 0;
  }

  Flag_open = 0;
  write(line_wrap("With a grunt (from you) and a clank (from the gate) and a clang (also from the gate), you have now closed off the way into Earwax's realm.\n"));
  say((string)this_player()->query_name() + " closes the massive iron gate.\n", this_player());
  return 1;
}

status passed() {
  return (member_array((string)this_player()->query_real_name(), Okay) > -1);
}

status go_north(string arg) {

  if (!Flag_open) {
/* Area open now :)
write(HIW+"This area is not open for play yet, hopefully it will be in soon.\n"+NORM+NORM);
*/
    write("Even you can't walk through a closed gate.\n");
    return 1;
  }

  if (passed()) {
    write("As you pass through the gates you notice a guard nodding in recognition.\n");
#ifndef __LDMUD__ /* Rumplemintz */
    this_player()->move_player("north#"+ENTRANCE);

#else
    this_player()->move_living("north#"+ENTRANCE);
#endif
    return 1;
  }

  write(line_wrap("A voice bellows out and stops you before you can enter the gates: 'Stop!  We only allow those in here who know the password.  Only a player can '" + HIW + "finger earwax" + NORM + NORM + "' to figure it out.  When you do, say it to prove you aren't one of Mizan's blasted creations.'\n"));
  return 1;
}

status check_say(string arg) {

  if (arg != "qtip")
    return 0;

  say((string)this_player()->query_name() + " mumbles something.\n", this_player());
  write("You quietly say the password.\n");
/* Area open now :)
if ((int)this_player()->query_level() < 20) {
write(HIW+"This area is not open for play yet, hopefully it will be in soon.\n"+NORM+NORM);
return 1;
}
*/

  if (Flag_open) {
    write(line_wrap("Guards pour out of the gate and escort you to the other side.  In passing, the leader of the detachment let's you know that in the future you can simply go through, they should recognize you.\n"));
    say(line_wrap("Guards come out from behind the gates and escort "+(string)this_player()->query_name()+" through the gates.\n"), this_player());
#ifndef __LDMUD__ /* Rumplemintz */
    this_player()->move_player("north#"+ENTRANCE);
#else
    this_player()->move_living("north#"+ENTRANCE);
#endif
    Okay += ({ (string)this_player()->query_real_name() });
    return 1;
  }

  write(line_wrap("The guards apparently can hear you and open the gates for you.  They escort you to the other side, as well.\n"));
  say(line_wrap("The gates suddenly swing open, and guards pour out to escort "+(string)this_player()->query_real_name()+" through them.\n"), this_player());
#ifndef __LDMUD__ /* Rumplemintz */
  this_player()->move_player("north#"+ENTRANCE);
#else
  this_player()->move_living("north#"+ENTRANCE);
#endif
  if (!passed())
    Okay += ({ (string)this_player()->query_real_name() });

  return 1;
}

status do_finger(string arg) {

  if (arg != "earwax" && arg != "Earwax")
    return 0;

  write(line_wrap("\n\nYou root your fingers around in your ears to clean out the obstruction somewhat.  Miraculously enough, you can hear a tiny voice whispering: '" + HIW + "The password is qtip" + NORM + NORM + ".'  You feel quite relieved that it was so easy.\n"));
  return 1;
}

void init() {
  add_action("do_open", "open");
  add_action("do_close", "close");
  add_action("go_north", "north");
  add_action("go_north", "n");
  add_action("check_say", "say");
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("check_say"); add_xverb("'");
#else
  add_action("check_say", "'", 3);
#endif
  add_action("do_finger", "finger");
}
   
reset(arg) {

  Flag_open = 0;
  Okay = ({ });

  if (arg)
    return;

   move_object(this_object(),DEST);

  /* Preload guild object */
#ifndef __LDMUD__ /* Rumplemintz */
  call_other("/players/earwax/closed/TRACKER/loader.c","reset",0);
#else
  load_object("/players/earwax/closed/TRACKER/loader.c");
#endif
/*
  call_other("/players/earwax/closed/shardak/new/gob/loader.c","reset",0);
  call_other("/players/earwax/obj/viral_gag.c", "reset", 0);
  call_other("/players/earwax/closed/shardak/mark.c","reset",0);
  call_other("/players/earwax/assassins/license_loader.c", "reset", 0);
*/

/*
  move_object(this_object(), "/players/earwax/workroom");
*/
}

