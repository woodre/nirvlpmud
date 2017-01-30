/* Ice Crystals are a watererd down version of Ice Spheres */

inherit "/obj/treasure.c";
#include "/sys/ansi.h"

status flag_melt; 

  is_heal() { return 1; }

  query_save_flag() { return 1; }

  id(str) { return str == "ice crystal" || str == "crystal"; }

  short() { 
   return 
    "An "+HIC+"Ice"+NORM+" Crystal"+(flag_melt ? " ("+HIC+"melting"+NORM+")":""); }

  long() {
   write("This is a rystal of "+HIC+"bluish ice"+NORM+". It glows with a strange magical power.\n"+
        "You become aware that you are able to '"+HIY+"apply crystal"+NORM+"' to heal your wounds.\n");
   return 1;
}

  query_weight() { return 1; }
    get() { return 1; }
    value() { return 0; }

  init() {
    add_action("apply_sphere","apply");
}

  int healnum;

  reset(arg) {
    if(!arg) healnum = 3;
}

  apply_sphere(str) {
    if(!str) { write("Apply what?\n"); return 1; }
    if(str == "crystal") {
    if(environment() != this_player()) return 0;
      this_player()->heal_self(50);
      write("You apply the "+BLU+"Crystal"+NORM+" to your wounds and they instantly feel much better.\n"+
        HIC+".:::::::::::::HP["+HIB+this_player()->query_hp()+NORM+"/"+
        HIB+this_player()->query_mhp()+NORM+"]"+HIC+"::"+NORM+HIC+"SP"+NORM+"["+HIB+this_player()->query_sp()+NORM+
          "/"+HIB+this_player()->query_msp()+NORM+"]"+HIC+":::::::::::::. \n"+NORM);
    if(healnum == 3) {
      write("The "+HIC+"Ice"+NORM+" Crystal begins to melt quickly... soon it will be gone.\n");
      flag_melt = 1;
      call_out("melt",400);
    }
    say(capitalize(this_player()->query_name())+" applies an "+HIC+"Ice"+NORM+" Crystal.\n");
    healnum --;
    if(healnum < 1) {
      write("You have just used up the last heal of the "+HIC+"Ice"+NORM+" Crystals. It is gone.\n");
      destruct(this_object()); 
      this_player()->recalc_carry();
      return 1;
    }
    return 1;
  }
}
 
melt() {
  object ob;
  ob = environment();
  if(!ob) return;
  tell_object(ob, "Your "+HIC+"Ice"+NORM+" Crystal melts away into nothing!\n");
  destruct(this_object());
  if(ob->is_player()) ob->recalc_carry();
  return 1;
}

quest_ob() { return 1; }
query_charges() { return healnum; }
