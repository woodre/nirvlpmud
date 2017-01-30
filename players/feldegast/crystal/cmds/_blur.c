#include "../defs.h"

int do_cmd(string str)
{
  object field, gob;

  if((int)TP->query_guild_rank() < 4)
    return 0;

  if((int)TP->query_sp() < 60)
  {
    write(NOSP_MSG);
    return 1;
  }

  gob = present(GUILD_ID, TP);

  if(!gob)
  {
    write("Error: No gob!\n");
    return 1;
  }

  if((int)gob->query_crystals() < 2)
  {
    write("You require two faeite crystals to perform this spell.\n");
    return 1;
  }

  field = present("crystal_blur_field", TP);

  if(field)
  {
    write(CYN+"You stop concentrating upon maintaining the blur field.\n"+NORM);
    field->stop();
    destruct(field);
    return 1;
  }

  write(CYN+"You refract the light around your body, creating a field of blurriness.\n"+NORM);
  say(CYN+TPN+" blurs the light around "+(string)TP->query_possessive()+" body.\n");
  field = clone_object(OBJ_DIR + "blur.c");
  field->start(TP);
  move_object(field, TP);
  TP->add_spell_point(-60);
  gob->add_crystals(-2);
  return 1;
}
