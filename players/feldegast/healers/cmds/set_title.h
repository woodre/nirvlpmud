do_set_title(str) {
  string title;
  int n;

  if(str) sscanf(str,"%i",n);
  if(!n) n=TP->query_guild_rank();
  if(n > TP->query_guild_rank())
    n=TP->query_guild_rank();

  switch(n) {
    case 1: title="the "+BOLD+"Student"+NORM;
            break;
    case 2: title="the "+BOLD+"Apprentice"+NORM;
            break;
    case 3: title="the "+BLU+"Journeyman"+NORM;
            break;
    case 4: title="the "+HIB+"Healer"+NORM;
            break;
    case 5: title="the "+CYN+"Healer"+NORM;
            break;
    case 6: title="the "+HIB+"Master Healer"+NORM;
            break;
    default: write("Invalid title.\n");
             return 1;
             break;
  }
  write("Your new title is '"+title+"'.\n");
  TP->set_title(title);
  return 1;
}

