
int drinks, price;

 

id(str) { return str == "cheesenub" || str == "cheesenubs" || str == "bag"; }

 

reset(arg) {

        if (!arg) drinks = 12;

        price = drinks * 150;

}

 

long() {

        write("This is a bag of cheese-filled pretzel chunks.\n"+

	"There are ["+drinks+"] chunks left.\n");

}

 

short() {

  return "A bag of Cheesenubs [" + drinks + "]";

}

 

query_save_flag() {return 1;}

query_value()

{

    return price;

}

 

init() {

add_action("use", "eat");
}

 

use(arg){

object tp;

tp = this_player();

if(!arg || arg != "cheesenub"){

        return 0;

} else {

if(!tp->eat_food(12)){

        return 1;

}else{

        if(arg == "cheesenub"){

drinks=drinks - 1;

tp->heal_self(random(5)+30);

        write("You pop a cheesenub in your mouth. Yum! There are ["+drinks+"] cheesenubs left.\n");

        say(capitalize(tp->query_name()) + " eats a cheesenub.\n");

if(drinks == 0){

        destruct(this_object());

        write("You eat the last one and finish off the bag.\n");

        tp->add_weight(-1);

                }

return 1;

                }

        }

}

}

 

get() {

    return 1;

}

 

query_weight() {

    return 1;

}
