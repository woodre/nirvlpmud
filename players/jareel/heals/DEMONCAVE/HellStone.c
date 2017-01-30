inherit "/obj/generic_heal.c";
#include "/players/jareel/define.h"

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name(HIY+"Hell Stone"+NORM);
  add_alias("hell stone");
  add_alias("Hell Stone");
  add_alias("stone");
  add_alias("Stone");
  set_short(HIY+"Hell Stone"+NORM);
  set_long("A small yellow stone, you feel like you can 'focus' its 'stone'.\n");
  set_type("focuses");
  set_type_single("focus");
  add_cmd("focus");
  set_msg_precharges(HIW+"["+YEL);
  set_msg_postcharges(NORM+HIW+"]"+NORM);
  set_msg("You mutter a few words.\n"+
          "A black aura washes over you, you feel sick.\n");
  set_msg2(" is washed by a black aura.\n");
  set_heal(-50,-50);
  set_charges(3);
  set_stuff(-50);
  set_soak(-50);
  set_value(0);
}

post_charge_hook() {
   call_other(this_player(), "add_alignment", -50);
   write("You "+RED+"U "+HIR+"N "+NORM+RED+"L "+RED+"E "+NORM+RED+"A "+RED+"S "+NORM+RED+"H "+NORM+"the power of "+HIK+"Evil"+NORM+" as you focus the "+HIY+"Hell Stone"+NORM+"!!!!!!\n");
   say(this_player()->query_name()+" "+RED+"U "+HIR+"N "+NORM+RED+"L "+HIR+"E "+NORM+RED+"A "+HIR+"S "+NORM+RED+"H "+HIR+"E "+NORM+RED+"S"+NORM+"the power of "+HIK+"Evil"+NORM+" as you focus the "+HIY+"Hell Stone"+NORM+"!!!!!!\n");
}
query_save_flag() { return 1; }