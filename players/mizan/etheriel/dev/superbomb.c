
id(str) { return str == "bomb"; }
get() { return 1; }
short() { return "An Acme Super Bomb"; }
long() {
  write("This is a black sphere, rather heavy, with a thick fuse coming\n"+
	"out from an oriface. It looks like it used to be a bowling ball.\n");
	}

init() {
	add_action("light","light");
	}

light(str) {
  if(!str) { return 0; }
  if(str == "bomb") {
	write("You light the bomb and roll it across the floor... Auuugh!!!!\n");
	say((this_player()->query_name())+" lights a fucking bomb!\n");
	command("drop bomb", this_player());
	call_out("pow_asplode", 6);
	}
  return 0;
}

pow_asplode() {
object ob;
say("PPPPPPPPPPPP      OOOOOOOOOOOOO    WWWWW               WWWWW    !!!! \n");
say("PPPPPPPPPPPPP    OOOOOOOOOOOOOOO   WWWWW               WWWWW   !!!!!!\n");
say("PPPPP     PPPP  OOOOOO     OOOOOO  WWWWW      WWW      WWWWW   !!!!!!\n");
say("PPPPP     PPPP  OOOOO       OOOOO   WWWWW    WWWWW    WWWWW    !!!!!!\n");
say("PPPPPPPPPPPPPP  OOOOO       OOOOO   WWWWW   WWWWWWW   WWWWW    !!!!!!\n"); 
say("PPPPPPPPPPPPP   OOOOO       OOOOO    WWWWW WWWWWWWWW WWWWW     !!!!!!\n");
say("PPPPPPPPPPP     OOOOO       OOOOO    WWWWWWWWWWWWWWWWWWWWW      !!!!\n");
say("PPPPP           OOOOO       OOOOO     WWWWWWWW   WWWWWWWW            \n");
say("PPPPP           OOOOOOO    OOOOOO     WWWWWWW     WWWWWWW       !!!!\n");
say("PPPPP            OOOOOOOOOOOOOOO      WWWWWW       WWWWWW      !!!!!!\n");
say("PPPPP             OOOOOOOOOOOOO        WWWW         WWWW        !!!!\n");
ob=first_inventory(environment(this_player()));
  while(ob) {
   object oc;
   oc=ob;
   oc=next_inventory(ob);
   if(living(oc)) {
     oc->run_away();
   }
  }
destruct(this_object());
return 1;
}

