
int pin;

id(str) {
    return str == "grenade";
}

short() {
    return "A grenade";
}

long() {
    if (pin)
        write("A grenade with the pin pulled.\n");
      else
        write("A grenade with the pin still in it.\n");
}

query_value() { return 300; }

get() {
    return 1;
}

query_weight() {
    return 1;
}

init() {
    add_action("pull","pull");
    add_action("drop","drop");
    add_action("toss","toss");
}

pull(str) {
    if (!str || str != "pin")
        return 0;
    write("You pull the pin out of the grenade.\n");
  say(call_other(this_player(),"query_name",0) + " pulls the pin from a grenade");
    pin = 1;
    return 1;
}

drop(str) {
    if (id(str) && pin)
        set_heart_beat(1);
    return;
}

toss(str) {
      string who;
      object dest;

      if(sscanf(str, "%s",who) !=1)
           {
            write("Toss at who.\n");
            return 1;
            }
      if(!find_living(who))
        {
         write("Player not on!\n");
         return 1;
         }
      if(pin)
      {
        dest=environment(find_living(who));
        move_object(this_object(),dest);
        set_heart_beat(1);
        return 1;
      }
}
    

       
      
heart_beat() {
    pin += 1;
    if (pin > 2) {
        object ob, next_ob;
        ob = first_inventory(environment(this_object()));
        if (ob) {
            while (ob) {
                next_ob = next_inventory(ob);
                if (living(ob))
                    tell_object(ob, "BOOM!!!!");
                    call_other (ob, "hit_player", 100);
                ob = next_ob;
                }
            }
        destruct(this_object());
        return 1;
        }
}

