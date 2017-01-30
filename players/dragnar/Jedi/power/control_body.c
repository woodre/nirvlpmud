/* if skill is greater than 4 then will also destroy poison. Otherwise this spell
   will lower intox by skill level +10, soaked & stuffed by skill level. Cost of
   the spell is 20 - skill level. if the caster is darkside, then there is an 80%
   failure rate. */

#include <ansi.h>
#include "defs.h"
inherit CMDBASE;
#define skill previous_object()->query_skill("control_body")
#define color previous_object()->query_mon_color()
#define delay previous_object()->query_force_delay()

object bad_poison,next;
string f1,f2;

main(){

if(USER->query_ghost()){ return 0; }
if(skill_check(1)){ return 1; }
if(cp_check(31 - skill)){ return 1;}

if(delay){ 
	write("You are too weary to concentrate on that.\n");
	return 1;
	}

if(previous_object()->query_darkside() && random(100) < 80){
write("Your hatred boils up, clouding your thought and breaking your concentration.\n");
previous_object()->adj_cp(-(31 - skill));
return 1;
}

write(
""+color+"[]"+NORM+"You concentrate, allowing the force to flow into your body.\n"+
""+color+"[]"+NORM+"The dangerous toxins begin to dissipate, leaving you feeling whole again.\n");
USER->drink_alcohol(-(skill + 5));
USER->drink_soft(-(skill));
USER->eat_food(-(skill));

if(skill > 4){ 
 bad_poison = first_inventory(USER);

 while (bad_poison) {
      next = next_inventory(bad_poison);
 if (sscanf(file_name(bad_poison),"%spoison%s",f1,f2) == 2 ||
     bad_poison->id("poison")) {
     destruct(bad_poison);
     }
     bad_poison = next;
    }
   }
previous_object()->adj_cp(-(31 - skill));
USER->add_guild_exp(skill);
previous_object()->set_force_delay(5);
return 1;
 }
 
