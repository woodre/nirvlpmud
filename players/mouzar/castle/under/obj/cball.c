/* changes by verte:

   !arg check in spy, environment() checks,
    25 spell point cost for usage, can only use every 20 secs
*/
#include <ansi.h>

int cant_use;
inherit"obj/treasure";
reset(arg) {
if(arg) return;
set_id("crystal ball");
set_alias("ball");
set_short("Crystal ball");
set_long(
"This is a crystal ball that wizards us to spy on people from afar.\n"
+ "As you look into its depths, you get dizzy.\n" +
"This item requires magical energy to use.\n");
set_value(500);
set_weight(1);
}
init() {
  add_action("spy","spy");
}

spy(arg) {
  object who;
  if(cant_use) return (notify_fail("The crystal ball is busy recharging from its last usage.\n"), 0);
  if(!arg) return (notify_fail("Spy on who?\n"), 0);
  who = find_living(arg);
  if(!who) { notify_fail("Can't seem to get a clear reading on that person.\n"); return 0; }
  if(who->query_invis() > 20) {
    notify_fail("Can't seem to get a clear reading on that person.\n");
    return 0;
  }
  if(who->query_level() > 20) {
    notify_fail("Can't seem to get a clear reading on that person\n");
    return 0;
  }

  if(this_player()->query_spell_point() < 25)
    return (write("You need more magical energy to focus into the crystal ball.\n"), 1);
  cant_use = 20;
  call_out("ok_you_can_use", 20);
   this_player()->add_spell_point(-25);
  write("<<>> "+capitalize(who->query_name())+"  ");
  if(!environment(who) || !environment(who)->short()) return (write("Logging in\n"), 1);
  if(environment(who)->short()) {write(environment(who)->short()+"\n"); return 1;}
  return 1;
}


ok_you_can_use()
{

    object e;
    if(e = environment()) {
      if(living(e)) tell_object(e, "The crystal ball " + CYN + "glimmers" + NORM + " faintly.\n");
    else tell_room(e, "The crystal ball " + CYN + "glimmers"+NORM + " faintly.\n");
    }
    cant_use = 0;
}

locker_arg() { return ""+cant_use; }

locker_init(arg) { sscanf(arg, "%d", cant_use);  if(cant_use) call_out("ok_you_can_use", cant_use); }
