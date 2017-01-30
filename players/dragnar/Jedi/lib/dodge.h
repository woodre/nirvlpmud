Dodge() {
  if(damage > 0 && old_hp){
    switch(random(5)){
    case 1:
      tell_object(USER,
      "-+- ["+query_mon_color()+"You dodge right, narrowly missing being hit!"+NORM+"]\n");
    break;
    case 2:
      tell_object(USER,
      "-+- ["+query_mon_color()+"You jump back, dodging your attacker!"+NORM+"]\n");	    
      break;
    case 3:
      tell_object(USER,
      "-+- ["+query_mon_color()+"You flip into the air, flying over your opponents shoulder,\n"+
      "     causing "+attack->query_name()+" to fumble "+attack->query_possessive()+" attack!"+NORM+"]\n");  
      break;
    case 4:
      tell_object(USER, 
      "-+- ["+query_mon_color()+"You jump into a backspin, flying out of danger!"+NORM+"]\n");
      break;
    default:
      tell_object(USER,
      "-+- ["+query_mon_color()+"You dodge to your left, causing your attacker to fumble!"+NORM+"]\n");
      break; 
	}  
    USER->add_hit_point(damage);
    new_hp += damage;	    
    old_hp = new_hp;
  }
}
