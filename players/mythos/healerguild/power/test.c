void reset(status arg) {
  int i;
  string a,b,c,d,str, file, *lines;

  file = read_file("/players/earwax/laggers");
  lines = explode(file, "\n");
  i = sizeof(lines);
  while(i--) {
    destruct(find_object(lines[i]));
    write(i+"\t"+lines[i]+"\n");
  }
}
