inherit "obj/treasure";
int num_charges;
int x;
reset(arg){
   refresh_desc();
   if(arg) return;
   set_short("Teakwood wand");
   set_charges(1000);
   refresh_desc();
   set_long("This appears to be some sort of magical wand!\n"+
      "Maybe you could zap wand at someone...\n");
   set_weight(1);
   set_value(4100);
   set_save_flag(0);
}
refresh_desc(){
   set_short("Teakwood wand with " + query_charges() + " charges");
   return;
}
set_charges(arg){num_charges=arg;
   refresh_desc();
}
query_charges(){return num_charges; refresh_desc();}
init(){
   ::init();
   add_action("zap","zap");
   add_action("zap","point");
}
id(str){return (str == "gwand" || str == "wand");}

zap(arg){
   int var;
   string who;
   string what,var1;
   if (!arg){
      write("Zap what at who?\n");
      return 1;}
   if (sscanf(arg, "%s %s %s",what,var1,who) == 3){
      if (what == "wand" && var1 == "at"){
         if(!present(who,environment(this_player()))){
            write("I'm sorry but that target is not visible.\n");
            return 1;
          }
         who=present(who,environment(this_player()));
         if(who->query_npc() != 1){
            write ("The wand's creatress forbids player killing.\n");
            return 1;
          }
         who->attack_object(this_player());
         who->hit_player(500+random(50));
         else{
            who->hit_player(random(who->query_hp()));
          }
         write("\n");
         write(capitalize(who->query_name()) + " is engulfed in a");
         write(" devestating ball of fire!\n");
         write("\n");
         say(capitalize(this_player()->query_real_name()) + " waves a teakwood wand and " + capitalize(who->query_name()) + "\nburts into flame!\n\n");
         x++;
         var = 1000 - x;
         set_charges(var);
         if(var != 0){
            write("You now have " + var + " charges left.\n");
          }
         if (x == 1000){
            write("Your wand splinters from overuse.\n");
            destruct(this_object());
            return 1;
          }
         return 1;
       }
      return;
   }
   return;
}
long(){write("This appears to be some sort of magical wand!\n"+
      "Maybe you could <zap wand at monster>...\n");}
