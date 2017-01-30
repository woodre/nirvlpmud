inherit "obj/treasure";
#define ME capitalize(this_player()->query_name())
#define PO this_player()->query_possessive()

reset(arg) {
  if(arg) return;
  set_short("A green Potion");
  set_alias("potion");
  set_long("A tiny vial filled with green liquid.\n");
  set_weight(1);
  set_value(700);
}

id(str) {
  return str == "vial" || str == "potion" || str == "green" ||
  str == "green potion";
}

init() {
 ::init();
  add_action("drink","drink");
  add_action("pour", "pour");
}

drink(str) {
  if(id(str)) {
    write(
    "After a small sip of the Green potion you realize that this\n"+
    "foul liquid is not suitable for drinking.\n"+
    "Perhaps you should pour it on something.\n");
    say(ME+" sniffs at a green potion and decides not to drink it.\n");
    return 1;
  }
}

pour(str) {
  string this, what;
  object ob;
  int was;

  if(str && sscanf(str, "%s on %s", this, what)==2) {
    if(this == "green" || this == "potion" || this == "green potion") {

      ob = present(what, this_player());

      if(!ob) {
        write("You do not have a "+what+".\n");
        return 1;
      }
      if(ob->query_wielded()) {
        write("You should unwield the weapon first.\n");
        return 1;
      }

      was = ob->weapon_class();

      if(!was) {
        write("You pour the green potion over the "+what+".\n");
        write("...nothing seems to happen.\n");
        say(ME+" pours a green potion on "+PO+" "+what+".\n");
        this_player()->add_weight(-1);
        destruct(this_object());
        return 1;
      }

      write(
      "You pour the green potion over the "+what+".\n"+
      "The green liquid begins to glow as it coats the weapon!\n");
      write(
      ob->query_name()+" now hums with enhanced magical power!\n");
      say(ME+" pours a green potion on "+PO+" "+what+".\n");

      was += 1;
      if(was > 21) was = 21;
      ob->set_class(was);
      this_player()->add_weight(-1);

      write_file("/players/pavlik/ilstkarn/ITEM_LOG",
        ctime()+"\t"+capitalize(this_player()->query_name())+" used a Green Potion.\n");

      destruct(this_object());
      return 1;
    }
  }
}
