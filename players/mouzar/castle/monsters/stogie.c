inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("stogie");
set_short("Stogie the Bard");
set_long("This poor Halfling is singing the blues.  His woman is giving him\n"+
         "troubles and is makeing him hit the ale.\n");
set_al(0);
set_level(3);
set_wc(7);
set_ac(5);
set_hp(45);
set_aggressive(0);
coins=clone_object("obj/money");
coins->set_money(200);
load_chat(5,({"Stogie pulls out a picture and stares at it for a little while.\n"+
               "He takes a pull on his Ale and tunes his lute and sings\n"+
                "'I once had a woman...I loved her so...But she didn't love me'\n"}));
}
 
