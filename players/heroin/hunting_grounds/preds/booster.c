id(str) { return str == "booster";}
/* Changed value from 5,000 to 1,000. -Snow */
query_value() {return 1000;}
get() {return 1;}
drop() {return 1;}

reset() {}
long() { write("Biobooster ***Inject it****\n"); }
short() { return "biobooster"; }

init () {
   add_action("cast","cast");
   add_action("inject","inject");
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
inject(arg) {
say(this_player()->query_name()+" injects a biobooster.\n");
write("You feel a surge of energy as you slam the biobooster into your flesh.\n");
call_other(this_player(), "heal_self",25);
write("all better now\n");
destruct(this_object());
return 1;
}
/*
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
*/
