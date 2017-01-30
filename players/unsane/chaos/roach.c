int n,i,count;
inherit "obj/monster.c";
object gold;

reset(arg)
{
::reset(arg);
if (arg)
  return;
set_heart_beat(1);
set_name("cochroach");
set_move_at_reset();
set_race("insect");
set_alias("roach");
set_short("A Devious Cochroach");
set_level(10);
set_al(-150);
set_wc(14);
set_ac(8);
gold=clone_object("obj/money");
gold->set_money(random(100));
move_object(gold,this_object());
move_object(clone_object("/players/unsane/trinket"),this_object());
set_aggressive(0);
load_chat("The cochroach scurries about.\n");
load_chat("The cochroach climbs into your clothes and then exits swiftly.\n");
set_chat_chance(10);
gold = clone_object("obj/money");
gold->set_money(random(100));
enable_commands();
}
long() {
write("A dastardly little insect.\nHe seems to be some sort of thief.\n"+
"Perhaps you should check all of your items.\n");
}
random_move() {
int n;
n = random(6);
if (n == 0) command("west");
if(n == 1) command("east");
if (n == 2) command("north");
if (n == 3) command("south");
if (n == 4) command("up");
if (n == 5) command ("down");
}
heart_beat()
{
::heart_beat();
steal();
if (random(6) == 0) random_move();
if (this_object()->query_hp() <30 && count < 1)
{
say("Nightcrawler enters the room with a large bamf?!\n");
say("Nightcrawler says: There you are, you little devil\n");
say("\n");
say("Nightcrawler grabs the cochroach and teleports out.\n");
i = random(3);
if (i==0){
say("You think: I bet they are headed for the danger room.\n");
move_object(this_object(),"/players/unsane/xmen/danger.c");
}
if (i==1){
say("You think: I bet they are headed for the hooded man.\n");
move_object(this_object(),"/room/big_tree");
}
if (i==2){
say("You think: I bet they went to visit plutus.\n");
move_object(this_object(),"/players/unsane/closed/hell/circle4.c");
}
say("A Devious Cochroach enters the room.\n");
count++;
}
}
steal()
{
int weight,count;
object ob, who;
count=random(4);
if (count==0 || count==1){return;}
who = this_object()->query_attack();
if (who) {
ob=who->query_weapon();
if (ob == 0)
ob= first_inventory(who);
if (ob==0) {return;}
if(!ob->get()) return; /* Duh! -Feldegast 8-11-2000 */
     transfer(ob, this_object());
return 1;
}
}

remove_object ( object prev ) {
    string log;
string err;

    object ob;

/* 08/20/06 Earwax: no need to keep logging this 
    log = "/players/unsane/log";
    err = catch(write_file(log, ctime()+": Roach dested!:\n"));
if (err) write_file("/ldmud.log", ctime()+": "+err+"\n");
    write_file(log, file_name(prev) + "\n");
    if ( this_player() )
        write_file(log, this_player()->query_real_name() + "\n");
    destruct(this_object());
*/
}
