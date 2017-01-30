
/*
  Modified pentacle of defense from ~/forest/Obj/pentacle.c
  A reward for Cgi per Vertebraker's permission for turning
  in bugs.
*/


inherit "/obj/armor";
#include "/players/fred/ansi.h"
object poo, me, fool;
string mess1;
int r, p, X;

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("amulet");
  set_alias("glass");
  set_short(BOLD+BLK+"Legendary Glass Amulet"+NORM);
  set_long(
  "  A small amulet made entirely from glass.  Legend has it that a\n"+
  "powerful sorcerer once fired a lightning bolt that missed it's mark\n"+ 
  "and hit the desert sands.  The lightning turned some of the sand into\n"+
  "a large chunk of crystal clear glass.  A peasant found the glass and\n"+
  "used a small circlet of it to form a beautiful amulet.  It is said \n"+
  "that the glass still holds great power for whomever wears it.\n");
  set_type("amulet");
  set_ac(2);
  set_weight(1);
  set_value(0);
}

do_special(owner){
   int n;
   n = random(100);
   if(owner->query_real_name() != "cgi"){
    tell_object(owner, BOLD+RED+"\tOnly Cgi may wear this amulet.\n"+NORM);
    command("remove amulet", owner);
    return 1; } 
   if(n < 20){
    p = random(4);
    r = random(4);
    switch(p){
      case 0: mess1 = "   The amulet glows softly as it offers you some protection"; break;
      case 1: mess1 = "   The amulet's energy swirls around you"; break;
      case 2: mess1 = "   The amulet glows brightly as it builds up energy..."; break;
      case 3: mess1 = "   The amulet blows flecks of sand around the room"; break;
     }
    tell_object(owner,
    BOLD+YEL+mess1+NORM+".\n"); 
    X += r;
   return 1; 
 }
   if(X > 10){
    tell_object(owner,
    BOLD+YEL+"The amulet's energy "+BLK+"explodes"+YEL+" throughout the room!\n"+NORM);
     owner->heal_self(random(4));
    X -= 11;
   return 1; 
  }
}
