/*  A cloak that heals 30 pts, and then disappears */

inherit "obj/armor";
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

reset(arg){
   ::reset(arg);
   set_name("sun cloak");
   set_short("A cloak of "+BOLD+HIY+"golden"+NORM+" scales");
   set_alias("cloak");
   set_long("A "+BOLD+HIY+"golden"+NORM+" cloak woven from the scales of a Sun Drake.\n"+
            "It radiates warmth and healing.  To take advantage of\n"+
            "the properties of this cloak, type < "+BOLD+HIY+"sunheal"+NORM+" >\n");
   set_type("cloak");
   set_ac(1);
   set_weight(2);
   set_value(1500);
   set_save_flag(1);
      }

init()  {
  add_action("heal_me","sunheal");
        }


heal_me()  {
  
  write("The "+BOLD+HIY+"Sun Cloak glows with "+BOLD+HIY+"healing light"+NORM+".\n"+
        "You feel refreshed.\n");
  say(this_player()->query_name()+"'s cloak glows like then "+BOLD+HIY+"Sun"+NORM+".\n");
  command("drop sun cloak", this_player());
  tell_room(environment(), "The "+BOLD+HIY+"Sun Cloak"+NORM+" disappears.\n");
  this_player()->heal_self(30);
  destruct(this_object());
  return 1;
  
          }
