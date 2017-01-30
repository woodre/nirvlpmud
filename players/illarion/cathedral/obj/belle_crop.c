/* weapon for high/mon/mugger.c */
inherit "obj/weapon";
#include "/players/illarion/dfns.h"
#define EMOTER(a,b,c) (string)call_other("/obj/user/parse_emote","parse_emote",a,b,c)

string damage_array;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("crop");
  set_short("A long black riding crop");
  set_type("club");
  set_long("");


  set_weight(1);
  set_value(5000);
  set_class(15);
  set_hit_func(this_object());
  set_params("other|dark",0,"dark_hit");
  set_params("other|mental",0,"mental_hit");
  
  if(!damage_array) damage_array = ({
  ({
"Your riding crop whistles through the air, barely grazing #TN#'s flesh.\n",
"#MN#'s riding crop whistles through the air, barely grazing your flesh.\n",
"#MN#'s riding crop whistles through the air, barely grazing #TN#'s flesh.\n"  
  }),({
"The knotted tassel ends of your riding crop slap sharply against #TN#'s skin.\n",
"The knotted tassel ends of #MN#'s riding crop slap sharply against your skin.\n",
"The knotted tassel ends of #MN#'s riding crop slap sharply against #TN#'s skin.\n"  
  }),({
"Stinging heat rises on #TN#'s skin in the wake of your riding crop's swift strike.\n",
"Stinging heat rises on your skin in the wake of #MN#'s riding crop's swift strike.\n",
"Stinging heat rises on #TN#'s skin in the wake of #MN#'s riding crop's swift strike.\n"
  }),({
"Thin black leather stings #TN#'s flesh, leaving a bright red, throbbing brand across the exposed skin.\n",
"Thin black leather stings your flesh, leaving a bright red, throbbing brand across the exposed skin.\n",
"Thin black leather stings #TN#'s flesh, leaving a bright red, throbbing brand across the exposed skin.\n"
  }),({
"The distinctive sound of leather striking #TN#'s flesh precedes the sharp jolt of pain that swiftly blossoms into hot agony.\n",
"The distinctive sound of leather striking your flesh precedes the sharp jolt of pain that swiftly blossoms into hot agony.\n",
"The distinctive sound of leather striking #TN#'s flesh precedes the sharp jolt of pain that swiftly blossoms into hot agony.\n"
  }),({
"The tightly bound leather rod bites cruelly into #TN#'s flesh, causing hot blood to splatter wide in all directions.",
"#MN#'s tightly bound leather rod bites cruelly into your flesh, causing hot blood to splatter wide in all directions.",
"#MN#'s tightly bound leather rod bites cruelly into #TN#'s flesh, causing hot blood to splatter wide in all directions."
  }),  
  });
  
  
}
status darked;
dark_hit(victim)
{
  darked = 0;
  if(!random(3)) 
  { 
    if(victim && wielded_by)
    {
      tell_room(environment(wielded_by), "An aura of darkness surrounds the crop.\n");
    }
    darked=1;
    return 5;
  }
}

mental_hit(victim)
{
  if(!darked && !random(2)) { 
    if(victim && wielded_by)
    {
      tell_object(wielded_by, victim->query_name()+" cringes away from the crop!\n");
      tell_object(victim, "You cringe away from "+wielded_by->query_name()+"'s crop!\n");
      tell_room(environment(wielded_by), victim->query_name()+" cringes away from "+wielded_by->query_name()+"'s crop!\n", ({victim, wielded_by}));
    }
    return 5; 
  }
}

weapon_hit(victim)
{
  int total;
  string tmp;
  total = 0;
  /* Note: fallthrough is deliberate.  do not add break statements */
  /* damage odds: +0: 80%, +5: 10%, +6 6%, +8: 5%, +11: 4%, + 15: 3% */
  /* average damage bonus:  2.15 */
  switch(random(100)) {
    case 25..27: 
      tell_object(wielded_by, "You spin on your heel, throwing your weight into the blow.\n");
      tell_room(environment(victim), wielded_by->query_name()+" spins on "+wielded_by->query_possessive()+" heel.\n");
      total+=4;
    case 21..24: 
      tell_object(wielded_by, "Drops of blood fly from the crop as it whips through the air.\n");
      tell_room(environment(victim),wielded_by->query_name()+"'s crop whips through the air, spraying drops of blood!\n");
      total+=3;
    case 16..20: 
      
      total+=2;
    case 10..15: 
      tmp = ({"left","right"})[random(2)];
      tell_object(wielded_by, "You feint to the "+tmp+".\n");
      tell_room(environment(victim), wielded_by->query_name()+" feints to the "+tmp+".\n", ({ wielded_by }));
      total+=1;
    case 0..9: 
      tell_object(wielded_by, "The riding crop pulls itself eagerly toward "+victim->query_name()+"!\n");
      tell_room(environment(victim), wielded_by->query_name()+"'s crop almost seems to pull itself towards "+victim->query_name()+".\n", ({victim, wielded_by}));
      tell_object(victim, wielded_by->query_name()+"'s crop almost seems to pull itself towards you.\n");
      total+=5;
  }
  
  return total;
}

query_wear() { return ::query_wear()/5; }

query_message_hit(dam)
{ 
  int ind;
  switch(dam)
  {
    case 1..2: ind = 0;
      break;
    case 3..5: ind = 1;
      break;
    case 6..10: ind = 2;
      break;
    case 11..20: ind = 3;
      break;
    case 21..30: ind = 4;
      break;
    default:  ind = 5;
  }
  return damage_array[ind];
}