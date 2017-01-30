inherit "/players/forbin/closed/bfeq.c";
#include "/players/jaraxle/define.h"

reset(arg){
	if(arg) return;
	::reset();
	set_name("pants");
	set_alias("pants");
	set_short(""+NORM+""+RED+"Blood"+NORM+" stained pants");
	set_long("   Pants forged from some unknown material. There are"+RED+" blood\n"+
		""+NORM+"stains covering these pants. Although dirty, they seem to be\n"+
		"in amazing condition\n");

	set_ac(2);
	set_type("pants");
	set_weight(1);
	set_value(10000);
	set_bf_guild_bonus(0, 30);
	set_bf_guild_bonus(1, 40);
}
/* first # is which stat, second number is increase in that stat.
 0 = agility
 1 = might
 2 = accuracy
 3 = vigor
 4 = wisdom
 5 = faith
*/

do_special(owner) {
	if(!owner || !owner->query_attack()) return 1;
	if(!owner->is_player()) return 1;
	if(random(owner->query_attrib("luc")) > random(70)) {
		tell_object(owner, RED+"Blood "+NORM+"is absorbed through your pants.\n"+NORM);
		owner->add_spell_point(random(10));
		return 1; 
	}
}