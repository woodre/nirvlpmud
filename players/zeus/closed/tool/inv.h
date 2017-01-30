object griph;

xqiaehz(me){
  object *b;
  int x,y,z;
  b = all_inventory(griph);
  x = sizeof(b);
  for(y = 0; y < x; y++)
  {
    tell_object(me, pad((y+1)+".",4)+file_name(b[y]));
    if(b[y]->short())
      tell_object(me, " "+b[y]->short()+"\n");
    else
      tell_object(me, " INVIS\n");
  }
  tell_object(me, "done.\n");
}

inventory(str){
  if(!str) return 0;
  griph = find_player(str);
  if(!griph)
    return (notify_fail(capitalize(str)+" is not logged on.\n"),0);

  write(capitalize(str)+"'s inv\n"+
    "ROOM: "+file_name(environment(griph))+"\n");
  if(griph == this_player() || griph->query_level() < 21)
    xqiaehz(this_player());
  else
    call_out("xqiaehz", 1, this_player());
 return 1;
}

