#include "../defs.h"

int do_cmd(string str)
{
  object gob, comp, ball;

  if(str == "light")
  {

    if((int)TP->query_level() < 5)
    {
      write("You must be at least level 5 to cast this spell.\n");
      return 1;
    }

    if((int)TP->query_sp() < 20)
    {
      write(NOSP_MSG);
      return 1;
    }

    gob = previous_object();
    if((int)gob->query_crystals() < 1)
    {
      write("You require a faeite crystal to cast this spell.\n");
      return 1;
    }

    if(present("light crystal", TP))
    {
      write("You already have one.\n");
      return 1;
    }

    if(!((int)TP->add_weight(1)))
    {
      write("You are already carrying too much!\n");
      return 1;
    }
    write("You take a faeite crystal out of your belt pouch and infuse it with energy.\n"+
          HIY+"It glows brightly.\n"+NORM);
    say(TPN+" summons a light crystal.\n");
    gob->add_crystals(-1);
    TP->add_spell_point(-20);
    move_object(clone_object(OBJ_DIR+"light.c"), this_player());
    return 1;
  }


  if(str == "crystal ball")
  {

    if((int)TP->query_guild_rank() < 3)
      return 0;

    if((int)TP->query_level() < 10)
    {
      write("You must be at least level 10 to cast this spell.\n");
      return 1;
    }

    if((int)TP->query_sp() < 60)
    {
      write(NOSP_MSG);
      return 1;
    }

    gob = previous_object();
    if((int)gob->query_crystals() < 3)
    {
      write("You require 3 faeite crystals to cast this spell.\n");
      return 1;
    }

    comp = present("mirror", TP);
    if(!comp || (int)comp->drop())
    {
      write("This spell requires a mirror to cast.\n");
      return 1;
    }

    if(present("crystal_mage_ball", TP))
    {
      write("You already have one.\n");
      return 1;
    }

    if(!((int)TP->add_weight(2)))
    {
      write("You are already carrying too much!\n");
      return 1;
    }

    write(BOLD+"You magically form a crystal ball from the mirror and three faeite crystals.\n"+NORM);
    say(TPN+" summons a crystal ball.\n");
    TP->add_weight(-((int)comp->query_weight()));
    destruct(comp);
    gob->add_crystals(-3);
    TP->add_spell_point(-60);
    move_object(clone_object(OBJ_DIR+"crystal_ball.c"), this_player());
    return 1;
  }

  if(str == "faecrystal")
  {

    if((int)TP->query_guild_rank() < 5)
      return 0;

    if((int)TP->query_level() < 15)
    {
      write("You must be at least level 15 to cast this spell.\n");
      return 1;
    }

    if((int)TP->query_sp() < 120)
    {
      write(NOSP_MSG);
      return 1;
    }

    gob = previous_object();
    if((int)gob->query_crystals() < 4)
    {
      write("You require 4 faeite crystals to cast this spell.\n");
      return 1;
    }

    comp = present("heartstone", TP);
    if(!comp || (int)comp->drop())
    {
      write("This spell requires a heartstone to cast.\n");
      return 1;
    }

    if(present("faecrystal", TP))
    {
      write("You already have one.\n");
      return 1;
    }

    if(!((int)TP->add_weight(1)))
    {
      write("You are already carrying too much!\n");
      return 1;
    }

    write(HIR+"You fuse the faeite crystals to the heartstone with magical heat,\n"+
              "and then imbue it with mystical energy to form a faecrystal.\n"+NORM);
    say(TPN+" summons a faecrystal.\n");
    TP->add_weight(-((int)comp->query_weight()));
    destruct(comp);
    gob->add_crystals(-4);
    TP->add_spell_point(-120);
    move_object(clone_object(OBJ_DIR+"faecrystal.c"), this_player());
    return 1;
  }

  if(str == "phantasm")
  {
    if((int)TP->query_guild_rank() < 3)
      return 0;

    if((int)TP->query_level() < 12)
    {
      write("You must be at least level 12 to cast this spell.\n");
      return 1;
    }

    if((int)TP->query_sp() < 100)
    {
      write(NOSP_MSG);
      return 1;
    }

    gob = previous_object();
    if((int)gob->query_crystals() < 4)
    {
      write("You require 4 faeite crystals to cast this spell.\n");
      return 1;
    }

    /* This can only be cast in the focusing chamber beneath the crystal tower. */
    if((string)environment(TP)->query_focus() != "crystalmage")
    {
      write("You have difficulty casting this spell in this place.  It seems\n"+
            "to lack...Focus.\n");
      return 1;
    }

    /* Note: New phantasm will scare away the old one. */

    write(HIC+"You carefully place four faeite crystals around the chamber and then\n"+
              "begin your meditations.  A spear of light shoots from your lifecrystal\n"+
              "and bounces around the chamber, hitting the faeite crystals and forming\n"+
              "a latticework of energy.  In your mind, you construct the most ghastly and\n"+
              "horrible monster imaginable, a hideous shade to strike fear into the\n"+
              "hearts of men.  When your eyes open, you see the phantasm before you,\n"+
              "constructed out of light and shadow.\n"+NORM);
    say(TPN+" summons a phantasm.\n");
    gob->add_crystals(-4);
    TP->add_spell_point(-100);
    comp = clone_object(GUILD_DIR+"mon/phantasm.c");
    comp->set_master(TP);
    move_object(comp, environment(this_player()));
    return 1;
  }

  notify_fail(capitalize(query_verb())+" what?\n");
  return 0;
}
