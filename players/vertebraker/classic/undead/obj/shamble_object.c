#include "../lib/guild_defs.h"

status id(string str)
{
  return (str=="shamble_object");
}

void reset(status x)
{
  if(x) return;
  call_out("hmm", 3);
}

void init()
{
  object x;
  if((x=TP) && !x->QueryArmor(TO))
    x->RegisterArmor(TO, ({"physical",(1+random((int)x->QA("dex")/10)),0,"do_special"}));
}
