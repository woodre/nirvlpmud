/*****************************************************************************
 *      File:                   bwo_template.c
 *      Function:               BWO Monk Generator
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2006 Sparrow 
 *                              All Rights Reserved.
 *      Source:                 03/14/06
 *      Notes:                 
 *      Change History:         03/17/06 Sparrow: Added proper headers to file
 *                              03/18/06 Sparrow: Added spells for demon race
 *                              03/18/06 Sparrow: Added more spells
 *                              03/20/06 Sparrow: Added darkness spell
 *                              03/20/06 Sparrow: Added change focus spell
 *                              04/12/06 Sparrow: Added gear cloning and equip
 *                              09/22/06 Sparrow: Changes to make compatable
 *                                       with LDmud driver.
 *                              09/23/06 Sparrow: Added roaming
 *                              09/23/06 Sparrow: Changed way monk gear is
 *                                       determined. Now minimum pieces of
 *                                       gear is 2, maximum is 5. 
 ****************************************************************************/
#include "/sys/ansi.h"
#include "/players/sparrow/areas/bwo/include/defs.h"
inherit "/players/sparrow/cont_addition/mob_funcs.c";
inherit "/players/sparrow/cont_addition/gear_funcs.c";
#define QP this_object()->query_possessive()
inherit "/obj/monster";
int ac_mod,wc_mod,hp_mod;
int *gear_chances;
int *slots_checked;
string *gear_slots;
int remaining_chances,random_chance,bonus_modifier,random_slot;
string current_slot;
object ob;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  /* Added to make compatable with both drivers */
  if(version() == "3.01.02-DR"){
    string race,gender;
    /*GLOBALS*/
    object Target;
  }  
  /* Generation of Equipment - minimum of 1 items, maximum of 5
     very difficult to gain more than 3 pieces */
     
  bonus_modifier = 0;
  gear_slots = allocate(5);
  gear_chances = allocate(5);
  slots_checked = allocate(5);
  gear_slots = ({"amulet","necklace","bracelet","earring","ring"});
  /* It will attempt to load 5 accessories to the mob the percentages in order:
     100%, 80%, 30%, 20%, 10% */
  gear_chances = ({-1,1,6,7,8});
  slots_checked = ({0,0,0,0,0});
  remaining_chances = 5;
  
  while(remaining_chances > 0) {
    random_chance = random(5);
    while(slots_checked[random_chance] == 1) {
      random_chance = random(5);
    }
    
    slots_checked[random_chance] = 1;
    if(random(10) > gear_chances[random_chance]) {
      random_slot = random(5);
      while(gear_slots[random_slot] == "used") {
        random_slot = random(5);
      }
      
      current_slot = gear_slots[random_slot];
      gear_slots[random_slot] = "used";
      ob=generate_accessory(current_slot, random(2)+1);
      move_object(ob, this_object());
      init_command("wear "+current_slot);
      bonus_modifier++;
    }
    
    remaining_chances--;
  }
  
  race = random_race();
  gender = random_sex();
  set_name("Black Willow Monk");
  set_alias("monk");
  set_short(HIW+"M"+HIK+"onk of the "+HIW+"B"+HIK+"lack "+HIW+"W"+HIK+
  "illow "+HIW+"O"+HIK+"rder "+HIB+"["+HIK+capitalize(race)+HIB+"]"+NORM);
  set_long(
    HIK+"The main defensive force of the Black Willow Order, these monks are\n"+
    "trained by the Black Willow himself. Having hand to hand combat skills\n"+
    "that border on the super-natural, some say that they must be imbibed with\n"+
    "the essence of the night itself.\n"+NORM);
  set_al(200-random(400));
  set_gender(gender);
  set_race(race);
  set_level(22);
  /* determine special bonuses based on race */
  switch(race){
    case "demon":
      hp_mod = 100;
      wc_mod = 6;
      ac_mod = 2;
      set_weapon_params("other|dark",10,0);
      set_armor_params("other|dark",0,60,0);
      set_armor_params("other|light",0,-20,0);
      break;
    case "celestial":
      hp_mod = 150;
      wc_mod = 5;
      ac_mod = 3;
      set_weapon_params("other|light",7,0);
      set_armor_params("other|mental",0,50,0);
      set_armor_params("other|poison",0,25,0);
      break;
    case "drow":
      hp_mod = 50;
      wc_mod = 1;
      ac_mod = 5;
      set_armor_params("other|mental",0,50,0);
      set_armor_params("other|light",0,-25,0);
      break;
    case "orc":
      hp_mod = 75;
      wc_mod = 7;
      ac_mod = -2;
      set_armor_params("other|mental",0,-50,0);
      break;
    case "elf":
      hp_mod = -50;
      wc_mod = 1;
      ac_mod = 5;
      set_armor_params("other|mental",0,50,0);
      set_armor_params("magical",0,25,0);
      break;
    case "dwarf":
      hp_mod = 75;
      wc_mod = 2;
      ac_mod = 2;
      set_armor_params("other|earth",0,25,0);
      set_armor_params("magical",0,25,0);
      set_armor_params("other|poison",0,25,0);
      break;
    case "human":
      hp_mod = random(30);
      wc_mod = random(5);
      ac_mod = random(5);
      break;
    default:
  }
  set_wc(29+wc_mod);
  set_ac(19+ac_mod);
  set_hp(700+random(200)+hp_mod);
  set_aggressive(0);
  set_wc_bonus(20);
  set_ac_bonus(10 + bonus_modifier);
  set_multi_cast(1);
  /* Sparrow: Spells for all Monks are here. */
  add_spell("babywave",
        "$HM$ ~ $N$\n$HM$ ~   The monk twists to one side and releases:\n$HM$ ~\n"+
        "$HM$ ~ $HK$     ,.   (   .      )        .      '\n"+
        "$HM$ ~ $HK$    ('     )  )'     ,'        )  . (`     '`\n"+
        "$HM$ ~ $HK$  .; )  ' (( (' )    ;(,     ((  (  ;)  '  )'\n"+
        "$HM$ ~ $HK$_'., ,._'_.,)_(..,( . )_  _' )_') (. _..( '..\n$HM$ ~\n$N$"+
        "$HM$ ~ $N$$Y$            A wave of dark fire!\n$HM$ ~\n$N$",
        "$HM$ ~ $HK$The monk releases a wave of darkness!$N$\n",
        15,35,"other|dark",1);
  add_spell("disarm",
    "$HM$ ~ $N$$R$#CMN# spins inside of your defenses and knocks your arms wide!\n$N$",
    "$HM$ ~ $N$$R$#CMN# spins inside of #CTN#'s defenses and knocks #TP# arms wide!\n$N$",
    15,25,0,0,"disarm");
  add_spell("wepbreak",
    "$HM$ ~ $N$$Y$#CMN# catches your incoming attack and redirects it back into you!\n$N$",
    "$HM$ ~ $N$$Y$#CMN# intercepts #CTN#'s attack and reverses it perfectly!\n$N$",
    10,25,0,0,"weapon_break");
  add_spell("kick1",
    "$HM$ ~ $N$$HK$#CMN# lands a solid kick to your chest!\n$N$",
    "$HM$ ~ $N$$HK$#CMN# lands a solid kick to #CTN#'s chest!\n$N$",
    20,15,0,0);
  add_spell("kick2",
    "$HM$ ~ $N$$HR$#CMN# spins quickly and places a roundhouse kick on your jaw!\n$N$",
    "$HM$ ~ $N$$HR$#CTN# is hit square on the jaw with a roundhouse kick!\n$N$",
    20,15,0,0);
  add_spell("shadowkick",
    "$HM$ ~ $N$#CMN#'s form $HY$blurs$N$ as #MS# hits you with a $HK$SHADOW KICK$N$!\n",
    "$HM$ ~ $N$#CMN#'s form $HY$blurs$N$ as #MS# hits #CTN# with a $HK$SHADOW KICK$N$!\n",
    20,({10,10,10,10}),({"other|dark","other|ice","other|mental",0}),0);
  add_spell("darkness",
    "$HM$ ~ $HK$#CMN# absorbs all of the light in the room, you feel drained!\n$N$",
    "$HM$ ~ $HK$#CMN# absorbs all of the light in the room, you feel drained!\n$N$",
    15,10,"other|dark",0,"true_darkness");
  add_spell("flurry",
    "$HM$ ~ $HG$#CMN# pummels you with a flurry of hard punches!\n$N$",
    "$HM$ ~ $HG$#CMN# pummels #CTN# with a flurry of hard punches!!\n$N$",
    20,10,0,2,"new_target");
  set_message_hit(({HIR+"obliterates"+NORM, " with a furious series of combinations",
                    RED+"pummels"+NORM," spraying the room with "+HIR+"blood"+NORM,
                    "thrashes"," with a deadly combination",
                    "stunned"," with a brilliant attack",
                    "kicks"," square in the face",
                    "punches"," in the stomach",
                    "grazed"," with a glancing blow"}));
  /* Sparrow - I will add some better chats here, just dont feel like it now */
  set_chat_chance(5);
  load_chat("The monk moves silently across the room.\n");
}
