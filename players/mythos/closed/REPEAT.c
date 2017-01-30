
/* Something to give people a little history...   */

int count, check_flag;
string  check_string;
object ENV;

id(str)  {  return str == "repeat";  }

long()  { return "A repeater.\nA repeater.\n";  }

short() { return 0; }

freeze()  {
  count = time();
        }

init() {
#ifndef __LDMUD__
add_action("iced"); add_xverb("");
#else
add_action("iced", "", 3);
#endif
}

init_arg(str)  {  sscanf(str, "%d", count);  }

iced(str)  {
  if(check_flag < 1)  {
      check_flag = 2;
      check_string = str;
      call_out("repeat",random(45));
        }
        }

repeat()  {
  ENV = environment(this_object());
  command(check_string, ENV);
  check_flag = 0;
  return 1;
        }

drop()  { return 1; }
get()   { return 1;  }
