id(str) { return str == "zippo"; }
   short() { return "A dark zippo lighter."; }
   long() { write (
      "A dark midnight nickel zippo lighter.\n" +
      "An item of incredible power.\n");
      }
   get() { return 1; }
   query_weight() { return 0; }
   query_value() { return 0; }

 /*
   if((this_player()->query_real_name()) != "darkblue") {
     write("This zippo is too sexy for you.\n");
   }
*/

init() {
   add_action( "axp","axp");
   add_action ( "light_cigarette", "lite");
   add_action ( "identify_object","identify" );
   add_action("force","force");
   add_action ( "bring_player", "bring");
   add_action ( "dungeon_player", "dungeon");
   add_action ( "church_player", "chch");
}

light_cigarette() {
   write("You light a cigarette.\n");
   say("Blue lights a cigarette.\n");
   return 1;}

bring_player(str) {
   object ob;
   string bye, there;

if(!str) return 0;
    ob = find_player(str);
   if(!ob) ob=find_living(str);
   if(!ob) {
   write (capitalize(str) + "is not online at this time.\n");
       return 1;
      }
    there = environment(ob);
    tell_object(ob, "Blue summons you into his workroom.\n");
   move_object(ob, environment(this_player()));
    tell_room(there, capitalize(str) +
       " is needed elsewhere.\n");
    say (capitalize(str) + " arrives suddenly.\n");
    write (capitalize(str) + " answers your summons.\n");
    return 1;
}

dungeon_player(str) {
   object ob;
   string bye, there;

if(!str) return 0;
    ob = find_player(str);
    if(!ob) ob=find_living(str);
    if(!ob) {
    write (capitalize(str) + "is not online at this time.\n");
    return 1;
}
   there = environment(ob);
   tell_object(ob,"You are imprisoned "+ capitalize(str)+".\n");
   move_object(ob, "players/blue/dungeon");
   tell_room(there, capitalize(str) +
      " is taken away.\n");
   write (capitalize(str) + " is imprisoned.\n");
   return 1;
}

church_player(str) {
   object ob;
   string bye, there;
   ob = find_player(str);
    if(!ob) ob=find_living(str);
    if(!ob) {
    write (capitalize(str) + "is not online at this time.\n");
    return 1;
}
   there = environment(ob);
   tell_object(ob,"You are escorted to the church.\n");
   move_object(ob, "room/church");
   tell_room(there, capitalize(str) +
      " is escorted to the church.\n");
   write (capitalize(str) + " is escorted to the church.\n");
   return 1;
}

identify_object(str) {
object ob;
   if(!environment(this_player())) {
      write("You must get it first.\n");
      return 1;
   }
   ob = player_inventory(str);
   if(!ob) {
      write("That is not in your inventory.\n");
      return 1;
   }
   if(ob) {
      write("NAME:          "+ob->short()+"\n");
      write("weapon class:  "+ob->weapon_class()+"\n");
      write("armor class:   "+ob->armor_class()+"\n");
      write("weight:        "+ob->query_weight()+"\n");
      write("value:         "+ob->query_value()+"\n");
      return 1;
   }
}
