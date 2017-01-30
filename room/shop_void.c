short() {
    return "The void";
}

long() {
    write(short() + ".\n");
    write("You come to the void if you fall out of a room, and have nowhere to go.\n");
    write("Give the command 'church', and you will come back to village church.\n");
}

init() {
    add_action("church", "church");
}

church() {
    call_other(this_player(), "move_player", "away#room/church");
    return 1;
}

reset(arg)
{
    if (arg)
  return;
    set_light(1);
    stop_overflow();
}

id(str) { return str == "void"; }
stop_overflow(){
     object list_no;
  int t,k;
   list_no = allocate(700);
  list_no = all_inventory(this_object());
  k = sizeof(list_no);
   t=0;
   while(t < k){
   if(!call_other(list_no[t],"query_interactive",0))
      destruct(list_no[t]);
      t += 1;
   }
   return;
}