stance_damage(user, dam)
{
  object gob;
  int stance, dmg_mod, dam1, dam2, dam3;
  gob = present("bloodfist_gob", user);
  if(!gob) return;
  
  stance = gob->query_stance();
  
  if(stance == 1)        dmg_mod = -1000; /* neutral   */
  else if(stance == 2)   dmg_mod = -2000; /* aggresive */
  else if(stance == 3)   dmg_mod = -3000; /* violent   */
  else if(stance == 4)   dmg_mod = -4000; /* murderous */
  else if(stance == 5)   dmg_mod = -5000; /* insane    */

  if(gob->query_bloodlust())
    dmg_mod -= 1500;
 
  if(gob->query_pain_aura())
    gob->add_endurance((dam * gob->query_endurance_percent()) / 100);
  else
    gob->add_endurance(-(1 + dam * gob->query_endurance_percent()) / 100);


  gob->honor_calc(dam);
  
  
  dam1 = (-(dmg_mod/10));
  
  dam2 = ((dam * dam1)/1000);

  dam3 = dam + dam2;

  gob->dodge_check(dam3);

  
  if(gob->is_testchar())
    tell_object(user, "Dam is "+dam+", Dam 1 is "+dam1+", Dam 2 is "+dam2+", Dam 3 is "+dam3+"\n");

  return dmg_mod;
}  
