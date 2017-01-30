#define HARRY 1

int count;

#undef EXTRA_INIT
#if HARRY
object harry;
#undef EXTRA_RESET
#define EXTRA_RESET\
        starta_harry();
#endif



#if HARRY
starta_harry() {
    if(!harry || !living(harry)) {
	harry = clone_object("obj/monster");
	call_other(harry, "set_name", "zombie of halucinated guy");
	call_other(harry, "set_alias", "zombie");
	call_other(harry, "set_short", "Halucinated guy");
	call_other(harry, "set_long", "Harry has an agreeable look.\n");
	call_other(harry, "set_ac", 0);
	call_other(harry, "set_level",3);
	call_other(harry, "set_al",50);
	call_other(harry, "set_ep",2283);
	call_other(harry, "set_hp",30);
	call_other(harry, "set_wc",5);
	call_other(harry, "set_aggressive", 0);
   move_object(harry, "players/jaraxle/workroom");
	call_other(harry, "set_object", this_object());
	call_other(harry, "set_type", "attack");
	call_other(harry, "set_match", " ");
	call_other(harry, "set_type", "arrives");
	call_other(harry, "set_match", "");
	call_other(harry, "set_function", "follow");
	call_other(harry, "set_type", "leaves");
	call_other(harry, "set_match", " "); 
	
	
    }
}

notify(str) {
    say(str);
    write(str);
}
	


follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
	call_other(harry, "init_command", where);
}


monster_died() {
    object obj, b;
    int num;
    obj = first_inventory(harry);
    while(obj) {
	b = next_inventory(harry);
	if(call_other(obj, "id", "bottle")) {
	    destruct(obj);
	    num = 1;
	}
	obj = b;
    }
    if(num)
	notify("There is a crushing sound of bottles breaking, as the body falls.\n");
}

#endif

down() {
      call_other(this_player(), "move_player", "down#room/station");
        return 1;
  }
