#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
short_desc="Bard Object Room";
long_desc=
"You stand in a room filled to near overflowing with musical instruments\n"+
"of all shapes and styles.  If you are missing a your musical instrument,\n"+
"feel free to <replace> it here.  If you wish to leave the renounce your\n"+
"membership to the Bardic guild, type <abandon bards>.\n";

items=({
 "floor","The floor is made from a beautiful mahogany wood",
 "instruments","There are a LOT of musical instruments here",
 });

  dest_dir=({
 "/players/saber/closed/bards/bardrooms/enterance.c","east",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
   add_action("replace","replace");
  add_action("abandon","abandon");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

replace()  {
object ob, OB;
  ob = this_player();
  if(present("instrument",this_player()))  {
    write("You already have an instrument...silly Bard...\n");
    return 1;
        }
  if(ob->query_guild_name() == "bard")  {
  OB = clone_object("/players/saber/closed/bards/instrument.c");
  move_object(OB,ob);
  write("You have been given an new instrument.\n");
  return 1;
        }
  write("You are not a bard...If you do not agree, ask a wizard.\n");
  return 1;
        }

abandon(str)  {
object ob, OB;
int xp_loss;
  if(!str)  {
  write("To leave the bardic guild, type <abandon bards>\n");
  return 1;
        }
if(str == "bards")  {
  ob = this_player();
  OB = present("instrument",this_player());
  xp_loss = ob->query_exp() / 6;
  ob->set_guild_name(0);
  write_file("/players/saber/closed/bards/logs/leave",tp+" left the bards->"+ctime(time())+"\n");
  command("bte LEAVES THE BARDIC GUILD!",ob);
  destruct(OB);
  write("You leave the Bardic guild.\n");
  call_other(this_player(),"add_exp",-xp_loss);
  return 1;
        }
        }

realm()  { return "NT"; }
