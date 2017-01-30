#include "/players/blue/closed/lib/color.h"
#include "/players/blue/closed/lib/basic.h"
#define THIS_FILE "players/blue/closed/obj/towel.c"

string text_color, back_color;
object owner;

id(str) { return str == "towel"||str == "towel-obj"; }
short() { return "An ACME towel"; }
long() { 
   if(owner&&owner->query_name())
      write(CN+"'s towel.\n");
   else write("A towel.\n");
}

get() { return 0; }
drop() { return 1; }
value() { return 0; }

reset(arg) {
   
   if(arg) return;
 
   text_color = 0;
   back_color = 0;

}
   
 /*
query_auto_load() {
   return "/players/blue/closed/obj/towel.c:"+"#"+text_color+"#"+
}

init_arg(str) {
   sscanf(str,"#%s#%s#%d", text_color, ownername, coloron);
} 
 */

init() {
 
   add_action("fix_color","colfix");
   add_action("set_text","coltext");
   add_action("set_back","colback");
 
}

static fix_color() {
   if(text_color) write(text_color);
   if(back_color) write(back_color);
   return 1;
}


static set_text(str) {
   string tmp;
   if(str) {
      tmp = valid_color(str);
      if(tmp) {
         text_color = tmp;
         write(text_color);
          write("\nNew text color set.\n");
         return 1;
      } else {
         write("That is not a valid color.\n");
         write("Type 'coltext' to see a list of choices.\n");
         return 1;
      }
   }
   list_colors();
   input_to("do_set_text");
   return 1;
}


static set_back(str) {
   string tmp;
   if(str) {
      tmp = valid_back(str);
      if(tmp) {
         back_color = tmp; 
         write(back_color);
         write("New background color set.\n");
         return 1;
      } else {
         write("That is not a valid color.\n");
         write("Type 'colback' to see a list of choices.\n");
         return 1;
      }
   }
   list_backs();
   input_to("do_set_back");
   return 1;
}

static do_set_text(str) {
   string tmp;
   if(!str||str == "x") return 1;
   tmp = valid_color(str);
   if(!tmp) {
      write("That is not a choice.\n");
      return 1;
   }
   text_color = tmp;
   write("\nNew text color set.\n");
   write(NOSTYLE);
   write(text_color);
   return 1;
}

static do_set_back(str) {
   string tmp;
   if(!str||str == "x") return 1;
   tmp = valid_back(str);
   if(!tmp) {
      write("That is not a choice.\n");
      return 1;
   }
   back_color = tmp;
   write("New background color set.\n");
   write(back_color);
   return 1;
}

list_colors() {
   write("Color choices are...\n");
    write(PUR+"purple\t"+BOLD+"PURPLE\n"+NOSTYLE);
   write(BLU+"blue\t\t"+BOLD+"BLUE\n"+NOSTYLE);
   write(RED+"red\t\t"+BOLD+"RED\n"+NOSTYLE);
   write(YEL+"yellow\t\t"+BOLD+"YELLOW\n"+NOSTYLE);
   write(BLA+"black\t\t"+BOLD+"BLACK\n"+NOSTYLE);
   write(WHI+"white\t\t"+BOLD+WHI+"WHITE\n"+NOSTYLE);
   write(CYA+"cyan\t\t"+BOLD+"CYAN\n"+NOSTYLE);
   write(GRE+"green\t\t"+BOLD+"GREEN\n"+NOSTYLE);
   write("What is your choice?");
   write(BACK_BLA);
   return 1;
}

valid_color(str) {
   string tmp;
   tmp = check_color(str);
   if(!tmp) return 0;
   return tmp;
}

list_backs() {
   if(text_color) write(text_color);
      else write(NOSTYLE + WHI);
   write(BACK_RED + "\nred\n");
   write(BACK_BLU + "\nblue\n");
   write(BACK_GRE + "\ngreen\n");
   write(BACK_PUR + "\npurple\n");
   write(BACK_CYA +"\ncyan\n");
   write(BACK_BLA + "\nblack\n");
   write(BLA+BACK_WHI +"\nwhite\n");
   write(BACK_BLA);
   if(text_color) write(text_color);
      else write(NOSTYLE+WHI);
   write("What is your choice?\n");
   return 1;
}

valid_back(str) {
   string tmp;
   tmp = check_back(str);
   if(!tmp) return 0;
   return tmp;
}
