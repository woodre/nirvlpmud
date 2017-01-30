inherit "/obj/monster.c";
inherit "/obj/monster";
int heal;
object ob;
int x;

reset(arg){
::reset();
  if(arg) return;
  
set_name("<<<CyberDaemon>>>");
set_alt_name("monster");
set_alt_name("cyber");
set_alt_name("CyberDaemon");
set_alt_name("cyberdaemon");
set_short("<<<CyberDaemon>>>");
set_long("Ooohhh\n"+
          "This is a big scary monster.\n"+
          "WOW!\n");
set_level(40+random(10));
set_hp(10000+random(5000));
set_hp_bonus(1500);
set_ac(50+random(25));
set_wc(50+random(25));
set_wc_bonus(25);
set_al(-250);
set_heal(100,10);
add_money(2500+random(2500));
set_chance(50);
set_spell_mess1("Swish...swish swish.. swish... swish swish swish....\n"+
"Throwing stars leap from the hands of the CyberDaemon.\n"+
"Pain begins to set in as blood pours from your open wounds...\n");
set_spell_mess2("Throwing stars leap from the hands of the CyberDaemon.");
set_spell_dam(70+random(30));
set_aggressive(1);

set_multi_cast(1);

add_spell("stars",
"Throwing stars stick into your flesh\n",
"#MN# launches throwing stars into #TN#'s flesh.\n",
25,50-100,"physical",3);

add_spell("kick",
"#MN# kicks you in the chest\n",
"#MN# kicks $TN# in the chest making them stumble backwards.\n",
25,90-100,"physical",3);

add_spell("smoke",
"#MN# chokes you in a cloud of smoke!\n",
"#MN# chokes #TN# in a cloud of smoke!\n",
50,75-100,"other|magic",3);
}

heart_beat()
{
	::heart_beat();

	if(!environment()) return;

	ob = all_inventory(environment(this_object()));

	for(x=0;x<sizeof(ob);x+=1)
	{
		if(ob[x]->is_wizard())
		{
			write("\n");
		}

		if(ob[x]->query_guild_name() == "cyberninja")
		{
			write("\n");
		}
		
		if(ob[x]->query_short() == "cyberdaemon")
		{
			write("\n");
		}

		else
		{
			if(ob[x]->is_living() || ob[x]->is_kid() || ob[x]->is_pet()){
			this_object()->attack_object(ob[x]);
		}
	}
}




/*  
heart_beat()
{
  if( !present(AFFILIATE, TP) ) {
  if(TP->query_level() > 20) {
    return 1; }
	
	  if(!present(AFFILIATE, TP) && ((int)TP->query_level() < 21))
	  if(!present(AFFILIATE, TP) && TP->query_level() < 20)
	    command("drop all", TP);
		return 1;
		}
				
		PUT THIS INTO THE XMOB AND THEN PUT INTO THIS MOB
		
	 if(!ob[x]->is_living())
return;
 ::heart_beat();
}
*/