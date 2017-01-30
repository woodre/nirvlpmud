#include "/players/dragnar/guild/defs/def.h"
do_sell(str) {
    int value, weight;
    object ob;
	 if(!str) {
	 write("What do you want to junk?\n");
	 return 1; }
    ob = present(str, this_player());
    if(!ob) {
	write("You do not have that object.\n");
    return 1; }
    if(usp < 10) {
    write("You don't have enough spell points to sacrifice.\n");
    return 1; }
    value = ob->query_value();
    if (!value) {
        write(ob->short() + " has no value.\n");
        return 1;
    }
    if (environment(ob) == this_player()) {
         if (call_other(ob, "drop", 0)) {
            write("You can't junk that!\n");
            return 1;
        }
        weight = call_other(ob, "query_weight", 0);
        call_other(this_player(), "add_weight", - weight);
    }
    if (value > 1000) {
           value = (random(200)+1000);
    }
    this_player()->add_spell_point(-10);
    write("The ground opens and the "+ob->short()+" is sucked into it.\n"+
    "When the ground closes "+value+" gold coins appear.\n"+
    "You bend down and pick them up.\n");
    say("The gound opens and the "+ob->short()+" is sucked into it.\n"+
    "When the ground closes a pile of gold coins appear.\n"+
    ""+capname+" bends over and picks them up.\n");
    call_other(this_player(), "add_money", value);
        destruct(ob);
        return 1;
}
