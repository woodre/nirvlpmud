reset(arg) {
        if(arg) return;
        /* Initialization code goes here */

}

long() {
           write("This is a virtual purses dispenser, type 'push button' to get one.\n");
           return 1;
        }

short() {
   return "A purses dispenser";
}

id(str) {
        if( str == "dispenser" ) return 1;
        return 0;
}

init() {
        add_action( "push", "push" );
        return 1;
}

query_weight()
{   return 50;
}

push(arg)
  { object ob;
    if(!arg||arg!="button") { write("Push what?\n"); return 1; }
    if(present("purse",this_player())) { write("You alread have a purse!!!\n"); return 1; }
    ob=clone_object("/players/trix/castle/obj/purse");
    move_object(ob,this_player());
    log_file("trix.di","Dispenser: "+call_other(this_player(),"query_name",)+".\n");
    write("You push the button and receive a brand new virtual purse.\n");
    return 1;
  }

get() {
        return 0;
}

drop() {
        return 1;
}
