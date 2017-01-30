#include "defs.h"

inherit "/obj/armor.c";

int paused;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("bracelet");
  set_alias("sylvan bracelet");
  set_short(GRN+"Sylvan"+NORM+" bracelet");
  set_long(
    "This is a simple silver bracelet with an emerald on it.\n"+
    "You notice an inscription on the inside of the band.\n"
  );

  set_ac(1);
  set_weight(1);
  set_type("bracelet");
}

void init() {
  ::init();
  add_action("beast_heal","bheal");
  add_action("cmd_read", "read");
}

int beast_heal(string str) {
  object targ;
  int amt;
  if(!str) str="pet";
  targ=present(str,environment(TP));
  if(!targ) {
    notify_fail("What beast do you want to heal?\n");
    return 0;
  }
  if(!living(targ)) {
    notify_fail("That is not a living thing.\n");
    return 0;
  }
  if((int)targ->is_player()) {
    notify_fail("This artifact cannot heal players.\n");
    return 0;
  }
  if(paused) {
    write("You cannot use this item again yet.\n");
    return 1;
  }
  amt = (int)targ->query_mhp() - (int)targ->query_hp();
  if(amt > 40) amt = 40;
  if(amt <= 0) {
    write((string)targ->short()+" does not need to be healed.\n");
    return 1;
  }
  if((int)TP->query_hp() < (amt/2)) {
    write("You don't have enough health points.\n");
    return 1;
  }
  if((int)TP->query_sp() < (amt/2)) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  targ->heal_self(amt);
  paused=1;
  write("You lay your hands upon "+(string)targ->short()+" and concentrate upon healing.\n");
  say(TPN+" heals "+(string)targ->short()+".\n");
  call_out("unpause",5);
  return 1;
}

void unpause() {
  paused=0;
}

int cmd_read(string str) {
  if(!id(str) && str!="inscription")
    return 0;
  else {
    write("Use the command <bheal> to heal pets.\n");
    return 1;
  }
}

int do_special(object owner) {
  if(!random(12) && (int)TP->query_attrib("pie") > 16) {
    tell_object(owner, "The blow rings off of your Sylvan bracelet.\n");
    return 3;
  }
  return 0;
}
