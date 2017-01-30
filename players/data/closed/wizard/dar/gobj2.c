/*
Warrior Profession Object   06.28.01
By - Maledicta
*/

#define CSC RED+"~"+HIR+"{}"+NORM
#define SCS HIR+"{}"+NORM+RED+"~"+NORM

#include "/players/maledicta/closed/w/defs.h"
#include "/players/maledicta/closed/w/test_obj4/variables.h"
#include "/players/maledicta/closed/w/test_obj4/paladin.h"
#include "/players/maledicta/closed/w/test_obj4/monk2.h"
#include "/players/maledicta/closed/w/test_obj4/knight.h"
#include "/players/maledicta/closed/w/test_obj4/berserker.h"
#include "/players/daranath/closed/w/obj/assassin.h"
#include "/players/maledicta/closed/w/test_obj4/adv_test.h"
#include "/players/maledicta/closed/w/test_obj4/armor_test.h"
#include "/players/maledicta/closed/w/test_obj4/reset.h"
#include "/players/maledicta/closed/w/test_obj5/init.h"
#include "/players/maledicta/closed/w/test_obj4/desc.h"
#include "/players/maledicta/closed/w/test_obj4/leave_guild.h"
#include "/players/maledicta/closed/w/test_obj4/offhand.h"
#include "/players/maledicta/closed/w/test_obj4/cmds.h"
#include "/players/maledicta/closed/w/test_obj4/wimpy.h"
#include "/players/maledicta/closed/w/test_obj4/title.h"
#include "/players/maledicta/closed/w/test_obj4/skill_listing.h"
#include "/players/maledicta/closed/w/test_obj5/id.h"
#include "/players/maledicta/closed/w/test_obj4/extras.h"
#include "/players/maledicta/closed/w/test_obj4/help.h"
#include "/players/maledicta/closed/w/test_obj4/save.h"
#include "/players/maledicta/closed/w/test_obj5/gen_wc.h"
#include "/players/maledicta/closed/w/test_obj5/heart_beat.h"
#include "/players/maledicta/closed/w/test_obj4/sense.h"
#include "/players/maledicta/closed/w/test_obj5/score.h"
#include "/players/maledicta/closed/w/test_obj4/inv.h"
#include "/players/maledicta/closed/w/test_obj4/settings.h"
#include "/players/maledicta/closed/w/test_obj4/endurance.h"
#include "/players/maledicta/closed/w/test_obj4/monk_help.h"
#include "/players/maledicta/closed/w/test_obj4/paladin_help.h"
#include "/players/maledicta/closed/w/test_obj4/knight_help.h"
#include "/players/maledicta/closed/w/test_obj4/berserker_help.h"






/******** TESTING PURPOSES *************/
set_tskill(int i, int x){ skills[i] = x; }
set_up(){
if(this_player()->query_real_name() != "maledicta" && 
   this_player()->query_real_name() != "wartest") return;
   monk = 1;
   knight = 1;
   paladin = 1;
   berserker = 1;
   blood = 1;
   time = 1;
   mind = 1;
   glvl = 60;
   endurance = query_max_end();
   skills[120] = 5;
   skills[123] = 5;
   skills[124] = 5;
   skills[121] = 5;
   skills[33] = 10;
   skills[100] = 1;
   skills[101] = 5;
   skills[102] = 5;
   skills[103] = 5;
   skills[104] = 5;
   skills[89] = 1;
   skills[90] = 5;
   skills[91] = 5;
   skills[92] = 5;
   skills[93] = 5;
   skills[94] = 1;
   skills[95] = 1;
   skills[96] = 5; 
   skills[97] = 5;
   skills[98] = 5;
   skills[99] = 5;
   skills[80] = 5;
   skills[30] = 5;
   skills[81] = 5;
   skills[85] = 5;
   skills[21] = 5; 
   skills[22] = 5;
	skills[70] = 2;
	skills[30] = 10;
	skills[31] = 5;
	skills[15] = 5;
	skills[16] = 5;
	skills[17] = 5;
	skills[18] = 5;
	skills[19] = 5;
	skills[20] = 5;
	skills[32] = 5;
	skills[40] = 5;
	skills[41] = 5;
	skills[50] = 3;
	skills[60] = 3;
	skills[1] = 10;
	skills[2] = 10;
	skills[3] = 10;
	skills[4] = 10;
	skills[5] = 10;
	skills[6] = 10;
write("done.\n");
	return 1;
}













