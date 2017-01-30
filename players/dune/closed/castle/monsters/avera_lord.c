inherit "obj/monster";
#include "definitions.h"


id(str)
{
  return str == "sithi" || str == "lord" || str == "avera";
}


reset(arg)
{
  if (!present("stone"))
  {
    move_object(clone_object(CASTLEOBJECT+"/mayesa.c"),
                this_object());
  }

  ::reset(arg);
  if(arg) return;
  set_name("Avera");
  set_race("sithi");
  set_alias("sithi");
  set_short("Avera, the Sithi Lord");
  set_long(
"     Avera is a strong, pretty Sithi with a wild look about her.\n"+
"She seems electric in attitude and her stare bears down on you.\n"+
"Avera sees the world turn many times in her quick glance.\n"+
"She wears a purple blouse and skirt that flow lightly in the wind.\n");
  set_level(14);
  set_hp(random(20)+215);
  set_al(-600);
  set_wc(17);
  set_ac(12);
}
