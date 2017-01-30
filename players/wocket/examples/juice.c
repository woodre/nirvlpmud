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

int drinks;

init() {
  add_action("drink", "drink");
}
reset(arg) {
  if(arg) return;
  drinks=MAX_CHARGES;
}

id(str) {
  return  str == "jug" || str == "juice";
}

short(){
   return "A jug of blackberry juice *"+drinks+"*";
}

long() {
  write("This is an earthenware jug with a label saying 'Blackberry juice' on it.\n"+
        "You think there's enough juice for "+drinks+" more swigs.\n"
  );
}

get(){
  return 1;
}

drink(str) {

  if (!str || !id(str))
    return 0;

  if (!TP->drink_soft(STRENGTH)) {
    write("You don't think you could drink any more of it.\n"); 
    return 1;

  }

  drinks--;
  TP->heal_self(STRENGTH);
  write("You take a swig of blackberry juice.\n"+
        "There are "+drinks+" more swigs left.\n"
  );
  say(TPN+" takes a swig of blackberry juice.\n");

  if (drinks==0) {
    destruct(this_object());
    write("You finish off the blackberry juice.\n");
  }
  return 1;
}

query_value() {
   return COST*HEAL*drinks;
}

query_weight() {
   return drinks/2;
}
