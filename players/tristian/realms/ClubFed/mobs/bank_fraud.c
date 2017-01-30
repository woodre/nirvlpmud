#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "con" || str == "convict" || str == "freddy"); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Freddy");
  set_alt_name("fred");
  set_race("human");
  set_alias("criminal");
  set_gender("male");
  set_short("Freddy Numbers");
  set_long(
    "Freddy is a pudgy man in his mid 30's.  He is in for bank fraud because\n"+
    "he wanted to become rich but didn't want to work to do it. He is now a\n"+
    "felon for life because of his inaptitude.\n\n"+
    HIR+"Bank Fraud"+NORM+": To engage in an act or pattern of activity\n"+
    "where the purpose is to defraud a bank of funds.\n\n");
  set_level(20);
  set_ac(47+random(10));
  set_wc(27+random(10));
  set_hp((800)+random(100));
  set_al(-250);
  set_aggressive(0);
  set_chat_chance(5);
  load_chat(
    "Freddy moans: 'I was gonna be rich, damn it! RICH!!'\n");
  load_chat(
    "Freddy says: 'Damn my stupidity to hell.'\n");
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
