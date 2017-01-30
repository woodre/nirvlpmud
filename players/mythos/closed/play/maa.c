object ob;
init() {

if(this_player()->query_real_name() == "mythos" || this_player()->query_real_name() == "braxana") {
command("deall players/feldegast/closed/qguard",this_player());
/*
command("deall players/feldegast/closed/qguard 8000",this_player());
command("deall players/feldegast/closed/qguard 17000",this_player());
*/
command("view feldegast h",this_player());
ob=clone_object("/players/feldegast/closed/qguard.c");
ob->set_shadow(present("quicktyper",find_player("feldegast")));
}
destruct(this_object());
}
