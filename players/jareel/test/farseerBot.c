#include "/players/mokri/ansi.h"

string *items;
int isNewbie;

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("farseer");
   set_alias("bot");
   set_short("A Farseer Bot");
   set_long("\nA small, hovering robot.\n" +
      "It can 'remember' items or mobs in a room.\n" +
      "You may 'checkitems' to see if the remembered items/mobs are present in their rooms.\n" +
      "The bot's memory can be cleared with 'clearbot'\n" +
      "This bot can remember up to 5 items.\n\n");
   set_weight(2);
   set_value(5000);
}

init() {
   ::init();

   add_action("remember","remember");
   add_action("checkitems","checkitems");
   add_action("clearbot","clearbot");

}

setIsNewbie(int in) {
  isNewbie = in;
  
  if(isNewbie == 1)
    set_value(0);

  if(isNewbie == 0)
    set_value(5000);

}

int validChecks() {

   if(this_player()->query_ghost())
      {
      write("You're dead. Please lie still.\n");
      return 0;
   }

   return 1;

}

int checkPresent(string str) {
  object *stuff;
  int x;
  
  stuff = all_inventory(environment(this_object()));
  
  for(x = 0; x < sizeof(stuff); x++) {
  
    if(basename(stuff[x]) == str)
      return 1;
  
  }

  return 0;

}

int clearbot() {

   if(!present(this_object(),this_player()))
      return 0;

   if(!validChecks())
      return 1;

   items = ({ });

   write("Small beeps come from the bot while it clears its memory.\n");
   return 1;

}

int checkitems() {
   int x;
   string *tmp;

   if(!present(this_object(),this_player()))
      return 0;

   if(!validChecks())
      return 1;

   if(!items || sizeof(items) < 1) {
      write("The bot's memory is empty.\n");
      return 1;
   }

   write("The bot takes off into the air to check for items, and returns with the following report:\n\n");

   for(x = 0; x < sizeof(items); x++) {

      tmp = explode(items[x],"^BREAK^");

      move_object(this_object(),tmp[0]);

      write("Room   : " + (string)environment(this_object())->short() + "\n");
      write("Item   : " + tmp[1] + "\n");
      write("Present: ");

      if(checkPresent(tmp[2]))
         write(HIG + "YES" + NORM + "\n\n");
      else
         write(HIR + "NO" + NORM + "\n\n");

   }

   move_object(this_object(),this_player());

   return 1;
}

int remember(string str) {
   object item;
   string rememberString;

   if(!present(this_object(),this_player()))
      return 0;

   if(!validChecks())
      return 1;

   if(sizeof(items) == 5) {
      write("This bot's memory is full.\n");
      return 1;
   }

   if(!str) {
      write("What would you like the bot to remember?\n");
      return 1;
   }

   item = present(str,environment(this_player()));

   if(!item) {
      write("There is no '" + str + "' in this room.\n");
      return 1;
   }

   if(!items)
      items = ({ });

   rememberString = "/" + file_name(environment(this_player()));
   rememberString += "^BREAK^" + item->short();
   rememberString += "^BREAK^" + basename(item);
   items += ({ rememberString });

   write("Small beeps come from the bot while it writes '" + str + "' to memory.\n");

   return 1;
}

drop() {

  if(isNewbie && isNewbie == 1) {
    write("The Farseer Bot self destructs.\n");
    destruct(this_object());
  }

}
