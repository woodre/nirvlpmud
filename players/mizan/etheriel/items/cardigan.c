inherit "obj/armor";

short() {
  if(worn) {
    return "A buttercup crochet cardigan (worn)";
  } else {
    return "A buttercup crochet cardigan";
  }
}

long() {
  write("This is a hand-knit cardigan sweater made of pure cotton, and\n"+
	"is in a dreamy buttercup color. It has some beautiful crochet\n"+
	"work at the cuffs, collar, and hemline.\n");
}

init() {
::init();
  add_action("use_me","wear");
  add_action("unuse_me","remove");
}

reset(arg) {
::reset(arg);
if(arg) return;
	set_name("cardigan");
	set_alias("sweater");
	set_value(1200);
	set_ac(2);
	set_type("misc");
	set_weight(1);
	}

use_me(str) {
  if(!str || str !="cardigan" || str !="sweater") return 0;
    if((this_player()->query_gender()) !="female") {
      write("For some reason, you cannot wear this sweater.\n");
    }
    if((this_player()->query_height()) > "5'9") {
      write("You're too tall.\n");
      return 1;
    }
    if((this_player()->query_weight()) > "140") {
      write("The sweater is too tight on you.\n");
      return 1;
    }
  ::wear("cardigan");
  return 1;
}

unuse_me(str) {
  if(!str || str !="cardigan" || str !="sweater") return 0;
  ::remove("cardigan");
  return 1;
}

