
#define tp this_player()->query_name()
int full, number, number2;

id(str)
 { return str == "rat" || str == "rat on a stick";  }

short() { return "Rat on a Stick"; }

query_save_flag()  { return 1; }
query_value() { return 250; }

long() {
  write("A rat that someone has killed and then impaled on a stick.\n"+
        "You could take a 'bite' of 'rat' if you are extremly hungry.\n");
}

reset(arg) {
    if (arg)
        return;
   number2 = 0;
   number = 2;
}

bite_rat(str)  {
if(!str) {
  write("Bite what?\n");
   return 1;   }
  if(str == "rat" || str == "rat on a stick")  {
if(number2 < 2)  {
    if (!call_other(this_player(), "eat_food", 14))
  return 0;
  write("You bite into the dead rat and choke down the rotten meat.\n"+
        "Its not exactly something you want to eat again.\n");
  say(tp+" bites into the dead rat and gets a sickening expression.\n");
  number2 = number2 + 1;
  number = number - 1;
 call_other(this_player(), "heal_self", 25);
 write("You have "+number+" bites left.\n");
    }
if(number2 > 1)  {
  write("You finish off the rat on a stick.\n");
  destruct(this_object());
}
 return 1;
}
}

init() {
    add_action("bite_rat","bite");
}
get() { return 1; }
query_weight() { return 1; }
