object one,two;
init() {
  add_action("exchange","push");
  add_action("enter","enter");
  add_action("leave","leave");
  add_action("look", "look"); 
     add_action("look", "l");
     add_action("look", "examine");
     add_action("look", "search");
}
enter(str) {
  string junk,num;
  if(!str) return 0;
  if(sscanf(str,"%s %d",junk,num) != 2) 
   {  write("USAGE: enter chamber 1 or 2\n"); return 1; }
  if(junk !="chamber") {
   write("USAGE: enter chamber 1 or 2\n");
  return 1;
  }
  if(environment(this_player()) == this_object()) return 0;
  if(num == 1) {
   if(one) {
     write("That chamber is occupied.\n");
     return 1;
   }
    move_object(this_player(),this_object());
    tell_room(environment(this_object()),this_player()->query_name()+" enters into the machine's number one chamber.\n");
    long();
    one=this_player();
    return 1;
   }
  if(num == 2) {
   if(two) {
     write("That chamber is occupied.\n");
     return 1;
   }
    move_object(this_player(),this_object());
    tell_room(environment(this_object()),this_player()->query_name()+" enters into the machine's number two chamber.\n");
    long();
    two=this_player();
    return 1;
   }
}
leave() {
    if(environment(this_player()) != this_object() ) return 0;
    if(this_player()==one) one = 0;
    if(this_player()==two) two = 0;
   move_object(this_player(),environment(this_object()));
   tell_room(environment(this_object()),this_player()->query_name()+" leaves the machine.\n");
 return 1;
}
exchange(str) {
  int wt1,wt2,htf1,htf2,hti1,hti2;
  int age1,age2,preg1,preg2;
  string de1,de2,gen1,gen2;
  string race1,race2;
  string ti1,ti2,pti1,pti2;
  object f1,f2;
 if(str != "button") return 0;
 if(!one || !two) { 
   write("Two people must be in the machine.\n");
   return 1;
  }
 wt1=one->query_phys_at(3);
 wt2=two->query_phys_at(3);
 htf1=one->query_phys_at(1);
 htf2=two->query_phys_at(1);
 hti1=one->query_phys_at(2);
 hti2=two->query_phys_at(2);
 age1=one->query_age();
 age2=two->query_age();
 preg1=one->query_pregnancy();
 preg2=two->query_pregnancy();
 de1=one->query_description();
 de2=two->query_description();
 gen1=one->query_gender();
 gen2=two->query_gender();
 race1=one->query_race();
 race2=two->query_race();
 ti1=one->query_title();
 ti2=two->query_title();
 pti1=one->query_pretitle();
 pti2=two->query_pretitle();
 tell_object(one,"The machine warms up it begins to glow inside.\nYou lose track of where you are.\n");
 tell_object(two,"The machine warms up it begins to glow inside.\nYou lose track of where you are.\n");
 one->add_phys_at(3,wt2-wt1);
 two->add_phys_at(3,wt1-wt2);
 one->add_phys_at(1,-htf1);
 one->add_phys_at(1,htf2);
 two->add_phys_at(1,-htf2);
 two->add_phys_at(1,htf1);
 one->add_phys_at(2,-hti1);
 one->add_phys_at(2,hti2);
 two->add_phys_at(2,-hti2);
 two->add_phys_at(2,hti1);
 if(preg1){
  two->set_preg_num(age2-(age1-preg1));
  one->set_preg_num(0);
  }
 if(preg2){
  one->set_preg_num(age1-(age2-preg2));
  two->set_preg_num(0);
  }
 one->set_description(de2);
 two->set_description(de1);
 one->set_gender(gen2);
 two->set_gender(gen1);
 two->set_race(race1);
 one->set_race(race2);
 two->set_title(ti1);
 one->set_title(ti2);
 two->set_pretitle(pti1);
 one->set_pretitle(pti2);
 one->save_me();
 two->save_me();
 f1=present("fertility",one);
 f2=present("fertility",two);
 if(f1)move_object(f1,two);
 if(f2)move_object(f2,one);
 f1=present("boobs",one);
 f2=present("boobs",two);
 if(f1)move_object(f1,two);
 if(f2)move_object(f2,one);
 tell_object(one,"You find yourself in a different body!!!\n");
 tell_object(two,"You find yourself in a different body!!!\n");
 log_file("BodSwap",one->query_real_name()+" with "+two->query_real_name()+"\n");
 return 1;
}
long() {
  if(environment(this_player())==this_object()) {
   tell_object(this_player(), "You enter the machine's chamber. There is a button on the wall.\nThe only exit is to leave.\n");
    return 1;
  }
  write("A large strange looking machine. It appears unlike anything you\n");
  write("have seen before. There are two chambers, one on each side that\n");
  write("you may enter. The center portion contains several dials and gages\n");
  write("with one large button that stands out.\n");
  if(one) {
   write(one->query_name()+" is in chamber one.\n");
   }
  if(two) {
   write(two->query_name()+" is in chamber two.\n");
   }
return 1;
}
short() {return "A large strange looking machine"; }
query_weight() { return 3500; }
id(str) { return str == "machine"; }
reset() {
  set_light(1);
}
look(str) {
   if (!str) {
   return 0;
  }
 if (str == "at button" || str == "at controls") { 
  write("The large button is labeled 'START'. You can push it. \n");
  return 1;
  }
 return 0;
}
