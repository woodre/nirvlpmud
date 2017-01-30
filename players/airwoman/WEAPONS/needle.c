inherit "obj/weapon";
reset(arg){
::reset(arg);
    if (arg) return;
   set_name("needle");
   set_short("A Hydraulic Needle");
  set_alias("needle");
   set_long("A needle that once belonged to an embalmer.\n"+
	"(How about embalming some people.hee..hee...)"+"\n");
   set_class(10);
   set_value(250);
   set_weight(3);
   set_hit_func(this_object());
}
  weapon_hit(attacker){
    int n;
    n=random(5);
   if (n>3){
	write("The long sharpness of the needle screams for death.\n");
	say(this_player()->query_name()+
	"'s needle will soon embalm "+attacker->query_name()+"\n"); 
}
return n;
}
