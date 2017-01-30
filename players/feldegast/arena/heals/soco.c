/*  This object is a heavily modified form of /obj/soft_drink.c
    the standard soft drink object.  Basicly, I commented out
    anything I didn't like and changed alot of the format
    to what I prefer and changed all the variables, and
    made alot of things defines so it'd be easier to change...
    Actually, it looks nothing like the original object,
    but it would've taken longer if I'd started from scratch.
*/

#define TP this_player()
#define TPN capitalize(this_player()->query_name())
#define STRENGTH 14
#define HEAL 35
#define COST 10  /* This is cost per heal point */
#define MAX_CHARGES 5

int charges;

init() {
  add_action("drink", "drink");
  add_action("drink","sip");
}
reset(arg) {
  if(arg) return;
  charges=MAX_CHARGES;
}

id(str) {
  return str=="bottle" || str=="southern comfort" || str=="comfort" || str=="soco";
}

short(){
   return "A bottle of Southern Comfort *"+charges+"*";
}

long() {
  write("This is a tall bottle of Southern Comfort.\n"+
        "There are "+charges+" sips left.\n");
}

get(){
  return 1;
}

drink(str) {

  if (!str || !id(str))
    return 0;

  if (!TP->drink_alcohol(STRENGTH)) return 1;
  

  charges--;
  TP->heal_self(HEAL);
  write("You stop a moment to savor the smoothness and texture of the Southern Comfort\n"+
        "as it warms your entire body.\n"+
        "There are "+charges+" sips left.\n"
  );
  say(TPN+" takes a swig of Southern Comfort.\n");

  if (charges==0) {
    destruct(this_object());
    write("You finish off the last of the Southern Comfort.\n"+
       "You hate yourself now.\n"
    );
  }
  return 1;
}

query_value() {
   return COST*HEAL*charges;
}

query_weight() {
   return (charges/2)+1;
}
query_save_flag() { return 1; }
