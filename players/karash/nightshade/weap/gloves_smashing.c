inherit "obj/armor";
reset(arg){
   ::reset(arg);
if (arg) return;
set_short("Leather glove");
set_long(
"An ordinary looking glove other than the fact that it has soft glow\n"+
"about it. It feels rather light as well.\n");
   set_ac(0);
   set_weight(1);
   set_value(1);
   set_alias("gauntlets");
set_name("glove");
   set_type("misc");
call_out("do_smash",20);
}
do_smash() {
object ob;
if (!environment(this_object())) return;
   if (worn_by && worn_by->query_attack()) {
   ob = worn_by->query_attack();
tell_object(worn_by,"You pound "+ob->query_name()+" to a bloody pulp with your magical glove!\n");
worn_by->say(worn_by->query_name()+" bloody-pulps "+ob->query_name()+" with "+worn_by->query_possessive()+" leather glove!\n", worn_by);
   ob->hit_player(5+random(15)); 
   /* changed this from rnd(15) + 5 to 5 and callout from 10 to 100
     and added rnd(3) == 0
     - mythos <5-10-96> */
         }
call_out("do_smash",100);
}
