id(str) { return str == "ball"; }
short() {write("A crystal ball\n"); }
long()  {write(
   "Snow's crystal ball of seeing. 'peer into ball' to use.\n"); }
alias() {return "ball"; }
get()   {return 1; }
drop()  {return 1; }

query_weight() {return 1; }

init() {

add_action("peer","peer");

   }

peer(arg) {

if (arg == "into ball") {
 write("You gaze deeply into the ball...\n"+"\n");
 say(this_player()->query_name()+" gazes deeply into the crystal ball...\n");
if (this_player()->query_level() < 21) {
 write("You cannot comprehend what you see... the images elude you.\n");
 say(this_player()->query_name()+" looks confused.\n");
return 1;
         }
else
 write("All becomes clear to your wizardly eye!\n");
 say(this_player()->query_name()+" nods in understanding.\n");
iwho();
return 1;
  }
}

iwho(str) {
  object us;
string is_invis;
  int x, y;
  if(str) return;
  us=users();
write("[-----*inv player*--------*location*--------------]\n");
  for(x=0;x<sizeof(us);x++) {
        is_invis = us[x]->short();
        y = x+1;
        if(is_invis==0){
        write("["+y + "]\t" + capitalize(us[x]->query_real_name()));
      if(strlen(us[x]->query_real_name())>7)
        write("\t"); else write("\t\t");
      write(environment(us[x])->short());
      write("\n");
        }
  }
  return 1;
}
