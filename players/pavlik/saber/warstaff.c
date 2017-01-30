#define tp this_player()->query_name()

inherit "obj/weapon.c";
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

 reset(arg) {
    ::reset(arg);

    if (arg) return;
    set_name("staff of war");
    set_alias("staff");
    set_type("staff");         /* set type added by Pavlik */
    set_short("Staff of War");
    set_long("A long ironwood staff inlaid with mystic runes and wards.\n"+
             "The staff quivers in your hand.\n");
    set_read("You can not translate the runes on the staff.\n");
    set_class(17);
    set_weight(2);
    set_value(1500);
    set_hit_func(this_object());
        }
        
weapon_hit(attacker){

 if(call_other(this_player(), "query_attrib", "mag") > random(70)) {

  if(random(9) < 4)  {

  say("The Staff of War pulses with "+BOLD+"dark shadows"+NORM+" as it drains life from "
      +attacker->query_name()+".\n"+
      tp+" looks stronger.\n");
  write("The Staff of War pulses with "+BOLD+"dark shadows"+NORM+" as it drains life from "
      +attacker->query_name()+".\n"+
     "You feel stronger.\n");

  call_other(this_player(),"heal_self",5);
  call_other(attacker,"heal_self",-5);
  return 2;

        }
        
  else if(random(9) < 4)  {

  say("The Staff of War "+BOLD+HIR+"blazes"+NORM+" with "+BOLD+HIR+"FIRE"+NORM+" as it hits "
      +attacker->query_name()+".\n");
  write("The Staff of War "+BOLD+HIR+"blazes"+NORM+" with "+BOLD+HIR+"FIRE"+NORM+" as it hits "
      +attacker->query_name()+".\n");

    return 9;
        }

  else  {

  say("The Staff of War thunders with "+BOLD+HIR+"LIGHTNING"+NORM+" as it hits "
      +attacker->query_name()+".\n");
  write("The Staff of War thunders with "+BOLD+HIR+"LIGHTNING"+NORM+" as it hits "
      +attacker->query_name()+".\n");

  return 5;

        }
        }
    return;
        }

