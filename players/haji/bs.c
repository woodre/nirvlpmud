change(str) {
   string me,title;
     object ob;
      sscanf(str, "%s %s",me,title);
        ob=find_player(me);
           if(ob==0) {
             write("Nothing by that name is currently functioning.\n");
             return 1;
             }
          call_other(ob,"set_title",title);
          write("Title changed.\n");
          return 1;
          }
