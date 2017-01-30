inv = all_inventory(environment(this_object()));
for(x=0;x<sizeof(rooms);x++)
        {
           if(inv[x]->id("bite bug") && inv[x]->query_attack())
           {
              tell_room(environment(this_object()), HIB + "The Bite Bugs swarm to the attack!\n" + OFF);
              attack_object(inv[x]->query_attack());
              return 1;
           }
        }

move_me(){
     num = random(sizeof(rooms));
     rooms = ({ "entrance","roomw","roomw2","roomw3","room2","room3","roome","roome2","roome3" });
    if(!environment()) return;
say("The rabbit hops away.\n");
move_object(this_player(),"/players/jaraxle/3rd/warrior/rooms/"+rooms[num]+"");
say("A rabbit hops into the room.\n");
call_out("move_me", 5);
}

inv = all_inventory(environment(this_object()));

for (x=0;x<sizeof(rooms);x++)
{
	if(inv[rooms [x]]->id("statue"))
	{
		destruct(this_object());
		move_object(clone_object("/players/jaraxle/monster.c"),environment(this_object()));
	}
}

