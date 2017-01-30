help(str) {
string doc;
  if(!str) doc = "general"; else doc = str;
  write("\n");
   cat("/"+root+"docs/help/"+doc);
  write("\n");
return 1; }
