static int gft;
gfiletest(arg,meob) {
object blah;
if(file_size(arg) < 1 && file_size(arg+".c") && file_size("/"+arg) < 1 && file_size("/"+arg+".c") < 1) {
   write(meob);
  meob->set_guild_file(0);
  return 0;
}
if(find_object(arg)) return 1;
if(!call_other(arg, "id", "GI")) {
  meob->set_guild_file(0);
  return 0;
}
blah=clone_object(arg);
if(blah) {
   destruct(blah);
   return 1;
}
if(!blah) {
  meob->set_guild_file(0);
  return 0;
}
return 0;
}
get_gft() { return gft; }
set_gft() {
gft = random(10000);
return gft;
}
