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
 *                                       gear is 1, maximum is 5.
 *                              10/04/06 Sparrow: Increased difficulty of mob,
 *                                       better to be too hard than too easy.
 *                              10/05/06 Sparrow: Added more documentation
 ****************************************************************************/
#include "/sys/ansi.h"
#include "/players/sparrow/areas/bwo/include/defs.h"
inherit "/players/sparrow/areas/bwo/include/mob_funcs.c";
inherit "/players/sparrow/areas/bwo/include/gear_funcs.c";
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
  if(arg && !attacker_ob) { 
    object ob;
    string *drop;
    string room;
    drop = ({"/players/maledicta/cont/rooms/444",
             "/players/maledicta/cont/rooms/771",
             "/players/maledicta/cont/rooms/109",
             "/players/mythos/aroom/forest/forest5",
             "/players/earwax/area/fields/room/tunnel3",
             "/players/maledicta/cont/rooms/892",
             "/players/maledicta/cont/rooms/887",
             "/players/jaraxle/cont/rdragon/rooms/pond2",
             "/players/angel/area/school/room/principal_office_02.c",
             "/players/angel/area/walmart/room/automotives.c",
             "/room/south/sshore30.c",
             "/room/south/sforst38.c",
             "/players/wocket/turtleville/tvmarsh6.c",
             "/players/saber/tower/tower20+9.c",
             "/players/eurale/Fiend/mm18.c",
             "/players/eurale/Keep/k53.c",
             "/players/bastion/isle/wiz/shore5.c",
             "/players/trix/castle/primo/apse20.c",
             "/players/fakir/woods/room20.c",
             "/players/beck/room/park19.c",
             "/players/mythos/aroom/forest/around.c",
             "/players/vertebraker/swamp/ROOMS/s25.c",
             "/players/fred/forest/Rooms/forest24.c",
             });
    room = drop[random(23)];
    call_other(room, "load_up_fucker");
    this_object()->move_player("quietly, disappearing into a shadow#"+room);
    log_file("sparrow.bwm", "Log Entry: "+ctime()+" Obj: "+object_name(this_object())+"\n   On reset moved to: "+room+"\n"); 
  return;
  }
  
  /* Added to make compatable with both drivers */
  if(version() == "3.01.02-DR"){
    string race,gender;
    /*GLOBALS*/
    object Target;
  }
  
  /* Generation of Equipment - minimum of 1 items, maximum of 5
     very difficult to gain more than 2 pieces */
  
  /* bonus_modifier, slight addition to xp for each armor generated */   
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
  
  /* While there are still chances remaining attempt to generate item */
  while(remaining_chances > 0) {
    random_chance = random(5);
    /* If random slot has already been attempted, try again */
    while(slots_checked[random_chance] == 1) {
      random_chance = random(5);
    }
    
    /* If we find a slot that we havent checked, mark it as checked */
    slots_checked[random_chance] = 1;
    /* see if random chance of loading is met, if so, pick a random slot */
    if(random(10) > gear_chances[random_chance]) {
      random_slot = random(5);
      /* keep checking random slots until we find one that isn't used */
      while(gear_slots[random_slot] == "used") {
        random_slot = random(5);
      }
      
      /* we have found an unused slot, mark it as used now */
      current_slot = gear_slots[random_slot];
      gear_slots[random_slot] = "used";
      /* generate armor, move it to npc, force npc to wear armor */
      ob=generate_accessory(current_slot, random(2)+1);
      move_object(ob, this_object());
      init_command("wear "+current_slot);
      
      /* add slight bonus to xp worth */
      bonus_modifier++;
    }
    
    /* one less chance */
    remaining_chances--;
  }
  
  race = random_race();
  gender = random_sex();
  set_name("Black Willow Monk");
  set_alias("monk");
  set_short(HIB+"M"+NORM+"onk of the "+HIB+"B"+NORM+"lack "+HIB+"W"+NORM+
  "illow "+HIB+"O"+NORM+"rder "+HIC+"["+HIB+capitalize(race)+HIC+"]"+NORM);
  set_long(
    HIW+"The main defensive force of the Black Willow Order, these monks are\n"+
    "trained by the Black Willow himself. Having hand to hand combat skills\n"+
    "that border on the super-natural, some say that they must be imbibed with\n"+
    "the essence of the night itself.  Normally gentle in nature, Black Willow\n"+
    "Monks are a force to be reckoned with when provoked.\n"+NORM);
  set_al(0);
  set_gender(gender);
  set_race(race);
  set_level(25);
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
  
  set_wc(35+wc_mod);
  set_ac(25+ac_mod);
  set_hp(1100+random(200)+hp_mod);
  set_aggressive(0);
  set_wc_bonus(18);
  set_ac_bonus(7 + bonus_modifier);
  set_multi_cast(1);
  set_dead_ob(this_object());
  /* Sparrow: Spells for all Monks are here. */
  
  /* Babywave spell. Moderate dark damage to all in room, calls miscarriage 
     function in mob_funcs.c
  */
  add_spell("babywave",
        "\n$HM$ ~ $N$      The monk twists to one side and releases:\n"+
        "$HM$ ~ $HB$         ,.   (   .      )        .      '\n"+
        "$HM$ ~ $HB$        ('     )  )'     ,'        )  . (`     '`\n"+
        "$HM$ ~ $HB$      .; )  ' (( (' )    ;(,     ((  (  ;)  '  )'\n"+
        "$HM$ ~ $HB$    _'., ,._'_.,)_(..,( . )_  _' )_') (. _..( '..\n$N$"+
        "$HM$ ~ $N$               A wave of dark fire!\n\n$N$",
        "$HM$ ~ $N$$B$The monk releases a wave of darkness!$N$\n",
        15,"9d5+10","other|dark",1,"gut_punch");
  
  /* Disarm spell. Weak physical attack, calls disarm function in mob_funcs.c */
  add_spell("disarm",
    "$HM$ ~ $N$$R$#CMN# spins inside of your defenses and knocks your arms wide!\n$N$",
    "$HM$ ~ $N$$R$#CMN# spins inside of #CTN#'s defenses and knocks #TP# arms wide!\n$N$",
    12,"2d10",0,0,"disarm");
  
  /* Wepbreak spell. Weak physical damage, calls weapon_break function in 
     mob_funcs.c. Mean little function that will piss some people off :)
  */
  add_spell("wepbreak",
    "$HM$ ~ $N$$HB$#CMN# catches your incoming attack and redirects it back into you!\n$N$",
    "$HM$ ~ $N$$HB$#CMN# intercepts #CTN#'s attack and reverses it perfectly!\n$N$",
    7,"2d10+5",0,0,"weapon_breaker");
  
  /* Kick1 spell. Moderate physcial damage to single target. */
  add_spell("kick1",
    "$HM$ ~ $N$$HB$#CMN# lands a solid kick to your chest, knocking you back!\n$N$",
    "$HM$ ~ $N$$HB$#CMN# lands a solid kick to #CTN#'s chest, knocking #TP# back!\n$N$",
    25,"10d3+5",0,0);
  
  /* Kick2 spell. weak physcial damage to single target. */
  add_spell("kick2",
    "$HM$ ~ $N$$HR$#CMN# spins quickly and places a roundhouse kick on your jaw!\n$N$",
    "$HM$ ~ $N$$HR$#CTN# is hit square on the jaw with a roundhouse kick!\n$N$",
    25,"2d10",0,0);
  
  /* Shadowkick spell. Moderate total damage, combination of dark, ice, mental
     and physcial to a single target.
  */
  add_spell("shadowkick",
    "$HM$ ~ $N$#CMN#'s form $HY$blurs$N$ as #MS# hits you with a $HK$SHADOW KICK$N$!\n",
    "$HM$ ~ $N$#CMN#'s form $HY$blurs$N$ as #MS# hits #CTN# with a $HK$SHADOW KICK$N$!\n",
    25,({"10d2","3d5","2d10","4d5+5"}),({"other|dark","other|ice","other|mental",0}),0);
  
  /* Darkness spell. Very weak dark damage to one target, calls true_darkness 
     function from mob_funcs.c
  */
  add_spell("darkness",
    "$HM$ ~ $HK$#CMN# absorbs all of the light in the room, you feel drained!\n$N$",
    "$HM$ ~ $HK$#CMN# absorbs all of the light in the room, you feel drained!\n$N$",
    10,5,"other|dark",0,"true_darkness");
  
  /* Flurry spell. Weak physical damage to a single random target, calls new_target
     function from mob_funcs.c
  */
  add_spell("flurry",
    "$HM$ ~ $HG$#CMN# pummels you with a flurry of hard punches!\n$N$",
    "$HM$ ~ $HG$#CMN# pummels #CTN# with a flurry of hard punches!!\n$N$",
    25,"2d10+5",0,2,"new_target");
    
  /* Paralyze ability
  */
  add_spell("paralyze",  
    "\n$HM$ ~$HC$                   You are engulfed by\n"+
    "$HM$ ~$N$$C$           .__                .___ \n"+                  
    "$HM$ ~$N$$C$      _____|  |__ _____     __| _/______  _  ________\n"+
    "$HM$ ~$N$$C$     /  ___/  |  \\\\__  \\   / __ |/  _ \\ \\/ \\/ /  ___/\n"+
    "$HM$ ~$N$$C$     \\___ \\|   Y  \\/ __ \\_/ /_/ (  <_> )     /\\___ \\ \n"+
    "$HM$ ~$N$$C$    /____  >___|  (____  /\\____ |\\____/ \\/\\_//____  >\n"+
    "$HM$ ~$N$$C$         \\/     \\/     \\/      \\/                 \\/ \n$N$"+
    "$HM$ ~$HC$                 YOU ARE BOUND IN PLACE!\n\n$N$",
    "$HM$ ~$HW$ #CMN# causes the $HK$shadows$HW$ to engulf #CTN#, #TS# is bound in place!\n$N$",
    5,"5d6+5","other|dark",3,"paralyze");
  /* Custom hit messages */
  set_message_hit(({HIR+"O B L I T E R A T E S"+NORM, " with a furious series of combinations",
                    RED+"pummels"+NORM," spraying the room with "+HIR+"blood"+NORM,
                    "thrashes"," with a deadly combination",
                    "stunned"," with a brilliant attack",
                    "kicks"," square in the face",
                    "punches"," in the stomach",
                    "grazed"," with a glancing blow"}));
}

monster_died() {
  string tname;
  tname = (this_player() ? this_player()->query_name() : "Unknown: "+object_name(previous_object()));
  log_file("sparrow.bwm", "Log Entry: "+ctime()+" Obj: "+object_name(this_object())+"\n   Monk was killed by "+capitalize(tname)+"\n");
  return 0;
}

is_castle() { return 1; }
int id(string arg) { return (arg == "castle" || ::id(arg)); }
