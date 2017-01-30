#define _MULTICOLOR_

#include "../defs.h"


int do_cmd(string str)
{
  object gob;
  object ob;
  object targ;

  if( (int)this_player()->query_guild_rank() < 5 )
    return 0;

  if(!str)
  {
    if( (int)this_player()->query_sp() < 60 )
    {
      write(NOSP_MSG);
      return 1;
    }

    gob = previous_object();
    if(gob->query_crystals() < 3)
    {
      write("You require 3 faeite crystals to cast this spell.\n");
      return 1;
    }

    this_player()->add_spell_point(-60);
    gob->add_crystals(-3);

    tell_room(environment(TP), rand_color() + 
      TPN+" throws three crystals into the air.  They reach an altitude of several meters and\n"+
      "then hang in the sky.  Suddenly, they begin flashing "+multi_color("multicolored lights")+", blinding\n"+
      "everyone within eyesight!\n"+NORM
    );

    ob = first_inventory(environment(TP));
    while(ob)
    {
      if(living(ob))
      {
        if( (object)ob->query_attack() )
          ob->stop_fight();
        if( (object)ob->query_attack() )
          ob->stop_fight();
        if( (object)ob->query_hunter() )
          ob->stop_hunter();
        tell_room(environment(TP), rand_color() + (string)ob->query_name() + " is dazzled by the lights!\n"+NORM);
      }
      ob = next_inventory(ob);
    }
  }
  else        /* if(str) */
  {
    targ = present(str, environment(TP));

    if(!targ)
    {
      notify_fail("There is no '"+str+"' here.\n");
      return 0;
    }

    if( (int)this_player()->query_sp() < 40 )
    {
      write(NOSP_MSG);
      return 1;
    }

    gob = previous_object();
    if(gob->query_crystals() < 1)
    {
      write("You require a faeite crystal to cast this spell.\n");
      return 1;
    }

    this_player()->add_spell_point(-40);

    tell_room(environment(TP),
      TPN + multi_color(" dazzles ") + (string)ob->query_name() + " with multicolored lights!\n");
    if( (object)targ->query_attack() )
      targ->stop_fight();
    if( (object)targ->query_attack() )
      targ->stop_fight();
    if( (object)ob->query_hunter() )
      targ->stop_hunter();
    ob = first_inventory(environment(targ));
    while(ob)
    {
      if(living(ob))
      {
        if( (object)ob->query_attack() == targ)
          ob->stop_fight();
        if( (object)ob->query_attack() == targ)
          ob->stop_fight();
        if( (object)ob->query_hunter() == targ)
          targ->stop_hunter();
      }
      ob = next_inventory(ob);
    }
    return 1;
  }
}
