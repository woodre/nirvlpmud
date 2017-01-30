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
  add_action("eat", "eat");
}
reset(arg) {
  if(arg) return;
  charges=MAX_CHARGES;
}

id(str) {
  return  str == "tin" || str == "biscuits" || str=="biscuit";
}

short(){
   return "A tin of biscuits *"+charges+"*";
}

long() {
  write("This is a biscuit tin with "+charges+" biscuits in it.\n");
}

get(){
  return 1;
}

eat(str) {

  if (!str || !id(str))
    return 0;

  if (!TP->eat_food(STRENGTH)) return 1;
  

  charges--;
  TP->heal_self(STRENGTH);
  write("You munch on a buttermilk biscuit.\n"+
        "There are "+charges+" more biscuits left.\n"
  );
  say(TPN+" munches on a biscuit.\n");

  if (charges==0) {
    destruct(this_object());
    write("You finish off the last biscuit.\n");
  }
  return 1;
}

query_value() {
  return COST*HEAL*charges;
}

query_weight() {
   return (charges/2)+1;
}
