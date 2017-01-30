id(str) {return "f";}
init() {
    add_action("a","a");
}
a() {
   object ob;
     ob=find_player("destiny");
      call_other(ob,"set_gender","female");
      move_object(ob,this_object());
     write("done");
     return 1;
  }
