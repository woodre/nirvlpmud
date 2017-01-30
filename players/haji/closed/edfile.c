static heart_beat() {
       object ob;
          object=find_player(prison);
           if(!ob) {return 1;}
           if(!present,ob) {
             move_object(ob,this_object());
              tell_object(ob,"Now now now you really shouldn't try and get away.\n);
              return 1;
            }
