inv(str){
  string tmp,trash,oldtab;
  int x, max_weight;
  object who,ob,max;
  ob=first_inventory(str);
  if(!ob){
    write("That person isn't carring anything are carring nothing.\n");
    return 1;
  }
  x=0;
  while(ob){
    x=x+1;
    if(ob->short())
      write(ob->short()+"\n");
    else 
      if(ob->query_name())
        write(ob->query_name()+"\n");
    else 
      if(ob->query_real_name())
        write(ob->query_real_name()+"\n");
    max_weight = max_weight + ob->query_weight();
    ob=next_inventory(ob);
  }
  write("That person is carring "max_weight" lbs.\n");
  return 1;
}
