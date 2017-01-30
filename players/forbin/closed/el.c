extra_look(){
  string s,w;
  object a,e;
  if(environment()->is_player())
  {
    if(guild_level == 2) w = "two";
    else if(guild_level == 3) w = "three";
    else if(guild_level == 4) w = "four";
    else if(guild_level == 5) w = "five";
    else if(guild_level == 6) w = "six";
    else if(guild_level == 7) w = "seven";
    else if(guild_level == 8) w = "eight";

    if((a = this_player()) && (e = environment()) && (e == a)) 
    {     
      s = "You have a scar in the shape of an X"+
        " in the palm of your left hand";
      if(guild_level == 1)
        s += ".\nYou have one deep scar"+
        " running along your left arm";
      else if(guild_level >= 2)
        s += ".\nYou have "+w+" deep scars"+
        " running along your left arm";
    }
    else 
    {    
      s = USER->query_name()+" has a scar in the shape of an X"+
        " in the palm of "+USER->POS+" left hand";
      if(guild_level == 1)
        s += ".\n"+USER->query_name()+" has one deep scar"+
        " running along "+USER->POS+" left arm";
      else if(guild_level >= 2)
        s += ".\n"+USER->query_name()+" has "+w+" deep scars"+
        " running along "+USER->POS+" left arm";
    }
    return s;
  }
}