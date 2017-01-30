/*  Originally coded by Saber for /players/saber/monsters/stormlich.c
    Recode by Zeus
    Recode approved by _ on []
*/
#include "/players/zeus/closed/all.h"
inherit "obj/weapon.c";
int power, x;

reset(arg) {
  if (arg) return;

  set_name("Staff of Power");
  set_type("staff");
  set_alt_name("staff of power");
  set_short("Staff of Power");
  set_long("A six foot long staff covered with runes of living lightning.\n"+
    "You can feel the power this staff pulsating through your body.\n");
  set_class(18);
  set_weight(4);
  set_value(5000);
  set_hit_func(this_object());
}

weapon_hit(atk){
  power = this_player()->query_attrib("mag");
  if(!random(10))
  {
    x = random(2);
    switch(x){
    case 0:
      write(BOLD+BLK+"Your staff glows as a healing warmth flows into you!\n"+
        NORM);
      say(BOLD+BLK+TP->QN+"'s staff glows as a healing warmth flows into "+
        TP->OBJ+"!\n"+NORM);
      TP->add_hit_point(1);
    break;
    case 1:
      write(BOLD+BLK+
        "Your staff crackles as an aura of healing encompases you!\n"+NORM);
      say(BOLD+BLK+TP->QN+
        "'s staff crackles as an aura of healing encompases "+TP->OBJ+
        "!\n"+NORM);
      TP->add_spell_point(1);
      break;
    }
    return 0;
  }
  if(power > random(60))
  {
    x = random(3);
    switch(x){
    case 0:
      write("You wave your staff in a broad arc...\n\n\t"+atk->QN+
        " is engulfed in a raging "+HIY+"* * CRASH "+
        "* *"+NORM+" of "+NORM+BOLD+BLK+"THUNDER!\n\n"+NORM);
      say(TP->QN+" waves "+TP->POS+" staff in a broad arc...\n\n\t"+
        atk->QN+" is engulfed in a raging "+HIY+"* * CRASH "+
        "* *"+NORM+" of "+NORM+BOLD+BLK+"THUNDER!\n\n"+NORM);
      break;
    case 1:
      write(HIY+"Lightning"+NORM+" explodes from the runes of your staff!\n"+
        atk->QN+" is consumed by a "+BOLD+BLK+
        "raging storm "+NORM+"of "+HIY+"lightning!\n"+NORM);
      say(HIY+"Lightning"+NORM+" explodes from the runes of "+TP->QN+
        "'s staff!\n"+
        atk->QN+" is consumed by a "+BOLD+BLK+
        "raging storm "+NORM+"of "+HIY+"lightning!\n"+NORM);
      break;
    case 2:
      write("The runes of your staff glow with "+BOLD+BLK+
        "thunderous power...\n"+NORM+
        "You strike "+atk->QN+" in an explosion of "+BOLD+BLK+"thunder"+NORM+
        " and "+HIY+"lightning!\n"+NORM);
      say("The runes of "+TP->QN+"'s staff glow with "+BOLD+BLK+
        "thunderous power...\n"+NORM+TP->QN+
        " strikes "+atk->QN+" in an explosion of "+BOLD+BLK+"thunder"+NORM+
        " and "+HIY+"lightning!\n"+NORM);
      break;
    }
    if(atk->query_hp() > (power / 10))
      atk->heal_self(-(power / 10));
    return (power / 10);
  }
  x = random(9);
  switch(x){
  case 0:
    write("A "+HIY+"band of lightning"+NORM+" surges across your staff.\n");
    say("A "+HIY+"band of lightning"+NORM+
      " surges across "+TP->QN+"'s staff.\n");
    break;
  case 1:
    write("Your staff glows as "+HIY+"lightning"+NORM+
      " crackles through the air.\n");
    say(TP->QN+"'s staff glows as "+HIY+"lightning"+NORM+
      " crackles through the air.\n");
    break;
  case 2:
    write("You wave your staff as "+HIY+"lightning"+NORM+
      " shoots into the air.\n");
    say(TP->QN+" waves "+TP->POS+" staff as "+HIY+"lightning"+NORM+
      " shoots into the air.\n");
    break;
  case 3:
    write("An "+HIY+"arc of lightning"+NORM+
      " leaps from your staff into the air.\n");
    say("An "+HIY+"arc of lightning"+NORM+
      " leaps from "+TP->QN+"'s staff into the air.\n");
    break;
  case 4:
    write("You can hear thunder rolling through the sky above.\n");
    say("Thunder can be heard rolling through the sky above.\n");
    break;
  case 5:
    write("Thunder can be heard off in the distance.\n");
    say("Thunder can be heard off in the distance.\n");
    break;
  case 6..8:
    break;
    return 1;
  }
}

