#include "/players/feldegast/defines.h"
#define TEMP_FILE "/players/feldegast/closed/tool/TEMP.c"

do_cmd(str) {
  mixed r;
  string def;
  int i;

  rm(TEMP_FILE);
  if(find_object(TEMP_FILE))
    destruct(TEMP_FILE);

  def=read_file("/players/feldegast/defines.h");
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

  if(find_object(TEMP_FILE))
    destruct(find_object(TEMP_FILE));

  return 1;

}
