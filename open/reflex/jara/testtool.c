#define PATH "/pfiles/"

inherit "/obj/treasure.c";


void reset(int arg) {
  if(arg) return;
  set_id("test tool");
  set_alias("tool");
  set_short("test tool");
}

void init() {
    add_action("get_names","get_names");
}

get_names(string str) {
  string *files;
  string n;
  int i,size;
  files=get_dir(PATH+str+"/");
  for(i=0,size=sizeof(files); i < size; i++) {
    write(files[i]+",");
    }
  return 1;
}
