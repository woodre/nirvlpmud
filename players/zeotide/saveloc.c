   string loc;
   object list;
init() {
    add_action("move","move");
  add_action("ret","ret");
}
move() {
   list=allocate(50);
   loc=allocate(50);
    list=users();
   while(i<length_of(list)+1) {
     loc[i]=filename(environment(list[i])));
     move_object(list[i], "room/church");
      write(list[i]);
      write("       "+loc[i]+"\n");
      i+=1;
    }
return 1;
}
ret() {
   while(i<length_of(list)+1) {
      move_object(list[i], loc[i]);
      write(list[i]);
      write("       "+loc[i]+"\n");
      i+=1;
    }
return 1;
}
