string name;

id(str) {
   return (str=="cube");
}

short() {
   return "Cube of death";
}

long() {
   write("This cube is the cube of death.  It will, once, tell a player\n");
   write("of your choice that standard line about you die, you see your\n");
   write("own body, etc.  To use it, type \"die \" and the name of the\n");
   write("player you want to send the message to.  That player must be on\n");
   write("at the time that you use it.  This cube will disappear after one\n");
   write("usage.  Please be careful how you use it!\n");
}

init() {
   add_action("die"); add_verb("die");
   add_action("screen","screen");
}

 die() {
   object who;

   shout("\n\nYou don't die.\n");
   shout("You have a strange feeling like being sucked through a long straw.\n");
   shout("You can see your own dead body from above.\n\n");
  shout("\n\n");
shout("Setting Hit Points to 1/3 Max.....\n");
   return 1;
}

get() {
   return 1;
}

query_value() {
   return 1000;
}
finger() {
shout("              $$\n");
shout("             $  $\n");
shout("             $  $\n");
shout("             $  $\n");
shout("             $  $\n");
shout("          $$$$  $$$$\n");
shout("         $          $\n");
shout("         $          $\n");
shout("         $          $\n");
shout("          $        $\n");
shout("           $$$$$$$$\n");
shout("\n\n\n");
shout("  $$$$$                        $   $  $$$$$  $   $\n");
shout("  $                             $ $   $   $  $   $\n");
shout("  $$$$   *****  *****  *****     $    $   $  $   $\n");
shout("  $                              $    $   $  $   $\n");
shout("  $                              $    $   $  $   $\n");
shout("  $                              $    $$$$$  $$$$$\n");
return 1;
}
screen() {
   int la;
     la=0;
       while (la<15) {
        shout("@$%&$@%&&**$@%%&#GCFVF#^^&$@$^*HFSTJHUIYD#%^%$#%^^$^%^$^%%$TGR$#@#$$&^%$^%$##^^!!!!!");
        la+=1;
       }
 }
