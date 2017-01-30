
/*
 * DUST OF APPEARANCE (3/19/94)
 * Removes player's invisibility
 */

int uses;

reset(arg) {
   if(arg)
     return;
   uses = 3;
}

id(str) { return str == "bag" || str == "dust"; }

get() { return 1; }

query_value() { return uses*50; }

short() { return "A bag of dust of disappearance"; }

long() {
  write("A small leather bag with some dust in it.\n");
  write("You can 'sprinkle' it in the room.\n");
  write("It will cause invisible players to become visible.\n");
}

init() {
   add_action("sprinkle","sprinkle");
}

sprinkle() {
   object dest, list;
   object player;
   int i;

   dest = environment(this_player());
   list = users();
   tell_room(dest, capitalize(this_player()->query_name())+
       " sprinkles some dust in the room.\n");
   for(i=0; i < sizeof(list); i++) {
      player = present(list[i], dest);
      if(player && list[i]->query_invis() && list[i]->query_level() < 20)
        command("vis",list[i]);
   }
   uses -= 1;
   if(uses <= 0) {
     write("You use up all the dust.\n");
     destruct(this_object());
     return 1;
   }
   return 1;
}

