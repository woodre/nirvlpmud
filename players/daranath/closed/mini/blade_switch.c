#define POSS environment(this_object())->query_possessive()
inherit "/players/saber/armor/armor3.c";
string ONE, TWO, THREE;
reset(arg){
   ::reset(arg);
   set_name("blade_twirl");
   set_short();
   set_long();
   set_type("dance");
   set_ac(0);
   set_weight(0);
   set_value(0);
call_out("count_down", random(750) + 25);
call_out("juggle_time", random(5) + 10);
}
drop() {return 1;}
get() {return 1;}

count_down()  {
object ob;
  ob = environment(this_object());
tell_room(environment(ob),
  environment(this_object())->query_name()+" stops "+ob->query_possessive()+" juggling act.\n");
remove_call_out("count_down");
remove_call_out("juggle_time");
destruct(this_object());
  return 1;
        }

juggle_time()  {
object ob;
string weap_name;
object WONE, WTWO, WTHREE;
int temp;
  ob = environment(this_object());

  WONE = present(ONE, ob);
  WTWO = present(TWO, ob);
  WTHREE = present(THREE, ob);

  if(!WONE || !WTWO || !WTHREE)  {
  say("You need all three weapons to juggle!\n");
  remove_call_out("count_down");
  remove_call_out("juggle_time");
  destruct(this_object());
  return 1;
        }

  temp = random(3);
  if(temp == 0) weap_name = WONE->query_name();
  if(temp == 1) weap_name = WTWO->query_name();
  if(temp == 2) weap_name = WTHREE->query_name();

  if(temp == 0)  {
  tell_room(environment(ob),
    ob->query_name()+" juggles the "+capitalize(WONE->query_name())+" into "+ob->query_possessive()+" 'on' hand.\n");
        }
  if(temp == 1)  {
  tell_room(environment(ob),
    ob->query_name()+" juggles the "+capitalize(WTWO->query_name())+" into "+ob->query_possessive()+" 'on' hand.\n");
        }
  if(temp == 2)  {
  tell_room(environment(ob),
    ob->query_name()+" juggles the "+capitalize(WTHREE->query_name())+" into "+ob->query_possessive()+" 'on' hand.\n");
        }

  command("wield "+weap_name, ob);

call_out("juggle_time", random(30) + 10);
  return 1;
        }

set_one(str)  { ONE = str; }
set_two(str)  { TWO = str; }
set_three(str){ THREE = str; }
