/* Basic Example of using monster spells */

inherit "/obj/monster.c";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("The Demon of Darkness");
  set_alt_name("demon");
  set_alias("darkness");
  set_race("demon");
  set_short("The Demon of Darkness");
  set_long("A fearsome, 8 foot figure, the Demon of Darkness is mostly\n"+
           "shadow, with the occasional flash of fire from within which\n"+
           "illuminates features not suited to the retention of sanity.\n");
  set_hp(1500);
  set_ac(30);
  set_wc(15);

  
/* multi_cast is actually 0 by default.  This means the demon will */
/* cast at most one spell per round, but has a 25% chance of casting */
/* a spell (8 for hellfire +12 for fire claws + 5 for darkness drain) */
  set_multi_cast(0);

/* Hits all attackers with evil and fire damage */
/* First message is displayed to each, second to whole room */
  add_spell("hellfire",
"The $HK$HELL$HR$FIRE$N$ burns you!\n",
"#MN# drops to one knee and calls $HK$HELL$HR$FIRE$N$ up from the ground!\n",
8,({30,30}),({"other|evil","other|fire"}),1);

/* Hits the primary target with fire and physical damage */
/* First message is shown to target, second to whole room */
  add_spell("fire claws",
"#MN# surrounds one claw in a swirling vortex of $HR$fire$N$\n"+
"then jabs it directly at your heart!\n",
"#MN# surrounds one claw in a swirling vortex of $HR$fire$N$\n"+
"then jabs it directly at #TN#'s heart!\n",
12,({20,20}),({"physical","other|fire"}));

/* Hits the primary target with evil damage */
/* Notice that the room sees nothing on this spell, only the target */
  add_spell("darkness drain",
"The evil $HK$darkness$N$ oozing from the demon drains you.\n",0,
5,30,"other|evil");

}
