
int drinks, price;


id(str) { return str == "snack"
 || str == "snacks" || str == "bag"; }

reset(arg) {

        if (!arg) drinks = 13;

        price = drinks * 150;

}

 

long() {

        write("This is a bag of filled with a meat-like substance\n"+

	"that is a favorite treat of the cartoon star Scooby Doo.\n"+

	"There are ["+drinks+"] chunks left.\n");

}

 

short() {

     return "A bag of Scooby Snacks";

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

if(!arg || arg != "snack"){

        return 0;

} else {

if(!tp->eat_food(12)){

        return 1;

}else{

        if(arg == "snack"){

drinks=drinks - 1;

tp->heal_self(random(5)+28);

        write("You pop one in your mouth and bark and roof around the room.\n"+

	"There are ["+drinks+"] snacks left.\n");

        say(capitalize(tp->query_name()) + " goes: 'Scooby-rooby-roo!!!\n");

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
