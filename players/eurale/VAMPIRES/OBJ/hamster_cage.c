/*
  hamster_cage.c
*/

#define TP this_player()
#define CTPN capitalize(TP->query_name())
inherit "obj/treasure";
int number_of_hamsters, i;
object eater;

init(arg) {
  add_action("eat_hamster","eat");
}

query_save_flag() { return 1; }

eat_hamster(str) {
string str2;
if(!str || str != "hamster") {
  write("Eat what?\n"); return 1; }
if (number_of_hamsters == 0) {
  write("Your hamster cage is empty!\n");
  return 1; }

if(!call_other(TP,"eat_food",14)) {
  write("You are too full to eat another bite!\n");
  return 1; }

number_of_hamsters -= 1;

if(number_of_hamsters > 0) set_weight(number_of_hamsters);
else set_weight(1);

if (number_of_hamsters == 0) {
  write("Your hamster cage is now empty!\n");
  return 1; }

  eater = this_player();
  call_out("effect1",1);
  return 1; }

effect1() {
tell_object(eater,
  "\nYou open the cage and take out a quivering hamster.\n\n");
tell_my_room(capitalize(eater->query_real_name())+
  " opens the cage and takes out a quivering hamster.\n\n");
call_out("effect2",3);
return 1; }

effect2() {
tell_object(eater,
  "You open your jaws and quickly close them over the squirming rat.\n\n");
tell_my_room(
  capitalize(eater->query_real_name())+" opens "+eater->query_possessive()+
  " jaws and closes them over the quivering hamster.\n\n");
call_out("effect3",3);
return 1; }

effect3() {
tell_object(eater,
  "As you clamp down with your jaws, you hear a crunch and one\n"+
  "muffled squeak.\n\n");
tell_my_room(capitalize(eater->query_real_name())+
  " crunches down and you hear a single muffled squeak.\n\n");
call_out("effect4",4);
return 1; }

effect4() {
tell_object(eater,
  "You feel a tickle in your throat and then begin to GAG!\n\n");
tell_my_room(capitalize(eater->query_real_name())+
  " makes a peculiar face and begins to GAG!\n\n");
call_out("effect5",3);
return 1; }

effect5() {
tell_object(eater,
  "You HACK out a huge furball....\n\n");
tell_my_room("You watch as "+eater->query_pronoun()+" hacks out a huge "+
    "furball.\n\n");
eater->heal_self(12);
return 1; }

reset(arg) {
  if (arg) return 0;

  number_of_hamsters=5;
  set_value(500);
  set_weight(5);
}

short() { return
  "A hamster cage with "+number_of_hamsters+" hamsters in it"; }

long() {
  write(short()+".\n"+
    "You can 'eat hamster' for medicinal healing.\n"+
    "A small label on the cage says: Mfg by Eurale Goodies\n");
}

id(str) { return str == "hamster cage" || str == "cage" ||
	str == "hamsters"; }

tell_my_room(str) {
string players_here;
if(first_inventory(environment(eater)))
  players_here = first_inventory(environment(eater));
else
  players_here = first_inventory(eater);

while(players_here) {
  if(living(players_here) && !players_here->query_npc() &&
    players_here != environment()) {
    tell_object(players_here,str);
  }
  players_here = next_inventory(players_here);
}
return 1; }
