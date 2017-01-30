/*  Originally coded by Saber for /players/saber/monsters/stormlich.c
    Recode by Zeus
    Recode approved by _ on []
*/

/*
//  Modified for electrical damage, two handed status, re-described,
//    and put into the game 2006.04.16
//  Forbin - approved by Earwax 2006.04.16
*/
/* edited 05-17-07 by tallos to add mage guild bonus*/
#include "/players/zeus/closed/all.h"
inherit "players/vertebraker/closed/std/weapon.c";

int power, x;
#define GUILDID "mageobj"
#define BONUS_TYPE "evocation"
#define BONUS_TYPE2 "conjuration"
#define BONUS_TYPE3 "necromancy"
#define BONUS_TYPE4 "enchantment"
#define BONUS_TYPE5 "illusion"
#define BONUS_AMOUNT  3 
#define BONUS_AMOUNT2 2
#define BONUS_AMOUNT3 2
#define BONUS_AMOUNT4 2
#define BONUS_AMOUNT5 2
reset(arg) {
   ::reset(arg);
   if (arg) return;

  set_name("Staff of Power");
  set_type("staff");
  set_alt_name("staff of power");
  set_short(HIK+"The Staff of "+HIY+"Power"+NORM);
  set_long("Stretching over six feet long, the Staff of Power pulses with living\n"+
           "electrical energy.  Legend tells of its long ago carving from Nightwood,\n"+
           "a deep black wood that grows only in the forests of the DarkenWoods.  A\n"+
           "lightning bolt has been carefully etched into the head of the staff, its\n"+
           "image gilt in gold, and dozens of blue glowing runes have been engraved\n"+
           "down its length.  A single blue gemstone has been set into the staff just\n"+
           "above the tight, leather bound grips.\n");
  set_class(19);
  set_two_handed(1);
  set_weight(4);
  set_value(5000);  
  set_hit_func(this_object());
}
query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2, BONUS_AMOUNT2);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE3, -BONUS_AMOUNT3);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE4, -BONUS_AMOUNT4);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE5, -BONUS_AMOUNT5);				
   }
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
present(GUILDID, this_player())->remove_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
present(GUILDID, this_player())->remove_guild_bonus(BONUS_TYPE2, BONUS_AMOUNT2);
present(GUILDID, this_player())->remove_guild_bonus(BONUS_TYPE3, -BONUS_AMOUNT3);
present(GUILDID, this_player())->remove_guild_bonus(BONUS_TYPE4, -BONUS_AMOUNT4);
present(GUILDID, this_player())->remove_guild_bonus(BONUS_TYPE5, -BONUS_AMOUNT5);	
  }
}
weapon_hit(atk) {
  power = random(35) + this_player()->query_attrib("mag");
  if(!random(10)) {
    x = random(2);
    switch(x) {
      case 0:
        write(BOLD+BLK+"Your staff glows as a healing warmth flows into you!\n"+
          NORM);
        say(BOLD+BLK+TP->QN+"'s staff glows as a healing warmth flows into "+
          TP->OBJ+"!\n"+NORM);
        TP->add_hit_point(5);
        break;
      case 1:
        write(BOLD+BLK+
          "Your staff crackles as an aura of healing encompases you!\n"+NORM);
        say(BOLD+BLK+TP->QN+
          "'s staff crackles as an aura of healing encompases "+TP->OBJ+
          "!\n"+NORM);
        TP->add_spell_point(5);
        break;
    }
    return 0;
  }
  if(power > random(80)) {
    x = random(3);
    switch(x) {
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
    atk->hit_player((power / 10), "other|electric");
    return (power / 10);
  }
  x = random(9);
  switch(x) {
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

