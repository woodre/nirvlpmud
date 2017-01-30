set_herb(str){
  int num;
  string nam;
  sscanf(str, "%d %s", num, nam);
  parents[num]=nam;
  write("set #"+num+" to parent "+nam+"\n");
  return 1;
  }
  
  set_amount(str){
  int num;
  int nam;
  sscanf(str, "%d %d", num, nam);
  levels[num]=nam;
  write("set #"+num+" to level "+nam+"\n");
  return 1;
  }