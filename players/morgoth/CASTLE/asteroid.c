inherit "room/room";
object tingler, money, thingy;
 
reset(arg)
{
    if (arg) return;
    set_light(1);
    tingler = clone_object("players/morgoth/MONSTERS/tingler");
    money = clone_object("obj/money");
    thingy = clone_object("players/morgoth/OBJ/thingy");
    short_desc = "An asteroid";
    long_desc = "Stark and desolate, this crator pocked asteroid\n" +
                "is located 2,000,000 light years away from Nirvana !\n";

    money->set_money(random(200));
    move_object(money, tingler);
    move_object(thingy, tingler);
    move_object(tingler, this_object());

dest_dir = 
({
    "players/morgoth/CASTLE/asteroid2", "south",
});
}

realm(){return "NT";}
