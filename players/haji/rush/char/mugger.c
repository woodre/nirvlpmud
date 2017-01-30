inherit "obj/monster";
     int mon,eatmoney,plymon,count;
      object goldeat,lostgold;
reset(arg) {
if (!arg)
::reset(arg);
   starta_goldeat();
}
starta_goldeat() {
        goldeat = this_object();
	call_other(goldeat, "set_name", "man");
	call_other(goldeat, "set_short", "A man");
	call_other(goldeat, "set_long",
  "This is a man who collects your money as a hobby.\n");
        call_other(goldeat, "set_alias","mugger");
	call_other(goldeat, "set_ac", 9);
	call_other(goldeat, "set_level",12);
	call_other(goldeat, "set_al",125);
	call_other(goldeat, "set_hp",140);
	call_other(goldeat, "set_wc",12);
	call_other(goldeat, "set_aggressive", 0);
	call_other(goldeat, "set_object", this_object());
	call_other(goldeat, "set_function", "eatgold");
	call_other(goldeat, "set_type", "arrives");
	call_other(goldeat, "set_match", "");
call_other(goldeat, "set_function", "eatgold");
call_other(goldeat, "set_type", "hit");
call_other(goldeat, "set_match", "A man");
call_other(goldeat, "set_function", "eatgold");
call_other(goldeat, "set_type", "missed");
call_other(goldeat, "set_match", "A man");
call_other(goldeat, "set_function", "eatgold");
call_other(goldeat, "set_type", "leaves");
call_other(goldeat, "set_match", "");
	
}

eatgold(str) {
   string who, ext;
      goldeat = this_object();
   sscanf(str, "%s %s\n", who, ext);
   lostgold = find_player(lower_case(who));
   if (lostgold == 0) {
    return 1;
}
     mon = 0 - random(300) - 1;
    if (lostgold->query_level() < 5) mon = 0 - random(100) - 1;
   if (lostgold->query_level() < 3) mon = 0 - random(3) - 1;
    if(lostgold->query_money() < 3000) mon = 0 - 1;
    if (lostgold->query_money() > 45000) mon = 0 - random(1000) - 1;
      count = call_other(lostgold, "query_money", 0);
     plymon = 0 - count;
     if (mon < plymon) {
        mon = plymon;
        }
        eatmoney = 0 - mon/3;
       if(mon == 0) {
   tell_object(lostgold, "A man finds you have no money and smacks you across the face.\n");
    call_other(lostgold, "add_hit_point", 0-random(11));
   return 1;
    }
    call_other(lostgold, "add_money", mon);
    call_other(goldeat, "set_level", 20);
    call_other(goldeat, "add_money", eatmoney);
    call_other(goldeat, "set_level",12);
     tell_object(lostgold, "A man takes your money!!\n");
    do_something();
   return 1;
  }
do_something(){
object cash;
   int ran, expl;
   string who, what;
   int repro;
   object offspring;
   ran = random(25);
   if (ran == 1) {
     say("A man opens his mouth.\n");
     random_move();
    return 1;
     }
  if (ran == 11)
  say("A man says: I want to cut your spending.\n");
  if (ran == 3) {
     say("A man says: We must all sacrifice to change things.\n");
    random_move();
      }
  if (ran == 4)
   {
     say("A man looks around.\n");
    random_move();
   }
  if (ran == 5)
     say("A man says: Most people don't even notice when I ask them to contribute or when they do.\n");
  if (ran == 6)
     say("A man smiles.\n");
  if (ran == 10 || ran == 0)
      say("A man looks at you.\n");
   if (ran == 7)
      say("A man says: The economy will grow under my plan.\n");
   if (ran == 15)
     {
      expl = random(100);
      if (expl > 13)
            return 1;
       say("Suddenly, A man explodes.\n");
       say("A few coins scatter in the explosion");
       cash=clone_object("obj/money");
       call_other(cash, "set_money", random(30));
       move_object(cash, environment(this_object()));
       destruct(this_object());
       }
   if (ran == 8)
     say("A man starts jogging in place.\n");
   if (ran == 9)
     say("A man looks around for a place to eat.\n");
     if (ran == 2) {
       repro = random(100);
     if (repro > 20)
 {
    random_move();
           return 1;
  }
     offspring = clone_object("players/haji/rush/char/mugger");
    if (random(100) < 20) 
    move_object(clone_object("players/boltar/things/waste.c"),offspring);
     say("A man becomes two!!!\n");
     move_object(offspring, environment(this_object()));
     call_other(offspring, "random_move", 0);
     random_move();
     return 1;
     }
    return 1;
}

random_move() {
    int n;
    n = random(4);
    if (n == 0)
	command("west");
    else if (n == 1)
	command("east");
    else if (n == 2)
	command("south");
    else if (n == 3)
	command("north");
}

