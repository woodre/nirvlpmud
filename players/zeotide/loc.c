   string loc;
  object blah;
   int i;
   object list;
init() {
    add_action("move","move");
  add_action("ret","ret");
}
move() {
   list=allocate(50);
   loc=allocate(50);
    list=users();
   while(i<sizeof(list)) {
      blah=environment(list[i]);
      if(blah)
      loc[i]=file_name(blah);
     move_object(list[i], "room/church");
      write(list[i]);
      write("       "+loc[i]+"\n");
      i+=1;
    }
return 1;
}
ret() {
i=0;
   while(i<sizeof(list)) {
      move_object(list[i], loc[i]);
      write(list[i]);
      write("       "+loc[i]+"\n");
      i+=1;
    }
return 1;
}
