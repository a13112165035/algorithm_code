void randomPlace(int n, int pieces[])
{
    srand((unsigned)time(NULL));
    ; i < n; i++)
    {
        ;
        ;
        swap(pieces[a], pieces[b]);
    }
}
void nQueen(int n, int t, int pieces[])
{
    if (t > n)
    {
        resultNumber++;
        ; i <= n; i++)
        {
            ; j < pieces[i]; j++)
                cout << "- ";
            cout << pieces[i] << " ";
            ; j <= n; j++)
                cout << "- ";
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        for (int i = t; i <= n; i++)
        {
            swap(pieces[t], pieces[i]);
            if (isOK(t, pieces))
            {
                nQueen(n, t + , pieces);
            }
            swap(pieces[t], pieces[i]);
        }
    }
}
void LasVegas(int n, int pieces[])
{
    
    )
    {
        cout <<  << endl;
    }
    else
    {
        ; i <= n; i++)
        {
            pieces[i] = i;
        }
        )
        {
            
            , pieces))
            {
                randomPlace(n, pieces);
            }
            nQueen(n, (n / )-, pieces);
        }
    }
 
}
