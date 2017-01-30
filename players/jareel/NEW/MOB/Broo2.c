#include "/players/eurale/defs.h"
inherit "obj/monster.c";
int i;
string def_mess;

reset(arg)  {
  i = 0;
  ::reset(arg);
  if(arg) return;


set_name(BOLD+"Death Knight"+NORM);
set_alias("death knight");
set_race("creature");
set_short(BOLD+"Death Knight"+NORM);
set_long(
        "  This Death Knight resembles a hulking knight, standing nearly\n"+
        "7 feet tall and weighing close to 350 pounds.  It's face is a\n"+
        "blackened skull with shards of shriveled, rotting flesh.  He\n"+
        "has two tiny, glowing red pinpoints for eyes.  His armor is\n"+
        "scorched black as if it had been in a fire.  His demeanor is\n"+
        "so terrifying that even kender have been known to become fright-\n"+
        "ened of him.  His deep, chilling voice seems to echo from the\n"+
        "depths of a bottomless cavern.  The DeathMace he carries has\n"+
        "ended many an adventurer's life.\n");

set_level(30);
set_hp(2800);
set_hp_bonus(600);
set_al(-1000);
if(!present("mace")) {
move_object(clone_object("players/eurale/Keep/OBJ/death_mace"),TO); }
init_command("wield mace");
if(!present("gloves")) {
move_object(clone_object("players/eurale/Keep/OBJ/hard_gloves"),TO); }
init_command("wear gloves");
set_wc(65);
set_ac(33);
set_heal(5,2);
set_aggressive(1);
set_dead_ob(this_object());
set_chat_chance(15);
  load_chat("The Death Knight grins:  hehehe!\n");
  load_chat("A death tingle runs down your spine...\n");
  load_chat("The DeathMace glints in the light....\n");
  load_chat("The Knight whispers: Say your prayers!\n");
set_a_chat_chance(15);
  load_a_chat("The Death Knight unleashes a vicious attack..\n");
  load_a_chat("The Death Knight screams: MEET YOUR MAKER!!\n");
  load_a_chat("You wince from the blow of the DeathMace!\n");
/*
set_chance(10);
set_spell_dam(40);
set_spell_mess1(
  BOLD+"\nThe Death Knight TOUCHES his target with an icy finger!"+NORM+"\n\n");
set_spell_mess2(BOLD+
  "\nThe Death Knight TOUCHES YOU with an icy finger!"+NORM+"\n\n");
*/
add_spell("attack", 0, 0,
/*
  "#HG#Death Knight#N# takes a deep breath.\n",
  "#HG#Death Knight#N# takes a deep breath.\n", */
    100,1,0,0, "big_heal" );

}

id(str) { return (::id(str) || str == "knight"); }
#include "/players/eurale/closed/aggro_hb.h"


monster_died() {
  tell_room(environment(this_object()),
  "\nYou have bested me this time... but "+BOLD+"I'LL BE BACK!"+NORM+"\n\n");
return 0; }

mass_attack(){
int i,z,a;
  ::heart_beat();
if(attacker_ob && present(attacker_ob,environment(this_object()))){
z = 2;
for(a=0;a<z;a++){
    already_fight = 0;
    this_object()->attack(attacker_ob);
}
}
}

big_heal( object target, object room, int damage ) {
int amt;

get_message();


amt = 200 + random(100);
if(this_object()->query_hp() < 350) {
  if(i <= 3){
tell_room(environment(),
  HIG+"Death Knight"+NORM+" laughs chaotically as "+RED+"demons"+NORM+" heal him.\n"+
  NORM);
  heal_self(amt);
  i += 1;
return 1; }
else
return 1;
}
}


get_message()
{
if(attacker_ob && present(attacker_ob,environment(this_object()))){
	  switch(random(6))
      {

         case 0:
         {
         	
         	tell_room(environment(), BOLD+"Death Knight"+NORM+" cringes as he absorbs the blow.\n");
         	break;
         }
         
         case 1: 
         {
         	
         	tell_room(environment(), BOLD+"Death Knight"+NORM+" deflects the attack.\n");
         	break;
         }
         
         case 2:
         {
         	
         	tell_room(environment(),BOLD+"Death Knight"+NORM+" parries some of the damage\n");
         	break;
         }
         
         case 3: 
         {
         
         	tell_room(environment(),BOLD+"Death Knight"+NORM+" defends the blow with ease.\n");
         	break;
         }
         
         case 4: 
         {
         	
         	tell_room(environment(),BOLD+"Death Knight"+NORM+" shrugs off the attack like it was nothing.\n");
         	break;
         }
         
         case 5: 
         {	
         	
         	tell_room(environment(),BOLD+"Death Knight"+NORM+" is unaffected by the attack.\n");
         	break;
         }
         
         default: 
         {
         	
         	tell_room(environment(), BLK+"THIS IS YOUR DEFAULT MESSAGE.\n");
         	break;
         }
         
	}

}}
	
/*
         if(msg==0)
         {
         	def_mess = BOLD+"Death Knight"+NORM+" cringes as he absorbs the blow.\n";
         	break;
         }
         
         elseif(msg==1) 
         {
         	def_mess = BOLD+"Death Knight"+NORM+" deflects the attack.\n";
         	break;
         }
         
         elseif(msg==2)
         }
         	def_mess = BOLD+"Death Knight"+NORM+" parries some of the damage\n";
         	break;
         }
         
         elseif(msg==3) 
         {
         	def_mess = BOLD+"Death Knight"+NORM+" defends the blow with ease.\n";
         	break;
         }
         
         elseif(msg==4) 
         {
         	def_mess = BOLD+"Death Knight"+NORM+" shrugs off the attack like it was nothing.\n";
         	break;
         }
         
         elseif(msg==5) 
         {	
         	def_mess = BOLD+"Death Knight"+NORM+" is unaffected by the attack.\n";
         	break;
         }
         
         else: 
         {
         	def_mess = BLK+"THIS IS YOUR DEFAULT MESSAGE.\n";
         	break;
         }
*/

