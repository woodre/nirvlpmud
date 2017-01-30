#include "/players/mythos/closed/guild/def.h"
#include "/sys/ansi.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("demon");
  set_short();
  set_race("guard");
  set_gender("demon");
  set_alias("nightmare");
  set_long(HIK+"A thing of "+NORM+CYAN+"mist"+HIK+"....\n"+NORM);
  set_hp(500);
  set_level(23);
  set_al(-1000);
  set_wc(30);
  set_ac(21);
  set_heal(5,20);
  /* it's mist, physical damage would not be very effective */
  set_res(25);
  add_money(random(2000)+3750);
  set_weapon_params("other|electric", 5, 0);
  set_weapon_params("other|water", 5, 0);
  set_armor_params("other|water",10,50,0);
  set_armor_params("other|electric",5,10,0);
  set_armor_params("other|fire",-10,-50,"fireDamage");  
  set_wc_bonus(10);
  add_spell("flash",
            "The mist flashes with "+HIY+"sudden brilliance"+NORM+"!\n\n"+  
            HIR+"* C R A C K *  "+HIY+"You feel a great "+HIR+HBYEL+"electrical shock"+NORM+HIY+" run through you!  "+HIR+"* C R A C K *\n\n"+NORM,
            "The mist flashes with "+HIY+"sudden brilliance"+NORM+"!\n"+
            "#CTN is blasted by a wave of "+HIY+"electrical energy"+NORM+"!\n",
            40,({"25-45","10-20"}),({"other|electric","other|sonic"}),6);
}

fireDamage() {
  tell_room(environment(this_object()), "The "+this_object()->query_name()+" screams out in pain from the "+HIR+"fire attack"+NORM+"!!!\n");
  return 0;
}

waterBlock() {
  tell_room(environment(this_object()), "The "+this_object()->query_name()+" screams out in pain from the "+HIR+"fire attack"+NORM+"!!!\n");
  return 0;
}