#include "../def.h"

status main(string str, object gob, object player)
{
  if(((int)gob->query_school_bonus("abju") +
      (int)gob->query_school_bonus("conj") +
      (int)gob->query_school_bonus("ench") +
      (int)gob->query_school_bonus("evoc") +
      (int)gob->query_school_bonus("divi") +
      (int)gob->query_school_bonus("illu") +
      (int)gob->query_school_bonus("necr") +
      (int)gob->query_school_bonus("tran") +
      (int)gob->query_attrib_bonus("power") +                              
      (int)gob->query_attrib_bonus("will power") +
      (int)gob->query_attrib_bonus("intelligence") +
      (int)gob->query_attrib_bonus("wisdom")) > 0)                  
    return (notify_fail(
    "You can not update while you have school or attribute bonuses.\n"), 0);
  tell_object(player,
    PGC+"["+SGC+"*"+PGC+"]"+TGC+" Updating Mage Guild Object.\n"+NORM);
  gob->update_gob();
  return 1;
}
