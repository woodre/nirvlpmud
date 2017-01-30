#define TP this_player()
#define TPN capitalize(this_player()->query_name())
#define STRENGTH 14
#define HEAL 35
#define COST 10  /* This is cost per heal point */
#define MAX_CHARGES 7

int charges;

init() {
  add_action("eat", "eat");
  add_action("eat","chew");
}
reset(arg) {
  if(arg) return;
  charges=MAX_CHARGES;
}

id(str) {
  return str == "tubor" || str == "root";
}

short(){
   return "Tubor roots *"+charges+"*";
}

long() {
  write(
"This is a dark tubor root wrapped in a piece of burlap cloth.\n"+
"It gives off a strong mossy smell.\n"+
"There are "+charges+" portions left.\n"
  );
}

get(){
  return 1;
}

eat(str) {

  if (!str || !id(str))
    return 0;

  if (!TP->eat_food(STRENGTH)) return 1;
  

  charges--;
  TP->heal_self(HEAL);
  write("You slowly chew on a slice of tubor root.\n"+
        "There are "+charges+" more biscuits left.\n"+
        "HP: "+TP->query_hp()+" SP: "+TP->query_sp()+"\n\n"
  );
  say(TPN+" chews on a tubor root.\n");

  if (charges==0) {
    destruct(this_object());
    write("You finish off the root.\n");
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
