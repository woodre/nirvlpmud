do_cmd(str) {
  object *everybody;
  string good,bad;
  object current;
  string file;
  int i;
  string name;
  if(!str) name="feldegast";
  else name=str;
  everybody=users();
  for(i=0; i < sizeof(everybody); i++) {
    current=first_inventory(everybody[i]);
    while(current) {
    file=file_name(current);
    if(sscanf(file,"%s"+name+"%s",good,bad)==2) {
      write(pad(everybody[i]->query_name(),20));
      write(current->short()+"\n");
    }
    current=next_inventory(current);
    }
  }
  return 1;
}
