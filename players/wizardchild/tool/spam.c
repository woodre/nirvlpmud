inherit "/obj/user/one_chan.c";
spam(str) {
  object who;
  string *dir,file;
  int i, so;
  if(!(who = find_player(str))) {
    write("No such player.\n");
    return 1;
  }
dir = get_dir("/players/wizardchild/closed/logger/help/");
  for(i = 0, so = sizeof(dir); i < so; i++) {
    write("Current file: "+dir[i]+"\n");
    if(dir[i] != "." && dir[i] != "..")
    file = read_file("/players/wizardchild/closed/logger/help/"+dir[i]);
    if(strlen(file))
      tell_object(who, file);
    else write("No file.\n");
    if(!interactive(who)) {
      write("SPPAAAMMMEEDD!!\n");
      chan_msg("You see "+who->query_name()+"'s ass fly streaking across the mud, covered in spam.\n", "junk");
      break;
    }
  }
  write("Ok.\n");
  return 1;
}
