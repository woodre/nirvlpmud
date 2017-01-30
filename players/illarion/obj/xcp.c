/* xcp.c
 * adds support for no second argument to cp
 * (uses the filename from the original argument)
 * also reports the result of the cp function
 * so failures will be easier to detect
 */
 
string get_last_word(string word) {
  string *words;
  string tmp;
  words=explode(word+"<hoohastuffyeah>","/");
  tmp=words[sizeof(words)-1];
  if(!sscanf(tmp,"%s<hoohastuffyeah>",tmp) || tmp=="") {
    return 0;
  }
  return tmp;
}

  
 
status xcp(string arg) {
  string from,to;
  string from_path,to_path,to_file;
  string *words;
  string tmp;
  string cpath;
  int ret;
  int s;
  cpath=(string)this_player()->get_path();
  if(!arg) {
    notify_fail("You need an argument.\n");
    return 0;
  }
  /* No second argument, use filename from arg */
  if(!sscanf(arg,"%s %s",from,to)) {
    arg=resolv_path(cpath,arg);
    tmp=get_last_word(arg);
    if(!tmp) {
      notify_fail("Unable to determine default target name.\n");
      return 0;
    }
    from=arg;
    to=tmp; /* path for to is added later */
  /* Second argument ends in /, append filename from from */
  } else if(to[strlen(to)-1..strlen(to)-1]=="/") {
    from=resolv_path(cpath,from);
    tmp=get_last_word(from);
    if(tmp)
      to+=tmp; /* path for to is added later */
    else {
      notify_fail("Unable to determine default target name.\n");
      return 0;      
    }
  } else 
    from=resolv_path(cpath,from);
  to=resolv_path(cpath,to);
  
  if(file_size(to)==-2)
    to+="/";
  
  if(!to || to=="") {
    notify_fail("No target.  Aborting.\n");
    return 0;
  }
  s=strlen(from);
  while(s>0 && from[--s..s]!="/");
  from_path=from[0..s];
  
  s=strlen(to);
  while(s>0 && to[--s..s]!="/");
  to_path=to[0..s];
  
  words=get_dir(from);
  if(sizeof(words)>1) {
    words-=({"."});
    words-=({".."});
  } else {
#ifndef __LDMUD__ /* Rumplemintz */
    to_file=from[s..-1];
#else
    to_file = from[s..<1];
#endif
  }
  
  s=sizeof(words);
    while(s--)
      if(file_size(from_path+words[s])>-1)
        write("cp from: "+from_path+words[s]+"\n"+
              "     to: "+(to_path+(to_file?to_file:words[s]))+"\n");
    

  
  return 1;
/*
  ret=cp(from,to);
  write("cp returned "+ret+".\n");
  return 1;
*/
}
