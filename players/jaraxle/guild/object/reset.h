void
reset(int arg)
{
    if(arg) return;
    set_no_clean(1);
    Stats = ([ ]);
    Tasks = ([ ]);
}
