int pregnancy;
string pregtoo;

set_pregnancy(str) {
string tmpa,tmpb;
object malekid;
     string preg_from;
    if (gender !="female") return 0;
    if(pregnancy) return 0;
       if(!present("fertility",this_object()))
     if(this_object()->query_phys_at(3) > 1200)  {
       if(random(100) > 20) return 0;
     }
      pregnancy = age;
      if(this_object()->is_kid()) {
        this_object()->set_kidpreg();
      }
      preg_from=this_player()->query_real_name();
      malekid = present(str);
      if(malekid && malekid->is_kid() && preg_from != name) preg_from = str;
      if (preg_from == name ) preg_from = str;
      if(this_player()==this_object() && str) 
         preg_from=str;
         pregtoo = preg_from;
/*
      tell_object(this_object(), preg_from+" has made you pregnant\n");
*/
     if(this_player() != this_object())
/*
       tell_object(this_player(), "You have made "+name+" pregnant\n");
*/
     if(this_player() == this_object() && preg_from)
     if(sscanf(preg_from,"%shis med%s",tmpa,tmpb)!=2)
     tell_object(find_living(preg_from), "You have made "+name+" pregnant.\n");
   return 1;
 }
clear_pregnancy() {
  if(!pregnancy) return 0;
   pregnancy = 0;
   tell_object(this_object(), "You are no longer pregnant.\n");
   return 1;
   }
clear_psilent() {
  if(!pregnancy) return 0;
   pregnancy = 0;
   return 1;
   }
