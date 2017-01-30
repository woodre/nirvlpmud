cool(str)  {
string gender;
 if(!str)  {
  gender = "It";
  if(TP->query_gender() == "male") { gender = "He"; }
  if(TP->query_gender() == "female") { gender = "She"; }
  write("You lean back against a wall.\n"+
     "You look pretty damn cool.\n");
  say(tp+" leans back against a wall.\n"+
     gender+" looks pretty damn cool.\n");
  return 1;
     }
  str = CAP;
  write("You think that "+str+" is pretty damn cool.\n");
  say(tp+" thinks that "+str+" s pretty damn cool.\n");
  return 1;
        }
