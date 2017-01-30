/*****************************************************************************
                    present.c (c) by Ugh (06-Jun-1994) 
            finds also objects whose ids end with a number
*****************************************************************************/

#include <ctype.h>
#include <inventory.h>

#if 1  // Alfe 2002-Sep-13
#define AL_ID(ob, str) (this_player() && this_player()->query_int() < 1 && \
                        objectp(ob) && !living(ob)?                        \
                        (str)=="thing" || (ob)->id(str) : (ob)->id(str))
#else
#define AL_ID(ob, str) ((ob)->id(str))
#endif

varargs object
present(mixed ob, mixed where)
{
  int i, size ;
  object *inv;
  string pure_ob;
  object h;

  if (where)
  {
    if (stringp(ob))
    {
      inv = INVENTORY(where,0);
      for (i = sizeof(inv); i; i--)
        if (AL_ID(inv[<i],ob))
          return inv[<i];
        else if (h = inv[<i]->get_component(ob, 1))
          return h;
      // next line by sunblood 23-jun-1999
      if (ob[<1] < '0' || ob[<1] > '9')
        return 0;
      // following if inserted for 'last' functionality by Alfe 01-Feb-13
      // put it _inside_ the 'string' case -- Ugh 01-Sep-21
      if (ob[<3..<1] == " -1") {  // eg "last" given as ordinal
        pure_ob = ob[0..<4];  // cut off -1
        for (i=sizeof(inv); i-->0; )
          if (AL_ID(inv[i],pure_ob))
            return inv[i];
      }
    }
    return efun::present(ob, where);
  }
  else if (previous_object())
    return present(ob, previous_object()) || 
           (environment(previous_object()) && 
            present(ob, environment(previous_object())));
}
