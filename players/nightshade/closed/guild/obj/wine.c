inherit "obj/treasure";
int pow;
reset(arg) {
if(arg) return;
  set_id("glass of wine");
  set_short("A glass of wine");
  set_long("This pure white wine was created by a knight.\n");
  set_alias("wine");
  set_value(0);
  set_weight(0);
}

init() {
::init();
  add_action("drinking", "drink");
}

drinking(str) {
int heal, hp, hpmax;
  hpmax = this_player()->query_max_hp();
  hp = this_player()->query_hit_point();
  heal = this_object()->query_pow();
  if(str == "wine" || str == "glass of wine") {
    write("You drink the glass of wine. The glass vanishes.\n");
    say(this_player()->query_name()+" drinks a glass of wine.\n");
    this_player()->heal_self(heal);
    this_player()->drink_alco(heal/2);
    destruct(this_object());
    return 1;
  }
}
set_strength(s)         { pow = s; }
query_pow()             { return pow; }

