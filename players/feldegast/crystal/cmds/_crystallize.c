#include "../defs.h"

int do_cmd(string str)
{
  object corpse;
  int strength;
  object gob;

  if(str == "corpse")
  {
    corpse = present("corpse", environment(TP));
    strength = (int) corpse->query_corpse_level();
    if(strength > 0)
    {
      write("You cause the corpse's organic matter to crystallize.\n");
      say((string)TP->query_name()+" crystallizes a corpse.\n");
      strength /= 3 + random(2);
      if(strength > 0)
      {
        write("You collect "+CYN+strength+NORM+" crystals.\n");
        gob = present(GUILD_ID, TP);
        if(gob)
          gob->add_crystals(strength);
        else
          write("Error: No gob\n");
        destruct(corpse);
      }
      else
        write("  It crumbles beneath your touch.\n");
      return 1;
    }
    notify_fail("There is no corpse present.\n");
  }
  else if(str == "air")
  {
    if((int)TP->query_sp() < 60)
    {
      write(NOSP_MSG);
      return 1;
    }
    if(present("snow", environment(TP)))
    {
      write("It is already crystallizing.\n");
      return 1;
    }
    write("You crystallize the air.\n");
    say(TPN+" stretches "+(string)TP->query_possessive()+" hands into the air as the air chills.\n");
    move_object(clone_object(OBJ_DIR+"snow.c"), environment(TP));
    TP->add_spell_point(-60);
    call_out("snowing", 1, TP);
    return 1;
  }

}

void snowing(object ob)
{
  tell_room(environment(ob), "It has begun to "+HIW+"snow"+NORM+".\n");
}
  
