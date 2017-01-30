
id(str){ return str == "tester"; }

init(){
   add_action("bingle", "bingle");
}

bingle(){
  object shadow;
    shadow = clone_object("players/deathmonger/test");
   shadow->frog();
   write("You binglefrog.\n");
   return 1;
}
