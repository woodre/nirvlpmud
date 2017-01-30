string *beat;
reset(arg) {
  if(arg) return ;
  beat = ({ });
  call_out("beat_me",3);
}
beat_me() {
  int i,so;
  while(remove_call_out("beat_me") != -1) ;
  for(i=0,so=sizeof(beat); i<so; i++) {
    if(find_object(beat[i]))
      find_object(beat[i])->hb();
  }
  call_out("beat_me",3);
}
beats() {
  int i,so;
  for(i=0,so=sizeof(beat); i<so; i++) {
/*    if(find_object(beat[i])) */
      write(i+": "+beat[i]+"\n");
  }
  return 1;
}
set_beat(str) {
  int x;
  if((x = member_array(str, beat)) == -1)
    beat += ({ str });
  return x;
}
