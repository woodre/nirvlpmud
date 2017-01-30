/*
  This weapon is pretty damn powerful - but note that it
    has a disatvantage - any time the special attack hits
    (which is about 1/3), the monster hits attacks the
    player using this weapon - so much for tagging
    and stuff during a party...!   */

#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int n,ahp;
string shield_count;
string boom_count;
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("staff of Power");
    set_alias("staff");
    set_type("staff");         /* set type added by Pavlik */
    set_alt_name("staff of power");
    set_short("Staff of Power");
    set_long("A six foot long staff covered with runes of living lightning.\n"+
     "You can feel the power this staff pulsating through your body.\n");
    set_read("The runes on the staff inform you that you can use it to do the following:\n"+
      "   lightning <target> <effect>\n"+
    "   field  <will cover you with a magic shield of protection. <once a day>  >\n"+
      "   blast <hits creature with a bolt of lightning> <limited #>\n"+
      "\n");
    set_class(18);
    set_weight(2);
    set_value(5000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
if(call_other(this_player(), "query_attrib", "mag") > random(60)) {
  write("You engulf "+attacker->query_name()+" in a raging * * CRASH * * of thunder.\n");
  say(tp+" engulfs "+attacker->query_name()+" in a raging * * CRASH * * of thunder.\n");
 n = random(3);
 ahp = attacker->query_hp();
 if(n>ahp) { n = ahp -1; }
attacker->heal_self(-n);
  return 2;
    }
 return;
}

init() {
  ::init();
add_action("lightning", "lightning");
add_action("field", "field");
add_action("blast","blast");
}
lightning(str){
object ob;
string gender;
if(!str){
write("Lightning bolt who?\n");
return 1;   }
ob = present(str,environment(this_player()));
if(!ob)  {  write("There is no "+str+" here to blast.\n");
  return 1;        }
str = capitalize(str);
gender = "its";
if(this_player()->query_gender() == "male") {gender = "his";}
if(this_player()->query_gender() == "female") {gender = "her";}
write("You blast "+str+" with a bolt of blue lightning.\n");
write(str+" looks like toast!\n");
say(tp+" blasts "+str+" with a bolt of lightning from "+gender+" staff.\n");
say(str+" looks like one big log of charcoal with two little white eyes.\n");
return 1;  }

field() {
if(shield_count < 1) {
move_object(clone_object("/players/saber/armor/mshield.c"),this_player());
command("wear magic shield",this_player());
write("You are surrounded by a nearly invisible magic shield.\n");
say(tp+" is covered by a thin field of magic.\n");
shield_count = shield_count + 1;
return 1;
}
write("You have already cast that spell today.\n");
return 1;
}

blast() {
object ob, ob2;
ob2 = this_player();
ob = this_player()->query_attack();
if(!ob) {
 write("At whom?\n");
 return 1;  }
if(boom_count < 5) {
if(ob->is_player())  { write("The lightning powers of this staff do not work verses players.\n");  return 1;  }
ob->hit_object(random(30));
write("You call down a bolt of lightning to smite "+ob->query_name()+"\n");
say(tp+" calls down a bolt of lightning to smite "+ob->query_name()+"\n");
boom_count = boom_count + 1;
return 1;
}
write("You have used up all of the charges.\n");
return 1;
}

query_save_flag()  { return 0; }
