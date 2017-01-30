/*  Level 4 Control Spell: Heal - Heals Hps for Sps at a loss. Range is 5-30 hps
healed, with an mp cost of sps spent divided by 5.  Real Ratio is therefore
5:6, or something like that. This is a 5th glevel ability, which means a lot.   */

#include "/players/chip/venom2/sdefine.h"


main(string str, object gob, object player)
{
	int woot;
	
	if(USER->query_ghost()) return 0;
	if(CON < 5) return 0;
	if(!str){ tell_object(USER, "heal <amount>  range of 5- "+(CON * 5)+"\n"); return 1; }
	
	sscanf(str, "%d", woot);
	if(!woot){ tell_object(USER, "heal <amount>  range of 5- "+(CON * 5)+"\n"); return 1; }
	if(woot < 5){ tell_object(USER, "heal <amount>  range of 5- "+(CON * 5)+"\n"); return 1; }
	if(woot > CON*5){ tell_object(USER, "heal <amount>  range of 5- "+(CON * 5)+"\n"); return 1; }
	if(USER->query_sp() < woot){ tell_object(USER, "You lack the energy to perform a heal.\n"); return 1; }
	USER->add_spell_point(-woot);
	USER->add_hit_point(woot);
	GOB->add_mp(-(woot/6));
	tell_object(USER,
		COLOR+"(heal)"+NORM+"  You concentrate and will your symbiote to heal your wounds.\n"+
	"             "+COLOR+"HPS: "+NORM+USER->query_hp()+"/"+USER->query_mhp()+"\n");
	tell_room(environment(USER),
	USER->query_name()+" closes "+USER->POS+" eyes and "+USER->POS+" wounds close.\n", ({USER}));
	return 1;
}
