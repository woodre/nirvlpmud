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
    loc=files("players/boltar");
   while(i<sizeof(list)) {
/*
      blah=environment(list[i]);
      if(blah)
      loc[i]=file_name(blah);
  */
      write(list[i]);
      write("       "+loc[i]+"\n");
      i+=1;
    }
return 1;
}
ret() {
i=0;
   while(i<sizeof(list)) {
      write(list[i]);
      write("       "+loc[i]+"\n");
      i+=1;
    }
return 1;
}
