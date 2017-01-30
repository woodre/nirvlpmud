id(str) {return str == "heal";}

reset() {}
long() { write("no more ouchie\n"); }
short() { return "ouchie-fixer"; }

init () {
   add_action("cast","cast");
   add_action("heal","heal");
   add_action("drop_object","drop");
}
cast (arg) {
  if (arg=="heal") {
heal();
return 1;
} else {
  return 0;
}
}
heal(arg) {
say(this_player()->query_name()+" fixes ouchie\n");
  write("You lick your wounds-like a dog\n");
call_other(this_player(), "heal_self",1000);
write("all better now\n");
destruct(this_object());
return 1;
}
get () { return 0; }
query_weight() {return 0; }
drop_object(str) {
 if (str== "all") {
 drop_object("heal");
 return 0;
}
if (!str || !id(str))
  return 0;
write("all gone\n");
say(call_other(this_player(), "query_name") + " says: all gone\n");
destruct(this_object());
return 1;
}
