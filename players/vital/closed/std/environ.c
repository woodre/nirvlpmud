#include "/players/vertebraker/ansi.h"
#include "../macros.h"
#define COST 10
status
main()
{
    int f;
    object e, t;
    string r, a;

    needmana(COST);
    write("\
You lift your head up reverently.\n\
The dark gods enter your mind with information...\n\n");

    t = this_player();

    say((string)t->query_name() + " lifts up " + possessive(t) 
    + " head.\n");

    if(!(e = environment(t)))
    {
      notify_fail("\
The area around you is void...\n\
Nothing seems to make any sense.\n");
      return 0;
    }

    r = (string)e->realm();

    if(r == "LA" || (r == "NT" && !e->okay_follow()))
    {
      write(HIB + "\
*" + NORM + " You are unable to follow using any traditional means\n\
  within this environment.\n");
      f = 1;
    }
    if(r == "NT")
    {
      write(HIC + "\
*" + NORM + " Some sort of force field shrouds the area.\n");
      f = 1;
    }
    if(r && r != "NT" && r != "LA" && r != "NM")
    {
      write(HIG + "\
*" + NORM + " The area seems to have some sort of aura\
 around it, but you\n cannot put your finger on it.\n");
      f = 1;
    }
    if((status)e->query_no_fight())
    {
      write(HIW + "\
*" + NORM + " \
Combat may not begin within your present environment.\n");
      f = 1;
    }
    if((status)e->query_spar_area())
    {
      write(HIM + "\
*" + NORM + "\
 Your environ has been designated a sparring arena.\n");
      f = 1;
    }
    if(a = (string)t->query_fight_area())
    {
      if(a == file_name(e))
      write(HIR + "\
*" + NORM + " The blood of another player may be spilt here.\n");
      else t->clear_fight_area();
      f = 1;
    }
    if((status)e->query_NM() || r == "NM")
    {
      write(BOLD + "\
*" + NORM + " Magical energy seems to die around you.\n");
      f = 1;
    }
    if(!f)
      write("\
There is nothing special about your particular environment.\n");

    t->add_spell_point(-COST);
    return 1;
}
