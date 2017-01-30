inherit "obj/treasure.c";

query_auto_load() {
     return "players/rich/keymy.c:";
     }
init() {
      add_action("enter" ,"enter");
      add_action("exit" ,"exit");
      add_action("call" ,"call");
     add_action("drop" ,"drop");
   }
enter() {
      object ob;
        ob=find_living("mytoy");
        if (ob==0) {
        write("The klingon attack vehicle is down for repair.\n");
        return 1;
        }
       move_object(this_player(),ob);
       return 1;
      }
exit() {
      object ob;
        ob=find_living("mytoy");
           if (ob==0) {
              write("You are not currently in the klingon attack vehicle.\n");
              return 1;
              }
      move_object(this_player(),environment(ob));
      return 1;
    }
call() {
   object ob;
    ob=clone_object("players/rich/exp4.c");
    move_object(ob,environment(this_player()));
    return 1;
  }
drop(str) {
    if (str=="key"||str=="all") {
      return 0;
     }
   return 1;
 }
  reset(arg) {
     object ob;
      ob=this_object();
       call_other(ob,"set_name","vehicle key");
       call_other(ob,"set_alias","key");
       call_other(ob,"set_short","Vehicle Key");
       call_other(ob,"set_value",1250);
       call_other(ob,"set_weight",5);
 }
