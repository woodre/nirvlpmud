#define STEP 800
object tp;
/* reads an array of size STEP elements */
grp(str) {
  string *current;
  string file, s,foo,foo2;
  int i, base,so;
  status done;
  if(!str || sscanf(str, "%s %s", s, file) != 2) return 0;
  if(file[0] != '/') file = this_player()->get_path()+file;
  if(file_size(file) < 1) {
    write("File not found.\n");
    return 1;
  }
  tp = this_player();
  while(!done) {
    for(i = 0; i < base+STEP; i++) {
      if(i == 0) current = ({read_file(file, base+i)});
      else current += ({read_file(file, base+i)});
      if(!current[i]) done = 1;
    }
    current += ({s+"#"+base});
    base += STEP;
    call_out("do_grep", 0, current);
    current = ({ });
  }
  return 1;
}
do_grep(current) {
  string s,foo,dip;
  int i, base,max;
  max = sizeof(current)-1;
  sscanf(current[max], "%s#%d", s, base);
  current[max] = 0;
  tell_object(tp, "base = "+base+", s = "+s+"\n");
  for(i = 0; i < max; i++) {
    if(sscanf(current[i], "%s"+s+"%s", foo, dip))
      tell_object(tp, (base+i)+": "+current[i]+"\n");
  }
}

