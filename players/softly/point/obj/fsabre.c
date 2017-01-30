#include "/players/softly/misc/ansi.h"

inherit "/obj/weapon.c";

void reset(int arg) {
    ::reset(arg);
    if (arg) return;
    set_name("french sabre");
    set_alias("sabre");
    set_short(BLK+BOLD+"Blackbeard's Sabre"+NORM);
    set_long("\
This French sabre is a cutlass with a very sharp\n\
long, thin blade.  The handle is wooden with hand\n\
hammered brass finishings.\n");
    set_type("sword");
    set_class(19);
    set_weight(2);
    set_value(2200);
    set_hit_func(this_object());

  message_hit=({
    "annihilated","",
    "decimated","",
    "ripped","",
    "tore","",
    "split","",
    "punctured","",
    "sliced","",   
  });
  return;
}

mixed weapon_hit(object attacker)
{
    int X;
    string att;
 
    X = random(4);
    if(X > 2)
    {
      att = (string)attacker->query_name();
      switch(random(2))
      {
        case 0:
          say(BOLD + BLK +"   The sabre cleanly slices a tear through "  + att + "'s flesh."+NORM+"\n", attacker);
          tell_object(attacker,BOLD + BLK +
"The sabre cleanly slices a tear in your flesh."+NORM+"\n");
          write(BOLD+BLK+"   The sabre cleanly slices a tear through " + att + "'s flesh."+NORM+"\n");
          break;

        case 1:
          say(BOLD + BLK+ "   The sabre slices through " + att + "'s flesh..."+NORM+"\n", attacker);
          tell_object(attacker,BLK+BOLD+"\
   The sabre\n\
                   s l i c e s\n\
                                     cleanly through your flesh..."+NORM+"\n");
          write(BOLD + BLK+"   The sabre slices through " + att + "..."+NORM+"\n");
          break;
      }
    return 7;
    }
}

query_save_flag() { 
  return 1; 
}
