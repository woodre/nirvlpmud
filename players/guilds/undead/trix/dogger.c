reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="dogger") return 1;
        return 0;
}

long() {
        write( "This is a dogger\n");
}

short()
  { return "A dogger"; }
init()
{
  add_action( "doggy","doggy");
}

doggy()
{  object dog;
   dog=clone_object("/players/trix/closed/guild/ddog");
   call_other(dog, "set_master",this_player());
   move_object(dog,environment(this_player()));
   write("Ok!!!\n");
   return 1;
}

get() {
        return 1;
}
drop() {
        return 0;
}
