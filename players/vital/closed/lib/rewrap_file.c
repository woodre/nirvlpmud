/* this rewraps files at WRAPAT chars so they look nice for all */
#define WRAPAT 75
#define ROOT "/players/wizardchild/congo/rooms/"
#define ERROR(str) return (this_player() ? \
  tell_object(this_player(), str) || 1 : 0)
 
#pragma strict_types
#pragma save_types
 
status rewrap_file(string name, status congo) {
  string fn, *file, tmp;
  string oldfile, foo, tmp2;
  if(!name || name == "") 
    ERROR("No filename.\n");
  fn = name;
  if(fn[0] != '/') fn = ROOT+fn;
  if(file_size(fn) < 1) 
    ERROR("No file.\n");
  oldfile = read_file(fn);
  if(!oldfile || oldfile == "")
    ERROR("File not read.\n");
  if(congo) {
    sscanf(oldfile, "%s**%s**%s", foo, oldfile, tmp2);
  }
  file = explode(oldfile, "\n");
  if(!sizeof(file)) 
    ERROR("Unable to explode file.\n");
  tmp = implode(file, " ");
  if(congo) 
    write_file(fn+".Old", foo+"**"+oldfile+"**"+tmp2);
  else
    write_file(fn+".Old",oldfile);
  rm(fn);
  if(congo)
    write_file(fn, foo+"**"+format(tmp, WRAPAT)+"**"+tmp2);
  else
    write_file(fn, format(tmp, WRAPAT));
  ERROR("Ok.\n");
}
