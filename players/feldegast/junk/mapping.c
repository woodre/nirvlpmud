mapping bonus;

int strength, stamina, will_power, magic_aptitude, piety, stealth, luck, intelligence;
query_attrib(str) {
  int val;
  switch(str) {
    case "str" : val=strength; break;
    case "sta" : val=stamina; break;
    case "wil" : val=will_power; break;
    case "mag" : val=magic_aptitude; break;
    case "pie" : val=piety; break;
    case "ste" : val=stealth; break;
    case "luc" : val=luck; break;
    case "int" : val=intelligence; break;
    default: return 0;
  }
  val+=bonus[str];
  if(val > 30)
    return 30;
  else
    return val;
}

add_bonus(str,n) {
  bonus[str]+=n;
}


reset(arg) {
  bonus=([ ]);
}
