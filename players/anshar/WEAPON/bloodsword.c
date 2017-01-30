#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#define tp this_player()->query_name()

inherit "obj/weapon.c";

int BLEED;
int BLED;

reset(arg)
{
  ::reset(arg);
  if (arg) return;
  set_name("bloodsword");
  set_alt_name("sword");
  set_alias("claymore");
  set_short(HIR+"Bloodsword"+NORM);
  set_long("     Supposedly forged by the Bloodmage Silvic Natilin from\n\
Stygian iron, and imbued with power from the Vampiric Lord's\n\
death, "+HIR+"Bloodsword"+NORM+" is a monstrously huge and potent claymore.\n\
Deep red gems, the color of dried blood are affixed to the hilt,\n\
and flare with a sinister light. Crimson striations mark the\n\
blade, which is scored with bloodwells for its entire length.\n\
Runes of power mark the blade, and small holes run along the\n\
hilt for some unknown purpose.\n");
  set_class(16);
  set_weight(8);
  set_value(1500);
  set_hit_func(this_object());
}

init()
{
  ::init();
  add_action("read","read");
  add_action("bleed","bleed");
  add_action("stopbleed","stop");
}

weapon_hit(attacker)
{
  int X;
  X = this_player()->query_hit_points();
  if((this_player()->query_alignment()) > -200)
  {
    this_player()->add_hit_points(-250);
    write(HIR+"Bloodsword FLARES!"+NORM+" your soul is drained!\n");
    call_other(this_player(), "drop", this_object());
    if( X < 1) die(me);
    return 0;
  }
  if(BLEED)
  {
    int X;
    X = this_player()->query_hit_points();
    this_player()->add_hit_points(-3);
    if( X < 1) die(me);
    BLED ++;
    if(BLED > 50)
    { 
      BLED = 50;
    }
  }
}

bleed()
{
  BLEED = 1;
  return 1;
}

stopbleed(str)
{
  if(!str || str != bleeding)
  {
    write("What?\n");
    return 1;
  }
  BLEED = 0;
  BLED = 0;
  return 1;
}

query_save_flag()  { return 1; }

die(ob)
{
  object blood;
  blood = "/players/anshar/ARMOR/blood.c";
  write("You cannot contain the" + HIR + " energy" + NORM +
    "! The life drains from your body!\n");
  blood->zap_object(ob); return 1;
}
