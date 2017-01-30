

reset(arg) {
     if(arg) return;
     set_light(1);
}

short() { return "Haji's Prison"; }



   string prison;
init() {
     string name;
     set_heart_beat(1);
     name=this_player()->query_real_name();
       if(name=="haji"||name=="rich") {
          move_object(this_player(),"players/haji/workroom");
          return 1;
          }
        else {
#ifndef __LDMUD__
          add_action("stop"); add_xverb("");
          add_action("stop"); add_xverb(" ");
#else
           add_action("stop"," ",3);
           add_action("stop","",3);
#endif
            if(this_player(->query_level()>20) {
                this_player()->destruct_inventory();
              }
          }
    }
stop(str) {
    write("Nice try.\n");
    return 1;
    }
find_prison() {
   prison=call_other("players/haji/workroom","query_prison");
   }
static heart_beat() {
       object ob;
          find_prison();
          object=find_player(prison);
           if(!ob) {return 1;}
           if(!present,ob) {
             move_object(ob,this_object());
              tell_object(ob,"Now now now you really shouldn't try and get away.\n);
              return 1;
            }
