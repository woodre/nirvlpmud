#include "/players/jaraxle/define.h"
#include "def.h"

inherit "/obj/clean";

inherit "/players/vertebraker/closed/std/m_efuns";

int Quickening, TYPE;
string *saved_stats, *saved_tasks, WeaponPath, Sheathed;
mapping Stats, Tasks;

extra_look(){
switch(random(12)){
case 0..1: TYPE = ""+HIC+"water droplet"+NORM+"";
break;
case 2..3: TYPE = ""+HIR+"flickering fire"+NORM+"";
break;
case 4..5: TYPE = ""+HIC+"chil"+HIW+"ling ic"+HIB+"icle"+NORM+"";
break;
case 6..7: TYPE = ""+GRN+"tree leaf"+NORM+"";
break;
case 8: TYPE = " g*omanc*r ";
}
write("A ~"+TYPE+"~ necklace.\n");
return ; }
void
save_it()
{

    if(!environment()) return;
    saved_tasks = deconstruct_mapping(Tasks);
    saved_stats = deconstruct_mapping(Stats);
    save_object(SAVE_PATH + (string)environment()->query_real_name());
}

void
restore_it()
{
    if(!environment()) return;
    restore_object(SAVE_PATH + (string)environment()->query_real_name());
    Stats = reconstruct_mapping(saved_stats);
    Tasks = reconstruct_mapping(saved_tasks);
}

#include "object/all.h"

