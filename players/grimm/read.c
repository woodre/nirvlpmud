inherit "obj/treasure";
reset (arg) {
  if(arg) return;
  set_alias("reader");
  set_short("reader");
  set_long("Usage:  read <filename>   or   grep <string> <filename>\n");
  set_weight(0);
  set_value(0);
}
 
init() {
  add_action("read","read");
  add_action("grep","grep");
  ::init();
}
 
read(str) {
  string ln;
  int i;
  if (!str) return;
  i=1;
  ln=read_file(str,i);
  while(ln) {
    write(ln);
    i++;
    ln=read_file(str,i);
    }
  return 1;
}
 
grep(str) {
  string ln,filename,strang;
  string dummy,dummy2;
  int i;
  if(!str) return;
  i=1;
  sscanf(str,"%s /%s",strang,filename);
  filename="/"+filename;
  ln=read_file(filename,i);
  while(ln) {
    if(sscanf(ln,"%s"+strang+"%s",dummy,dummy2)) {
      write(ln);
    }
    i++;
    ln=read_file(filename,i);
    }
  return 1;
}
