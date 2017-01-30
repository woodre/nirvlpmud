short() { return "Philosophers' stone"; }

reset(arg) {
    if (arg)
        return;
}

query_weight() {
    return 1;
}

long() {
     write("This is the Philosophers' Stone! Everything touched by it melts\n"+
    "into gold (coins). To use it type 'touch <item>'.\n");
    return 1;
}

id(str) {
    return str == "stone";
}

init() {
    add_action("touch", "touch");
}

touch(str)  {
object obj;
int value,weight;
if(!str)  {
	notify_fail("Usage: touch <item>\n");
	return 0;
	}
obj=present(str,this_player());
if(!obj)  {
	notify_fail("What do you want to touch?\n");
	return 0;
	}
value=obj->query_value();
if (!value) {
    write("You can't melt worthless things!\n");
    return 1;
}
/* added by mizan- this shouldnt be free, matched to guild spell */
if(this_player()->query_sp() < 20) {
    write("You are too tired to do that.\n");
    return 1;
}
  this_player()->add_spell_point(-20);
weight = call_other(obj, "query_weight", 0);
call_other(this_player(), "add_weight", - weight);
if (value > 900)  value = 700 + random(200);
write("As you touch the "+str+" the stone glows.\nThe item melts into "+value+" coins.\n");
say("You see "+call_other(this_player(),"query_name")+" touching a "+str+" with a gray stone.\nThe item melts into "+value+" coins.\n");
call_other(this_player(), "add_money", value);
destruct(obj);
return 1;
}

query_value() {
    return 250;
}

get() {
    return 1;
}

