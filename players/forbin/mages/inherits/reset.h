#include "../def.h"

reset(arg)
{
	advance_checks();
	if(arg) return;

  if(!root())
    set_heart_beat(1);
}