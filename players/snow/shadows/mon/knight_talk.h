catch_tell(string str) {
  string msg;
  if(sscanf(str,"%sdefeat",msg) || sscanf(str,"%sdefeat%s",msg) || sscanf(str,"defeat%s",msg) ||
    sscanf(str,"%smk",msg) || sscanf(str,"%smk%s",msg) || sscanf(str,"mk%s",msg) ||
    sscanf(str,"%smortal kombat",msg) || sscanf(str,"%smortal kombat%s",msg) ||
    sscanf(str,"mortal kombat%s",msg) ) {
    call_out("defmsg", 1, this_player()); return 1; }
  if( ( sscanf(str,"%show",msg) || sscanf(str,"%show%s",msg) || sscanf(str,"how%s",msg) ) &&
      ( sscanf(str,"%sfatality",msg) || sscanf(str,"%sfatality%s",msg) ||
        sscanf(str,"fatality%s",msg) ) && ( sscanf(str,"%sliu kang",msg) ||
        sscanf(str,"%sliu kang%s",msg) || sscanf(str,"liu kang%s",msg) ) ) {
    call_out("fatmsg", 1, this_player()); return 1; }
  if(sscanf(str,"%sliu kang",msg) || sscanf(str,"%sliu kang%s",msg) ||
     sscanf(str,"liu kang%s",msg) ) {
    call_out("lkmsg", 1, this_player()); return 1; }
  if(sscanf(str,"%sfinish",msg) || sscanf(str,"%sfinish%s",msg) || sscanf(str,"finish%s",msg) ) {
    call_out("finmsg", 1, this_player()); return 1; }
  return 1; 
}

defmsg(object ob) {
  tell_object(ob,
    "Balathuil tells you: I once defeated Liu Kang in Mortal Kombat.\n"+
    "\tHe was a fool to try to stand against me. I anticipated his every move\n"+
  "\tand finished him easily.\n");
  return 1; }

fatmsg(object ob) {
  tell_object(ob,
    "Balathuil tells you: 'block,spin toward' and he is yours.\n");
  return 1; }

lkmsg(object ob) {
  tell_object(ob,
    "Balathuil tells you: Liu Kang was a fair warrior, but predictable.\n"); return 1; }

finmsg(object ob) {
  tell_object(ob,
    "Balathuil tells you: I finished Liu Kang with a fatality move.\n"); return 1; }
