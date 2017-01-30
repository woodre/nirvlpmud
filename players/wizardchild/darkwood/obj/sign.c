/* sign.c: entry way sign */
#define HOME "/players/wizardchild/darkwood/rooms/entry"
short() { return "A warning sign";     }
long()  { read_sign("sign"); return 1; }
 
id(str) { return str == "sign" || str == "warning sign"; }
init()  {
  add_action("read_sign", "read");
  if(!find_object(HOME))
    HOME->blah();
  if(environment(this_object()) != find_object(HOME)) {
    if(!present("sign", find_object(HOME)))
      move_object(this_object(), HOME);
    else
      destruct(this_object());
  }
}
read_sign(str) {
  if(!id(str))
    return 0;
  write("The sign contains the following message:\n\n");
  write("Be warned that this realms' heavy overgrowth prevents leaving by abnormal means.\n");
  write("This area has not been completely explored, and many creatures in here are not\n");
  write("freindly, especially to young children. Many creatures in here contain abnormal\n");
  write("strength, and the dim light tends to prevent accurate perception.\n");
  write("Buying a darkwood torch will help (somewhat) with your vision.\n");
  return 1;
}
