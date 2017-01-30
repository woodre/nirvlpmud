#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "con" || str == "convict" || str == "tim"); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Tim");
  set_race("human");
  set_alias("criminal");
  set_gender("male");
  set_short("Tim Dinduse");
  set_long(
    "Tim is in his mid 20's with sandy blond hair and a fit, tan physique.\n"+
    "He is in for blackmailing money from a former lover. He milked a\n"+
    "wealthy heiress of four million dollars before her husband got wise\n"+
    "and called the FBI.\n\n"+
    HIM+"Blackmail"+NORM+": A demand for money or other consideration under\n"+
    "threat to do bodily harm, to injure property, to accuse of a\n"+
    "crime, or to expose secrets.\n\n");
  set_level(20);
  set_ac(45+random(10));
  set_wc(25+random(10));
  set_hp((800)+random(100));
  set_al(-250);
  set_aggressive(0);
  set_chat_chance(5);
  load_chat(
    "Tim whines: 'Stupid Bitch!! She shoulda just payed me.'\n");
  set_death_emote(
    "\n\nAs #MN# dies, cigarettes fall out of #MP# pockets.\n");

  set_dead_ob(this_object());
  set_multi_cast(1);
   add_spell("shiv","#MN# stabs you with a sharpened toothbrush called a $HR$shiv$N$.\n",
                     "#MN# stabs #TN# with a $HR$shiv$N$.\n",
                     20,40-60,"physical");
   add_spell("eyegouge","#MN# gouges your $HY$eye$N$ out.\n",
                     "#MN# gouges #TN# $HR$eye$N$ out.\n",
                     40,40-60,"physical");
}

monster_died()
{
 int s;
   s=5;
   while(s--)
   move_object(clone_object(OBJ+"cig.c"));

  tell_room(environment(),
    "As the convict dies he drops his shiv.\n"+NORM);
  move_object(
    clone_object(OBJ+"shiv.c"),
    this_object());
}
