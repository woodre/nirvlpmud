#include "/players/feldegast/defines.h"
#define TEMP_FILE "/players/feldegast/closed/tool/TEMP.c"
#define DEF_FILE "/players/feldegast/defines.h"
#define OWNER "feldegast"

do_cmd(str) {
  object file;
  mixed r;
  string def;
  int i;

  if(this_player()->query_real_name()!=OWNER) {
    write_file("/players/feldegast/log/DANGER",TPRN+" attempted to use your exec tool.\n");
    return 0;
  }
  rm(TEMP_FILE);
  file=find_object(TEMP_FILE);
  if(file) destruct(file);

  def=read_file(DEF_FILE);
  write_file(TEMP_FILE,def);
  write_file(TEMP_FILE,
    "execute_me() {\n"
    +str+
    "\n}\n"
  );
  write("Return: ");
  r=TEMP_FILE->execute_me();

  if(stringp(r)) write("<string> ");
  if(intp(r)) write("<int> ");

  if(pointerp(r)) {
    write("<array>\n");
    for(i=0; i < sizeof(r); i++)
      write(r[i]+"\n");
  } else
    write(r+"\n");
  rm(TEMP_FILE);

  file=find_object(TEMP_FILE);
  if(file) destruct(file);

  return 1;

}
