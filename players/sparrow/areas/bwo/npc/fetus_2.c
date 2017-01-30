/*****************************************************************************
 *      File:                   fetus.c
 *      Function:               Posessed Fetus
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2006 Sparrow
 *                              All Rights Reserved.
 *      Source:                 03/17/06
 *      Notes:
 *      Change History:         03/22/06 Sparrow: Added spells to fetus
 ****************************************************************************/
#include "/sys/ansi.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    /* sm - spell marker. Make it easier for players to see when important
       battle messages come through.
    */
    string sm;
    sm = HIY+" ~ "+NORM;
    set_name("child");
    set_alias("fetus");
    set_short(HIM+"C"+HIK+"hild of the "+HIM+"D"+HIK+"ark"+NORM);
    set_race( "demon");
    set_long(HIM+"Perversion of nature on the highest level does not even begin to\n"+
      "describe a Child of the Dark.  Thick globs of placenta and embryonic\n"+
      "fluid constantly ooze out of every orifice and down its pale white skin.\n"+
      "Wisps of black vapor escape rows of razor sharp teeth.  A mindless and\n"+
      "fearless slave to the darkness, it will stop at nothing to punish the\n"+
      "one that once nourished it.\n"+NORM);
    set_level(15);
    set_ac(9+random(5));
    set_wc(15+random(5));
    set_hp(25+random(25));
    set_al(0);
    set_aggressive(1);
    set_chat_chance(50);
    set_a_chat_chance(50);
    add_spell("bite",
      sm+"The "+HIM+"C"+HIK+"hild of the "+HIM+"D"+HIK+"ark"+NORM+" lunges forward"+
      " and bites you on the leg!\n",
      sm+"The "+HIM+"C"+HIK+"hild of the "+HIM+"D"+HIK+"ark"+NORM+" lunges forward"+
      " and bites #CTN# on the leg!\n",
      20,({7,7,7}),({0,"other|dark","other|poison"}),0);
    add_spell("spray",
      sm+MAG+"You grasp at your face as you are sprayed with embryonic fluid!"+NORM+"\n",
      sm+"The "+HIM+"C"+HIK+"hild of the "+HIM+"D"+HIK+"ark"+NORM+" sprays the"+
      " room with embryonic fluid!\n",
      20,({7,7}),({"other|poison","other|dark"}),1);
    add_spell("scream",
      sm+"The "+HIM+"C"+HIK+"hild of the "+HIM+"D"+HIK+"ark"+NORM+" arches back and "+
      "lets loose a terrifying "+HIC+"scream"+NORM+"!\n"+
      sm+HIC+"Intense pain tears through your head, your eardrums nearly burst!\n"+NORM,
      sm+"The "+HIM+"C"+HIK+"hild of the "+HIM+"D"+HIK+"ark"+NORM+" arches back and "+
      "lets loose a terrifying "+HIC+"scream"+NORM+"!\n"+sm+"#CTN# grabs #TP# head, "+
      "screaming in sheer "+HIM+"AGONY"+NORM+"!\n",
      15,20,"other|sonic",0);
    load_chat("The child screams: '"+HIR+"Mommy why did you do this to me?"+NORM+"'\n");
    load_chat(HIK+"Dark flames envelope the child.\n"+NORM);
    load_chat("The child "+HIY+"cackles"+NORM+" demonically!\n");
    load_chat("A "+HIK+"vortex of darkness"+NORM+" shrouds the child!\n");
    load_chat("The child screams: '"+HIM+"Mommy why did you do this to me?"+NORM+"'\n");
    load_chat("The child screams: '"+HIR+"I will make you pay for what you did!"+NORM+"'\n");
    load_chat("The child screams: '"+HIR+"Ow it HURTS! It HURTS!"+NORM+"\n");
    load_a_chat("The child screams: '"+HIC+"Take your medicine BITCH!"+NORM+"'\n");
    load_a_chat("The child screams: '"+HIR+"Mommy why did you do this to me?"+NORM+"'\n");
    load_a_chat(HIK+"Dark flames envelope the child.\n"+NORM);
    load_a_chat("The child "+HIY+"cackles"+NORM+" demonically!\n");
    load_a_chat("A "+HIK+"vortex of darkness"+NORM+" shrouds the child!\n");
    load_a_chat("The child screams: '"+HIM+"Mommy why did you do this to me?"+NORM+"'\n");
    load_a_chat("The child screams: '"+HIR+"I will make you pay for what you did!"+NORM+"'\n");
    load_a_chat("The child screams: '"+HIG+"Ow it HURTS! It HURTS!"+NORM+"'\n");
    set_weapon_params("other|dark",10,0);
    set_wc_bonus(3350);
    set_ac_bonus(3300);
  }
}
