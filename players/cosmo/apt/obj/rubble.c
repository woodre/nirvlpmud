#define tp this_player()->query_name()

short() { return "A pile of rubble" ; }

long() {
  write("The remains of the table upon which Newman landed.\n");
  write("It may be worth a closer inspection.\n");
}

id(str) { return str == "rubble" || str == "pile"; }

int count;

reset(arg) {
  if(arg) return;
}

get() { return 0; }

init() {
  add_action("search","search");
}

search(arg) {
  if(!arg) {
    write("What?\n"); return 1; }
  if((arg=="rubble" || arg=="pile") && count==0) {
    say(capitalize(tp)+" searches the rubble.\n");
    write("You find a U.S. Postal Service Uniform!!\n");
    move_object(clone_object("/players/cosmo/apt/armor/usps.c"), environment());
    count = 1; }
  else { write("You find nothing.\n"); }
  return 1;
}

