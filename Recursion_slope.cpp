#include <stdio.h>

//=============================================================================

const char *s = "((1+3*5)/4+2)/3";

//=============================================================================

int Get_G ();

int Get_E ();

int Get_T ();

int Get_P ();

int Get_N ();

//-----------------------------------------------------------------------------

void Sin_Error (const char *name_of_func);

//=============================================================================

int main ()
{
    printf ("%d", Get_G ());

    return 0;
}

//=============================================================================

int Get_G ()
{
    int res = Get_E ();

    if (*s == '\0')
        return res;
    else
    {
        Sin_Error ("Get_G");
    }

    return 0;
}

//-----------------------------------------------------------------------------

int Get_E ()
{
    int val = Get_T ();

    while (*s == '+' || *s == '-')
    {
        char op = *s;
        s++;

        int val2 = Get_T ();

        if (op == '+') val += val2;
        else           val -= val2;
    }

    return val;
}

//-----------------------------------------------------------------------------

int Get_T ()
{
    int val = Get_P ();

    while (*s == '*' || *s == '/')
    {
        char op = *s;
        s++;

        int val2 = Get_P ();

        if (op == '*') val *= val2;
        else           val /= val2;
    }

    return val;
}

//-----------------------------------------------------------------------------

int Get_P ()
{
    if (*s == '(')
    {
        s++;
        int val = Get_E ();

        if (*s == ')')
        {
            s++;
            return val;
        }
        else Sin_Error ("Get_P");
    }
    else
    {
        return Get_N ();
    }
}

//-----------------------------------------------------------------------------

int Get_N ()
{
    int val = 0;

    val = val * 10 + (*s - '0');
    s++;

    while ('0' <= *s && *s <= '9')
    {
        val = val * 10 + (*s - '0');
        s++;
    }

    return val;
}

//-----------------------------------------------------------------------------

void Sin_Error (const char *name_of_func)
{
    printf ("SINT ERROR IN %s!\n", name_of_func);
}
