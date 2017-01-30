main(str) { object ob;
object shad;
ob = find_player(str);
 if(present("babs", ob)) present("babs",ob)->set_release(1);
 return 1;
}
