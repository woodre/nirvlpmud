init()
{ add_action("x"); add_verb("x");
}
x() {
 call_other(this_player(),"set_ac", 10000);
}
id() {
return "setter";
}
