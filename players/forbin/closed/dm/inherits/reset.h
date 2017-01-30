#include "../defs.h"

void reset(int arg)
{
	if(arg) return;

 call_out("light_damage", 3);

  if(!root())
    set_heart_beat(1);
}
