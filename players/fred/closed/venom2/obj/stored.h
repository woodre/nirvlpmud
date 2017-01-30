/***************************************************
******* Stored Mp, Sp, and Coins ******************
**************************************************/
store_coins(int i){
	int moneymoney;
	if(file_name(environment(this_player())) != "players/maledicta/venom/symb_room"){
		return 0;
	}
	if(!i){
		write("store how many coins?\n");
		return 1;
	}
	sscanf(i, "%d", moneymoney);
	if(moneymoney < 1){
		write("You cannot store that amount!\n");
		return 1;
	}
	if(moneymoney > USER->query_money()){
		write("You don't have that much!\n");
		return 1;
	}
	USER->add_money(-(moneymoney));
	stored_mon += moneymoney;
	write("You drop "+moneymoney+" coins into the pool of dark matter.\n");
	write("You now have "+stored_mon+" saved up.\n");
if(stored_mon >= 1000000 && stored_mp >= 5000 && stored_sp >= 5000 && !lair &&
      USER->query_level() > 15){
      tell_object(USER,
      "                           "+BOLD+"<<<< LAIR >>>>"+NORM+"\n\n\n"+
      HIR+"    Your domain is ready now.  All you need do is 'place' it where\n"+
      "    you want it hidden.  Remember, it cannot go into the main village\n"+
      "    and a few other places, which you will know if you try."+NORM+"\n\n\n"+
      "                           "+BOLD+"<<<< LAIR >>>>"+NORM+"\n"); 
      stored_mon -= 1000000;
      stored_mp -= 5000;
      stored_sp -= 5000;
      lair = 1;
      }
	write_file("/players/maledicta/log/store_coins2",
	NAME+" "+ctime(time())+"  "+moneymoney+" "+stored_mon+"\n");
	save_venom();
	return 1;
}
set_stored_coins(int i){ stored_mon = i; }
query_stored_coins(){ return stored_mon; }
set_stored_mp(int i){ stored_mp = i; }
query_stored_mp(){ return stored_mp; }
set_stored_sp(int i){ stored_sp = i; }
query_stored_sp(){ return stored_sp; }
add_stored_mp(int i){ stored_mp += i; }
add_stored_mon(int i){ stored_mon += i; }
add_stored_sp(int i){ stored_sp += i; }

store_mp(int i){
	int mpmp;
	if(USER->query_ghost()) return 0;
	if(file_name(environment(this_player())) != "players/maledicta/venom/symb_room"){
		return 0;
	}
	if(!i){
		write("store how much mp?\n");
		return 1;
	}
	sscanf(i, "%d", mpmp);
	if(mpmp < 1){
		write("You cannot store that amount!\n");
		return 1;
	}
	if(mpmp > mp - 10){
		write("You don't have that much to spare!\n");
		return 1;
	}
	mp -= mpmp;
	stored_mp += mpmp;
	write("You expend "+mpmp+" "+BOLD+"Dark Matter"+NORM+" into the pool.\n");
	write("You now have "+stored_mp+" Matter saved up.\n");
if(stored_mon >= 1000000 && stored_mp >= 5000 && stored_sp >= 5000 && !lair &&
      USER->query_level() > 15){
      tell_object(USER,
      "                           "+BOLD+"<<<< LAIR >>>>"+NORM+"\n\n\n"+
      HIR+"    Your domain is ready now.  All you need do is 'place' it where\n"+
      "    you want it hidden.  Remember, it cannot go into the main village\n"+
      "    and a few other places, which you will know if you try."+NORM+"\n\n\n"+
      "                           "+BOLD+"<<<< LAIR >>>>"+NORM+"\n"); 
      stored_mon -= 1000000;
      stored_mp -= 5000;
      stored_sp -= 5000;
      lair = 1;
      }
	write_file("/players/maledicta/log/store_mp2",
	NAME+" "+ctime(time())+"  "+mpmp+" "+stored_mp+"\n");
	save_venom();
	return 1;
}

store_sp(int i){
	int spsp;
	if(USER->query_ghost()) return 0;
	if(file_name(environment(this_player())) != "players/maledicta/venom/symb_room"){
		return 0;
	}
	if(!i){
		write("store how much Spell Points?\n");
		return 1;
	}
	sscanf(i, "%d", spsp);
	if(spsp < 1){
		write("You cannot store that amount!\n");
		return 1;
	}
	if(spsp > USER->query_sp()){
		write("You do not have enough energy for that.\n");
		return 1;
	}
	USER->add_spell_point(-spsp);
	stored_sp += spsp;
	write("You expend "+spsp+" spell energy into the pool.\n");
	write("You now have "+stored_sp+" Spell Points saved up.\n");
if(stored_mon >= 1000000 && stored_mp >= 5000 && stored_sp >= 5000 && !lair &&
      USER->query_level() > 15){
      tell_object(USER,
      "                           "+BOLD+"<<<< LAIR >>>>"+NORM+"\n\n\n"+
      HIR+"    Your domain is ready now.  All you need do is 'place' it where\n"+
      "    you want it hidden.  Remember, it cannot go into the main village\n"+
      "    and a few other places, which you will know if you try."+NORM+"\n\n\n"+
      "                           "+BOLD+"<<<< LAIR >>>>"+NORM+"\n"); 
      stored_mon -= 1000000;
      stored_mp -= 5000;
      stored_sp -= 5000;
      lair = 1;
      }
	write_file("/players/maledicta/log/store_sp2",
	NAME+" "+ctime(time())+"  "+spsp+" "+stored_sp+"\n");
	save_venom();
	return 1;
}




