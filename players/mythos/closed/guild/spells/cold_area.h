#include "/players/mythos/closed/guild/def.h"
cold_area(str)
{
  int hm;
  object ob, ob2, ob3;
  string title;
  if(!str)
  {
    if(qtf < 10) { write("Your control over fae is not enough!\n"); return 1;}
    if(tsp < 75) { write("You do not have enough energy!\n"); return 1;}
    if(scrp < 200) { write("The darkness calls for a sacrifice.\n"); return 1;}

    tp->add_spell_point(-75);
    pp->add_sacrifice(-200);
    if(!present("chill_factor",tp))
    {
      ob2 = clone_object("/players/mythos/closed/guild/spells/cshield.c");
      move_object(ob2,tp);
      ob2->set_dam(4);
      ob2->set_need(100);
      write("You allow the cold within you to envelope the room.\n"+
            "You may turn it off by typing <cold_area stop>.\n");
      say("The room suddenly becomes colder.\n");
    }
    ob=all_inventory(environment(tp));
    for(hm=0;hm<sizeof(ob);hm++)
    {
      if(!living(ob[hm]) && !(ob[hm]->query_shatter_proof()))
      {
        tell_room(environment(tp),
          BLU+"COLD FIRE"+NORM+" snakes out from "+capitalize(tpn)+
          " and strikes "+ob[hm]->short()+"- shattering it!\n");
          
        if(ob[hm]->weapon_class()) { ob[hm]->weapon_breaks();}
        if(ob[hm]->armor_class())
        {
          ob[hm]->set_ac(0);
          ob[hm]->set_value(0);
          title=ob[hm]->short();
          ob[hm]->set_short(title+" <broken>"); 
          ob->set_broke(1);
        }
        if(!(ob[hm]->armor_class()) && !(ob[hm]->weapon_class()) && ob[hm]->short())
        {
          ob[hm]->set_value(0);
          title = ob[hm]->short();
          ob[hm]->set_short(title+" <shattered>");
          ob[hm]->set_save_flag(0);
        }
      }
    }
  }
  if(str && str == "stop")
  {
    write("You dampen your aura of cold.\n");
    tell_room(environment(tp),"The room warms up suddenly.\n");
    destruct(present("chill_factor",tp));
    return 1;
  }
  if(str && str != "stop")
    return 0;

  return 1; }
