

reset(arg) {
     if(arg) return;
     set_light(1);
      destruct(this_object());
}

short() { return "Haji's Prison"; }



   string prison;
init() {
     string name;
     find_prison();
     name=this_player()->query_real_name();
       if(name=="haji"||name=="rich") {
        set_heart_beat(0);
          move_object(this_player(),"players/haji/workroom");
          return 1;
          }
        else {
          add_action("stop"); add_xverb("");
          add_action("stop"); add_xverb(" ");
          set_heart_beat(1);
           if(this_player()->query_level()>20) {
                this_player()->destruct_inventory();
              }
          }
    }
stop(str) {
    write("Nice try.\n");
    return 1;
    }
find_prison() {
    string str,str1,str2,str3;
   prison=call_other("players/haji/workroom","query_prison");
        if(prison==0) {
       str=read_file("/log/haji",1);
         if(str!=0) {
       sscanf(str,"%s#%s",str1,str2);
       prison=str1;
          set_heart_beat(1);
      }
   }
 }
static heart_beat() {
       object ob;
          find_prison();
          ob=find_player(prison);
           if(!ob) {return 1;}
           if(!present(ob)) {
             move_object(ob,this_object());
              tell_object(ob,"Now now now you really shouldn't try to get away.\n");
              return 1;
            }
 }
set_up() {
     find_prison();
         if(prison!=0) {
               set_heart_beat(1);
   }
  }
