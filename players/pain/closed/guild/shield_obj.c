int shields;

long() {
  return;
}
reset(arg) {
    if (arg)
   return;
  shields = 0;
}
query_weight() {
    return 0;
}
short() {
   return;
}
id(str) {
  return str == "shield_obj" || str == "monk_obj";
}
query_value() {
    return 0;
}
get() {
  return;
}
drop() {
 return 1;
}

init(){
add_action("shield","shiel_d");
}

shield(){
 int myac;
if(this_player()->query_sp() < 25){
 write("You do not have enough Spell Points for a Shield.\n");
 return 1; }
if(shields > 3){
 write("You cannot cast another Shield yet.\n");
 return 1; }
myac = this_player()->query_ac();
if(myac > 10){
 write("You do not need another Shield right now.\n");
 return 1; }
write("You create a shimmering shield of force around your body.\n");
this_player()->add_ac(2);
call_out("remove_shield", 400);
this_player()->add_spell_point(-40);
shields++;
return 1;
}

remove_shield(){
 int myac;
 tell_object(environment(this_object()),
    "> Your shield disappears.\n");
 myac = environment(this_object())->query_ac();
environment(this_object())->add_ac(-2);
 shields--;
return 1;
}

query_shields(){ return shields; }
