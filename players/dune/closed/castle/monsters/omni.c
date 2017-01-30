inherit "obj/monster";


int u, one;
object more;
string monssr;


init() { add_action("move_down","down"); }


move_down()
{
  if (this_object()->query_attack())
  {
    write("Omni blocks your egress!\n");
    return 1;
  }
  else return 0;
}


reset(arg)
{
   object gold;
   one = 0;

   ::reset(arg);
   if(arg) return;
   set_name("Omni");
   set_race("god");
   set_alias("omni");
   set_short("Omni, the Overlord of Elements");
   set_long("Omni is the Overlord of Elements. He is ALL powerful.\n"+
     "His form is ever-changing, and his body is of all four elements.\n"+
     "Blasts of frost, fumes of fire, raging winds, and a rock-solid\n"+
     "armor make up his godly being. Omni is no easy kill.\n");
   set_level(30);
   set_hp(2000);
   set_al(0);
   set_ac(50);
   set_chance(60);
   set_spell_dam(120);
   set_spell_mess1("Omni commands you to DIE.");
   set_spell_mess2("Omni BLASTS you with godfire.");
   set_chat_chance(20);
load_chat("Omni says: The Eyes of Truth are always watching.\n");
load_chat("Omni dwells in omniscient thoughts.\n");
load_chat("Omni commands the elements.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(15000)+12000);
   move_object(gold,this_object());
   move_object(clone_object("/players/dune/weapons/lifeblood.c"),
       this_object());
   init_command("wield lifeblood");
   set_wc(50);
}


heart_beat()
{
  object boo;
  boo = this_object()->query_attack();
  if (boo)
  {
    if(this_object()->query_wc() < 50)
    {
      this_object()->set_wc(100);
      this_object()->heal_self(500);
    }
    if(this_object()->query_ac() < 30)
    {
      this_object()->set_ac(75);
      this_object()->heal_self(500);
    }
    if(boo->query_real_name() == "omni")
    {
      boo->stop_fight(); boo->stop_hunted();
      this_object()->stop_fight(); this_object()->stop_hunted();
    }
    if(random(25) < 3)
    {
      u = random(4);
      if (u == 0)   {
        more=clone_object("/players/dune/monsters/firedragon.c");
        move_object(more, environment(this_object()));
        monssr = "a fire dragon";}
      if (u == 1)   {
        more=clone_object("/players/dune/monsters/airelement.c");
        move_object(more, environment(this_object()));
        monssr = "an air elemental";}
      if (u == 2)   {
        more=clone_object("/players/dune/monsters/shark.c");
        move_object(more, environment(this_object()));
        monssr = "a shark";}
      if (u == 3)   {
        more=clone_object("/players/dune/monsters/digger.c");
        move_object(more, environment(this_object()));
        monssr = "a digger";}
      say("Omni COMMANDS a "+monssr+" to appear at his side.\n");
      say("The elements collide!\n");
      say("A "+monssr+" steps into the room from the chaos!\n");
      more->attack_object(this_object()->query_attack());
    }
  }

  if (this_object()->query_attack() && 
      this_object()->query_hit_point() <= 0)
  {
    if (one == 0 && this_object()->query_attack())
    {
      log_file("dune.mon",capitalize
        ((this_object()->query_attack())->query_real_name())+
        "("+(this_object()->query_attack())->query_level()+")"+
        " killed omni.c\n");
      one = 1;
    }
  }
  ::heart_beat();
}
