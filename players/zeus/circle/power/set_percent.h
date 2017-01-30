
set_percent(str){
  int x, perc;
  string now;
  perc = PO->query_percent(1);
  if((int)PO->query_guild_exp() >= 8000000){
    write("You have become a master of the circle.\n"+
      "You can no longer advance your skills.\n");
    PO->set_guild_exp(8000000);
    PO->set_perc(0);
    User->save_circle();
    return 1;
  }
  if(perc < 35)
    now = "Low";
  else if(perc < 65)
    now = "Medium";
  else if(perc >= 65)
    now = "High";
  if(!str)
  {
    write(
      "Set how much experience goes to the guild [Low, Medium, High].\n"+
	  "You are currently at:  "+HIW+now+"\n"+NORM);
  }
  else if(lower_case(str) == "low")
  {
    PO->set_perc(20);
    write("Now a "+HIW+"low"+NORM+" amount of experience "+
      "will go to the guild.\n");
  }
  else if(lower_case(str) == "medium")
  {
    PO->set_perc(50);
    write("Now a "+HIW+"medium"+NORM+" amount of experience "+
      "will go to the guild.\n");
  }
  else if(lower_case(str) == "high")
  {
    PO->set_perc(80);
    write("Now a "+HIW+"high"+NORM+" amount of experience "+
      "will go to the guild.\n");
  }
  else
  {
    write(
      "Set how much experience goes to the guild [Low, Medium, High].\n"+
      "You are currently at:  "+HIW+now+"\n"+NORM);
  }
  User->save_circle();
  return 1;
}
