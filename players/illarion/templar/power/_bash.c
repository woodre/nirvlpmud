/* _bash.c 
   Templar shield bash spell
*/

#include "../def.h"
#define COST      14
#define PIE       9
#define HONOR     50
#define GLEV      2
#define FIXED_DAM 5
#define RAND_DAM  25


status main(string arg, object gob, object play, object room) {
  object target;
  target=call_other(MASTER_DAEM,"get_target",arg,play,room);
  if(!check_combat_spell(play,target,