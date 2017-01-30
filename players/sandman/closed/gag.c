id(str) { return str == "ggg"; }

get() {
   return 1;
}

drop() {
   return 1;
}

init() {
   add_action("womble","shout");
   add_action("womble","gossip");
   add_action("womble","risque");
   add_action("womble","equip");
   add_action("womble","emergency");
   add_action("womble","junk");
}

womble() {
   write("Your throat is too soar to do this.\n");
   return 1;
}

