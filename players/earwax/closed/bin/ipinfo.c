string name, hostname, called_from_ip;

status main(string arg) {
  int i;
  string *files;

  i = sizeof(files = get_dir("/pfiles/"+arg+"/"));
  if (!i) { write("Could not get dir:  /pfiles/"+arg+"/*.o\n"); return 1; }

  while(i--) {
    restore_object("pfiles/"+arg+"/"+files[i][0..-3]);
    write_file("/players/earwax/closed/IPINFO", name+";"+hostname+";"+called_from_ip+"\n");
    write(pad(files[i][0..-3], 15)+name+"\n");
  }
  write("Complete.\n");
  return 1;
}
