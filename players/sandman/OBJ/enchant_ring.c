#include "/players/feldegast/closed/ansi.h"

int charges;

inherit "/obj/armor.c";

reset(arg)
{
   if(arg) return;
   charges = 2;
   set_name("ring");
   set_short(GRN+"Enchanted Ring"+NORM);
   set_long("An ornate silver ring, with a priceless emerald set in it.\n"+
            "Type 'energize' to use it. It will energize your spell points.\n");
   set_type("ring");
   set_ac(1);
   set_value(1000);
   set_weight(1);
}

init()
{
  ::init();
  add_action("energize","energize");
}

energize()
{
   if(charges == 0) {
      write("The ring glows for a second, and then disintegrates.\n");
      remove("ring");
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
   }
   call_other(this_player(), "add_spell_point", 100);
   write("The ring glows, and you feel energized!\n");
   charges = charges - 1;
   return 1;
}



query_value() { return charges*2700; }

string locker_arg()
{
  return ""+charges;
}

void locker_init(string arg)
{
  charges=atoi(arg);
}
