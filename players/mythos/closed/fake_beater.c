string *beat;

id(str) { return str == "fake_beater" || str == "callouter"; }

get() { return 0; }

drop() { return 1;}

init() {
  if(environment() && living(environment())) {
     destruct(environment(this_object())); 
  }
  add_action("beats","beats");
}

reset(arg) {
  if(arg) return ;
  beat = ({ });
/* 03/20/06 Earwax: why is this always running? */
/*
  call_out("beat_me",3);
*/
}

beat_me() {
  int i,so;
  while(remove_call_out("beat_me") != -1) ;
  for(i=0,so=sizeof(beat); i<so; i++) {
    if(find_object(beat[i])) find_object(beat[i])->hb();
  }
  remove_call_out("beat_me");
  call_out("beat_me",3);
  return 1;
}

beats() {
  int i,so;
  for(i=0,so=sizeof(beat); i<so; i++) {
      write(i+": "+beat[i]+"\n");
  }
  return 1;
}

set_beat(object ob) {
  int x;
  string obs;
  sscanf(ob,"%s",obs);
  if((x = member_array(obs, beat)) == -1) {
    beat += ({ obs });
  }
  /* 03/20/06 Earwax: this is where hb should start */
  call_out("beat_me", 3);
  return x;
}
