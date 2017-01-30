#include "/obj/ansi.h"
#define GOB present("venom_object", targ)

object targ;

shadow_symbon(object a)
{
  if(!a) return 1;
  targ = a;
  shadow(targ,1);
  return 1;
}

shadow_symboff()
{
  shadow(targ,0);
  destruct(this_object());
  return 1;
}

destruct_this_shadow()
{
  destruct(this_object());
  return 1;
}

short()
{
  if(targ)
  {
    if(GOB)
    {
      if(GOB->query_venomed())
      {
        return HIW+capitalize((string)GOB->query_symbiote())+"   ("+NORM+HIR+" Symbiote "+NORM+HIW+")"+NORM;
      }
    }
  }
  else
  {
    return targ->short();
  }
  return targ->short();
}

query_symb_shadow() { return 1; }
