inherit "obj/armor";
int charges;
reset(arg){
 ::reset(arg);
 if(arg) return;
 set_short("Tourmaline Ring");
 set_long("a ring. neat.\n");
 set_ac(1);
 set_weight(2);
 set_value(3000);
 set_alias("ring");
 set_name("Tourmaline Ring");
 set_type("ring");
 set_save_flag(1);
 charges = 3;
}

long(){
 write("A golden pinky ring with a blue gem set in it.\n"+
 "This ring is known to have magical powers of healing.\n"+
 "You can activate its magic by twisting the gem.\n"+
 "There are "+charges+" charges remaining.\n");
 return;
}

init(){
 ::init();
 add_action("twist_gem","twist");
}

twist_gem(str){
 if(str == "gem"){
 if(!worn){ write("You must wear the ring first.\n"); return 1; }
 write("You twist the small gem and the ring grows warm against your skin.\n");
 write("The ring restores your health.\n");
 this_player()->heal_self(30+random(20));
 charges--;
 if(charges == 0){
  write("The magic of the gem is used up and the ring disappears.\n");
  command("remove ring", this_player());
  destruct(this_object());
  return 1;
  }
 return 1;
 }
}
