/*
Changes:
12-13-99 Changed the short, fixed up the code a little, and corrected the
         typos.  Most importantly, when the potion is used up, it now sets
         the wc back properly. -Feldegast
*/
#include "/players/feldegast/closed/ansi.h"
#define PASS "ThIs_iS_A_PaSs"
int num;
object obj;

int dfl; /* Drop flag */

inherit "/obj/treasure.c";

void reset() {
  set_id("potion");
  set_alias("glowing potion");
  set_short("A "+CYN+"glowing"+NORM+" potion");
  set_long("This is a potion of strength.  You can quaff it to gain the strength of\n"+
           "Asterix for one minute.\n");
  set_value(1000);
  set_weight(1);
  dfl=0;
  num=0;
}

init() {
  add_action("heal","quaff");
  add_action("wcset",PASS);   
}
pil() {
  command(PASS,obj);
}

wcset() {
  if(num == 0)
    return 1;
  call_other(obj,"set_wc",20);
  short_desc="A countdown clock (time left: "+(num-time())+" seconds)";
  if(num < time())
  {
    object wep;
    tell_object(obj,"The clock fades away.\n");
    tell_object(obj,"You feel Asterix's strength drain away from you.\n");
    wep=this_player()->query_weapon();
    if(wep)
      call_other(this_player(),"set_wc",wep->weapon_class());
    else
      call_other(this_player(),"set_wc",3);
    obj->add_weight(-1);
    destruct(this_object());
    return 1;
  }
  call_out("pil",1);
  return 1;
}

heal(arg) {
  if (!arg || this_object()!=present(arg,this_player()))
  {
    notify_fail("What do you want to quaff?\n");
    return 0;
  }
  if(num == 0)   {
    say(call_other(this_player(),"query_name") + " quaffs the potion.\n");
    write("You quaff the potion. You feel as strong as Asterix now!\nYou have the strength of a thousand men!\n");
    write("The bottle explodes in your hands and you see a clock in it.\n");
    long_desc="This clock shows the time left for the effect of the potion.\n";
    name="clock";
    dfl=1;
    value=0;
    obj=this_player();
    num=time()+60;
    call_out("wcset",1);
    return 1;
  }
}

drop() { return dfl; }