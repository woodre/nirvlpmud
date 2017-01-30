/*
VERY OLD->>     Scooter helped me BIG time with the code on this
                jug. (The part involving the sscanf function.
                I got this idea from Genocide. More functions are
                being worked out....

NEW->>	This item is gradually going to be phased out of service.
	Reason: It needs to be revamped, and BIG time. It was carried
	over because people actually like it- really! they do :)
	1 Dec 93
*/
object ob;
string kick;
int pow_int;
id(str) { return str == "jug" || str == "MI-jug"; }
short() { return "A jug of healing with ["+pow_int+"] charges"; }
long() {
cat("/players/mizan/etheriel/items/JUG");
write("\n"+
"This jug has ["+pow_int+"] charges remaining.\n");
        }

get() { return 1; }
query_weight() { return 2; }
query_value() { return 500; }

init() {
        add_action("as","as");
        add_action("ah","ah");
        /*
        add_action("add","add");
        */
        add_action("jug","jug");
        }
ah() {
        int x, y, z;
        x=this_player()->query_mhp();
        y=this_player()->query_hp();
        z=x-y;
        command("jug "+z, this_player());
        write("HP Autoheal\n");
        return 1;
}
as() {
        int x, y, z;
        x=this_player()->query_msp();
        y=this_player()->query_sp();
        z=x-y;
        command("jug "+z, this_player());
        write("SP Autoheal\n");
        return 1;
}
/*
add(item) {
        if(!item) return 0;
        ob=first_inventory(this_player());
        while(ob) {
                if(ob->query_strength()<1) {
                        write("Bingo! "+(ob->query_strength())+"!\n");
                        }
        write("whee!\n");
                ob=next_inventory(ob);
                }
        write("Conversion made.\n");
        return 1;
        }
*/

add_charge(str) {
        int x;
  x = str;
        pow_int=pow_int+x;
	if(pow_int > 150) pow_int = 150;
        write(
        "Current charge is ["+pow_int+"] units.\n");
        return 1;
        }

jug(arg) {
        int x;
        if(!arg) {
                write("There are ["+pow_int+"] units in the jug.\n"); 
                return 1;
                }
  sscanf(arg,"%d",x);
        if(x < 0) { write("You can't do that.\n");
          return 1;
        }
        if(x > pow_int) { write("There are only ["+pow_int+"] charges remaining!\n");   return 1; }
        this_player()->heal_self(x);
        pow_int=pow_int-x;
        write("["+(this_player()->query_hp())+"]hp ["+
        (this_player()->query_sp())+"]sp  ["+
        pow_int+"]charges \n");
        say((this_player()->query_name())+" guzzles some purple liquid from an ugly brown jug.\n");
        return 1;
        }
