#pragma strict_types
#pragma save_types
 
string get_prototype(string root_dir, string filename, status define) {
  string file, *ex, junk, foo, out, *a;
  int i, so, so2;
  file = read_file(root_dir+filename);
  if(!file || file == "") 
    return "";
  ex = explode(file, "\n");
  file = 0;
  sscanf(filename, "%s.c", file);
  for(i = 0, so = sizeof(ex); i < so; i++) {
    junk = ex[i];
    if(junk[0] == '/' && junk[1] == '*') /* ignore comments */
      continue;
    junk = 0;
    if(sscanf(ex[i], "%s"+file+"(%s) {", junk, foo) == 2) {
      if(!define || define == 0) {
           out = junk+file+"("+foo+")";
        return out;
      }
      a = explode(foo, ",");
      out = file+"(";
      so2 = sizeof(a);
      for(i = 0; i < so2; i++) {
        out += ("a"+i);
        if(i != so2-1)
          out += ",";
        else
          out += ")";
      }
      junk = 0;
      sscanf(out, file+"(%s)", foo);
      junk = "#define "+out+" call_other(\""+(root_dir+filename)+
             "\",\""+file+"\", "+foo+")";
      return junk;
    }
  }
  return "";
}
