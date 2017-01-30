#define ME capitalize(this_player()->query_real_name())

int sips_taken;

id(str) { 
 return str == "sprig" || str == "leaf" || str == "leaves";
}

reset() {}

long() {
  write("A sprig of Aspen leaves.\n");
  write("The leaves are small, green, and appear to be edible.\n");
  if((3 - sips_taken) == 1) write("Tere is 1 leaf left.\n");
  else write("There are " + (3-sips_taken) + " leaves left on the branch.\n");
}

short() { return "A Sprig of Leaves"; }

init() {
  add_action("eat","eat");
}

eat(arg) {
  if (id(arg)) {
    say(ME+" plucks a leaf of the sprig, puts it in "+this_player()->query_possessive()+
    " mouth and chews it.\n");
    write("You pluck a leaf of the branch and put it into your mouth.\n"+
    "The leaf tastes sweet on your tounge.  You chew the leaf thouroughly\n"+
    "and swallow.  Your head feels alot clearer and your vision seems\n"+
    "to be much sharper now.\n");
    if(sips_taken == 2) { write("You have eaten the last leaf.\n"); }
    else { write("There are "+(2 - sips_taken)+" leafs still on the branch.\n"); }
      call_other(this_player(),"drink_alcohol",-4);
      sips_taken++;
      if (sips_taken > 2) { 
        this_player()->add_weight(-1);
        destruct(this_object()); 
      return 1;
    }
    return 1;
   }
}
 


get() { return 1; }
query_weight() { return 1; }
query_value() { return 2500; }
query_save_flag(){ return 1; }

