#include "../tasks.h"
#include "/players/vertebraker/ansi.h"

#include "../def.h"
#include "../std.h"
#include "../macros.h"

#define TP this_player()
#define TPN this_player()->query_name()
#define TRU(x) tell_room(environment(TP), x)

status main(string str)
{
    object     flames, n;
    status     abc;

    needrank(2);
    if(this_player()->query_ghost()) return 0;
    needmana(24 - ((int)this_player()->query_guild_rank()));
    previous_object()->query_flames();

    needtask(FLAMES_TASK);
    if(str != "flames" && str != "flame"
       && str != "fire") return 0;

   if(present("shardak_fire",environment(this_player())))
    {
      notify_fail("\
You intone the dark spell, and the flames will not arise...\n");
      return 0;
    }    
    if(environment(TP)->query_no_fight())
    {
      notify_fail("\
This room is protected by some sort of magical means.\n");
      return 0;
    }
    if(0 == random(3))
    {
      write("You intone quietly...\n");
      say(TPN + " intones quietly...\n");
    }
    else if(0 == random(3))
    {
      write("You hold your head down in vigil...\n");
      say(TPN + " holds " + possessive(TP) + " head down in vigil...\n");
    }
    else if(0 == random(3))
    {
      write("You growl an unholy hymn...\n");
      say(TPN + " growls an unholy hymn...\n");
    }
    else if(0 == random(3))
    {
      write("You bow down and pray to Lord Shardak...\n");
      say(TPN + " bows down and begins a prayer...\n");
    }
    else
    {
      write("You kneel and pray to Shardak almighty.\n");
      say(TPN + " kneels and prays to Shardak.\n");
    }
    if(0 == random(3))
      TRU(RED + "\tA twisted, burning flame emerges...\n" + NORM);
    else if(0 == random(3))
      TRU(RED + "\tDark flames wither into view...\n" + NORM);
    else if(0 == random(3))
      TRU(RED + "\tA scorching flame explodes into the area...\n" + NORM);
    else if(0 == random(3))
      TRU(RED + "\tThe ground beneath your feet ignites...\n" + NORM
          + "Heat rises from the flame...\n");
    else if(0 == random(3))
      TRU(RED + "\tFlames explode all over...\n" + NORM);
    else
      TRU(RED + "\tFire blazes into the room...\n" + NORM);
    flames = clone_object(OBJDIR + "burn");
    present(OBJID, TP)->set_flames(flames);
    flames->set_owner(TP);
    flames->set_strength(80 + random((int)this_player()->query_guild_rank() * 2));
    while(n = present("nitropyr", this_player()))
    {
      if(creator(n) == "vertebraker") {
      if(!abc)
      {
        abc ++;
        write("The Nitropyr erupts into the flame!\n");
      }
      flames->set_strength((int)flames->query_strength() + random(6) + random(6) + random(6));
      destruct(n);
      this_player()->recalc_weight();
      }
    }
    TP->add_spell_point(-24-((int)TP->query_guild_rank()));
    move_object(flames, environment(TP));
    return 1;
}
