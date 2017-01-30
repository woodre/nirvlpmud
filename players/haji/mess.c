id(str) {return "message";}
   object ob,ob1;
init() {
  if(this_player()->query_real_name()!="carol") {
      return 0;
    }
  if (this_player()->query_real_name()=="carol") {
    write("Haji flies in and lands beside you and gives you a rose.\n");
    write("He then bows before you and kisses you goodnight and \n");
    write("flies off the mud.\n");
    log_file("haji.mess",this_player()->query_real_name());
    log_file("haji.mess"," received message.\n");
    ob=this_player();
    ob1=clone_object("players/haji/rose1");
    move_object(ob1,ob);
    destruct(this_object());
    return 1;
    }
 }
