blush()  {
string gender;
  gender = "its";
  if(TP->query_gender() == "male") { gender = "his"; }
  if(TP->query_gender() == "female") { gender = "her"; }
  write("You lower your eyes and blush a deep crimson red.\n");
  say(tp+" lowers "+gender+" eyes and blushes a deep crimson red.\n");
  return 1;
        }
