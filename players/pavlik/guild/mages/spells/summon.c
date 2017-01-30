#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("summon");
  set_name("Summon Dragon");
  set_color_name(HIBLK+"Summon "+NORM+GRN+"Dragon"+NORM);
  set_level(4);
  set_school("conjuration");
  set_sp_cost(SUMMON_COST);
  set_cost_string(SUMMON_COST+" sp + HeartStone");
  set_component_id("heartstone");
  set_component_string("HeartStone");
  set_descrip(
	"Use this spell to summon a powerful companion, the Mage's Dragon.  Dragons are " +
	"powerful allies that can assist in combat as well as help with other tasks.  They " +
	"can only be summoned from a special summoning chamber deep in the Mages Tower.\n" +
	"See Also: dragon\n"
  );
}


spell()
{
  /* empty container */
  /* see: guild/mages/room/summon_room.c */
}
