#define tp this_player()->query_name()
#define TP this_player()
#define TPQ this_player()->query_real_name()
#define TARG capitalize(target)
#define TARGET find_player(target)


id(str)  { return str == "coin"; }

short() { return "A silver coin"; }

long()  {
     write("A silver coin covered with golden runes.\n");
         }

get()   {
     return 1;
        }

drop()  { return 1; }

init()  {
   add_action("coin_player","Coin");
   add_action("dest_dragon","Ick");
   }


coin_player(str)  {
 object target;
   if(!str)  {
     write("To use type < Coin 'player name' >\n");
     return 1;
        }
   target = find_living(str);
   str = capitalize(str);
   if(!target) {
     write(str+" is not within the realms of magic.\n");
     return 1;
        }
  move_object(target, environment(this_player()));
     return 1;
        }

dest_dragon(str)  {
object target;
  if(!str)  {  write("To use type: Ick <target>\n");  return 1;  }
  target = find_living(str);
    if(!target){  write(str+" is not within the realms of magic.\n");  return 1;  }
  target->hit_player(80000);
  return 1;
        }
