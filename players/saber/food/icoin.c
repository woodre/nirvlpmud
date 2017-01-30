
#define tp this_player()->query_name()
int full, number, number2;

id(str)
  { return str == "coin" || str == "iron coin";  }

short() {
   return "An iron coin";
}

query_save_flag()  { return 1; }
query_value()
{
/* Changed from 500 due to not counting price in buying price -Snow */
    return number*100;
}

long() {
   write("An iron coin covered with silver runes.\n"+
    "The runes seem to form a word.\n"+
    "You have another "+number+" charges.\n");
}

reset(arg) {
    if (arg)
        return;
   number2 = 0;
/* changed from 10 to 7 because of boltar's rules about heals total healing not exceeding 175 - mythos <8-10-96>
  number = 10;
*/
  number = 7;
}

feedme()  {
if(number > 0)  {
    if (!call_other(this_player(), "eat_food", 14))
  return 0;
  write("You are surrounded by a golden aura.\n"+
    "Your body feels nourished.\n");
  say(tp+" murmurs a single word as "+this_player()->query_pronoun()+" touches an iron coin.\n"+
    tp+" is surrounded by a golden aura.\n");
  number2 = number2 + 1;
  number = number - 1;
 call_other(this_player(), "heal_self", 25);
  return 1;
    }
else {
  write("There are no more charges in the coin.\n");
  write("Your coin disappears.\n");
  destruct(this_object());
    return 1;
}
}

init() {
    add_action("feedme","feedme");
    add_action("read","read");
}

get() {
    return 1;
}

read(str)  {
if(str == "coin")  {
write("The silver runes spell out the word <feedme>.\n");
  return 1;
}
}

query_weight() {
    return 1;
}
