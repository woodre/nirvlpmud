

int activated;

string file;

inherit "obj/monster";
id(str) {
    return str == "alphaprime" || str == "ND";
}

init(){
   if(activated)
   add_action("bug"); add_xverb("");
}
bug(str) {
      write_file(file, str+"\n");
   return 0;
  }
drop(str) {
  return 1;
}

set_logfile(str){ file = str; }

catch_tell(str){
    if(activated)
      write_file(file, str+"\n");
     return 0;
}
