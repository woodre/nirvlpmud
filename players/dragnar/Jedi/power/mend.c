#include <ansi.h>
#include "defs.h"
inherit CMDBASE;

#define skill previous_object()->query_skill("heal")
#define delay previous_object()->query_force_delay()
object target;

main(string str){

  string color;

color = previous_object()->query_mon_color();
if(USER->query_ghost()){ return 0; }
skill_type = "physical";
if( skill_check(1) ) return 1;
if(cp_check(25 - (skill))) return 1;
if(delay_check()) return 1;

if(previous_object()->query_darkside() && random(100) < 80){
write("Your hatred boils up, clouding your thought and breaking your concentration.\n");
previous_object()->adj_cp(-(25 - skill));
return 1;
}

if(!str || capitalize(str) == ""+USER->query_name()+""){
USER->add_hit_point((skill*2)+15);
write(
""+color+"[]"+NORM+"You concentrate briefly allowing the force to flow into your body.\n"+
""+color+"[]"+NORM+"Your skin, bone, and sinew mend, relieving you of pain.\n");
say(USER->query_name()+"'s wounds mend!\n");
previous_object()->adj_cp(-(25 - skill));
previous_object()->set_force_delay(3);
USER->add_guild_exp(skill + 5);
return 1;
 }
 
target = find_living(str);
if(str && present(target, environment(USER))){
skill_check(5);
target->add_hit_point(skill + 15);
write(
""+color+"[]"+NORM+"You focus your thoughts on "+capitalize(str)+", sensing their suffering and\n"+
""+color+"[]"+NORM+"pain. Suddenly their wounds begin to heal, relief spreading across their\n"+
""+color+"[]"+NORM+"face.\n");      
say(
USER->query_name()+" concentrates briefly on "+capitalize(str)+", mending their wounds.\n");
previous_object()->adj_cp(-(25 - skill));
previous_object()->set_force_delay(3);
USER->add_guild_exp(skill + 15);
    return 1;
    }
write("Heal what?\n");
return 1;
}      
