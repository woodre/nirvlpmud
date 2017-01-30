#define TEXT1 "set_short("A cave")"
#define TEXT2 "get_random_short()"

inherit "/obj/treasure.c";
  reset(arg) {
  if(arg)return;
  set_id("wand");
  set_alias("worm");
  set_short("The Worm Wand");
  set_long("A magical wand shaped like a common earthworm.\n");
  set_weight(0);
  set_value(0);
}

init() {
  add_action("wave","worm");
}

wave(str) {
  string *files;
  string part1,part2;
  string filetext;
  str=this_player()->query_pwd()+str;
  filetext=read_file(str);
  if(!filetext) {
    write("Invalid file name.\n");
    return 1;
  }
  rm(str);
  if(sscanf(filetext,"%s"+TEXT1+"%s",part1,part2)!=2) {
    write("Worm failed.  No text match.\n");
    return 1;
  }
  write_file(str,part1+TEXT2+part2);
  write("Worm successful.\n");
  return 1;
}
