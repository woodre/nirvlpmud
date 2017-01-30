#include <ansi.h>
#define tp this_player()->query_name()

int DEATH, PART, W;

 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
     set_name("revenge");
     set_alias("blade");
     set_short("Part of a blade named \"Revenge\"");
    set_class(8);
    set_weight(2);
    set_value(6001);
    set_save_flag(1);
    set_hit_func(this_object());
}

long()  {
  write("Part of the legendary blade named REVENGE.\n");
  write("This was the weapon once used to defeat the Dream Thief.\n"+
       "The blade is "+this_object()->query_part()+"/13th forged.\n"+
       "The blade is silver, covered with crimson runes.\n");
        }

weapon_hit(attacker){
if(call_other(this_player(), "query_attrib", "pie") > random(60))  {

tell_room(environment(this_player()),
 HBYEL+"The blade"+NORM+""+HIR+""+BOLD+" REVENGE"+NORM+" "+HBYEL+"glows with a holy light"+NORM+".\n"+
  HIY+""+attacker->query_name()+""+NORM+" staggers and screams in pain.\n");

if(call_other(attacker, "id", "nightmare"))  {
if(call_other(this_player(), "query_attrib", "pie") > random(35)) {
 tell_room(environment(this_player()),

   "\n\n"+HIB+"REVENGE SLICES THROUGH "+attacker->query_name()+""+NORM+".\n\n");
  attacker->heal_self(-10);
  DEATH = attacker->query_death();
  DEATH = DEATH - 1;
  attacker->set_death(DEATH);
if(this_object()->query_part() > 12)  { attacker->set_ac(6);  }
if(DEATH < 1)  {
    attacker->heal_self(-10000);
        }
     }
     }
  return 8;
    }
    return;
}

query_part()   {  return PART; }
set_part(str)  {  PART = str;    }
