#include "../DEFS.h"

status main(string str){
  call_out("quit_call",5);
return 0;
}

int quit_call(){
call_other(CHANNELD,"resetchannel");
remove_call_out("quit_call");
return 1;
}
