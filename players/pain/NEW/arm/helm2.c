inherit "obj/armor" ;

int broken;
reset(arg)
{
  ::reset(arg) ;
    set_short("A horned helm");
    set_long("A large horned helm made by orcs.\n");
     set_ac(2);
     set_weight(5);
	set_value(1500);
	set_alias("helm");
	set_name("helm");
	set_type("helmet");
	call_out("do_smash",15);
}
do_smash() {
object ob;
if(random(100) < 15) {
	broken = 1;
}
if (!environment(this_object())) return;
   if (worn_by && worn_by->query_attack()) {
   if(worn_by->query_sp() < 10) { broken = 1;  }
  if(broken == 1) {
      write("You smash the helmet against your opponent and ......\n"+
        "\t\t\t C  R  A  C  K!!\n"+
       "The helmet breaks!\n");
    worn_by->set_ac(worn_by->query_ac() - 2);
   destruct(this_object());
  return 1; }
   	ob = worn_by->query_attack();
	tell_object(worn_by,"You impale "+ob->query_name()+" with your horned helm!\n");
	worn_by->say(worn_by->query_name()+" impales "+ob->query_name()+" with "+worn_by->query_possessive()+" horned helm!\n", worn_by);
	ob->hit_player(3+random(3)); 
  worn_by->add_spell_point(-8);
         }
call_out("do_smash",10+random(20));
}
