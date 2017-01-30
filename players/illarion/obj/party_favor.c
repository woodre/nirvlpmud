#include "/players/illarion/dfns.h"
#define PATH "/players/illarion/obj/favor_base.c"
inherit obj/treasure;

string color,ccode;
string *mess;

void reset(int arg) {
  if(arg) return;

  set_id("favor");
  set_value(0);
  set_weight(1);
}
short() {
  if(!alias_name) return "A generic party favor";
  switch(alias_name) {
    case "rose": return "A large "+ccode+color+" rose";
    default: return "A generic party favor";
  }
}
long() {
  if(!alias_name) {
    write("A party favor.  Use "+BLD("favor_info")+" for information.\n");
    return;
  }
  else {
    int n,size;
    string *pic_array;
    pic_array=(mixed)call_other(PATH,alias_name+"_array",ccode);
    size=sizeof(pic_array);
    for(n=0;n<size;n++) {
      write(pic_array[n]+"\n");
    }
  }
}
void init() {
  add_action("cmd_info","favor_info");
  add_action("cmd_color","change_color");
  add_action("cmd_message","set_message");
  add_action("cmd_change","change_shape");
}
int cmd_info() {
  write("You have found an extremely versitile party favor.  It can become\n"+
       "one of several popular party items, in whichever color you choose.\n"+
       "You may also set a message that will appear to whoever looks at it.\n");
  write(BLD(change_color)+" <color>   - set the color.\n");
  write(BLD(change_shape)+" <shape>   - set the shape.\n");
  write(BLD(set_message)+"        - set a message (you'll be prompted).\n");
  return 1;
}
