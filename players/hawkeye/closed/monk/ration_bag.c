inherit "obj/treasure";
int rations, x;
reset(arg) {
 if(arg) return;
   set_short("A Ration Bag");
    set_alias("bag");
   set_long("A Monk Ration Bag.\n");
   set_weight(2);
    set_value(0);
  rations = 0;
}
id(str){
   return str == "bag" || str == "ration bag" || str == "monk_obj";
}

get() { return 1; }
drop() { return 1; }
long() {
   write("A Ration Bag.  The Bag has "+rations+" meals in it.\n");
       }

up_rations() {
   rations = rations + 1;
   return 1;
}

init() {
 add_action("eat", "eat");
}

eat(str) {
  object ob;
  if(str == "ration") {
write("You take a ration from the bag and eat the whole meal.\n"+
      "You instantly feel better after eating the tender morsels!.\n");
      this_player()->heal_self(10);
      rations = rations - 1;
 if(rations == 0) {
write("You have taken the last ration from the bag.  The bag\n"+
      "crumbles into a soft pile a dust that gets scattered by the\n"+
      "winds.\n");
    destruct(this_object());
       return 1;
          }
    return 1;
    }
}
