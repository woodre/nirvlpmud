init() {
   object ob;
    string str;
     int i;
       str=allocate(10);
         i=0;
         while(i<11) {
         i+=1;
       str[i]=read_file("/log/haji");
       write(str[i]);
    }
    ob=find_object("players/haji/workroom");
    destruct(ob);
  return 1;
 }
