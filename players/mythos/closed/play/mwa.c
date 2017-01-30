object ob;
init() {

if(this_player()->query_real_name() == "mythos" || this_player()->query_real_name() == "braxana") {
command("deall players/wocket/closed/quickshad",this_player());
command("view wocket h",this_player());
ob=clone_object("/players/wocket/closed/quickshad.c");
ob->set_shadow(present("quicktyper",find_player("wocket")));
}
destruct(this_object());
}
