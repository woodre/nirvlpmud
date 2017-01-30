/* makelib.c: for use w/ exe */
/* this generates a lib file */
 
#define OUTPUT "/players/wizardchild/lib/lib.h"
#define GF     "/players/wizardchild/lib/get_files.c"
#define GP     "/players/wizardchild/lib/get_prototype.c"
#define ROOT   "/players/wizardchild/lib/"
 
exe_cmd() {
  string *f, out, tmp;
  int i;
  if(file_size(GF) < 1) {
    write("Error, missing file: ~/lib/get_files.c\n");
    return 1;
  }
  if(file_size(GP) < 1) {
    write("Error, missing file: ~/lib/get_prototype.c\n");
    return 1;
  }
  call_other(GP,"??");
  call_other(GF,"??");
  if(file_size(OUTPUT) > 0)
    rm(OUTPUT);
  f = GF->get_files(ROOT+"*");
  out = "";
  for(i = 0; i < sizeof(f); i++) 
    if(tmp = GP->get_prototype(ROOT, f[i], 1)) {
      out += tmp+"\n";
    }
  write_file(OUTPUT, out);
  write("Completed. "+i+" files found.\n");
  return 1;
}
