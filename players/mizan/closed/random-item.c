#define ODD_DM "/players/mizan/closed/Odd-ItemDM.c"
string long_desc;
string id_desc;
int value;

reset(arg) {
  string inpt;
  if(arg) return 0;
  inpt=call_other(ODD_DM, "return_info");
  if(sscanf(inpt, "%s#%s#%d", long_desc, id_desc, value) != 3) {
    destruct(this_object());
    return 1;
  }
}

id(str) { return str == id_desc; }

short() { return capitalize(long_desc); }

long() {
  write("This is " + long_desc + ".\n" +
        "You are not too sure what to do with it. It appears to be nearly useless.\n");
}

get() { return 1; }
query_weight() { return value; }
query_value() { return 100; }
query_save_flag() { return 1; }

