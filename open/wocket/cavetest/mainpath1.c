inherit "/players/wocket/graveyard/groom.c";


reset(arg){
  ::reset();
  short_desc = "A cave";
  get_random_long();
  dest_dir = ({
  "open/wocket/cavetest/mainpath2.c","northeast",
  });
  set_light(1);
}

get_random_long(){
  switch(random(3)){
  case 0: long_desc = "This is a long of a cave that was the first to return.\n";
          break;
  case 1: long_desc = "This is a dark scary cave that was returned second.\n";
          break;
  case 2: long_desc = "Last verse.. same as the first.. a scary scary cave.\n";
          break;
  }
}