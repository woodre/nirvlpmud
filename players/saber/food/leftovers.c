/*
 *  Leftover turkey for eating.
 *  Saber on 11/24/95
 *
 */

#define tp this_player()->query_name()
int full, number, number2;

id(str) { return str == "leftover" || str == "leftovers" || str == "sack";  }

short() { return "A sack full of T-day leftovers"; }

query_save_flag()  { return 1;   }
query_value()      { return 250; }
query_weight()     { return 1;   }


long() {
    write("A sack full of Thanksgiving leftovers.\n"+
          "You think you could 'munch' them.\n");
        }

reset(arg) {
    if (arg)
        return;
   number2 = 0;
   number = 5;
        }

feedme(str)  {

  if(!str) {
    write("What would you like to munch what?\n");
    return 1;   
        }

  if(str == "leftovers" || str == "leftover" || str == "sack")  {
  
  if(number2 < 5)  {
    if (!call_other(this_player(), "eat_food", 14)) return 0;

    write("Yummm.  Almost as good as yesterday.\n");
    say(tp+" eats from a sack of T-day leftovers.\n");
  
  number2 = number2 + 1;
  number = number - 1;
  call_other(this_player(), "heal_self", 25);
  write("You have enough leftovers to munch "+number+" more times.\n");
    }
    
  if(number2 > 4)  {
    write("You finish off the sack of leftovers.\n");
    destruct(this_object());
        }
  return 1;
        }
        }

init() {  add_action("feedme","munch");  }

get()  { return 1; }
