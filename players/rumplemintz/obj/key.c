inherit "obj/treasure";

private string type, code;

string
short() {
  return treasure::short() || (type ? type+" " : "")+"key";
}

varargs string
long(string str) {
  return treasure::long(str) ||
         "This is "+(type ? type+" key" : "a key")+
         ", wonder where it fits?\n";
}

status
id(string str) {
  return (type && str==type+" key") || str=="key" || treasure::id(str);
}

void
reset(status arg) {
  if(arg)
    return;
  treasure::reset(arg);
  set_name("key");
  set_short(0);
  set_long(0);
  set_value(10);
}

int
set_key_data(string str) {
  if (sscanf(str,"%s %s",type,code)==2)
    return 1;
  return 2;
}

string
query_name() {
   string res;
   res = (string)treasure::query_name();
   if (res == "key" && type)
      return type + " key";
   return res;
}

string query_type() { return type; }
string query_code() { return code; }
void set_type(string str) { type = str; }
void set_code(string str) { code = str; }
