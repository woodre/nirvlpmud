inherit "obj/monster.c";

reset(arg)  {
object gold;
string a, b, c, mid;
int i;
  ::reset(arg);
  if(arg) return;
  a = "disgruntled";
  b = "hard";
  c = "city";
  i = random(3);
  if (i == 0) {mid=a;}
    else if (i == 1) {mid=b;}
    else {mid=c;}
  set_name("worker");
  set_alias("worker");
  set_alt_name("worker");
  set_race("creature");
  set_short("a "+mid+" worker");
  set_long(
    "A strong young man working hard for an honest day's\n"+
    "pay.  He goes about his business and ignores those\n"+
    "around him.  He'll probably continue doing his work\n"+
    "peacefully, unless someone disturbs him.\n");
  set_level(11);
  set_hp(165);
  set_al(100 + random(100));
  set_wc(15);
  set_ac(9);
  set_aggressive(0);

  set_chat_chance(15);
    load_chat("The worker says: We'll never get this place clean. \n");
  set_a_chat_chance(15);
    load_a_chat("The worker says: Ok, you're in trouble now. \n");

  gold = clone_object("obj/money");
  gold->set_money(450 + random(50));
  move_object(gold,this_object());
}

