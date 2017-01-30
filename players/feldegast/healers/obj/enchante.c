#define TP this_player()
#define TPN capitalize(this_player()->query_name())
#define STRENGTH 14
#define HEAL 40
#define COST 1  /* This is cost per heal point */
#define MAX_CHARGES 1

int charges;

init() {
  add_action("eat", "eat");
}
reset(arg) {
  if(arg) return;
  charges=MAX_CHARGES;
}

id(str) {
  return str == "fruit" || str == "magical fruit";
}

short(){
   return "Magical fruit";
}

long() {
  write(
"This is a golden-skinned fruit that seems to glimmer slightly\n"+
"with healing energy.\n"
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
  write("You bite into the delicious magical fruit, then wipe your\n"+
        "chin when you're done with it.\n"+
        "HP: "+TP->query_hp()+" SP: "+TP->query_sp()+"\n\n"
  );
  say(TPN+" eats a gold-skinned fruit.\n");

  if (charges==0) {
    destruct(this_object());
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
