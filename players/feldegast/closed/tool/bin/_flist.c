do_cmd(str) {
  object *everybody;
  object current;
  string file;
  int i;
  string name;
  if(!str) name="feldegast";
  else name=str;
  everybody=users();
  for(i=0; i < sizeof(everybody); i++) {
    if(everybody[i]->query_real_name()!=name) {
    current=first_inventory(everybody[i]);
    while(current) {
    file=file_name(current);
    if(creator(current)==lower_case(name)) {
      write(pad(everybody[i]->query_name(),20));
      write(current->short()+"\n");
    }
    current=next_inventory(current);
    }
    }
  }
  return 1;
}
