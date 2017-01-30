bop(str){
string gender;
if(!str){
 write("You look around for somebody to bop.\n");
 say(tp+" looks around for somebody to bop.\n");
return 1;   }
str = capitalize(str);
gender = this_player()->query_possessive();
if(str == "Saber") {
  write("You wouldn't want to do that!\n"+
     "You bop yourself over the head many times!\n");
  say(tp+" bops himself over the head many times!\n");
  say(tp+" looks VERY confused.\n");
  return 1;
}
  write("You bop "+str+" over the head with your hoopak!\n");
  write(str+" looks confused.\n");
  say(tp+" bops "+str+" over the head with "+gender+" hoopak.\n");
  say(str+" looks confused.\n");
return 1;  }
