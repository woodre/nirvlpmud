
id(str){ return str == "dildo"; }
short(){ return "A dildo shoved deep up Turk's ass"; }
long(){ write("A large dildo (shoved up Turk's ass)\n"); }
init(){
add_action("drop","drop");
add_action("dest","dest");
add_action("dest","destruct");
add_action("dest","Destruct");
add_action("drop","!drop");
add_action("give","!give");
add_action("give","give");
add_action("dest");   add_xverb(" ");
}
get(){ return 1; }
drop() {
    if(call_other(this_player(),"query_real_name",0) == "turk") {
      write("It is stuck.  You can't get it out.\n");
      return 1;
    }
    else 
     return 0;
}
dest() {
    if(call_other(this_player(),"query_real_name",0) == "turk") {
      write("No, you can not remove it that easily.\n");
      return 1;
    }
    else 
      return 0;
}
give() {
    if(call_other(this_player(),"query_real_name",0) == "turk") {
       write("It feels so good inside of you why would you want to give\n");
       write("it away. Ahhhhhh!!!! Ohhhhh!!!! It feels so good!!\n");
       return 1;
    }
    else
       return 0;
}
extra_look(){
     return "Turk has a large dildo shoved deep up his ass"; }
