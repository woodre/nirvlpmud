/*
Changes:
12-13-99 Changed the short, fixed up the code a little, and corrected the
         typos.  Most importantly, when the potion is used up, it now sets
         the wc back properly. -Feldegast

Changes: Made it so the potion won't reset, and have it moving back into
         their inventory each round so new objects won't interfere.
         - Maledicta  3.09.01

CHANGES: Made it so the potion uses gen_wc_bonus instead, and maxes at
         a bonus of 20 unless wc is already that high. (i.e. a wc 15
         wep allows for a bonus of +5)
         - Maledicta 7.28.01

09-08-01 Reduced the maximum possible wc bonus to +5.  Many guilds have a
         wc of 0 and rely entirely upon wc returns.  Essentially, they get
         a 20 point bonus in addition to their guild attacks.  In order to
         prevent this, a cap is required.
         - Feldegast

09-10-01  After discussing this with another Senior and hate mail from
          a lot of players, We (vertebraker and maledicta) have decided
          to change this back to its original form.

09-10-01 After discussing this with Boltar, we (by which I mean myself and
         my many personalities) have decided to fix this bug by adding a
         check for "notweapon".
         - Feldegast

09-13-01 Argh!  Changed to constant return of 5, due to existing weapons
         with low wc and constant returns.  Also, lowered this item's price
         from 2500 back to 1000.  There is an equilibrium to be found here.
         - Feldegast
*/
#include "/players/feldegast/closed/ansi.h"
#define PASS "ThIs_iS_A_PaSs"
int num;
object obj;

int dfl; /* Drop flag */

inherit "/obj/treasure.c";

reset(arg) {
  if(arg) return;
  set_id("potion");
  set_alias("glowing potion");
  set_short("A "+CYN+"glowing"+NORM+" potion");
  set_long("This is a potion of strength.  You can quaff it to gain the strength of\n"+
           "Asterix for one minute.\n");
  set_value(500);
  set_weight(1);
  dfl=0;
  num=0;
}

init() {
  add_action("heal"); add_verb("quaff");
  add_action("wcset",PASS);   
}
pil() {
  if(!obj) return 0;  /* added by Vertebraker [5.31.01] */
  move_object(this_object(), obj);
  command(PASS,obj);
}

wcset() {
  if(num == 0)
    return 1;
  short_desc="A countdown clock (time left: "+(num-time())+" seconds)";
  if(num < time())
  {
    object wep;
    tell_object(obj,"The clock fades away.\n");
    tell_object(obj,"You feel Asterix's strength drain away from you.\n");
    obj->add_weight(-1);
    destruct(this_object());
    return 1;
  }
  move_object(this_object(), obj);
  call_out("pil",1);
  return 1;
}

heal(arg) {
  if (!arg || this_object()!=present(arg,this_player()))
  {
    notify_fail("What do you want to quaff?\n");
    return 0;
  }
  if(present("active_strength_potion", environment())){
    write("You are already empowered!\n");
    return 1;
    }
  if(num == 0)   {
    say(call_other(this_player(),"query_name") + " quaffs the potion.\n");
    write("You quaff the potion. You feel as strong as Asterix now!\nYou have the strength of a thousand men!\n");
    write("The bottle explodes in your hands and you see a clock in it.\n");
    long_desc="This clock shows the time left for the effect of the potion.\n";
    name="active_strength_potion";
    alias_name = "generic_wc_bonus";
    dfl=1;
    value=0;
    obj=this_player();
    num=time()+60;
    call_out("wcset",1);
    return 1;
  }
}

drop() { return dfl; }

gen_wc_bonus() {
  return 5;
}
