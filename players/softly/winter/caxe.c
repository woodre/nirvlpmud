#include "/players/softly/misc/ansi.h"

inherit "/obj/weapon.c";

void reset(int arg) {
    ::reset(arg);
    if (arg) return;
    set_name("chrome axe");
    set_alias("axe");
    set_short("A "+HIW+"chrome axe"+NORM);
    set_long("A hardened axe coated with chrome.  This tool is\n"+
             "intended to allow the use to cut through ice, but\n"+
             "makes a good weapon should the need arise.\n");
    set_type("axe");
    set_class(17);
    set_weight(4);
    set_value(1500);
    set_hit_func(this_object());

  message_hit=({
    "ripped","",   
    "tore","",
    "split","",
    "hacked","",
    "gouged","",
    "sliced","",
    "chopped","",
  });
  return;
}

mixed weapon_hit(object attacker)
{
    int X;
    string att;
 
    X = random(6);
    if(X > 4)
    {
      att = (string)attacker->query_name();
      switch(random(2))
      {
        case 0:
          say("The axe rips a " + HIR + "bloody" + NORM + " tear in " + att + "'s flesh.\n", attacker);
          tell_object(attacker,
"The axe rips a " + HIR + "bloody" + NORM + " tear in your flesh.\n");
          write("The axe rips a " + HIR + "bloody " + NORM + "tear through " + att + "'s flesh.\n");
          break;

        case 1:
          tell_room(environment(environment()),
HIR +
"              /     /     /\n" +
"             /     /     /\n" +                     
"            /     /     /\n" +                
"           /     /     /\n" + NORM);
          say("\
The axe flays the flesh of " + att + "...\n", attacker);
          tell_object(attacker,"\
The axe flays evenly through your flesh...\n");
          write(
"The axe flays evenly through " + att + "...\n");
          break;
      }
    return 5;
    }
}


