inherit "/players/wocket/graveyard/groom.c";
int alt_path;

reset(arg){
  ::reset();
  short_desc = "A cave";
  long_desc = get_random_long();
  dest_dir = ({
  "open/wocket/cavetest/mainpath3.c","north",
  "open/wocket/cavetest/mainpath1.c","southwest",
  });
  if(!alt_path){
    alt_path = random(2)+1;
    "/open/wocket/cavetest/mainpath4.c"->set_alt_path(alt_path);
  }
  get_alt_path(alt_path);
  set_light(1);
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

get_alt_path(i){
  switch(i){
  case 1: dest_dir += ({ "/open/wocket/cavetest/apath1.c", "east" });
          break;
  case 2: dest_dir += ({ "/open/wocket/cavetest/bpath1.c","east" });
          break;
  }
}

set_alt_path(i){
  alt_path = i;
  get_alt_path(alt_path);
}
