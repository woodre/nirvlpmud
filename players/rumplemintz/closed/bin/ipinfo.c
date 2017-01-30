string name, hostname, called_from_ip;

status main(string arg) {
  int i;
  string *files;

  i = sizeof(files = get_dir("/pfiles/"+arg+"/"));
  if (!i) { write("Could not get dir:  /pfiles/"+arg+"/*.o\n"); return 1; }

  while(i--) {
#ifndef __LDMUD__
    restore_object("pfiles/"+arg+"/"+files[i][0..-3]);
#else
    restore_object("pfiles/"+arg+"/"+files[i][0..<3]);
#endif
    write_file("/players/earwax/closed/IPINFO", name+";"+hostname+";"+called_from_ip+"\n");
#ifndef __LDMUD__
    write(pad(files[i][0..-3], 15)+name+"\n");
#else
    write(pad(files[i][0..<3], 15)+name+"\n");
#endif
  }
  write("Complete.\n");
  return 1;
}
