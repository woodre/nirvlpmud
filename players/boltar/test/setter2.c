init()
{ add_action("x"); add_verb("x");
}
x() {
 call_other(this_player(),"set_wc", 10000);
}
id() {
return "setter";
}
