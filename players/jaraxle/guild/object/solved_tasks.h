void
set_solved(string task)
{
    Tasks[task] = 1;
}

status
query_solved(string task)
{
    if(Tasks[task]) return 1;
    else return 0;
}
