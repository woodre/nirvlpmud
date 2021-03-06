/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Flame Forest
//  Function:     Random mob creation for miscellaneous mobs in area
//  Create Date:  2004.01.26
//  Last Edit:    2004.07.27 -Forbin
//  Notes:        Adapted from: 
//                  /players/vertebraker/swamp/NPC/beast.c
//                  Orignal Copyright (c) 2000 Vertebraker@Nirvana
//  Notable Changes:  
//    2004.07.27 -changed ratios of mob cloning          
*/ 

#include "/players/forbin/define.h"
#include "/players/forbin/logging.h"
#pragma combine_strings
#define OBJ "/players/forbin/realms/flame_forest/OBJ/"
inherit "/players/vertebraker/closed/std/monster.c";

int Destruct_Corpse;  /* Does corpes destruct or not */
int Thermal_Wraith;   /* Is the mob a Thermal Wraith */
string Death_Chat;    /* Room emote at mob death */
string Prize;         /* Reward object */

   
reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_gender("creature");
  set_al(random(2001)-1000);
  set_wander(30, 0, ({ "path" }));
  set_heart_beat(2);
  set_chat_chance(5);
  set_a_chat_chance(10);
  Thermal_Wraith = 0;
  switch(random(8)) {
    case 0..1: smallmob(); break;
    case 2..3: mediummob(); break;
    case 4..7: largemob(); break; 
  }
  set_dead_ob(this_object()); 
}

smallmob() {
  object mob;
  mob = previous_object();
  switch(random(2)) {
    case 0:
      mob->set_short(HIK+"ash "+HIR+"lizard"+NORM);
      mob->set_long("  Seemingly a bit large to call a lizard, the ash lizard has a short,\n"+
        "fat body that ends in a long slender tail.  Three black pupils glance\n"+
        "out from yellow eyes and it shuffles about the area on four stubby\n"+
        "paws in quick spurts, constantly looking for food.\n");
      mob->set_name("ash lizard"); mob->set_race("animal"); 
      mob->set_alt_name("lizard");
      mob->set_level(10); mob->set_hp(150); mob->set_wc(15); mob->set_ac(8); 
      mob->set_death_chat("With your last blow, you sever the lizard's tail....."); mob->set_destruct_corpse(0); 
      mob->set_prize(OBJ+"lizard_tail.c");  
      mob->load_chat("The lizard scurries about.\n");
      mob->load_chat("The lizard roots around in the dirt.\n");
      mob->load_a_chat("The ash lizard bites at you.\n");
      break;
    case 1:
      mob->set_short("a "+HIK+"smolder"+NORM+"snake");
      mob->set_long("  Small, slender, and slimy, this snake has a is about a foot long,\n"+
         "and has a spiraling pattern of black and white on its back.  Coiled\n"+
          "up, you can see that its belly is a dark red - in stark contrast to\n"+
          "the grayish color that its back pattern gives it.\n");
      mob->set_name("smoldersnake"); mob->set_race("animal"); 
      mob->set_alias("snake");
      mob->set_level(5); mob->set_hp(75); mob->set_wc(10); mob->set_ac(4); 
      mob->set_death_chat("The snake shrivels away, leaving only its skin."); mob->set_destruct_corpse(1); 
      mob->set_prize(OBJ+"snake_skin.c");
      mob->load_chat("The smoldersnake slithers slithers around....\n");
      mob->load_chat("The smoldersnake coils up....preparing to attack....\n"); 
      mob->load_a_chat("The smoldersnake strikes out with its fangs!\n");
      break;
   }
}

