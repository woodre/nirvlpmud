

#include "/room/clean.c"
#include "rm-alias.h"

/* Some arrays for handling destination directions */
string *dest_cmd, *dest_dir;

/* Items and their descriptions */
string *items, *item_desc;

/* Short description of the room */
string short_desc;

/* Long description of the room */
string long_desc;

/* 
 * If you want an init_function to occur when someone enters room 
 * Set init_ob to this_object().  Similiar to monster init_ob 
 */
object init_ob;

init() {
   int i;
   if(!dest_cmd)
     return;
   i = 0;
   add_action("listen","listen");
   add_action("search","search");
   while(i < sizeof(dest_cmd)) {
     add_action("move", dest_cmd[i]);
     i += 1;
   }
   if(init_ob)
     call_out("init_function",2); /* have some delay */
   set_up_alias();
}

id(str) {
   int i;
   if(!items)
     return;
   i = 0;
   while(i < sizeof(items)) {
     if(str == items[i])
       return 1;
     i += 1;
   }
   return 0;
}

long(str) {
   int i;

   if(set_light(0) == 0) {
     write("It is too dark.\n");
     return 1;
   }
   if(!str) {
     write(long_desc);
     if(!dest_cmd)
       write("     There are no obvious exits.\n");
     else {
       if(sizeof(dest_cmd) == 1) 
         write("     There is one obvious exit:");
       else
         write("     There are "+convert_number(sizeof(dest_cmd))+
               " obvious exits:");
       i = 0;
       while(i < sizeof(dest_cmd)) {
         write(" "+dest_cmd[i]);
         if(i == (sizeof(dest_cmd)-2))
           write(" and");
         else if(i < sizeof(dest_cmd)-1)
           write(",");
       i += 1;
       }
       write("\n");
     }
     return;
   }
   if(!items)
     return;
   i = 0;
   while(i < sizeof(items)) {
     if(str == items[i]) {
       write(item_desc[i]+"\n");
       return;
     }
     i += 1;
   }
}

search(str) {
   if(!str)
     return;
   this_player()->look("at "+str);
   return 1;
}

move(str) {
  int i;

  i = 0;
  while(i < sizeof(dest_dir)) {
    if(query_verb() == dest_cmd[i]) {
      this_player()->move_player(dest_cmd[i]+"#"+dest_dir[i]);
      return 1;
    }
    i += 1;
  }
}


short() {
   if(set_light(0))
     return short_desc;
   return "Dark room";
}

query_long() { return long_desc; }

/* 
 * Converts numbers to words
 */

string numbers;

convert_number(n) {
   numbers = ({ "no", "one", "two", "three", "four", "five", "six",
                "seven", "eight", "nine", "ten" });
   if(n > 10)
     return "a lot of";
   return numbers[n];
}

query_drop_castle() { return 1; }

set_init_ob(o) { init_ob = o; }

add_item(string what, string info) {
   if(!what || !info)
     return 1;
   if(!items) { items = ({ }); item_desc = ({ }); }
   items += ({ what });
   item_desc += ({ info });
}

add_exit(string what, string where) {
   if(!what || !where)
     return 1;
   if(!dest_cmd) { dest_cmd = ({ }); dest_dir = ({ }); }
   dest_cmd += ({ what });
   dest_dir += ({ where });
}

set_short(s) { short_desc = s; long_desc = s+"\n"; }

set_long(l) { long_desc = l; }

#include "rm-listen.h"

