inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("pelt");
    set_alias("fur");
    set_short("A beautiful white pelt");
    set_long("A pelt taken from the white wolves of the\n"+
             "Forbidden.  You may wish to 'sell to trader'\n");
    set_weight(4);
    set_value(5000);
}

init() {
  ::init();
  add_action("ssell","sell");
}

ssell(str) {
int nm;
  if(str == "to trader") {
  nm = 4000 + random(2000);
  write("You sell the pelt to a trader\n");
  write("He gives you "+nm+" for it.\n");
  this_player()->add_money(nm);
  destruct(this_object());
  return 1;}
}
