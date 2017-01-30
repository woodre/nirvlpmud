#include "../defs.h"

int do_cmd(string str)
{
  object gob;
  object skin;

  if((int)TP->query_guild_rank() < 6)
    return 0;

  if((int)TP->query_level() < 10)
  {
    write("You must be at least level 10 to cast this spell.\n");
    return 1;
  }

  gob = previous_object();

  if((int)TP->query_sp() < 80)
  {
    write(NOSP_MSG);
    return 1;
  }

  if((int)gob->query_crystals() < 5)
  {
    write("You require 5 faeite crystals to cast this spell.\n");
    return 1;
  }

  if(present("crystalskin", TP))
  {
    write("You already have a crystalskin.\n");
    return 1;
  }

  skin = clone_object(OBJ_DIR + "crystalskin.c");
  move_object(skin, TP);
  skin->start(TP);

  write("You summon faeite crystals to encase your body in a sheathe of protective crystal.\n");
  say(TPN+" sheathes "+(string)TP->query_possessive()+" body in protective crystal.\n");
  TP->add_spell_point(-80);
  gob->add_crystals(-5);
  return 1;
}
