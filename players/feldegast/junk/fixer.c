#define PATH "/players/saber/closed/new_mini/stats/"

inherit "/obj/treasure.c";


void reset(int arg) {
  if(arg) return;
  set_id("wand");
  set_alias("culler");
  set_short("Culling Wand");
  set_long(
"This wand is used to cull files of players who no longer exist.\n"+
"The current directory is set to :"+PATH+"\n"+
"To begin, type 'cull'.\n"
  );
}

void init() {
  if((int)this_player()->query_level() < 20)
    destruct(this_object());
  else
    add_action("cmd_cull","cull");
}

int cmd_cull(string str) {
  string *files;
  string n;
  int i,size;
  files=get_dir(PATH);
  for(i=0,size=sizeof(files); i < size; i++) {
    name=0;
    write(files[i]+"\n");
    if(sscanf(files[i],"%s.o",n)) {
      if(!restore_object("pfiles/"+extract(files[i],0,0)+"/"+n))
        restore_object("players/inactive_saved/"+n);
      if(!name) {
        cp(PATH+files[i],PATH+"bak/"+files[i]);
        rm(PATH+files[i]);
        write("\tRemoving: "+files[i]+"\n");
      }
    }
  }
  return 1;
}
