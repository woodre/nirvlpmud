heart_beat(){
   if(!environment()) return;
   
   if(earth_shield){ earth_shield -= 1;
      if(!earth_shield) tell_object(USER, "Your "+YEL+"rock-skin"+NORM+" returns to normal.\n"); }
   
   if(fire_shield){ fire_shield -= 1;
      if(!fire_shield) tell_object(USER, "The "+HIR+"flames"+NORM+" around your body extinguish.\n"); }
   
   if(water_shield){ water_shield -= 1;
      if(!water_shield) tell_object(USER, "The "+HIB+"misty rains"+NORM+" around your body evaporate.\n"); }
   
   if(wind_shield){ wind_shield -= 1;
      if(!wind_shield) tell_object(USER, "Your "+HIC+"winds"+NORM+" around your body settle to a calm.\n"); }
   
if(fire_hands){ fire_hands -= 1;
if(!fire_hands) tell_object(USER, "The "+HIR+"fire"+NORM+" around your hands diffuses.\n"); }

   if(USER->query_level() > 19) return;
}
