#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";
#define FR HIC+"Falcon Rapier"+NORM
#define ME capitalize(this_player()->query_name())
#define IT capitalize(attacker->query_name())

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("the "+FR);
  set_alt_name("falcon rapier");
  set_alias("rapier");
  set_short("the "+FR);
  set_long(
  "The "+FR+" is a beautiful sword with a thin sharp blade.  The ornate\n"+
  "hand guard is carved to the likeness of a falcon.  The falcon's wings\n"+
  "are spread wide, providing excellent protection for the wielders arm.\n"+
  "The bird's eyes are masterfully cut gemstones that twinkle with light.\n"+
  "There is something written on the handle's fine leather.\n");
  set_read("\n"+
           " \"strike!\" \n"+
           "\n");
  set_type("sword");
  set_class(18);
  set_weight(2);
  set_value(5000);
  message_hit = ({
    HIW+"lunged forward"+NORM+" and "+HIW+"PLUNGED"+NORM+" the "+FR+" deep into "+
        "the "+HIR+"heart"+NORM+" of", "",
    HIW+"sliced"+NORM+" the flesh of", HIW+" WIDE OPEN"+NORM+" with the "+FR,
    HIW+"darted"+NORM+" under the guard of", " and "+HIW+"SLASHED"+NORM+" it viscously",
    HIW+"tumbled"+NORM+" away from the clumsy attack of", "",
    HIW+"slashed"+NORM, " with the thin blade and then "+HIW+"BASHED"+NORM+" its "+
        "face with the hilt",
    HIW+"pierced"+NORM+" the body of", " with the "+FR,
    HIW+"nicked"+NORM, " with a quick swing of the narrow blade",
  });
  set_no_clean(1);
  set_save_flag(1);
  set_hit_func(this_object());
}

wield(str) {
  if(!id(str)) {
     return 0;
  }
  if(environment() != this_player()) {
     return 0;
  }
  if(this_player()->query_alignment() < 0) {
    write("You are not worthy of such an honorable weapon.\n");
    return 1;
  }
  ::wield(str);
  return 1;
}

weapon_hit(attacker){
  int chance;
  int i;

  /*
   * Specials chance is same is stat vs random(50) (40%)
   */
  if(random(this_player()->query_attrib("luc")) > 14) {
    write("You get an "+HIC+"extra attack!"+NORM+"\n");
    say(ME+" gets an "+HIC+"extra attack!"+NORM+"\n");

    i = random(14);
    if(i % 2) i -= 1;

    /* echo another message_hit message */
    write("You "+message_hit[i]+" "+IT+message_hit[i+1]);
    say(ME+" "+message_hit[i]+" "+IT+message_hit[i+1]);
    if(i == 0) { write("!\n"); say("!\n"); }
    else { write(".\n"); say(".\n"); }

    this_player()->add_spell_point(-random(6));
    return 6;
  }
  return;
}


init() {
  ::init();
  add_action("do_strike","say");
#ifndef __LDMUD__
  add_action("do_strike"); add_xverb("'");
#else
  add_action("do_strike", "'", 3);
#endif

}

do_strike(str) {
  object attacker;

  if(str == "strike!" && wielded_by) {
    write("You shout: "+HIC+"STRIKE!"+NORM+"\n");
    say(ME+" shouts: "+HIC+"STRIKE!"+NORM+"\n");
    attacker = this_player()->query_attack();

    if(!attacker || attacker->is_player() || this_player()->query_sp() < 0) {
      write("You "+HIC+"slice the air"+NORM+" with "+HIW+"three quick "+
      "swings"+NORM+" of the agile blade.\n");
      say(ME+HIC+" slices the air"+NORM+" with "+HIW+"three quick swings"+
      NORM+" of the agile blade.\n");
      return 1;
    }

    tell_room(environment(this_player()),
    ME+HIW+" leaps forward"+NORM+" and "+HIW+"slices the air"+NORM+" with "+
    "the agile "+FR+"!\n");
    tell_room(environment(this_player()),
    "The "+HIW+"swinging blade"+NORM+" becomes a "+HIW+"blur"+NORM+" as it "+
    HIW+"Cuts "+NORM+IT+"'s "+HIW+"flesh to ribbons!\n"+NORM);
    attacker->hit_player(5+random(10));
    this_player()->add_spell_point(-random(15));
    return 1;
  }
}

