#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "obj/monster";

reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("coran");
  set_short("A large bare chested man");
  set_alias("man");
  set_race("god");
  set_long("     This must be the largest man you have ever laid eyes\n\
upon! From the bulging biceps, to the massive chest, the \n\
man's physique screams of prodigious strength and stamina.\n\
His curly brown shoulder length hair nearly covers his deep\n\
blue eyes that regard you with a look of pity.\n");
  set_hp(1000);
  set_level(20);
  set_al(-1000);
  set_wc(40);
  set_ac(13);
  set_aggressive(0);
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("Coran's sad eyes stare deep into your soul.\n");
  load_chat("The large man stretches, his muscles tightening and popping.\n");
  load_a_chat("Coran pummels you with large fists.\n");
  set_chance(25);
  set_spell_dam(60);
  set_spell_mess1("Coran slams his opponent with a fist surrounded by a "
    + RED + "red aura" + NORM + ".\n");
  set_spell_mess2("A crackling " + RED + "red aura" + NORM +
    " surrounds Coran's hand as he pounds into you.\nYour body writhes \
in pain.\n");
}

heart_beat()
{
  object stuck_weapon;
  ::heart_beat();
  if (query_attack() && random(100) <= 5)
  {
    stuck_weapon=0;
    stuck_weapon=query_attack()->query_weapon();
    if (stuck_weapon==query_attack()) stuck_weapon=0;
    if (stuck_weapon)
    {
      if(!stuck_weapon->query_auto_load())
      {
        if(!stuck_weapon->two_handed())
        {
          query_attack()->stop_wielding();
          tell_room(environment(this_object()),
            query_attack()->query_name()+"'s "+stuck_weapon->short()+
            " is ripped out of "+query_attack()->query_possessive()+
            " hand by Coran!\n");
          move_object(stuck_weapon, this_object());
        }
      }
    }
  }
}
