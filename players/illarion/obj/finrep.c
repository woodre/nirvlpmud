string find_and_replace(string str,string what,string with) {
  string bef,aft,ret;
  while(str) {
    if(sscanf(str,"%s"+what+"%s",bef,aft)) {
      ret+=bef+what;
      str=aft;
    } else {
      bef+=str;
      break;
    }
  }
  return ret;
}
