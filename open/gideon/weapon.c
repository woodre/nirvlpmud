inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("sword");
    set_alias("shortsword");
    set_short("A rusty shortsword");
    set_long(
		"The shortsword is very rusted. It definitely looks like\n"+
		"it has seen better days, but it is better than nothing.\n");
    set_class(1);
    set_weight(1);
    set_value(0);
}

/*
Guidelines

500k coins to buy the base weapon which is this file right here
For each upgrade:

100k xp + 10k coins

1. 100k xp + 10k coins
2. 200k xp + 20k coins
3. 300k xp + 30k coins
.
..
...
etc.


Have stuff that you can buy

Traps
Poisons
Weapon Class
Increased Stats

Ideas still coming in on the stuff that you can buy


Traps =

Something like a hamstring...
At a low level, the person that they use the move on has a 90% chance to be able to leave the room
Raising it higher and higher until a maximum of 5 gives the person that you use it on like a x% less chance to leave the room

Rank 1 - 90%
Rank 2 - 80%
Rank 3 - 70%
Rank 4 - 60%
Rank 5 - 50%

Poisons

The higher the level (out of 10), the more damage the poison will do

Rank 1   - 0 to 5 damage per round
Rank 2   - 0 to 10 damage per round
Rank 3   - 0 to 15
Rank 4   - 0 to 20
Rank 5   - 0 to 25
Rank 6   - 0 to 30
Rank 7   - 0 to 35
Rank 8   - 0 to 40
Rank 9   - 0 to 45
Rank 10  - 0 to 50

Weapon Class

The higher the level (out of 25), the more the weapon class will be
Yes I realize this makes the weapon class maximum of 25... So I was thinking maybe weapon class could be an increased charge of experience and coins.
Such as 500k xp + 80k coins for each wc you add on

Rank 1  - WC 1
Rank 2  - WC 2
Rank 3  - WC 3
Rank 4  - WC 4
Rank 5  - WC 5
Rank 6  - WC 6
Rank 7  - WC 7
Rank 8  - WC 8
Rank 9  - WC 9
Rank 10 - WC 10
Rank 11 - WC 11
Rank 12 - WC 12
Rank 13 - WC 13
Rank 14 - WC 14
Rank 15 - WC 15
Rank 16 - WC 16
Rank 17 - WC 17
Rank 18 - WC 18
Rank 19 - WC 19
Rank 20 - WC 20
Rank 21 - WC 21
Rank 22 - WC 22
Rank 23 - WC 23
Rank 24 - WC 24
Rank 25 - WC 25

Increased Stats

You can choose ONE stat to upgrade and you can upgrade it 10 or 15 more (your choice).
Brings up a prompt that will ask: cha, int, mag, sta, str, dex, luc, pie, ste, wil
You select one and it starts out at 1 since you just bought it
Then you can increase it making that stat the maximum of 40 or 45.

********NEW IDEA********

Worm suggested that none of these cost sps to use... Instead.. Make a point system which you can also upgrade.

You have like polymorph clay which you can charge with something at the shop.. LIKE a battery which would cost more coins (not sure how much exactly)
Each rank will increase your maximum points by 100. (20 ranks) So this is obviously what you need to buy first or else the weapon is useless.

Rank 1  - 100
Rank 2  - 200
Rank 3  - 300
Rank 4  - 400
Rank 5  - 500
Rank 6  - 600
Rank 7  - 700
Rank 8  - 800
Rank 9  - 9000
Rank 10 - 1000
Rank 11 - 1100
Rank 12 - 1200
Rank 13 - 1300
Rank 14 - 1400
Rank 15 - 1500
Rank 16 - 1600
Rank 17 - 1700
Rank 18 - 1800
Rank 19 - 1900
Rank 20 - 2000

There can be 20 different "battery packs". And you HAVE to buy the right "size". If you have a maximum of 100 charges, you have to buy a pack that is 100 charges exactly. No more than it can hold
Now if you have 5 points still left in your points "clay", you still have to get the 100, but it takes the 5 out. You can't hold ANY more than your rank allows you.

********END IDEA********