child_birth() {
   object kid;
   int rr;
   if(!pregnancy) return 0;
   if(!this_object()->is_kid()) {
   if(16199 > age - pregnancy) return 0;
   if(this_object()->query_phys_at(4) == 4123) return 0;
   if(this_player() != this_object()) return 0;
   if(this_object()->query_ghost()) {
     pregnancy = pregnancy + 300;
     return 0;
    }
   }
   if(gender != "female") {
     write("You feel a great deal of pain...\n");
     say(cap_name+" doubles over from a severe pain.\n");
     write("The baby can't find the way out!!\n");
     this_object()->hit_player(15+random(30));
     pregnancy=pregnancy+500;
     return 1;
     }
   pregnancy =0;
say(cap_name+" falls to the ground and through much pain and screaming, gives birth to a child.\n");
tell_object(this_object(), "The labor pains become too great...\n"+
   "You need to lay down.\n" +
   "You have the urge to PUSH.\n"+
     "Through much pain and agony... you have given birth.\n");
    add_hit_point(-6);
    this_object()->hit_player(10);
    add_phys_at(3, -5);
    add_phys_at(3, -random(25));
    if(present("boobs",this_object())) {
      present("boobs",this_object())->add_cup(-random(3));
      present("boobs",this_object())->add_bust(-random(3));
    }
    write("You can name your child with 'childname <name>'\n");
     kid = clone_object("obj/kid");
    kid->set_gender("female");
   if(random(100) < 50) kid->set_gender("male");
	call_other(kid, "set_name", "baby");
	call_other(kid, "set_hp", 30);
call_other(kid, "set_ac", 0);
	call_other(kid, "set_wc", 0);
	call_other(kid, "set_al", 0);
          kid->set_short(cap_name+"'s baby");
	call_other(kid, "set_long",
              "A little newborn baby.\n");
	call_other(kid, "set_aggressive", 0);
         kid->set_parent(name);
         if(!pregtoo) pregtoo = "-*unknown*-";
         kid->set_nparents(name+"#"+pregtoo);
call_other(kid, "set_level", 1);
call_other(kid, "set_chat_chance", 10);
      kid->load_chat("The baby cries.\n");
      kid->load_chat("The baby drools.\n");
      kid->load_chat("The baby smiles.\n");
      kid->load_chat("The baby says: OOGA BOOGA MMOOMY\n");
      kid->load_chat("The baby says: OCA PYUPY ORCI SUM\n");
     move_object(clone_object("obj/soul"), kid);
       move_object(kid,this_object());
 rr = random(100);
 if(present("fertility",this_object()) && rr > 85) { 
   if(this_object()->query_phys_at(4)!=9) {
    this_object()->add_phys_at(4,-query_phys_at(4));
    this_object()->add_phys_at(4,9);
   }
 }
 if(rr > 94 || this_object()->query_phys_at(4) == 9) {
   if(this_object()->query_phys_at(4) == 9)
   this_object()->add_phys_at(4,-9);
    set_preg_num((query_age()-15900)+random(150));
    add_phys_at(3,random(25));
    write("You are still pregnant with another child.\n");
  }
   return 1;
}
query_pregnancy() { return pregnancy; }
static have_sex(str) {
     string tmp;
    object sexob,condom;
     int pass;
        if(!str) return 0;
        if(this_object()->query_attack()) {
          write("You are too busy for that at the moment.\n");
          return 1;
        }
    if(this_player()->query_guild_name() == "Undead")
   {
    write("\
You are currently unable to have sex, due to the loss\n\
of your private parts to the infernal powers of rot\n\
and decay. Beg Vertebraker to create zombie babies\n\
like in \"Dead Alive\" if you ever want functioning\n\
for this mud ability ever again in your guild.\n");
     return 1;
  }
        if(str =="yes") {
           str = current_room;
           pass = 1;
       }
       sexob = find_living(str);
       if(!sexob) return 0;
       if(!present(sexob)) {
         write("That is not here.\n");
         return 1;
        }
    if (!pass) {
      write("You ask "+str+" to have sex.\n");
      sexob->set_part(name);
      sexob->ask_sex(cap_name);
      return 1;
    }
    tell_object(this_object(), "You have sex with "+str+"\n");
    tell_object(sexob, "You have sex with "+cap_name+"\n");
    tell_room(environment(this_object()),this_object()->query_name()+" has sex with "+sexob->query_name()+"\n");
    current_room = "nottodaythisisresettoprevent";
    if(gender=="female" && sexob->query_gender()=="female") return 1;
    condom = present("condomxx",this_object());
    if(!condom) condom = present("condomxx",sexob);
    if(condom) {
      if(!condom->query_worn()) condom = 0;
    }
    if(!condom || (condom && condom->breaking()) ||
      (condom && condom->query_broke()) ) {
      if(condom) { 
        tell_object(this_object(),"The condom broke!\n");
        tell_object(sexob,"The condom broke!\n");
        condom->set_broken();
      }
    if(gender=="female" && random(100) < 15 || present("fertility",this_object())) {
            tmp = sexob->query_real_name();
            if(!tmp) tmp = sexob->query_name();
            set_pregnancy(tmp);
         }
     if(gender!="female" && random(100) < 15 || present("fertility",sexob)) sexob->set_pregnancy(name);
   }  
   return 1;
}
ask_sex(str) {
tell_object(this_object(), str+" wishes to have sex with you, If you wish to have sex with "+str+"\nType 'sex yes'\n");
if(this_object()->is_kid()) {
  tell_object(find_player(this_object()->query_parent()), str+" wishes to have sex with "+
              this_object()->query_name()+". Use 'com <kidname> sex yes' to accept.\n");
}
  return 1;
}
set_part(str) { 
     current_room = str;
     return 1;
  }
set_preg_num(arg) {
 if(this_player() && this_player() != this_object()) { 
 int aa,bb;
 if(pregnancy)
 aa=age-pregnancy;
 bb=age-arg;
   log_file("POINTS", this_player()->query_real_name()+" preg_num_patch "+
   aa +" to "+bb +" of "+name +"\n");
 }
   pregnancy=arg; 
}
query_pregtoo() { return pregtoo; }
set_pregtoo(arg) { pregtoo=arg; }