mediummob() {
  object mob;
  mob = previous_object();
  switch(random(3)) {
    case 0:
      mob->set_short(HIW+"a blinding light"+NORM);
      mob->set_long("  Mystifying man for centuries, Ignis Fatuus or Will-o'-the-wisps,\n"+
        "have inhabited forested and swampy regions for time untold.  Though\n"+
        "thought by many to be a natural phenomena caused by gas or drunken\n"+ 
        "stupor - only recently has it been realized that will-o'-the-wisps\n"+
        "are living things.  Their mesmerizing bright glow conceals the\n"+ 
        "creatures true danger to those who would attempt to hurt it.\n");
      mob->set_name("will-o'the-wisp"); mob->set_race("willowwisp"); 
      mob->set_alt_name("light"); mob->set_alias("ignis");
      mob->set_level(17); mob->set_hp(300); mob->set_wc(26); mob->set_ac(40); 
      mob->set_death_chat("The will-o'-the-wisp fades away....."); mob->set_destruct_corpse(1); 
      mob->set_prize(OBJ+"essence_ignis.c"); 
      mob->load_chat("The will-o'-the-wisp pulses brightly.\n");
      mob->load_chat("Floating about the area, the will-o'-the-wisp glows warmly.\n");
      mob->load_a_chat("Quickly dispersing, the will-o'-the-wisp forms somewhere else.\n");
      mob->load_a_chat("The will-o'-the-wisp dodges your attack.\n");
      break;
    case 1: 
      mob->set_short(RED+"drake"+NORM);
      mob->set_long("  Slightly larger than a cow, drakes are the tiny cousins of dragons.\n"+
               "A glistening slime covers the drake's armor of small, oval scales, and\n"+
               "two leather wings lie tucked away on its back.  Dark Bile drips from\n"+
               "sharp teeth that fill its tapered snout, and the drake's forelimbs end\n"+
               "in four fingered claws.  Its thick tail ends in a mass of spikes.\n");
      mob->set_name("drake"); mob->set_race("dragon"); 
      mob->set_level(15); mob->set_hp(250); mob->set_wc(20); mob->set_ac(12); 
      mob->set_death_chat("One of its wings snaps off as the drake falls over dead....."); mob->set_destruct_corpse(0); 
      mob->set_prize(OBJ+"drake_wing.c"); 
      mob->load_chat("The drake glares at you.\n");
      mob->load_chat("Raising its head, the drake hisses gutturally.\n");
      mob->load_a_chat("The drake scratches at its attacker with its claws.\n");
      mob->load_a_chat("With a quick flip of its tail, the drake sends its attacker flying.\n");
      break;
    case 2: 
      mob->set_short("ash crawler"); 
      mob->set_long("  Resembling a large, bloated slug, you imagine this ugly thing would\n"+
               "be the result of an earthworm and a caterpillar mating.  Its skin looks\n"+
               "crusty and gray, but you notice a dark slickness that covers it.  It\n"+
               "seems to have several hundred pairs of legs, and makes a loud thumping\n"+
               "noise and it shuffles about the area.\n");
      mob->set_name("ash crawler"); mob->set_alias("crawler"); mob->set_race("animal");
      mob->set_level(13); mob->set_hp(190); mob->set_wc(15); mob->set_ac(10);
      mob->set_death_chat("With a final blow, you splatter the ash crawler....."); mob->set_destruct_corpse(1); 
      mob->load_chat("The ash crawler slowly moves about the area.\n");
      mob->load_a_chat("The ash crawler tramples you with its many feet.\n");
      break;
  }
}

