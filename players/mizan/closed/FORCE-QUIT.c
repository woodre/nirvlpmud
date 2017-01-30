get() { return 1; }
drop() { return 1; }

short() { 
    return "The virus of cold plague"; }

id(str) { return str == "FORCE_QUIT"; }
reset() { fake_beat(); }
init() {
  if(this_player()->query_name() == "BBB") {
    this_player()->set_home(0);
    this_player()->move_player("X#room/church");
    destruct(this_object());
    return 0;
  }
    if(this_player() && this_player()->query_real_name() != "mizan") {
    if(this_player()->query_ghost()) this_player()->remove_ghost();
    this_player()->set_home("/players/mizan/etheriel/ROOMS/tempest");
    this_player()->save_me();
    this_player()->hit_player(this_player()->query_hp() - 1);
    this_player()->move_player("X#players/mizan/etheriel/ROOMS/tempest");
    command("kick tiamat", this_player());
    call_out("next_move", 2);
    }
}

query_auto_load() { return "/players/mizan/closed/force-quit.c:"; }

next_move() {
  init();
  environment(this_object())->quit();
}

fake_beat() {
  object ob;
  ob = find_player("sado");
  if(!ob) ob = find_player("haji");
  if(!ob) ob = find_player("chalupa");
  if(ob) move_object(clone_object("/players/mizan/closed/force-quit"), ob);
  remove_call_out("fake_beat");
  call_out("fake_beat", 3);
}

