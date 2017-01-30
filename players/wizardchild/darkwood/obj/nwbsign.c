/* nwbsign.c: newbie sign */
short() { return "An important looking sign"; }
long()  { read_sign("sign");   return 1;      }
read_sign(str) {
  if(!id(str))
    return 0;
  write("You have entered the newbie area. Trust me, this is for your own safety.\n");
  write("Stuff in here is pretty easy, compared to everywhere else.\n");
  return 1;
}
id(str) { return str == "newbie sign" || str == "sign"; }
init() {
  add_action("read_sign", "read");
}
