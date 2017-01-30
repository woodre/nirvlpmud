inherit "obj/monster";
int level1;
/* Not needed - Rumplemintz - Dec-05-2009
int level;
 */
string solution;
string argomento;
int aaa;
int coins;

set_argomento(solution){argomento=solution; }

set_level1(level){

   set_chat_chance(4);
   load_chat("The student looks angry at you.\n");
   load_chat("The student looks inside his backpack.\n");

if(level <=5)
{
   set_level(20);
   set_hp(500);
   set_al(0);
   set_wc(32);
   set_ac(20);
   coins=150;
   set_chance(25);
   set_spell_dam(25);
} 

if(level >= 6 && level <=10)
{
   set_level(20);
   set_hp(900);
   set_al(0);
   set_wc(36);
   set_ac(22);
   coins=300;
   set_chance(25);
   set_spell_dam(25);
}

if(level >= 11 && level <=15)
{
   set_level(20);
   set_hp(900);
   set_al(0);
   set_wc(40);
   set_ac(26);
   coins=500;
   set_chance(25);
   set_spell_dam(25);
}

if(level >= 16 && level <=23)
{
   set_level(20);
   set_hp(1100);
   set_al(0);
   set_wc(50);
   set_ac(30);
   coins=1000;
   set_chance(25);
   set_spell_dam(25);
}

if(level >= 24)
{
   set_level(20);
   set_hp(1300);
   set_al(0);
   set_wc(58);
   set_ac(34);
   coins=3500;
   set_chance(35);
   set_spell_dam(25);
}
}

reset(arg){
   ::reset(arg);
   set_name("student");
   set_alias("student");
   set_short("A phd student");
   set_long("He appears to be in his early twenties.  He has a very pale\n"+
            "complexion from spending many hours in the laboratory.  He is\n"+
            "wearing shorts, comfortable for the work in the lab.  A nice \n"+
            "yellow pocket protector that holds his large assortment of pens \n"+
            "sits in his shirt pocket.\n");
  set_dead_ob(this_object());
}

id(str) { return str =="student_fran" || str=="student";}

monster_died() {
   object ob;
  write_file("/players/francesco/masterquest/killstudent.log", ctime(time())+" "+
    attacker_ob->query_real_name()+"  "+argomento+"\n");
  if(!present("paper",attacker_ob)) {
  write("A piece of paper magically appears in your inventory.\n");
  ob=(clone_object("/players/francesco/masterquest/paper.c"));
  move_object(ob,attacker_ob);}
  present("paper",attacker_ob)->set_userid(argomento);
  return 0; }
 
