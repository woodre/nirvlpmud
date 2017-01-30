int
cmd_iwho( string str ) {
  object *us;
  string is_invis;
  int x, y;
  us=users();
  write("Player------------>location\n");
  for(x=0; x<sizeof(us); x++) {
    string pname;

    is_invis = (string) us[x]->short();
    
    pname = (string) us[x]->query_real_name();
    y = x+1;
    write(pad(y + ". ",4)+pad(query_idle(us[x])/60,4)+pad(capitalize( pname ), 20));
    if( environment( us[x] ) ) 
      write(environment(us[x])->short());
    write("\n");
  }
  return 1;
}
