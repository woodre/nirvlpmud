#include "/players/fred/closed/bloodfist/defs.h"
/* #define FAITH (gob->query_attrib(5) + gob->query_attrib(5)) */
object ths, shad;

set_bloodfist_player_shadow(object obj){
  ths = obj;
  shadow(ths,1);
}

query_bloodfist_player_shadow(){ return 1; }

rm_bloodfist_player_shadow(){
  ths->unshadow();
  destruct(this_object());
  return 1;
}

/* updated with additional wield arguments by illarion 11 dec 2004 */
wield(str,silent,params) {
  ths->wield(str, silent, params);
  if(str && str == ths->query_weapon() && !str->query_bloodfist_wep_shadow())
  {
    shad = clone_object("/players/fred/closed/bloodfist/obj/wep_shadow.c");
    shad->set_bloodfist_wep_shadow(str);
  }
}

/* if a wizard is refunding experience, do not move any portion of it into
   the guild, since it is not earned experience. */
add_exp(amt)
{
  object gob;
  if(this_player())
  {
    if(this_player()->is_player())
    {
      if(this_player()->query_level() >= 21)
      {
        gob = present("bloodfist_gob", ths);
        if(!gob)
        {
          destruct(this_object());
          return;
        }
        gob->add_old_exp(amt);
        ths->add_exp(amt);
        return;
      }
    }
  }
  ths->add_exp(amt);
  if( previous_object() && previous_object()->is_npc() )
    ths->set_top_kill( amt, previous_object() );
}

damage_message(dam)
{
  string msg1, msg2;
  if(dam > 40 && !random(4))
  {
    msg1 = "You stagger from the blow.\n";
    msg2 = ths->query_name()+" staggers from the blow.\n";

    tell_object(ths, msg1);
    tell_room(environment(ths), msg2, ({ ths }));
  }
  if(random(dam) > 8+random(50)
    && (ths->query_hp() < (ths->query_mhp() * 2/3)))
    tell_object(ths, RED+"Blood drips from your wounds.\n"+NORM);
}

/* calc gained potential and honor for solo and partying */
/* guild exp formula 
   (glvl + (npc_lvl / 3) + 58%dmg_tkn) * (1 + (1/3 of ac) + ((glvl+4) / 2)) */


/* workaround code, adds one honor for the player */
bfht()
{
  object gob;
  if(!previous_object()->query_log()) return 0;
  gob = present("bloodfist_gob", ths);
  HONOR_DAEMON->add_honor(ths->query_real_name(), 1, gob);
}

/* increased damage taken based on combat stance */
/* also deals with endurance gain, guild experience and honor */
hit_player(dam){
  object gob;
  int stance, dmg_mod, new_dmg;
  gob = present("bloodfist_gob", ths);
  if(!gob)
  {
    destruct(this_object());
    return;
  }
  stance = gob->query_stance(1);

  if(this_player())
  {
    if(this_player() == ths)
    { 
      ths->hit_player(dam);
      return dam; 
    }
  }
                       dmg_mod = 110;  /* neutral    */
  if(stance == 2)      dmg_mod = 120;  /* aggressive */
  else if(stance == 3) dmg_mod = 130;  /* violent    */
  else if(stance == 4) dmg_mod = 140;  /* murderous  */
  else if(stance == 5) dmg_mod = 150;  /* insane     */

  if(gob->query_bloodlust())
    dmg_mod += 15;

  new_dmg = (dmg_mod * dam / 100) + stance;

  if(gob->query_pain_aura())
    gob->add_endurance((new_dmg * gob->query_endurance_percent()) / 100);
  else
    gob->add_endurance(-(1 + new_dmg * gob->query_endurance_percent()) / 100);

  damage_message(new_dmg);
 
  ths->hit_player(new_dmg);
  return new_dmg;
}

/* block nirvana alignment with honor level */
align_title()
{
  object gob;
  string al_title;
  int my_honor;
  my_honor = (int)HONOR_DAEMON->query_honor(ths->query_real_name());
  gob = present("bloodfist_gob", ths);
  if(gob && my_honor >= 0 && ths->query_level() < 21)
  {
    if(gob->is_testchar())
      al_title = "Bloodfist";
    else if(my_honor < gob->query_hrank(1))
      al_title = RED+"BloodInitiate"+NORM;
    else if(my_honor < gob->query_hrank(2))
      al_title = RED+"BloodApprentice"+NORM;
    else if(my_honor < gob->query_hrank(3))
      al_title = RED+"BloodRogue"+NORM;
    else if(my_honor < gob->query_hrank(4))
      al_title = RED+"BloodWarrior"+NORM;
    else if(my_honor < gob->query_hrank(5))
      al_title = RED+"BloodLord"+NORM;
    else if(my_honor > gob->query_hrank(5))
      al_title = RED+"BloodMaster"+NORM;
    else
      al_title = "Bloodfist";
    ths->set_al_title(al_title);
    return al_title;
  }
  else
    return (ths->query_al_title());
}

short(){  align_title();  return (ths->short()); }
score(){  align_title();  return (ths->score()); }

query_al_title(){ return align_title(); }
