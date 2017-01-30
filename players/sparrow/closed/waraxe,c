#define USER environment()
#define ATT USER->query_attack()
#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";


reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("axe");
set_alias("war axe");
set_short("Vorpal War Axe");
set_long(
"  This is a huge grey War Axe. Its head is covered in\n"+
"glowing runes of power. The handle is made of a light\n"+
"weight metal, and wrapped in a black material. This\n"+
"weapon exudes a powerful aura of magic.\n");
set_type("axe");  
set_class(20);
set_weight(3);
set_value(30000);
set_hit_func(this_object());
set_save_flag(1);
}

weapon_hit(attacker){
string loc;
string dam1;
object corpse;

if(random(100) < 30){
switch(random(10) + 1){
case 10:   loc = "head";  dam1 = random(10) + 5;  break; 
case 6..9: loc = "chest"; dam1 = random(7) + 4;   break; 
case 3..5: loc = "arm";   dam1 = random(5) + 3;   break; 
case 1..2: loc = "leg";   dam1 = random(3) + 3;   break; 
default:   loc = "head";  dam1 = random(10) + 5;  break; 
}

tell_room(environment(USER),
"The War Axe hisses with magical energy as it slices the air!\n\n"+
"                 "+HIG+"- -- -- - S L I C E - - -- -"+NORM+"\n\n"+
"    "+ATT->query_name()+" is cut deeply in the "+loc+"!\n");
return dam1;
}


if(USER->query_attack() && ATT->query_hp() < 50){
if((ATT->query_hp()*10)/(ATT->query_mhp()) < 1 && ATT->is_npc()){
tell_room(environment(USER),
"The Vorpal Axe hums loudly...\n\n"+
"    "+HIR+"------ - -- --- C U T --- -  ------ ------"+NORM+"\n\n"+
"      "+ATT->query_name()+"'s head rolls to the ground.\n");
if(!present("head", environment(USER))){
    corpse = clone_object("obj/treasure");
    corpse->set_id("head");
    corpse->set_short("the head of "+ATT->query_name()+"");
    corpse->set_long("This is the head of "+ATT->query_name()+". It was chopped off\n"+
                     "by "+USER->query_name()+"'s Vorpal Axe.\n");
    corpse->set_weight(1);
    corpse->set_value(10);
    corpse->set_save_flag(1);
    }
    move_object(corpse, environment(USER));
    ATT->heal_self(-(ATT->query_hp()));
    return 50;
    }
 return 0;
 }
return 0;
}