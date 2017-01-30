dervish_upall()
{
	int b;
	object ob, GID;
	object * dervish;
	dervish = users();
	
	GID = present("dervish_tattoo", this_player());
	
	if(!GID) return 0;
	write("~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for(b=0; b<sizeof(dervish); b+=1)  {
		ob = dervish[b];
		if(present(ob, this_player()))  {
			GID->ssave();
			destruct(GID);
			move_object(clone_object(GID), ob);
			write(pad((string)ob->query_name(),15));
			}
			}
			write("~~~~~~~~~~~~~~~~~~~~~~~~\n");
			return 1;
			}