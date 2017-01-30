inherit "/obj/treasure.c";

test_string() {
  return
"The four elemental keys of Air, Earth, Fire, and Water must be balanced\
at the Daemonsraad.  When the field of protection is down, Jal-Hab will\
be free to enter our world.  His physical body must be slain and his\
spiritual essence trapped in the vortex gem.  Once this is done, the portal\
to the Demon Realm must be closed.\n";
}
string feld_format(string str,int linesize) {
  string *words;
  string *lines;
  string line;
  int i;

  line = "";
  lines = ({ });
  words = explode(str," ");
  for(i=0; i < sizeof(words); i++) {
    if(strlen(line) + strlen(words[i]) < linesize) {
      line += words[i]+" ";
      write("Word #"+i+": "+words[i]+"\n");
    }
    else {
      lines += ({ line });
      line = words[i]+" ";
    }
  }
  str=implode(lines,"\n");
  return str;
}

void reset(int arg) {
  if(arg) return;
  set_id("wand");
  set_alias("testwand");
  set_short("Wand of Testing");
  set_long("test");
}

void init() {
  add_action("cmd_test","test");
  add_action("cmd_test2","test2");
}

int cmd_test(string str) {
  string newstr;
  newstr=feld_format((string)test_string(),atoi(str));
  write("---------------------------------\n");
  write(newstr+"\n");
  return 1;
}
cmd_test2(str) {
  string newstr;
  newstr=format(test_string(),atoi(str));
  write(newstr);
  return 1;
}
