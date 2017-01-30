inherit "obj/monster.talk";
object temp, bowl2,sboy;
object room;
 
reset(arg) {
  
        ::reset(arg);
        if(!arg) {
        set_name("bboy");
	set_alias("boy");
        set_level(10);
        set_al(0);
        set_short("A Blind Boy");
        set_long("This is a special blind boy.\n"+
                "The only way to cure his blindness is\n"+
                "to rub the tears of heaven on his eyes...\n");
        set_aggressive(0);
        set_wc(14);
        set_ac(8);
        set_chat_chance(20);
        load_chat("Boy says:  I want to be able to see...\n");
}
 }
 
init()
      { add_action("rub_eyes_with_tears", "rub");
::init();
      }
 
rub_eyes_with_tears(str)
{
        bowl2 = clone_object("players/airwoman/bowl2");
        if (str == "eyes")
        {
        if(!present("bowl2", this_player()))
	{ write("You do not have the ability to cure him.\n");
        return 1;}
        if(present("bowl2", this_player()))
        {
        remove_chat("Boy says:  I want to be able to see...\n");
        temp = present("bowl2", this_player());
        destruct(temp);
        write("You rub the blind boys eyes with the tears from\n"+
        "heaven.  The boy's eyes glistens and smiles at you.\n"); 
	sboy=clone_object("players/airwoman/quest/sboy");  
	room = environment(this_object());
        move_object(sboy, room);
/*
        call_other(this_player(), "set_quest", "blind_boy");
*/
	destruct(this_object());
        return 1; }
 
       }/*of if str== "eyes*/
}/*of rub_eyes_with_tears()*/
 
 
 
  
