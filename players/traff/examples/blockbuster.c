
 

id(str) { return str == "blockbuster"; }

get() { return 1; }
query_value() { return 100; }
short() { return "A Blockbuster"; }

long() {

  write("This looks like a firecracker... but it is REALLY big...\n");

	}

 

init() {

	add_action("light","light");

	}

 

light(str) {

  if(!str) { return 0; }

  if(str == "blockbuster") {

	write("You light the thing and toss it on the floor... better run!!\n");

	say((this_player()->query_name())+" lights a REALLY big firecracker...\n");

    move_object(this_object(), environment(this_player()));
	call_out("pow", 6);

	}

  return 1;

}

 

pow() {

say("\n");
say("PPPPPPPP         OOOOOOOOOO      WWW                WWW     !!!  \n");

say("PPPPPPPPPP      OOOOOOOOOOOO     WWW                WWW    !!!!! \n");

say("PPP     PPP    OOOO      OOOO     WWW     WWWW     WWW     !!!!! \n");

say("PPP     PPP    OOO        OOO     WWW    WWWWWW    WWW     !!!!! \n"); 

say("PPPPPPPPPP     OOO        OOO      WWW  WWWWWWWW  WWW      !!!!! \n");

say("PPPPPPPP       OOO        OOO      WWW  WWW  WWW  WWW       !!!  \n");

say("PPP            OOOO      OOOO       WWWWWW    WWWWWW             \n");

say("PPP             OOOOOOOOOOOO        WWWWW      WWWWW        !!!  \n");

say("PPP              OOOOOOOOOO          WWW        WWW         !!!  \n");

destruct(this_object());

return 1;

}

 

