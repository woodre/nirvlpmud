reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="semen") return 1;
        return 0;
}

long() {
        write( "Your personal semen.  preg <name> to make someone pregnant.\n");
}

short()
  { return "Semen"; }
init()
{
  add_action( "preg","preg");
}

get() {
        return 1;
}
drop() {
        return 0;
}
preg(arg)
{  object who;
   if(!arg) { write("Who do u want to make pregnant?\n"); return 1; }
   who=find_living(arg);
   if(!who) { write("Nobody with that name is currently on.\n"); return 1; }
   if(who->query_gender()!="female") { 
      write("You can't make "+arg+" pregnant. Not a female!\n");
      return 1; }
   who->set_pregnancy();
   return 1;
}
