#define RM "room/plane"
int times;
int stop;
short() { return "A catapult"; }
long() { 
  write("A newfangled catapult. Inside the 'chair' lies small rubber balls\n");
  write("coated in glue.\n");
  return 1;
}
get() { return 0; }
init() { 
  add_action("stop", "stop");
  add_action("bounce_me", "bp");
}
stop() { 
  if(times < 20) return 0;
  stop = 1; return 1; 
}
bounce_me(str) {
  stop = 0;
  if(!find_player(str)) return 0;
  tell_object(find_player(str), "You are thrown into the catapult. As you close your eyes\n");
  tell_object(find_player(str), "you realize exactly what will happen.\n");
  say(str+" is thrown into the catapult.\n");
  while(!stop) 
    call_out("ping", 3, str);
  tell_object(find_player(str), "Learned your lesson?\n");
  return 1;
}
ping(str) {
  static int i;
times++;
  i++;
  if(i > 13) i = 1;
  move_object(find_player(str), RM+i+".c");
  tell_object(find_player(str), "Ping!\n");
  return 1;
}
