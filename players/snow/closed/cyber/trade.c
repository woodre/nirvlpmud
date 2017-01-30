id(str) { return str == "droid"; }
short() { "A droid"; }
long() {
  write("This small little electric thing is following you.\n");}
get() { return 0; }
drop() { return 1; }
query_value() { return 0; }
query_weight() { return 0; }

object tp, trader, my_ob, his_ob;

init() {
  add_action("yes_way","yes");
  add_action("no_way","no");
  add_action("yes_way","y");
  add_action("no_way","n");
  }

set_me(object ob) { tp = ob; }
set_him(object ob) { trader = ob; }
set_his(object ob) { his_ob = ob; }
set_mine(object ob) { my_ob = ob; }
object query_me() { return tp; }
object query_him() { return trader; }
object query_his() { return his_ob; }
object query_mine() { return my_ob; }

activate(object me, object him, object his, object mine,
         string this, string that) {
  string name, pos;
  set_me(me);
  set_him(him);
  set_his(his);
  set_mine(mine);
  name = capitalize(him->query_real_name());
  pos = him->query_possessive();
  tell_object(me,
    "A small electronic floating droid swings up to you.\n");
  tell_object(me,
    "Droid says: "+name+" requests a trade with you.\n"+
    "Droid says: Your "+that+" for "+pos+" "+this+".\n");
  tell_object(me, "Droid says: Do you accept? [y/n] ");
  time_limit(300);
  return 1; }

time_limit(int duration) {
  object me, him;
  me = query_me();
  him = query_him();
  if(duration <= 0) {
    tell_object(me, "The droid becomes impatient with the trade.\n");
    tell_object(me, "Droid says: Time for the trade has expired.\n"+
                    "Droid says: The trade has taken too long.\n");
    tell_object(him, "Your droid becomes impatient with the trade.\n");
    tell_object(him, "Droid says: Time for the trade has expired.\n"+
                     "Droid says: The trade has taken too long.\n");
    destruct(this_object());
    return 1; }
  duration -= 1;
  call_out("time_limit", 100); }

no_way() {
  string myname, hisname;
  object me, him;
  me = query_me();
  him = query_him();
  myname = capitalize(me->query_real_name());
  hisname = capitalize(him->query_real_name());
  tell_object(him, "___ "+myname+" has declined the trade. ___\n");
  tell_object(me, "You decline "+hisname+"'s trade.\n");
  tell_object(me, "The droid leaves.\n");
  tell_object(him, "Your droid comes back with your goods.\n");
  destruct(this_object());
  return 1; }

yes_way() {
  string myname, hisname;
  object his, mine, him, me;
  his = query_his();
  mine = query_mine();
  him = query_him();
  me = query_me();
  myname = capitalize(me->query_real_name());
  hisname = capitalize(him->query_real_name());
  move_object(his, me);
  move_object(mine, him);
  tell_object(him, "*** Your trade was accepted ***\n");
  tell_object(him, "Your droid comes back with something new!\n");
  tell_object(me, "* You accept the trade. *\n");
  tell_object(me, "The droid drops something in your inventory.\n"+
                  "and leaves with your item.\n");
  destruct(this_object());
  return 1; }
