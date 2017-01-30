#define tp this_player()->query_name()
#define TP this_player()
#define TPQ this_player()->query_real_name()
#define TARG capitalize(target)
#define TARGET find_player(target)


id(str)  { return str == "coins"; }

short() { return "A silver coin"; }

long()  {
     write("A silver coin covered with golden runes.\n");
         }

get()   {
     return 1;
        }

drop()  { return 1; }

init()  {
  if(TP->query_level() < 20)  {
   add_action("coin_player","Coin");
   }
   else
   {
     write("This bag was not created for you.\n");
     write("You find yourself some place new.\n");
     say(tp+" is turned to dust and blown away by a gust of wind.\n");
     call_other(TP,"move_player","church#room/church.c");
     return 1;
   }
   }


coin_player(str)  {
 object target;
   if(!str)  {
     write("To use type < Coin 'player name' >\n");
     return 1;
        }
   target = find_player(str);
   str = capitalize(str);
   if(!target) {
     write(str+" is not within the realms of magic.\n");
     return 1;
        }
   tell_object(target,
     "\n A silver coin spins through the air and embeds itself into your forehead.\n");
   tell_object(target,
     "\n\nYour universe has changed.\n\n");
   write("You send a silver coin flying off into the realms of magic.\n");
     return 1;
        }

