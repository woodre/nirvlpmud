inherit "obj/monster";


int one;


reset(arg)
{
   int a, x, v;
   object gold;
   one = 0;
   ::reset(arg);
   if(arg) return;
   a = random(3) + 1;
   set_name("Planetar");
   set_race("planetar");
   set_alias("planetar");
   if (a == 1) {
set_short("A silver planetar");
set_long("A Planetar!  Before you stands one of the more\n"+
         "powerful servants of nature.  The Planetar is\n"+
         "one of the highest servants to a god.  They\n"+
         "even carry out battles for their masters.\n"+
         "This planetar has glittering silver skin.\n"+
         "It's eyes are of pearl white.\n");}
   if (a == 2) {
set_short("A golden planetar");
set_long("A Golden Planetar!  Before you stands one of the\n"+
         "more powerful servants of nature.  The Planetar is\n"+
         "one of the highest servants to a god.  They\n"+
         "even carry out battles for their masters.\n"+
         "This planetar has glittering gold skin.\n"+
         "It's eyes are of jet black.\n");}
   if (a == 3) {
set_short("A vorpal planetar");
set_long("The Vorpal Planetar!  Before you stands one of\n"+
         "the more powerful servants of nature.  The Planetar\n"+
         "is one of the highest servants to a god.  They\n"+
         "even carry out battles for their masters.\n"+
         "This planetar is surrounded in arcs of crackling\n"+
         "cosmic energy.  It's eyes are of radiant red.\n");}
if (a == 1) { set_level(20);
   set_hp(random(100)+600); set_wc(30); set_ac(20); }
if (a == 2) { set_level(21);
   set_hp(random(100)+750); set_wc(35); set_ac(27); }
if (a == 3) { set_level(22);
   set_hp(random(100)+800); set_wc(40); set_ac(34); }
   set_al(0);
   if (a <= 2) set_chance(30);
   if (a > 2) set_chance(40);
   if (a == 1) set_spell_dam(60);
   if (a == 2) set_spell_dam(65);
   if (a == 3) set_spell_dam(70);
   set_spell_mess1("The planetar BLASTS you with GAMMA RAYS!");
   set_spell_mess2("The planetar DISRUPTS your EARTHLY FORM!");
   set_aggressive(1);
   gold=clone_object("obj/money");
   if (a == 1) gold->set_money(random(2000)+1000);
   if (a == 2) gold->set_money(random(3500)+1500);
   if (a == 3) gold->set_money(random(5500)+2000);
   move_object(gold,this_object());
   init_command("get all");
}
