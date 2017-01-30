short() { return "heal maker"; }

id(str) { return "maker"; }
init()
{
add_action("healeveryone","healeveryone");
}

healeveryone()
{
	object ob;
	int v;

   ob=users();
   
   for(v=0; v<sizeof(ob); v++) 
   {
      object oc;
	  if(ob[v] && ob[v]->query_level() < 20)
	  move_object(clone_object("/players/mizan/etheriel/items/squishweapon"), ob[v]);
	  move_object(clone_object("/players/mizan/etheriel/items/squishweapon"), ob[v]);
	  move_object(clone_object("/players/mizan/etheriel/items/jacket-stealing"), ob[v]);
	  move_object(clone_object("/obj/heal"), ob[v]);
	  move_object(clone_object("/obj/heal"), ob[v]);
	  move_object(clone_object("/obj/heal"), ob[v]);
      tell_object(ob[v], "Mizan has given you heal spells and weapons. Don't drop the heals. To use, type 'heal'.\n");
   }

	write("done");
	return 1;
}