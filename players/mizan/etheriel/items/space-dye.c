inherit "obj/armor";

short() {
  if(worn) {
    return "A Space-dyed top (worn)";
  } else {
    return "A Space-dyed top";
  }
}

long() {
  write("This is a top made of the inherently indestructable ether-material\n"+
	"simply known as 'Spuckstuff'. Normally translucent, it has been\n"+
	"electro-dyed with an assortment of rich, vibrant colors to give\n"+
	"it a futuristic, stand-alone quality. It has a soft, squishy feel\n"+
	"and is styled with a boatneck and extra-long sleeves.\n");
}

init() {
::init();
  add_action("use_me","wear");
  add_action("unuse_me","remove");
}

reset(arg) {
::reset(arg);
if(arg) return;
	set_name("top");
	set_alias("shirt");
	set_value(10000);
	set_ac(3);
	set_type("armor");
	set_weight(1);
	}

use_me(str) {
  if(!str || str !="top" || str !="shirt") return 0;
    if((this_player()->query_gender()) !="female") {
      write("You would look really silly wearing this top.\n");
    }
/*
    if((this_player()->query_height()) > 5'9) {
      write("The shirt is too short on you.\n");
      return 1;
    }
*/
    if((this_player()->query_weight()) > 150) {
      write("The shirt is too tight on you.\n");
      return 1;
    }
  ::wear("top");
  return 1;
}

unuse_me(str) {
  if(!str || str !="shirt" || str !="top") return 0;
  ::remove("top");
  return 1;
}

