
object this;
int gen;
string gen_hisher;

inherit "room/room";
reset(arg) {
   if(arg) return;
   short_desc = "A wardrobe";
  long_desc = "This is a large and comfortable wardrobe. Here you can\n" +
  "relax and it seems all your thoughts are miles and miles from you.\n" +
  "There are few things here but the place is nice. There is carpet on\n" +
  "the floor. In a corner you see a comfortable bed, with blue sheet on it.\n" +
  "On the wall there are some pictures and few lamps that keep the light on.\n";
    dest_dir = ({
    "room/church", "church",
    "room/post"  , "post" ,
    "room/adv_guild" , "adv" ,
    "room/shop"  , "shop" ,
    "/players/gorgan/closed/guild/guild_room" , "guild",
    "/players/hurtbrain/workroom" , "home"
    });
    items = ({"bed","It's a large and comfortable bed, with blue sheet and\n"+
	     "two fluffy pillows on it. You can lay there (if you want).\n"});
   set_light(1);
}

init(){
    ::init();
        add_action("undress","undress");
	add_action("lay","lay");
}

lay(str)  {
        if(!str || ((str != "bed" ) && (str != "on bed"))) {
		write("Where??\n");
		return 1;
		}
	write("You lay on the bed and feel just wonderful.\n");
	say(this_player()->query_name() + " lays on the bed and take a breath of pleasure.\n");
	return 1;
	}

undress() {

	this=this_player();
	gen=0;
	gen_hisher="his";
	if(this_player()->query_gender()=="female")  {
		gen=1;
		gen_hisher="her";
		}
		write("You slowly slides your shirt up to your head and toss it in a corner.\n");
		say(this_player()->query_name()+" winks at you seductively and slowly raises "+gen_hisher+" shirt up\nto "+gen_hisher+" head, tossing it away.\n");
		call_out("jeans",2);
		if(gen==1)  {
			call_out("bra",4);
			call_out("panties",7);
			}
		else    call_out("panties",5);
    return 1;
}

jeans()  {
	object ppl;
	tell_object(this,"Now you move your hand to your waist , you unzip your jeans and lower\nthem to your ankles, kicking them far from you.\n");
	ppl = first_inventory(environment(this));
	while(ppl)  {
		if(ppl!=this)
			tell_object(ppl,this->query_name()+" now moves "+gen_hisher+" hands down to "+gen_hisher+" jeans, unzips them and slowly lowers\nthem down to "+gen_hisher+" ankles, kicking them away.\n");
		ppl = next_inventory(ppl);
		}
	return 1;
	}

bra()  {
	object ppl;
	tell_object(this,"You raise your hands up to your bra and unbutton it, letting it falling\nfrom your beautiful round breasts.\n");
	ppl = first_inventory(environment(this));
	while(ppl)  {
		if(ppl!=this)
			tell_object(ppl,this->query_name()+" raises her hands up to her bra and unbuttons it, letting it\nfalling and revealing her beautiful round breasts.\n");
		ppl = next_inventory(ppl);
		}
	return 1;
	}

panties()  {
	object ppl;
	tell_object(this,"You slide your hands under your panties and lower them down to your legs.\nNow you're totally naked.\n");
	ppl = first_inventory(environment(this));
	while(ppl)  {
		if(ppl!=this)
			tell_object(ppl,this->query_name()+" slides "+gen_hisher+" hands under "+gen_hisher+" panties and lowers them down to "+gen_hisher+" legs.\nNow "+this->query_name()+" is totally naked.\n");
		ppl = next_inventory(ppl);
		}
	return 1;
	}

realm(){return "NT";}

