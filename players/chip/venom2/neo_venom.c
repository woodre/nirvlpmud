/* known for IDEST as: new_venom_object (NOW KNOWN AS 'GI' */
#include "/players/chip/venom2/obj/variables.h"
#include "/players/chip/ansi.h"
#include "/players/chip/venom2/define.h"
#include "/players/chip/venom2/obj/clawstwo.h"
#include "/players/chip/venom2/obj/weapon.h"
#include "/players/chip/venom2/obj/list_skills.h"
#include "/players/chip/venom2/obj/absorb.h"
#include "/players/chip/venom2/obj/armor.h"
#include "/players/chip/venom2/obj/comm.h"
#include "/players/chip/venom2/obj/desc.h"
#include "/players/chip/venom2/obj/hb.h"
#include "/players/chip/venom2/obj/help.h"
#include "/players/chip/venom2/obj/id_init.h"
#include "/players/chip/venom2/obj/info.h"
#include "/players/chip/venom2/obj/invis.h"
#include "/players/chip/venom2/obj/monitor.h"
#include "/players/chip/venom2/obj/reset.h"
#include "/players/chip/venom2/obj/save.h"
#include "/players/chip/venom2/obj/settings.h"
#include "/players/chip/venom2/obj/skill_setup.h"
#include "/players/chip/venom2/obj/stored.h"
#include "/players/chip/venom2/obj/tentacles.h"
#include "/players/chip/venom2/obj/shaped_arm.h"
#include "/players/chip/venom2/obj/threat.h"


no_spell(){
	write("You cannot do that.\n");
	return 1;
}

/************************************************************
**      No quit - woot.                                     **
*************************************************************/
quit_out(){
	if(USER->query_attack()){
		write("You cannot quit out while in combat!\n");
		return 1;
	}
	save_venom();
	return;
}


