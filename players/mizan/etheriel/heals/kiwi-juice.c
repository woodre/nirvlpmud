int drinks, price;

id(str) { return str == "bottle" || str == "juice"; }

reset(arg) {
        if (!arg) drinks = 7;
        price = drinks * 150;
}

long() {
  write("This is a bright green bottle with pictures of goofy brown\n"+
	"bird that have no wings on it. Bah! Commercialism!\n");
       write("There are [" + drinks + "] servings left.\n");
}

short() {
     return "A bottle of kiwi juice ["+drinks+"]";
}

query_save_flag() { return 1; }
query_value() { return price; }

init() {
add_action("use", "drink");
}

use(arg){
object tp;
tp = this_player();
if(!arg || arg != "tank" || arg !="juice"){
        return 0;
} else {
if(!tp->drink_soft(3)){
        return 1;
}else{
        if(arg == "juice" || arg == "tank"){
drinks=drinks - 1;
tp->heal_self(10);
        write("You put the bottle to your mouth slurp some juice... Mmm!\n"+
	"There are ["+drinks+"] servings left.\n");
        say(capitalize(tp->query_name()) + " drinks some kiwi juice.\n");
if(drinks == 0){
        destruct(this_object());
        write("You finish off the bottle and bash it to billions of bits.\n");
        tp->add_weight(-1);
                }
return 1;
                }
        }
}
}

get() { return 1; }

query_weight() { return 1; }
