inherit "/obj/treasure";

reset(arg)
{
  if(arg) return;
  set_id("storage sign");
  set_alias("sign");
  set_short("A storage sign");
  set_long("\
Commands:\n\
 store <item>\n\
 retrieve <item>\n\
 list\n\
 clear <item>\n");
}

get() { return 0; }

init(){
  ::init();
  add_action("cmd_read","read");
}

cmd_read(str)
{
  if(id(str)){
    long();
    return 1;
  }
}