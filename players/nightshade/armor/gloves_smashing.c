inherit "obj/armor";
reset(arg){
   ::reset(arg);
if (arg) return;
set_short("Leather glove");
set_long(
"An ordinary looking glove other than the fact that it has soft glow\n"+
"about it. It feels rather light as well.\n");
   set_ac(1);
   set_weight(2);
   set_value(1);
   set_alias("gauntlets");
set_name("glove");
   set_type("misc");
call_out("do_smash",20);
}
do_smash() {
object ob;
if (!environment(this_object())) return;
  if(worn_by && worn_by->query_attack() &&
     present(worn_by->query_attack()->query_name(),environment(worn_by))) {
   ob = worn_by->query_attack();
tell_object(worn_by,"You pound "+ob->query_name()+" to a bloody pulp with your magical glove!\n");
worn_by->say(worn_by->query_name()+" bloody-pulps "+ob->query_name()+" with "+worn_by->query_possessive()+" leather glove!\n", worn_by);
   ob->hit_player(random(5) + 5);
         }
call_out("do_smash",20);
}
