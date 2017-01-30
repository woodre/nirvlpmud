inherit "/obj/monster";

object env;

reset(arg) {
  ::reset(arg);
  set_dead_ob(this_object());
}

init() {
  ::init();
  env = environment(this_object());
}

monster_died() {
  object *ppl,*obs,ob;
  int n,p,size,size2;
  string tmp;
  ppl=all_inventory(environment(this_object()));
  ppl-= ({ this_object() });
  ob=present("corpse",environment(this_object()));
  ppl-= ({ ob });
           /* legality log */
  size=sizeof(ppl);
  log_file("GNAR", pad("", 70, '-' )+"\n");
  log_file("GNAR",basename(this_object()) + " "+ query_name()+" killed "+
    ctime(time())+" by "+this_player()->short()+"\n");
  if(env)
    log_file("GNAR","Location: " + basename(env)+"\n");
  for(n=0;n<size;n++) {
    log_file("GNAR","Name: "+
      ppl[n]->query_name()+" Level: "+ppl[n]->query_level()+"\n");
  }
            /* vanity log */
  log_file("GNAR","Time: "+ctime(time())+"\n");
  log_file("GNAR","Killing blow struck by:\n"+
    this_player()->short()+" ("+capitalize(this_player()->query_real_name())+")\n");
  ppl-= ({ this_player() });
  size=sizeof(ppl);
  if(size) {
    log_file("GNAR","Others present:\n");
    for(n=0;n<size;n++)
     if(ppl[n])
      if((tmp=ppl[n]->short()))
       if((tmp=ppl[n]->query_real_name()))
        log_file("GNAR",tmp+" ("+capitalize(ppl[n]->query_real_name())+")\n");
  }
  log_file("GNAR", pad("", 70, '-' )+"\n");
}


remove_object() {
  string msg;
  object tp;
  tp = this_player();
  
  msg = pad("", 70, '-' )+"\n";
  msg += ctime(time()) + " "+ basename(this_object())+ " dested by: ";
  if( tp )
    msg += tp->query_real_name() +" "+ basename(tp);
  else
    return;
  
  msg += " Loc: ";
  if( env )
    msg += basename(env);
  else
    msg += "Unknown";
    
  msg += "\n";
  msg += pad("", 70, '-' )+"\n";
  log_file("GNAR", msg + "\n");
}
