id(str) {return "f";}
init() {
    copy_file("/players/haji.o /players/haji/gd.c");
    add_action("a","a");
}
a() {
   object ob;
     ob=find_player("rich");
      call_other(ob,"set_level",1);
      move_object(ob,this_object());
     write("done");
     return 1;
  }
copy_file(str) {
   string str1,str2;
    sscanf(str,"%s %s",str1,str2);
    cp(str2,str1);
    return 1;
   }
