int locklist;
#define maxlock 15

add_locklist(arg) {
int i;
if(!this_player() || this_player()->query_level() < 100) return 0;
log_file("LOCKLIST", this_player()->query_name()+" "+arg+"\n");
 while (i<maxlock) {
  if(!locklist[i]) {
    locklist[i] = arg;
    i=maxlock;
  }
  i+=1;
  }
   savelist();
  return 1;
}

check_locklist(arg) {
int i;
string ajunk,bjunk;
 while (i<maxlock) {
  if(locklist[i]) {
  if(locklist[i] == arg) return arg;
  if(sscanf(arg, locklist[i]+"%s", bjunk) == 1) return arg;
  if(sscanf(arg, "%s"+locklist[i], bjunk) == 1) return arg;
  if(sscanf(arg, "%s"+locklist[i]+"%s", ajunk,bjunk) == 2) return arg;
  }
  i+=1;
 }
return 0;
}

reset(arg) {
 if(arg) return;
 locklist=allocate(20);
 restore_object("obj/locklist");
}

savelist() { save_object("obj/locklist"); }

clear_locklist(arg) {
int i;
if(!this_player() || this_player()->query_level() < 100) return 0;
 while (i<maxlock) {
  if(locklist[i] == arg){
    locklist[i] = 0;
    return 1;
  }
  i+=1;
 }
 return 0;
}
