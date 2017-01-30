/************************************************************
| weapon base for weapons used by bandits- type variable is
| all that need be set.
*************************************************************/
inherit "obj/weapon";
string type;

set_type(string str) {
  if(!str) str = "sword";
  if(member_array(str,({"sword","spear","axe","staff","club","mace"})) == -1)
    type="sword";
  else
    type=str;
  set_class(random(4)+12);
  set_name(type);
}
locker_arg() { return type; }
locker_init(str) {
  set_type(str);
}
long() {
  if(!type) type="sword";
  write(
"A crudely made but fairly solid and servicable "+type+", the sort that might\n"+
"be used by a cheap mercenary, or a peasant.\n");
}
short() {
  if(!type) type="sword";
  return "A crude "+type;
}
query_weight() {
  return 3;
}
query_value() {
  return 400;
}
