#include "/players/mythos/myth/healer/def.h"
inherit "players/mythos/myth/base";
static int wielded;
static object wielded_by;
static string oncelist;

id(str) { return str == "hob" || str == "healer_staff" ||
                 str == "staff" || str == "MYTHOSSYSOBJ"; }
                 
query_auto_load() { return "/players/mythos/myth/healer/base.c:"; }

short() { return "Staff of True Healing"; }

long() {
   write("\n");
   write("myth_help will bring up the help files\n");
}

reset(arg) {
::reset(arg);
  if(arg) return;
  wielded = 0;
  wielded_by = 0;
  whatob = "healer";
  oncelist = ({""});
}

init() {
::init();
  if(tp == ep) {
    add_action("wield","wield");
    add_action("unwield","unwield");
  }
}       

query_heal_wield() { return wielded; }

wield(str) {
    if (!id(str)) {
      write("You can not unwield the Staff of Healing.\n");
    return 1; }
    if (ep != tp) return 0;
    if (wielded) { write("You already wield it!\n"); return 1; }
    wielded_by = this_player();
    call_other(this_player(), "wield", this_object());
    wielded = 1;
    add_action("heal_once","qheal");
    return 1;
}

weapon_class() { return 3; }

stopwield() {
  write("You can not unwield the Staff of Healing.\n");
return 1;}

unwield() {
  write("You can not unwield the Staff of Healing.\n");
return 1;} 

un_wield() { return 1; }

add_oncelist(string who,arg) { 
  if(!arg) oncelist += ({who});
  else oncelist -= ({who});
}

set_oncelist(str) { oncelist = str; }

query_oncelist() { return oncelist; }

obswitch(object one,object two) {
  one->set_oncelist(two->query_oncelist());
return 1; }

wield_check() {
  if(!wielded) { write("You must wield the healing staff first.\n");
             return 1; }
return 0; }

/* POWER material */

heal_once(str) { if(!wield_check()) POWER->heal_once(str); return 1; }

