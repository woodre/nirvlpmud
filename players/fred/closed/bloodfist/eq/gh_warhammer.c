inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (arg) return;

  set_name("greyhorn warhammer");
  set_alias("warhammer");
  set_type("hammer");
  set_short(HIW+"GreyHorn Warhammer"+NORM);
  set_long(
"This massive warhammer is part of the magical equipment that was forged\n"+
"for the mighty warrior Sir Drevalus.  The handle of the warhammer is very\n"+
"thick and about three feet long.  The head of the warhammer is a massive\n"+
"hunk of metal with small spikes covering both ends.  It radiates a soft\n"+
"glow of gray light which flickers softly.\n");
  set_value(4800);
  set_weight(4);
  set_class(20);
  set_read(0);
  set_hit_func(this_object());
  message_hit=({
    HIW+"crushed"+NORM, " in the head with a "+HIW+"deadly blow"+NORM,
    HIW+"smashed"+NORM, " in the face with a "+HIW+"powerful blow"+NORM,
    HIW+"pounded"+NORM, " with a strong blow",
    "struck",  " with a hard blow",
    "hit",     "",
    "grazed",  "",
    "nicked",  "",
  });
}

id(str){ return (::id(str) || str == "greyhorn" || str == "greyhorn_zeq"); }

query_save_flag(){    return 1; }
query_dest_flag() { return 1; }

int weapon_hit(object t){
  if(!random(10))
  {
    tell_object(environment(),
      "\n  You swing the mighty warhammer into "+t->query_name()+"...\n"+
      "  Bones break and flesh liquifies underneath the blow...\n"+
      "  "+t->query_name()+" recoils in anguish!\n\n");
    tell_room(environment(t),
      "\n  "+environment()->query_name()+
      " swings the mighty warhammer into "+t->query_name()+"...\n"+
      "  Bones break and flesh liquifies underneath the blow...\n"+
      "  "+t->query_name()+" recoils in anguish!\n\n", ({ environment() }));
    return 6;
  }
  else if(!random(10))
  {
    tell_object(environment(),
      HIW+"You glow with an aura of gray light.\n"+NORM);
    tell_room(environment(t), HIW+environment()->query_name()+
      " glows with an aura of gray light.\n"+NORM,
      ({ environment() }));
  }
  else if(!random(10))
  {
    tell_object(environment(),
      HIW+"Your focus on combat is acute.\n"+NORM);
    tell_room(environment(t), HIW+environment()->query_name()+
      "'s focus on combat is acute.\n"+NORM, ({ environment() }));
    environment()->drink_alcohol(-1);
  }
  else if(!random(10))
  {
    tell_object(environment(),
      "\n  The mighty warhammer glows as you swing it into "+
      t->query_name()+".\n"+HIW+
      "  "+t->query_name()+" reels from the massive blow.\n\n"+NORM);
    tell_room(environment(t), "\n  The mighty warhammer glows at "+
      environment()->query_name()+" swings it into "+t->query_name()+".\n"+
      "  "+t->query_name()+" reels from the massive blow.\n\n"+NORM,
      ({ environment() }));
    t->hit_player(6);
    return 5;
  }
}

query_wear(){
  int wear;
  wear = 3*misses/5 + 2*hits/11;
  return wear;
}
