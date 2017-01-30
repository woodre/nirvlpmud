string pretitle,title,race,gender,al_title,description;
string name;
int *phys_at;

load_info(str) {
  if(!restore_object("pfiles/"+extract(str,0,0)+"/"+lower_case(str))) {
    write("That person doesn't exist, is inactive, or is banished.\n");
    return 1;
  }
  if(!name) { write("Panic.\n"); return 1; }
  write("You see a vision:\n");
  write("\n"+pretitle+" "+capitalize(name)+" "+title+"\n");
  write(capitalize(name)+" is a "+gender+" "+race+
        " "+phys_at[1]+" feet "+phys_at[2]+" inches tall and "+
        phys_at[3]+" lbs.\n");
  write("You get the feeling "+capitalize(name)+" is of "+al_title+" alignment.\n");
  if(!description)
    write("\n"+capitalize(name)+" doesn't seem to have any distinctive features.\n");
  else
  write("\n"+capitalize(name)+" "+description+"\n");
  return 1;
}
