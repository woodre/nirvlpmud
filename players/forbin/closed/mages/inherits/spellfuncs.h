string colorize_letters(string str) {
  string msg, letter;
  int i;

  msg = "";
  for(i = 0; i < strlen(str); i++) {
    letter = extract(str,i,i);
    switch(random(13) {
      case 0: letter = RED+letter; break; 
      case 1: letter = YEL+letter; break;
      case 2: letter = GRN+letter; break;
      case 3: letter = BLU+letter; break;
      case 4: letter = CYN+letter; break;
      case 5: letter = MAG+letter; break;
      case 6: letter = HIR+letter; break;
      case 7: letter = HIY+letter; break;
      case 8: letter = HIG+letter; break;
      case 9: letter = HIB+letter; break;
      case 10: letter = HIC+letter; break;                  
      case 11: letter = HIM+letter; break;
      case 12: letter = HIW+letter; break;
    }
    msg += letter;
  }
  msg += NORM;
  return msg;
}

string colorize_string(string str) {
  string msg;
  switch(random(13) {
    case 0: msg = RED+str+NORM; break; 
    case 1: msg = YEL+str+NORM; break;
    case 2: msg = GRN+str+NORM; break;
    case 3: msg = BLU+str+NORM; break;
    case 4: msg = CYN+str+NORM; break;
    case 5: msg = MAG+str+NORM; break;
    case 6: msg = HIR+str+NORM; break;
    case 7: msg = HIY+str+NORM; break;
    case 8: msg = HIG+str+NORM; break;
    case 9: msg = HIB+str+NORM; break;
    case 10: msg = HIC+str+NORM; break;                  
    case 11: msg = HIM+str+NORM; break;
    case 12: msg = HIW+str+NORM; break;
  }
  return msg;
}