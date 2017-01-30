int toast,price;
id(str) { return str == "fishnuggets" || str == "nuggets" || str == "bag"; }


reset(arg) {
   if(arg) return;
   toast=288;
   price = toast * 13;
}

short() { return "A bag of frozen fishnuggets [" + toast + "]"; }

long() {
   write("This is nothing more than a plastic bag containing ordinary,\n"+
      "non-descript frozen fish nuggets. A label on the bag seems to show the\n"+
      "ingredients of the nuggets themselves.\n");
   write("There are [" + toast + "] nuggets left.\n");
}

lose_ammo(i) {
   if(i) toast = toast - i;
   else toast=toast-1;
   return toast;
}

query_ammo() {
   return toast;
}

query_save_flag() {return 1;}

query_value() { return price; }

init() {
add_action("use", "eat");
   add_action("readme","read");
}

use(arg) {
   write("What? How? You would break your teeth on one of these things.\n");
   return 1;
}

readme(str) {
   if(!str || str != "label") return 0;
   write("Ingredients:\n\n"+
      "  Horse lips, Bread crumbs, Chicken meat (white portions only),\n"+
      "  Kangaroo bellies, Icelandic cod.\n\n");
   return 1;
}


get() { return 1; }

query_weight() { return 1; }