largemob() {
  object mob;
  mob = previous_object();
  switch(random(3)) {
    case 0:  
      mob->set_short(HIK+"creep"+NORM);
      mob->set_long("  Wide and flat-bodied, this creature scurries about on three pairs\n"+
               "of long tendrils.  At the end of each tendril is a barbed claw that\n"+
               "is used to capture it's victims.  Creeps have survived in the forest\n"+
               "for ages, though they have been known to migrate into populated areas\n"+
               "as well.  A nocturnal creature for the most part, it is usually found\n"+
               "flattened out on the ground, lying in wait for potential prey.\n");
      mob->set_name("creep"); set_race("animal");
      mob->set_level(19); mob->set_hp(525); mob->set_wc(28+random(6)); mob->set_ac(18);
      mob->set_death_chat("The creep screeches, collapsing in death."); mob->set_destruct_corpse(1); 
      mob->set_prize(OBJ+"creep_carcass.c");     
      mob->load_chat("The creep scurries about the ground.\n");
      mob->load_chat("Flattening itself against the ground, the creep is barely noticable.\n");
      mob->load_a_chat("A stinging pain in felt as the creep scratches you with its claw!\n");
      mob->load_a_chat("The creep scurries away, preparing for another attack.\n");
      mob->load_a_chat("The creep gurggles a nasty, low sounding hiss.\n");
      mob->set_spell_dam(50);
      mob->set_chance(75);
      mob->set_spell_mess1("The "+HIK+"creep"+NORM+" digs its claws into its prey tearing away skin.\n");
      mob->set_spell_mess2("\n\n\n\t\Skin is torn away as the "+HIK+"creep"+NORM+" digs its claws into you.\n\n\n");
      break;
    case 1:
      mob->set_short(HIC+"shrieker"+NORM);
      mob->set_long("  A curiously odd creature this is.  This wailing animal resembles\n"+
               "a large monkey - except for the fact that it has two pairs of arms.\n"+
               "Bright blue fur covers the entire body of the shriek, while a long\n"+
               "gleaming white stripe runs the length of its back.\n");
      mob->set_name("shrieker"); mob->set_race("animal");
      mob->set_alt_name("shriek"); mob->set_alias("monkey");
      mob->set_level(18); mob->set_hp(450+random(100)); mob->set_wc(32+random(8)); mob->set_ac(16);
      mob->set_death_chat("The shriek collapses dead onto the ground."); mob->set_destruct_corpse(0); 
      mob->set_prize(OBJ+"shriek_fur.c");
      mob->set_aggro(1, 40, 80);
      mob->load_chat("The shrieker wails loudly.\n");
      mob->load_chat("The shriek watches you as it rocks slowly back and forth.\n");
      mob->load_a_chat("The shriek quickly dodges your attack.\n");
      mob->load_a_chat("Speedily darting between your legs, the shrieker bites at your ankle.\n");
      mob->set_spell_dam(50);
      mob->set_chance(30); 
      mob->set_spell_mess1("The shriek pummels its attacker with all four fists.\n");
      mob->set_spell_mess2("The shriek pummels you with all four of its fists.\n");
      break;
    case 2:
      mob->set_short(HIR+"thermal"+HIW+" wraith"+NORM);
      mob->set_long("  Similar in appearance to a ferret, yet colossal in size, thermal\n"+
               "wraiths have been hunted to near extinction.  The wraith stands 4 feet\n"+
               "high standing on all fours, and almost 10 feet high when balancing on\n"+
               "its hind legs.  Large paws end with black talons, and its jaws are\n"+
               "filled with many bone-crushing teeth.  Milky-white fur is covered with\n"+
               "bright red stripes in a tiger-like pattern.  This well-insulating fur\n"+
               "is highly sought-after and treasured by many.\n");
      mob->set_name("thermal wraith"); set_race("animal");
      mob->set_alt_name("wraith"); set_alias("thermal");
      mob->set_level(21); mob->set_hp(550+random(100)); mob->set_wc(35+random(5)); mob->set_ac(20);
      mob->set_heal(2,2); mob->set_armor_params("other|fire", 15, 70, "special_defense");
      mob->set_death_chat("The thermal wraith crumples into a smoldering heap.");
      mob->set_prize(OBJ+"wraith_pelt.c"); mob->set_thermal_wraith(1);
      mob->load_chat("The thermal wraith stalks about the area.\n");
      mob->load_chat("The thermal wraith makes a quibbiling sound.\n");
      mob->load_chat("Standing on its hind legs, the thermal wraith growls at you.\n");
      mob->load_a_chat("With quick reflexes, the thermal wraith darts away from your attack.\n");
      mob->load_a_chat("The thermal wraith strikes at you with its sharp talons.\n");
      mob->add_spell("Rake",
             "With astonishing quickness, the thermal wraith bounds\n"+
             "across the room and\n\n"+
             "            $R$/ / / / $HW$RAKES$N$R$ / / / /$N$\n\n"+
             "                   you with razor-sharp claws.\n"+
             "$HR$Fire$N$ bursts forth from your terrible wound.\n",
             "With astonishing quickness, the thermal wraith bounds\n"+
             "across the room and\n\n"+
             "            $R$/ / / / $HW$RAKES$N$R$ / / / /$N$\n\n"+
             "                   #CTN# with razor-sharp claws.\n"+
             "$HR$Fire$N$ bursts forth from #TP# terrible wound.\n",
             50, "40-80", "other|fire");
      break;
   }
}

/* 
 *  ***********************************************************************
 *  Function:    set_destruct_corpse
 *  Description: sets corpse destructing
 *  Arguments:   int 0 for no, 1 for yes
 *  ***********************************************************************
 */

set_destruct_corpse(int num) {
  Destruct_Corpse = num;
}

/* 
 *  ***********************************************************************
 *  Function:    set_thermal_wraith
 *  Description: sets whether or not mob is thermal wraith for special item
 *  Arguments:   int 0 for no, 1 for yes
 *  ***********************************************************************
 */

set_thermal_wraith(int num) {
  Thermal_Wraith = num;
}

/* 
 *  ***********************************************************************
 *  Function:    set_death_chat
 *  Description: sets corpse destructing
 *  Arguments:   string dc, where dc is the message upon monster_died()
 *  ***********************************************************************
 */

set_death_chat(string dc) {
  Death_Chat = dc;
}

/* 
 *  ***********************************************************************
 *  Function:    set_prize
 *  Description: sets monster_died() reward
 *  Arguments:   string p, where p is the path for item to be cloned
 *  ***********************************************************************
 */

set_prize(string p) {
  Prize = p; 
}

monster_died() {
  if(Death_Chat) tell_room(environment(),Death_Chat+"\n");
  if(Prize) move_object(clone_object(Prize),environment());
  if(Thermal_Wraith) {
    if(!random(2)) 
      move_object(clone_object(OBJ+"bone_shard.c"), environment());
    if(!random(4))   
      move_object(clone_object(OBJ+"bone_shard.c"), environment());
  }
  if(Destruct_Corpse) destruct(present("corpse",environment()));
    return 1; 
}

special_defense() {
  if(!random(5)) {
      return 3001;
  }
}
