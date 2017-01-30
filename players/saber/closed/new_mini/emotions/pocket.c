pocket(str) {
string gender;
object ob;
if(!str){
write("Whose pocket?\n");
return 1;  }
ob = present(str,environment(this_player()));
if(!ob){ write("They are not here.\n");
return 1;}
gender = this_player()->query_possessive();
write("You sort through "+str+"'s pockets.\n"+
          "Nothing interesting.  Ah well...\n");
tell_object(ob,"You feel light fingers searching through your pockets.\n"+
          "Spinning around quickly, you find "+tp+" with "+gender+" hand in your pocket!\n");
return 1;  }
