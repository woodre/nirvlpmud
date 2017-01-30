/*
File: farhelm.c
Creator: Feldegast @ Nirvana
Date: 1/11/01
Description:
  A magical helm with the ability to see the description
of a room that a player or monster is in.  Basicly, an
expensive wooden boy.  There is a refresh time of 60
seconds between uses.  The target has a chance of noticing.
The helm must be worn to be used, so not all guilds can
use it.  Sold in Morgar's magic shop.
Made non-storable on June 22nd, 2002 - Maledicta
*/

#include "/players/feldegast/defines.h"

inherit "/obj/armor.c";

int timeout;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("farhelm");
  set_alias("helm");
  set_short("Helm of Farseeing");
  set_long(
"This is a heavy steel helm with a metal nosepiece and two slits\n"+
"for the eyes.  This helm was once worn by Sir Edwick the Farseer,\n"+
"a legendary warrior-mage who it is said could see through the eyes\n"+
"of his enemies.  To use the helm's power, type '"+BOLD+"farsee"+NORM+".\n"
  );
  set_ac(1);
  set_type("helmet");
  set_weight(3);
  set_value(4500);
}

void init() {
  ::init();
  add_action("cmd_farsee","farsee");
}

int cmd_farsee(string str) {
  object targ;
  object env;
  if(!worn) {
    notify_fail("You must wear the helm to use its power.\n");
    return 0;
  }
  if(timeout) {
    notify_fail("The helm is still recharging its power.\n");
    return 0;
  }
  if(!str) {
    notify_fail("Farsee who?\n");
    return 0;
  }
  targ=find_player(str);
  if(!targ) targ=find_living(str);
  if(targ && targ->query_level() > 20)
    targ=0;
  if(!targ) {
    notify_fail("There is no player or monster by that name.\n");
    return 0;
  }
  write("You see through the eyes of "+(string)targ->query_name()+":\n");
  env=environment(targ);
  if(!env) {
    write("Nothing.\n");
    return 1;
  }
  write((string)env->short()+"\n");
  env->long();
  timeout=1;
  call_out("timein",60);
  if((int)this_player()->query_attrib("wil") < random(120)) {
    tell_object(targ,"You sense that you are being watched.\n");
    write((string)targ->query_name()+" notices your attention.\n");
  }
  return 1;  
}

void timein() {
  timeout=0;
  if(environment() && environment()->is_player() && worn) {
    tell_object(environment(),HIR+"Your eyes glow red.\n"+NORM);
    tell_room(environment(environment()),HIR+environment()->query_name()+"'s eyes glow.\n"+NORM,({ environment() }));
  }
}

int do_special(object owner) {
  /* 1 in 10 */
  if(!this_player()) return 0;
   if((int)this_player()->query_attrib("int") > random(200) && !timeout) {
    write(HIR+owner->query_name()+"'s eyes glow red!\n"+NORM);
    tell_object(owner,HIR+"Your eyes glow red from within the helm!\n"+NORM);
    return 1;
  }
  return 0;
}
