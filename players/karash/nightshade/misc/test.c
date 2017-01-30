inherit "obj/treasure";
int blood;
reset(arg) {
if (arg) return;
set_short("Bag of human blood");
set_weight(1);
set_alias("blood");
set_value(1500);
blood=7;
}
long() {
   write("This is a bag containing blood. There is a long tube\n"+
      "with a needle at its end that you might use to inject\n"+
      "the blood into you. It is just ordinary human blood.\n"+
      "The bag contains "+blood+" injections left.\n");
   }
init()
{
add_action("do_inject", "inject");
}
do_inject(str)
{
if(id(str))
{
if(!call_other(this_player(), "drink_alcohol",13))
{
write("You have to much blood in you already!\n");
return 1;
}
if(call_other(this_player(), "drink_alcohol", 13))
{
say(call_other(this_player(), "query_name") + " winces as they insert the needle into a vein.\n");
write("You wince as you stick the needle into a swollen vein but feel\n"+
"a slight buzz as the blood rushes into you.\n");
call_other(this_player(), "heal_self", 22);
blood -=1;
return 1;
}
if(blood<1)
{
write("The bag is empty and fades away.\n");
destruct(this_object());
return 1;
}
}
else {return 0; }
}
