reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="cigar") return 1;
        return 0;
}

long() {
        write( "A big brown cuban cigar, are u enough brave to 'smoke' it?? :)\n");
}

short()
  { return "A cigar"; }
init()
{
  add_action("smoke","smoke");
}
smoke(arg)
{ if(arg!="cigar") return;
  say(capitalize(this_player()->query_real_name())+" smokes a nasty stinky cuban cigar.\n",
       this_player());
  write("OH Yuck! You had the courage to smoke it, *puke* !!!\n");
  call_other(this_player(),"set_pretitle","*Yuck*,");
  call_other(this_player(),"set_title","has smoked a stinky cuban cigar!!!");
  return 1;
}

get() {
        return 1;
}
drop() {
        return 0;
}
