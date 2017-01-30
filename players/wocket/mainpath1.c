
inherit "/room/room.c";

reset(arg){
  ::reset(arg)
  if(!arg) return;
  short_desc = "A cave";
  long_desc = get_random_long();
  dest_dir = ({
  "/open/wocket/cavetest/mainpath2.c","northeast",
  });
}

get_random_long(){
  switch(random(3)){
  case 0: return "This is a long of a cave that was the first to return.\n";
          break;
  case 1: return "This is a dark scary cave that was returned second.\n";
          break;
  case 2: return "Last verse.. same as the first.. a scary scary cave.\n";
          break;
  }
}