inherit "room/room";

reset(arg){

    if(!arg){

    set_light(1);
    short_desc="Jethro's Burrow";
    long_desc=
  "As you enter the burrow, you realize that this is not the normal home\n"+
  "of an everyday person. Stuff is piled in every corner of this area, atop\n"+
  "each table and every dresser, stuff is all about. A spicey type of smoke\n"+
  "drifts from a small room on the far end of the hole, and the light coming\n"+
  "from there is warm and inviting.\n";

items=({
 "stuff", "Items large and small are piled about the corners and stacked\n"+
          "everywhere there is any bit of space within this room. Upon\n"+
          "further inspection you find a collection of the varied and,\n"+
          "wonderful, a collection of items from around all of Nirvana",
 "burrow", "The burrow appears to be occupied at this time",
 "table", "The tables here are made of an exotic oak",
 "dresser", "The dressers are made of the same exotic oak as the tables,\n"+
            "and are just as covered with stuff",
 "light", "A soft and warm light comes from the far room",
 });


dest_dir=({
 "/players/daranath/clearing/hill.c","exit",
 "/players/daranath/clearing/burrow2.c","room",
           });
        }
        }
