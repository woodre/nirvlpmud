posessive() {
  return posess(this_player());
}
posess(who) {
  if(who->query_gender() == "male")   return "his";
  if(who->query_gender() == "female") return "her";
  return "its";
}
pronoun() {
  return pro(this_player());
}
pro(who) {
  if(who->query_gender() == "male")   return "he";
  if(who->query_gender() == "female") return "she";
  return "it";
}
noun(who) {
  if(!who) who = this_player();
  if(who->query_gender() == "male")   return "him";
  if(who->query_gender() == "female") return "her";
  return "it";
}  
