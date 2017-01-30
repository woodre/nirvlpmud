inherit "/obj/monster";
#include <ansi.h>
#include "/players/fred/closed/templar/defs.h"

object gob, grail;

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_name(HIR+"Dragon"+NORM);
    set_alias("dragon");
    set_short(BOLD+HIR+"A "+NORM+RED+"fiery"+BOLD+HIR+" Dragon"+NORM);
    set_race("dragon");
    set_long(
      "Heldurabhoricka the Mage is a legendary spell caster.  She is wearing a\n"+
      "long red robe with black lining that drags along the ground.  A book\n"+
      "of spells is visible beneath her robe.  She has long flowing auburn hair\n"+
      "that tumbles over her shoulders.\n");
    set_level(21);
    set_ac(30+random(4));
    set_hp(1500 +random(500));
    add_money(7500+random(2000));
    set_heal(10,2);
    set_wc(80+random(10));
    set_wc_bonus(43);
    set_aggressive(0);
    set_al(-1000);
    set_chat_chance(4);
    load_chat(short()+" roars.\n");
    load_chat(short()+" lights up the cave with a ball of flame.\n");
    load_chat(short()+" swishes it's tail back and forth.\n");
    load_chat(short()+" gazes over at you.\n");
    set_dead_ob(this_object());
  }
}


monster_died()
{
  write_file("/players/fred/closed/templar/quest", ctime(time())+"   "+
	  capitalize((string)AO->QRN)+" defeated "+short()+".\n");
  tell_room(environment(),
    short()+" lets out one final "+HIR+"B l A sT"+NORM+" of fire before it collapses\n"+
    "to the ground with a sickening "+BOLD+"ThUd"+NORM+".\n\n");
  move_object(clone_object("/players/fred/closed/templar/grail.c"), ENV);
  AO->hit_player(30+random(50), "other|fire");
  gob = present("KnightTemplar", AO)->set_complete(1);
  gob = present("KnightTemplar", AO)->save_ob();
}

tail_whip()
{
  if(!present(AO, ENV)) return 0;
  tell_room(environment(),
    "\nThe "+query_name()+" whips it's tail around in a wide arc.....\n\n"+
    "The tail "+BOLD+"SlAmS"+NORM+" into you throwing you into a nearby wall.\n\n");
  AO->hit_player(50+random(50));   
  return 1;
}

crush_him()
{
  if(!present(AO, ENV)) return 0;
  tell_object(AO,
   "\nThe "+query_name()+" charges at you pining you against the cave wall.\n\n"+
   "You feel the imense pressure squeeze the life out of you.\n");
   AO->hit_player(30+random(40));
   return 1;
}

fire_blast(){
  int i;
  object all_opp;
  all_opp = all_inventory(ENV);
  if(!present(AO, ENV)) return 0;
  for(i=0; i<sizeof(all_opp); i++)
  {
    if(all_opp[i]->is_player())
    {
      TR(ENV,
        "\n"+short()+" breaths a massive ball of fire into the air...\n\n"+
        BOLD+RED+"\t|\t |         |\t       |\n"+
        "\t   | \t |     |  \t  |\n"+
        "\t       |\t|      |   \t|    |\n"+
        "\t|        |\t    |     |         |\n\n"+NORM+
        "Bursts of "+BOLD+RED+"fire"+NORM+" rain down on you!\n");
      all_opp[i]->hit_player(60+random(30), "other|fire");
    }
  }
}

heart_beat()
{
  ::heart_beat();
  if(!ENV) 
    return ;
  if(!AO) 
    return ;
  if(!random(4)){    fire_blast();  return ;  }
  if(!random(5)){    tail_whip();   return ;  }
  if(!random(5)){    crush_him();   return ;  }
}
