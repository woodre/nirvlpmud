#define SAVE "players/cosmo/hslist/alltime"
string *at_names;
int *at_scores;
reset(arg) {
  if(arg) return ;
  at_names = ({"Blank","Blank","Blank","Blank","Blank","Blank","Blank","Blank",
               "Blank","Blank","Blank","Blank","Blank","Blank","Blank"});
  at_scores = ({1500,1400,1300,1200,1100,1000,900,800,700,600,500,400,300,200,100});
}
short() { return "A score filler"; } 
id(str) { return str == "filler" || str == "score filler"; }
long() { 
  write("Type \"save_scores\" or \"restore_scores\" to reset scores.\n"); 
}
init() { 
  add_action("save_scores","save_scores"); 
  add_action("restore_scores","restore_scores");
}
save_scores() {
  save_object(SAVE);
  write("Ok.\n");
  return 1;
}
restore_scores() {
  at_names = ({}); /* zero out */
  at_scores = ({}); /* zero out */
  restore_object(SAVE);
  write("Ok.\n");
  return 1;
}
