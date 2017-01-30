inherit "players/nightshade/new_room";
int i;
object ob;
reset(arg){
if(!present("fighter"))
{
while(i<5)
{
ob=clone_object("players/nightshade/mons/fighter");
move_object(ob, this_object());
i++;
}
i=0;
}
   if(arg) return;
        set_light(1);
        short_desc = " Fighters Room";
     long_desc =
"The smell of sweat and blood greets you as you enter the hall of\n"+
"fighters. Here the would be heros can learn the skills of fighting\n"+
"and wrestling.\n";
      dest_dir = 
({
"players/nightshade/room/guild_row2", "west",
      });
}
