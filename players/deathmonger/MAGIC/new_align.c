
#include <ansi.h>

id(str) { return str=="test"; }

short() { return "A test device"; }

long(str) {
     write("A little thingy.\n");
     return 1;
}

init() {
     add_action("set_al_title", "alt");
     add_action("set_my_title", "tit");
}

get() { return 1; }

set_al_title(arg) {
     int num, num2, num3;
     string title;
     if(!arg) return;
     if(sscanf(arg, "%d %d %d %s", num, num2, num3, title)==4)
          num=num;
     else if(sscanf(arg, "%d %d %s", num, num2, title)==3) 
          num=num;
     else if(sscanf(arg, "%d %s", num, title)!=2) {
          write("Alt <num> <title>.\n");
          return 1;
     }
     if(num3)
          command("setal "+esc+"[0m"+esc+"["+num+"m"+esc+"["+num2+"m"+
             esc+"["+num3+"m"+title+esc+"[0m", this_player());
     else if(num2)
          command("setal "+esc+"[0m"+esc+"["+num+"m"+esc+"["+num2+"m"+
             title+esc+"[0m", this_player());
     else
          command("setal "+esc+"[0m"+esc+"["+num+"m"+title+esc+"[0m",
             this_player());
     write(this_player()->short()+"\n");
     write("Ok.\n");
     return 1;
}

set_my_title(arg) {
     int num, num2, num3;
     string title;
     if(!arg) return;
     if(sscanf(arg, "%d %d %d %s", num, num2, num3, title)==4)
          num=num;
     else if(sscanf(arg, "%d %d %s", num, num2, title)==3) 
          num=num;
     else if(sscanf(arg, "%d %s", num, title)!=2) {
          write("Tit <num> <title>.\n");
          return 1;
     }
     if(num3)
          command("title "+esc+"[0m"+esc+"["+num+"m"+esc+"["+num2+"m"+
             esc+"["+num3+"m"+title+esc+"[0m", this_player());
     else if(num2)
          command("title "+esc+"[0m"+esc+"["+num+"m"+esc+"["+num2+"m"+
             title+esc+"[0m", this_player());
     else
          command("title "+esc+"[0m"+esc+"["+num+"m"+title+esc+"[0m",
             this_player());
     write(this_player()->short()+"\n");
     write("Ok.\n");
     return 1;
}
